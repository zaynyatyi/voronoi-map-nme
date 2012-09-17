package com.nodename.delaunay;

//import as3.Rectangle;
import nme.geom.Rectangle;
import nme.geom.Point;
import nme.display.BitmapData;
import nme.ObjectHash;
import nme.Lib;
//import as3.TypeDefs;
import com.nodename.delaunay.EdgeReorderer;
import com.nodename.geom.Circle;
import com.nodename.geom.LineSegment;
import de.polygonal.math.PM_PRNG;

using Lambda;
using Std;
//using as3.PointCore;

class Voronoi {

	private var _prng:PM_PRNG;
	private var _sites:SiteList;
	private var _sitesIndexedByLocation:ObjectHash<Point, Site>;
	private var _triangles:Array<Triangle>;
	private var _edges:Array<Edge>;

	// TODO generalize this so it doesn't have to be a rectangle;
	// then we can make the fractal voronois-within-voronois
	public var plotBounds(default, null):Rectangle;

	public function dispose():Void
	{
		var i:Int, n:Int;
		if (_sites != null)
		{
			_sites.dispose();
			_sites = null;
		}
		if (_triangles != null)
		{
			n = _triangles.length;
			for (i in 0...n)
			{
				_triangles[i].dispose();
			}
			//_triangles.length = 0;
			_triangles = null;
		}
		if (_edges != null)
		{
			n = _edges.length;
			for (i in 0...n)
			{
				_edges[i].dispose();
			}
			//_edges.length = 0;
			_edges = null;
		}
		plotBounds = null;
		_sitesIndexedByLocation = null;
	}

	public function new(points:Array<Point>, colors:Array<Int>, plotBounds:Rectangle)
	{	
		//makeSureNoDuplicatePoints(points); //no need since we are using nme.ObjectHash
		(_prng = new PM_PRNG()).seed = 1;
		_sites = new SiteList();
		_sitesIndexedByLocation = new ObjectHash();
		addSites(points, colors);
		Lib.trace(_sitesIndexedByLocation.count());
		this.plotBounds = plotBounds;
		_triangles = new Array<Triangle>();
		_edges = new Array<Edge>();
		fortunesAlgorithm();
	}
	
	/**
	 * AS3 Hash stores object keys by object identity.
	 * Haxe Hash only supports string keys.
	 * This means duplicate coordinates can't be stored in hash.
	 * Prevent this case until it's possible to store duplicate points coords.
	 */
	/*private function makeSureNoDuplicatePoints(points:Array<Point>) {
		var h = new nme.ObjectHash<Point, Point>();
		for (p in points) {
			if (h.exists(p)) {
				throw "Duplicate points not supported yet!";
			}
			h.set(p, p);
		}
	}*/

	private function addSites(points:Array<Point>, colors:Array<Int>):Void
	{
		var length:Int = points.length;
		for (i in 0...length)
		{
			addSite(points[i], (colors != null) ? colors[i] : 0, i);
		}
	}
	
	private function addSite(p:Point, color:Int, index:Int):Void
	{
		var weight:Float = _prng.nextDouble() * 100;
		var site:Site = Site.create(p, index, weight, color);
		_sites.push(site);
		_sitesIndexedByLocation.set(p, site);
	}

	public function edges():Array<Edge>
	{
		return _edges;
	}
	
	public function region(p:Point):Array<Point>
	{
		//Lib.trace(p);
		var site:Site = _sitesIndexedByLocation.get(p);
		//Lib.trace(site);
		if (site == null)
		{
			//Lib.trace('site is null');
			return new Array<Point>();
		}
		return site.region(plotBounds);
	}

	  // TODO: bug: if you call this before you call region(), something goes wrong :(
	public function neighborSitesForSite(coord:Point):Array<Point>
	{
		var points:Array<Point> = new Array<Point>();
		var site:Site = _sitesIndexedByLocation.get(coord);
		if (site == null)
		{
			return points;
		}
		var sites:Array<Site> = site.neighborSites();
		var neighbor:Site;
		for (neighbor in sites)
		{
			points.push(neighbor.coord);
		}
		return points;
	}
	
	public function circles():Array<Circle>
	{
		return _sites.circles();
	}
	
	public function voronoiBoundaryForSite(coord:Point):Array<LineSegment>
	{
		return Delaunay.visibleLineSegments(Delaunay.selectEdgesForSitePoint(coord, _edges));
	}

	public function delaunayLinesForSite(coord:Point):Array<LineSegment>
	{
		return Delaunay.delaunayLinesForEdges(Delaunay.selectEdgesForSitePoint(coord, _edges));
	}
	
	public function voronoiDiagram():Array<LineSegment>
	{
		return Delaunay.visibleLineSegments(_edges);
	}
	
	public function delaunayTriangulation(keepOutMask:BitmapData = null):Array<LineSegment>
	{
		return Delaunay.delaunayLinesForEdges(Delaunay.selectNonIntersectingEdges(keepOutMask, _edges));
	}
	
	public function hull():Array<LineSegment>
	{
		return Delaunay.delaunayLinesForEdges(hullEdges());
	}
	
	private function hullEdges():Array<Edge>
	{
		return _edges.filter(function (edge:Edge):Bool {
			return (edge.isPartOfConvexHull());
		}).array();
	}

	public function hullPointsInOrder():Array<Point>
	{
		var hullEdges:Array<Edge> = hullEdges();
		
		var points:Array<Point> = new Array<Point>();
		if (hullEdges.length == 0)
		{
			return points;
		}
		
		var reorderer:EdgeReorderer = new EdgeReorderer(hullEdges, Criterion.site);
		hullEdges = reorderer.edges;
		var orientations:Array<LR> = reorderer.edgeOrientations;
		reorderer.dispose();
		
		var orientation:LR;

		var n:Int = hullEdges.length;
		for (i in 0...n)
		{
			var edge:Edge = hullEdges[i];
			orientation = orientations[i];
			points.push(edge.site(orientation).coord);
		}
		return points;
	}
	
	public function spanningTree(type:String = "minimum", keepOutMask:BitmapData = null):Array<LineSegment>
	{
		var edges:Array<Edge> = Delaunay.selectNonIntersectingEdges(keepOutMask, _edges);
		var segments:Array<LineSegment> = Delaunay.delaunayLinesForEdges(edges);
		return Kruskal.kruskal(segments, type);
	}

	public function regions():Array<Array<Point>>
	{
		return _sites.regions(plotBounds);
	}
	
	public function siteColors(referenceImage:BitmapData = null):Array<Int>
	{
		return _sites.siteColors(referenceImage);
	}
	
	/**
	 * 
	 * @param proximityMap a BitmapData whose regions are filled with the site index values; see PlanePointsCanvas::fillRegions()
	 * @param x
	 * @param y
	 * @return coordinates of nearest Site to (x, y)
	 * 
	 */
	public function nearestSitePoint(proximityMap:BitmapData, x:Int, y:Int):Point
	{
		return _sites.nearestSitePoint(proximityMap, x, y);
	}
	
	public function siteCoords():Array<Point>
	{
		return _sites.siteCoords();
	}
	
	private function fortunesAlgorithm():Void
	{
		var newSite:Site, bottomSite:Site, topSite:Site, tempSite:Site;
		var v:Vertex, vertex:Vertex;
		var newintstar:Point;
		var leftRight:LR;
		var lbnd:Halfedge, rbnd:Halfedge, llbnd:Halfedge, rrbnd:Halfedge, bisector:Halfedge;
		var edge:Edge;
		
		var dataBounds:Rectangle = _sites.getSitesBounds();
		
		var sqrt_nsites:Int = Std.int(Math.sqrt(_sites.length + 4));
		var heap:HalfedgePriorityQueue = new HalfedgePriorityQueue(dataBounds.y, dataBounds.height, sqrt_nsites);
		var edgeList:EdgeList = new EdgeList(dataBounds.x, dataBounds.width, sqrt_nsites);
		var halfEdges:Array<Halfedge> = new Array<Halfedge>();
		var vertices:Array<Vertex> = new Array<Vertex>();
		
		var bottomMostSite:Site = _sites.next();
		newSite = _sites.next();

		function leftRegion (he:Halfedge):Site
		{
			var edge:Edge = he.edge;
			if (edge == null)
			{
				return bottomMostSite;
			}
			return edge.site(he.leftRight);
		}
		
		function rightRegion (he:Halfedge):Site
		{
			var edge:Edge = he.edge;
			if (edge == null)
			{
				return bottomMostSite;
			}
			return edge.site(LR.other(he.leftRight));
		}
		
		while (true)
		{
			if (heap.empty() == false)
			{
				newintstar = heap.min();
			}
		
			if (newSite != null 
			&&  (heap.empty() || comparePointByYThenX(newSite, newintstar) < 0))
			{
				/* new site is smallest */
				//Lib.trace("smallest: new site " + newSite);
				
				// Step 8:
				lbnd = edgeList.edgeListLeftNeighbor(newSite.coord);	// the Halfedge just to the left of newSite
				//Lib.trace("lbnd: " + lbnd);
				rbnd = lbnd.edgeListRightNeighbor;		// the Halfedge just to the right
				//Lib.trace("rbnd: " + rbnd);
				bottomSite = rightRegion(lbnd);		// this is the same as leftRegion(rbnd)
				// this Site determines the region containing the new site
				//Lib.trace("new Site is in region of existing site: " + bottomSite);
				
				// Step 9:
				edge = Edge.createBisectingEdge(bottomSite, newSite);
				//Lib.trace("new edge: " + edge);
				_edges.push(edge);
				
				bisector = Halfedge.create(edge, LR.LEFT);
				halfEdges.push(bisector);
				// inserting two Halfedges into edgeList constitutes Step 10:
				// insert bisector to the right of lbnd:
				edgeList.insert(lbnd, bisector);
				
				// first half of Step 11:
				vertex = Vertex.intersect(lbnd, bisector);
				if (vertex != null) 
				{
					vertices.push(vertex);
					heap.remove(lbnd);
					lbnd.vertex = vertex;
					lbnd.ystar = vertex.y + newSite.dist(vertex);
					heap.insert(lbnd);
				}
				
				lbnd = bisector;
				bisector = Halfedge.create(edge, LR.RIGHT);
				halfEdges.push(bisector);
				// second Halfedge for Step 10:
				// insert bisector to the right of lbnd:
				edgeList.insert(lbnd, bisector);
				
				// second half of Step 11:
				vertex = Vertex.intersect(bisector, rbnd);
				if (vertex != null)
				{
					vertices.push(vertex);
					bisector.vertex = vertex;
					bisector.ystar = vertex.y + newSite.dist(vertex);
					heap.insert(bisector);	
				}
				
				newSite = _sites.next();	
			}
			else if (heap.empty() == false) 
			{
				/* intersection is smallest */
				lbnd = heap.extractMin();
				llbnd = lbnd.edgeListLeftNeighbor;
				rbnd = lbnd.edgeListRightNeighbor;
				rrbnd = rbnd.edgeListRightNeighbor;
				bottomSite = leftRegion(lbnd);
				topSite = rightRegion(rbnd);
				// these three sites define a Delaunay triangle
				// (not actually using these for anything...)
				//_triangles.push(new Triangle(bottomSite, topSite, rightRegion(lbnd)));
				
				v = lbnd.vertex;
				v.setIndex();
				lbnd.edge.setVertex(lbnd.leftRight, v);
				rbnd.edge.setVertex(rbnd.leftRight, v);
				edgeList.remove(lbnd); 
				heap.remove(rbnd);
				edgeList.remove(rbnd); 
				leftRight = LR.LEFT;
				if (bottomSite.y > topSite.y)
				{
					tempSite = bottomSite; bottomSite = topSite; topSite = tempSite; leftRight = LR.RIGHT;
				}
				edge = Edge.createBisectingEdge(bottomSite, topSite);
				_edges.push(edge);
				bisector = Halfedge.create(edge, leftRight);
				halfEdges.push(bisector);
				edgeList.insert(llbnd, bisector);
				edge.setVertex(LR.other(leftRight), v);
				if ((vertex = Vertex.intersect(llbnd, bisector)) != null)
				{
					vertices.push(vertex);
					heap.remove(llbnd);
					llbnd.vertex = vertex;
					llbnd.ystar = vertex.y + bottomSite.dist(vertex);
					heap.insert(llbnd);
				}
				if ((vertex = Vertex.intersect(bisector, rrbnd)) != null)
				{
					vertices.push(vertex);
					bisector.vertex = vertex;
					bisector.ystar = vertex.y + bottomSite.dist(vertex);
					heap.insert(bisector);
				}
			}
			else
			{
				break;
			}
		}
		
		// heap should be empty now
		heap.dispose();
		edgeList.dispose();
		
		for (halfEdge in halfEdges)
		{
			halfEdge.reallyDispose();
		}
		//halfEdges.length = 0;
		
		// we need the vertices to clip the edges
		for (edge in _edges)
		{
			edge.clipVertices(plotBounds);
		}
		// but we don't actually ever use them again!
		for (vertex in vertices)
		{
			vertex.dispose();
		}
		//vertices.length = 0;
		
	}

	/**
	 * HxDelaunay
	 */
	public inline static function isInfSite(s1:Site, s2:Site) : Bool {
		return (s1.y < s2.y) || (s1.y == s2.y && s1.x < s2.x);
	}
	
	public static function comparePointByYThenX(s1:Site, s2:Point):Int
	{
		return compareByYThenX(s1.x, s1.y, s2.x, s2.y);
	}
	
	public static function compareSiteByYThenX(s1:Site, s2:Site):Int
	{
		return compareByYThenX(s1.x, s1.y, s2.x, s2.y);
	}

	public static function compareByYThenX(s1x:Float, s1y:Float, s2x:Float, s2y:Float):Int
	{
		if (s1y < s2y) return -1;
		if (s1y > s2y) return 1;
		if (s1x < s2x) return -1;
		if (s1x > s2x) return 1;
		return 0;
	}
}
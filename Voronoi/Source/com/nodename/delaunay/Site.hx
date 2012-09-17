package com.nodename.delaunay;

//import as3.PointCore;
//import as3.Rectangle;
import nme.geom.Rectangle;
import nme.geom.Point;
import nme.Lib;
//import as3.TypeDefs;
import com.nodename.geom.Polygon;
import com.nodename.geom.Winding;

import com.nodename.delaunay.EdgeReorderer;

//using as3.RectangleCore;

class Site implements ICoord {

	private static var _pool:Array<Site> = new Array<Site>();
	public static function create(p:Point, index:Int, weight:Float, color:Int):Site
	{
		if (_pool.length > 0)
		{
			return _pool.pop().init(p, index, weight, color);
		}
		else
		{
			return new Site(p, index, weight, color);
		}
	}

	/**
	 * sort sites on y, then x, coord
	 * also change each site's _siteIndex to match its new position in the list
	 * so the _siteIndex can be used to identify the site for nearest-neighbor queries
	 * 
	 * haha "also" - means more than one responsibility...
	 * 
	 */
	public static function sortSites(sites:Array<Site>):Void
	{
		sites.sort(Voronoi.compareSiteByYThenX);
		for (i in 0...sites.length) {
			sites[i]._siteIndex = i;
		}
	}
	
	private static inline var EPSILON:Float = .005;
	private static function closeEnough(p0:Point, p1:Point):Bool
	{
		return Point.distance(p0, p1) < EPSILON;
	}
	public var coord(get_coord, null) : Point;
	private var _coord:Point;
	inline public function get_coord():Point {
		return _coord;
	}
	

	public var color:Int;
	public var weight:Float;
	
	private var _siteIndex:Int;
	
	// the edges that define this Site's Voronoi region:
	private var _edges:Array<Edge>;
	public var edges(get_edges, null):Array<Edge>;
	inline function get_edges():Array<Edge>
	{
		return _edges;
	}
	// which end of each edge hooks up with the previous edge in _edges:
	private var _edgeOrientations:Array<LR>;
	// ordered list of points that define the region clipped to bounds:
	private var _region:Array<Point>;

	private function new(p:Point, index:Int, weight:Float, color:Int)
	{
		init(p, index, weight, color);
	}

	private function init(p:Point, index:Int, weight:Float, color:Int):Site
	{
		_coord = p;
		_siteIndex = index;
		this.weight = weight;
		this.color = color;
		_edges = new Array<Edge>();
		_region = null;
		return this;
	}

	public function toString():String
	{
		return "Site " + _siteIndex + ": " + Std.string(coord);
	}
	
	private function move(p:Point):Void
	{
		clear();
		_coord = p;
	}
	
	public function dispose():Void
	{
		_coord = null;
		clear();
		_pool.push(this);
	}
	
	private function clear():Void
	{
		if (_edges != null)
		{
			_edges = null;
		}
		if (_edgeOrientations != null)
		{
			_edgeOrientations = null;
		}
		if (_region != null)
		{
			_region = null;
		}
	}

	public function addEdge(edge:Edge):Void
	{
		_edges.push(edge);
	}
	
	public function nearestEdge():Edge
	{
		_edges.sort(Edge.compareSitesDistances);
		return _edges[0];
	}
	
	public function neighborSites():Array<Site>
	{
		if (_edges == null || _edges.length == 0)
		{
			return new Array<Site>();
		}
		if (_edgeOrientations == null)
		{ 
			reorderEdges();
		}
		var list:Array<Site> = new Array<Site>();
		var edge:Edge;
		for (edge in _edges)
		{
			list.push(neighborSite(edge));
		}
		return list;
	}
	
	private function neighborSite(edge:Edge):Site
	{
		if (this == edge.leftSite)
		{
			return edge.rightSite;
		}
		if (this == edge.rightSite)
		{
			return edge.leftSite;
		}
		return null;
	}
	
	public function region(clippingBounds:Rectangle):Array<Point>
	{
		//Lib.trace('region called');
		if (_edges == null || _edges.length == 0)
		{
			Lib.trace('empty region array');
			return new Array<Point>();
		}
		if (_edgeOrientations == null)
		{
			//Lib.trace('no edge orientation');
			reorderEdges();
			_region = clipToBounds(clippingBounds);
			if ((new Polygon(_region)).winding() == Winding.CLOCKWISE)
			{
				_region.reverse();
			}
		}
		//Lib.trace(_region.length);
		return _region;
	}

	private function reorderEdges():Void
	{
		//Lib.trace("_edges:"+ _edges);
		var reorderer:EdgeReorderer = new EdgeReorderer(_edges, Criterion.vertex);
		_edges = reorderer.edges;
		//Lib.trace("reordered:"+ _edges);
		_edgeOrientations = reorderer.edgeOrientations;
		reorderer.dispose();
	}

	private function clipToBounds(bounds:Rectangle):Array<Point>
	{
		var points:Array<Point> = new Array<Point>();
		var n:Int = _edges.length;
		var i:Int = 0;
		var edge:Edge;
		while (i < n && (_edges[i].visible == false))
		{
			++i;
		}
		
		if (i == n)
		{
			// no edges visible
			//Lib.trace('no edges visible');
			return new Array<Point>();
		}
		edge = _edges[i];
		var orientation:LR = _edgeOrientations[i];
		points.push(edge.clippedEnds.get(orientation.toString()));
		points.push(edge.clippedEnds.get(LR.other(orientation).toString()));
		
		for (j in (i + 1)...n)
		{
			edge = _edges[j];
			if (edge.visible == false)
			{
				continue;
			}
			connect(points, j, bounds);
		}
		// close up the polygon by adding another corner point of the bounds if needed:
		connect(points, i, bounds, true);
		
		return points;
	}
	
	private function connect(points:Array<Point>, j:Int, bounds:Rectangle, closingUp:Bool = false):Void
	{
		var rightPoint:Point = points[points.length - 1];
		var newEdge:Edge = _edges[j];
		var newOrientation:LR = _edgeOrientations[j];
		// the point that  must be connected to rightPoint:
		var newPoint:Point = newEdge.clippedEnds.get(newOrientation.toString());
		if (!closeEnough(rightPoint, newPoint))
		{
			// The points do not coincide, so they must have been clipped at the bounds;
			// see if they are on the same border of the bounds:
			if (rightPoint.x != newPoint.x
			&&  rightPoint.y != newPoint.y)
			{
				// They are on different borders of the bounds;
				// insert one or two corners of bounds as needed to hook them up:
				// (NOTE this will not be correct if the region should take up more than
				// half of the bounds rect, for then we will have gone the wrong way
				// around the bounds and included the smaller part rather than the larger)
				var rightCheck:Int = BoundsCheck.check(rightPoint, bounds);
				var newCheck:Int = BoundsCheck.check(newPoint, bounds);
				var px:Float, py:Float;
				if (rightCheck & BoundsCheck.RIGHT != 0)
				{
					px = bounds.right;
					if (newCheck & BoundsCheck.BOTTOM != 0)
					{
						py = bounds.bottom;
						points.push(new Point(px, py));
					}
					else if (newCheck & BoundsCheck.TOP != 0)
					{
						py = bounds.top;
						points.push(new Point(px, py));
					}
					else if (newCheck & BoundsCheck.LEFT != 0)
					{
						if (rightPoint.y - bounds.y + newPoint.y - bounds.y < bounds.height)
						{
							py = bounds.top;
						}
						else
						{
							py = bounds.bottom;
						}
						points.push(new Point(px, py));
						points.push(new Point(bounds.left, py));
					}
				}
				else if (rightCheck & BoundsCheck.LEFT != 0)
				{
					px = bounds.left;
					if (newCheck & BoundsCheck.BOTTOM != 0)
					{
						py = bounds.bottom;
						points.push(new Point(px, py));
					}
					else if (newCheck & BoundsCheck.TOP != 0)
					{
						py = bounds.top;
						points.push(new Point(px, py));
					}
					else if (newCheck & BoundsCheck.RIGHT != 0)
					{
						if (rightPoint.y - bounds.y + newPoint.y - bounds.y < bounds.height)
						{
							py = bounds.top;
						}
						else
						{
							py = bounds.bottom;
						}
						points.push(new Point(px, py));
						points.push(new Point(bounds.right, py));
					}
				}
				else if (rightCheck & BoundsCheck.TOP != 0)
				{
					py = bounds.top;
					if (newCheck & BoundsCheck.RIGHT != 0)
					{
						px = bounds.right;
						points.push(new Point(px, py));
					}
					else if (newCheck & BoundsCheck.LEFT != 0)
					{
						px = bounds.left;
						points.push(new Point(px, py));
					}
					else if (newCheck & BoundsCheck.BOTTOM != 0)
					{
						if (rightPoint.x - bounds.x + newPoint.x - bounds.x < bounds.width)
						{
							px = bounds.left;
						}
						else
						{
							px = bounds.right;
						}
						points.push(new Point(px, py));
						points.push(new Point(px, bounds.bottom));
					}
				}
				else if (rightCheck & BoundsCheck.BOTTOM != 0)
				{
					py = bounds.bottom;
					if (newCheck & BoundsCheck.RIGHT != 0)
					{
						px = bounds.right;
						points.push(new Point(px, py));
					}
					else if (newCheck & BoundsCheck.LEFT != 0)
					{
						px = bounds.left;
						points.push(new Point(px, py));
					}
					else if (newCheck & BoundsCheck.TOP != 0)
					{
						if (rightPoint.x - bounds.x + newPoint.x - bounds.x < bounds.width)
						{
							px = bounds.left;
						}
						else
						{
							px = bounds.right;
						}
						points.push(new Point(px, py));
						points.push(new Point(px, bounds.top));
					}
				}
			}
			if (closingUp)
			{
				// newEdge's ends have already been added
				return;
			}
			points.push(newPoint);
		}
		var newRightPoint:Point = newEdge.clippedEnds.get(LR.other(newOrientation).toString());
		if (!closeEnough(points[0], newRightPoint))
		{
			points.push(newRightPoint);
		}
	}

	public var x(getX, null):Float;
	private inline function getX():Float
	{
		return _coord.x;
	}
	public var y(getY, null):Float;
	private inline function getY():Float
	{
		return _coord.y;
	}
	
	public function dist(p:ICoord):Float
	{
		return Point.distance(p.coord, this.coord);
	}	
	
}
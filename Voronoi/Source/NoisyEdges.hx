// Annotate each edge with a noisy path, to make maps look more Interesting.
// Author:amitp@cs.stanford.edu
// License:MIT

package;

  import nme.geom.Point;
  import graph.Center;
import graph.Corner;
import graph.Edge;
  import de.polygonal.math.PM_PRNG;
  
  class NoisyEdges {
static public var NOISY_LINE_TRADEOFF:Float=0.5;// low:jagged vedge;high:jagged dedge

public var path0:Array<Dynamic>;// edge index ->Array<Point>
public var path1:Array<Dynamic>;// edge index ->Array<Point>

public function new(){

path1=[];
path0=[];
}

// Build noisy line paths for of the Voronoi edges. There are
// two noisy line paths for edge, each covering half the
// distance:path0 is from v0 to the midpoint and path1 is from v1
// to the midpoint. When drawing the polygons, one or the other
// must be drawn in reverse order.
public function buildNoisyEdges(map:Map, lava:Lava, random:PM_PRNG):Void {
  var p:Center, edge:Edge;
  for(p in map.centers){
	  for(edge in p.borders){
		  if(edge.d0 != null && edge.d1 != null && edge.v0 != null && edge.v1 != null && path0[edge.index] == null){
			var f:Float=NOISY_LINE_TRADEOFF;
			var t:Point=Point.interpolate(edge.v0.point, edge.d0.point, f);
			var q:Point=Point.interpolate(edge.v0.point, edge.d1.point, f);
			var r:Point=Point.interpolate(edge.v1.point, edge.d0.point, f);
			var s:Point=Point.interpolate(edge.v1.point, edge.d1.point, f);

			var minLength:Int=10;
			if(edge.d0.biome !=edge.d1.biome)minLength=3;
			if(edge.d0.ocean && edge.d1.ocean)minLength=100;
			if(edge.d0.coast || edge.d1.coast)minLength=1;
			if(edge.river > 0 || lava.lava[edge.index] != null)minLength=1;
			
			path0[edge.index]=buildNoisyLineSegments(random, edge.v0.point, t, edge.midpoint, q, minLength);
			path1[edge.index]=buildNoisyLineSegments(random, edge.v1.point, s, edge.midpoint, r, minLength);
		  }
		}
	}
}


// Helper function:build a single noisy line in a quadrilateral A-B-C-D,
// and store the output points in a Vector.
static public function buildNoisyLineSegments(random:PM_PRNG, A:Point, B:Point, C:Point, D:Point, minLength:Float):Array<Point>{
  var points:Array<Point>=new Array<Point>();

  function subdivide(A:Point, B:Point, C:Point, D:Point):Void {
	if(A.subtract(C).length<minLength || B.subtract(D).length<minLength){
	  return;
	}

	// Subdivide the quadrilateral
	var p:Float=random.nextDoubleRange(0.2, 0.8);// vertical(along A-D and B-C)
	var q:Float=random.nextDoubleRange(0.2, 0.8);// horizontal(along A-B and D-C)

	// Midpoints
	var E:Point=Point.interpolate(A, D, p);
	var F:Point=Point.interpolate(B, C, p);
	var G:Point=Point.interpolate(A, B, q);
	var I:Point=Point.interpolate(D, C, q);
	
	// Central point
	var H:Point=Point.interpolate(E, F, q);
	
	// Divide the quad Into subquads, but meet at H
	var s:Float=1.0 - random.nextDoubleRange(-0.4, 0.4);
	var t:Float=1.0 - random.nextDoubleRange(-0.4, 0.4);

	subdivide(A, Point.interpolate(G, B, s), H, Point.interpolate(E, D, t));
	points.push(H);
	subdivide(H, Point.interpolate(F, C, s), C, Point.interpolate(I, D, t));
  }

  points.push(A);
  subdivide(A, B, C, D);
  points.push(C);
  return points;
}
  }
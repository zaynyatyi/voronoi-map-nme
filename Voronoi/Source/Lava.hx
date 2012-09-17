// Randomly place lava on high elevation dry land.
// Author:amitp@cs.stanford.edu
// License:MIT

package;

  import graph.Center;
  import graph.Corner;
  import graph.Edge;
  
  class Lava {
static public var FRACTION_LAVA_FISSURES:Float=0.2;// 0 to 1, probability of fissure

// The lava array marks the edges that hava lava.
public var lava:Array<Dynamic>;// edge index ->Boolean

public function new()
{
	lava=[];
}

// Lava fissures are at high elevations where moisture is low
public function createLava(map:Map, randomDouble:Void -> Float):Void {
  /*var edge:Edge;
  for(edge in map.edges){
	  if(edge.river == null && edge.d0.water == null && edge.d1.water == null
		  && edge.d0.elevation>0.8 && edge.d1.elevation>0.8
		  && edge.d0.moisture<0.3 && edge.d1.moisture<0.3
		  && randomDouble()<FRACTION_LAVA_FISSURES){
		lava[edge.index]=true;
	  }
	}*/
}
  }
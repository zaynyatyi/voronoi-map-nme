package graph;

  import nme.geom.Point;
  
  class Corner {
public var index:Int;
  
public var point:Point;// location
public var ocean:Bool;// ocean
public var water:Bool;// lake or ocean
public var coast:Bool;// touches ocean and land polygons
public var border:Bool;// at the edge of the map
public var elevation:Float;// 0.0-1.0
public var moisture:Float;// 0.0-1.0

public var touches:Array<Center>;
public var protrudes:Array<Edge>;
public var adjacent:Array<Corner>;
  
public var river:Int;// 0 if no river, or volume of water in river
public var downslope:Corner;// pointer to adjacent corner most downhill
public var watershed:Corner;// pointer to coastal corner, or null
public var watershed_size:Int;
public function new(){}
  }


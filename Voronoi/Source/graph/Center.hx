package graph;

  import nme.geom.Point;
  
  class Center {
public var index:Int;
  
public var point:Point;// location
public var water:Bool;// lake or ocean
public var ocean:Bool;// ocean
public var coast:Bool;// land polygon touching an ocean
public var border:Bool;// at the edge of the map
public var biome:String;// biome type(see article)
public var elevation:Float;// 0.0-1.0
public var moisture:Float;// 0.0-1.0

public var neighbors:Array<Center>;
public var borders:Array<Edge>;
public var corners:Array<Corner>;
public function new(){}
  }

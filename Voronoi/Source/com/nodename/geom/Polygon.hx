package com.nodename.geom;

//import as3.TypeDefs;
import nme.geom.Point;

class Polygon {

	private var _vertices:Array<Point>;

	public function new(vertices:Array<Point>) {
		_vertices = vertices;
	}
	
	public function area():Float
	{
		return Math.abs(signedDoubleArea() * 0.5);
	}

	public function winding():Winding
	{
		var signedDoubleArea:Float = signedDoubleArea();
		if (signedDoubleArea < 0)
		{
			return Winding.CLOCKWISE;
		}
		if (signedDoubleArea > 0)
		{
			return Winding.COUNTERCLOCKWISE;
		}
		return Winding.NONE;
	}

	private function signedDoubleArea():Float
	{
		var index:Int, nextIndex:Int;
		var n:Int = _vertices.length;
		var point:Point, next:Point;
		var signedDoubleArea:Float = 0;
		for (index in 0...n)
		{
			nextIndex = (index + 1) % n;
			point = _vertices[index];
			next = _vertices[nextIndex];
			signedDoubleArea += point.x * next.y - next.x * point.y;
		}
		return signedDoubleArea;
	}
	
}
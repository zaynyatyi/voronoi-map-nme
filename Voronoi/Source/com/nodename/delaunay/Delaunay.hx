package com.nodename.delaunay;

//import as3.TypeDefs;
import nme.geom.Point;
import nme.display.BitmapData;
import com.nodename.geom.LineSegment;

using Lambda;
//using as3.BitmapDataCore;

class Delaunay {

	public static function delaunayLinesForEdges(edges:Array<Edge>):Array<LineSegment>
	{
		var segments:Array<LineSegment> = new Array<LineSegment>();
		for (edge in edges)
		{
			segments.push(edge.delaunayLine());
		}
		return segments;
	}

	public static function selectEdgesForSitePoint(coord:Point, edgesToTest:Array<Edge>):Array<Edge>
	{
		return edgesToTest.filter(function (edge:Edge):Bool {
			return ((edge.leftSite != null && edge.leftSite.coord == coord)
			||  (edge.rightSite != null && edge.rightSite.coord == coord));
		}).array();
	}	

	public static function selectNonIntersectingEdges(keepOutMask:BitmapData, edgesToTest:Array<Edge>):Array<Edge>
	{
		if (keepOutMask == null)
		{
			return edgesToTest;
		}
		
		var zeroPoint:Point = new Point(0.0, 0.0);
		return edgesToTest.filter(function (edge:Edge):Bool {
			var delaunayLineBmp:BitmapData = edge.makeDelaunayLineBmp();
			//var notIntersecting:Bool = !(keepOutMask.hitTest(zeroPoint, 1, delaunayLineBmp, zeroPoint, 1));
			delaunayLineBmp.dispose();
			//return notIntersecting;
			return false;
		}).array();
	}
	
	public static function visibleLineSegments(edges:Array<Edge>):Array<LineSegment>
	{
		var segments:Array<LineSegment> = new Array<LineSegment>();
	
		for (edge in edges)
		{
			if (edge.visible)
			{
				var p1:Point = edge.clippedEnds.get(LR.LEFT.toString());
				var p2:Point = edge.clippedEnds.get(LR.RIGHT.toString());
				segments.push(new LineSegment(p1, p2));
			}
		}
		
		return segments;
	}	
	
}
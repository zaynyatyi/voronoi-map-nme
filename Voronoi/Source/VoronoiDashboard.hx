package;

import nme.display.Sprite;
import nme.display.Bitmap;
import nme.display.BitmapData;
import nme.display.Shape;
import nme.Lib;
import nme.geom.Point;
import nme.geom.Rectangle;
import de.polygonal.math.PM_PRNG;
import com.nodename.delaunay.Voronoi;
import graph.Center;
import graph.Corner;
import graph.Edge;

/**
 * ...
 * @author zaynyatyi
 */
 
typedef State = {
	map : Map,
	noisyEdges : NoisyEdges,
	roads : Roads,
	watersheds : Watersheds,
	lava : Lava
}

class VoronoiDashboard extends Sprite {

	private static var seed:PM_PRNG;
	private static var image:Bitmap;
	private static var state:State;
	private static var SIZE:Size = {width:800, height:600};


	static public var displayColors = {
		// Features
		OCEAN: 0x44447a,
		COAST: 0x33335a,
		LAKESHORE: 0x225588,
		LAKE: 0x336699,
		RIVER: 0x225588,
		MARSH: 0x2f6666,
		ICE: 0x99ffff,
		BEACH: 0xa09077,
		ROAD1: 0x442211,
		ROAD2: 0x553322,
		ROAD3: 0x664433,
		BRIDGE: 0x686860,
		LAVA: 0xcc3333,
		
		// Terrain
		SNOW: 0xffffff,
		TUNDRA: 0xbbbbaa,
		BARE: 0x888888,
		SCORCHED: 0x555555,
		TAIGA: 0x99aa77,
		SHRUBLAND: 0x889977,
		TEMPERATE_DESERT: 0xc9d29b,
		TEMPERATE_RAIN_FOREST: 0x448855,
		TEMPERATE_DECIDUOUS_FOREST: 0x679459,
		GRASSLAND: 0x88aa55,
		SUBTROPICAL_DESERT: 0xd2b98b,
		TROPICAL_RAIN_FOREST: 0x337755,
		TROPICAL_SEASONAL_FOREST: 0x559944
    };

    static public var elevationGradientColors = {
		OCEAN: 0x008800,
		GRADIENT_LOW: 0x008800,
		GRADIENT_HIGH: 0xffff00
    };	

	public function new () 
	{
		super ();
		Lib.trace('ololo');
		image = new Bitmap(new BitmapData(SIZE.width, SIZE.height));
		seed = new PM_PRNG();
		state = generate();
		addChild(image);
		
		/*var points:Array<Point> = new Array<Point>();
		for(i in 0...50)
		{
			points.push(new Point(Math.random()*800, Math.random()*600));
		}
		var voronoi:Voronoi = new Voronoi(points, null, new Rectangle(0, 0, 800, 600));*/
	}
	
	public static function generate() : State 
	{
		var tmp_state = { map : null, noisyEdges : null, roads : null, watersheds : null, lava : null };
		tmp_state.map = new Map(SIZE);
		tmp_state.map.newIsland('Blob', 85882, 8);
		//tmp_state.map.go(0,6);
		tmp_state.map.go(0,6);
		tmp_state.watersheds = new Watersheds();
		tmp_state.noisyEdges = new NoisyEdges();
		tmp_state.lava = new Lava();
		tmp_state.roads = new Roads();
		
		tmp_state.roads.createRoads(tmp_state.map);
		tmp_state.watersheds.createWatersheds(tmp_state.map);
		//tmp_state.noisyEdges.buildNoisyEdges(tmp_state.map, tmp_state.lava, seed);
		render(tmp_state);
		
		return tmp_state;
	}
	
	private static function render( tmp_state : State ) : Void 
	{
		//reset graphic
		renderDebugPolygons(image, tmp_state.map);
	}
	
	public static function renderDebugPolygons(bitmap:Bitmap, map:Map):Void 
	{
		Lib.trace('in render debug poly');
		var shape:Shape = new Shape();
		var p:Center, q:Corner, edge:Edge, point:Point, color:Int;
		if (map.centers.length == 0) {
			Lib.trace('there is 0 map.centers: ' + Std.string(map.centers.length));
	        // We're still constructing the map so we may have some points
	        shape.graphics.beginFill(0xdddddd);
	        shape.graphics.drawRect(0, 0, map.SIZE.width, map.SIZE.height);
	        shape.graphics.endFill();
	        for (point in map.points) {
	        	//Lib.trace('point addd: ' + Std.string(point.x) + '-' + Std.string(point.y));
	            shape.graphics.beginFill(0x000000);
	            shape.graphics.drawCircle(point.x, point.y, 1.3);
	            shape.graphics.endFill();
	        }
	    }
	      
		for (p in map.centers) 
		{
		  //Lib.trace(p.biome);
		  color = NullHelper.IsNotNull(p.biome) ? Reflect.field(displayColors, p.biome) : (p.ocean ? displayColors.OCEAN : p.water ? displayColors.RIVER : 0xffffff);
		  //color = Reflect.field(displayColors, p.biome);
		  shape.graphics.beginFill(interpolateColor(color, 0xdddddd, 0.2));
		  for (edge in p.borders) {
		      if (edge.v0 != null && edge.v1 != null) {
		        shape.graphics.moveTo(p.point.x, p.point.y);
		        shape.graphics.lineTo(edge.v0.point.x, edge.v0.point.y);
		        if (edge.river > 0) {
		          shape.graphics.lineStyle(2, displayColors.RIVER, 1.0);
		        } else {
		          shape.graphics.lineStyle(0, 0x000000, 0.4);
		        }
		        shape.graphics.lineTo(edge.v1.point.x, edge.v1.point.y);
		        shape.graphics.lineStyle();
		      }
		  }
		  shape.graphics.endFill();
		  shape.graphics.beginFill(p.water ? 0x003333 : 0x000000, 0.7);
		  shape.graphics.drawCircle(p.point.x, p.point.y, 1.3);
		  shape.graphics.endFill();
		  for (q in p.corners) {
		      shape.graphics.beginFill(NullHelper.IsNotNull(q.water) ? 0x0000ff : 0x009900);
		      shape.graphics.drawRect(q.point.x-0.7, q.point.y-0.7, 1.5, 1.5);
		      shape.graphics.endFill();
		  }
		}
		bitmap.bitmapData.draw(shape,null,null,null,new Rectangle(0,0,map.SIZE.width, map.SIZE.height));
	}
	
	private static function interpolateColor(color0:Int, color1:Int, f:Float):Int {
      var r:Int = Std.int((1-f)*(color0 >> 16) + f*(color1 >> 16));
      var g:Int = Std.int((1-f)*((color0 >> 8) & 0xff) + f*((color1 >> 8) & 0xff));
      var b:Int = Std.int((1-f)*(color0 & 0xff) + f*(color1 & 0xff));
      if (r > 255) r = 255;
      if (g > 255) g = 255;
      if (b > 255) b = 255;
      return (r << 16) | (g << 8) | b;
    }
	
	public static function main () 
	{
		Lib.current.addChild (new VoronoiDashboard ());
	}	
}



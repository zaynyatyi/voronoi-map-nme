package;

import nme.display.Sprite;
import nme.display.Bitmap;
import nme.display.BitmapData;
import nme.display.Shape;
import nme.display.Graphics;
import nme.display.GradientType;
import nme.display.SpreadMethod;
import nme.Lib;
import nme.geom.Point;
import nme.geom.Rectangle;
import nme.geom.Vector3D;
import nme.geom.Matrix;

import de.polygonal.math.PM_PRNG;
import com.nodename.delaunay.Voronoi;
import graph.Center;
import graph.Corner;
import graph.Edge;

/**
 * ...
 * @author zaynyatyi
 */

using Lambda;

typedef State = {
		map : Map,
      	noisyEdges : NoisyEdges,
      	roads : Roads,
      	watersheds : Watersheds,
      	lava : Lava
}

class VoronoiDashboard extends Sprite {

    private static var seed:PM_PRNG;
    #if flash
    private static var image:Bitmap;
    #end
    private static var shape:Shape;
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
        //Lib.trace('ololo');
        shape = new Shape();
        
        seed = new PM_PRNG();
        state = generate();
        
        //addChild(image);
        #if flash
        	image = new Bitmap(new BitmapData(SIZE.width, SIZE.height));
        	image.bitmapData.draw(shape,null,null,null,new Rectangle(0,0,SIZE.width, SIZE.height));
        	addChild(image);
        #elseif js
        	addChild(shape);
        #else
        	//should be tested on android
        	addChild(shape);
        #end

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
        tmp_state.map.newIsland('Perlin', 85882, 8);
        //tmp_state.map.go(0,6);
        tmp_state.map.go(0,6);
        tmp_state.watersheds = new Watersheds();
        tmp_state.noisyEdges = new NoisyEdges();
        tmp_state.lava = new Lava();
        tmp_state.roads = new Roads();

        //tmp_state.roads.createRoads(tmp_state.map);
        //tmp_state.watersheds.createWatersheds(tmp_state.map);
        tmp_state.lava.createLava(tmp_state.map, seed.nextDouble);
        tmp_state.noisyEdges.buildNoisyEdges(tmp_state.map, tmp_state.lava, seed);
        render(tmp_state);

        return tmp_state;
    }

    private static function render( tmp_state : State ) : Void 
    {
        //reset graphic
        if(false) //just while debugging
        {
        	renderDebugPolygons(shape.graphics, tmp_state.map, tmp_state.lava);
        	//renderDebugPolygons(c, state.map, Style.displayColors);
        }else{
        	//renderPolygons(c, Style.displayColors, null, CanvasRender.colorWithSlope, state.map, state.noisyEdges);
			//renderEdges(c, Style.displayColors, state.map, state.noisyEdges, state.lava, true);
			renderPolygons(shape.graphics, null, colorWithSlope, tmp_state.map, tmp_state.noisyEdges);
			renderEdges(shape.graphics, tmp_state.map, tmp_state.noisyEdges, tmp_state.lava);
        }
    }


	// Render the exterior of polygons: coastlines, lake shores,
    // rivers, lava fissures. We draw all of these after the polygons
    // so that polygons don't overwrite any edges.
    public static function renderEdges(graphics:Graphics, map:Map, noisyEdges:NoisyEdges, lava:Lava):Void {
      //var shape:Shape = new Shape();
      var p:Center, r:Center, edge:Edge;

      for(p in map.centers) {
          for(r in p.neighbors) {
              edge = map.lookupEdgeFromCenter(p, r);
              if (noisyEdges.path0[edge.index] == null
                  || noisyEdges.path1[edge.index] == null) {
                // It's at the edge of the map
                continue;
              }
              if (p.ocean != r.ocean) {
                // One side is ocean and the other side is land -- coastline
                graphics.lineStyle(2, displayColors.COAST);
              } else if ((p.water) != (r.water) && p.biome != 'ICE' && r.biome != 'ICE') {
                // Lake boundary
                graphics.lineStyle(1, displayColors.LAKESHORE);
              } else if (p.water || r.water) {
                // Lake interior – we don't want to draw the rivers here
                continue;
              } else if (lava.lava[edge.index]) {
                // Lava flow
                graphics.lineStyle(1, displayColors.LAVA);
              } else if (edge.river > 0) {
                // River edge
                graphics.lineStyle(Math.sqrt(edge.river), displayColors.RIVER);
              } else {
                // No edge
                continue;
              }
              
              graphics.moveTo(noisyEdges.path0[edge.index][0].x,
                              noisyEdges.path0[edge.index][0].y);
              drawPathForwards(graphics, noisyEdges.path0[edge.index]);
              drawPathBackwards(graphics, noisyEdges.path1[edge.index]);
              graphics.lineStyle();
            }
        }
        //bitmap.bitmapData.draw(shape,null,null,null,new Rectangle(0,0,map.SIZE.width, map.SIZE.height));
    }

	public static function renderPolygons(graphics:Graphics, gradientFillProperty:String, 
		colorOverrideFunction:Int->Center->Center->Edge->Int, 
		map:Map, noisyEdges:NoisyEdges):Void 
	{
		var shape:Shape = new Shape();
		var p:Center, r:Center;

      // My Voronoi polygon rendering doesn't handle the boundary
      // polygons, so I just fill everything with ocean first.
      graphics.beginFill(displayColors.OCEAN);
      graphics.drawRect(0, 0, SIZE.width, SIZE.height);
      graphics.endFill();
      
      for (p in map.centers) {
          for(r in p.neighbors) {
              var edge:Edge = map.lookupEdgeFromCenter(p, r);
              var color:Int = NullHelper.IsNotNull(Reflect.field(displayColors, p.biome)) ? Reflect.field(displayColors, p.biome) : 0;
              if (colorOverrideFunction != null) {
                color = colorOverrideFunction(color, p, r, edge);
              }

              function drawPath0():Void {
                var path:Array<Point> = noisyEdges.path0[edge.index];
                graphics.moveTo(p.point.x, p.point.y);
                graphics.lineTo(path[0].x, path[0].y);
                drawPathForwards(graphics, path);
                graphics.lineTo(p.point.x, p.point.y);
              }

              function drawPath1():Void {
                var path:Array<Point> = noisyEdges.path1[edge.index];
                graphics.moveTo(p.point.x, p.point.y);
                graphics.lineTo(path[0].x, path[0].y);
                drawPathForwards(graphics, path);
                graphics.lineTo(p.point.x, p.point.y);
              }

              if (noisyEdges.path0[edge.index] == null
                  || noisyEdges.path1[edge.index] == null) {
                // It's at the edge of the map, where we don't have
                // the noisy edges computed. TODO: figure out how to
                // fill in these edges from the voronoi library.
                continue;
              }

              if (gradientFillProperty != null) {
                // We'll draw two triangles: center - corner0 -
                // midpoint and center - midpoint - corner1.
                var corner0:Corner = edge.v0;
                var corner1:Corner = edge.v1;

                // We pick the midpoint elevation/moisture between
                // corners instead of between polygon centers because
                // the resulting gradients tend to be smoother.
                var midpoint:Point = edge.midpoint;
                var midpointAttr:Float = 0.5*(Reflect.field(corner0, gradientFillProperty)
                	+ Reflect.field(corner1, gradientFillProperty));
                drawGradientTriangle
                  (graphics,
                   new Vector3D(p.point.x, p.point.y, Reflect.field(p, gradientFillProperty)),
                   new Vector3D(corner0.point.x, corner0.point.y, Reflect.field(corner0,gradientFillProperty)),
                   new Vector3D(midpoint.x, midpoint.y, midpointAttr),
                   [elevationGradientColors.GRADIENT_LOW, elevationGradientColors.GRADIENT_HIGH], drawPath0);
                drawGradientTriangle
                  (graphics,
                   new Vector3D(p.point.x, p.point.y, Reflect.field(p, gradientFillProperty)),
                   new Vector3D(midpoint.x, midpoint.y, midpointAttr),
                   new Vector3D(corner1.point.x, corner1.point.y, Reflect.field(corner1,gradientFillProperty)),
                   [elevationGradientColors.GRADIENT_LOW, elevationGradientColors.GRADIENT_HIGH], drawPath1);
              } else {
                graphics.beginFill(color);
                drawPath0();
                drawPath1();
                graphics.endFill();
              }
            }
        }
        //bitmap.bitmapData.draw(shape,null,null,null,new Rectangle(0,0,map.SIZE.width, map.SIZE.height));
	}

	private static function drawPathForwards(graphics:Graphics, path:Array<Point>):Void {
		for(i in 0...path.length) {
			graphics.lineTo(path[i].x, path[i].y);
		}
	}
	
	private static function drawPathBackwards(graphics:Graphics, path:Array<Point>):Void {
      for (i in 0...path.length) {
        graphics.lineTo(path[i].x, path[i].y);
      }
    }

	/**
	 * Helper function for drawing triangles with gradients. This
	 * function sets up the fill on the graphics object, and then
	 * calls fillFunction to draw the desired path.
	 */
    private static function drawGradientTriangle(graphics:Graphics,
                                          v1:Vector3D, v2:Vector3D, v3:Vector3D,
                                          colors:Array<Int>, fillFunction:Void->Void):Void {
      var m:Matrix = new Matrix();

      // Center of triangle:
      var V:Vector3D = v1.add(v2).add(v3);
      V.scaleBy(1/3.0);

      // Normal of the plane containing the triangle:
      var N:Vector3D = v2.subtract(v1).crossProduct(v3.subtract(v1));
      N.normalize();

      // Gradient vector in x-y plane pointing in the direction of increasing z
      var G:Vector3D = new Vector3D(-N.x/N.z, -N.y/N.z, 0);

      // Center of the color gradient
      var C:Vector3D = new Vector3D(V.x - G.x*((V.z-0.5)/G.length/G.length), V.y - G.y*((V.z-0.5)/G.length/G.length));

      if (G.length < 1e-6) {
        // If the gradient vector is small, there's not much
        // difference in colors across this triangle. Use a plain
        // fill, because the numeric accuracy of 1/G.length is not to
        // be trusted.  NOTE: only works for 1, 2, 3 colors in the array
        var color:Int = colors[0];
        if (colors.length == 2) {
          color = interpolateColor(colors[0], colors[1], V.z);
        } else if (colors.length == 3) {
          if (V.z < 0.5) {
            color = interpolateColor(colors[0], colors[1], V.z*2);
          } else {
            color = interpolateColor(colors[1], colors[2], V.z*2-1);
          }
        }
		graphics.beginFill(color);
      } else {
        // The gradient box is weird to set up, so we let Flash set up
        // a basic matrix and then we alter it:
        m.createGradientBox(1, 1, 0, 0, 0);
        m.translate(-0.5, -0.5);
        m.scale((1/G.length), (1/G.length));
        m.rotate(Math.atan2(G.y, G.x));
        m.translate(C.x, C.y);
        var alphas = Lambda.array(Lambda.map(colors, function (c:Int) { return 1.0; } ));
        var spread = Lambda.array(Lambda.mapi(colors, function (index:Int, c:Int) { return 255 * index / (colors.length - 1); } ));
        graphics.beginGradientFill(GradientType.LINEAR, colors, alphas, spread, m, SpreadMethod.PAD);
      }
      fillFunction();
	  graphics.endFill();
    }	

    public static function renderDebugPolygons(graphics:Graphics, map:Map, lava:Lava):Void 
    {
        Lib.trace('in render debug poly');
        var shape:Shape = new Shape();
        var p:Center, q:Corner, edge:Edge, point:Point, color:Int;
        if (map.centers.length == 0) {
            Lib.trace('there is 0 map.centers: ' + Std.string(map.centers.length));
            // We're still constructing the map so we may have some points
            graphics.beginFill(0xdddddd);
            graphics.drawRect(0, 0, map.SIZE.width, map.SIZE.height);
            graphics.endFill();
            for (point in map.points) {
                //Lib.trace('point addd: ' + Std.string(point.x) + '-' + Std.string(point.y));
                graphics.beginFill(0x000000);
                graphics.drawCircle(point.x, point.y, 1.3);
                graphics.endFill();
            }
        }

        for (p in map.centers) 
        {
            //Lib.trace(p.biome);
            color = NullHelper.IsNotNull(p.biome) ? Reflect.field(displayColors, p.biome) : (p.ocean ? displayColors.OCEAN : p.water ? displayColors.RIVER : 0xffffff);
            //color = Reflect.field(displayColors, p.biome);
            graphics.beginFill(interpolateColor(color, 0xdddddd, 0.2));
            for (edge in p.borders) {
                if (edge.v0 != null && edge.v1 != null) {
                    graphics.moveTo(p.point.x, p.point.y);
                    graphics.lineTo(edge.v0.point.x, edge.v0.point.y);
                    if (edge.river > 0) {
                        graphics.lineStyle(2, displayColors.RIVER, 1.0);
                    } else if (lava.lava[edge.index]) {
                    	graphics.lineStyle(2, displayColors.LAVA, 1.0);
                    } else {
                        graphics.lineStyle(0, 0x000000, 0.4);
                    }
                    graphics.lineTo(edge.v1.point.x, edge.v1.point.y);
                    graphics.lineStyle();
                }
            }
            graphics.endFill();
            graphics.beginFill(p.water ? 0x003333 : 0x000000, 0.7);
            graphics.drawCircle(p.point.x, p.point.y, 1.3);
            graphics.endFill();
            for (q in p.corners) {
                graphics.beginFill(NullHelper.IsNotNull(q.water) ? 0x0000ff : 0x009900);
                graphics.drawRect(q.point.x-0.7, q.point.y-0.7, 1.5, 1.5);
                graphics.endFill();
            }
        }
        //bitmap.bitmapData.draw(shape,null,null,null,new Rectangle(0,0,map.SIZE.width, map.SIZE.height));
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
    
    public static function colorWithSlope(color:Int, p:Center, q:Center, edge:Edge):Int {
		var r:Corner = edge.v0;
		var s:Corner = edge.v1;
		if (NullHelper.IsNull(r) || NullHelper.IsNull(s)) {
			// Edge of the map
			return displayColors.OCEAN;
		} else if (p.water) {
			return color;
		}
		//return color;

		if (q != null && p.water == q.water) color = interpolateColor(color, Reflect.field(displayColors, q.biome), 0.4);
		var colorLow:Int = interpolateColor(color, 0x333333, 0.3); //0.7
		var colorHigh:Int = interpolateColor(color, 0xffffff, 0.1); //0.3
		var light:Float = calculateLighting(p, r, s);
		if (light < 0.5) return interpolateColor(colorLow, color, light*2);
		else return interpolateColor(color, colorHigh, light*2-1);
    }

	private static var lightVector:Vector3D = new Vector3D(-1, -1, 0);
    public static function calculateLighting(p:Center, r:Corner, s:Corner):Float {
		var A:Vector3D = new Vector3D(p.point.x, p.point.y, p.elevation);
		var B:Vector3D = new Vector3D(r.point.x, r.point.y, r.elevation);
		var C:Vector3D = new Vector3D(s.point.x, s.point.y, s.elevation);
		var normal:Vector3D = B.subtract(A).crossProduct(C.subtract(A));
		if (normal.z < 0) { normal.scaleBy(-1); }
		normal.normalize();
		var light:Float = 0.5 + 35*normal.dotProduct(lightVector);
		if (light < 0) light = 0;
		if (light > 1) light = 1;
		return light;
    }

    public static function main () 
    {
        Lib.current.addChild (new VoronoiDashboard ());
    }	
}



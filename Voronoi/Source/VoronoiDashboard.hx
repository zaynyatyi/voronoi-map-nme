package;

import nme.display.Sprite;
import nme.Lib;
import nme.geom.Point;
import nme.geom.Rectangle;
import com.nodename.delaunay.Voronoi;

/**
 * ...
 * @author zaynyatyi
 */
/*class VoronoiDashboard extends Sprite {

  public function new () {

  super ();
  var points:Array<Point> = new Array<Point>();
  for(i in 0...50)
  {
  points.push(new Point(Math.random()*800, Math.random()*600));
  }
  var voronoi:Voronoi = new Voronoi(points, null, new Rectangle(0, 0, 800, 600));


  }

  public static function main () {

  Lib.current.addChild (new VoronoiDashboard ());

  }	

  }*/

// Display the voronoi graph produced in Map.as
// Author:amitp@cs.stanford.edu
// License:MIT

import graph.Center;
import graph.Corner;
import graph.Edge;
//import flash.geom.*;
//import nme.display.*;
import nme.events.Event;
import nme.events.TimerEvent;
import nme.events.MouseEvent;
//import flash.text.*;
import nme.text.TextField;
import nme.text.TextFormat;
import nme.text.TextFormatAlign;
import nme.display.Bitmap;
import nme.display.BitmapData;
import nme.display.Shape;
//import flash.utils.ByteArray<Dynamic>;
import nme.utils.ByteArray;
import nme.utils.Timer;
import nme.display.IGraphicsData;
import nme.display.Graphics;
import nme.display.GradientType;
import nme.geom.Vector3D;
import nme.geom.Matrix3D;
import nme.geom.Matrix;
//import flash.utils.getTimer;
//import flash.utils.Timer;
//import flash.net.FileReference;
//import flash.system.System;
import nme.display.LineScaleMode;
import nme.display.CapsStyle;
import de.polygonal.math.PM_PRNG;
import nme.display.BlendMode;
import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.display.StageQuality;
import nme.display.SpreadMethod;



//[SWF(width="800", height="600", frameRate=60)]
class VoronoiDashboard extends Sprite {
    static public var SIZE:Size = { width : 800, height : 600};

    static public var displayColors:Dynamic={
        // Features
OCEAN:0x44447a,
      COAST:0x33335a,
      LAKESHORE:0x225588,
      LAKE:0x336699,
      RIVER:0x225588,
      MARSH:0x2f6666,
      ICE:0x99ffff,
      BEACH:0xa09077,
      ROAD1:0x442211,
      ROAD2:0x553322,
      ROAD3:0x664433,
      BRIDGE:0x686860,
      LAVA:0xcc3333,

      // Terrain
      SNOW:0xffffff,
      TUNDRA:0xbbbbaa,
      BARE:0x888888,
      SCORCHED:0x555555,
      TAIGA:0x99aa77,
      SHRUBLAND:0x889977,
      TEMPERATE_DESERT:0xc9d29b,
      TEMPERATE_RAIN_FOREST:0x448855,
      TEMPERATE_DECIDUOUS_FOREST:0x679459,
      GRASSLAND:0x88aa55,
      SUBTROPICAL_DESERT:0xd2b98b,
      TROPICAL_RAIN_FOREST:0x337755,
      TROPICAL_SEASONAL_FOREST:0x559944
    };

    static public var elevationGradientColors:Dynamic={
OCEAN:0x008800,
      GRADIENT_LOW:0x008800,
      GRADIENT_HIGH:0xffff00
    };

    static public var moistureGradientColors:Dynamic={
OCEAN:0x4466ff,
      GRADIENT_LOW:0xbbaa33,
      GRADIENT_HIGH:0x4466ff
    };

    // Island shape is controlled by the islandRandom seed and the
    // type of island. The islandShape function uses both of them to
    // determine whether any point should be water or land.
    public var islandType:String;
    static public var islandSeedInitial:String="85882-1";

    // GUI for controlling the map generation and view
    public var controls:Sprite;
    public var islandSeedInput:TextField;
    public var statusBar:TextField;

    // This is the current map style. UI buttons change this, and it
    // persists when you make a new map. The timer is used only when
    // the map mode is '3d'.
    public var mapMode:String;
    public var render3dTimer:Timer;
    public var noiseLayer:Bitmap;

    // These store 3d rendering data
    private var rotationAnimation:Float;
    private var triangles3d:Array<Dynamic>;
    private var graphicsData:Array<IGraphicsData>;

    // The map data
    public var map:Map;
    public var roads:Roads;
    public var lava:Lava;
    public var watersheds:Watersheds;
    public var noisyEdges:NoisyEdges;


    public function new(){
        super();
        addEventListener(Event.ADDED_TO_STAGE, Init);
        
    }

	private function Init(e:Event):Void
	{
		removeEventListener(Event.ADDED_TO_STAGE, Init);
		trace('ololo1');
		islandType='Perlin';
		// GUI for controlling the map generation and view
		controls=new Sprite();
		// the map mode is '3d'.
		mapMode='smooth';
		render3dTimer=new Timer(1000/20, 0);
		noiseLayer=new Bitmap(new BitmapData(SIZE.width, SIZE.height));
		_guiQueue=[];
		lightVector=new Vector3D(-1, -1, 0);
		trace('ololo2');
		// These store 3d rendering data
		rotationAnimation=0.0;
		triangles3d=[];	
        trace('ololo3');
        stage.scaleMode=StageScaleMode.NO_SCALE;
        stage.align=StageAlign.TOP_LEFT;
		trace('ololo4');
        addChild(noiseLayer);
        noiseLayer.bitmapData.noise(555, 128-10, 128+10, 7, true);
        noiseLayer.blendMode=BlendMode.HARDLIGHT;
		trace('ololo5');
        controls.x=SIZE.width;
        addChild(controls);
		
        /*addExportButtons();
        addViewButtons();
        addGenerateButtons();*/
        addMiscLabels();
		trace('ololo6');
        map=new Map(SIZE);
        go(islandType);

        render3dTimer.addEventListener(TimerEvent.TIMER, function(e:TimerEvent):Void {
                // TODO:don't draw this while the map is being built
                drawMap(mapMode);
                });
	}
    // Random parameters governing the overall shape of the island
    public function newIsland(type:String):Void {
        var seed:Int=0, variant:Int=0;
        //var t:Float=getTimer();

        if(islandSeedInput.text.length==0){
            islandSeedInput.text=Std.string(Math.ceil((Math.random()*100000)));
        }
		var regex:EReg = ~/\s*(\d+)(?:\-(\d+))\s*$/;
        var match:Bool=regex.match(islandSeedInput.text);
        if(match ==true){
            // It's of the format SHAPE-VARIANT
            //seed=Std.parseInt(regex.matched[1]); //TODO fix here
            //variant=Std.parseInt(regex.matched || "0"); //TODO fix here
        }
        if(seed==0){
            // Convert the string Into a number. This is a cheesy way to
            // do it but it doesn't matter. It just allows people to use
            // words as seeds.
            for(i in 0...islandSeedInput.text.length){
                seed=(seed<<4)| islandSeedInput.text.charCodeAt(i);
            }
            seed %=100000;
            variant=1+Math.floor(9*Math.random());
        }
        islandType=type;
        map.newIsland(type, seed, variant);
    }


    public function graphicsReset():Void {
        triangles3d=[];
        graphics.clear();
        graphics.beginFill(0xbbbbaa);
        graphics.drawRect(0, 0, 2000, 2000);
        graphics.endFill();
        graphics.beginFill(displayColors.OCEAN);
        graphics.drawRect(0, 0, SIZE.width, SIZE.height);
        graphics.endFill();
    }


    public function go(type:String):Void {
        cancelCommands();

        roads=new Roads();
        lava=new Lava();
        watersheds=new Watersheds();
        noisyEdges=new NoisyEdges();

        commandExecute("Shaping map...",
                function():Void {
                newIsland(type);
                });

        commandExecute("Placing points...",
                function():Void {
                map.go(0, 1);
                drawMap('polygons');
                });

        commandExecute("Improving points...",
                function():Void {
                map.go(1, 2);
                drawMap('polygons');
                });

        commandExecute("Building graph...",
                function():Void {
                map.go(2, 3);
                map.assignBiomes();
                drawMap('polygons');
                });

        commandExecute("Features...",
                function():Void {
                map.go(3, 6);
                map.assignBiomes();
                drawMap('polygons');
                });

        commandExecute("Edges...",
                function():Void {
                roads.createRoads(map);
                // lava.createLava(map, map.mapRandom.nextDouble);
                watersheds.createWatersheds(map);
                noisyEdges.buildNoisyEdges(map, lava, map.mapRandom);
                drawMap(mapMode);
                });
    }


    // Command queue is processed on ENTER_FRAME. If it's empty,
    // remove the handler.
    private var _guiQueue:Array<Dynamic>;
    private function _onEnterFrame(e:Event):Void {
        (_guiQueue.shift()[1])();
        if(_guiQueue.length==0){
            stage.removeEventListener(Event.ENTER_FRAME, _onEnterFrame);
            statusBar.text="";
        } else {
            statusBar.text=_guiQueue[0][0];
        }
    }

    public function cancelCommands():Void {
        if(_guiQueue.length !=0){
            stage.removeEventListener(Event.ENTER_FRAME, _onEnterFrame);
            statusBar.text="";
            _guiQueue=[];
        }
    }

    public function commandExecute(status:String, command:Void -> Void):Void {
    	trace(status);
    	trace('ololo7');
        if(_guiQueue.length==0){
        	trace('ololo8');
            statusBar.text=status;
            trace('ololo8.1');
            stage.addEventListener(Event.ENTER_FRAME, _onEnterFrame);
        }
        trace('ololo9');
        _guiQueue.push([status, command]);
    }


    // Show some information about the maps
    private static var _biomeMap:Array<Dynamic>=
        ['BEACH', 'LAKE', 'ICE', 'MARSH', 'SNOW', 'TUNDRA', 'BARE', 'SCORCHED',
        'TAIGA', 'SHRUBLAND', 'TEMPERATE_DESERT', 'TEMPERATE_RAIN_FOREST',
        'TEMPERATE_DECIDUOUS_FOREST', 'GRASSLAND', 'SUBTROPICAL_DESERT',
        'TROPICAL_RAIN_FOREST', 'TROPICAL_SEASONAL_FOREST'];
    public function drawHistograms():Void {
        // There are pairs of functions for chart. The bucket
        // function maps the polygon Center to a small Int, and the
        // color function maps the Int to a color.
        function landTypeBucket(p:Center):Int {
            if(p.ocean)return 1;
            else if(p.coast)return 2;
            else if(p.water)return 3;
            else return 4;
        }
        function landTypeColor(bucket:Int):Int {
            if(bucket==1)return displayColors.OCEAN;
            else if(bucket==2)return displayColors.BEACH;
            else if(bucket==3)return displayColors.LAKE;
            else return displayColors.TEMPERATE_DECIDUOUS_FOREST;
        }
        function elevationBucket(p:Center):Int {
            if(p.ocean)return -1;
            else return Math.floor(p.elevation*10);
        }
        function elevationColor(bucket:Int):Int {
            return InterpolateColor(displayColors.TEMPERATE_DECIDUOUS_FOREST,
                    displayColors.GRASSLAND, bucket*0.1);
        }
        function moistureBucket(p:Center):Int {
            if(p.water)return -1;
            else return Math.floor(p.moisture*10);
        }
        function moistureColor(bucket:Int):Int {
            return InterpolateColor(displayColors.BEACH, displayColors.RIVER, bucket*0.1);
        }
        function biomeBucket(p:Center):Int {
            return Lambda.indexOf(_biomeMap, p.biome);
        }
        function biomeColor(bucket:Int):Int {
            return displayColors[_biomeMap[bucket]];
        }

        function computeHistogram(bucketFn:Center -> Int):Array<Dynamic> {
            var p:Center, histogram:Array<Dynamic>, bucket:Int;
            histogram=[];
            for(p in map.centers){
                bucket=bucketFn(p);
                if(bucket>=0)histogram[bucket]=(histogram[bucket] == null ? 0 : histogram[bucket])+ 1;
            }
            return histogram;
        }

        function drawHistogram(x:Float, y:Float, bucketFn:Center -> Int, colorFn:Int -> Int,
                width:Float, height:Float):Void {
            var scale:Float;//, i:Int;
            var histogram:Array<Dynamic>=computeHistogram(bucketFn);

            scale=0.0;
            for(i in 0...histogram.length){
                scale=Math.max(scale, histogram[i] == null ? 0 : histogram[i]);
            }
            for(i in 0...histogram.length){
                if(histogram[i]){
                    graphics.beginFill(colorFn(i));
                    graphics.drawRect(SIZE.width+x+i*width/histogram.length, y+height,
                            Math.max(0, width/histogram.length-1), -height*histogram[i]/scale);
                    graphics.endFill();
                }
            }
        }

        function drawDistribution(x:Float, y:Float, bucketFn:Center -> Int, colorFn:Int -> Int,
                width:Float, height:Float):Void {
            var scale:Float,/* i:Int, */x:Float = 0.0, w:Float;
            var histogram:Array<Dynamic>=computeHistogram(bucketFn);

            scale=0.0;
            for(i in 0...histogram.length){
                scale +=histogram[i] == null ? 0.0 : histogram[i];
            }
            for(i in 0...histogram.length){
                if(histogram[i]){
                    graphics.beginFill(colorFn(i));
                    w=histogram[i]/scale*width;
                    graphics.drawRect(SIZE.width+x, y, Math.max(0, w-1), height);
                    x +=w;
                    graphics.endFill();
                }
            }
        }

        var x:Float=23, y:Float=140, width:Float=154;
        drawDistribution(x, y, landTypeBucket, landTypeColor, width, 20);
        drawDistribution(x, y+25, biomeBucket, biomeColor, width, 20);

        drawHistogram(x, y+55, elevationBucket, elevationColor, width, 30);
        drawHistogram(x, y+95, moistureBucket, moistureColor, width, 20);
    }


    // Helper functions for rendering paths
    private function drawPathForwards(graphics:Graphics, path:Array<Point>):Void {
        for(i in 0...path.length){
            graphics.lineTo(path[i].x, path[i].y);
        }
    }
    private function drawPathBackwards(graphics:Graphics, path:Array<Point>):Void {
        for(i in path.length-1...0){
            graphics.lineTo(path[i].x, path[i].y);
        }
    }


    // Helper function for color manipulation. When f==0:color0, f==1:color1
    private function InterpolateColor(color0:Int, color1:Int, f:Float):Int {
        var r:Int=Std.int((1-f)*(color0>>16)+ f*(color1>>16));
        var g:Int=Std.int((1-f)*((color0>>8)& 0xff)+ f*((color1>>8)& 0xff));
        var b:Int=Std.int((1-f)*(color0 & 0xff)+ f*(color1 & 0xff));
        if(r>255)r=255;
        if(g>255)g=255;
        if(b>255)b=255;
        return(r<<16)|(g<<8)| b;
    }


    // Helper function for drawing triangles with gradients. This
    // function sets up the fill on the graphics object, and then
    // calls fillFunction to draw the desired path.
    private function drawGradientTriangle(graphics:Graphics,
            v1:Vector3D, v2:Vector3D, v3:Vector3D,
            colors:Array<Int>, fillFunction:Void -> Void):Void {
        var m:Matrix=new Matrix();

        // Center of triangle:
        var V:Vector3D=v1.add(v2).add(v3);
        V.scaleBy(1/3.0);

        // Normal of the plane containing the triangle:
        var N:Vector3D=v2.subtract(v1).crossProduct(v3.subtract(v1));
        N.normalize();

        // Gradient vector in x-y plane pointing in the direction of increasing z
        var G:Vector3D=new Vector3D(-N.x/N.z, -N.y/N.z, 0);

        // Center of the color gradient
        var C:Vector3D=new Vector3D(V.x - G.x*((V.z-0.5)/G.length/G.length), V.y - G.y*((V.z-0.5)/G.length/G.length));

        if(G.length<1e-6){
            // If the gradient vector is small, there's not much
            // difference in colors across this triangle. Use a plain
            // fill, because the numeric accuracy of 1/G.length is not to
            // be trusted.  NOTE:only works for 1, 2, 3 colors in the array
            var color:Int=colors[0];
            if(colors.length==2){
                color=InterpolateColor(colors[0], colors[1], V.z);
            } else if(colors.length==3){
                if(V.z<0.5){
                    color=InterpolateColor(colors[0], colors[1], V.z*2);
                } else {
                    color=InterpolateColor(colors[1], colors[2], V.z*2-1);
                }
            }
            graphics.beginFill(color);
        } else {
            // The gradient box is weird to set up, so we let Flash set up
            // a basic matrix and then we alter it:
            m.createGradientBox(1, 1, 0, 0, 0);
            m.translate(-0.5, -0.5);
            m.scale((1/G.length),(1/G.length));
            m.rotate(Math.atan2(G.y, G.x));
            m.translate(C.x, C.y);
            var alphas:List<Float> = Lambda.map(colors, function (c:Int) { return 1.0; } );
        	var spread:List<Float> = Lambda.mapi(colors, function (index:Int, c:Int) { return 255 * index / (colors.length - 1); } );
            graphics.beginGradientFill(GradientType.LINEAR, colors, Lambda.array(alphas), 
            Lambda.array(spread), m, SpreadMethod.PAD);
        }
        fillFunction();
        graphics.endFill();
    }


    // Draw the map in the current map mode
    public function drawMap(mode:String):Void {
        graphicsReset();
        noiseLayer.visible=true;

        drawHistograms();

        if(mode=='3d'){
            if(!render3dTimer.running)render3dTimer.start();
            noiseLayer.visible=false;
            render3dPolygons(graphics, displayColors, colorWithSlope);
            return;
        } else if(mode=='polygons'){
            noiseLayer.visible=false;
            renderDebugPolygons(graphics, displayColors);
        } else if(mode=='watersheds'){
            noiseLayer.visible=false;
            renderDebugPolygons(graphics, displayColors);
            renderWatersheds(graphics);
            return;
        } else if(mode=='biome'){
            renderPolygons(graphics, displayColors, null, null);
        } else if(mode=='slopes'){
            renderPolygons(graphics, displayColors, null, colorWithSlope);
        } else if(mode=='smooth'){
            renderPolygons(graphics, displayColors, null, colorWithSmoothColors);
        } else if(mode=='elevation'){
            renderPolygons(graphics, elevationGradientColors, 'elevation', null);
        } else if(mode=='moisture'){
            renderPolygons(graphics, moistureGradientColors, 'moisture', null);
        }

        if(render3dTimer.running)render3dTimer.stop();

        if(mode !='slopes' && mode !='moisture'){
            renderRoads(graphics, displayColors);
        }
        if(mode !='polygons'){
            renderEdges(graphics, displayColors);
        }
        if(mode !='slopes' && mode !='moisture'){
            renderBridges(graphics, displayColors);
        }
    }


    // 3D rendering of polygons. If the 'triangles3d' array is empty,
    // it's filled and the graphicsData is filled in as well. On
    // rendering, the triangles3d array has to be z-sorted and then
    // the resulting polygon data is transferred Into graphicsData
    // before rendering.
    public function render3dPolygons(graphics:Graphics, colors:Dynamic, 
    colorFunction:Int -> Center -> Center -> Edge -> Int):Void {
        /*var p:Center, q:Corner, edge:Edge;
        var zScale:Float=0.15*SIZE;

        graphics.beginFill(colors.OCEAN);
        graphics.drawRect(0, 0, SIZE.width, SIZE.height);
        graphics.endFill();

        if(triangles3d.length==0){
            graphicsData=new Array<IGraphicsData>();
            for(p in map.centers){
                if(p.ocean)continue;
                for(edge in p.borders){
                    var color:Int=colors[p.biome] || 0;
                    if(colorFunction !=null){
                        color=colorFunction(color, p, q, edge);
                    }

                    // We'll draw two triangles:center - corner0 -
                    // midpoint and center - midpoint - corner1.
                    var corner0:Corner=edge.v0;
                    var corner1:Corner=edge.v1;

                    if(corner0==null || corner1==null){
                        // Edge of the map;we can't deal with it right now
                        continue;
                    }

                    var zp:Float=zScale*p.elevation;
                    var z0:Float=zScale*corner0.elevation;
                    var z1:Float=zScale*corner1.elevation;
                    triangles3d.push({
					a:new Vector3D(p.point.x, p.point.y, zp),
					b:new Vector3D(corner0.point.x, corner0.point.y, z0),
					c:new Vector3D(corner1.point.x, corner1.point.y, z1),
					rA:null,
					rB:null,
					rC:null,
					z:0.0,
					color:color
					});
					graphicsData.push(new GraphicsSolidFill());
					graphicsData.push(new GraphicsPath(Array<Int>([GraphicsPathCommand.MOVE_TO, GraphicsPathCommand.LINE_TO, GraphicsPathCommand.LINE_TO]),
					            Array<Float>([0, 0, 0, 0, 0, 0])));
					graphicsData.push(new GraphicsEndFill());
				}
			}
		}

		var camera:Matrix3D=new Matrix3D();
		camera.appendRotation(rotationAnimation, new Vector3D(0, 0, 1), new Vector3D(SIZE.width/2, SIZE.height/2));
		camera.appendRotation(60, new Vector3D(1,0,0), new Vector3D(SIZE.width/2, SIZE.height/2));
		rotationAnimation +=1;
		
		for(tri in triangles3d){
		    tri.rA=camera.transformVector(tri.a);
		    tri.rB=camera.transformVector(tri.b);
		    tri.rC=camera.transformVector(tri.c);
		    tri.z=(tri.rA.z + tri.rB.z + tri.rC.z)/3;
		}
		triangles3d.sortOn('z', Array.NUMERIC);
		
		for(i in 0...triangles3d.length){
		    tri=triangles3d[i];
		    GraphicsSolidFill(graphicsData[i*3]).color=tri.color;
		    var data:Array<Float>=GraphicsPath(graphicsData[i*3+1]).data;
		    data[0]=tri.rA.x;
		    data[1]=tri.rA.y;
		    data[2]=tri.rB.x;
		    data[3]=tri.rB.y;
		    data[4]=tri.rC.x;
		    data[5]=tri.rC.y;
		}
		graphics.drawGraphicsData(graphicsData);*/
}


// Render the Interior of polygons
public function renderPolygons(graphics:Graphics, colors:Dynamic, 
gradientFillProperty:String, colorOverrideFunction:Int -> Center -> Center -> Edge -> Int):Void {
    var p:Center, r:Center;

    // My Voronoi polygon rendering doesn't handle the boundary
    // polygons, so I just fill everything with ocean first.
    graphics.beginFill(colors.OCEAN);
    graphics.drawRect(0, 0, SIZE.width, SIZE.height);
    graphics.endFill();

    for(p in map.centers){
        for(r in p.neighbors){
            var edge:Edge=map.lookupEdgeFromCenter(p, r);
            var color:Int=Reflect.field(colors, p.biome) == null ? 0 : Reflect.field(colors, p.biome);
            if(colorOverrideFunction !=null){
                color=colorOverrideFunction(color, p, r, edge);
            }

            function drawPath0():Void {
                var path:Array<Point>=noisyEdges.path0[edge.index];
                graphics.moveTo(p.point.x, p.point.y);
                graphics.lineTo(path[0].x, path[0].y);
                drawPathForwards(graphics, path);
                graphics.lineTo(p.point.x, p.point.y);
            }

            function drawPath1():Void {
                var path:Array<Point>=noisyEdges.path1[edge.index];
                graphics.moveTo(p.point.x, p.point.y);
                graphics.lineTo(path[0].x, path[0].y);
                drawPathForwards(graphics, path);
                graphics.lineTo(p.point.x, p.point.y);
            }

            if(noisyEdges.path0[edge.index]==null
                    || noisyEdges.path1[edge.index]==null){
                // It's at the edge of the map, where we don't have
                // the noisy edges computed. TODO:figure out how to
                // fill in these edges from the voronoi library.
                continue;
            }

            if(gradientFillProperty !=null){
                // We'll draw two triangles:center - corner0 -
                // midpoint and center - midpoint - corner1.
                var corner0:Corner=edge.v0;
                var corner1:Corner=edge.v1;

                // We pick the midpoint elevation/moisture between
                // corners instead of between polygon centers because
                // the resulting gradients tend to be smoother.
                var midpoint:Point=edge.midpoint;
                var midpointAttr:Float=0.5 * (Reflect.field(corner0, gradientFillProperty) + Reflect.field(corner1, gradientFillProperty));
                drawGradientTriangle
                    (graphics,
                     new Vector3D(p.point.x, p.point.y, Reflect.field(p, gradientFillProperty)),
                     new Vector3D(corner0.point.x, corner0.point.y, Reflect.field(corner0, gradientFillProperty)),
                     new Vector3D(midpoint.x, midpoint.y, midpointAttr),
                     [colors.GRADIENT_LOW, colors.GRADIENT_HIGH], drawPath0);
                drawGradientTriangle
                    (graphics,
                     new Vector3D(p.point.x, p.point.y, Reflect.field(p, gradientFillProperty)),
                     new Vector3D(midpoint.x, midpoint.y, midpointAttr),
                     new Vector3D(corner1.point.x, corner1.point.y, Reflect.field(corner0, gradientFillProperty)),
                     [colors.GRADIENT_LOW, colors.GRADIENT_HIGH], drawPath1);
            } else {
                graphics.beginFill(color);
                drawPath0();
                drawPath1();
                graphics.endFill();
            }
        }
    }
}


// Render bridges across every narrow river edge. Bridges are
// straight line segments perpendicular to the edge. Bridges are
// drawn after rivers. TODO:sometimes the bridges aren't long
// enough to cross the entire noisy line river. TODO:bridges
// don't line up with curved road segments when there are
// roads. It might be worth making a shader that draws the bridge
// only when there's water underneath.
public function renderBridges(graphics:Graphics, colors:Dynamic):Void {
    var edge:Edge;

    for(edge in map.edges){
        if(edge.river>0 && edge.river<4
                && !edge.d0.water && !edge.d1.water
                &&(edge.d0.elevation>0.05 || edge.d1.elevation>0.05)){
            var n:Point=new Point(-(edge.v1.point.y - edge.v0.point.y), edge.v1.point.x - edge.v0.point.x);
            n.normalize(0.25 +(roads.road[edge.index]? 0.5:0)+ 0.75*Math.sqrt(edge.river));
            graphics.lineStyle(1.1, colors.BRIDGE, 1.0, false, LineScaleMode.NORMAL, CapsStyle.SQUARE);
            graphics.moveTo(edge.midpoint.x - n.x, edge.midpoint.y - n.y);
            graphics.lineTo(edge.midpoint.x + n.x, edge.midpoint.y + n.y);
            graphics.lineStyle();
        }
    }
}


// Render roads. We draw these before polygon edges, so that rivers overwrite roads.
public function renderRoads(graphics:Graphics, colors:Dynamic):Void {
    // First draw the roads, because any other feature should draw
    // over them. Also, roads don't use the noisy lines.
    var p:Center, A:Point, B:Point, C:Point;
    var i:Int, j:Int, d:Float, edge1:Edge, edge2:Edge, edges:Array<Edge>;

    // Helper function:find the normal vector across edge 'e' and
    // make sure to point it in a direction towards 'c'.
    function normalTowards(e:Edge, c:Point, len:Float):Point {
        // Rotate the v0-->v1 vector by 90 degrees:
        var n:Point=new Point(-(e.v1.point.y - e.v0.point.y), e.v1.point.x - e.v0.point.x);
        // Flip it around it if doesn't point towards c
        var d:Point=c.subtract(e.midpoint);
        if(n.x * d.x + n.y * d.y<0){
            n.x=-n.x;
            n.y=-n.y;
        }
        n.normalize(len);
        return n;
    }

    for(p in map.centers){
        if(roads.roadConnections[p.index]){
            if(roads.roadConnections[p.index].length==2){
                // Regular road:draw a spline from one edge to the other.
                edges=p.borders;
                for(i in 0...edges.length){
                    edge1=edges[i];
                    if(roads.road[edge1.index]>0){
                        for(j in i+1...edges.length){
                            edge2=edges[j];
                            if(roads.road[edge2.index]>0){
                                // The spline connects the midpoints of the edges
                                // and at right angles to them. In between we
                                // generate two control points A and B and one
                                // additional vertex C.  This usually works but
                                // not always.
                                d=0.5*Math.min
                                    (edge1.midpoint.subtract(p.point).length,
                                     edge2.midpoint.subtract(p.point).length);
                                A=normalTowards(edge1, p.point, d).add(edge1.midpoint);
                                B=normalTowards(edge2, p.point, d).add(edge2.midpoint);
                                C=Point.interpolate(A, B, 0.5);
                                graphics.lineStyle(1.1, Reflect.field(colors, "ROAD" + roads.road[edge1.index]));
                                graphics.moveTo(edge1.midpoint.x, edge1.midpoint.y);
                                graphics.curveTo(A.x, A.y, C.x, C.y);
                                graphics.lineStyle(1.1, Reflect.field(colors, "ROAD" + roads.road[edge2.index]));
                                graphics.curveTo(B.x, B.y, edge2.midpoint.x, edge2.midpoint.y);
                                graphics.lineStyle();
                            }
                        }
                    }
                }
            } else {
                // Intersection or dead end:draw a road spline from
                // each edge to the center
                for(edge1 in p.borders){
                    if(roads.road[edge1.index]>0){
                        d=0.25*edge1.midpoint.subtract(p.point).length;
                        A=normalTowards(edge1, p.point, d).add(edge1.midpoint);
                        graphics.lineStyle(1.4, Reflect.field(colors, "ROAD" + roads.road[edge1.index]));
                        graphics.moveTo(edge1.midpoint.x, edge1.midpoint.y);
                        graphics.curveTo(A.x, A.y, p.point.x, p.point.y);
                        graphics.lineStyle();
                    }
                }
            }
        }
    }
}


// Render the exterior of polygons:coastlines, lake shores,
// rivers, lava fissures. We draw all of these after the polygons
// so that polygons don't overwrite any edges.
public function renderEdges(graphics:Graphics, colors:Dynamic):Void {
    var p:Center, r:Center, edge:Edge;

    for(p in map.centers){
        for(r in p.neighbors){
            edge=map.lookupEdgeFromCenter(p, r);
            if(noisyEdges.path0[edge.index]==null
                    || noisyEdges.path1[edge.index]==null){
                // It's at the edge of the map
                continue;
            }
            if(p.ocean !=r.ocean){
                // One side is ocean and the other side is land -- coastline
                graphics.lineStyle(2, colors.COAST);
            } else if((p.water)!=(r.water)&& p.biome !='ICE' && r.biome !='ICE'){
                // Lake boundary
                graphics.lineStyle(1, colors.LAKESHORE);
            } else if(p.water || r.water){
                // Lake Interior – we don't want to draw the rivers here
                continue;
            } else if(lava.lava[edge.index]){
                // Lava flow
                graphics.lineStyle(1, colors.LAVA);
            } else if(edge.river>0){
                // River edge
                graphics.lineStyle(Math.sqrt(edge.river), colors.RIVER);
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
}


// Render the polygons so that each can be seen clearly
public function renderDebugPolygons(graphics:Graphics, colors:Dynamic):Void {
    var p:Center, q:Corner, edge:Edge, point:Point, color:Int;

    if(map.centers.length==0){
        // We're still constructing the map so we may have some points
        graphics.beginFill(0xdddddd);
        graphics.drawRect(0, 0, SIZE.width, SIZE.height);
        graphics.endFill();
        for(point in map.points){
            graphics.beginFill(0x000000);
            graphics.drawCircle(point.x, point.y, 1.3);
            graphics.endFill();
        }
    }

    for(p in map.centers){
        color=p.biome != null ? Reflect.field(displayColors, p.biome) : (p.ocean ? displayColors.OCEAN : p.water ? displayColors.RIVER : 0xffffff);
        graphics.beginFill(InterpolateColor(color, 0xdddddd, 0.2));
        for(edge in p.borders){
            if(edge.v0 != null && edge.v1 != null){
                graphics.moveTo(p.point.x, p.point.y);
                graphics.lineTo(edge.v0.point.x, edge.v0.point.y);
                if(edge.river>0){
                    graphics.lineStyle(2, displayColors.RIVER, 1.0);
                } else {
                    graphics.lineStyle(0, 0x000000, 0.4);
                }
                graphics.lineTo(edge.v1.point.x, edge.v1.point.y);
                graphics.lineStyle();
            }
        }
        graphics.endFill();
        graphics.beginFill(p.water ? 0x003333:0x000000, 0.7);
        graphics.drawCircle(p.point.x, p.point.y, 1.3);
        graphics.endFill();
        for(q in p.corners){
            graphics.beginFill(q.water? 0x0000ff:0x009900);
            graphics.drawRect(q.point.x-0.7, q.point.y-0.7, 1.5, 1.5);
            graphics.endFill();
        }
    }
}


// Render the paths from each polygon to the ocean, showing watersheds
public function renderWatersheds(graphics:Graphics):Void {
    /*var edge:Edge, w0:Int, w1:Int;

    for(edge in map.edges){
        if(edge.d0 != null && edge.d1 != null && edge.v0 != null && edge.v1 != null
                && !edge.d0.ocean != null && !edge.d1.ocean != null){
            w0=watersheds.watersheds[edge.d0.index];
            w1=watersheds.watersheds[edge.d1.index];
            if(w0 !=w1){
                graphics.lineStyle(3.5, 0x000000, 0.1*Math.sqrt((map.corners[w0].watershed_size || 1)+(map.corners[w1].watershed.watershed_size || 1)));
                graphics.moveTo(edge.v0.point.x, edge.v0.point.y);
                graphics.lineTo(edge.v1.point.x, edge.v1.point.y);
                graphics.lineStyle();
            }
        }
    }

    for(edge in map.edges){
        if(edge.river != null){
            graphics.lineStyle(1.0, 0x6699ff);
            graphics.moveTo(edge.v0.point.x, edge.v0.point.y);
            graphics.lineTo(edge.v1.point.x, edge.v1.point.y);
            graphics.lineStyle();
        }
    }*/
}


private var lightVector:Vector3D;
public function calculateLighting(p:Center, r:Corner, s:Corner):Float {
    var A:Vector3D=new Vector3D(p.point.x, p.point.y, p.elevation);
    var B:Vector3D=new Vector3D(r.point.x, r.point.y, r.elevation);
    var C:Vector3D=new Vector3D(s.point.x, s.point.y, s.elevation);
    var normal:Vector3D=B.subtract(A).crossProduct(C.subtract(A));
    if(normal.z<0){ normal.scaleBy(-1);}
    normal.normalize();
    var light:Float=0.5 + 35*normal.dotProduct(lightVector);
    if(light<0)light=0;
    if(light>1)light=1;
    return light;
}

public function colorWithSlope(color:Int, p:Center, q:Center, edge:Edge):Int {
    var r:Corner=edge.v0;
    var s:Corner=edge.v1;
    if(r == null || s == null){
        // Edge of the map
        return displayColors.OCEAN;
    } else if(p.water){
        return color;
    }

    if(q !=null && p.water==q.water)color=InterpolateColor(color, Reflect.field(displayColors, q.biome), 0.4);
    var colorLow:Int=InterpolateColor(color, 0x333333, 0.7);
    var colorHigh:Int=InterpolateColor(color, 0xffffff, 0.3);
    var light:Float=calculateLighting(p, r, s);
    if(light<0.5)return InterpolateColor(colorLow, color, light*2);
    else return InterpolateColor(color, colorHigh, light*2-1);
}


public function colorWithSmoothColors(color:Int, p:Center, q:Center, edge:Edge):Int {
    if(q !=null && p.water==q.water){
        color=InterpolateColor(Reflect.field(displayColors, p.biome), Reflect.field(displayColors, q.biome), 0.25);
    }
    return color;
}


//////////////////////////////////////////////////////////////////////
// The following code is used to export the maps to disk

// We export elevation, moisture, and an override byte. Instead of
// rendering with RGB values, we render with bytes 0x00-0xff as
// colors, and then save these bytes in a ByteArray. For override
// codes, we turn off anti-aliasing.
static public var exportOverrideColors:Dynamic={
    /* override codes are 0:none, 0x10:river water, 0x20:lava,
0x30:snow, 0x40:ice, 0x50:ocean, 0x60:lake, 0x70:lake shore,
0x80:ocean shore, 0x90,0xa0,0xb0:road, 0xc0:bridge.  These
are ORed with 0x01:polygon center, 0x02:safe polygon
center. */
POLYGON_CENTER:0x01,
               POLYGON_CENTER_SAFE:0x03,
               OCEAN:0x50,
               COAST:0x80,
               LAKE:0x60,
               LAKESHORE:0x70,
               RIVER:0x10,
               MARSH:0x10,
               ICE:0x40,
               LAVA:0x20,
               SNOW:0x30,
               ROAD1:0x90,
               ROAD2:0xa0,
               ROAD3:0xb0,
               BRIDGE:0xc0
};

static public var exportElevationColors:Dynamic={
OCEAN:0x00,
      GRADIENT_LOW:0x00,
      GRADIENT_HIGH:0xff
};

static public var exportMoistureColors:Dynamic={
OCEAN:0xff,
      GRADIENT_LOW:0x00,
      GRADIENT_HIGH:0xff
};


// This function draws to a bitmap and copies that data Into the
// three export byte arrays.  The layer parameter should be one of
// 'elevation', 'moisture', 'overrides'.
public function makeExport(layer:String):Void {
    /*var exportBitmap:BitmapData=new BitmapData(2048, 2048);
    var exportGraphics:Shape=new Shape();
    var exportData:ByteArray=new ByteArray();

    var m:Matrix=new Matrix();
    m.scale(2048.0 / SIZE.width, 2048.0 / SIZE.height);

    function saveBitmapToArray():Void {
        for(x in 0...2048){
            for(y in 0...2048){
                exportData.writeByte(exportBitmap.getPixel(x, y)& 0xff);
            }
        }
    }

    if(layer=='overrides'){
        renderPolygons(exportGraphics.graphics, exportOverrideColors, null, null);
        renderRoads(exportGraphics.graphics, exportOverrideColors);
        renderEdges(exportGraphics.graphics, exportOverrideColors);
        renderBridges(exportGraphics.graphics, exportOverrideColors);

        stage.quality=StageQuality.LOW;
        exportBitmap.draw(exportGraphics, m);
        stage.quality=StageQuality.BEST;

        // Mark the polygon centers in the export bitmap
        for(p in map.centers){
            if(!p.ocean){
                var r:Point=new Point(Math.floor(p.point.x * 2048/SIZE.width),
                        Math.floor(p.point.y * 2048/SIZE.height));
                exportBitmap.setPixel(Std.int(r.x), Std.int(r.y),
                        exportBitmap.getPixel(Std.int(r.x), Std.int(r.y))
                        |(Reflect.field(roads.roadConnections, p)?
                            exportOverrideColors.POLYGON_CENTER_SAFE
                            :exportOverrideColors.POLYGON_CENTER));
            }
        }

        saveBitmapToArray();
    } else if(layer=='elevation'){
        renderPolygons(exportGraphics.graphics, exportElevationColors, 'elevation', null);
        exportBitmap.draw(exportGraphics, m);
        saveBitmapToArray();
    } else if(layer=='moisture'){
        renderPolygons(exportGraphics.graphics, exportMoistureColors, 'moisture', null);
        exportBitmap.draw(exportGraphics, m);
        saveBitmapToArray();
    }
    return exportData;*/
}


// Export the graph data as XML.
public function exportPolygons():String {
    return "not yet";
    // NOTE:For performance, we do not assemble the entire XML in
    // memory and then serialize it. Instead, we incrementally
    // serialize small portions Into arrays of strings, and then assemble the
    // strings together.
    /*var p:Center, q:Corner, r:Center, s:Corner, edge:Edge;
      XML.prettyPrinting=false;
      var top:XML =
      <map 
      shape={islandSeedInput.text}
      type={islandType}
      size={Map.NUM_POINTS}>
      <generator
      url=\"http://www-cs-students.stanford.edu/~amitp/game-programming/polygon-map-generation/\"
      timestamp={new Date().toUTCString()} />
      <REPLACE/>
      </map>";

      var dnodes:Array<Dynamic>=[];
      var edges:Array<Dynamic>=[];
      var vnodes:Array<Dynamic>=[];
      var outroads:Array<Dynamic>=[];
      var accum:Array<Dynamic>=[];// temporary accumulator for serialized xml fragments
      var edgeNode:XML;

      for(p in map.centers){
      accum.splice(0, accum.length);

      for(r in p.neighbors){
      accum.push(<center id={r.index}/>.toXMLString());
      }
      for(edge in p.borders){
      accum.push(<edge id={edge.index}/>.toXMLString());
      }
      for(q in p.corners){
      accum.push(<corner id={q.index}/>.toXMLString());
      }

      dnodes.push
      (<center id={p.index}
      x={p.point.x} y={p.point.y}
      water={p.water} ocean={p.ocean}
      coast={p.coast} border={p.border}
      biome={p.biome}
      elevation={p.elevation} moisture={p.moisture}>
      <REPLACE/>
      </center>.toXMLString().replace("<REPLACE/>", accum.join("")));
      }

      for(edge in map.edges){
      edgeNode=
      <edge id={edge.index} river={edge.river}/>;
      if(edge.midpoint !=null){
      edgeNode.@x=edge.midpoint.x;
      edgeNode.@y=edge.midpoint.y;
      }
      if(edge.d0 !=null)edgeNode.@center0=edge.d0.index;
      if(edge.d1 !=null)edgeNode.@center1=edge.d1.index;
      if(edge.v0 !=null)edgeNode.@corner0=edge.v0.index;
      if(edge.v1 !=null)edgeNode.@corner1=edge.v1.index;
      edges.push(edgeNode.toXMLString());
      }

      for(q in map.corners){
      accum.splice(0, accum.length);
      for(p in q.touches){
      accum.push(<center id={p.index}/>.toXMLString());
      }
      for(edge in q.protrudes){
      accum.push(<edge id={edge.index}/>.toXMLString());
      }
      for(s in q.adjacent){
      accum.push(<corner id={s.index}/>.toXMLString());
      }

      vnodes.push
    (<corner id={q.index}
     x={q.point.x} y={q.point.y}
     water={q.water} ocean={q.ocean}
     coast={q.coast} border={q.border}
     elevation={q.elevation} moisture={q.moisture}
     river={q.river} downslope={q.downslope?q.downslope.index:-1}>
     <REPLACE/>
     </corner>.toXMLString().replace("<REPLACE/>", accum.join("")));
}

for(i in roads.road){
    outroads.push(<road edge={i} contour={roads.road[i]} />.toXMLString());
}

var out:String=top.toXMLString();
accum=[].concat("<centers>",
        dnodes, "</centers><edges>",
        edges, "</edges><corners>",
        vnodes, "</corners><roads>",
        outroads, "</roads>");
out=out.replace("<REPLACE/>", accum.join(""));
return out;*/
}


// Make a button or label. If the callback is null, it's just a label.
public function makeButton(label:String, x:Int, y:Int, width:Int, callback_fn:Event -> Void):TextField {
    var button:TextField=new TextField();
    var format:TextFormat=new TextFormat();
    format.font="Arial";
    format.align=TextFormatAlign.CENTER;
    button.defaultTextFormat=format;
    button.text=label;
    button.selectable=false;
    button.x=x;
    button.y=y;
    button.width=width;
    button.height=20;
    if(callback_fn !=null){
        button.background=true;
        button.backgroundColor=0xffffcc;
        button.addEventListener(MouseEvent.CLICK, callback_fn);
    }
    return button;
}

public function addMiscLabels():Void {
    controls.addChild(makeButton("Distribution:", 50, 120, 100, null));
    statusBar=makeButton("", Math.ceil(SIZE.width/2)-50, 10, 100, null);
    addChild(statusBar);
}

/*public function addGenerateButtons():Void {
    var y:Int=4;
    var islandShapeButton:TextField=makeButton("Island Shape:", 25, y, 150, null);

    var seedLabel:TextField=makeButton("Shape #", 20, y+22, 50, null);

    islandSeedInput=makeButton(islandSeedInitial, 70, y+22, 54, null);
    islandSeedInput.background=true;
    islandSeedInput.backgroundColor=0xccddcc;
    islandSeedInput.selectable=true;
    islandSeedInput.type=TextFieldType.INPUT;
    islandSeedInput.addEventListener(KeyboardEvent.KEY_UP, function(e:KeyboardEvent):Void {
            if(e.keyCode==13){
            go(islandType);
            }
            });

    function markActiveIslandShape(type:String):Void {
        mapTypes[islandType].backgroundColor=0xffffcc;
        mapTypes[type].backgroundColor=0xffff00;
    }

    function switcher(type:String):Function {
        return function(e:Event):Void {
            markActiveIslandShape(type);
            go(type);
        }
    }

    var mapTypes:Dynamic={
        'Radial':makeButton("Radial", 23, y+44, 40, switcher('Radial')),
        'Perlin':makeButton("Perlin", 65, y+44, 35, switcher('Perlin')),
        'Square':makeButton("Square", 102, y+44, 44, switcher('Square')),
        'Blob':makeButton("Blob", 148, y+44, 29, switcher('Blob'))
    };
    markActiveIslandShape(islandType);

    controls.addChild(islandShapeButton);
    controls.addChild(seedLabel);
    controls.addChild(islandSeedInput);
    controls.addChild(makeButton("Random", 125, y+22, 56,
                function(e:Event):Void {
                islandSeedInput.text=
                ((Math.random()*100000).toFixed(0)
                 + "-"
                 +(1 + Math.floor(9*Math.random())).toFixed(0));
                go(islandType);
                }));
    controls.addChild(mapTypes.Radial);
    controls.addChild(mapTypes.Perlin);
    controls.addChild(mapTypes.Square);
    controls.addChild(mapTypes.Blob);
}


public function addViewButtons():Void {
    var y:Int=300;

	var views:ObjectHash<String, >

    function markViewButton(mode:String):Void {
        views[mapMode].backgroundColor=0xffffcc;
        views[mode].backgroundColor=0xffff00;
    }

    function switcher(mode:String):Event -> Void {
        return function(e:Event):Void {
            markViewButton(mode);
            mapMode=mode;
            drawMap(mapMode);
        }
    }

    var views:Dynamic={
        'biome':makeButton("Biomes", 25, y+22, 74, switcher('biome')),
        'smooth':makeButton("Smooth", 101, y+22, 74, switcher('smooth')),
        'slopes':makeButton("2D slopes", 25, y+44, 74, switcher('slopes')),
        '3d':makeButton("3D slopes", 101, y+44, 74, switcher('3d')),
        'elevation':makeButton("Elevation", 25, y+66, 74, switcher('elevation')),
        'moisture':makeButton("Moisture", 101, y+66, 74, switcher('moisture')),
        'polygons':makeButton("Polygons", 25, y+88, 74, switcher('polygons')),
        'watersheds':makeButton("Watersheds", 101, y+88, 74, switcher('watersheds'))
    };

    markViewButton(mapMode);

    controls.addChild(makeButton("View:", 50, y, 100, null));

    controls.addChild(views.biome);
    controls.addChild(views.smooth);
    controls.addChild(views.slopes);
    controls.addChild(views['3d']);
    controls.addChild(views.elevation);
    controls.addChild(views.moisture);
    controls.addChild(views.polygons);
    controls.addChild(views.watersheds);
}


public function addMiscLabels():Void {
    controls.addChild(makeButton("Distribution:", 50, 120, 100, null));
    statusBar=makeButton("", SIZE/2-50, 10, 100, null);
    addChild(statusBar);
}


public function addExportButtons():Void {
    var y:Float=450;
    controls.addChild(makeButton("Export Bitmaps:", 25, y, 150, null));

    controls.addChild(makeButton("Elevation", 50, y+22, 100,
                function(e:Event):Void {
                new FileReference().save(makeExport('elevation'), 'elevation.data');
                }));
    controls.addChild(makeButton("Moisture", 50, y+44, 100,
                function(e:Event):Void {
                new FileReference().save(makeExport('moisture'), 'moisture.data');
                }));
    controls.addChild(makeButton("Overrides", 50, y+66, 100,
                function(e:Event):Void {
                new FileReference().save(makeExport('overrides'), 'overrides.data');
                }));

    controls.addChild(makeButton("Export XML", 25, y+100, 150,
                function(e:Event):Void {
                new FileReference().save(exportPolygons(), 'map.xml');
                }));
}*/

public static function main () {

    Lib.current.addChild (new VoronoiDashboard ());

}	

}

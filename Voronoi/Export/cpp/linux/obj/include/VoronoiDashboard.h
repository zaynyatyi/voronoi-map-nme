#ifndef INCLUDED_VoronoiDashboard
#define INCLUDED_VoronoiDashboard

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/display/Sprite.h>
HX_DECLARE_CLASS0(Lava)
HX_DECLARE_CLASS0(Map)
HX_DECLARE_CLASS0(NoisyEdges)
HX_DECLARE_CLASS0(VoronoiDashboard)
HX_DECLARE_CLASS3(de,polygonal,math,PM_PRNG)
HX_DECLARE_CLASS1(graph,Center)
HX_DECLARE_CLASS1(graph,Corner)
HX_DECLARE_CLASS1(graph,Edge)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,Graphics)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Shape)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,geom,Point)
HX_DECLARE_CLASS2(neash,geom,Vector3D)


class VoronoiDashboard_obj : public ::neash::display::Sprite_obj{
	public:
		typedef ::neash::display::Sprite_obj super;
		typedef VoronoiDashboard_obj OBJ_;
		VoronoiDashboard_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< VoronoiDashboard_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~VoronoiDashboard_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("VoronoiDashboard"); }

		static ::de::polygonal::math::PM_PRNG seed; /* REM */ 
		static ::neash::display::Shape shape; /* REM */ 
		static Dynamic state; /* REM */ 
		static Dynamic SIZE; /* REM */ 
		static Dynamic displayColors; /* REM */ 
		static Dynamic elevationGradientColors; /* REM */ 
		static Dynamic generate( );
		static Dynamic generate_dyn();

		static Void render( Dynamic tmp_state);
		static Dynamic render_dyn();

		static Void renderEdges( ::neash::display::Graphics graphics,::Map map,::NoisyEdges noisyEdges,::Lava lava);
		static Dynamic renderEdges_dyn();

		static Void renderPolygons( ::neash::display::Graphics graphics,::String gradientFillProperty,Dynamic colorOverrideFunction,::Map map,::NoisyEdges noisyEdges);
		static Dynamic renderPolygons_dyn();

		static Void drawPathForwards( ::neash::display::Graphics graphics,Array< ::neash::geom::Point > path);
		static Dynamic drawPathForwards_dyn();

		static Void drawPathBackwards( ::neash::display::Graphics graphics,Array< ::neash::geom::Point > path);
		static Dynamic drawPathBackwards_dyn();

		static Void drawGradientTriangle( ::neash::display::Graphics graphics,::neash::geom::Vector3D v1,::neash::geom::Vector3D v2,::neash::geom::Vector3D v3,Array< int > colors,Dynamic fillFunction);
		static Dynamic drawGradientTriangle_dyn();

		static Void renderDebugPolygons( ::neash::display::Graphics graphics,::Map map,::Lava lava);
		static Dynamic renderDebugPolygons_dyn();

		static int interpolateColor( int color0,int color1,Float f);
		static Dynamic interpolateColor_dyn();

		static int colorWithSlope( int color,::graph::Center p,::graph::Center q,::graph::Edge edge);
		static Dynamic colorWithSlope_dyn();

		static ::neash::geom::Vector3D lightVector; /* REM */ 
		static Float calculateLighting( ::graph::Center p,::graph::Corner r,::graph::Corner s);
		static Dynamic calculateLighting_dyn();

		static Void main( );
		static Dynamic main_dyn();

};


#endif /* INCLUDED_VoronoiDashboard */ 

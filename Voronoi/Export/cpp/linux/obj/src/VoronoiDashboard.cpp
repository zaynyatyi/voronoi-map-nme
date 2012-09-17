#include <hxcpp.h>

#ifndef INCLUDED_Lava
#include <Lava.h>
#endif
#ifndef INCLUDED_Map
#include <Map.h>
#endif
#ifndef INCLUDED_NoisyEdges
#include <NoisyEdges.h>
#endif
#ifndef INCLUDED_NullHelper
#include <NullHelper.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Roads
#include <Roads.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_VoronoiDashboard
#include <VoronoiDashboard.h>
#endif
#ifndef INCLUDED_Watersheds
#include <Watersheds.h>
#endif
#ifndef INCLUDED_de_polygonal_math_PM_PRNG
#include <de/polygonal/math/PM_PRNG.h>
#endif
#ifndef INCLUDED_graph_Center
#include <graph/Center.h>
#endif
#ifndef INCLUDED_graph_Corner
#include <graph/Corner.h>
#endif
#ifndef INCLUDED_graph_Edge
#include <graph/Edge.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_neash_display_Bitmap
#include <neash/display/Bitmap.h>
#endif
#ifndef INCLUDED_neash_display_BitmapData
#include <neash/display/BitmapData.h>
#endif
#ifndef INCLUDED_neash_display_CapsStyle
#include <neash/display/CapsStyle.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_Graphics
#include <neash/display/Graphics.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_JointStyle
#include <neash/display/JointStyle.h>
#endif
#ifndef INCLUDED_neash_display_LineScaleMode
#include <neash/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_neash_display_MovieClip
#include <neash/display/MovieClip.h>
#endif
#ifndef INCLUDED_neash_display_PixelSnapping
#include <neash/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_neash_display_Shape
#include <neash/display/Shape.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_geom_ColorTransform
#include <neash/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_neash_geom_Matrix
#include <neash/geom/Matrix.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
#ifndef INCLUDED_neash_geom_Rectangle
#include <neash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif

Void VoronoiDashboard_obj::__construct()
{
HX_STACK_PUSH("VoronoiDashboard::new","VoronoiDashboard.hx",76);
{
	HX_STACK_LINE(77)
	super::__construct();
	HX_STACK_LINE(78)
	::haxe::Log_obj::trace(HX_CSTRING("ololo"),hx::SourceInfo(HX_CSTRING("VoronoiDashboard.hx"),78,HX_CSTRING("VoronoiDashboard"),HX_CSTRING("new")));
	HX_STACK_LINE(79)
	::VoronoiDashboard_obj::image = ::neash::display::Bitmap_obj::__new(::neash::display::BitmapData_obj::__new(::VoronoiDashboard_obj::SIZE->__Field(HX_CSTRING("width"),true),::VoronoiDashboard_obj::SIZE->__Field(HX_CSTRING("height"),true),null(),null()),null(),null());
	HX_STACK_LINE(80)
	::VoronoiDashboard_obj::seed = ::de::polygonal::math::PM_PRNG_obj::__new();
	HX_STACK_LINE(81)
	::VoronoiDashboard_obj::state = ::VoronoiDashboard_obj::generate();
	HX_STACK_LINE(82)
	this->addChild(::VoronoiDashboard_obj::image);
}
;
	return null();
}

VoronoiDashboard_obj::~VoronoiDashboard_obj() { }

Dynamic VoronoiDashboard_obj::__CreateEmpty() { return  new VoronoiDashboard_obj; }
hx::ObjectPtr< VoronoiDashboard_obj > VoronoiDashboard_obj::__new()
{  hx::ObjectPtr< VoronoiDashboard_obj > result = new VoronoiDashboard_obj();
	result->__construct();
	return result;}

Dynamic VoronoiDashboard_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< VoronoiDashboard_obj > result = new VoronoiDashboard_obj();
	result->__construct();
	return result;}

::de::polygonal::math::PM_PRNG VoronoiDashboard_obj::seed;

::neash::display::Bitmap VoronoiDashboard_obj::image;

Dynamic VoronoiDashboard_obj::state;

Dynamic VoronoiDashboard_obj::SIZE;

Dynamic VoronoiDashboard_obj::displayColors;

Dynamic VoronoiDashboard_obj::elevationGradientColors;

Dynamic VoronoiDashboard_obj::generate( ){
	HX_STACK_PUSH("VoronoiDashboard::generate","VoronoiDashboard.hx",93);
	struct _Function_1_1{
		inline static Dynamic Block( ){
			HX_STACK_PUSH("*::closure","VoronoiDashboard.hx",94);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("map") , null(),false);
				__result->Add(HX_CSTRING("noisyEdges") , null(),false);
				__result->Add(HX_CSTRING("roads") , null(),false);
				__result->Add(HX_CSTRING("watersheds") , null(),false);
				__result->Add(HX_CSTRING("lava") , null(),false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(94)
	Dynamic tmp_state = _Function_1_1::Block();		HX_STACK_VAR(tmp_state,"tmp_state");
	HX_STACK_LINE(95)
	tmp_state->__FieldRef(HX_CSTRING("map")) = ::Map_obj::__new(::VoronoiDashboard_obj::SIZE);
	HX_STACK_LINE(96)
	tmp_state->__Field(HX_CSTRING("map"),true)->__Field(HX_CSTRING("newIsland"),true)(HX_CSTRING("Blob"),(int)85882,(int)8);
	HX_STACK_LINE(98)
	tmp_state->__Field(HX_CSTRING("map"),true)->__Field(HX_CSTRING("go"),true)((int)0,(int)6);
	HX_STACK_LINE(99)
	tmp_state->__FieldRef(HX_CSTRING("watersheds")) = ::Watersheds_obj::__new();
	HX_STACK_LINE(100)
	tmp_state->__FieldRef(HX_CSTRING("noisyEdges")) = ::NoisyEdges_obj::__new();
	HX_STACK_LINE(101)
	tmp_state->__FieldRef(HX_CSTRING("lava")) = ::Lava_obj::__new();
	HX_STACK_LINE(102)
	tmp_state->__FieldRef(HX_CSTRING("roads")) = ::Roads_obj::__new();
	HX_STACK_LINE(104)
	tmp_state->__Field(HX_CSTRING("roads"),true)->__Field(HX_CSTRING("createRoads"),true)(tmp_state->__Field(HX_CSTRING("map"),true));
	HX_STACK_LINE(105)
	tmp_state->__Field(HX_CSTRING("watersheds"),true)->__Field(HX_CSTRING("createWatersheds"),true)(tmp_state->__Field(HX_CSTRING("map"),true));
	HX_STACK_LINE(107)
	::VoronoiDashboard_obj::render(tmp_state);
	HX_STACK_LINE(109)
	return tmp_state;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(VoronoiDashboard_obj,generate,return )

Void VoronoiDashboard_obj::render( Dynamic tmp_state){
{
		HX_STACK_PUSH("VoronoiDashboard::render","VoronoiDashboard.hx",113);
		HX_STACK_ARG(tmp_state,"tmp_state");
		HX_STACK_LINE(113)
		::VoronoiDashboard_obj::renderDebugPolygons(::VoronoiDashboard_obj::image,tmp_state->__Field(HX_CSTRING("map"),true));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(VoronoiDashboard_obj,render,(void))

Void VoronoiDashboard_obj::renderDebugPolygons( ::neash::display::Bitmap bitmap,::Map map){
{
		HX_STACK_PUSH("VoronoiDashboard::renderDebugPolygons","VoronoiDashboard.hx",119);
		HX_STACK_ARG(bitmap,"bitmap");
		HX_STACK_ARG(map,"map");
		HX_STACK_LINE(120)
		::haxe::Log_obj::trace(HX_CSTRING("in render debug poly"),hx::SourceInfo(HX_CSTRING("VoronoiDashboard.hx"),120,HX_CSTRING("VoronoiDashboard"),HX_CSTRING("renderDebugPolygons")));
		HX_STACK_LINE(121)
		::neash::display::Shape shape = ::neash::display::Shape_obj::__new();		HX_STACK_VAR(shape,"shape");
		HX_STACK_LINE(122)
		::graph::Center p;		HX_STACK_VAR(p,"p");
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		::graph::Edge edge;		HX_STACK_VAR(edge,"edge");
		::neash::geom::Point point;		HX_STACK_VAR(point,"point");
		int color;		HX_STACK_VAR(color,"color");
		HX_STACK_LINE(123)
		if (((map->centers->length == (int)0))){
			HX_STACK_LINE(124)
			::haxe::Log_obj::trace((HX_CSTRING("there is 0 map.centers: ") + ::Std_obj::string(map->centers->length)),hx::SourceInfo(HX_CSTRING("VoronoiDashboard.hx"),124,HX_CSTRING("VoronoiDashboard"),HX_CSTRING("renderDebugPolygons")));
			HX_STACK_LINE(126)
			shape->nmeGetGraphics()->beginFill((int)14540253,null());
			HX_STACK_LINE(127)
			shape->nmeGetGraphics()->drawRect((int)0,(int)0,map->SIZE->__Field(HX_CSTRING("width"),true),map->SIZE->__Field(HX_CSTRING("height"),true));
			HX_STACK_LINE(128)
			shape->nmeGetGraphics()->endFill();
			HX_STACK_LINE(129)
			{
				HX_STACK_LINE(129)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::neash::geom::Point > _g1 = map->points;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(129)
				while(((_g < _g1->length))){
					HX_STACK_LINE(129)
					::neash::geom::Point point1 = _g1->__get(_g);		HX_STACK_VAR(point1,"point1");
					HX_STACK_LINE(129)
					++(_g);
					HX_STACK_LINE(131)
					shape->nmeGetGraphics()->beginFill((int)0,null());
					HX_STACK_LINE(132)
					shape->nmeGetGraphics()->drawCircle(point1->x,point1->y,1.3);
					HX_STACK_LINE(133)
					shape->nmeGetGraphics()->endFill();
				}
			}
		}
		HX_STACK_LINE(137)
		{
			HX_STACK_LINE(137)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Center > _g1 = map->centers;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(137)
			while(((_g < _g1->length))){
				HX_STACK_LINE(137)
				::graph::Center p1 = _g1->__get(_g);		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(137)
				++(_g);
				HX_STACK_LINE(141)
				color = ::Reflect_obj::field(::VoronoiDashboard_obj::displayColors,p1->biome);
				HX_STACK_LINE(142)
				shape->nmeGetGraphics()->beginFill(::VoronoiDashboard_obj::interpolateColor(color,(int)14540253,0.2),null());
				HX_STACK_LINE(143)
				{
					HX_STACK_LINE(143)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Edge > _g3 = p1->borders;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(143)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(143)
						::graph::Edge edge1 = _g3->__get(_g2);		HX_STACK_VAR(edge1,"edge1");
						HX_STACK_LINE(143)
						++(_g2);
						HX_STACK_LINE(144)
						if (((bool((edge1->v0 != null())) && bool((edge1->v1 != null()))))){
							HX_STACK_LINE(145)
							shape->nmeGetGraphics()->moveTo(p1->point->x,p1->point->y);
							HX_STACK_LINE(146)
							shape->nmeGetGraphics()->lineTo(edge1->v0->point->x,edge1->v0->point->y);
							HX_STACK_LINE(147)
							if (((edge1->river > (int)0))){
								HX_STACK_LINE(147)
								shape->nmeGetGraphics()->lineStyle((int)2,::VoronoiDashboard_obj::displayColors->__Field(HX_CSTRING("RIVER"),true),1.0,null(),null(),null(),null(),null());
							}
							else{
								HX_STACK_LINE(149)
								shape->nmeGetGraphics()->lineStyle((int)0,(int)0,0.4,null(),null(),null(),null(),null());
							}
							HX_STACK_LINE(152)
							shape->nmeGetGraphics()->lineTo(edge1->v1->point->x,edge1->v1->point->y);
							HX_STACK_LINE(153)
							shape->nmeGetGraphics()->lineStyle(null(),null(),null(),null(),null(),null(),null(),null());
						}
					}
				}
				HX_STACK_LINE(156)
				shape->nmeGetGraphics()->endFill();
				HX_STACK_LINE(157)
				shape->nmeGetGraphics()->beginFill((  ((p1->water)) ? int((int)13107) : int((int)0) ),0.7);
				HX_STACK_LINE(158)
				shape->nmeGetGraphics()->drawCircle(p1->point->x,p1->point->y,1.3);
				HX_STACK_LINE(159)
				shape->nmeGetGraphics()->endFill();
				HX_STACK_LINE(160)
				{
					HX_STACK_LINE(160)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Corner > _g3 = p1->corners;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(160)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(160)
						::graph::Corner q1 = _g3->__get(_g2);		HX_STACK_VAR(q1,"q1");
						HX_STACK_LINE(160)
						++(_g2);
						HX_STACK_LINE(161)
						shape->nmeGetGraphics()->beginFill((  ((::NullHelper_obj::IsNotNull(q1->water))) ? int((int)255) : int((int)39168) ),null());
						HX_STACK_LINE(162)
						shape->nmeGetGraphics()->drawRect((q1->point->x - 0.7),(q1->point->y - 0.7),1.5,1.5);
						HX_STACK_LINE(163)
						shape->nmeGetGraphics()->endFill();
					}
				}
			}
		}
		HX_STACK_LINE(166)
		bitmap->bitmapData->draw(shape,null(),null(),null(),::neash::geom::Rectangle_obj::__new((int)0,(int)0,map->SIZE->__Field(HX_CSTRING("width"),true),map->SIZE->__Field(HX_CSTRING("height"),true)),null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(VoronoiDashboard_obj,renderDebugPolygons,(void))

int VoronoiDashboard_obj::interpolateColor( int color0,int color1,Float f){
	HX_STACK_PUSH("VoronoiDashboard::interpolateColor","VoronoiDashboard.hx",169);
	HX_STACK_ARG(color0,"color0");
	HX_STACK_ARG(color1,"color1");
	HX_STACK_ARG(f,"f");
	HX_STACK_LINE(170)
	int r = ::Std_obj::_int((((((int)1 - f)) * ((int(color0) >> int((int)16)))) + (f * ((int(color1) >> int((int)16))))));		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(171)
	int g = ::Std_obj::_int((((((int)1 - f)) * ((int((int(color0) >> int((int)8))) & int((int)255)))) + (f * ((int((int(color1) >> int((int)8))) & int((int)255))))));		HX_STACK_VAR(g,"g");
	HX_STACK_LINE(172)
	int b = ::Std_obj::_int((((((int)1 - f)) * ((int(color0) & int((int)255)))) + (f * ((int(color1) & int((int)255))))));		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(173)
	if (((r > (int)255))){
		HX_STACK_LINE(173)
		r = (int)255;
	}
	HX_STACK_LINE(174)
	if (((g > (int)255))){
		HX_STACK_LINE(174)
		g = (int)255;
	}
	HX_STACK_LINE(175)
	if (((b > (int)255))){
		HX_STACK_LINE(175)
		b = (int)255;
	}
	HX_STACK_LINE(176)
	return (int((int((int(r) << int((int)16))) | int((int(g) << int((int)8))))) | int(b));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(VoronoiDashboard_obj,interpolateColor,return )

Void VoronoiDashboard_obj::main( ){
{
		HX_STACK_PUSH("VoronoiDashboard::main","VoronoiDashboard.hx",180);
		HX_STACK_LINE(180)
		::nme::Lib_obj::nmeGetCurrent()->addChild(::VoronoiDashboard_obj::__new());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(VoronoiDashboard_obj,main,(void))


VoronoiDashboard_obj::VoronoiDashboard_obj()
{
}

void VoronoiDashboard_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(VoronoiDashboard);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void VoronoiDashboard_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic VoronoiDashboard_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"seed") ) { return seed; }
		if (HX_FIELD_EQ(inName,"SIZE") ) { return SIZE; }
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"image") ) { return image; }
		if (HX_FIELD_EQ(inName,"state") ) { return state; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"generate") ) { return generate_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"displayColors") ) { return displayColors; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"interpolateColor") ) { return interpolateColor_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"renderDebugPolygons") ) { return renderDebugPolygons_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"elevationGradientColors") ) { return elevationGradientColors; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic VoronoiDashboard_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"seed") ) { seed=inValue.Cast< ::de::polygonal::math::PM_PRNG >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SIZE") ) { SIZE=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"image") ) { image=inValue.Cast< ::neash::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"state") ) { state=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"displayColors") ) { displayColors=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"elevationGradientColors") ) { elevationGradientColors=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void VoronoiDashboard_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("seed"),
	HX_CSTRING("image"),
	HX_CSTRING("state"),
	HX_CSTRING("SIZE"),
	HX_CSTRING("displayColors"),
	HX_CSTRING("elevationGradientColors"),
	HX_CSTRING("generate"),
	HX_CSTRING("render"),
	HX_CSTRING("renderDebugPolygons"),
	HX_CSTRING("interpolateColor"),
	HX_CSTRING("main"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(VoronoiDashboard_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(VoronoiDashboard_obj::seed,"seed");
	HX_MARK_MEMBER_NAME(VoronoiDashboard_obj::image,"image");
	HX_MARK_MEMBER_NAME(VoronoiDashboard_obj::state,"state");
	HX_MARK_MEMBER_NAME(VoronoiDashboard_obj::SIZE,"SIZE");
	HX_MARK_MEMBER_NAME(VoronoiDashboard_obj::displayColors,"displayColors");
	HX_MARK_MEMBER_NAME(VoronoiDashboard_obj::elevationGradientColors,"elevationGradientColors");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(VoronoiDashboard_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(VoronoiDashboard_obj::seed,"seed");
	HX_VISIT_MEMBER_NAME(VoronoiDashboard_obj::image,"image");
	HX_VISIT_MEMBER_NAME(VoronoiDashboard_obj::state,"state");
	HX_VISIT_MEMBER_NAME(VoronoiDashboard_obj::SIZE,"SIZE");
	HX_VISIT_MEMBER_NAME(VoronoiDashboard_obj::displayColors,"displayColors");
	HX_VISIT_MEMBER_NAME(VoronoiDashboard_obj::elevationGradientColors,"elevationGradientColors");
};

Class VoronoiDashboard_obj::__mClass;

void VoronoiDashboard_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("VoronoiDashboard"), hx::TCanCast< VoronoiDashboard_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void VoronoiDashboard_obj::__boot()
{
struct _Function_0_1{
	inline static Dynamic Block( ){
		HX_STACK_PUSH("*::closure","VoronoiDashboard.hx",34);
		{
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("width") , (int)800,false);
			__result->Add(HX_CSTRING("height") , (int)600,false);
			return __result;
		}
		return null();
	}
};
	SIZE= _Function_0_1::Block();
struct _Function_0_2{
	inline static Dynamic Block( ){
		HX_STACK_PUSH("*::closure","VoronoiDashboard.hx",37);
		{
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("OCEAN") , (int)4473978,false);
			__result->Add(HX_CSTRING("COAST") , (int)3355482,false);
			__result->Add(HX_CSTRING("LAKESHORE") , (int)2250120,false);
			__result->Add(HX_CSTRING("LAKE") , (int)3368601,false);
			__result->Add(HX_CSTRING("RIVER") , (int)2250120,false);
			__result->Add(HX_CSTRING("MARSH") , (int)3106406,false);
			__result->Add(HX_CSTRING("ICE") , (int)10092543,false);
			__result->Add(HX_CSTRING("BEACH") , (int)10522743,false);
			__result->Add(HX_CSTRING("ROAD1") , (int)4465169,false);
			__result->Add(HX_CSTRING("ROAD2") , (int)5583650,false);
			__result->Add(HX_CSTRING("ROAD3") , (int)6702131,false);
			__result->Add(HX_CSTRING("BRIDGE") , (int)6842464,false);
			__result->Add(HX_CSTRING("LAVA") , (int)13382451,false);
			__result->Add(HX_CSTRING("SNOW") , (int)16777215,false);
			__result->Add(HX_CSTRING("TUNDRA") , (int)12303274,false);
			__result->Add(HX_CSTRING("BARE") , (int)8947848,false);
			__result->Add(HX_CSTRING("SCORCHED") , (int)5592405,false);
			__result->Add(HX_CSTRING("TAIGA") , (int)10070647,false);
			__result->Add(HX_CSTRING("SHRUBLAND") , (int)8952183,false);
			__result->Add(HX_CSTRING("TEMPERATE_DESERT") , (int)13226651,false);
			__result->Add(HX_CSTRING("TEMPERATE_RAIN_FOREST") , (int)4491349,false);
			__result->Add(HX_CSTRING("TEMPERATE_DECIDUOUS_FOREST") , (int)6788185,false);
			__result->Add(HX_CSTRING("GRASSLAND") , (int)8956501,false);
			__result->Add(HX_CSTRING("SUBTROPICAL_DESERT") , (int)13810059,false);
			__result->Add(HX_CSTRING("TROPICAL_RAIN_FOREST") , (int)3372885,false);
			__result->Add(HX_CSTRING("TROPICAL_SEASONAL_FOREST") , (int)5609796,false);
			return __result;
		}
		return null();
	}
};
	displayColors= _Function_0_2::Block();
struct _Function_0_3{
	inline static Dynamic Block( ){
		HX_STACK_PUSH("*::closure","VoronoiDashboard.hx",69);
		{
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("OCEAN") , (int)34816,false);
			__result->Add(HX_CSTRING("GRADIENT_LOW") , (int)34816,false);
			__result->Add(HX_CSTRING("GRADIENT_HIGH") , (int)16776960,false);
			return __result;
		}
		return null();
	}
};
	elevationGradientColors= _Function_0_3::Block();
}


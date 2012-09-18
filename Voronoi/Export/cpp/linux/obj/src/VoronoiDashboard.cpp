#include <hxcpp.h>

#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_Lava
#include <Lava.h>
#endif
#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Map
#include <Map.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
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
#ifndef INCLUDED_neash_display_CapsStyle
#include <neash/display/CapsStyle.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_GradientType
#include <neash/display/GradientType.h>
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
#ifndef INCLUDED_neash_display_InterpolationMethod
#include <neash/display/InterpolationMethod.h>
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
#ifndef INCLUDED_neash_display_Shape
#include <neash/display/Shape.h>
#endif
#ifndef INCLUDED_neash_display_SpreadMethod
#include <neash/display/SpreadMethod.h>
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
#ifndef INCLUDED_neash_geom_Matrix
#include <neash/geom/Matrix.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
#ifndef INCLUDED_neash_geom_Vector3D
#include <neash/geom/Vector3D.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif

Void VoronoiDashboard_obj::__construct()
{
HX_STACK_PUSH("VoronoiDashboard::new","VoronoiDashboard.hx",87);
{
	HX_STACK_LINE(88)
	super::__construct();
	HX_STACK_LINE(90)
	::VoronoiDashboard_obj::shape = ::neash::display::Shape_obj::__new();
	HX_STACK_LINE(92)
	::VoronoiDashboard_obj::seed = ::de::polygonal::math::PM_PRNG_obj::__new();
	HX_STACK_LINE(93)
	::VoronoiDashboard_obj::state = ::VoronoiDashboard_obj::generate();
	HX_STACK_LINE(104)
	this->addChild(::VoronoiDashboard_obj::shape);
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

::neash::display::Shape VoronoiDashboard_obj::shape;

Dynamic VoronoiDashboard_obj::state;

Dynamic VoronoiDashboard_obj::SIZE;

Dynamic VoronoiDashboard_obj::displayColors;

Dynamic VoronoiDashboard_obj::elevationGradientColors;

Dynamic VoronoiDashboard_obj::generate( ){
	HX_STACK_PUSH("VoronoiDashboard::generate","VoronoiDashboard.hx",116);
	struct _Function_1_1{
		inline static Dynamic Block( ){
			HX_STACK_PUSH("*::closure","VoronoiDashboard.hx",117);
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
	HX_STACK_LINE(117)
	Dynamic tmp_state = _Function_1_1::Block();		HX_STACK_VAR(tmp_state,"tmp_state");
	HX_STACK_LINE(118)
	tmp_state->__FieldRef(HX_CSTRING("map")) = ::Map_obj::__new(::VoronoiDashboard_obj::SIZE);
	HX_STACK_LINE(119)
	tmp_state->__Field(HX_CSTRING("map"),true)->__Field(HX_CSTRING("newIsland"),true)(HX_CSTRING("Perlin"),(int)85882,(int)8);
	HX_STACK_LINE(121)
	tmp_state->__Field(HX_CSTRING("map"),true)->__Field(HX_CSTRING("go"),true)((int)0,(int)6);
	HX_STACK_LINE(122)
	tmp_state->__FieldRef(HX_CSTRING("watersheds")) = ::Watersheds_obj::__new();
	HX_STACK_LINE(123)
	tmp_state->__FieldRef(HX_CSTRING("noisyEdges")) = ::NoisyEdges_obj::__new();
	HX_STACK_LINE(124)
	tmp_state->__FieldRef(HX_CSTRING("lava")) = ::Lava_obj::__new();
	HX_STACK_LINE(125)
	tmp_state->__FieldRef(HX_CSTRING("roads")) = ::Roads_obj::__new();
	HX_STACK_LINE(129)
	tmp_state->__Field(HX_CSTRING("lava"),true)->__Field(HX_CSTRING("createLava"),true)(tmp_state->__Field(HX_CSTRING("map"),true),::VoronoiDashboard_obj::seed->nextDouble_dyn());
	HX_STACK_LINE(130)
	tmp_state->__Field(HX_CSTRING("noisyEdges"),true)->__Field(HX_CSTRING("buildNoisyEdges"),true)(tmp_state->__Field(HX_CSTRING("map"),true),tmp_state->__Field(HX_CSTRING("lava"),true),::VoronoiDashboard_obj::seed);
	HX_STACK_LINE(131)
	::VoronoiDashboard_obj::render(tmp_state);
	HX_STACK_LINE(133)
	return tmp_state;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(VoronoiDashboard_obj,generate,return )

Void VoronoiDashboard_obj::render( Dynamic tmp_state){
{
		HX_STACK_PUSH("VoronoiDashboard::render","VoronoiDashboard.hx",137);
		HX_STACK_ARG(tmp_state,"tmp_state");
		HX_STACK_LINE(146)
		::VoronoiDashboard_obj::renderPolygons(::VoronoiDashboard_obj::shape->nmeGetGraphics(),null(),::VoronoiDashboard_obj::colorWithSlope_dyn(),tmp_state->__Field(HX_CSTRING("map"),true),tmp_state->__Field(HX_CSTRING("noisyEdges"),true));
		HX_STACK_LINE(147)
		::VoronoiDashboard_obj::renderEdges(::VoronoiDashboard_obj::shape->nmeGetGraphics(),tmp_state->__Field(HX_CSTRING("map"),true),tmp_state->__Field(HX_CSTRING("noisyEdges"),true),tmp_state->__Field(HX_CSTRING("lava"),true));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(VoronoiDashboard_obj,render,(void))

Void VoronoiDashboard_obj::renderEdges( ::neash::display::Graphics graphics,::Map map,::NoisyEdges noisyEdges,::Lava lava){
{
		HX_STACK_PUSH("VoronoiDashboard::renderEdges","VoronoiDashboard.hx",155);
		HX_STACK_ARG(graphics,"graphics");
		HX_STACK_ARG(map,"map");
		HX_STACK_ARG(noisyEdges,"noisyEdges");
		HX_STACK_ARG(lava,"lava");
		HX_STACK_LINE(157)
		::graph::Center p;		HX_STACK_VAR(p,"p");
		::graph::Center r;		HX_STACK_VAR(r,"r");
		::graph::Edge edge;		HX_STACK_VAR(edge,"edge");
		HX_STACK_LINE(159)
		{
			HX_STACK_LINE(159)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Center > _g1 = map->centers;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(159)
			while(((_g < _g1->length))){
				HX_STACK_LINE(159)
				::graph::Center p1 = _g1->__get(_g);		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(159)
				++(_g);
				HX_STACK_LINE(160)
				{
					HX_STACK_LINE(160)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Center > _g3 = p1->neighbors;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(160)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(160)
						::graph::Center r1 = _g3->__get(_g2);		HX_STACK_VAR(r1,"r1");
						HX_STACK_LINE(160)
						++(_g2);
						HX_STACK_LINE(161)
						edge = map->lookupEdgeFromCenter(p1,r1);
						HX_STACK_LINE(162)
						if (((bool((noisyEdges->path0->__GetItem(edge->index) == null())) || bool((noisyEdges->path1->__GetItem(edge->index) == null()))))){
							HX_STACK_LINE(163)
							continue;
						}
						HX_STACK_LINE(167)
						if (((p1->ocean != r1->ocean))){
							HX_STACK_LINE(167)
							graphics->lineStyle((int)2,::VoronoiDashboard_obj::displayColors->__Field(HX_CSTRING("COAST"),true),null(),null(),null(),null(),null(),null());
						}
						else{
							HX_STACK_LINE(170)
							if (((bool((bool((p1->water != r1->water)) && bool((p1->biome != HX_CSTRING("ICE"))))) && bool((r1->biome != HX_CSTRING("ICE")))))){
								HX_STACK_LINE(170)
								graphics->lineStyle((int)1,::VoronoiDashboard_obj::displayColors->__Field(HX_CSTRING("LAKESHORE"),true),null(),null(),null(),null(),null(),null());
							}
							else{
								HX_STACK_LINE(173)
								if (((bool(p1->water) || bool(r1->water)))){
									HX_STACK_LINE(173)
									continue;
								}
								else{
									HX_STACK_LINE(176)
									if ((lava->lava->__GetItem(edge->index))){
										HX_STACK_LINE(176)
										graphics->lineStyle((int)1,::VoronoiDashboard_obj::displayColors->__Field(HX_CSTRING("LAVA"),true),null(),null(),null(),null(),null(),null());
									}
									else{
										HX_STACK_LINE(179)
										if (((edge->river > (int)0))){
											HX_STACK_LINE(179)
											graphics->lineStyle(::Math_obj::sqrt(edge->river),::VoronoiDashboard_obj::displayColors->__Field(HX_CSTRING("RIVER"),true),null(),null(),null(),null(),null(),null());
										}
										else{
											HX_STACK_LINE(182)
											continue;
										}
									}
								}
							}
						}
						HX_STACK_LINE(187)
						graphics->moveTo(noisyEdges->path0->__GetItem(edge->index)->__GetItem((int)0)->__Field(HX_CSTRING("x"),true),noisyEdges->path0->__GetItem(edge->index)->__GetItem((int)0)->__Field(HX_CSTRING("y"),true));
						HX_STACK_LINE(189)
						::VoronoiDashboard_obj::drawPathForwards(graphics,noisyEdges->path0->__GetItem(edge->index));
						HX_STACK_LINE(190)
						::VoronoiDashboard_obj::drawPathBackwards(graphics,noisyEdges->path1->__GetItem(edge->index));
						HX_STACK_LINE(191)
						graphics->lineStyle(null(),null(),null(),null(),null(),null(),null(),null());
					}
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(VoronoiDashboard_obj,renderEdges,(void))

Void VoronoiDashboard_obj::renderPolygons( ::neash::display::Graphics graphics,::String gradientFillProperty,Dynamic colorOverrideFunction,::Map map,::NoisyEdges noisyEdges){
{
		HX_STACK_PUSH("VoronoiDashboard::renderPolygons","VoronoiDashboard.hx",197);
		HX_STACK_ARG(graphics,"graphics");
		HX_STACK_ARG(gradientFillProperty,"gradientFillProperty");
		HX_STACK_ARG(colorOverrideFunction,"colorOverrideFunction");
		HX_STACK_ARG(map,"map");
		HX_STACK_ARG(noisyEdges,"noisyEdges");
		HX_STACK_LINE(197)
		Array< ::NoisyEdges > noisyEdges1 = Array_obj< ::NoisyEdges >::__new().Add(noisyEdges);		HX_STACK_VAR(noisyEdges1,"noisyEdges1");
		HX_STACK_LINE(197)
		Array< ::neash::display::Graphics > graphics1 = Array_obj< ::neash::display::Graphics >::__new().Add(graphics);		HX_STACK_VAR(graphics1,"graphics1");
		HX_STACK_LINE(201)
		::neash::display::Shape shape = ::neash::display::Shape_obj::__new();		HX_STACK_VAR(shape,"shape");
		HX_STACK_LINE(202)
		::graph::Center p;		HX_STACK_VAR(p,"p");
		::graph::Center r;		HX_STACK_VAR(r,"r");
		HX_STACK_LINE(206)
		graphics1->__get((int)0)->beginFill(::VoronoiDashboard_obj::displayColors->__Field(HX_CSTRING("OCEAN"),true),null());
		HX_STACK_LINE(207)
		graphics1->__get((int)0)->drawRect((int)0,(int)0,::VoronoiDashboard_obj::SIZE->__Field(HX_CSTRING("width"),true),::VoronoiDashboard_obj::SIZE->__Field(HX_CSTRING("height"),true));
		HX_STACK_LINE(208)
		graphics1->__get((int)0)->endFill();
		HX_STACK_LINE(210)
		{
			HX_STACK_LINE(210)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Center > _g1 = map->centers;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(210)
			while(((_g < _g1->length))){
				HX_STACK_LINE(210)
				Array< ::graph::Center > p1 = Array_obj< ::graph::Center >::__new().Add(_g1->__get(_g));		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(210)
				++(_g);
				HX_STACK_LINE(211)
				{
					HX_STACK_LINE(211)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Center > _g3 = p1->__get((int)0)->neighbors;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(211)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(211)
						::graph::Center r1 = _g3->__get(_g2);		HX_STACK_VAR(r1,"r1");
						HX_STACK_LINE(211)
						++(_g2);
						HX_STACK_LINE(212)
						Array< ::graph::Edge > edge = Array_obj< ::graph::Edge >::__new().Add(map->lookupEdgeFromCenter(p1->__get((int)0),r1));		HX_STACK_VAR(edge,"edge");
						HX_STACK_LINE(213)
						int color = (  ((::NullHelper_obj::IsNotNull(::Reflect_obj::field(::VoronoiDashboard_obj::displayColors,p1->__get((int)0)->biome)))) ? int(::Reflect_obj::field(::VoronoiDashboard_obj::displayColors,p1->__get((int)0)->biome)) : int((int)0) );		HX_STACK_VAR(color,"color");
						HX_STACK_LINE(214)
						if (((colorOverrideFunction != null()))){
							HX_STACK_LINE(214)
							color = colorOverrideFunction(color,p1->__get((int)0),r1,edge->__get((int)0)).Cast< int >();
						}

						HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_5_1,Array< ::graph::Center >,p1,Array< ::neash::display::Graphics >,graphics1,Array< ::NoisyEdges >,noisyEdges1,Array< ::graph::Edge >,edge)
						Void run(){
							HX_STACK_PUSH("*::_Function_5_1","VoronoiDashboard.hx",218);
							{
								HX_STACK_LINE(219)
								Array< ::neash::geom::Point > path = noisyEdges1->__get((int)0)->path0->__GetItem(edge->__get((int)0)->index);		HX_STACK_VAR(path,"path");
								HX_STACK_LINE(220)
								graphics1->__get((int)0)->moveTo(p1->__get((int)0)->point->x,p1->__get((int)0)->point->y);
								HX_STACK_LINE(221)
								graphics1->__get((int)0)->lineTo(path->__get((int)0)->x,path->__get((int)0)->y);
								HX_STACK_LINE(222)
								::VoronoiDashboard_obj::drawPathForwards(graphics1->__get((int)0),path);
								HX_STACK_LINE(223)
								graphics1->__get((int)0)->lineTo(p1->__get((int)0)->point->x,p1->__get((int)0)->point->y);
							}
							return null();
						}
						HX_END_LOCAL_FUNC0((void))

						HX_STACK_LINE(218)
						Dynamic drawPath0 =  Dynamic(new _Function_5_1(p1,graphics1,noisyEdges1,edge));		HX_STACK_VAR(drawPath0,"drawPath0");

						HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_5_2,Array< ::graph::Center >,p1,Array< ::neash::display::Graphics >,graphics1,Array< ::NoisyEdges >,noisyEdges1,Array< ::graph::Edge >,edge)
						Void run(){
							HX_STACK_PUSH("*::_Function_5_2","VoronoiDashboard.hx",226);
							{
								HX_STACK_LINE(227)
								Array< ::neash::geom::Point > path = noisyEdges1->__get((int)0)->path1->__GetItem(edge->__get((int)0)->index);		HX_STACK_VAR(path,"path");
								HX_STACK_LINE(228)
								graphics1->__get((int)0)->moveTo(p1->__get((int)0)->point->x,p1->__get((int)0)->point->y);
								HX_STACK_LINE(229)
								graphics1->__get((int)0)->lineTo(path->__get((int)0)->x,path->__get((int)0)->y);
								HX_STACK_LINE(230)
								::VoronoiDashboard_obj::drawPathForwards(graphics1->__get((int)0),path);
								HX_STACK_LINE(231)
								graphics1->__get((int)0)->lineTo(p1->__get((int)0)->point->x,p1->__get((int)0)->point->y);
							}
							return null();
						}
						HX_END_LOCAL_FUNC0((void))

						HX_STACK_LINE(226)
						Dynamic drawPath1 =  Dynamic(new _Function_5_2(p1,graphics1,noisyEdges1,edge));		HX_STACK_VAR(drawPath1,"drawPath1");
						HX_STACK_LINE(234)
						if (((bool((noisyEdges1->__get((int)0)->path0->__GetItem(edge->__get((int)0)->index) == null())) || bool((noisyEdges1->__get((int)0)->path1->__GetItem(edge->__get((int)0)->index) == null()))))){
							HX_STACK_LINE(235)
							continue;
						}
						HX_STACK_LINE(242)
						if (((gradientFillProperty != null()))){
							HX_STACK_LINE(245)
							::graph::Corner corner0 = edge->__get((int)0)->v0;		HX_STACK_VAR(corner0,"corner0");
							HX_STACK_LINE(246)
							::graph::Corner corner1 = edge->__get((int)0)->v1;		HX_STACK_VAR(corner1,"corner1");
							HX_STACK_LINE(251)
							::neash::geom::Point midpoint = edge->__get((int)0)->midpoint;		HX_STACK_VAR(midpoint,"midpoint");
							HX_STACK_LINE(252)
							Float midpointAttr = (0.5 * ((::Reflect_obj::field(corner0,gradientFillProperty) + ::Reflect_obj::field(corner1,gradientFillProperty))));		HX_STACK_VAR(midpointAttr,"midpointAttr");
							HX_STACK_LINE(254)
							::VoronoiDashboard_obj::drawGradientTriangle(graphics1->__get((int)0),::neash::geom::Vector3D_obj::__new(p1->__get((int)0)->point->x,p1->__get((int)0)->point->y,::Reflect_obj::field(p1->__get((int)0),gradientFillProperty),null()),::neash::geom::Vector3D_obj::__new(corner0->point->x,corner0->point->y,::Reflect_obj::field(corner0,gradientFillProperty),null()),::neash::geom::Vector3D_obj::__new(midpoint->x,midpoint->y,midpointAttr,null()),Array_obj< int >::__new().Add(::VoronoiDashboard_obj::elevationGradientColors->__Field(HX_CSTRING("GRADIENT_LOW"),true)).Add(::VoronoiDashboard_obj::elevationGradientColors->__Field(HX_CSTRING("GRADIENT_HIGH"),true)),drawPath0);
							HX_STACK_LINE(260)
							::VoronoiDashboard_obj::drawGradientTriangle(graphics1->__get((int)0),::neash::geom::Vector3D_obj::__new(p1->__get((int)0)->point->x,p1->__get((int)0)->point->y,::Reflect_obj::field(p1->__get((int)0),gradientFillProperty),null()),::neash::geom::Vector3D_obj::__new(midpoint->x,midpoint->y,midpointAttr,null()),::neash::geom::Vector3D_obj::__new(corner1->point->x,corner1->point->y,::Reflect_obj::field(corner1,gradientFillProperty),null()),Array_obj< int >::__new().Add(::VoronoiDashboard_obj::elevationGradientColors->__Field(HX_CSTRING("GRADIENT_LOW"),true)).Add(::VoronoiDashboard_obj::elevationGradientColors->__Field(HX_CSTRING("GRADIENT_HIGH"),true)),drawPath1);
						}
						else{
							HX_STACK_LINE(267)
							graphics1->__get((int)0)->beginFill(color,null());
							HX_STACK_LINE(268)
							drawPath0().Cast< Void >();
							HX_STACK_LINE(269)
							drawPath1().Cast< Void >();
							HX_STACK_LINE(270)
							graphics1->__get((int)0)->endFill();
						}
					}
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(VoronoiDashboard_obj,renderPolygons,(void))

Void VoronoiDashboard_obj::drawPathForwards( ::neash::display::Graphics graphics,Array< ::neash::geom::Point > path){
{
		HX_STACK_PUSH("VoronoiDashboard::drawPathForwards","VoronoiDashboard.hx",277);
		HX_STACK_ARG(graphics,"graphics");
		HX_STACK_ARG(path,"path");
		HX_STACK_LINE(278)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = path->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(278)
		while(((_g1 < _g))){
			HX_STACK_LINE(278)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(279)
			graphics->lineTo(path->__get(i)->x,path->__get(i)->y);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(VoronoiDashboard_obj,drawPathForwards,(void))

Void VoronoiDashboard_obj::drawPathBackwards( ::neash::display::Graphics graphics,Array< ::neash::geom::Point > path){
{
		HX_STACK_PUSH("VoronoiDashboard::drawPathBackwards","VoronoiDashboard.hx",283);
		HX_STACK_ARG(graphics,"graphics");
		HX_STACK_ARG(path,"path");
		HX_STACK_LINE(284)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = path->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(284)
		while(((_g1 < _g))){
			HX_STACK_LINE(284)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(285)
			graphics->lineTo(path->__get(i)->x,path->__get(i)->y);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(VoronoiDashboard_obj,drawPathBackwards,(void))

Void VoronoiDashboard_obj::drawGradientTriangle( ::neash::display::Graphics graphics,::neash::geom::Vector3D v1,::neash::geom::Vector3D v2,::neash::geom::Vector3D v3,Array< int > colors,Dynamic fillFunction){
{
		HX_STACK_PUSH("VoronoiDashboard::drawGradientTriangle","VoronoiDashboard.hx",294);
		HX_STACK_ARG(graphics,"graphics");
		HX_STACK_ARG(v1,"v1");
		HX_STACK_ARG(v2,"v2");
		HX_STACK_ARG(v3,"v3");
		HX_STACK_ARG(colors,"colors");
		HX_STACK_ARG(fillFunction,"fillFunction");
		HX_STACK_LINE(294)
		Array< Array< int > > colors1 = Array_obj< Array< int > >::__new().Add(colors);		HX_STACK_VAR(colors1,"colors1");
		HX_STACK_LINE(297)
		::neash::geom::Matrix m = ::neash::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());		HX_STACK_VAR(m,"m");
		struct _Function_1_1{
			inline static ::neash::geom::Vector3D Block( ::neash::geom::Vector3D &v1,::neash::geom::Vector3D &v3,::neash::geom::Vector3D &v2){
				HX_STACK_PUSH("*::closure","VoronoiDashboard.hx",300);
				{
					HX_STACK_LINE(300)
					::neash::geom::Vector3D _this = ::neash::geom::Vector3D_obj::__new((v1->x + v2->x),(v1->y + v2->y),(v1->z + v2->z),null());		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(300)
					return ::neash::geom::Vector3D_obj::__new((_this->x + v3->x),(_this->y + v3->y),(_this->z + v3->z),null());
				}
				return null();
			}
		};
		HX_STACK_LINE(300)
		::neash::geom::Vector3D V = _Function_1_1::Block(v1,v3,v2);		HX_STACK_VAR(V,"V");
		HX_STACK_LINE(301)
		{
			HX_STACK_LINE(301)
			Float s = (Float((int)1) / Float(3.0));		HX_STACK_VAR(s,"s");
			HX_STACK_LINE(301)
			hx::MultEq(V->x,s);
			HX_STACK_LINE(301)
			hx::MultEq(V->y,s);
			HX_STACK_LINE(301)
			hx::MultEq(V->z,s);
		}
		struct _Function_1_2{
			inline static ::neash::geom::Vector3D Block( ::neash::geom::Vector3D &v1,::neash::geom::Vector3D &v3,::neash::geom::Vector3D &v2){
				HX_STACK_PUSH("*::closure","VoronoiDashboard.hx",304);
				{
					HX_STACK_LINE(304)
					::neash::geom::Vector3D _this = ::neash::geom::Vector3D_obj::__new((v2->x - v1->x),(v2->y - v1->y),(v2->z - v1->z),null());		HX_STACK_VAR(_this,"_this");
					::neash::geom::Vector3D a = ::neash::geom::Vector3D_obj::__new((v3->x - v1->x),(v3->y - v1->y),(v3->z - v1->z),null());		HX_STACK_VAR(a,"a");
					HX_STACK_LINE(304)
					return ::neash::geom::Vector3D_obj::__new(((_this->y * a->z) - (_this->z * a->y)),((_this->z * a->x) - (_this->x * a->z)),((_this->x * a->y) - (_this->y * a->x)),(int)1);
				}
				return null();
			}
		};
		HX_STACK_LINE(304)
		::neash::geom::Vector3D N = _Function_1_2::Block(v1,v3,v2);		HX_STACK_VAR(N,"N");
		HX_STACK_LINE(305)
		{
			HX_STACK_LINE(305)
			Float l = ::Math_obj::sqrt((((N->x * N->x) + (N->y * N->y)) + (N->z * N->z)));		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(305)
			if (((l != (int)0))){
				HX_STACK_LINE(305)
				hx::DivEq(N->x,l);
				HX_STACK_LINE(305)
				hx::DivEq(N->y,l);
				HX_STACK_LINE(305)
				hx::DivEq(N->z,l);
			}
			HX_STACK_LINE(305)
			l;
		}
		HX_STACK_LINE(308)
		::neash::geom::Vector3D G = ::neash::geom::Vector3D_obj::__new((Float(-(N->x)) / Float(N->z)),(Float(-(N->y)) / Float(N->z)),(int)0,null());		HX_STACK_VAR(G,"G");
		HX_STACK_LINE(311)
		::neash::geom::Vector3D C = ::neash::geom::Vector3D_obj::__new((V->x - (G->x * ((Float((Float(((V->z - 0.5))) / Float(::Math_obj::sqrt((((G->x * G->x) + (G->y * G->y)) + (G->z * G->z)))))) / Float(::Math_obj::sqrt((((G->x * G->x) + (G->y * G->y)) + (G->z * G->z)))))))),(V->y - (G->y * ((Float((Float(((V->z - 0.5))) / Float(::Math_obj::sqrt((((G->x * G->x) + (G->y * G->y)) + (G->z * G->z)))))) / Float(::Math_obj::sqrt((((G->x * G->x) + (G->y * G->y)) + (G->z * G->z)))))))),null(),null());		HX_STACK_VAR(C,"C");
		HX_STACK_LINE(313)
		if (((::Math_obj::sqrt((((G->x * G->x) + (G->y * G->y)) + (G->z * G->z))) < 1e-6))){
			HX_STACK_LINE(318)
			int color = colors1->__get((int)0)->__get((int)0);		HX_STACK_VAR(color,"color");
			HX_STACK_LINE(319)
			if (((colors1->__get((int)0)->length == (int)2))){
				HX_STACK_LINE(319)
				color = ::VoronoiDashboard_obj::interpolateColor(colors1->__get((int)0)->__get((int)0),colors1->__get((int)0)->__get((int)1),V->z);
			}
			else{
				HX_STACK_LINE(321)
				if (((colors1->__get((int)0)->length == (int)3))){
					HX_STACK_LINE(321)
					if (((V->z < 0.5))){
						HX_STACK_LINE(322)
						color = ::VoronoiDashboard_obj::interpolateColor(colors1->__get((int)0)->__get((int)0),colors1->__get((int)0)->__get((int)1),(V->z * (int)2));
					}
					else{
						HX_STACK_LINE(324)
						color = ::VoronoiDashboard_obj::interpolateColor(colors1->__get((int)0)->__get((int)1),colors1->__get((int)0)->__get((int)2),((V->z * (int)2) - (int)1));
					}
				}
			}
			HX_STACK_LINE(328)
			graphics->beginFill(color,null());
		}
		else{
			HX_STACK_LINE(332)
			m->createGradientBox((int)1,(int)1,(int)0,(int)0,(int)0);
			HX_STACK_LINE(333)
			m->translate(-0.5,-0.5);
			HX_STACK_LINE(334)
			m->scale((Float((int)1) / Float(::Math_obj::sqrt((((G->x * G->x) + (G->y * G->y)) + (G->z * G->z))))),(Float((int)1) / Float(::Math_obj::sqrt((((G->x * G->x) + (G->y * G->y)) + (G->z * G->z))))));
			HX_STACK_LINE(335)
			m->rotate(::Math_obj::atan2(G->y,G->x));
			HX_STACK_LINE(336)
			m->translate(C->x,C->y);

			HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_2_1)
			Float run(int c){
				HX_STACK_PUSH("*::_Function_2_1","VoronoiDashboard.hx",337);
				HX_STACK_ARG(c,"c");
				{
					HX_STACK_LINE(337)
					return 1.0;
				}
				return null();
			}
			HX_END_LOCAL_FUNC1(return)

			HX_STACK_LINE(337)
			Array< Float > alphas = ::Lambda_obj::array(::Lambda_obj::map(colors1->__get((int)0), Dynamic(new _Function_2_1())));		HX_STACK_VAR(alphas,"alphas");

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_2,Array< Array< int > >,colors1)
			Float run(int index,int c){
				HX_STACK_PUSH("*::_Function_2_2","VoronoiDashboard.hx",338);
				HX_STACK_ARG(index,"index");
				HX_STACK_ARG(c,"c");
				{
					HX_STACK_LINE(338)
					return (Float(((int)255 * index)) / Float(((colors1->__get((int)0)->length - (int)1))));
				}
				return null();
			}
			HX_END_LOCAL_FUNC2(return)

			HX_STACK_LINE(338)
			Array< Float > spread = ::Lambda_obj::array(::Lambda_obj::mapi(colors1->__get((int)0), Dynamic(new _Function_2_2(colors1))));		HX_STACK_VAR(spread,"spread");
			HX_STACK_LINE(339)
			graphics->beginGradientFill(::neash::display::GradientType_obj::LINEAR_dyn(),colors1->__get((int)0),alphas,spread,m,::neash::display::SpreadMethod_obj::PAD_dyn(),null(),null());
		}
		HX_STACK_LINE(341)
		fillFunction().Cast< Void >();
		HX_STACK_LINE(342)
		graphics->endFill();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(VoronoiDashboard_obj,drawGradientTriangle,(void))

Void VoronoiDashboard_obj::renderDebugPolygons( ::neash::display::Graphics graphics,::Map map,::Lava lava){
{
		HX_STACK_PUSH("VoronoiDashboard::renderDebugPolygons","VoronoiDashboard.hx",346);
		HX_STACK_ARG(graphics,"graphics");
		HX_STACK_ARG(map,"map");
		HX_STACK_ARG(lava,"lava");
		HX_STACK_LINE(347)
		::nme::Lib_obj::trace(HX_CSTRING("in render debug poly"));
		HX_STACK_LINE(348)
		::neash::display::Shape shape = ::neash::display::Shape_obj::__new();		HX_STACK_VAR(shape,"shape");
		HX_STACK_LINE(349)
		::graph::Center p;		HX_STACK_VAR(p,"p");
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		::graph::Edge edge;		HX_STACK_VAR(edge,"edge");
		::neash::geom::Point point;		HX_STACK_VAR(point,"point");
		int color;		HX_STACK_VAR(color,"color");
		HX_STACK_LINE(350)
		if (((map->centers->length == (int)0))){
			HX_STACK_LINE(351)
			::nme::Lib_obj::trace((HX_CSTRING("there is 0 map.centers: ") + ::Std_obj::string(map->centers->length)));
			HX_STACK_LINE(353)
			graphics->beginFill((int)14540253,null());
			HX_STACK_LINE(354)
			graphics->drawRect((int)0,(int)0,map->SIZE->__Field(HX_CSTRING("width"),true),map->SIZE->__Field(HX_CSTRING("height"),true));
			HX_STACK_LINE(355)
			graphics->endFill();
			HX_STACK_LINE(356)
			{
				HX_STACK_LINE(356)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::neash::geom::Point > _g1 = map->points;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(356)
				while(((_g < _g1->length))){
					HX_STACK_LINE(356)
					::neash::geom::Point point1 = _g1->__get(_g);		HX_STACK_VAR(point1,"point1");
					HX_STACK_LINE(356)
					++(_g);
					HX_STACK_LINE(358)
					graphics->beginFill((int)0,null());
					HX_STACK_LINE(359)
					graphics->drawCircle(point1->x,point1->y,1.3);
					HX_STACK_LINE(360)
					graphics->endFill();
				}
			}
		}
		HX_STACK_LINE(364)
		{
			HX_STACK_LINE(364)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Center > _g1 = map->centers;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(364)
			while(((_g < _g1->length))){
				HX_STACK_LINE(364)
				::graph::Center p1 = _g1->__get(_g);		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(364)
				++(_g);
				HX_STACK_LINE(367)
				color = (  ((::NullHelper_obj::IsNotNull(p1->biome))) ? int(::Reflect_obj::field(::VoronoiDashboard_obj::displayColors,p1->biome)) : int((  ((p1->ocean)) ? int(::VoronoiDashboard_obj::displayColors->__Field(HX_CSTRING("OCEAN"),true)) : int((  ((p1->water)) ? int(::VoronoiDashboard_obj::displayColors->__Field(HX_CSTRING("RIVER"),true)) : int((int)16777215) )) )) );
				HX_STACK_LINE(369)
				graphics->beginFill(::VoronoiDashboard_obj::interpolateColor(color,(int)14540253,0.2),null());
				HX_STACK_LINE(370)
				{
					HX_STACK_LINE(370)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Edge > _g3 = p1->borders;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(370)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(370)
						::graph::Edge edge1 = _g3->__get(_g2);		HX_STACK_VAR(edge1,"edge1");
						HX_STACK_LINE(370)
						++(_g2);
						HX_STACK_LINE(371)
						if (((bool((edge1->v0 != null())) && bool((edge1->v1 != null()))))){
							HX_STACK_LINE(372)
							graphics->moveTo(p1->point->x,p1->point->y);
							HX_STACK_LINE(373)
							graphics->lineTo(edge1->v0->point->x,edge1->v0->point->y);
							HX_STACK_LINE(374)
							if (((edge1->river > (int)0))){
								HX_STACK_LINE(374)
								graphics->lineStyle((int)2,::VoronoiDashboard_obj::displayColors->__Field(HX_CSTRING("RIVER"),true),1.0,null(),null(),null(),null(),null());
							}
							else{
								HX_STACK_LINE(376)
								if ((lava->lava->__GetItem(edge1->index))){
									HX_STACK_LINE(376)
									graphics->lineStyle((int)2,::VoronoiDashboard_obj::displayColors->__Field(HX_CSTRING("LAVA"),true),1.0,null(),null(),null(),null(),null());
								}
								else{
									HX_STACK_LINE(378)
									graphics->lineStyle((int)0,(int)0,0.4,null(),null(),null(),null(),null());
								}
							}
							HX_STACK_LINE(381)
							graphics->lineTo(edge1->v1->point->x,edge1->v1->point->y);
							HX_STACK_LINE(382)
							graphics->lineStyle(null(),null(),null(),null(),null(),null(),null(),null());
						}
					}
				}
				HX_STACK_LINE(385)
				graphics->endFill();
				HX_STACK_LINE(386)
				graphics->beginFill((  ((p1->water)) ? int((int)13107) : int((int)0) ),0.7);
				HX_STACK_LINE(387)
				graphics->drawCircle(p1->point->x,p1->point->y,1.3);
				HX_STACK_LINE(388)
				graphics->endFill();
				HX_STACK_LINE(389)
				{
					HX_STACK_LINE(389)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Corner > _g3 = p1->corners;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(389)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(389)
						::graph::Corner q1 = _g3->__get(_g2);		HX_STACK_VAR(q1,"q1");
						HX_STACK_LINE(389)
						++(_g2);
						HX_STACK_LINE(390)
						graphics->beginFill((  ((::NullHelper_obj::IsNotNull(q1->water))) ? int((int)255) : int((int)39168) ),null());
						HX_STACK_LINE(391)
						graphics->drawRect((q1->point->x - 0.7),(q1->point->y - 0.7),1.5,1.5);
						HX_STACK_LINE(392)
						graphics->endFill();
					}
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(VoronoiDashboard_obj,renderDebugPolygons,(void))

int VoronoiDashboard_obj::interpolateColor( int color0,int color1,Float f){
	HX_STACK_PUSH("VoronoiDashboard::interpolateColor","VoronoiDashboard.hx",398);
	HX_STACK_ARG(color0,"color0");
	HX_STACK_ARG(color1,"color1");
	HX_STACK_ARG(f,"f");
	HX_STACK_LINE(399)
	int r = ::Std_obj::_int((((((int)1 - f)) * ((int(color0) >> int((int)16)))) + (f * ((int(color1) >> int((int)16))))));		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(400)
	int g = ::Std_obj::_int((((((int)1 - f)) * ((int((int(color0) >> int((int)8))) & int((int)255)))) + (f * ((int((int(color1) >> int((int)8))) & int((int)255))))));		HX_STACK_VAR(g,"g");
	HX_STACK_LINE(401)
	int b = ::Std_obj::_int((((((int)1 - f)) * ((int(color0) & int((int)255)))) + (f * ((int(color1) & int((int)255))))));		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(402)
	if (((r > (int)255))){
		HX_STACK_LINE(402)
		r = (int)255;
	}
	HX_STACK_LINE(403)
	if (((g > (int)255))){
		HX_STACK_LINE(403)
		g = (int)255;
	}
	HX_STACK_LINE(404)
	if (((b > (int)255))){
		HX_STACK_LINE(404)
		b = (int)255;
	}
	HX_STACK_LINE(405)
	return (int((int((int(r) << int((int)16))) | int((int(g) << int((int)8))))) | int(b));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(VoronoiDashboard_obj,interpolateColor,return )

int VoronoiDashboard_obj::colorWithSlope( int color,::graph::Center p,::graph::Center q,::graph::Edge edge){
	HX_STACK_PUSH("VoronoiDashboard::colorWithSlope","VoronoiDashboard.hx",408);
	HX_STACK_ARG(color,"color");
	HX_STACK_ARG(p,"p");
	HX_STACK_ARG(q,"q");
	HX_STACK_ARG(edge,"edge");
	HX_STACK_LINE(409)
	::graph::Corner r = edge->v0;		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(410)
	::graph::Corner s = edge->v1;		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(411)
	if (((bool(::NullHelper_obj::IsNull(r)) || bool(::NullHelper_obj::IsNull(s))))){
		HX_STACK_LINE(411)
		return ::VoronoiDashboard_obj::displayColors->__Field(HX_CSTRING("OCEAN"),true);
	}
	else{
		HX_STACK_LINE(414)
		if ((p->water)){
			HX_STACK_LINE(414)
			return color;
		}
	}
	HX_STACK_LINE(419)
	if (((bool((q != null())) && bool((p->water == q->water))))){
		HX_STACK_LINE(419)
		color = ::VoronoiDashboard_obj::interpolateColor(color,::Reflect_obj::field(::VoronoiDashboard_obj::displayColors,q->biome),0.4);
	}
	HX_STACK_LINE(420)
	int colorLow = ::VoronoiDashboard_obj::interpolateColor(color,(int)3355443,0.3);		HX_STACK_VAR(colorLow,"colorLow");
	HX_STACK_LINE(421)
	int colorHigh = ::VoronoiDashboard_obj::interpolateColor(color,(int)16777215,0.1);		HX_STACK_VAR(colorHigh,"colorHigh");
	HX_STACK_LINE(422)
	Float light = ::VoronoiDashboard_obj::calculateLighting(p,r,s);		HX_STACK_VAR(light,"light");
	HX_STACK_LINE(423)
	if (((light < 0.5))){
		HX_STACK_LINE(423)
		return ::VoronoiDashboard_obj::interpolateColor(colorLow,color,(light * (int)2));
	}
	else{
		HX_STACK_LINE(424)
		return ::VoronoiDashboard_obj::interpolateColor(color,colorHigh,((light * (int)2) - (int)1));
	}
	HX_STACK_LINE(423)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(VoronoiDashboard_obj,colorWithSlope,return )

::neash::geom::Vector3D VoronoiDashboard_obj::lightVector;

Float VoronoiDashboard_obj::calculateLighting( ::graph::Center p,::graph::Corner r,::graph::Corner s){
	HX_STACK_PUSH("VoronoiDashboard::calculateLighting","VoronoiDashboard.hx",428);
	HX_STACK_ARG(p,"p");
	HX_STACK_ARG(r,"r");
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(429)
	::neash::geom::Vector3D A = ::neash::geom::Vector3D_obj::__new(p->point->x,p->point->y,p->elevation,null());		HX_STACK_VAR(A,"A");
	HX_STACK_LINE(430)
	::neash::geom::Vector3D B = ::neash::geom::Vector3D_obj::__new(r->point->x,r->point->y,r->elevation,null());		HX_STACK_VAR(B,"B");
	HX_STACK_LINE(431)
	::neash::geom::Vector3D C = ::neash::geom::Vector3D_obj::__new(s->point->x,s->point->y,s->elevation,null());		HX_STACK_VAR(C,"C");
	struct _Function_1_1{
		inline static ::neash::geom::Vector3D Block( ::neash::geom::Vector3D &A,::neash::geom::Vector3D &C,::neash::geom::Vector3D &B){
			HX_STACK_PUSH("*::closure","VoronoiDashboard.hx",432);
			{
				HX_STACK_LINE(432)
				::neash::geom::Vector3D _this = ::neash::geom::Vector3D_obj::__new((B->x - A->x),(B->y - A->y),(B->z - A->z),null());		HX_STACK_VAR(_this,"_this");
				::neash::geom::Vector3D a = ::neash::geom::Vector3D_obj::__new((C->x - A->x),(C->y - A->y),(C->z - A->z),null());		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(432)
				return ::neash::geom::Vector3D_obj::__new(((_this->y * a->z) - (_this->z * a->y)),((_this->z * a->x) - (_this->x * a->z)),((_this->x * a->y) - (_this->y * a->x)),(int)1);
			}
			return null();
		}
	};
	HX_STACK_LINE(432)
	::neash::geom::Vector3D normal = _Function_1_1::Block(A,C,B);		HX_STACK_VAR(normal,"normal");
	HX_STACK_LINE(433)
	if (((normal->z < (int)0))){
		HX_STACK_LINE(433)
		hx::MultEq(normal->x,(int)-1);
		HX_STACK_LINE(433)
		hx::MultEq(normal->y,(int)-1);
		HX_STACK_LINE(433)
		hx::MultEq(normal->z,(int)-1);
	}
	HX_STACK_LINE(434)
	{
		HX_STACK_LINE(434)
		Float l = ::Math_obj::sqrt((((normal->x * normal->x) + (normal->y * normal->y)) + (normal->z * normal->z)));		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(434)
		if (((l != (int)0))){
			HX_STACK_LINE(434)
			hx::DivEq(normal->x,l);
			HX_STACK_LINE(434)
			hx::DivEq(normal->y,l);
			HX_STACK_LINE(434)
			hx::DivEq(normal->z,l);
		}
		HX_STACK_LINE(434)
		l;
	}
	struct _Function_1_2{
		inline static Float Block( ::neash::geom::Vector3D &normal){
			HX_STACK_PUSH("*::closure","VoronoiDashboard.hx",435);
			{
				HX_STACK_LINE(435)
				::neash::geom::Vector3D a = ::VoronoiDashboard_obj::lightVector;		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(435)
				return (((normal->x * a->x) + (normal->y * a->y)) + (normal->z * a->z));
			}
			return null();
		}
	};
	HX_STACK_LINE(435)
	Float light = (0.5 + ((int)35 * _Function_1_2::Block(normal)));		HX_STACK_VAR(light,"light");
	HX_STACK_LINE(436)
	if (((light < (int)0))){
		HX_STACK_LINE(436)
		light = (int)0;
	}
	HX_STACK_LINE(437)
	if (((light > (int)1))){
		HX_STACK_LINE(437)
		light = (int)1;
	}
	HX_STACK_LINE(438)
	return light;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(VoronoiDashboard_obj,calculateLighting,return )

Void VoronoiDashboard_obj::main( ){
{
		HX_STACK_PUSH("VoronoiDashboard::main","VoronoiDashboard.hx",442);
		HX_STACK_LINE(442)
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
		if (HX_FIELD_EQ(inName,"shape") ) { return shape; }
		if (HX_FIELD_EQ(inName,"state") ) { return state; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"generate") ) { return generate_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"renderEdges") ) { return renderEdges_dyn(); }
		if (HX_FIELD_EQ(inName,"lightVector") ) { return lightVector; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"displayColors") ) { return displayColors; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"renderPolygons") ) { return renderPolygons_dyn(); }
		if (HX_FIELD_EQ(inName,"colorWithSlope") ) { return colorWithSlope_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"drawPathForwards") ) { return drawPathForwards_dyn(); }
		if (HX_FIELD_EQ(inName,"interpolateColor") ) { return interpolateColor_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"drawPathBackwards") ) { return drawPathBackwards_dyn(); }
		if (HX_FIELD_EQ(inName,"calculateLighting") ) { return calculateLighting_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"renderDebugPolygons") ) { return renderDebugPolygons_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"drawGradientTriangle") ) { return drawGradientTriangle_dyn(); }
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
		if (HX_FIELD_EQ(inName,"shape") ) { shape=inValue.Cast< ::neash::display::Shape >(); return inValue; }
		if (HX_FIELD_EQ(inName,"state") ) { state=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"lightVector") ) { lightVector=inValue.Cast< ::neash::geom::Vector3D >(); return inValue; }
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
	HX_CSTRING("shape"),
	HX_CSTRING("state"),
	HX_CSTRING("SIZE"),
	HX_CSTRING("displayColors"),
	HX_CSTRING("elevationGradientColors"),
	HX_CSTRING("generate"),
	HX_CSTRING("render"),
	HX_CSTRING("renderEdges"),
	HX_CSTRING("renderPolygons"),
	HX_CSTRING("drawPathForwards"),
	HX_CSTRING("drawPathBackwards"),
	HX_CSTRING("drawGradientTriangle"),
	HX_CSTRING("renderDebugPolygons"),
	HX_CSTRING("interpolateColor"),
	HX_CSTRING("colorWithSlope"),
	HX_CSTRING("lightVector"),
	HX_CSTRING("calculateLighting"),
	HX_CSTRING("main"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(VoronoiDashboard_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(VoronoiDashboard_obj::seed,"seed");
	HX_MARK_MEMBER_NAME(VoronoiDashboard_obj::shape,"shape");
	HX_MARK_MEMBER_NAME(VoronoiDashboard_obj::state,"state");
	HX_MARK_MEMBER_NAME(VoronoiDashboard_obj::SIZE,"SIZE");
	HX_MARK_MEMBER_NAME(VoronoiDashboard_obj::displayColors,"displayColors");
	HX_MARK_MEMBER_NAME(VoronoiDashboard_obj::elevationGradientColors,"elevationGradientColors");
	HX_MARK_MEMBER_NAME(VoronoiDashboard_obj::lightVector,"lightVector");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(VoronoiDashboard_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(VoronoiDashboard_obj::seed,"seed");
	HX_VISIT_MEMBER_NAME(VoronoiDashboard_obj::shape,"shape");
	HX_VISIT_MEMBER_NAME(VoronoiDashboard_obj::state,"state");
	HX_VISIT_MEMBER_NAME(VoronoiDashboard_obj::SIZE,"SIZE");
	HX_VISIT_MEMBER_NAME(VoronoiDashboard_obj::displayColors,"displayColors");
	HX_VISIT_MEMBER_NAME(VoronoiDashboard_obj::elevationGradientColors,"elevationGradientColors");
	HX_VISIT_MEMBER_NAME(VoronoiDashboard_obj::lightVector,"lightVector");
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
		HX_STACK_PUSH("*::closure","VoronoiDashboard.hx",45);
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
		HX_STACK_PUSH("*::closure","VoronoiDashboard.hx",48);
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
		HX_STACK_PUSH("*::closure","VoronoiDashboard.hx",80);
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
	lightVector= ::neash::geom::Vector3D_obj::__new((int)-1,(int)-1,(int)0,null());
}


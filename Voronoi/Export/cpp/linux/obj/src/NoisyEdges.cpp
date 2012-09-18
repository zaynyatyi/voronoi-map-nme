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
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif

Void NoisyEdges_obj::__construct()
{
HX_STACK_PUSH("NoisyEdges::new","NoisyEdges.hx",20);
{
	HX_STACK_LINE(22)
	this->path1 = Dynamic( Array_obj<Dynamic>::__new());
	HX_STACK_LINE(23)
	this->path0 = Dynamic( Array_obj<Dynamic>::__new());
}
;
	return null();
}

NoisyEdges_obj::~NoisyEdges_obj() { }

Dynamic NoisyEdges_obj::__CreateEmpty() { return  new NoisyEdges_obj; }
hx::ObjectPtr< NoisyEdges_obj > NoisyEdges_obj::__new()
{  hx::ObjectPtr< NoisyEdges_obj > result = new NoisyEdges_obj();
	result->__construct();
	return result;}

Dynamic NoisyEdges_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NoisyEdges_obj > result = new NoisyEdges_obj();
	result->__construct();
	return result;}

Void NoisyEdges_obj::buildNoisyEdges( ::Map map,::Lava lava,::de::polygonal::math::PM_PRNG random){
{
		HX_STACK_PUSH("NoisyEdges::buildNoisyEdges","NoisyEdges.hx",31);
		HX_STACK_THIS(this);
		HX_STACK_ARG(map,"map");
		HX_STACK_ARG(lava,"lava");
		HX_STACK_ARG(random,"random");
		HX_STACK_LINE(32)
		::graph::Center p;		HX_STACK_VAR(p,"p");
		::graph::Edge edge;		HX_STACK_VAR(edge,"edge");
		HX_STACK_LINE(33)
		{
			HX_STACK_LINE(33)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Center > _g1 = map->centers;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(33)
			while(((_g < _g1->length))){
				HX_STACK_LINE(33)
				::graph::Center p1 = _g1->__get(_g);		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(33)
				++(_g);
				HX_STACK_LINE(35)
				{
					HX_STACK_LINE(35)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Edge > _g3 = p1->borders;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(35)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(35)
						::graph::Edge edge1 = _g3->__get(_g2);		HX_STACK_VAR(edge1,"edge1");
						HX_STACK_LINE(35)
						++(_g2);
						HX_STACK_LINE(37)
						if (((bool((bool((bool((bool((edge1->d0 != null())) && bool((edge1->d1 != null())))) && bool((edge1->v0 != null())))) && bool((edge1->v1 != null())))) && bool((this->path0->__GetItem(edge1->index) == null()))))){
							HX_STACK_LINE(39)
							Float f = ::NoisyEdges_obj::NOISY_LINE_TRADEOFF;		HX_STACK_VAR(f,"f");
							HX_STACK_LINE(40)
							::neash::geom::Point t = ::neash::geom::Point_obj::interpolate(edge1->v0->point,edge1->d0->point,f);		HX_STACK_VAR(t,"t");
							HX_STACK_LINE(41)
							::neash::geom::Point q = ::neash::geom::Point_obj::interpolate(edge1->v0->point,edge1->d1->point,f);		HX_STACK_VAR(q,"q");
							HX_STACK_LINE(42)
							::neash::geom::Point r = ::neash::geom::Point_obj::interpolate(edge1->v1->point,edge1->d0->point,f);		HX_STACK_VAR(r,"r");
							HX_STACK_LINE(43)
							::neash::geom::Point s = ::neash::geom::Point_obj::interpolate(edge1->v1->point,edge1->d1->point,f);		HX_STACK_VAR(s,"s");
							HX_STACK_LINE(45)
							int minLength = (int)20;		HX_STACK_VAR(minLength,"minLength");
							HX_STACK_LINE(46)
							if (((edge1->d0->biome != edge1->d1->biome))){
								HX_STACK_LINE(46)
								minLength = (int)3;
							}
							HX_STACK_LINE(47)
							if (((bool(edge1->d0->ocean) && bool(edge1->d1->ocean)))){
								HX_STACK_LINE(47)
								minLength = (int)100;
							}
							HX_STACK_LINE(48)
							if (((bool(edge1->d0->coast) || bool(edge1->d1->coast)))){
								HX_STACK_LINE(48)
								minLength = (int)1;
							}
							HX_STACK_LINE(49)
							if (((bool((edge1->river > (int)0)) || bool((lava->lava->__GetItem(edge1->index) != null()))))){
								HX_STACK_LINE(49)
								minLength = (int)1;
							}
							HX_STACK_LINE(51)
							hx::IndexRef((this->path0).mPtr,edge1->index) = ::NoisyEdges_obj::buildNoisyLineSegments(random,edge1->v0->point,t,edge1->midpoint,q,minLength);
							HX_STACK_LINE(52)
							hx::IndexRef((this->path1).mPtr,edge1->index) = ::NoisyEdges_obj::buildNoisyLineSegments(random,edge1->v1->point,s,edge1->midpoint,r,minLength);
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(NoisyEdges_obj,buildNoisyEdges,(void))

Float NoisyEdges_obj::NOISY_LINE_TRADEOFF;

Array< ::neash::geom::Point > NoisyEdges_obj::buildNoisyLineSegments( ::de::polygonal::math::PM_PRNG random,::neash::geom::Point A,::neash::geom::Point B,::neash::geom::Point C,::neash::geom::Point D,Float minLength){
	HX_STACK_PUSH("NoisyEdges::buildNoisyLineSegments","NoisyEdges.hx",61);
	HX_STACK_ARG(random,"random");
	HX_STACK_ARG(A,"A");
	HX_STACK_ARG(B,"B");
	HX_STACK_ARG(C,"C");
	HX_STACK_ARG(D,"D");
	HX_STACK_ARG(minLength,"minLength");
	HX_STACK_LINE(61)
	Array< Float > minLength1 = Array_obj< Float >::__new().Add(minLength);		HX_STACK_VAR(minLength1,"minLength1");
	HX_STACK_LINE(61)
	Array< ::de::polygonal::math::PM_PRNG > random1 = Array_obj< ::de::polygonal::math::PM_PRNG >::__new().Add(random);		HX_STACK_VAR(random1,"random1");
	HX_STACK_LINE(62)
	Array< Array< ::neash::geom::Point > > points = Array_obj< Array< ::neash::geom::Point > >::__new().Add(Array_obj< ::neash::geom::Point >::__new());		HX_STACK_VAR(points,"points");
	HX_STACK_LINE(64)
	int limit = (int)10;		HX_STACK_VAR(limit,"limit");
	struct _Function_1_1{
		inline static Dynamic Block( Array< Float > &minLength1,Array< ::de::polygonal::math::PM_PRNG > &random1,Array< Array< ::neash::geom::Point > > &points){
			HX_STACK_PUSH("*::closure","NoisyEdges.hx",66);
			{
				HX_STACK_LINE(66)
				Dynamic subdivide = Dynamic( Array_obj<Dynamic>::__new().Add(null()));		HX_STACK_VAR(subdivide,"subdivide");

				HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_2_1,Dynamic,subdivide,Array< Float >,minLength1,Array< ::de::polygonal::math::PM_PRNG >,random1,Array< Array< ::neash::geom::Point > >,points)
				Void run(::neash::geom::Point A1,::neash::geom::Point B1,::neash::geom::Point C1,::neash::geom::Point D1,hx::Null< bool >  __o_proceed){
					bool proceed = __o_proceed.Default(true);
					{
						HX_STACK_PUSH("*::_Function_2_1","NoisyEdges.hx",66);
						HX_STACK_ARG(A1,"A1");
						HX_STACK_ARG(B1,"B1");
						HX_STACK_ARG(C1,"C1");
						HX_STACK_ARG(D1,"D1");
						HX_STACK_ARG(proceed,"proceed");
						{
							HX_STACK_LINE(67)
							if ((!(proceed))){
								HX_STACK_LINE(68)
								return null();
							}
							HX_STACK_LINE(71)
							if (((bool((A1->subtract(C1)->nmeGetLength() < minLength1->__get((int)0))) || bool((B1->subtract(D1)->nmeGetLength() < minLength1->__get((int)0)))))){
								HX_STACK_LINE(72)
								return null();
							}
							HX_STACK_LINE(77)
							Float p = random1->__get((int)0)->nextDoubleRange(0.2,0.8);		HX_STACK_VAR(p,"p");
							HX_STACK_LINE(78)
							Float q = random1->__get((int)0)->nextDoubleRange(0.2,0.8);		HX_STACK_VAR(q,"q");
							HX_STACK_LINE(82)
							::neash::geom::Point E = ::neash::geom::Point_obj::interpolate(A1,D1,p);		HX_STACK_VAR(E,"E");
							HX_STACK_LINE(83)
							::neash::geom::Point F = ::neash::geom::Point_obj::interpolate(B1,C1,p);		HX_STACK_VAR(F,"F");
							HX_STACK_LINE(84)
							::neash::geom::Point G = ::neash::geom::Point_obj::interpolate(A1,B1,q);		HX_STACK_VAR(G,"G");
							HX_STACK_LINE(85)
							::neash::geom::Point I = ::neash::geom::Point_obj::interpolate(D1,C1,q);		HX_STACK_VAR(I,"I");
							HX_STACK_LINE(88)
							::neash::geom::Point H = ::neash::geom::Point_obj::interpolate(E,F,q);		HX_STACK_VAR(H,"H");
							HX_STACK_LINE(91)
							Float s = (1.0 - random1->__get((int)0)->nextDoubleRange(-0.4,0.4));		HX_STACK_VAR(s,"s");
							HX_STACK_LINE(92)
							Float t = (1.0 - random1->__get((int)0)->nextDoubleRange(-0.4,0.4));		HX_STACK_VAR(t,"t");
							HX_STACK_LINE(97)
							subdivide->__GetItem((int)0)(A1,::neash::geom::Point_obj::interpolate(G,B1,s),H,::neash::geom::Point_obj::interpolate(E,D1,t),false).Cast< Void >();
							HX_STACK_LINE(98)
							points->__get((int)0)->push(H);
							HX_STACK_LINE(99)
							subdivide->__GetItem((int)0)(H,::neash::geom::Point_obj::interpolate(F,C1,s),C1,::neash::geom::Point_obj::interpolate(I,D1,t),false).Cast< Void >();
						}
						return null();
					}
				}
				HX_END_LOCAL_FUNC5((void))

				HX_STACK_LINE(66)
				hx::IndexRef((subdivide).mPtr,(int)0) =  Dynamic(new _Function_2_1(subdivide,minLength1,random1,points));
				HX_STACK_LINE(66)
				return subdivide->__GetItem((int)0);
			}
			return null();
		}
	};
	HX_STACK_LINE(66)
	Dynamic subdivide = _Function_1_1::Block(minLength1,random1,points);		HX_STACK_VAR(subdivide,"subdivide");
	HX_STACK_LINE(102)
	points->__get((int)0)->push(A);
	HX_STACK_LINE(103)
	subdivide(A,B,C,D,null()).Cast< Void >();
	HX_STACK_LINE(104)
	points->__get((int)0)->push(C);
	HX_STACK_LINE(105)
	return points->__get((int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(NoisyEdges_obj,buildNoisyLineSegments,return )


NoisyEdges_obj::NoisyEdges_obj()
{
}

void NoisyEdges_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NoisyEdges);
	HX_MARK_MEMBER_NAME(path1,"path1");
	HX_MARK_MEMBER_NAME(path0,"path0");
	HX_MARK_END_CLASS();
}

void NoisyEdges_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(path1,"path1");
	HX_VISIT_MEMBER_NAME(path0,"path0");
}

Dynamic NoisyEdges_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"path1") ) { return path1; }
		if (HX_FIELD_EQ(inName,"path0") ) { return path0; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"buildNoisyEdges") ) { return buildNoisyEdges_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"NOISY_LINE_TRADEOFF") ) { return NOISY_LINE_TRADEOFF; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"buildNoisyLineSegments") ) { return buildNoisyLineSegments_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NoisyEdges_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"path1") ) { path1=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"path0") ) { path0=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"NOISY_LINE_TRADEOFF") ) { NOISY_LINE_TRADEOFF=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void NoisyEdges_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("path1"));
	outFields->push(HX_CSTRING("path0"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("NOISY_LINE_TRADEOFF"),
	HX_CSTRING("buildNoisyLineSegments"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("buildNoisyEdges"),
	HX_CSTRING("path1"),
	HX_CSTRING("path0"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NoisyEdges_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(NoisyEdges_obj::NOISY_LINE_TRADEOFF,"NOISY_LINE_TRADEOFF");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NoisyEdges_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(NoisyEdges_obj::NOISY_LINE_TRADEOFF,"NOISY_LINE_TRADEOFF");
};

Class NoisyEdges_obj::__mClass;

void NoisyEdges_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("NoisyEdges"), hx::TCanCast< NoisyEdges_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NoisyEdges_obj::__boot()
{
	NOISY_LINE_TRADEOFF= 0.5;
}


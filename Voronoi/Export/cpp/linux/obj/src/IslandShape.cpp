#include <hxcpp.h>

#ifndef INCLUDED_IslandShape
#include <IslandShape.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_co_janicek_core_array_Array2dCore
#include <co/janicek/core/array/Array2dCore.h>
#endif
#ifndef INCLUDED_co_janicek_core_math_PerlinNoise
#include <co/janicek/core/math/PerlinNoise.h>
#endif
#ifndef INCLUDED_de_polygonal_math_PM_PRNG
#include <de/polygonal/math/PM_PRNG.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif

Void IslandShape_obj::__construct()
{
	return null();
}

IslandShape_obj::~IslandShape_obj() { }

Dynamic IslandShape_obj::__CreateEmpty() { return  new IslandShape_obj; }
hx::ObjectPtr< IslandShape_obj > IslandShape_obj::__new()
{  hx::ObjectPtr< IslandShape_obj > result = new IslandShape_obj();
	result->__construct();
	return result;}

Dynamic IslandShape_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< IslandShape_obj > result = new IslandShape_obj();
	result->__construct();
	return result;}

Float IslandShape_obj::ISLAND_FACTOR;

Dynamic IslandShape_obj::makeRadial( int seed){
	HX_STACK_PUSH("IslandShape::makeRadial","Map.hx",912);
	HX_STACK_ARG(seed,"seed");
	HX_STACK_LINE(913)
	::de::polygonal::math::PM_PRNG islandRandom = ::de::polygonal::math::PM_PRNG_obj::__new();		HX_STACK_VAR(islandRandom,"islandRandom");
	HX_STACK_LINE(914)
	islandRandom->seed = seed;
	HX_STACK_LINE(915)
	Array< int > bumps = Array_obj< int >::__new().Add(islandRandom->nextIntRange((int)1,(int)6));		HX_STACK_VAR(bumps,"bumps");
	HX_STACK_LINE(916)
	Array< Float > startAngle = Array_obj< Float >::__new().Add(islandRandom->nextDoubleRange((int)0,((int)2 * ::Math_obj::PI)));		HX_STACK_VAR(startAngle,"startAngle");
	HX_STACK_LINE(917)
	Array< Float > dipAngle = Array_obj< Float >::__new().Add(islandRandom->nextDoubleRange((int)0,((int)2 * ::Math_obj::PI)));		HX_STACK_VAR(dipAngle,"dipAngle");
	HX_STACK_LINE(918)
	Array< Float > dipWidth = Array_obj< Float >::__new().Add(islandRandom->nextDoubleRange(0.2,0.7));		HX_STACK_VAR(dipWidth,"dipWidth");

	HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_1_1,Array< int >,bumps,Array< Float >,dipAngle,Array< Float >,startAngle,Array< Float >,dipWidth)
	bool run(::neash::geom::Point q){
		HX_STACK_PUSH("*::_Function_1_1","Map.hx",920);
		HX_STACK_ARG(q,"q");
		{
			HX_STACK_LINE(921)
			Float angle = ::Math_obj::atan2(q->y,q->x);		HX_STACK_VAR(angle,"angle");
			HX_STACK_LINE(922)
			Float length = (0.5 * ((::Math_obj::max(::Math_obj::abs(q->x),::Math_obj::abs(q->y)) + q->nmeGetLength())));		HX_STACK_VAR(length,"length");
			HX_STACK_LINE(924)
			Float r1 = (0.5 + (0.40 * ::Math_obj::sin(((startAngle->__get((int)0) + (bumps->__get((int)0) * angle)) + ::Math_obj::cos((((bumps->__get((int)0) + (int)3)) * angle))))));		HX_STACK_VAR(r1,"r1");
			HX_STACK_LINE(925)
			Float r2 = (0.7 - (0.20 * ::Math_obj::sin(((startAngle->__get((int)0) + (bumps->__get((int)0) * angle)) - ::Math_obj::sin((((bumps->__get((int)0) + (int)2)) * angle))))));		HX_STACK_VAR(r2,"r2");
			HX_STACK_LINE(926)
			if (((bool((bool((::Math_obj::abs((angle - dipAngle->__get((int)0))) < dipWidth->__get((int)0))) || bool((::Math_obj::abs(((angle - dipAngle->__get((int)0)) + ((int)2 * ::Math_obj::PI))) < dipWidth->__get((int)0))))) || bool((::Math_obj::abs(((angle - dipAngle->__get((int)0)) - ((int)2 * ::Math_obj::PI))) < dipWidth->__get((int)0)))))){
				HX_STACK_LINE(928)
				r1 = r2 = 0.2;
			}
			HX_STACK_LINE(931)
			return (bool((length < r1)) || bool((bool((length > (r1 * ::IslandShape_obj::ISLAND_FACTOR))) && bool((length < r2)))));
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(920)
	Dynamic inside =  Dynamic(new _Function_1_1(bumps,dipAngle,startAngle,dipWidth));		HX_STACK_VAR(inside,"inside");
	HX_STACK_LINE(934)
	return inside;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(IslandShape_obj,makeRadial,return )

Dynamic IslandShape_obj::makePerlin( int seed){
	HX_STACK_PUSH("IslandShape::makePerlin","Map.hx",939);
	HX_STACK_ARG(seed,"seed");
	HX_STACK_LINE(945)
	Array< Array< Array< int > > > perlin = Array_obj< Array< Array< int > > >::__new();		HX_STACK_VAR(perlin,"perlin");
	HX_STACK_LINE(946)
	perlin[(int)0] = ::co::janicek::core::math::PerlinNoise_obj::makePerlinNoise((int)256,(int)256,1.0,1.0,1.0,seed,(int)8,null(),null());

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< Array< Array< int > > >,perlin)
	bool run(::neash::geom::Point q){
		HX_STACK_PUSH("*::_Function_1_1","Map.hx",949);
		HX_STACK_ARG(q,"q");
		{
			HX_STACK_LINE(953)
			Float c = (Float(((int(::co::janicek::core::array::Array2dCore_obj::get(perlin->__get((int)0),::Std_obj::_int((((q->x + (int)1)) * (int)128)),::Std_obj::_int((((q->y + (int)1)) * (int)128)))) & int((int)255)))) / Float(255.0));		HX_STACK_VAR(c,"c");
			HX_STACK_LINE(955)
			return (c > (0.3 + ((0.3 * q->nmeGetLength()) * q->nmeGetLength())));
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(949)
	return  Dynamic(new _Function_1_1(perlin));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(IslandShape_obj,makePerlin,return )

Dynamic IslandShape_obj::makeSquare( int seed){
	HX_STACK_PUSH("IslandShape::makeSquare","Map.hx",961);
	HX_STACK_ARG(seed,"seed");

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
	bool run(::neash::geom::Point q){
		HX_STACK_PUSH("*::_Function_1_1","Map.hx",962);
		HX_STACK_ARG(q,"q");
		{
			HX_STACK_LINE(962)
			return true;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(961)
	return  Dynamic(new _Function_1_1());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(IslandShape_obj,makeSquare,return )

Dynamic IslandShape_obj::makeBlob( int seed){
	HX_STACK_PUSH("IslandShape::makeBlob","Map.hx",969);
	HX_STACK_ARG(seed,"seed");

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
	bool run(::neash::geom::Point q){
		HX_STACK_PUSH("*::_Function_1_1","Map.hx",970);
		HX_STACK_ARG(q,"q");
		{
			HX_STACK_LINE(971)
			bool eye1 = (::neash::geom::Point_obj::__new((q->x - 0.2),((Float(q->y) / Float((int)2)) + 0.2))->nmeGetLength() < 0.05);		HX_STACK_VAR(eye1,"eye1");
			HX_STACK_LINE(972)
			bool eye2 = (::neash::geom::Point_obj::__new((q->x + 0.2),((Float(q->y) / Float((int)2)) + 0.2))->nmeGetLength() < 0.05);		HX_STACK_VAR(eye2,"eye2");
			HX_STACK_LINE(973)
			bool body = (q->nmeGetLength() < (0.8 - (0.18 * ::Math_obj::sin(((int)5 * ::Math_obj::atan2(q->y,q->x))))));		HX_STACK_VAR(body,"body");
			HX_STACK_LINE(974)
			return (bool((bool(body) && bool(!(eye1)))) && bool(!(eye2)));
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(969)
	return  Dynamic(new _Function_1_1());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(IslandShape_obj,makeBlob,return )


IslandShape_obj::IslandShape_obj()
{
}

void IslandShape_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(IslandShape);
	HX_MARK_END_CLASS();
}

void IslandShape_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic IslandShape_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"makeBlob") ) { return makeBlob_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"makeRadial") ) { return makeRadial_dyn(); }
		if (HX_FIELD_EQ(inName,"makePerlin") ) { return makePerlin_dyn(); }
		if (HX_FIELD_EQ(inName,"makeSquare") ) { return makeSquare_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"ISLAND_FACTOR") ) { return ISLAND_FACTOR; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic IslandShape_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"ISLAND_FACTOR") ) { ISLAND_FACTOR=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void IslandShape_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("ISLAND_FACTOR"),
	HX_CSTRING("makeRadial"),
	HX_CSTRING("makePerlin"),
	HX_CSTRING("makeSquare"),
	HX_CSTRING("makeBlob"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IslandShape_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(IslandShape_obj::ISLAND_FACTOR,"ISLAND_FACTOR");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IslandShape_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(IslandShape_obj::ISLAND_FACTOR,"ISLAND_FACTOR");
};

Class IslandShape_obj::__mClass;

void IslandShape_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("IslandShape"), hx::TCanCast< IslandShape_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void IslandShape_obj::__boot()
{
	ISLAND_FACTOR= 1.07;
}


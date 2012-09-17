#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_de_polygonal_math_PM_PRNG
#include <de/polygonal/math/PM_PRNG.h>
#endif
namespace de{
namespace polygonal{
namespace math{

Void PM_PRNG_obj::__construct()
{
HX_STACK_PUSH("PM_PRNG::new","de/polygonal/math/PM_PRNG.hx",13);
{
	HX_STACK_LINE(13)
	this->seed = (int)1;
}
;
	return null();
}

PM_PRNG_obj::~PM_PRNG_obj() { }

Dynamic PM_PRNG_obj::__CreateEmpty() { return  new PM_PRNG_obj; }
hx::ObjectPtr< PM_PRNG_obj > PM_PRNG_obj::__new()
{  hx::ObjectPtr< PM_PRNG_obj > result = new PM_PRNG_obj();
	result->__construct();
	return result;}

Dynamic PM_PRNG_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PM_PRNG_obj > result = new PM_PRNG_obj();
	result->__construct();
	return result;}

int PM_PRNG_obj::gen( ){
	HX_STACK_PUSH("PM_PRNG::gen","de/polygonal/math/PM_PRNG.hx",52);
	HX_STACK_THIS(this);
	HX_STACK_LINE(52)
	return this->seed = hx::Mod((this->seed * (int)16807),(int)2147483647);
}


HX_DEFINE_DYNAMIC_FUNC0(PM_PRNG_obj,gen,return )

Float PM_PRNG_obj::nextDoubleRange( Float min,Float max){
	HX_STACK_PUSH("PM_PRNG::nextDoubleRange","de/polygonal/math/PM_PRNG.hx",43);
	HX_STACK_THIS(this);
	HX_STACK_ARG(min,"min");
	HX_STACK_ARG(max,"max");
	HX_STACK_LINE(43)
	return (min + (((max - min)) * this->nextDouble()));
}


HX_DEFINE_DYNAMIC_FUNC2(PM_PRNG_obj,nextDoubleRange,return )

int PM_PRNG_obj::nextIntRange( Float min,Float max){
	HX_STACK_PUSH("PM_PRNG::nextIntRange","de/polygonal/math/PM_PRNG.hx",32);
	HX_STACK_THIS(this);
	HX_STACK_ARG(min,"min");
	HX_STACK_ARG(max,"max");
	HX_STACK_LINE(33)
	hx::SubEq(min,.4999);
	HX_STACK_LINE(34)
	hx::AddEq(max,.4999);
	HX_STACK_LINE(35)
	return ::Math_obj::round((min + (((max - min)) * this->nextDouble())));
}


HX_DEFINE_DYNAMIC_FUNC2(PM_PRNG_obj,nextIntRange,return )

Float PM_PRNG_obj::nextDouble( ){
	HX_STACK_PUSH("PM_PRNG::nextDouble","de/polygonal/math/PM_PRNG.hx",22);
	HX_STACK_THIS(this);
	HX_STACK_LINE(22)
	return (Float(this->gen()) / Float((int)2147483647));
}


HX_DEFINE_DYNAMIC_FUNC0(PM_PRNG_obj,nextDouble,return )


PM_PRNG_obj::PM_PRNG_obj()
{
}

void PM_PRNG_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PM_PRNG);
	HX_MARK_MEMBER_NAME(seed,"seed");
	HX_MARK_END_CLASS();
}

void PM_PRNG_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(seed,"seed");
}

Dynamic PM_PRNG_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"gen") ) { return gen_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"seed") ) { return seed; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"nextDouble") ) { return nextDouble_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nextIntRange") ) { return nextIntRange_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nextDoubleRange") ) { return nextDoubleRange_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PM_PRNG_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"seed") ) { seed=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PM_PRNG_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("seed"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("gen"),
	HX_CSTRING("nextDoubleRange"),
	HX_CSTRING("nextIntRange"),
	HX_CSTRING("nextDouble"),
	HX_CSTRING("seed"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PM_PRNG_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PM_PRNG_obj::__mClass,"__mClass");
};

Class PM_PRNG_obj::__mClass;

void PM_PRNG_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("de.polygonal.math.PM_PRNG"), hx::TCanCast< PM_PRNG_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void PM_PRNG_obj::__boot()
{
}

} // end namespace de
} // end namespace polygonal
} // end namespace math

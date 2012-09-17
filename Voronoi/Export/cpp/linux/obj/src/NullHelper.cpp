#include <hxcpp.h>

#ifndef INCLUDED_NullHelper
#include <NullHelper.h>
#endif

Void NullHelper_obj::__construct()
{
	return null();
}

NullHelper_obj::~NullHelper_obj() { }

Dynamic NullHelper_obj::__CreateEmpty() { return  new NullHelper_obj; }
hx::ObjectPtr< NullHelper_obj > NullHelper_obj::__new()
{  hx::ObjectPtr< NullHelper_obj > result = new NullHelper_obj();
	result->__construct();
	return result;}

Dynamic NullHelper_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NullHelper_obj > result = new NullHelper_obj();
	result->__construct();
	return result;}

bool NullHelper_obj::IsNull( Dynamic e){
	HX_STACK_PUSH("NullHelper::IsNull","NullHelper.hx",10);
	HX_STACK_ARG(e,"e");
	HX_STACK_LINE(10)
	return (e != null());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(NullHelper_obj,IsNull,return )

bool NullHelper_obj::IsNotNull( Dynamic e){
	HX_STACK_PUSH("NullHelper::IsNotNull","NullHelper.hx",15);
	HX_STACK_ARG(e,"e");
	HX_STACK_LINE(15)
	return (e == null());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(NullHelper_obj,IsNotNull,return )


NullHelper_obj::NullHelper_obj()
{
}

void NullHelper_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NullHelper);
	HX_MARK_END_CLASS();
}

void NullHelper_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic NullHelper_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"IsNull") ) { return IsNull_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"IsNotNull") ) { return IsNotNull_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NullHelper_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void NullHelper_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("IsNull"),
	HX_CSTRING("IsNotNull"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NullHelper_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NullHelper_obj::__mClass,"__mClass");
};

Class NullHelper_obj::__mClass;

void NullHelper_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("NullHelper"), hx::TCanCast< NullHelper_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NullHelper_obj::__boot()
{
}


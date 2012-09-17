#include <hxcpp.h>

#ifndef INCLUDED_com_nodename_delaunay_LR
#include <com/nodename/delaunay/LR.h>
#endif
namespace com{
namespace nodename{
namespace delaunay{

Void LR_obj::__construct(::String name)
{
HX_STACK_PUSH("LR::new","com/nodename/delaunay/LR.hx",11);
{
	HX_STACK_LINE(11)
	this->_name = name;
}
;
	return null();
}

LR_obj::~LR_obj() { }

Dynamic LR_obj::__CreateEmpty() { return  new LR_obj; }
hx::ObjectPtr< LR_obj > LR_obj::__new(::String name)
{  hx::ObjectPtr< LR_obj > result = new LR_obj();
	result->__construct(name);
	return result;}

Dynamic LR_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LR_obj > result = new LR_obj();
	result->__construct(inArgs[0]);
	return result;}

::String LR_obj::toString( ){
	HX_STACK_PUSH("LR::toString","com/nodename/delaunay/LR.hx",21);
	HX_STACK_THIS(this);
	HX_STACK_LINE(21)
	return this->_name;
}


HX_DEFINE_DYNAMIC_FUNC0(LR_obj,toString,return )

::com::nodename::delaunay::LR LR_obj::LEFT;

::com::nodename::delaunay::LR LR_obj::RIGHT;

::com::nodename::delaunay::LR LR_obj::other( ::com::nodename::delaunay::LR leftRight){
	HX_STACK_PUSH("LR::other","com/nodename/delaunay/LR.hx",16);
	HX_STACK_ARG(leftRight,"leftRight");
	HX_STACK_LINE(16)
	return (  (((leftRight == ::com::nodename::delaunay::LR_obj::LEFT))) ? ::com::nodename::delaunay::LR(::com::nodename::delaunay::LR_obj::RIGHT) : ::com::nodename::delaunay::LR(::com::nodename::delaunay::LR_obj::LEFT) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(LR_obj,other,return )


LR_obj::LR_obj()
{
}

void LR_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LR);
	HX_MARK_MEMBER_NAME(_name,"_name");
	HX_MARK_END_CLASS();
}

void LR_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_name,"_name");
}

Dynamic LR_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"LEFT") ) { return LEFT; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"RIGHT") ) { return RIGHT; }
		if (HX_FIELD_EQ(inName,"other") ) { return other_dyn(); }
		if (HX_FIELD_EQ(inName,"_name") ) { return _name; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic LR_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"LEFT") ) { LEFT=inValue.Cast< ::com::nodename::delaunay::LR >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"RIGHT") ) { RIGHT=inValue.Cast< ::com::nodename::delaunay::LR >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_name") ) { _name=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void LR_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_name"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("LEFT"),
	HX_CSTRING("RIGHT"),
	HX_CSTRING("other"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toString"),
	HX_CSTRING("_name"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LR_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(LR_obj::LEFT,"LEFT");
	HX_MARK_MEMBER_NAME(LR_obj::RIGHT,"RIGHT");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LR_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(LR_obj::LEFT,"LEFT");
	HX_VISIT_MEMBER_NAME(LR_obj::RIGHT,"RIGHT");
};

Class LR_obj::__mClass;

void LR_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.delaunay.LR"), hx::TCanCast< LR_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void LR_obj::__boot()
{
	LEFT= ::com::nodename::delaunay::LR_obj::__new(HX_CSTRING("left"));
	RIGHT= ::com::nodename::delaunay::LR_obj::__new(HX_CSTRING("right"));
}

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

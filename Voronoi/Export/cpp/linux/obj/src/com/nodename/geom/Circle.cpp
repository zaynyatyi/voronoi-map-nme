#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_nodename_geom_Circle
#include <com/nodename/geom/Circle.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
namespace com{
namespace nodename{
namespace geom{

Void Circle_obj::__construct(Float centerX,Float centerY,Float radius)
{
HX_STACK_PUSH("Circle::new","com/nodename/geom/Circle.hx",12);
{
	HX_STACK_LINE(13)
	this->center = ::neash::geom::Point_obj::__new(centerX,centerY);
	HX_STACK_LINE(14)
	this->radius = radius;
}
;
	return null();
}

Circle_obj::~Circle_obj() { }

Dynamic Circle_obj::__CreateEmpty() { return  new Circle_obj; }
hx::ObjectPtr< Circle_obj > Circle_obj::__new(Float centerX,Float centerY,Float radius)
{  hx::ObjectPtr< Circle_obj > result = new Circle_obj();
	result->__construct(centerX,centerY,radius);
	return result;}

Dynamic Circle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Circle_obj > result = new Circle_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::String Circle_obj::toString( ){
	HX_STACK_PUSH("Circle::toString","com/nodename/geom/Circle.hx",18);
	HX_STACK_THIS(this);
	HX_STACK_LINE(18)
	return ((((HX_CSTRING("Circle (center: ") + ::Std_obj::string(this->center)) + HX_CSTRING("; radius: ")) + this->radius) + HX_CSTRING(")"));
}


HX_DEFINE_DYNAMIC_FUNC0(Circle_obj,toString,return )


Circle_obj::Circle_obj()
{
}

void Circle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Circle);
	HX_MARK_MEMBER_NAME(radius,"radius");
	HX_MARK_MEMBER_NAME(center,"center");
	HX_MARK_END_CLASS();
}

void Circle_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(radius,"radius");
	HX_VISIT_MEMBER_NAME(center,"center");
}

Dynamic Circle_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"radius") ) { return radius; }
		if (HX_FIELD_EQ(inName,"center") ) { return center; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Circle_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"radius") ) { radius=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"center") ) { center=inValue.Cast< ::neash::geom::Point >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Circle_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("radius"));
	outFields->push(HX_CSTRING("center"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toString"),
	HX_CSTRING("radius"),
	HX_CSTRING("center"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Circle_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Circle_obj::__mClass,"__mClass");
};

Class Circle_obj::__mClass;

void Circle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.geom.Circle"), hx::TCanCast< Circle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Circle_obj::__boot()
{
}

} // end namespace com
} // end namespace nodename
} // end namespace geom

#include <hxcpp.h>

#ifndef INCLUDED_com_nodename_geom_LineSegment
#include <com/nodename/geom/LineSegment.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
namespace com{
namespace nodename{
namespace geom{

Void LineSegment_obj::__construct(::neash::geom::Point p0,::neash::geom::Point p1)
{
HX_STACK_PUSH("LineSegment::new","com/nodename/geom/LineSegment.hx",33);
{
	HX_STACK_LINE(34)
	this->p0 = p0;
	HX_STACK_LINE(35)
	this->p1 = p1;
}
;
	return null();
}

LineSegment_obj::~LineSegment_obj() { }

Dynamic LineSegment_obj::__CreateEmpty() { return  new LineSegment_obj; }
hx::ObjectPtr< LineSegment_obj > LineSegment_obj::__new(::neash::geom::Point p0,::neash::geom::Point p1)
{  hx::ObjectPtr< LineSegment_obj > result = new LineSegment_obj();
	result->__construct(p0,p1);
	return result;}

Dynamic LineSegment_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LineSegment_obj > result = new LineSegment_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

int LineSegment_obj::compareLengths_MAX( ::com::nodename::geom::LineSegment segment0,::com::nodename::geom::LineSegment segment1){
	HX_STACK_PUSH("LineSegment::compareLengths_MAX","com/nodename/geom/LineSegment.hx",10);
	HX_STACK_ARG(segment0,"segment0");
	HX_STACK_ARG(segment1,"segment1");
	HX_STACK_LINE(11)
	Float length0 = ::neash::geom::Point_obj::distance(segment0->p0,segment0->p1);		HX_STACK_VAR(length0,"length0");
	HX_STACK_LINE(12)
	Float length1 = ::neash::geom::Point_obj::distance(segment1->p0,segment1->p1);		HX_STACK_VAR(length1,"length1");
	HX_STACK_LINE(13)
	if (((length0 < length1))){
		HX_STACK_LINE(14)
		return (int)1;
	}
	HX_STACK_LINE(17)
	if (((length0 > length1))){
		HX_STACK_LINE(18)
		return (int)-1;
	}
	HX_STACK_LINE(21)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(LineSegment_obj,compareLengths_MAX,return )

int LineSegment_obj::compareLengths( ::com::nodename::geom::LineSegment edge0,::com::nodename::geom::LineSegment edge1){
	HX_STACK_PUSH("LineSegment::compareLengths","com/nodename/geom/LineSegment.hx",25);
	HX_STACK_ARG(edge0,"edge0");
	HX_STACK_ARG(edge1,"edge1");
	HX_STACK_LINE(25)
	return -(::com::nodename::geom::LineSegment_obj::compareLengths_MAX(edge0,edge1));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(LineSegment_obj,compareLengths,return )


LineSegment_obj::LineSegment_obj()
{
}

void LineSegment_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LineSegment);
	HX_MARK_MEMBER_NAME(p1,"p1");
	HX_MARK_MEMBER_NAME(p0,"p0");
	HX_MARK_END_CLASS();
}

void LineSegment_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(p1,"p1");
	HX_VISIT_MEMBER_NAME(p0,"p0");
}

Dynamic LineSegment_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"p1") ) { return p1; }
		if (HX_FIELD_EQ(inName,"p0") ) { return p0; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"compareLengths") ) { return compareLengths_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"compareLengths_MAX") ) { return compareLengths_MAX_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic LineSegment_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"p1") ) { p1=inValue.Cast< ::neash::geom::Point >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p0") ) { p0=inValue.Cast< ::neash::geom::Point >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void LineSegment_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("p1"));
	outFields->push(HX_CSTRING("p0"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("compareLengths_MAX"),
	HX_CSTRING("compareLengths"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("p1"),
	HX_CSTRING("p0"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LineSegment_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LineSegment_obj::__mClass,"__mClass");
};

Class LineSegment_obj::__mClass;

void LineSegment_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.geom.LineSegment"), hx::TCanCast< LineSegment_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void LineSegment_obj::__boot()
{
}

} // end namespace com
} // end namespace nodename
} // end namespace geom

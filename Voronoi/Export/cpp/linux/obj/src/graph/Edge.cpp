#include <hxcpp.h>

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
namespace graph{

Void Edge_obj::__construct()
{
HX_STACK_PUSH("Edge::new","graph/Edge.hx",12);
{
}
;
	return null();
}

Edge_obj::~Edge_obj() { }

Dynamic Edge_obj::__CreateEmpty() { return  new Edge_obj; }
hx::ObjectPtr< Edge_obj > Edge_obj::__new()
{  hx::ObjectPtr< Edge_obj > result = new Edge_obj();
	result->__construct();
	return result;}

Dynamic Edge_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Edge_obj > result = new Edge_obj();
	result->__construct();
	return result;}


Edge_obj::Edge_obj()
{
}

void Edge_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Edge);
	HX_MARK_MEMBER_NAME(river,"river");
	HX_MARK_MEMBER_NAME(midpoint,"midpoint");
	HX_MARK_MEMBER_NAME(v1,"v1");
	HX_MARK_MEMBER_NAME(v0,"v0");
	HX_MARK_MEMBER_NAME(d1,"d1");
	HX_MARK_MEMBER_NAME(d0,"d0");
	HX_MARK_MEMBER_NAME(index,"index");
	HX_MARK_END_CLASS();
}

void Edge_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(river,"river");
	HX_VISIT_MEMBER_NAME(midpoint,"midpoint");
	HX_VISIT_MEMBER_NAME(v1,"v1");
	HX_VISIT_MEMBER_NAME(v0,"v0");
	HX_VISIT_MEMBER_NAME(d1,"d1");
	HX_VISIT_MEMBER_NAME(d0,"d0");
	HX_VISIT_MEMBER_NAME(index,"index");
}

Dynamic Edge_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"v1") ) { return v1; }
		if (HX_FIELD_EQ(inName,"v0") ) { return v0; }
		if (HX_FIELD_EQ(inName,"d1") ) { return d1; }
		if (HX_FIELD_EQ(inName,"d0") ) { return d0; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"river") ) { return river; }
		if (HX_FIELD_EQ(inName,"index") ) { return index; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"midpoint") ) { return midpoint; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Edge_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"v1") ) { v1=inValue.Cast< ::graph::Corner >(); return inValue; }
		if (HX_FIELD_EQ(inName,"v0") ) { v0=inValue.Cast< ::graph::Corner >(); return inValue; }
		if (HX_FIELD_EQ(inName,"d1") ) { d1=inValue.Cast< ::graph::Center >(); return inValue; }
		if (HX_FIELD_EQ(inName,"d0") ) { d0=inValue.Cast< ::graph::Center >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"river") ) { river=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"index") ) { index=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"midpoint") ) { midpoint=inValue.Cast< ::neash::geom::Point >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Edge_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("river"));
	outFields->push(HX_CSTRING("midpoint"));
	outFields->push(HX_CSTRING("v1"));
	outFields->push(HX_CSTRING("v0"));
	outFields->push(HX_CSTRING("d1"));
	outFields->push(HX_CSTRING("d0"));
	outFields->push(HX_CSTRING("index"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("river"),
	HX_CSTRING("midpoint"),
	HX_CSTRING("v1"),
	HX_CSTRING("v0"),
	HX_CSTRING("d1"),
	HX_CSTRING("d0"),
	HX_CSTRING("index"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Edge_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Edge_obj::__mClass,"__mClass");
};

Class Edge_obj::__mClass;

void Edge_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("graph.Edge"), hx::TCanCast< Edge_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Edge_obj::__boot()
{
}

} // end namespace graph

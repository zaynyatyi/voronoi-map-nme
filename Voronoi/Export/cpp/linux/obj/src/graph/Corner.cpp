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

Void Corner_obj::__construct()
{
HX_STACK_PUSH("Corner::new","graph/Corner.hx",24);
{
}
;
	return null();
}

Corner_obj::~Corner_obj() { }

Dynamic Corner_obj::__CreateEmpty() { return  new Corner_obj; }
hx::ObjectPtr< Corner_obj > Corner_obj::__new()
{  hx::ObjectPtr< Corner_obj > result = new Corner_obj();
	result->__construct();
	return result;}

Dynamic Corner_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Corner_obj > result = new Corner_obj();
	result->__construct();
	return result;}


Corner_obj::Corner_obj()
{
}

void Corner_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Corner);
	HX_MARK_MEMBER_NAME(watershed_size,"watershed_size");
	HX_MARK_MEMBER_NAME(watershed,"watershed");
	HX_MARK_MEMBER_NAME(downslope,"downslope");
	HX_MARK_MEMBER_NAME(river,"river");
	HX_MARK_MEMBER_NAME(adjacent,"adjacent");
	HX_MARK_MEMBER_NAME(protrudes,"protrudes");
	HX_MARK_MEMBER_NAME(touches,"touches");
	HX_MARK_MEMBER_NAME(moisture,"moisture");
	HX_MARK_MEMBER_NAME(elevation,"elevation");
	HX_MARK_MEMBER_NAME(border,"border");
	HX_MARK_MEMBER_NAME(coast,"coast");
	HX_MARK_MEMBER_NAME(water,"water");
	HX_MARK_MEMBER_NAME(ocean,"ocean");
	HX_MARK_MEMBER_NAME(point,"point");
	HX_MARK_MEMBER_NAME(index,"index");
	HX_MARK_END_CLASS();
}

void Corner_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(watershed_size,"watershed_size");
	HX_VISIT_MEMBER_NAME(watershed,"watershed");
	HX_VISIT_MEMBER_NAME(downslope,"downslope");
	HX_VISIT_MEMBER_NAME(river,"river");
	HX_VISIT_MEMBER_NAME(adjacent,"adjacent");
	HX_VISIT_MEMBER_NAME(protrudes,"protrudes");
	HX_VISIT_MEMBER_NAME(touches,"touches");
	HX_VISIT_MEMBER_NAME(moisture,"moisture");
	HX_VISIT_MEMBER_NAME(elevation,"elevation");
	HX_VISIT_MEMBER_NAME(border,"border");
	HX_VISIT_MEMBER_NAME(coast,"coast");
	HX_VISIT_MEMBER_NAME(water,"water");
	HX_VISIT_MEMBER_NAME(ocean,"ocean");
	HX_VISIT_MEMBER_NAME(point,"point");
	HX_VISIT_MEMBER_NAME(index,"index");
}

Dynamic Corner_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"river") ) { return river; }
		if (HX_FIELD_EQ(inName,"coast") ) { return coast; }
		if (HX_FIELD_EQ(inName,"water") ) { return water; }
		if (HX_FIELD_EQ(inName,"ocean") ) { return ocean; }
		if (HX_FIELD_EQ(inName,"point") ) { return point; }
		if (HX_FIELD_EQ(inName,"index") ) { return index; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"border") ) { return border; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"touches") ) { return touches; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"adjacent") ) { return adjacent; }
		if (HX_FIELD_EQ(inName,"moisture") ) { return moisture; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"watershed") ) { return watershed; }
		if (HX_FIELD_EQ(inName,"downslope") ) { return downslope; }
		if (HX_FIELD_EQ(inName,"protrudes") ) { return protrudes; }
		if (HX_FIELD_EQ(inName,"elevation") ) { return elevation; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"watershed_size") ) { return watershed_size; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Corner_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"river") ) { river=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"coast") ) { coast=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"water") ) { water=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ocean") ) { ocean=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"point") ) { point=inValue.Cast< ::neash::geom::Point >(); return inValue; }
		if (HX_FIELD_EQ(inName,"index") ) { index=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"border") ) { border=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"touches") ) { touches=inValue.Cast< Array< ::graph::Center > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"adjacent") ) { adjacent=inValue.Cast< Array< ::graph::Corner > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"moisture") ) { moisture=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"watershed") ) { watershed=inValue.Cast< ::graph::Corner >(); return inValue; }
		if (HX_FIELD_EQ(inName,"downslope") ) { downslope=inValue.Cast< ::graph::Corner >(); return inValue; }
		if (HX_FIELD_EQ(inName,"protrudes") ) { protrudes=inValue.Cast< Array< ::graph::Edge > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"elevation") ) { elevation=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"watershed_size") ) { watershed_size=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Corner_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("watershed_size"));
	outFields->push(HX_CSTRING("watershed"));
	outFields->push(HX_CSTRING("downslope"));
	outFields->push(HX_CSTRING("river"));
	outFields->push(HX_CSTRING("adjacent"));
	outFields->push(HX_CSTRING("protrudes"));
	outFields->push(HX_CSTRING("touches"));
	outFields->push(HX_CSTRING("moisture"));
	outFields->push(HX_CSTRING("elevation"));
	outFields->push(HX_CSTRING("border"));
	outFields->push(HX_CSTRING("coast"));
	outFields->push(HX_CSTRING("water"));
	outFields->push(HX_CSTRING("ocean"));
	outFields->push(HX_CSTRING("point"));
	outFields->push(HX_CSTRING("index"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("watershed_size"),
	HX_CSTRING("watershed"),
	HX_CSTRING("downslope"),
	HX_CSTRING("river"),
	HX_CSTRING("adjacent"),
	HX_CSTRING("protrudes"),
	HX_CSTRING("touches"),
	HX_CSTRING("moisture"),
	HX_CSTRING("elevation"),
	HX_CSTRING("border"),
	HX_CSTRING("coast"),
	HX_CSTRING("water"),
	HX_CSTRING("ocean"),
	HX_CSTRING("point"),
	HX_CSTRING("index"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Corner_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Corner_obj::__mClass,"__mClass");
};

Class Corner_obj::__mClass;

void Corner_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("graph.Corner"), hx::TCanCast< Corner_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Corner_obj::__boot()
{
}

} // end namespace graph

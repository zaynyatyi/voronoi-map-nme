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

Void Center_obj::__construct()
{
HX_STACK_PUSH("Center::new","graph/Center.hx",20);
{
}
;
	return null();
}

Center_obj::~Center_obj() { }

Dynamic Center_obj::__CreateEmpty() { return  new Center_obj; }
hx::ObjectPtr< Center_obj > Center_obj::__new()
{  hx::ObjectPtr< Center_obj > result = new Center_obj();
	result->__construct();
	return result;}

Dynamic Center_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Center_obj > result = new Center_obj();
	result->__construct();
	return result;}


Center_obj::Center_obj()
{
}

void Center_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Center);
	HX_MARK_MEMBER_NAME(corners,"corners");
	HX_MARK_MEMBER_NAME(borders,"borders");
	HX_MARK_MEMBER_NAME(neighbors,"neighbors");
	HX_MARK_MEMBER_NAME(moisture,"moisture");
	HX_MARK_MEMBER_NAME(elevation,"elevation");
	HX_MARK_MEMBER_NAME(biome,"biome");
	HX_MARK_MEMBER_NAME(border,"border");
	HX_MARK_MEMBER_NAME(coast,"coast");
	HX_MARK_MEMBER_NAME(ocean,"ocean");
	HX_MARK_MEMBER_NAME(water,"water");
	HX_MARK_MEMBER_NAME(point,"point");
	HX_MARK_MEMBER_NAME(index,"index");
	HX_MARK_END_CLASS();
}

void Center_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(corners,"corners");
	HX_VISIT_MEMBER_NAME(borders,"borders");
	HX_VISIT_MEMBER_NAME(neighbors,"neighbors");
	HX_VISIT_MEMBER_NAME(moisture,"moisture");
	HX_VISIT_MEMBER_NAME(elevation,"elevation");
	HX_VISIT_MEMBER_NAME(biome,"biome");
	HX_VISIT_MEMBER_NAME(border,"border");
	HX_VISIT_MEMBER_NAME(coast,"coast");
	HX_VISIT_MEMBER_NAME(ocean,"ocean");
	HX_VISIT_MEMBER_NAME(water,"water");
	HX_VISIT_MEMBER_NAME(point,"point");
	HX_VISIT_MEMBER_NAME(index,"index");
}

Dynamic Center_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"biome") ) { return biome; }
		if (HX_FIELD_EQ(inName,"coast") ) { return coast; }
		if (HX_FIELD_EQ(inName,"ocean") ) { return ocean; }
		if (HX_FIELD_EQ(inName,"water") ) { return water; }
		if (HX_FIELD_EQ(inName,"point") ) { return point; }
		if (HX_FIELD_EQ(inName,"index") ) { return index; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"border") ) { return border; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"corners") ) { return corners; }
		if (HX_FIELD_EQ(inName,"borders") ) { return borders; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"moisture") ) { return moisture; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"neighbors") ) { return neighbors; }
		if (HX_FIELD_EQ(inName,"elevation") ) { return elevation; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Center_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"biome") ) { biome=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"coast") ) { coast=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ocean") ) { ocean=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"water") ) { water=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"point") ) { point=inValue.Cast< ::neash::geom::Point >(); return inValue; }
		if (HX_FIELD_EQ(inName,"index") ) { index=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"border") ) { border=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"corners") ) { corners=inValue.Cast< Array< ::graph::Corner > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borders") ) { borders=inValue.Cast< Array< ::graph::Edge > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"moisture") ) { moisture=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"neighbors") ) { neighbors=inValue.Cast< Array< ::graph::Center > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"elevation") ) { elevation=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Center_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("corners"));
	outFields->push(HX_CSTRING("borders"));
	outFields->push(HX_CSTRING("neighbors"));
	outFields->push(HX_CSTRING("moisture"));
	outFields->push(HX_CSTRING("elevation"));
	outFields->push(HX_CSTRING("biome"));
	outFields->push(HX_CSTRING("border"));
	outFields->push(HX_CSTRING("coast"));
	outFields->push(HX_CSTRING("ocean"));
	outFields->push(HX_CSTRING("water"));
	outFields->push(HX_CSTRING("point"));
	outFields->push(HX_CSTRING("index"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("corners"),
	HX_CSTRING("borders"),
	HX_CSTRING("neighbors"),
	HX_CSTRING("moisture"),
	HX_CSTRING("elevation"),
	HX_CSTRING("biome"),
	HX_CSTRING("border"),
	HX_CSTRING("coast"),
	HX_CSTRING("ocean"),
	HX_CSTRING("water"),
	HX_CSTRING("point"),
	HX_CSTRING("index"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Center_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Center_obj::__mClass,"__mClass");
};

Class Center_obj::__mClass;

void Center_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("graph.Center"), hx::TCanCast< Center_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Center_obj::__boot()
{
}

} // end namespace graph

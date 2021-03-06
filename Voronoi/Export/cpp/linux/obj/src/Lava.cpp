#include <hxcpp.h>

#ifndef INCLUDED_Lava
#include <Lava.h>
#endif
#ifndef INCLUDED_Map
#include <Map.h>
#endif
#ifndef INCLUDED_graph_Center
#include <graph/Center.h>
#endif
#ifndef INCLUDED_graph_Edge
#include <graph/Edge.h>
#endif

Void Lava_obj::__construct()
{
HX_STACK_PUSH("Lava::new","Lava.hx",18);
{
	HX_STACK_LINE(18)
	this->lava = Dynamic( Array_obj<Dynamic>::__new());
}
;
	return null();
}

Lava_obj::~Lava_obj() { }

Dynamic Lava_obj::__CreateEmpty() { return  new Lava_obj; }
hx::ObjectPtr< Lava_obj > Lava_obj::__new()
{  hx::ObjectPtr< Lava_obj > result = new Lava_obj();
	result->__construct();
	return result;}

Dynamic Lava_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Lava_obj > result = new Lava_obj();
	result->__construct();
	return result;}

Void Lava_obj::createLava( ::Map map,Dynamic randomDouble){
{
		HX_STACK_PUSH("Lava::createLava","Lava.hx",23);
		HX_STACK_THIS(this);
		HX_STACK_ARG(map,"map");
		HX_STACK_ARG(randomDouble,"randomDouble");
		HX_STACK_LINE(24)
		::graph::Edge edge;		HX_STACK_VAR(edge,"edge");
		HX_STACK_LINE(25)
		{
			HX_STACK_LINE(25)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Edge > _g1 = map->edges;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(25)
			while(((_g < _g1->length))){
				HX_STACK_LINE(25)
				::graph::Edge edge1 = _g1->__get(_g);		HX_STACK_VAR(edge1,"edge1");
				HX_STACK_LINE(25)
				++(_g);
				HX_STACK_LINE(26)
				if (((bool((bool((bool((bool((bool((bool((bool((edge1->river == (int)0)) && bool(!(edge1->d0->water)))) && bool(!(edge1->d1->water)))) && bool((edge1->d0->elevation > 0.8)))) && bool((edge1->d1->elevation > 0.8)))) && bool((edge1->d0->moisture < 0.3)))) && bool((edge1->d1->moisture < 0.3)))) && bool((randomDouble().Cast< Float >() < ::Lava_obj::FRACTION_LAVA_FISSURES))))){
					HX_STACK_LINE(31)
					hx::IndexRef((this->lava).mPtr,edge1->index) = true;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Lava_obj,createLava,(void))

Float Lava_obj::FRACTION_LAVA_FISSURES;


Lava_obj::Lava_obj()
{
}

void Lava_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Lava);
	HX_MARK_MEMBER_NAME(lava,"lava");
	HX_MARK_END_CLASS();
}

void Lava_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(lava,"lava");
}

Dynamic Lava_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"lava") ) { return lava; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"createLava") ) { return createLava_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"FRACTION_LAVA_FISSURES") ) { return FRACTION_LAVA_FISSURES; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Lava_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"lava") ) { lava=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"FRACTION_LAVA_FISSURES") ) { FRACTION_LAVA_FISSURES=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Lava_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("lava"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("FRACTION_LAVA_FISSURES"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("createLava"),
	HX_CSTRING("lava"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Lava_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Lava_obj::FRACTION_LAVA_FISSURES,"FRACTION_LAVA_FISSURES");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Lava_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Lava_obj::FRACTION_LAVA_FISSURES,"FRACTION_LAVA_FISSURES");
};

Class Lava_obj::__mClass;

void Lava_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Lava"), hx::TCanCast< Lava_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Lava_obj::__boot()
{
	FRACTION_LAVA_FISSURES= 0.2;
}


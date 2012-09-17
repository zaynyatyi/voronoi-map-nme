#include <hxcpp.h>

#ifndef INCLUDED_Map
#include <Map.h>
#endif
#ifndef INCLUDED_Watersheds
#include <Watersheds.h>
#endif
#ifndef INCLUDED_graph_Center
#include <graph/Center.h>
#endif
#ifndef INCLUDED_graph_Corner
#include <graph/Corner.h>
#endif

Void Watersheds_obj::__construct()
{
HX_STACK_PUSH("Watersheds::new","Watersheds.hx",17);
{
	HX_STACK_LINE(18)
	this->lowestCorner = Dynamic( Array_obj<Dynamic>::__new());
	HX_STACK_LINE(19)
	this->watersheds = Dynamic( Array_obj<Dynamic>::__new());
}
;
	return null();
}

Watersheds_obj::~Watersheds_obj() { }

Dynamic Watersheds_obj::__CreateEmpty() { return  new Watersheds_obj; }
hx::ObjectPtr< Watersheds_obj > Watersheds_obj::__new()
{  hx::ObjectPtr< Watersheds_obj > result = new Watersheds_obj();
	result->__construct();
	return result;}

Dynamic Watersheds_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Watersheds_obj > result = new Watersheds_obj();
	result->__construct();
	return result;}

Void Watersheds_obj::createWatersheds( ::Map map){
{
		HX_STACK_PUSH("Watersheds::createWatersheds","Watersheds.hx",24);
		HX_STACK_THIS(this);
		HX_STACK_ARG(map,"map");
		HX_STACK_LINE(25)
		::graph::Center p;		HX_STACK_VAR(p,"p");
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		::graph::Corner s;		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(29)
		{
			HX_STACK_LINE(29)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Center > _g1 = map->centers;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(29)
			while(((_g < _g1->length))){
				HX_STACK_LINE(29)
				::graph::Center p1 = _g1->__get(_g);		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(29)
				++(_g);
				HX_STACK_LINE(30)
				s = null();
				HX_STACK_LINE(31)
				{
					HX_STACK_LINE(31)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Corner > _g3 = p1->corners;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(31)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(31)
						::graph::Corner q1 = _g3->__get(_g2);		HX_STACK_VAR(q1,"q1");
						HX_STACK_LINE(31)
						++(_g2);
						HX_STACK_LINE(32)
						if (((bool((s == null())) || bool((q1->elevation < s->elevation))))){
							HX_STACK_LINE(32)
							s = q1;
						}
					}
				}
				HX_STACK_LINE(36)
				hx::IndexRef((this->lowestCorner).mPtr,p1->index) = (  (((s == null()))) ? int((int)-1) : int(s->index) );
				HX_STACK_LINE(37)
				hx::IndexRef((this->watersheds).mPtr,p1->index) = (  (((s == null()))) ? int((int)-1) : int((  (((s->watershed == null()))) ? int((int)-1) : int(s->watershed->index) )) );
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Watersheds_obj,createWatersheds,(void))


Watersheds_obj::Watersheds_obj()
{
}

void Watersheds_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Watersheds);
	HX_MARK_MEMBER_NAME(watersheds,"watersheds");
	HX_MARK_MEMBER_NAME(lowestCorner,"lowestCorner");
	HX_MARK_END_CLASS();
}

void Watersheds_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(watersheds,"watersheds");
	HX_VISIT_MEMBER_NAME(lowestCorner,"lowestCorner");
}

Dynamic Watersheds_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"watersheds") ) { return watersheds; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"lowestCorner") ) { return lowestCorner; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"createWatersheds") ) { return createWatersheds_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Watersheds_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"watersheds") ) { watersheds=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"lowestCorner") ) { lowestCorner=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Watersheds_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("watersheds"));
	outFields->push(HX_CSTRING("lowestCorner"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("createWatersheds"),
	HX_CSTRING("watersheds"),
	HX_CSTRING("lowestCorner"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Watersheds_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Watersheds_obj::__mClass,"__mClass");
};

Class Watersheds_obj::__mClass;

void Watersheds_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Watersheds"), hx::TCanCast< Watersheds_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Watersheds_obj::__boot()
{
}


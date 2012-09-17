#include <hxcpp.h>

#ifndef INCLUDED_Map
#include <Map.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Roads
#include <Roads.h>
#endif
#ifndef INCLUDED_graph_Center
#include <graph/Center.h>
#endif
#ifndef INCLUDED_graph_Corner
#include <graph/Corner.h>
#endif
#ifndef INCLUDED_graph_Edge
#include <graph/Edge.h>
#endif

Void Roads_obj::__construct()
{
HX_STACK_PUSH("Roads::new","Roads.hx",19);
{
	HX_STACK_LINE(20)
	this->road = Dynamic( Array_obj<Dynamic>::__new());
	HX_STACK_LINE(21)
	this->roadConnections = Dynamic( Array_obj<Dynamic>::__new());
}
;
	return null();
}

Roads_obj::~Roads_obj() { }

Dynamic Roads_obj::__CreateEmpty() { return  new Roads_obj; }
hx::ObjectPtr< Roads_obj > Roads_obj::__new()
{  hx::ObjectPtr< Roads_obj > result = new Roads_obj();
	result->__construct();
	return result;}

Dynamic Roads_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Roads_obj > result = new Roads_obj();
	result->__construct();
	return result;}

Void Roads_obj::createRoads( ::Map map){
{
		HX_STACK_PUSH("Roads::createRoads","Roads.hx",27);
		HX_STACK_THIS(this);
		HX_STACK_ARG(map,"map");
		HX_STACK_LINE(33)
		Dynamic queue = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(queue,"queue");
		HX_STACK_LINE(34)
		::graph::Center p;		HX_STACK_VAR(p,"p");
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		::graph::Center r;		HX_STACK_VAR(r,"r");
		::graph::Edge edge;		HX_STACK_VAR(edge,"edge");
		int newLevel;		HX_STACK_VAR(newLevel,"newLevel");
		HX_STACK_LINE(35)
		Dynamic elevationThresholds = Dynamic( Array_obj<Dynamic>::__new().Add((int)0).Add(0.05).Add(0.37).Add(0.64));		HX_STACK_VAR(elevationThresholds,"elevationThresholds");
		HX_STACK_LINE(36)
		Dynamic cornerContour = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(cornerContour,"cornerContour");
		HX_STACK_LINE(37)
		Dynamic centerContour = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(centerContour,"centerContour");
		HX_STACK_LINE(39)
		{
			HX_STACK_LINE(39)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Center > _g1 = map->centers;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(39)
			while(((_g < _g1->length))){
				HX_STACK_LINE(39)
				::graph::Center p1 = _g1->__get(_g);		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(39)
				++(_g);
				HX_STACK_LINE(40)
				if (((bool(p1->coast) || bool(p1->ocean)))){
					HX_STACK_LINE(41)
					hx::IndexRef((centerContour).mPtr,p1->index) = (int)1;
					HX_STACK_LINE(42)
					queue->__Field(HX_CSTRING("push"),true)(p1);
				}
			}
		}
		HX_STACK_LINE(46)
		while(((queue->__Field(HX_CSTRING("length"),true) > (int)0))){
			HX_STACK_LINE(47)
			p = queue->__Field(HX_CSTRING("shift"),true)();
			HX_STACK_LINE(48)
			{
				HX_STACK_LINE(48)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::graph::Center > _g1 = p->neighbors;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(48)
				while(((_g < _g1->length))){
					HX_STACK_LINE(48)
					::graph::Center r1 = _g1->__get(_g);		HX_STACK_VAR(r1,"r1");
					HX_STACK_LINE(48)
					++(_g);
					HX_STACK_LINE(49)
					newLevel = (  (((centerContour->__GetItem(p->index) == null()))) ? int((int)0) : int(centerContour->__GetItem(p->index)) );
					HX_STACK_LINE(50)
					while(((bool((r1->elevation > elevationThresholds->__GetItem(newLevel))) && bool(!(r1->water))))){
						HX_STACK_LINE(50)
						hx::AddEq(newLevel,(int)1);
					}
					HX_STACK_LINE(55)
					if (((newLevel < ((  (((centerContour->__GetItem(r1->index) == null()))) ? int((int)999) : int(centerContour->__GetItem(r1->index)) ))))){
						HX_STACK_LINE(56)
						hx::IndexRef((centerContour).mPtr,r1->index) = newLevel;
						HX_STACK_LINE(57)
						queue->__Field(HX_CSTRING("push"),true)(r1);
					}
				}
			}
		}
		HX_STACK_LINE(63)
		{
			HX_STACK_LINE(63)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Center > _g1 = map->centers;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(63)
			while(((_g < _g1->length))){
				HX_STACK_LINE(63)
				::graph::Center p1 = _g1->__get(_g);		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(63)
				++(_g);
				HX_STACK_LINE(64)
				{
					HX_STACK_LINE(64)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Corner > _g3 = p1->corners;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(64)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(64)
						::graph::Corner q1 = _g3->__get(_g2);		HX_STACK_VAR(q1,"q1");
						HX_STACK_LINE(64)
						++(_g2);
						HX_STACK_LINE(65)
						hx::IndexRef((cornerContour).mPtr,q1->index) = ::Math_obj::min((  (((centerContour->__GetItem(q1->index) == null()))) ? int((int)999) : int(centerContour->__GetItem(q1->index)) ),(  (((centerContour->__GetItem(p1->index) == null()))) ? int((int)999) : int(centerContour->__GetItem(p1->index)) ));
					}
				}
			}
		}
		HX_STACK_LINE(71)
		{
			HX_STACK_LINE(71)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Center > _g1 = map->centers;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(71)
			while(((_g < _g1->length))){
				HX_STACK_LINE(71)
				::graph::Center p1 = _g1->__get(_g);		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(71)
				++(_g);
				HX_STACK_LINE(72)
				{
					HX_STACK_LINE(72)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Edge > _g3 = p1->borders;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(72)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(72)
						::graph::Edge edge1 = _g3->__get(_g2);		HX_STACK_VAR(edge1,"edge1");
						HX_STACK_LINE(72)
						++(_g2);
						HX_STACK_LINE(73)
						if (((bool((bool((edge1->v0 != null())) && bool((edge1->v1 != null())))) && bool((cornerContour->__GetItem(edge1->v0->index) != cornerContour->__GetItem(edge1->v1->index)))))){
							HX_STACK_LINE(75)
							hx::IndexRef((this->road).mPtr,edge1->index) = ::Math_obj::min(cornerContour->__GetItem(edge1->v0->index),cornerContour->__GetItem(edge1->v1->index));
							HX_STACK_LINE(77)
							if ((!(this->roadConnections->__GetItem(p1->index)))){
								HX_STACK_LINE(77)
								hx::IndexRef((this->roadConnections).mPtr,p1->index) = Dynamic( Array_obj<Dynamic>::__new());
							}
							HX_STACK_LINE(80)
							this->roadConnections->__GetItem(p1->index)->__Field(HX_CSTRING("push"),true)(edge1);
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Roads_obj,createRoads,(void))


Roads_obj::Roads_obj()
{
}

void Roads_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Roads);
	HX_MARK_MEMBER_NAME(roadConnections,"roadConnections");
	HX_MARK_MEMBER_NAME(road,"road");
	HX_MARK_END_CLASS();
}

void Roads_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(roadConnections,"roadConnections");
	HX_VISIT_MEMBER_NAME(road,"road");
}

Dynamic Roads_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"road") ) { return road; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"createRoads") ) { return createRoads_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"roadConnections") ) { return roadConnections; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Roads_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"road") ) { road=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"roadConnections") ) { roadConnections=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Roads_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("roadConnections"));
	outFields->push(HX_CSTRING("road"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("createRoads"),
	HX_CSTRING("roadConnections"),
	HX_CSTRING("road"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Roads_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Roads_obj::__mClass,"__mClass");
};

Class Roads_obj::__mClass;

void Roads_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Roads"), hx::TCanCast< Roads_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Roads_obj::__boot()
{
}


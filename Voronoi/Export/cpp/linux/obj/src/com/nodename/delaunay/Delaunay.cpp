#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Delaunay
#include <com/nodename/delaunay/Delaunay.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Edge
#include <com/nodename/delaunay/Edge.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_ICoord
#include <com/nodename/delaunay/ICoord.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_LR
#include <com/nodename/delaunay/LR.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Site
#include <com/nodename/delaunay/Site.h>
#endif
#ifndef INCLUDED_com_nodename_geom_LineSegment
#include <com/nodename/geom/LineSegment.h>
#endif
#ifndef INCLUDED_neash_display_BitmapData
#include <neash/display/BitmapData.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
namespace com{
namespace nodename{
namespace delaunay{

Void Delaunay_obj::__construct()
{
	return null();
}

Delaunay_obj::~Delaunay_obj() { }

Dynamic Delaunay_obj::__CreateEmpty() { return  new Delaunay_obj; }
hx::ObjectPtr< Delaunay_obj > Delaunay_obj::__new()
{  hx::ObjectPtr< Delaunay_obj > result = new Delaunay_obj();
	result->__construct();
	return result;}

Dynamic Delaunay_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Delaunay_obj > result = new Delaunay_obj();
	result->__construct();
	return result;}

Array< ::com::nodename::geom::LineSegment > Delaunay_obj::delaunayLinesForEdges( Array< ::com::nodename::delaunay::Edge > edges){
	HX_STACK_PUSH("Delaunay::delaunayLinesForEdges","com/nodename/delaunay/Delaunay.hx",14);
	HX_STACK_ARG(edges,"edges");
	HX_STACK_LINE(15)
	Array< ::com::nodename::geom::LineSegment > segments = Array_obj< ::com::nodename::geom::LineSegment >::__new();		HX_STACK_VAR(segments,"segments");
	HX_STACK_LINE(16)
	{
		HX_STACK_LINE(16)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(16)
		while(((_g < edges->length))){
			HX_STACK_LINE(16)
			::com::nodename::delaunay::Edge edge = edges->__get(_g);		HX_STACK_VAR(edge,"edge");
			HX_STACK_LINE(16)
			++(_g);
			HX_STACK_LINE(18)
			segments->push(edge->delaunayLine());
		}
	}
	HX_STACK_LINE(20)
	return segments;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Delaunay_obj,delaunayLinesForEdges,return )

Array< ::com::nodename::delaunay::Edge > Delaunay_obj::selectEdgesForSitePoint( ::neash::geom::Point coord,Array< ::com::nodename::delaunay::Edge > edgesToTest){
	HX_STACK_PUSH("Delaunay::selectEdgesForSitePoint","com/nodename/delaunay/Delaunay.hx",23);
	HX_STACK_ARG(coord,"coord");
	HX_STACK_ARG(edgesToTest,"edgesToTest");
	HX_STACK_LINE(23)
	Array< ::neash::geom::Point > coord1 = Array_obj< ::neash::geom::Point >::__new().Add(coord);		HX_STACK_VAR(coord1,"coord1");

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::neash::geom::Point >,coord1)
	bool run(::com::nodename::delaunay::Edge edge){
		HX_STACK_PUSH("*::_Function_1_1","com/nodename/delaunay/Delaunay.hx",25);
		HX_STACK_ARG(edge,"edge");
		{
			HX_STACK_LINE(25)
			return (bool((bool((edge->leftSite != null())) && bool((edge->leftSite->_coord == coord1->__get((int)0))))) || bool((bool((edge->rightSite != null())) && bool((edge->rightSite->_coord == coord1->__get((int)0))))));
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(24)
	return ::Lambda_obj::array(::Lambda_obj::filter(edgesToTest, Dynamic(new _Function_1_1(coord1))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Delaunay_obj,selectEdgesForSitePoint,return )

Array< ::com::nodename::delaunay::Edge > Delaunay_obj::selectNonIntersectingEdges( ::neash::display::BitmapData keepOutMask,Array< ::com::nodename::delaunay::Edge > edgesToTest){
	HX_STACK_PUSH("Delaunay::selectNonIntersectingEdges","com/nodename/delaunay/Delaunay.hx",32);
	HX_STACK_ARG(keepOutMask,"keepOutMask");
	HX_STACK_ARG(edgesToTest,"edgesToTest");
	HX_STACK_LINE(33)
	if (((keepOutMask == null()))){
		HX_STACK_LINE(34)
		return edgesToTest;
	}
	HX_STACK_LINE(38)
	::neash::geom::Point zeroPoint = ::neash::geom::Point_obj::__new(0.0,0.0);		HX_STACK_VAR(zeroPoint,"zeroPoint");

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
	bool run(::com::nodename::delaunay::Edge edge){
		HX_STACK_PUSH("*::_Function_1_1","com/nodename/delaunay/Delaunay.hx",39);
		HX_STACK_ARG(edge,"edge");
		{
			HX_STACK_LINE(40)
			::neash::display::BitmapData delaunayLineBmp = edge->makeDelaunayLineBmp();		HX_STACK_VAR(delaunayLineBmp,"delaunayLineBmp");
			HX_STACK_LINE(42)
			delaunayLineBmp->dispose();
			HX_STACK_LINE(44)
			return false;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(39)
	return ::Lambda_obj::array(::Lambda_obj::filter(edgesToTest, Dynamic(new _Function_1_1())));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Delaunay_obj,selectNonIntersectingEdges,return )

Array< ::com::nodename::geom::LineSegment > Delaunay_obj::visibleLineSegments( Array< ::com::nodename::delaunay::Edge > edges){
	HX_STACK_PUSH("Delaunay::visibleLineSegments","com/nodename/delaunay/Delaunay.hx",49);
	HX_STACK_ARG(edges,"edges");
	HX_STACK_LINE(50)
	Array< ::com::nodename::geom::LineSegment > segments = Array_obj< ::com::nodename::geom::LineSegment >::__new();		HX_STACK_VAR(segments,"segments");
	HX_STACK_LINE(52)
	{
		HX_STACK_LINE(52)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(52)
		while(((_g < edges->length))){
			HX_STACK_LINE(52)
			::com::nodename::delaunay::Edge edge = edges->__get(_g);		HX_STACK_VAR(edge,"edge");
			HX_STACK_LINE(52)
			++(_g);
			HX_STACK_LINE(54)
			if (((edge->clippedEnds != null()))){
				HX_STACK_LINE(56)
				::neash::geom::Point p1 = edge->clippedEnds->get(::com::nodename::delaunay::LR_obj::LEFT->toString());		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(57)
				::neash::geom::Point p2 = edge->clippedEnds->get(::com::nodename::delaunay::LR_obj::RIGHT->toString());		HX_STACK_VAR(p2,"p2");
				HX_STACK_LINE(58)
				segments->push(::com::nodename::geom::LineSegment_obj::__new(p1,p2));
			}
		}
	}
	HX_STACK_LINE(62)
	return segments;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Delaunay_obj,visibleLineSegments,return )


Delaunay_obj::Delaunay_obj()
{
}

void Delaunay_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Delaunay);
	HX_MARK_END_CLASS();
}

void Delaunay_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Delaunay_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 19:
		if (HX_FIELD_EQ(inName,"visibleLineSegments") ) { return visibleLineSegments_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"delaunayLinesForEdges") ) { return delaunayLinesForEdges_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"selectEdgesForSitePoint") ) { return selectEdgesForSitePoint_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"selectNonIntersectingEdges") ) { return selectNonIntersectingEdges_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Delaunay_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Delaunay_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("delaunayLinesForEdges"),
	HX_CSTRING("selectEdgesForSitePoint"),
	HX_CSTRING("selectNonIntersectingEdges"),
	HX_CSTRING("visibleLineSegments"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Delaunay_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Delaunay_obj::__mClass,"__mClass");
};

Class Delaunay_obj::__mClass;

void Delaunay_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.delaunay.Delaunay"), hx::TCanCast< Delaunay_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Delaunay_obj::__boot()
{
}

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_com_nodename_geom_Polygon
#include <com/nodename/geom/Polygon.h>
#endif
#ifndef INCLUDED_com_nodename_geom_Winding
#include <com/nodename/geom/Winding.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
namespace com{
namespace nodename{
namespace geom{

Void Polygon_obj::__construct(Array< ::neash::geom::Point > vertices)
{
HX_STACK_PUSH("Polygon::new","com/nodename/geom/Polygon.hx",10);
{
	HX_STACK_LINE(10)
	this->_vertices = vertices;
}
;
	return null();
}

Polygon_obj::~Polygon_obj() { }

Dynamic Polygon_obj::__CreateEmpty() { return  new Polygon_obj; }
hx::ObjectPtr< Polygon_obj > Polygon_obj::__new(Array< ::neash::geom::Point > vertices)
{  hx::ObjectPtr< Polygon_obj > result = new Polygon_obj();
	result->__construct(vertices);
	return result;}

Dynamic Polygon_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Polygon_obj > result = new Polygon_obj();
	result->__construct(inArgs[0]);
	return result;}

Float Polygon_obj::signedDoubleArea( ){
	HX_STACK_PUSH("Polygon::signedDoubleArea","com/nodename/geom/Polygon.hx",34);
	HX_STACK_THIS(this);
	HX_STACK_LINE(35)
	int index;		HX_STACK_VAR(index,"index");
	int nextIndex;		HX_STACK_VAR(nextIndex,"nextIndex");
	HX_STACK_LINE(36)
	int n = this->_vertices->length;		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(37)
	::neash::geom::Point point;		HX_STACK_VAR(point,"point");
	::neash::geom::Point next;		HX_STACK_VAR(next,"next");
	HX_STACK_LINE(38)
	Float signedDoubleArea = (int)0;		HX_STACK_VAR(signedDoubleArea,"signedDoubleArea");
	HX_STACK_LINE(39)
	{
		HX_STACK_LINE(39)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(39)
		while(((_g < n))){
			HX_STACK_LINE(39)
			int index1 = (_g)++;		HX_STACK_VAR(index1,"index1");
			HX_STACK_LINE(41)
			nextIndex = hx::Mod(((index1 + (int)1)),n);
			HX_STACK_LINE(42)
			point = this->_vertices->__get(index1);
			HX_STACK_LINE(43)
			next = this->_vertices->__get(nextIndex);
			HX_STACK_LINE(44)
			hx::AddEq(signedDoubleArea,((point->x * next->y) - (next->x * point->y)));
		}
	}
	HX_STACK_LINE(46)
	return signedDoubleArea;
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,signedDoubleArea,return )

::com::nodename::geom::Winding Polygon_obj::winding( ){
	HX_STACK_PUSH("Polygon::winding","com/nodename/geom/Polygon.hx",20);
	HX_STACK_THIS(this);
	HX_STACK_LINE(21)
	Float signedDoubleArea = this->signedDoubleArea();		HX_STACK_VAR(signedDoubleArea,"signedDoubleArea");
	HX_STACK_LINE(22)
	if (((signedDoubleArea < (int)0))){
		HX_STACK_LINE(23)
		return ::com::nodename::geom::Winding_obj::CLOCKWISE;
	}
	HX_STACK_LINE(26)
	if (((signedDoubleArea > (int)0))){
		HX_STACK_LINE(27)
		return ::com::nodename::geom::Winding_obj::COUNTERCLOCKWISE;
	}
	HX_STACK_LINE(30)
	return ::com::nodename::geom::Winding_obj::NONE;
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,winding,return )

Float Polygon_obj::area( ){
	HX_STACK_PUSH("Polygon::area","com/nodename/geom/Polygon.hx",15);
	HX_STACK_THIS(this);
	HX_STACK_LINE(15)
	return ::Math_obj::abs((this->signedDoubleArea() * 0.5));
}


HX_DEFINE_DYNAMIC_FUNC0(Polygon_obj,area,return )


Polygon_obj::Polygon_obj()
{
}

void Polygon_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Polygon);
	HX_MARK_MEMBER_NAME(_vertices,"_vertices");
	HX_MARK_END_CLASS();
}

void Polygon_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_vertices,"_vertices");
}

Dynamic Polygon_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"area") ) { return area_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"winding") ) { return winding_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_vertices") ) { return _vertices; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"signedDoubleArea") ) { return signedDoubleArea_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Polygon_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_vertices") ) { _vertices=inValue.Cast< Array< ::neash::geom::Point > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Polygon_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_vertices"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("signedDoubleArea"),
	HX_CSTRING("winding"),
	HX_CSTRING("area"),
	HX_CSTRING("_vertices"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Polygon_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Polygon_obj::__mClass,"__mClass");
};

Class Polygon_obj::__mClass;

void Polygon_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.geom.Polygon"), hx::TCanCast< Polygon_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Polygon_obj::__boot()
{
}

} // end namespace com
} // end namespace nodename
} // end namespace geom

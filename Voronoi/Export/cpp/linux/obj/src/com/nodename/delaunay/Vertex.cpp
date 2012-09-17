#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Edge
#include <com/nodename/delaunay/Edge.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Halfedge
#include <com/nodename/delaunay/Halfedge.h>
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
#ifndef INCLUDED_com_nodename_delaunay_Vertex
#include <com/nodename/delaunay/Vertex.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Voronoi
#include <com/nodename/delaunay/Voronoi.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
namespace com{
namespace nodename{
namespace delaunay{

Void Vertex_obj::__construct(Float x,Float y)
{
HX_STACK_PUSH("Vertex::new","com/nodename/delaunay/Vertex.hx",38);
{
	HX_STACK_LINE(38)
	this->init(x,y);
}
;
	return null();
}

Vertex_obj::~Vertex_obj() { }

Dynamic Vertex_obj::__CreateEmpty() { return  new Vertex_obj; }
hx::ObjectPtr< Vertex_obj > Vertex_obj::__new(Float x,Float y)
{  hx::ObjectPtr< Vertex_obj > result = new Vertex_obj();
	result->__construct(x,y);
	return result;}

Dynamic Vertex_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Vertex_obj > result = new Vertex_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *Vertex_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::com::nodename::delaunay::ICoord_obj)) return operator ::com::nodename::delaunay::ICoord_obj *();
	return super::__ToInterface(inType);
}

Float Vertex_obj::getY( ){
	HX_STACK_PUSH("Vertex::getY","com/nodename/delaunay/Vertex.hx",125);
	HX_STACK_THIS(this);
	HX_STACK_LINE(125)
	return this->_coord->y;
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,getY,return )

Float Vertex_obj::getX( ){
	HX_STACK_PUSH("Vertex::getX","com/nodename/delaunay/Vertex.hx",120);
	HX_STACK_THIS(this);
	HX_STACK_LINE(120)
	return this->_coord->x;
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,getX,return )

::String Vertex_obj::toString( ){
	HX_STACK_PUSH("Vertex::toString","com/nodename/delaunay/Vertex.hx",60);
	HX_STACK_THIS(this);
	HX_STACK_LINE(60)
	return ((HX_CSTRING("Vertex (") + this->vertexIndex) + HX_CSTRING(")"));
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,toString,return )

Void Vertex_obj::setIndex( ){
{
		HX_STACK_PUSH("Vertex::setIndex","com/nodename/delaunay/Vertex.hx",55);
		HX_STACK_THIS(this);
		HX_STACK_LINE(55)
		this->vertexIndex = (::com::nodename::delaunay::Vertex_obj::_nvertices)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,setIndex,(void))

Void Vertex_obj::dispose( ){
{
		HX_STACK_PUSH("Vertex::dispose","com/nodename/delaunay/Vertex.hx",49);
		HX_STACK_THIS(this);
		HX_STACK_LINE(50)
		this->_coord = null();
		HX_STACK_LINE(51)
		::com::nodename::delaunay::Vertex_obj::_pool->push(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,dispose,(void))

::com::nodename::delaunay::Vertex Vertex_obj::init( Float x,Float y){
	HX_STACK_PUSH("Vertex::init","com/nodename/delaunay/Vertex.hx",43);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(44)
	this->_coord = ::neash::geom::Point_obj::__new(x,y);
	HX_STACK_LINE(45)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC2(Vertex_obj,init,return )

::neash::geom::Point Vertex_obj::get_coord( ){
	HX_STACK_PUSH("Vertex::get_coord","com/nodename/delaunay/Vertex.hx",32);
	HX_STACK_THIS(this);
	HX_STACK_LINE(32)
	return this->_coord;
}


HX_DEFINE_DYNAMIC_FUNC0(Vertex_obj,get_coord,return )

::com::nodename::delaunay::Vertex Vertex_obj::VERTEX_AT_INFINITY;

Array< ::com::nodename::delaunay::Vertex > Vertex_obj::_pool;

::com::nodename::delaunay::Vertex Vertex_obj::create( Float x,Float y){
	HX_STACK_PUSH("Vertex::create","com/nodename/delaunay/Vertex.hx",13);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(14)
	if (((bool(::Math_obj::isNaN(x)) || bool(::Math_obj::isNaN(y))))){
		HX_STACK_LINE(15)
		return ::com::nodename::delaunay::Vertex_obj::VERTEX_AT_INFINITY;
	}
	HX_STACK_LINE(18)
	if (((::com::nodename::delaunay::Vertex_obj::_pool->length > (int)0))){
		HX_STACK_LINE(19)
		return ::com::nodename::delaunay::Vertex_obj::_pool->pop()->init(x,y);
	}
	else{
		HX_STACK_LINE(23)
		return ::com::nodename::delaunay::Vertex_obj::__new(x,y);
	}
	HX_STACK_LINE(18)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vertex_obj,create,return )

int Vertex_obj::_nvertices;

::com::nodename::delaunay::Vertex Vertex_obj::intersect( ::com::nodename::delaunay::Halfedge halfedge0,::com::nodename::delaunay::Halfedge halfedge1){
	HX_STACK_PUSH("Vertex::intersect","com/nodename/delaunay/Vertex.hx",73);
	HX_STACK_ARG(halfedge0,"halfedge0");
	HX_STACK_ARG(halfedge1,"halfedge1");
	HX_STACK_LINE(74)
	::com::nodename::delaunay::Edge edge0;		HX_STACK_VAR(edge0,"edge0");
	::com::nodename::delaunay::Edge edge1;		HX_STACK_VAR(edge1,"edge1");
	::com::nodename::delaunay::Edge edge;		HX_STACK_VAR(edge,"edge");
	HX_STACK_LINE(75)
	::com::nodename::delaunay::Halfedge halfedge;		HX_STACK_VAR(halfedge,"halfedge");
	HX_STACK_LINE(76)
	Float determinant;		HX_STACK_VAR(determinant,"determinant");
	Float intersectionX;		HX_STACK_VAR(intersectionX,"intersectionX");
	Float intersectionY;		HX_STACK_VAR(intersectionY,"intersectionY");
	HX_STACK_LINE(77)
	bool rightOfSite;		HX_STACK_VAR(rightOfSite,"rightOfSite");
	HX_STACK_LINE(79)
	edge0 = halfedge0->edge;
	HX_STACK_LINE(80)
	edge1 = halfedge1->edge;
	HX_STACK_LINE(81)
	if (((bool((edge0 == null())) || bool((edge1 == null()))))){
		HX_STACK_LINE(82)
		return null();
	}
	HX_STACK_LINE(85)
	if (((edge0->rightSite == edge1->rightSite))){
		HX_STACK_LINE(86)
		return null();
	}
	HX_STACK_LINE(90)
	determinant = ((edge0->a * edge1->b) - (edge0->b * edge1->a));
	HX_STACK_LINE(91)
	if (((bool((-1e-10 < determinant)) && bool((determinant < 1.0e-10))))){
		HX_STACK_LINE(92)
		return null();
	}
	HX_STACK_LINE(97)
	intersectionX = (Float((((edge0->c * edge1->b) - (edge1->c * edge0->b)))) / Float(determinant));
	HX_STACK_LINE(98)
	intersectionY = (Float((((edge1->c * edge0->a) - (edge0->c * edge1->a)))) / Float(determinant));
	HX_STACK_LINE(101)
	if (((::com::nodename::delaunay::Voronoi_obj::compareSiteByYThenX(edge0->rightSite,edge1->rightSite) < (int)0))){
		HX_STACK_LINE(103)
		halfedge = halfedge0;
		HX_STACK_LINE(103)
		edge = edge0;
	}
	else{
		HX_STACK_LINE(107)
		halfedge = halfedge1;
		HX_STACK_LINE(107)
		edge = edge1;
	}
	HX_STACK_LINE(109)
	rightOfSite = (intersectionX >= edge->rightSite->_coord->x);
	HX_STACK_LINE(110)
	if (((bool((bool(rightOfSite) && bool((halfedge->leftRight == ::com::nodename::delaunay::LR_obj::LEFT)))) || bool((bool(!(rightOfSite)) && bool((halfedge->leftRight == ::com::nodename::delaunay::LR_obj::RIGHT))))))){
		HX_STACK_LINE(112)
		return null();
	}
	HX_STACK_LINE(115)
	return ::com::nodename::delaunay::Vertex_obj::create(intersectionX,intersectionY);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vertex_obj,intersect,return )


Vertex_obj::Vertex_obj()
{
}

void Vertex_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Vertex);
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(vertexIndex,"vertexIndex");
	HX_MARK_MEMBER_NAME(coord,"coord");
	HX_MARK_MEMBER_NAME(_coord,"_coord");
	HX_MARK_END_CLASS();
}

void Vertex_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(vertexIndex,"vertexIndex");
	HX_VISIT_MEMBER_NAME(coord,"coord");
	HX_VISIT_MEMBER_NAME(_coord,"_coord");
}

Dynamic Vertex_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return inCallProp ? getY() : y; }
		if (HX_FIELD_EQ(inName,"x") ) { return inCallProp ? getX() : x; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"getY") ) { return getY_dyn(); }
		if (HX_FIELD_EQ(inName,"getX") ) { return getX_dyn(); }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_pool") ) { return _pool; }
		if (HX_FIELD_EQ(inName,"coord") ) { return inCallProp ? get_coord() : coord; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"_coord") ) { return _coord; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"setIndex") ) { return setIndex_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"intersect") ) { return intersect_dyn(); }
		if (HX_FIELD_EQ(inName,"get_coord") ) { return get_coord_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_nvertices") ) { return _nvertices; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"vertexIndex") ) { return vertexIndex; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"VERTEX_AT_INFINITY") ) { return VERTEX_AT_INFINITY; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Vertex_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_pool") ) { _pool=inValue.Cast< Array< ::com::nodename::delaunay::Vertex > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"coord") ) { coord=inValue.Cast< ::neash::geom::Point >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_coord") ) { _coord=inValue.Cast< ::neash::geom::Point >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_nvertices") ) { _nvertices=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"vertexIndex") ) { vertexIndex=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"VERTEX_AT_INFINITY") ) { VERTEX_AT_INFINITY=inValue.Cast< ::com::nodename::delaunay::Vertex >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Vertex_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("vertexIndex"));
	outFields->push(HX_CSTRING("coord"));
	outFields->push(HX_CSTRING("_coord"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("VERTEX_AT_INFINITY"),
	HX_CSTRING("_pool"),
	HX_CSTRING("create"),
	HX_CSTRING("_nvertices"),
	HX_CSTRING("intersect"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getY"),
	HX_CSTRING("y"),
	HX_CSTRING("getX"),
	HX_CSTRING("x"),
	HX_CSTRING("toString"),
	HX_CSTRING("setIndex"),
	HX_CSTRING("dispose"),
	HX_CSTRING("init"),
	HX_CSTRING("vertexIndex"),
	HX_CSTRING("get_coord"),
	HX_CSTRING("coord"),
	HX_CSTRING("_coord"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Vertex_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Vertex_obj::VERTEX_AT_INFINITY,"VERTEX_AT_INFINITY");
	HX_MARK_MEMBER_NAME(Vertex_obj::_pool,"_pool");
	HX_MARK_MEMBER_NAME(Vertex_obj::_nvertices,"_nvertices");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Vertex_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Vertex_obj::VERTEX_AT_INFINITY,"VERTEX_AT_INFINITY");
	HX_VISIT_MEMBER_NAME(Vertex_obj::_pool,"_pool");
	HX_VISIT_MEMBER_NAME(Vertex_obj::_nvertices,"_nvertices");
};

Class Vertex_obj::__mClass;

void Vertex_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.delaunay.Vertex"), hx::TCanCast< Vertex_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Vertex_obj::__boot()
{
	VERTEX_AT_INFINITY= ::com::nodename::delaunay::Vertex_obj::__new(::Math_obj::NaN,::Math_obj::NaN);
	_pool= Array_obj< ::com::nodename::delaunay::Vertex >::__new();
	_nvertices= (int)0;
}

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

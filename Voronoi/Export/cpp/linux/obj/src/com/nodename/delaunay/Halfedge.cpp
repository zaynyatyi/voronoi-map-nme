#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
namespace com{
namespace nodename{
namespace delaunay{

Void Halfedge_obj::__construct(::com::nodename::delaunay::Edge edge,::com::nodename::delaunay::LR lr)
{
HX_STACK_PUSH("Halfedge::new","com/nodename/delaunay/Halfedge.hx",38);
{
	HX_STACK_LINE(38)
	this->init(edge,lr);
}
;
	return null();
}

Halfedge_obj::~Halfedge_obj() { }

Dynamic Halfedge_obj::__CreateEmpty() { return  new Halfedge_obj; }
hx::ObjectPtr< Halfedge_obj > Halfedge_obj::__new(::com::nodename::delaunay::Edge edge,::com::nodename::delaunay::LR lr)
{  hx::ObjectPtr< Halfedge_obj > result = new Halfedge_obj();
	result->__construct(edge,lr);
	return result;}

Dynamic Halfedge_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Halfedge_obj > result = new Halfedge_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

bool Halfedge_obj::isLeftOf( ::neash::geom::Point p){
	HX_STACK_PUSH("Halfedge::isLeftOf","com/nodename/delaunay/Halfedge.hx",86);
	HX_STACK_THIS(this);
	HX_STACK_ARG(p,"p");
	HX_STACK_LINE(87)
	::com::nodename::delaunay::Site topSite;		HX_STACK_VAR(topSite,"topSite");
	HX_STACK_LINE(88)
	bool rightOfSite;		HX_STACK_VAR(rightOfSite,"rightOfSite");
	bool above;		HX_STACK_VAR(above,"above");
	bool fast;		HX_STACK_VAR(fast,"fast");
	HX_STACK_LINE(89)
	Float dxp;		HX_STACK_VAR(dxp,"dxp");
	Float dyp;		HX_STACK_VAR(dyp,"dyp");
	Float dxs;		HX_STACK_VAR(dxs,"dxs");
	Float t1;		HX_STACK_VAR(t1,"t1");
	Float t2;		HX_STACK_VAR(t2,"t2");
	Float t3;		HX_STACK_VAR(t3,"t3");
	Float yl;		HX_STACK_VAR(yl,"yl");
	HX_STACK_LINE(91)
	topSite = this->edge->rightSite;
	HX_STACK_LINE(92)
	rightOfSite = (p->x > topSite->_coord->x);
	HX_STACK_LINE(93)
	if (((bool(rightOfSite) && bool((this->leftRight == ::com::nodename::delaunay::LR_obj::LEFT))))){
		HX_STACK_LINE(94)
		return true;
	}
	HX_STACK_LINE(97)
	if (((bool(!(rightOfSite)) && bool((this->leftRight == ::com::nodename::delaunay::LR_obj::RIGHT))))){
		HX_STACK_LINE(98)
		return false;
	}
	HX_STACK_LINE(102)
	if (((this->edge->a == 1.0))){
		HX_STACK_LINE(104)
		dyp = (p->y - topSite->_coord->y);
		HX_STACK_LINE(105)
		dxp = (p->x - topSite->_coord->x);
		HX_STACK_LINE(106)
		fast = false;
		HX_STACK_LINE(107)
		if (((bool((bool(!(rightOfSite)) && bool((this->edge->b < 0.0)))) || bool((bool(rightOfSite) && bool((this->edge->b >= 0.0))))))){
			HX_STACK_LINE(109)
			above = (dyp >= (this->edge->b * dxp));
			HX_STACK_LINE(110)
			fast = above;
		}
		else{
			HX_STACK_LINE(114)
			above = ((p->x + (p->y * this->edge->b)) > this->edge->c);
			HX_STACK_LINE(115)
			if (((this->edge->b < 0.0))){
				HX_STACK_LINE(116)
				above = !(above);
			}
			HX_STACK_LINE(119)
			if ((!(above))){
				HX_STACK_LINE(120)
				fast = true;
			}
		}
		HX_STACK_LINE(124)
		if ((!(fast))){
			HX_STACK_LINE(126)
			dxs = (topSite->_coord->x - this->edge->leftSite->_coord->x);
			HX_STACK_LINE(127)
			above = ((this->edge->b * (((dxp * dxp) - (dyp * dyp)))) < ((dxs * dyp) * (((1.0 + (Float((2.0 * dxp)) / Float(dxs))) + (this->edge->b * this->edge->b)))));
			HX_STACK_LINE(128)
			if (((this->edge->b < 0.0))){
				HX_STACK_LINE(129)
				above = !(above);
			}
		}
	}
	else{
		HX_STACK_LINE(136)
		yl = (this->edge->c - (this->edge->a * p->x));
		HX_STACK_LINE(137)
		t1 = (p->y - yl);
		HX_STACK_LINE(138)
		t2 = (p->x - topSite->_coord->x);
		HX_STACK_LINE(139)
		t3 = (yl - topSite->_coord->y);
		HX_STACK_LINE(140)
		above = ((t1 * t1) > ((t2 * t2) + (t3 * t3)));
	}
	HX_STACK_LINE(142)
	return (  (((this->leftRight == ::com::nodename::delaunay::LR_obj::LEFT))) ? bool(above) : bool(!(above)) );
}


HX_DEFINE_DYNAMIC_FUNC1(Halfedge_obj,isLeftOf,return )

Void Halfedge_obj::reallyDispose( ){
{
		HX_STACK_PUSH("Halfedge::reallyDispose","com/nodename/delaunay/Halfedge.hx",75);
		HX_STACK_THIS(this);
		HX_STACK_LINE(76)
		this->edgeListLeftNeighbor = null();
		HX_STACK_LINE(77)
		this->edgeListRightNeighbor = null();
		HX_STACK_LINE(78)
		this->nextInPriorityQueue = null();
		HX_STACK_LINE(79)
		this->edge = null();
		HX_STACK_LINE(80)
		this->leftRight = null();
		HX_STACK_LINE(81)
		this->vertex = null();
		HX_STACK_LINE(82)
		::com::nodename::delaunay::Halfedge_obj::_pool->push(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Halfedge_obj,reallyDispose,(void))

Void Halfedge_obj::dispose( ){
{
		HX_STACK_PUSH("Halfedge::dispose","com/nodename/delaunay/Halfedge.hx",57);
		HX_STACK_THIS(this);
		HX_STACK_LINE(58)
		if (((bool((this->edgeListLeftNeighbor != null())) || bool((this->edgeListRightNeighbor != null()))))){
			HX_STACK_LINE(59)
			return null();
		}
		HX_STACK_LINE(63)
		if (((this->nextInPriorityQueue != null()))){
			HX_STACK_LINE(64)
			return null();
		}
		HX_STACK_LINE(68)
		this->edge = null();
		HX_STACK_LINE(69)
		this->leftRight = null();
		HX_STACK_LINE(70)
		this->vertex = null();
		HX_STACK_LINE(71)
		::com::nodename::delaunay::Halfedge_obj::_pool->push(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Halfedge_obj,dispose,(void))

::String Halfedge_obj::toString( ){
	HX_STACK_PUSH("Halfedge::toString","com/nodename/delaunay/Halfedge.hx",52);
	HX_STACK_THIS(this);
	HX_STACK_LINE(52)
	return ((((HX_CSTRING("Halfedge (leftRight: ") + ::Std_obj::string(this->leftRight)) + HX_CSTRING("; vertex: ")) + ::Std_obj::string(this->vertex)) + HX_CSTRING(")"));
}


HX_DEFINE_DYNAMIC_FUNC0(Halfedge_obj,toString,return )

::com::nodename::delaunay::Halfedge Halfedge_obj::init( ::com::nodename::delaunay::Edge edge,::com::nodename::delaunay::LR lr){
	HX_STACK_PUSH("Halfedge::init","com/nodename/delaunay/Halfedge.hx",43);
	HX_STACK_THIS(this);
	HX_STACK_ARG(edge,"edge");
	HX_STACK_ARG(lr,"lr");
	HX_STACK_LINE(44)
	this->edge = edge;
	HX_STACK_LINE(45)
	this->leftRight = lr;
	HX_STACK_LINE(46)
	this->nextInPriorityQueue = null();
	HX_STACK_LINE(47)
	this->vertex = null();
	HX_STACK_LINE(48)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC2(Halfedge_obj,init,return )

Array< ::com::nodename::delaunay::Halfedge > Halfedge_obj::_pool;

::com::nodename::delaunay::Halfedge Halfedge_obj::create( ::com::nodename::delaunay::Edge edge,::com::nodename::delaunay::LR lr){
	HX_STACK_PUSH("Halfedge::create","com/nodename/delaunay/Halfedge.hx",10);
	HX_STACK_ARG(edge,"edge");
	HX_STACK_ARG(lr,"lr");
	HX_STACK_LINE(10)
	if (((::com::nodename::delaunay::Halfedge_obj::_pool->length > (int)0))){
		HX_STACK_LINE(12)
		return ::com::nodename::delaunay::Halfedge_obj::_pool->pop()->init(edge,lr);
	}
	else{
		HX_STACK_LINE(16)
		return ::com::nodename::delaunay::Halfedge_obj::__new(edge,lr);
	}
	HX_STACK_LINE(10)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Halfedge_obj,create,return )

::com::nodename::delaunay::Halfedge Halfedge_obj::createDummy( ){
	HX_STACK_PUSH("Halfedge::createDummy","com/nodename/delaunay/Halfedge.hx",22);
	HX_STACK_LINE(22)
	return ::com::nodename::delaunay::Halfedge_obj::create(null(),null());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Halfedge_obj,createDummy,return )


Halfedge_obj::Halfedge_obj()
{
}

void Halfedge_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Halfedge);
	HX_MARK_MEMBER_NAME(ystar,"ystar");
	HX_MARK_MEMBER_NAME(vertex,"vertex");
	HX_MARK_MEMBER_NAME(leftRight,"leftRight");
	HX_MARK_MEMBER_NAME(edge,"edge");
	HX_MARK_MEMBER_NAME(nextInPriorityQueue,"nextInPriorityQueue");
	HX_MARK_MEMBER_NAME(edgeListRightNeighbor,"edgeListRightNeighbor");
	HX_MARK_MEMBER_NAME(edgeListLeftNeighbor,"edgeListLeftNeighbor");
	HX_MARK_END_CLASS();
}

void Halfedge_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(ystar,"ystar");
	HX_VISIT_MEMBER_NAME(vertex,"vertex");
	HX_VISIT_MEMBER_NAME(leftRight,"leftRight");
	HX_VISIT_MEMBER_NAME(edge,"edge");
	HX_VISIT_MEMBER_NAME(nextInPriorityQueue,"nextInPriorityQueue");
	HX_VISIT_MEMBER_NAME(edgeListRightNeighbor,"edgeListRightNeighbor");
	HX_VISIT_MEMBER_NAME(edgeListLeftNeighbor,"edgeListLeftNeighbor");
}

Dynamic Halfedge_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"edge") ) { return edge; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_pool") ) { return _pool; }
		if (HX_FIELD_EQ(inName,"ystar") ) { return ystar; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"vertex") ) { return vertex; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isLeftOf") ) { return isLeftOf_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"leftRight") ) { return leftRight; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"createDummy") ) { return createDummy_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"reallyDispose") ) { return reallyDispose_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nextInPriorityQueue") ) { return nextInPriorityQueue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"edgeListLeftNeighbor") ) { return edgeListLeftNeighbor; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"edgeListRightNeighbor") ) { return edgeListRightNeighbor; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Halfedge_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"edge") ) { edge=inValue.Cast< ::com::nodename::delaunay::Edge >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_pool") ) { _pool=inValue.Cast< Array< ::com::nodename::delaunay::Halfedge > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ystar") ) { ystar=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"vertex") ) { vertex=inValue.Cast< ::com::nodename::delaunay::Vertex >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"leftRight") ) { leftRight=inValue.Cast< ::com::nodename::delaunay::LR >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nextInPriorityQueue") ) { nextInPriorityQueue=inValue.Cast< ::com::nodename::delaunay::Halfedge >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"edgeListLeftNeighbor") ) { edgeListLeftNeighbor=inValue.Cast< ::com::nodename::delaunay::Halfedge >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"edgeListRightNeighbor") ) { edgeListRightNeighbor=inValue.Cast< ::com::nodename::delaunay::Halfedge >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Halfedge_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("ystar"));
	outFields->push(HX_CSTRING("vertex"));
	outFields->push(HX_CSTRING("leftRight"));
	outFields->push(HX_CSTRING("edge"));
	outFields->push(HX_CSTRING("nextInPriorityQueue"));
	outFields->push(HX_CSTRING("edgeListRightNeighbor"));
	outFields->push(HX_CSTRING("edgeListLeftNeighbor"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_pool"),
	HX_CSTRING("create"),
	HX_CSTRING("createDummy"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("isLeftOf"),
	HX_CSTRING("reallyDispose"),
	HX_CSTRING("dispose"),
	HX_CSTRING("toString"),
	HX_CSTRING("init"),
	HX_CSTRING("ystar"),
	HX_CSTRING("vertex"),
	HX_CSTRING("leftRight"),
	HX_CSTRING("edge"),
	HX_CSTRING("nextInPriorityQueue"),
	HX_CSTRING("edgeListRightNeighbor"),
	HX_CSTRING("edgeListLeftNeighbor"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Halfedge_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Halfedge_obj::_pool,"_pool");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Halfedge_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Halfedge_obj::_pool,"_pool");
};

Class Halfedge_obj::__mClass;

void Halfedge_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.delaunay.Halfedge"), hx::TCanCast< Halfedge_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Halfedge_obj::__boot()
{
	_pool= Array_obj< ::com::nodename::delaunay::Halfedge >::__new();
}

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

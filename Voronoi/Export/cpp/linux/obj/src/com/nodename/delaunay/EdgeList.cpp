#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Edge
#include <com/nodename/delaunay/Edge.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_EdgeList
#include <com/nodename/delaunay/EdgeList.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Halfedge
#include <com/nodename/delaunay/Halfedge.h>
#endif
#ifndef INCLUDED_com_nodename_utils_IDisposable
#include <com/nodename/utils/IDisposable.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
namespace com{
namespace nodename{
namespace delaunay{

Void EdgeList_obj::__construct(Float xmin,Float deltax,int sqrt_nsites)
{
HX_STACK_PUSH("EdgeList::new","com/nodename/delaunay/EdgeList.hx",50);
{
	HX_STACK_LINE(51)
	this->_xmin = xmin;
	HX_STACK_LINE(52)
	this->_deltax = deltax;
	HX_STACK_LINE(53)
	this->_hashsize = ((int)2 * sqrt_nsites);
	HX_STACK_LINE(56)
	this->_hash = Array_obj< ::com::nodename::delaunay::Halfedge >::__new();
	HX_STACK_LINE(59)
	this->_leftEnd = ::com::nodename::delaunay::Halfedge_obj::createDummy();
	HX_STACK_LINE(60)
	this->_rightEnd = ::com::nodename::delaunay::Halfedge_obj::createDummy();
	HX_STACK_LINE(61)
	this->_leftEnd->edgeListLeftNeighbor = null();
	HX_STACK_LINE(62)
	this->_leftEnd->edgeListRightNeighbor = this->_rightEnd;
	HX_STACK_LINE(63)
	this->_rightEnd->edgeListLeftNeighbor = this->_leftEnd;
	HX_STACK_LINE(64)
	this->_rightEnd->edgeListRightNeighbor = null();
	HX_STACK_LINE(65)
	this->_hash[(int)0] = this->_leftEnd;
	HX_STACK_LINE(66)
	this->_hash[(this->_hashsize - (int)1)] = this->_rightEnd;
}
;
	return null();
}

EdgeList_obj::~EdgeList_obj() { }

Dynamic EdgeList_obj::__CreateEmpty() { return  new EdgeList_obj; }
hx::ObjectPtr< EdgeList_obj > EdgeList_obj::__new(Float xmin,Float deltax,int sqrt_nsites)
{  hx::ObjectPtr< EdgeList_obj > result = new EdgeList_obj();
	result->__construct(xmin,deltax,sqrt_nsites);
	return result;}

Dynamic EdgeList_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EdgeList_obj > result = new EdgeList_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *EdgeList_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::com::nodename::utils::IDisposable_obj)) return operator ::com::nodename::utils::IDisposable_obj *();
	return super::__ToInterface(inType);
}

::com::nodename::delaunay::Halfedge EdgeList_obj::getHash( int b){
	HX_STACK_PUSH("EdgeList::getHash","com/nodename/delaunay/EdgeList.hx",159);
	HX_STACK_THIS(this);
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(160)
	::com::nodename::delaunay::Halfedge halfEdge;		HX_STACK_VAR(halfEdge,"halfEdge");
	HX_STACK_LINE(162)
	if (((bool((b < (int)0)) || bool((b >= this->_hashsize))))){
		HX_STACK_LINE(163)
		return null();
	}
	HX_STACK_LINE(166)
	halfEdge = this->_hash->__get(b);
	HX_STACK_LINE(167)
	if (((bool((halfEdge != null())) && bool((halfEdge->edge == ::com::nodename::delaunay::Edge_obj::DELETED))))){
		HX_STACK_LINE(170)
		this->_hash[b] = null();
		HX_STACK_LINE(172)
		return null();
	}
	else{
		HX_STACK_LINE(175)
		return halfEdge;
	}
	HX_STACK_LINE(167)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(EdgeList_obj,getHash,return )

::com::nodename::delaunay::Halfedge EdgeList_obj::edgeListLeftNeighbor( ::neash::geom::Point p){
	HX_STACK_PUSH("EdgeList::edgeListLeftNeighbor","com/nodename/delaunay/EdgeList.hx",104);
	HX_STACK_THIS(this);
	HX_STACK_ARG(p,"p");
	HX_STACK_LINE(105)
	int i;		HX_STACK_VAR(i,"i");
	int bucket;		HX_STACK_VAR(bucket,"bucket");
	HX_STACK_LINE(106)
	::com::nodename::delaunay::Halfedge halfEdge;		HX_STACK_VAR(halfEdge,"halfEdge");
	HX_STACK_LINE(109)
	bucket = ::Std_obj::_int(((Float(((p->x - this->_xmin))) / Float(this->_deltax)) * this->_hashsize));
	HX_STACK_LINE(110)
	if (((bucket < (int)0))){
		HX_STACK_LINE(111)
		bucket = (int)0;
	}
	HX_STACK_LINE(114)
	if (((bucket >= this->_hashsize))){
		HX_STACK_LINE(115)
		bucket = (this->_hashsize - (int)1);
	}
	HX_STACK_LINE(118)
	halfEdge = this->getHash(bucket);
	HX_STACK_LINE(119)
	if (((halfEdge == null()))){
		HX_STACK_LINE(121)
		int i1 = (int)1;		HX_STACK_VAR(i1,"i1");
		HX_STACK_LINE(122)
		while((true)){
			HX_STACK_LINE(124)
			if ((((halfEdge = this->getHash((bucket - i1))) != null()))){
				HX_STACK_LINE(124)
				break;
			}
			HX_STACK_LINE(125)
			if ((((halfEdge = this->getHash((bucket + i1))) != null()))){
				HX_STACK_LINE(125)
				break;
			}
			HX_STACK_LINE(127)
			(i1)++;
		}
	}
	HX_STACK_LINE(131)
	if (((bool((halfEdge == this->_leftEnd)) || bool((bool((halfEdge != this->_rightEnd)) && bool(halfEdge->isLeftOf(p))))))){
		HX_STACK_LINE(133)
		do{
			HX_STACK_LINE(134)
			halfEdge = halfEdge->edgeListRightNeighbor;
		}
while(((bool((halfEdge != this->_rightEnd)) && bool(halfEdge->isLeftOf(p)))));
		HX_STACK_LINE(138)
		halfEdge = halfEdge->edgeListLeftNeighbor;
	}
	else{
		HX_STACK_LINE(141)
		do{
			HX_STACK_LINE(143)
			halfEdge = halfEdge->edgeListLeftNeighbor;
		}
while(((bool((halfEdge != this->_leftEnd)) && bool(!(halfEdge->isLeftOf(p))))));
	}
	HX_STACK_LINE(150)
	if (((bool((bucket > (int)0)) && bool((bucket < (this->_hashsize - (int)1)))))){
		HX_STACK_LINE(151)
		this->_hash[bucket] = halfEdge;
	}
	HX_STACK_LINE(154)
	return halfEdge;
}


HX_DEFINE_DYNAMIC_FUNC1(EdgeList_obj,edgeListLeftNeighbor,return )

Void EdgeList_obj::remove( ::com::nodename::delaunay::Halfedge halfEdge){
{
		HX_STACK_PUSH("EdgeList::remove","com/nodename/delaunay/EdgeList.hx",90);
		HX_STACK_THIS(this);
		HX_STACK_ARG(halfEdge,"halfEdge");
		HX_STACK_LINE(91)
		halfEdge->edgeListLeftNeighbor->edgeListRightNeighbor = halfEdge->edgeListRightNeighbor;
		HX_STACK_LINE(92)
		halfEdge->edgeListRightNeighbor->edgeListLeftNeighbor = halfEdge->edgeListLeftNeighbor;
		HX_STACK_LINE(93)
		halfEdge->edge = ::com::nodename::delaunay::Edge_obj::DELETED;
		HX_STACK_LINE(94)
		halfEdge->edgeListLeftNeighbor = halfEdge->edgeListRightNeighbor = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(EdgeList_obj,remove,(void))

Void EdgeList_obj::insert( ::com::nodename::delaunay::Halfedge lb,::com::nodename::delaunay::Halfedge newHalfedge){
{
		HX_STACK_PUSH("EdgeList::insert","com/nodename/delaunay/EdgeList.hx",76);
		HX_STACK_THIS(this);
		HX_STACK_ARG(lb,"lb");
		HX_STACK_ARG(newHalfedge,"newHalfedge");
		HX_STACK_LINE(77)
		newHalfedge->edgeListLeftNeighbor = lb;
		HX_STACK_LINE(78)
		newHalfedge->edgeListRightNeighbor = lb->edgeListRightNeighbor;
		HX_STACK_LINE(79)
		lb->edgeListRightNeighbor->edgeListLeftNeighbor = newHalfedge;
		HX_STACK_LINE(80)
		lb->edgeListRightNeighbor = newHalfedge;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(EdgeList_obj,insert,(void))

Void EdgeList_obj::dispose( ){
{
		HX_STACK_PUSH("EdgeList::dispose","com/nodename/delaunay/EdgeList.hx",28);
		HX_STACK_THIS(this);
		HX_STACK_LINE(29)
		::com::nodename::delaunay::Halfedge halfEdge = this->_leftEnd;		HX_STACK_VAR(halfEdge,"halfEdge");
		HX_STACK_LINE(30)
		::com::nodename::delaunay::Halfedge prevHe;		HX_STACK_VAR(prevHe,"prevHe");
		HX_STACK_LINE(31)
		while(((halfEdge != this->_rightEnd))){
			HX_STACK_LINE(33)
			prevHe = halfEdge;
			HX_STACK_LINE(34)
			halfEdge = halfEdge->edgeListRightNeighbor;
			HX_STACK_LINE(35)
			prevHe->dispose();
		}
		HX_STACK_LINE(37)
		this->_leftEnd = null();
		HX_STACK_LINE(38)
		this->_rightEnd->dispose();
		HX_STACK_LINE(39)
		this->_rightEnd = null();
		HX_STACK_LINE(41)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(42)
		{
			HX_STACK_LINE(42)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->_hashsize;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(42)
			while(((_g1 < _g))){
				HX_STACK_LINE(42)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(44)
				this->_hash[i1] = null();
			}
		}
		HX_STACK_LINE(46)
		this->_hash = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(EdgeList_obj,dispose,(void))

::com::nodename::delaunay::Halfedge EdgeList_obj::getRightEnd( ){
	HX_STACK_PUSH("EdgeList::getRightEnd","com/nodename/delaunay/EdgeList.hx",23);
	HX_STACK_THIS(this);
	HX_STACK_LINE(23)
	return this->_rightEnd;
}


HX_DEFINE_DYNAMIC_FUNC0(EdgeList_obj,getRightEnd,return )

::com::nodename::delaunay::Halfedge EdgeList_obj::getLeftEnd( ){
	HX_STACK_PUSH("EdgeList::getLeftEnd","com/nodename/delaunay/EdgeList.hx",17);
	HX_STACK_THIS(this);
	HX_STACK_LINE(17)
	return this->_leftEnd;
}


HX_DEFINE_DYNAMIC_FUNC0(EdgeList_obj,getLeftEnd,return )


EdgeList_obj::EdgeList_obj()
{
}

void EdgeList_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EdgeList);
	HX_MARK_MEMBER_NAME(rightEnd,"rightEnd");
	HX_MARK_MEMBER_NAME(_rightEnd,"_rightEnd");
	HX_MARK_MEMBER_NAME(leftEnd,"leftEnd");
	HX_MARK_MEMBER_NAME(_leftEnd,"_leftEnd");
	HX_MARK_MEMBER_NAME(_hash,"_hash");
	HX_MARK_MEMBER_NAME(_hashsize,"_hashsize");
	HX_MARK_MEMBER_NAME(_xmin,"_xmin");
	HX_MARK_MEMBER_NAME(_deltax,"_deltax");
	HX_MARK_END_CLASS();
}

void EdgeList_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(rightEnd,"rightEnd");
	HX_VISIT_MEMBER_NAME(_rightEnd,"_rightEnd");
	HX_VISIT_MEMBER_NAME(leftEnd,"leftEnd");
	HX_VISIT_MEMBER_NAME(_leftEnd,"_leftEnd");
	HX_VISIT_MEMBER_NAME(_hash,"_hash");
	HX_VISIT_MEMBER_NAME(_hashsize,"_hashsize");
	HX_VISIT_MEMBER_NAME(_xmin,"_xmin");
	HX_VISIT_MEMBER_NAME(_deltax,"_deltax");
}

Dynamic EdgeList_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_hash") ) { return _hash; }
		if (HX_FIELD_EQ(inName,"_xmin") ) { return _xmin; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		if (HX_FIELD_EQ(inName,"insert") ) { return insert_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getHash") ) { return getHash_dyn(); }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"leftEnd") ) { return inCallProp ? getLeftEnd() : leftEnd; }
		if (HX_FIELD_EQ(inName,"_deltax") ) { return _deltax; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rightEnd") ) { return inCallProp ? getRightEnd() : rightEnd; }
		if (HX_FIELD_EQ(inName,"_leftEnd") ) { return _leftEnd; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_rightEnd") ) { return _rightEnd; }
		if (HX_FIELD_EQ(inName,"_hashsize") ) { return _hashsize; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getLeftEnd") ) { return getLeftEnd_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getRightEnd") ) { return getRightEnd_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"edgeListLeftNeighbor") ) { return edgeListLeftNeighbor_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EdgeList_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_hash") ) { _hash=inValue.Cast< Array< ::com::nodename::delaunay::Halfedge > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_xmin") ) { _xmin=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"leftEnd") ) { leftEnd=inValue.Cast< ::com::nodename::delaunay::Halfedge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_deltax") ) { _deltax=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rightEnd") ) { rightEnd=inValue.Cast< ::com::nodename::delaunay::Halfedge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_leftEnd") ) { _leftEnd=inValue.Cast< ::com::nodename::delaunay::Halfedge >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_rightEnd") ) { _rightEnd=inValue.Cast< ::com::nodename::delaunay::Halfedge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_hashsize") ) { _hashsize=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EdgeList_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("rightEnd"));
	outFields->push(HX_CSTRING("_rightEnd"));
	outFields->push(HX_CSTRING("leftEnd"));
	outFields->push(HX_CSTRING("_leftEnd"));
	outFields->push(HX_CSTRING("_hash"));
	outFields->push(HX_CSTRING("_hashsize"));
	outFields->push(HX_CSTRING("_xmin"));
	outFields->push(HX_CSTRING("_deltax"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getHash"),
	HX_CSTRING("edgeListLeftNeighbor"),
	HX_CSTRING("remove"),
	HX_CSTRING("insert"),
	HX_CSTRING("dispose"),
	HX_CSTRING("getRightEnd"),
	HX_CSTRING("rightEnd"),
	HX_CSTRING("_rightEnd"),
	HX_CSTRING("getLeftEnd"),
	HX_CSTRING("leftEnd"),
	HX_CSTRING("_leftEnd"),
	HX_CSTRING("_hash"),
	HX_CSTRING("_hashsize"),
	HX_CSTRING("_xmin"),
	HX_CSTRING("_deltax"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EdgeList_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EdgeList_obj::__mClass,"__mClass");
};

Class EdgeList_obj::__mClass;

void EdgeList_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.delaunay.EdgeList"), hx::TCanCast< EdgeList_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void EdgeList_obj::__boot()
{
}

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

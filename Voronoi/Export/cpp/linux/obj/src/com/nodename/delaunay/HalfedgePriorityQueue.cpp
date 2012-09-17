#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Halfedge
#include <com/nodename/delaunay/Halfedge.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_HalfedgePriorityQueue
#include <com/nodename/delaunay/HalfedgePriorityQueue.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_ICoord
#include <com/nodename/delaunay/ICoord.h>
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

Void HalfedgePriorityQueue_obj::__construct(Float ymin,Float deltay,int sqrt_nsites)
{
HX_STACK_PUSH("HalfedgePriorityQueue::new","com/nodename/delaunay/HalfedgePriorityQueue.hx",17);
{
	HX_STACK_LINE(18)
	this->_ymin = ymin;
	HX_STACK_LINE(19)
	this->_deltay = deltay;
	HX_STACK_LINE(20)
	this->_hashsize = ((int)4 * sqrt_nsites);
	HX_STACK_LINE(21)
	this->initialize();
}
;
	return null();
}

HalfedgePriorityQueue_obj::~HalfedgePriorityQueue_obj() { }

Dynamic HalfedgePriorityQueue_obj::__CreateEmpty() { return  new HalfedgePriorityQueue_obj; }
hx::ObjectPtr< HalfedgePriorityQueue_obj > HalfedgePriorityQueue_obj::__new(Float ymin,Float deltay,int sqrt_nsites)
{  hx::ObjectPtr< HalfedgePriorityQueue_obj > result = new HalfedgePriorityQueue_obj();
	result->__construct(ymin,deltay,sqrt_nsites);
	return result;}

Dynamic HalfedgePriorityQueue_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HalfedgePriorityQueue_obj > result = new HalfedgePriorityQueue_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::com::nodename::delaunay::Halfedge HalfedgePriorityQueue_obj::extractMin( ){
	HX_STACK_PUSH("HalfedgePriorityQueue::extractMin","com/nodename/delaunay/HalfedgePriorityQueue.hx",136);
	HX_STACK_THIS(this);
	HX_STACK_LINE(137)
	::com::nodename::delaunay::Halfedge answer;		HX_STACK_VAR(answer,"answer");
	HX_STACK_LINE(140)
	answer = this->_hash->__get(this->_minBucket)->nextInPriorityQueue;
	HX_STACK_LINE(142)
	this->_hash->__get(this->_minBucket)->nextInPriorityQueue = answer->nextInPriorityQueue;
	HX_STACK_LINE(143)
	(this->_count)--;
	HX_STACK_LINE(144)
	answer->nextInPriorityQueue = null();
	HX_STACK_LINE(146)
	return answer;
}


HX_DEFINE_DYNAMIC_FUNC0(HalfedgePriorityQueue_obj,extractMin,return )

::neash::geom::Point HalfedgePriorityQueue_obj::min( ){
	HX_STACK_PUSH("HalfedgePriorityQueue::min","com/nodename/delaunay/HalfedgePriorityQueue.hx",124);
	HX_STACK_THIS(this);
	HX_STACK_LINE(125)
	this->adjustMinBucket();
	HX_STACK_LINE(126)
	::com::nodename::delaunay::Halfedge answer = this->_hash->__get(this->_minBucket)->nextInPriorityQueue;		HX_STACK_VAR(answer,"answer");
	HX_STACK_LINE(127)
	return ::neash::geom::Point_obj::__new(answer->vertex->_coord->x,answer->ystar);
}


HX_DEFINE_DYNAMIC_FUNC0(HalfedgePriorityQueue_obj,min,return )

bool HalfedgePriorityQueue_obj::empty( ){
	HX_STACK_PUSH("HalfedgePriorityQueue::empty","com/nodename/delaunay/HalfedgePriorityQueue.hx",115);
	HX_STACK_THIS(this);
	HX_STACK_LINE(115)
	return (this->_count == (int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(HalfedgePriorityQueue_obj,empty,return )

Void HalfedgePriorityQueue_obj::adjustMinBucket( ){
{
		HX_STACK_PUSH("HalfedgePriorityQueue::adjustMinBucket","com/nodename/delaunay/HalfedgePriorityQueue.hx",107);
		HX_STACK_THIS(this);
		HX_STACK_LINE(107)
		while(((bool((this->_minBucket < (this->_hashsize - (int)1))) && bool(this->isEmpty(this->_minBucket))))){
			HX_STACK_LINE(109)
			++(this->_minBucket);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HalfedgePriorityQueue_obj,adjustMinBucket,(void))

bool HalfedgePriorityQueue_obj::isEmpty( int bucket){
	HX_STACK_PUSH("HalfedgePriorityQueue::isEmpty","com/nodename/delaunay/HalfedgePriorityQueue.hx",98);
	HX_STACK_THIS(this);
	HX_STACK_ARG(bucket,"bucket");
	HX_STACK_LINE(98)
	return (this->_hash->__get(bucket)->nextInPriorityQueue == null());
}


HX_DEFINE_DYNAMIC_FUNC1(HalfedgePriorityQueue_obj,isEmpty,return )

int HalfedgePriorityQueue_obj::bucket( ::com::nodename::delaunay::Halfedge halfEdge){
	HX_STACK_PUSH("HalfedgePriorityQueue::bucket","com/nodename/delaunay/HalfedgePriorityQueue.hx",90);
	HX_STACK_THIS(this);
	HX_STACK_ARG(halfEdge,"halfEdge");
	HX_STACK_LINE(91)
	int theBucket = ::Std_obj::_int(((Float(((halfEdge->ystar - this->_ymin))) / Float(this->_deltay)) * this->_hashsize));		HX_STACK_VAR(theBucket,"theBucket");
	HX_STACK_LINE(92)
	if (((theBucket < (int)0))){
		HX_STACK_LINE(92)
		theBucket = (int)0;
	}
	HX_STACK_LINE(93)
	if (((theBucket >= this->_hashsize))){
		HX_STACK_LINE(93)
		theBucket = (this->_hashsize - (int)1);
	}
	HX_STACK_LINE(94)
	return theBucket;
}


HX_DEFINE_DYNAMIC_FUNC1(HalfedgePriorityQueue_obj,bucket,return )

Void HalfedgePriorityQueue_obj::remove( ::com::nodename::delaunay::Halfedge halfEdge){
{
		HX_STACK_PUSH("HalfedgePriorityQueue::remove","com/nodename/delaunay/HalfedgePriorityQueue.hx",70);
		HX_STACK_THIS(this);
		HX_STACK_ARG(halfEdge,"halfEdge");
		HX_STACK_LINE(71)
		::com::nodename::delaunay::Halfedge previous;		HX_STACK_VAR(previous,"previous");
		HX_STACK_LINE(72)
		int removalBucket = this->bucket(halfEdge);		HX_STACK_VAR(removalBucket,"removalBucket");
		HX_STACK_LINE(74)
		if (((halfEdge->vertex != null()))){
			HX_STACK_LINE(76)
			previous = this->_hash->__get(removalBucket);
			HX_STACK_LINE(77)
			while(((previous->nextInPriorityQueue != halfEdge))){
				HX_STACK_LINE(78)
				previous = previous->nextInPriorityQueue;
			}
			HX_STACK_LINE(81)
			previous->nextInPriorityQueue = halfEdge->nextInPriorityQueue;
			HX_STACK_LINE(82)
			(this->_count)--;
			HX_STACK_LINE(83)
			halfEdge->vertex = null();
			HX_STACK_LINE(84)
			halfEdge->nextInPriorityQueue = null();
			HX_STACK_LINE(85)
			halfEdge->dispose();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HalfedgePriorityQueue_obj,remove,(void))

Void HalfedgePriorityQueue_obj::insert( ::com::nodename::delaunay::Halfedge halfEdge){
{
		HX_STACK_PUSH("HalfedgePriorityQueue::insert","com/nodename/delaunay/HalfedgePriorityQueue.hx",51);
		HX_STACK_THIS(this);
		HX_STACK_ARG(halfEdge,"halfEdge");
		HX_STACK_LINE(52)
		::com::nodename::delaunay::Halfedge previous;		HX_STACK_VAR(previous,"previous");
		::com::nodename::delaunay::Halfedge next;		HX_STACK_VAR(next,"next");
		HX_STACK_LINE(53)
		int insertionBucket = this->bucket(halfEdge);		HX_STACK_VAR(insertionBucket,"insertionBucket");
		HX_STACK_LINE(54)
		if (((insertionBucket < this->_minBucket))){
			HX_STACK_LINE(55)
			this->_minBucket = insertionBucket;
		}
		HX_STACK_LINE(58)
		previous = this->_hash->__get(insertionBucket);
		HX_STACK_LINE(59)
		while(((bool(((next = previous->nextInPriorityQueue) != null())) && bool(((bool((halfEdge->ystar > next->ystar)) || bool((bool((halfEdge->ystar == next->ystar)) && bool((halfEdge->vertex->_coord->x > next->vertex->_coord->x)))))))))){
			HX_STACK_LINE(61)
			previous = next;
		}
		HX_STACK_LINE(64)
		halfEdge->nextInPriorityQueue = previous->nextInPriorityQueue;
		HX_STACK_LINE(65)
		previous->nextInPriorityQueue = halfEdge;
		HX_STACK_LINE(66)
		++(this->_count);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HalfedgePriorityQueue_obj,insert,(void))

Void HalfedgePriorityQueue_obj::initialize( ){
{
		HX_STACK_PUSH("HalfedgePriorityQueue::initialize","com/nodename/delaunay/HalfedgePriorityQueue.hx",36);
		HX_STACK_THIS(this);
		HX_STACK_LINE(37)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(39)
		this->_count = (int)0;
		HX_STACK_LINE(40)
		this->_minBucket = (int)0;
		HX_STACK_LINE(41)
		this->_hash = Array_obj< ::com::nodename::delaunay::Halfedge >::__new();
		HX_STACK_LINE(43)
		{
			HX_STACK_LINE(43)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->_hashsize;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(43)
			while(((_g1 < _g))){
				HX_STACK_LINE(43)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(45)
				this->_hash[i1] = ::com::nodename::delaunay::Halfedge_obj::createDummy();
				HX_STACK_LINE(46)
				this->_hash->__get(i1)->nextInPriorityQueue = null();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HalfedgePriorityQueue_obj,initialize,(void))

Void HalfedgePriorityQueue_obj::dispose( ){
{
		HX_STACK_PUSH("HalfedgePriorityQueue::dispose","com/nodename/delaunay/HalfedgePriorityQueue.hx",25);
		HX_STACK_THIS(this);
		HX_STACK_LINE(27)
		{
			HX_STACK_LINE(27)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->_hashsize;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(27)
			while(((_g1 < _g))){
				HX_STACK_LINE(27)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(29)
				this->_hash->__get(i)->dispose();
				HX_STACK_LINE(30)
				this->_hash[i] = null();
			}
		}
		HX_STACK_LINE(32)
		this->_hash = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HalfedgePriorityQueue_obj,dispose,(void))


HalfedgePriorityQueue_obj::HalfedgePriorityQueue_obj()
{
}

void HalfedgePriorityQueue_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HalfedgePriorityQueue);
	HX_MARK_MEMBER_NAME(_deltay,"_deltay");
	HX_MARK_MEMBER_NAME(_ymin,"_ymin");
	HX_MARK_MEMBER_NAME(_hashsize,"_hashsize");
	HX_MARK_MEMBER_NAME(_minBucket,"_minBucket");
	HX_MARK_MEMBER_NAME(_count,"_count");
	HX_MARK_MEMBER_NAME(_hash,"_hash");
	HX_MARK_END_CLASS();
}

void HalfedgePriorityQueue_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_deltay,"_deltay");
	HX_VISIT_MEMBER_NAME(_ymin,"_ymin");
	HX_VISIT_MEMBER_NAME(_hashsize,"_hashsize");
	HX_VISIT_MEMBER_NAME(_minBucket,"_minBucket");
	HX_VISIT_MEMBER_NAME(_count,"_count");
	HX_VISIT_MEMBER_NAME(_hash,"_hash");
}

Dynamic HalfedgePriorityQueue_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"min") ) { return min_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"empty") ) { return empty_dyn(); }
		if (HX_FIELD_EQ(inName,"_ymin") ) { return _ymin; }
		if (HX_FIELD_EQ(inName,"_hash") ) { return _hash; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bucket") ) { return bucket_dyn(); }
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		if (HX_FIELD_EQ(inName,"insert") ) { return insert_dyn(); }
		if (HX_FIELD_EQ(inName,"_count") ) { return _count; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isEmpty") ) { return isEmpty_dyn(); }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"_deltay") ) { return _deltay; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_hashsize") ) { return _hashsize; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"extractMin") ) { return extractMin_dyn(); }
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		if (HX_FIELD_EQ(inName,"_minBucket") ) { return _minBucket; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"adjustMinBucket") ) { return adjustMinBucket_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HalfedgePriorityQueue_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_ymin") ) { _ymin=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_hash") ) { _hash=inValue.Cast< Array< ::com::nodename::delaunay::Halfedge > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_count") ) { _count=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_deltay") ) { _deltay=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_hashsize") ) { _hashsize=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_minBucket") ) { _minBucket=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HalfedgePriorityQueue_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_deltay"));
	outFields->push(HX_CSTRING("_ymin"));
	outFields->push(HX_CSTRING("_hashsize"));
	outFields->push(HX_CSTRING("_minBucket"));
	outFields->push(HX_CSTRING("_count"));
	outFields->push(HX_CSTRING("_hash"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("extractMin"),
	HX_CSTRING("min"),
	HX_CSTRING("empty"),
	HX_CSTRING("adjustMinBucket"),
	HX_CSTRING("isEmpty"),
	HX_CSTRING("bucket"),
	HX_CSTRING("remove"),
	HX_CSTRING("insert"),
	HX_CSTRING("initialize"),
	HX_CSTRING("dispose"),
	HX_CSTRING("_deltay"),
	HX_CSTRING("_ymin"),
	HX_CSTRING("_hashsize"),
	HX_CSTRING("_minBucket"),
	HX_CSTRING("_count"),
	HX_CSTRING("_hash"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HalfedgePriorityQueue_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HalfedgePriorityQueue_obj::__mClass,"__mClass");
};

Class HalfedgePriorityQueue_obj::__mClass;

void HalfedgePriorityQueue_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.delaunay.HalfedgePriorityQueue"), hx::TCanCast< HalfedgePriorityQueue_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HalfedgePriorityQueue_obj::__boot()
{
}

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

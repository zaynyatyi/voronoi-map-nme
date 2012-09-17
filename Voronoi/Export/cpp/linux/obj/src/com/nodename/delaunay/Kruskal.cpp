#include <hxcpp.h>

#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Kruskal
#include <com/nodename/delaunay/Kruskal.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Node
#include <com/nodename/delaunay/Node.h>
#endif
#ifndef INCLUDED_com_nodename_geom_LineSegment
#include <com/nodename/geom/LineSegment.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
#ifndef INCLUDED_nme_ObjectHash
#include <nme/ObjectHash.h>
#endif
namespace com{
namespace nodename{
namespace delaunay{

Void Kruskal_obj::__construct()
{
	return null();
}

Kruskal_obj::~Kruskal_obj() { }

Dynamic Kruskal_obj::__CreateEmpty() { return  new Kruskal_obj; }
hx::ObjectPtr< Kruskal_obj > Kruskal_obj::__new()
{  hx::ObjectPtr< Kruskal_obj > result = new Kruskal_obj();
	result->__construct();
	return result;}

Dynamic Kruskal_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Kruskal_obj > result = new Kruskal_obj();
	result->__construct();
	return result;}

Array< ::com::nodename::geom::LineSegment > Kruskal_obj::kruskal( Array< ::com::nodename::geom::LineSegment > lineSegments,::String __o_type){
::String type = __o_type.Default(HX_CSTRING("minimum"));
	HX_STACK_PUSH("Kruskal::kruskal","com/nodename/delaunay/Kruskal.hx",18);
	HX_STACK_ARG(lineSegments,"lineSegments");
	HX_STACK_ARG(type,"type");
{
		HX_STACK_LINE(19)
		::nme::ObjectHash nodes = ::nme::ObjectHash_obj::__new();		HX_STACK_VAR(nodes,"nodes");
		HX_STACK_LINE(20)
		Array< ::com::nodename::geom::LineSegment > mst = Array_obj< ::com::nodename::geom::LineSegment >::__new();		HX_STACK_VAR(mst,"mst");
		HX_STACK_LINE(21)
		Array< ::com::nodename::delaunay::Node > nodePool = ::com::nodename::delaunay::Node_obj::pool;		HX_STACK_VAR(nodePool,"nodePool");
		HX_STACK_LINE(23)
		::String _switch_1 = (type);
		if (  ( _switch_1==HX_CSTRING("maximum"))){
			HX_STACK_LINE(27)
			lineSegments->sort(::com::nodename::geom::LineSegment_obj::compareLengths_dyn());
		}
		else  {
			HX_STACK_LINE(29)
			lineSegments->sort(::com::nodename::geom::LineSegment_obj::compareLengths_MAX_dyn());
		}
;
;
		HX_STACK_LINE(33)
		int i = (lineSegments->length - (int)1);		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(35)
		while(((i >= (int)0))){
			HX_STACK_LINE(37)
			::com::nodename::geom::LineSegment lineSegment = lineSegments->__get(i);		HX_STACK_VAR(lineSegment,"lineSegment");
			HX_STACK_LINE(38)
			(i)--;
			HX_STACK_LINE(40)
			::com::nodename::delaunay::Node node0 = nodes->hashValues->get(::__hxcpp_obj_id(lineSegment->p0));		HX_STACK_VAR(node0,"node0");
			HX_STACK_LINE(41)
			::com::nodename::delaunay::Node rootOfSet0;		HX_STACK_VAR(rootOfSet0,"rootOfSet0");
			HX_STACK_LINE(42)
			if (((node0 == null()))){
				HX_STACK_LINE(44)
				node0 = (  (((nodePool->length > (int)0))) ? ::com::nodename::delaunay::Node(nodePool->pop()) : ::com::nodename::delaunay::Node(::com::nodename::delaunay::Node_obj::__new()) );
				HX_STACK_LINE(46)
				rootOfSet0 = node0->parent = node0;
				HX_STACK_LINE(47)
				node0->treeSize = (int)1;
				HX_STACK_LINE(49)
				{
					HX_STACK_LINE(49)
					::neash::geom::Point key = lineSegment->p0;		HX_STACK_VAR(key,"key");
					HX_STACK_LINE(49)
					int id = ::__hxcpp_obj_id(key);		HX_STACK_VAR(id,"id");
					HX_STACK_LINE(49)
					nodes->hashKeys->set(id,key);
					HX_STACK_LINE(49)
					nodes->hashValues->set(id,node0);
				}
			}
			else{
				HX_STACK_LINE(52)
				rootOfSet0 = ::com::nodename::delaunay::Kruskal_obj::find(node0);
			}
			HX_STACK_LINE(56)
			::com::nodename::delaunay::Node node1 = nodes->hashValues->get(::__hxcpp_obj_id(lineSegment->p1));		HX_STACK_VAR(node1,"node1");
			HX_STACK_LINE(57)
			::com::nodename::delaunay::Node rootOfSet1;		HX_STACK_VAR(rootOfSet1,"rootOfSet1");
			HX_STACK_LINE(58)
			if (((node1 == null()))){
				HX_STACK_LINE(60)
				node1 = (  (((nodePool->length > (int)0))) ? ::com::nodename::delaunay::Node(nodePool->pop()) : ::com::nodename::delaunay::Node(::com::nodename::delaunay::Node_obj::__new()) );
				HX_STACK_LINE(62)
				rootOfSet1 = node1->parent = node1;
				HX_STACK_LINE(63)
				node1->treeSize = (int)1;
				HX_STACK_LINE(65)
				{
					HX_STACK_LINE(65)
					::neash::geom::Point key = lineSegment->p1;		HX_STACK_VAR(key,"key");
					HX_STACK_LINE(65)
					int id = ::__hxcpp_obj_id(key);		HX_STACK_VAR(id,"id");
					HX_STACK_LINE(65)
					nodes->hashKeys->set(id,key);
					HX_STACK_LINE(65)
					nodes->hashValues->set(id,node1);
				}
			}
			else{
				HX_STACK_LINE(68)
				rootOfSet1 = ::com::nodename::delaunay::Kruskal_obj::find(node1);
			}
			HX_STACK_LINE(72)
			if (((rootOfSet0 != rootOfSet1))){
				HX_STACK_LINE(74)
				mst->push(lineSegment);
				HX_STACK_LINE(77)
				int treeSize0 = rootOfSet0->treeSize;		HX_STACK_VAR(treeSize0,"treeSize0");
				HX_STACK_LINE(78)
				int treeSize1 = rootOfSet1->treeSize;		HX_STACK_VAR(treeSize1,"treeSize1");
				HX_STACK_LINE(79)
				if (((treeSize0 >= treeSize1))){
					HX_STACK_LINE(82)
					rootOfSet1->parent = rootOfSet0;
					HX_STACK_LINE(83)
					hx::AddEq(rootOfSet0->treeSize,treeSize1);
				}
				else{
					HX_STACK_LINE(88)
					rootOfSet0->parent = rootOfSet1;
					HX_STACK_LINE(89)
					hx::AddEq(rootOfSet1->treeSize,treeSize0);
				}
			}
		}
		HX_STACK_LINE(94)
		for(::cpp::FastIterator_obj< ::com::nodename::delaunay::Node > *__it = ::cpp::CreateFastIterator< ::com::nodename::delaunay::Node >(nodes->hashValues->iterator());  __it->hasNext(); ){
			::com::nodename::delaunay::Node node = __it->next();
			nodePool->push(node);
		}
		HX_STACK_LINE(99)
		return mst;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Kruskal_obj,kruskal,return )

::com::nodename::delaunay::Node Kruskal_obj::find( ::com::nodename::delaunay::Node node){
	HX_STACK_PUSH("Kruskal::find","com/nodename/delaunay/Kruskal.hx",103);
	HX_STACK_ARG(node,"node");
	HX_STACK_LINE(103)
	if (((node->parent == node))){
		HX_STACK_LINE(105)
		return node;
	}
	else{
		HX_STACK_LINE(110)
		::com::nodename::delaunay::Node root = ::com::nodename::delaunay::Kruskal_obj::find(node->parent);		HX_STACK_VAR(root,"root");
		HX_STACK_LINE(112)
		node->parent = root;
		HX_STACK_LINE(113)
		return root;
	}
	HX_STACK_LINE(103)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Kruskal_obj,find,return )


Kruskal_obj::Kruskal_obj()
{
}

void Kruskal_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Kruskal);
	HX_MARK_END_CLASS();
}

void Kruskal_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Kruskal_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"find") ) { return find_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"kruskal") ) { return kruskal_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Kruskal_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Kruskal_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("kruskal"),
	HX_CSTRING("find"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Kruskal_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Kruskal_obj::__mClass,"__mClass");
};

Class Kruskal_obj::__mClass;

void Kruskal_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.delaunay.Kruskal"), hx::TCanCast< Kruskal_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Kruskal_obj::__boot()
{
}

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

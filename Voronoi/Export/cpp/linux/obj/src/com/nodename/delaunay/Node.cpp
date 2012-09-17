#include <hxcpp.h>

#ifndef INCLUDED_com_nodename_delaunay_Node
#include <com/nodename/delaunay/Node.h>
#endif
namespace com{
namespace nodename{
namespace delaunay{

Void Node_obj::__construct()
{
HX_STACK_PUSH("Node::new","com/nodename/delaunay/Node.hx",9);
{
}
;
	return null();
}

Node_obj::~Node_obj() { }

Dynamic Node_obj::__CreateEmpty() { return  new Node_obj; }
hx::ObjectPtr< Node_obj > Node_obj::__new()
{  hx::ObjectPtr< Node_obj > result = new Node_obj();
	result->__construct();
	return result;}

Dynamic Node_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Node_obj > result = new Node_obj();
	result->__construct();
	return result;}

Array< ::com::nodename::delaunay::Node > Node_obj::pool;


Node_obj::Node_obj()
{
}

void Node_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Node);
	HX_MARK_MEMBER_NAME(treeSize,"treeSize");
	HX_MARK_MEMBER_NAME(parent,"parent");
	HX_MARK_END_CLASS();
}

void Node_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(treeSize,"treeSize");
	HX_VISIT_MEMBER_NAME(parent,"parent");
}

Dynamic Node_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"pool") ) { return pool; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"parent") ) { return parent; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"treeSize") ) { return treeSize; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Node_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"pool") ) { pool=inValue.Cast< Array< ::com::nodename::delaunay::Node > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"parent") ) { parent=inValue.Cast< ::com::nodename::delaunay::Node >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"treeSize") ) { treeSize=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Node_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("treeSize"));
	outFields->push(HX_CSTRING("parent"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("pool"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("treeSize"),
	HX_CSTRING("parent"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Node_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Node_obj::pool,"pool");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Node_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Node_obj::pool,"pool");
};

Class Node_obj::__mClass;

void Node_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.delaunay.Node"), hx::TCanCast< Node_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Node_obj::__boot()
{
	pool= Array_obj< ::com::nodename::delaunay::Node >::__new();
}

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#ifndef INCLUDED_com_nodename_delaunay_Node
#define INCLUDED_com_nodename_delaunay_Node

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,nodename,delaunay,Node)
namespace com{
namespace nodename{
namespace delaunay{


class Node_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Node_obj OBJ_;
		Node_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Node_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Node_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Node"); }

		int treeSize; /* REM */ 
		::com::nodename::delaunay::Node parent; /* REM */ 
		static Array< ::com::nodename::delaunay::Node > pool; /* REM */ 
};

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#endif /* INCLUDED_com_nodename_delaunay_Node */ 

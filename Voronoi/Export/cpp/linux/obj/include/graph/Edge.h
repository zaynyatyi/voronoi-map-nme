#ifndef INCLUDED_graph_Edge
#define INCLUDED_graph_Edge

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(graph,Center)
HX_DECLARE_CLASS1(graph,Corner)
HX_DECLARE_CLASS1(graph,Edge)
HX_DECLARE_CLASS2(neash,geom,Point)
namespace graph{


class Edge_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Edge_obj OBJ_;
		Edge_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Edge_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Edge_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Edge"); }

		int river; /* REM */ 
		::neash::geom::Point midpoint; /* REM */ 
		::graph::Corner v1; /* REM */ 
		::graph::Corner v0; /* REM */ 
		::graph::Center d1; /* REM */ 
		::graph::Center d0; /* REM */ 
		int index; /* REM */ 
};

} // end namespace graph

#endif /* INCLUDED_graph_Edge */ 

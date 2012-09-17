#ifndef INCLUDED_graph_Corner
#define INCLUDED_graph_Corner

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(graph,Center)
HX_DECLARE_CLASS1(graph,Corner)
HX_DECLARE_CLASS1(graph,Edge)
HX_DECLARE_CLASS2(neash,geom,Point)
namespace graph{


class Corner_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Corner_obj OBJ_;
		Corner_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Corner_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Corner_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Corner"); }

		int watershed_size; /* REM */ 
		::graph::Corner watershed; /* REM */ 
		::graph::Corner downslope; /* REM */ 
		int river; /* REM */ 
		Array< ::graph::Corner > adjacent; /* REM */ 
		Array< ::graph::Edge > protrudes; /* REM */ 
		Array< ::graph::Center > touches; /* REM */ 
		Float moisture; /* REM */ 
		Float elevation; /* REM */ 
		bool border; /* REM */ 
		bool coast; /* REM */ 
		bool water; /* REM */ 
		bool ocean; /* REM */ 
		::neash::geom::Point point; /* REM */ 
		int index; /* REM */ 
};

} // end namespace graph

#endif /* INCLUDED_graph_Corner */ 

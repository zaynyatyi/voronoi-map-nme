#ifndef INCLUDED_graph_Center
#define INCLUDED_graph_Center

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(graph,Center)
HX_DECLARE_CLASS1(graph,Corner)
HX_DECLARE_CLASS1(graph,Edge)
HX_DECLARE_CLASS2(neash,geom,Point)
namespace graph{


class Center_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Center_obj OBJ_;
		Center_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Center_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Center_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Center"); }

		Array< ::graph::Corner > corners; /* REM */ 
		Array< ::graph::Edge > borders; /* REM */ 
		Array< ::graph::Center > neighbors; /* REM */ 
		Float moisture; /* REM */ 
		Float elevation; /* REM */ 
		::String biome; /* REM */ 
		bool border; /* REM */ 
		bool coast; /* REM */ 
		bool ocean; /* REM */ 
		bool water; /* REM */ 
		::neash::geom::Point point; /* REM */ 
		int index; /* REM */ 
};

} // end namespace graph

#endif /* INCLUDED_graph_Center */ 

#ifndef INCLUDED_com_nodename_delaunay_Halfedge
#define INCLUDED_com_nodename_delaunay_Halfedge

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,nodename,delaunay,Edge)
HX_DECLARE_CLASS3(com,nodename,delaunay,Halfedge)
HX_DECLARE_CLASS3(com,nodename,delaunay,ICoord)
HX_DECLARE_CLASS3(com,nodename,delaunay,LR)
HX_DECLARE_CLASS3(com,nodename,delaunay,Vertex)
HX_DECLARE_CLASS2(neash,geom,Point)
namespace com{
namespace nodename{
namespace delaunay{


class Halfedge_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Halfedge_obj OBJ_;
		Halfedge_obj();
		Void __construct(::com::nodename::delaunay::Edge edge,::com::nodename::delaunay::LR lr);

	public:
		static hx::ObjectPtr< Halfedge_obj > __new(::com::nodename::delaunay::Edge edge,::com::nodename::delaunay::LR lr);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Halfedge_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Halfedge"); }

		virtual bool isLeftOf( ::neash::geom::Point p);
		Dynamic isLeftOf_dyn();

		virtual Void reallyDispose( );
		Dynamic reallyDispose_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual ::com::nodename::delaunay::Halfedge init( ::com::nodename::delaunay::Edge edge,::com::nodename::delaunay::LR lr);
		Dynamic init_dyn();

		Float ystar; /* REM */ 
		::com::nodename::delaunay::Vertex vertex; /* REM */ 
		::com::nodename::delaunay::LR leftRight; /* REM */ 
		::com::nodename::delaunay::Edge edge; /* REM */ 
		::com::nodename::delaunay::Halfedge nextInPriorityQueue; /* REM */ 
		::com::nodename::delaunay::Halfedge edgeListRightNeighbor; /* REM */ 
		::com::nodename::delaunay::Halfedge edgeListLeftNeighbor; /* REM */ 
		static Array< ::com::nodename::delaunay::Halfedge > _pool; /* REM */ 
		static ::com::nodename::delaunay::Halfedge create( ::com::nodename::delaunay::Edge edge,::com::nodename::delaunay::LR lr);
		static Dynamic create_dyn();

		static ::com::nodename::delaunay::Halfedge createDummy( );
		static Dynamic createDummy_dyn();

};

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#endif /* INCLUDED_com_nodename_delaunay_Halfedge */ 

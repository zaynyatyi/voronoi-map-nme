#ifndef INCLUDED_com_nodename_delaunay_Edge
#define INCLUDED_com_nodename_delaunay_Edge

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS3(com,nodename,delaunay,Edge)
HX_DECLARE_CLASS3(com,nodename,delaunay,ICoord)
HX_DECLARE_CLASS3(com,nodename,delaunay,LR)
HX_DECLARE_CLASS3(com,nodename,delaunay,Site)
HX_DECLARE_CLASS3(com,nodename,delaunay,Vertex)
HX_DECLARE_CLASS3(com,nodename,geom,LineSegment)
HX_DECLARE_CLASS2(neash,display,BitmapData)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,Graphics)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,geom,Rectangle)
namespace com{
namespace nodename{
namespace delaunay{


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

		virtual Void clipVertices( ::neash::geom::Rectangle bounds);
		Dynamic clipVertices_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Void init( );
		Dynamic init_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		int _edgeIndex; /* REM */ 
		virtual ::com::nodename::delaunay::Site site( ::com::nodename::delaunay::LR leftRight);
		Dynamic site_dyn();

		::com::nodename::delaunay::Site rightSite; /* REM */ 
		::com::nodename::delaunay::Site leftSite; /* REM */ 
		virtual bool getVisible( );
		Dynamic getVisible_dyn();

		bool visible; /* REM */ 
		::Hash clippedEnds; /* REM */ 
		virtual Float sitesDistance( );
		Dynamic sitesDistance_dyn();

		virtual bool isPartOfConvexHull( );
		Dynamic isPartOfConvexHull_dyn();

		virtual Void setVertex( ::com::nodename::delaunay::LR leftRight,::com::nodename::delaunay::Vertex v);
		Dynamic setVertex_dyn();

		virtual ::com::nodename::delaunay::Vertex vertex( ::com::nodename::delaunay::LR leftRight);
		Dynamic vertex_dyn();

		::com::nodename::delaunay::Vertex rightVertex; /* REM */ 
		::com::nodename::delaunay::Vertex leftVertex; /* REM */ 
		Float c; /* REM */ 
		Float b; /* REM */ 
		Float a; /* REM */ 
		virtual ::com::nodename::geom::LineSegment voronoiEdge( );
		Dynamic voronoiEdge_dyn();

		virtual ::com::nodename::geom::LineSegment delaunayLine( );
		Dynamic delaunayLine_dyn();

		virtual ::neash::display::BitmapData makeDelaunayLineBmp( );
		Dynamic makeDelaunayLineBmp_dyn();

		virtual ::neash::display::BitmapData getDelaunayLineBmp( );
		Dynamic getDelaunayLineBmp_dyn();

		::neash::display::BitmapData _delaunayLineBmp; /* REM */ 
		::neash::display::BitmapData delaunayLineBmp; /* REM */ 
		static Array< ::com::nodename::delaunay::Edge > _pool; /* REM */ 
		static ::com::nodename::delaunay::Edge createBisectingEdge( ::com::nodename::delaunay::Site site0,::com::nodename::delaunay::Site site1);
		static Dynamic createBisectingEdge_dyn();

		static ::com::nodename::delaunay::Edge create( );
		static Dynamic create_dyn();

		static ::neash::display::Sprite LINESPRITE; /* REM */ 
		static ::neash::display::Graphics GRAPHICS; /* REM */ 
		static int _nedges; /* REM */ 
		static ::com::nodename::delaunay::Edge DELETED; /* REM */ 
		static int compareSitesDistances_MAX( ::com::nodename::delaunay::Edge edge0,::com::nodename::delaunay::Edge edge1);
		static Dynamic compareSitesDistances_MAX_dyn();

		static int compareSitesDistances( ::com::nodename::delaunay::Edge edge0,::com::nodename::delaunay::Edge edge1);
		static Dynamic compareSitesDistances_dyn();

};

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#endif /* INCLUDED_com_nodename_delaunay_Edge */ 

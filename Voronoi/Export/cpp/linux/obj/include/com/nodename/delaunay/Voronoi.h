#ifndef INCLUDED_com_nodename_delaunay_Voronoi
#define INCLUDED_com_nodename_delaunay_Voronoi

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,nodename,delaunay,Edge)
HX_DECLARE_CLASS3(com,nodename,delaunay,ICoord)
HX_DECLARE_CLASS3(com,nodename,delaunay,Site)
HX_DECLARE_CLASS3(com,nodename,delaunay,SiteList)
HX_DECLARE_CLASS3(com,nodename,delaunay,Triangle)
HX_DECLARE_CLASS3(com,nodename,delaunay,Voronoi)
HX_DECLARE_CLASS3(com,nodename,geom,Circle)
HX_DECLARE_CLASS3(com,nodename,geom,LineSegment)
HX_DECLARE_CLASS3(com,nodename,utils,IDisposable)
HX_DECLARE_CLASS3(de,polygonal,math,PM_PRNG)
HX_DECLARE_CLASS2(neash,display,BitmapData)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,geom,Point)
HX_DECLARE_CLASS2(neash,geom,Rectangle)
HX_DECLARE_CLASS1(nme,ObjectHash)
namespace com{
namespace nodename{
namespace delaunay{


class Voronoi_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Voronoi_obj OBJ_;
		Voronoi_obj();
		Void __construct(Array< ::neash::geom::Point > points,Array< int > colors,::neash::geom::Rectangle plotBounds);

	public:
		static hx::ObjectPtr< Voronoi_obj > __new(Array< ::neash::geom::Point > points,Array< int > colors,::neash::geom::Rectangle plotBounds);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Voronoi_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Voronoi"); }

		virtual Void fortunesAlgorithm( );
		Dynamic fortunesAlgorithm_dyn();

		virtual Array< ::neash::geom::Point > siteCoords( );
		Dynamic siteCoords_dyn();

		virtual ::neash::geom::Point nearestSitePoint( ::neash::display::BitmapData proximityMap,int x,int y);
		Dynamic nearestSitePoint_dyn();

		virtual Array< int > siteColors( ::neash::display::BitmapData referenceImage);
		Dynamic siteColors_dyn();

		virtual Array< Array< ::neash::geom::Point > > regions( );
		Dynamic regions_dyn();

		virtual Array< ::com::nodename::geom::LineSegment > spanningTree( ::String type,::neash::display::BitmapData keepOutMask);
		Dynamic spanningTree_dyn();

		virtual Array< ::neash::geom::Point > hullPointsInOrder( );
		Dynamic hullPointsInOrder_dyn();

		virtual Array< ::com::nodename::delaunay::Edge > hullEdges( );
		Dynamic hullEdges_dyn();

		virtual Array< ::com::nodename::geom::LineSegment > hull( );
		Dynamic hull_dyn();

		virtual Array< ::com::nodename::geom::LineSegment > delaunayTriangulation( ::neash::display::BitmapData keepOutMask);
		Dynamic delaunayTriangulation_dyn();

		virtual Array< ::com::nodename::geom::LineSegment > voronoiDiagram( );
		Dynamic voronoiDiagram_dyn();

		virtual Array< ::com::nodename::geom::LineSegment > delaunayLinesForSite( ::neash::geom::Point coord);
		Dynamic delaunayLinesForSite_dyn();

		virtual Array< ::com::nodename::geom::LineSegment > voronoiBoundaryForSite( ::neash::geom::Point coord);
		Dynamic voronoiBoundaryForSite_dyn();

		virtual Array< ::com::nodename::geom::Circle > circles( );
		Dynamic circles_dyn();

		virtual Array< ::neash::geom::Point > neighborSitesForSite( ::neash::geom::Point coord);
		Dynamic neighborSitesForSite_dyn();

		virtual Array< ::neash::geom::Point > region( ::neash::geom::Point p);
		Dynamic region_dyn();

		virtual Array< ::com::nodename::delaunay::Edge > edges( );
		Dynamic edges_dyn();

		virtual Void addSite( ::neash::geom::Point p,int color,int index);
		Dynamic addSite_dyn();

		virtual Void addSites( Array< ::neash::geom::Point > points,Array< int > colors);
		Dynamic addSites_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		::neash::geom::Rectangle plotBounds; /* REM */ 
		Array< ::com::nodename::delaunay::Edge > _edges; /* REM */ 
		Array< ::com::nodename::delaunay::Triangle > _triangles; /* REM */ 
		::nme::ObjectHash _sitesIndexedByLocation; /* REM */ 
		::com::nodename::delaunay::SiteList _sites; /* REM */ 
		::de::polygonal::math::PM_PRNG _prng; /* REM */ 
		static bool isInfSite( ::com::nodename::delaunay::Site s1,::com::nodename::delaunay::Site s2);
		static Dynamic isInfSite_dyn();

		static int comparePointByYThenX( ::com::nodename::delaunay::Site s1,::neash::geom::Point s2);
		static Dynamic comparePointByYThenX_dyn();

		static int compareSiteByYThenX( ::com::nodename::delaunay::Site s1,::com::nodename::delaunay::Site s2);
		static Dynamic compareSiteByYThenX_dyn();

		static int compareByYThenX( Float s1x,Float s1y,Float s2x,Float s2y);
		static Dynamic compareByYThenX_dyn();

};

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#endif /* INCLUDED_com_nodename_delaunay_Voronoi */ 

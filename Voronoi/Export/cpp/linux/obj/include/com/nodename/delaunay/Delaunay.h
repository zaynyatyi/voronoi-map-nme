#ifndef INCLUDED_com_nodename_delaunay_Delaunay
#define INCLUDED_com_nodename_delaunay_Delaunay

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,nodename,delaunay,Delaunay)
HX_DECLARE_CLASS3(com,nodename,delaunay,Edge)
HX_DECLARE_CLASS3(com,nodename,geom,LineSegment)
HX_DECLARE_CLASS2(neash,display,BitmapData)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,geom,Point)
namespace com{
namespace nodename{
namespace delaunay{


class Delaunay_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Delaunay_obj OBJ_;
		Delaunay_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Delaunay_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Delaunay_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Delaunay"); }

		static Array< ::com::nodename::geom::LineSegment > delaunayLinesForEdges( Array< ::com::nodename::delaunay::Edge > edges);
		static Dynamic delaunayLinesForEdges_dyn();

		static Array< ::com::nodename::delaunay::Edge > selectEdgesForSitePoint( ::neash::geom::Point coord,Array< ::com::nodename::delaunay::Edge > edgesToTest);
		static Dynamic selectEdgesForSitePoint_dyn();

		static Array< ::com::nodename::delaunay::Edge > selectNonIntersectingEdges( ::neash::display::BitmapData keepOutMask,Array< ::com::nodename::delaunay::Edge > edgesToTest);
		static Dynamic selectNonIntersectingEdges_dyn();

		static Array< ::com::nodename::geom::LineSegment > visibleLineSegments( Array< ::com::nodename::delaunay::Edge > edges);
		static Dynamic visibleLineSegments_dyn();

};

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#endif /* INCLUDED_com_nodename_delaunay_Delaunay */ 

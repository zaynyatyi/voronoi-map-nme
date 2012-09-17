#ifndef INCLUDED_com_nodename_geom_LineSegment
#define INCLUDED_com_nodename_geom_LineSegment

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,nodename,geom,LineSegment)
HX_DECLARE_CLASS2(neash,geom,Point)
namespace com{
namespace nodename{
namespace geom{


class LineSegment_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef LineSegment_obj OBJ_;
		LineSegment_obj();
		Void __construct(::neash::geom::Point p0,::neash::geom::Point p1);

	public:
		static hx::ObjectPtr< LineSegment_obj > __new(::neash::geom::Point p0,::neash::geom::Point p1);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~LineSegment_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("LineSegment"); }

		::neash::geom::Point p1; /* REM */ 
		::neash::geom::Point p0; /* REM */ 
		static int compareLengths_MAX( ::com::nodename::geom::LineSegment segment0,::com::nodename::geom::LineSegment segment1);
		static Dynamic compareLengths_MAX_dyn();

		static int compareLengths( ::com::nodename::geom::LineSegment edge0,::com::nodename::geom::LineSegment edge1);
		static Dynamic compareLengths_dyn();

};

} // end namespace com
} // end namespace nodename
} // end namespace geom

#endif /* INCLUDED_com_nodename_geom_LineSegment */ 

#ifndef INCLUDED_com_nodename_delaunay_Kruskal
#define INCLUDED_com_nodename_delaunay_Kruskal

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,nodename,delaunay,Kruskal)
HX_DECLARE_CLASS3(com,nodename,delaunay,Node)
HX_DECLARE_CLASS3(com,nodename,geom,LineSegment)
namespace com{
namespace nodename{
namespace delaunay{


class Kruskal_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Kruskal_obj OBJ_;
		Kruskal_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Kruskal_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Kruskal_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Kruskal"); }

		static Array< ::com::nodename::geom::LineSegment > kruskal( Array< ::com::nodename::geom::LineSegment > lineSegments,::String type);
		static Dynamic kruskal_dyn();

		static ::com::nodename::delaunay::Node find( ::com::nodename::delaunay::Node node);
		static Dynamic find_dyn();

};

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#endif /* INCLUDED_com_nodename_delaunay_Kruskal */ 

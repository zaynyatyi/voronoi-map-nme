#ifndef INCLUDED_com_nodename_delaunay_EdgeReorderer
#define INCLUDED_com_nodename_delaunay_EdgeReorderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,nodename,delaunay,Criterion)
HX_DECLARE_CLASS3(com,nodename,delaunay,Edge)
HX_DECLARE_CLASS3(com,nodename,delaunay,EdgeReorderer)
HX_DECLARE_CLASS3(com,nodename,delaunay,LR)
namespace com{
namespace nodename{
namespace delaunay{


class EdgeReorderer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EdgeReorderer_obj OBJ_;
		EdgeReorderer_obj();
		Void __construct(Array< ::com::nodename::delaunay::Edge > origEdges,::com::nodename::delaunay::Criterion criterion);

	public:
		static hx::ObjectPtr< EdgeReorderer_obj > __new(Array< ::com::nodename::delaunay::Edge > origEdges,::com::nodename::delaunay::Criterion criterion);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EdgeReorderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EdgeReorderer"); }

		virtual Array< ::com::nodename::delaunay::Edge > reorderEdges( Array< ::com::nodename::delaunay::Edge > origEdges,::com::nodename::delaunay::Criterion criterion);
		Dynamic reorderEdges_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		Array< ::com::nodename::delaunay::LR > edgeOrientations; /* REM */ 
		Array< ::com::nodename::delaunay::Edge > edges; /* REM */ 
};

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#endif /* INCLUDED_com_nodename_delaunay_EdgeReorderer */ 

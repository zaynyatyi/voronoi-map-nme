#ifndef INCLUDED_com_nodename_delaunay_Triangle
#define INCLUDED_com_nodename_delaunay_Triangle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,nodename,delaunay,ICoord)
HX_DECLARE_CLASS3(com,nodename,delaunay,Site)
HX_DECLARE_CLASS3(com,nodename,delaunay,Triangle)
namespace com{
namespace nodename{
namespace delaunay{


class Triangle_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Triangle_obj OBJ_;
		Triangle_obj();
		Void __construct(::com::nodename::delaunay::Site a,::com::nodename::delaunay::Site b,::com::nodename::delaunay::Site c);

	public:
		static hx::ObjectPtr< Triangle_obj > __new(::com::nodename::delaunay::Site a,::com::nodename::delaunay::Site b,::com::nodename::delaunay::Site c);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Triangle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Triangle"); }

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Array< ::com::nodename::delaunay::Site > get_sites( );
		Dynamic get_sites_dyn();

		Array< ::com::nodename::delaunay::Site > sites; /* REM */ 
		Array< ::com::nodename::delaunay::Site > _sites; /* REM */ 
};

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#endif /* INCLUDED_com_nodename_delaunay_Triangle */ 

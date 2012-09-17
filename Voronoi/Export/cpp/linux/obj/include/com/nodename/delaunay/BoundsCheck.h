#ifndef INCLUDED_com_nodename_delaunay_BoundsCheck
#define INCLUDED_com_nodename_delaunay_BoundsCheck

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,nodename,delaunay,BoundsCheck)
HX_DECLARE_CLASS2(neash,geom,Point)
HX_DECLARE_CLASS2(neash,geom,Rectangle)
namespace com{
namespace nodename{
namespace delaunay{


class BoundsCheck_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BoundsCheck_obj OBJ_;
		BoundsCheck_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< BoundsCheck_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BoundsCheck_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BoundsCheck"); }

		static int TOP; /* REM */ 
		static int BOTTOM; /* REM */ 
		static int LEFT; /* REM */ 
		static int RIGHT; /* REM */ 
		static int check( ::neash::geom::Point point,::neash::geom::Rectangle bounds);
		static Dynamic check_dyn();

};

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#endif /* INCLUDED_com_nodename_delaunay_BoundsCheck */ 

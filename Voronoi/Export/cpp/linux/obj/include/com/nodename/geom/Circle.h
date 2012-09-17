#ifndef INCLUDED_com_nodename_geom_Circle
#define INCLUDED_com_nodename_geom_Circle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,nodename,geom,Circle)
HX_DECLARE_CLASS2(neash,geom,Point)
namespace com{
namespace nodename{
namespace geom{


class Circle_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Circle_obj OBJ_;
		Circle_obj();
		Void __construct(Float centerX,Float centerY,Float radius);

	public:
		static hx::ObjectPtr< Circle_obj > __new(Float centerX,Float centerY,Float radius);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Circle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Circle"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

		Float radius; /* REM */ 
		::neash::geom::Point center; /* REM */ 
};

} // end namespace com
} // end namespace nodename
} // end namespace geom

#endif /* INCLUDED_com_nodename_geom_Circle */ 

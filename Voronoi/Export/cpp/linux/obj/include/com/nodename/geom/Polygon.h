#ifndef INCLUDED_com_nodename_geom_Polygon
#define INCLUDED_com_nodename_geom_Polygon

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,nodename,geom,Polygon)
HX_DECLARE_CLASS3(com,nodename,geom,Winding)
HX_DECLARE_CLASS2(neash,geom,Point)
namespace com{
namespace nodename{
namespace geom{


class Polygon_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Polygon_obj OBJ_;
		Polygon_obj();
		Void __construct(Array< ::neash::geom::Point > vertices);

	public:
		static hx::ObjectPtr< Polygon_obj > __new(Array< ::neash::geom::Point > vertices);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Polygon_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Polygon"); }

		virtual Float signedDoubleArea( );
		Dynamic signedDoubleArea_dyn();

		virtual ::com::nodename::geom::Winding winding( );
		Dynamic winding_dyn();

		virtual Float area( );
		Dynamic area_dyn();

		Array< ::neash::geom::Point > _vertices; /* REM */ 
};

} // end namespace com
} // end namespace nodename
} // end namespace geom

#endif /* INCLUDED_com_nodename_geom_Polygon */ 

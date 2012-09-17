#ifndef INCLUDED_com_nodename_geom_Winding
#define INCLUDED_com_nodename_geom_Winding

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,nodename,geom,Winding)
namespace com{
namespace nodename{
namespace geom{


class Winding_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Winding_obj OBJ_;
		Winding_obj();
		Void __construct(::String name);

	public:
		static hx::ObjectPtr< Winding_obj > __new(::String name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Winding_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Winding"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

		::String _name; /* REM */ 
		static ::com::nodename::geom::Winding CLOCKWISE; /* REM */ 
		static ::com::nodename::geom::Winding COUNTERCLOCKWISE; /* REM */ 
		static ::com::nodename::geom::Winding NONE; /* REM */ 
};

} // end namespace com
} // end namespace nodename
} // end namespace geom

#endif /* INCLUDED_com_nodename_geom_Winding */ 

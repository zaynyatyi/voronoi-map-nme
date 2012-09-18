#ifndef INCLUDED_neash_geom_Vector3D
#define INCLUDED_neash_geom_Vector3D

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,geom,Vector3D)
namespace neash{
namespace geom{


class Vector3D_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Vector3D_obj OBJ_;
		Vector3D_obj();
		Void __construct(Dynamic __o_x,Dynamic __o_y,Dynamic __o_z,Dynamic __o_w);

	public:
		static hx::ObjectPtr< Vector3D_obj > __new(Dynamic __o_x,Dynamic __o_y,Dynamic __o_z,Dynamic __o_w);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Vector3D_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Vector3D"); }

		virtual Float nmeGetLengthSquared( );
		Dynamic nmeGetLengthSquared_dyn();

		virtual Float nmeGetLength( );
		Dynamic nmeGetLength_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual ::neash::geom::Vector3D subtract( ::neash::geom::Vector3D a);
		Dynamic subtract_dyn();

		virtual Void scaleBy( Float s);
		Dynamic scaleBy_dyn();

		virtual Void project( );
		Dynamic project_dyn();

		virtual Float normalize( );
		Dynamic normalize_dyn();

		virtual Void negate( );
		Dynamic negate_dyn();

		virtual bool nearEquals( ::neash::geom::Vector3D toCompare,Float tolerance,Dynamic allFour);
		Dynamic nearEquals_dyn();

		virtual Void incrementBy( ::neash::geom::Vector3D a);
		Dynamic incrementBy_dyn();

		virtual bool equals( ::neash::geom::Vector3D toCompare,Dynamic allFour);
		Dynamic equals_dyn();

		virtual Float dotProduct( ::neash::geom::Vector3D a);
		Dynamic dotProduct_dyn();

		virtual Void decrementBy( ::neash::geom::Vector3D a);
		Dynamic decrementBy_dyn();

		virtual ::neash::geom::Vector3D crossProduct( ::neash::geom::Vector3D a);
		Dynamic crossProduct_dyn();

		virtual ::neash::geom::Vector3D clone( );
		Dynamic clone_dyn();

		virtual ::neash::geom::Vector3D add( ::neash::geom::Vector3D a);
		Dynamic add_dyn();

		Float z; /* REM */ 
		Float y; /* REM */ 
		Float x; /* REM */ 
		Float w; /* REM */ 
		Float lengthSquared; /* REM */ 
		Float length; /* REM */ 
		static ::neash::geom::Vector3D X_AXIS; /* REM */ 
		static ::neash::geom::Vector3D Y_AXIS; /* REM */ 
		static ::neash::geom::Vector3D Z_AXIS; /* REM */ 
		static Float angleBetween( ::neash::geom::Vector3D a,::neash::geom::Vector3D b);
		static Dynamic angleBetween_dyn();

		static Float distance( ::neash::geom::Vector3D pt1,::neash::geom::Vector3D pt2);
		static Dynamic distance_dyn();

		static ::neash::geom::Vector3D nmeGetX_AXIS( );
		static Dynamic nmeGetX_AXIS_dyn();

		static ::neash::geom::Vector3D nmeGetY_AXIS( );
		static Dynamic nmeGetY_AXIS_dyn();

		static ::neash::geom::Vector3D nmeGetZ_AXIS( );
		static Dynamic nmeGetZ_AXIS_dyn();

};

} // end namespace neash
} // end namespace geom

#endif /* INCLUDED_neash_geom_Vector3D */ 

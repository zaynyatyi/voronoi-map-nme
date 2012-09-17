#ifndef INCLUDED_com_nodename_delaunay_LR
#define INCLUDED_com_nodename_delaunay_LR

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,nodename,delaunay,LR)
namespace com{
namespace nodename{
namespace delaunay{


class LR_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef LR_obj OBJ_;
		LR_obj();
		Void __construct(::String name);

	public:
		static hx::ObjectPtr< LR_obj > __new(::String name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~LR_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("LR"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

		::String _name; /* REM */ 
		static ::com::nodename::delaunay::LR LEFT; /* REM */ 
		static ::com::nodename::delaunay::LR RIGHT; /* REM */ 
		static ::com::nodename::delaunay::LR other( ::com::nodename::delaunay::LR leftRight);
		static Dynamic other_dyn();

};

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#endif /* INCLUDED_com_nodename_delaunay_LR */ 

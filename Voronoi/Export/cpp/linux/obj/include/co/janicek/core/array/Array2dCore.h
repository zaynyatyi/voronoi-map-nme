#ifndef INCLUDED_co_janicek_core_array_Array2dCore
#define INCLUDED_co_janicek_core_array_Array2dCore

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(co,janicek,core,array,Array2dCore)
namespace co{
namespace janicek{
namespace core{
namespace array{


class Array2dCore_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Array2dCore_obj OBJ_;
		Array2dCore_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Array2dCore_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Array2dCore_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Array2dCore"); }

		static Dynamic get( Dynamic a,int x,int y);
		static Dynamic get_dyn();

		static Dynamic set( Dynamic a,int x,int y,Dynamic value);
		static Dynamic set_dyn();

		static Dynamic getIndices( int index,int width,hx::Null< int >  blockSize);
		static Dynamic getIndices_dyn();

		static Void foreachY( Dynamic a,Dynamic f);
		static Dynamic foreachY_dyn();

		static Void foreachXY( Dynamic a,Dynamic f);
		static Dynamic foreachXY_dyn();

		static Dynamic any( Dynamic a,Dynamic f);
		static Dynamic any_dyn();

		static Dynamic dimensions( Dynamic array);
		static Dynamic dimensions_dyn();

		static Dynamic values( Dynamic array);
		static Dynamic values_dyn();

		static Dynamic indexes( Dynamic array);
		static Dynamic indexes_dyn();

};

} // end namespace co
} // end namespace janicek
} // end namespace core
} // end namespace array

#endif /* INCLUDED_co_janicek_core_array_Array2dCore */ 

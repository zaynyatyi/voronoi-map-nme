#ifndef INCLUDED_co_janicek_core_array_Array2dIterator
#define INCLUDED_co_janicek_core_array_Array2dIterator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(co,janicek,core,array,Array2dIterator)
namespace co{
namespace janicek{
namespace core{
namespace array{


class Array2dIterator_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Array2dIterator_obj OBJ_;
		Array2dIterator_obj();
		Void __construct(Dynamic a);

	public:
		static hx::ObjectPtr< Array2dIterator_obj > __new(Dynamic a);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Array2dIterator_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Array2dIterator"); }

		virtual Dynamic next( );
		Dynamic next_dyn();

		virtual bool hasNext( );
		Dynamic hasNext_dyn();

		int x; /* REM */ 
		int y; /* REM */ 
		Dynamic nextValue; /* REM */ 
		Dynamic a; /* REM */ 
};

} // end namespace co
} // end namespace janicek
} // end namespace core
} // end namespace array

#endif /* INCLUDED_co_janicek_core_array_Array2dIterator */ 

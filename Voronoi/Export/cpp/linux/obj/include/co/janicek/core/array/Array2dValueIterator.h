#ifndef INCLUDED_co_janicek_core_array_Array2dValueIterator
#define INCLUDED_co_janicek_core_array_Array2dValueIterator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(co,janicek,core,array,Array2dValueIterator)
namespace co{
namespace janicek{
namespace core{
namespace array{


class Array2dValueIterator_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Array2dValueIterator_obj OBJ_;
		Array2dValueIterator_obj();
		Void __construct(Dynamic a);

	public:
		static hx::ObjectPtr< Array2dValueIterator_obj > __new(Dynamic a);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Array2dValueIterator_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Array2dValueIterator"); }

		virtual Dynamic next( );
		Dynamic next_dyn();

		virtual bool hasNext( );
		Dynamic hasNext_dyn();

		Dynamic nextValue; /* REM */ 
		Dynamic xIterator; /* REM */ 
		Dynamic yIterator; /* REM */ 
};

} // end namespace co
} // end namespace janicek
} // end namespace core
} // end namespace array

#endif /* INCLUDED_co_janicek_core_array_Array2dValueIterator */ 

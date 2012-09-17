#ifndef INCLUDED_de_polygonal_math_PM_PRNG
#define INCLUDED_de_polygonal_math_PM_PRNG

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(de,polygonal,math,PM_PRNG)
namespace de{
namespace polygonal{
namespace math{


class PM_PRNG_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PM_PRNG_obj OBJ_;
		PM_PRNG_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< PM_PRNG_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PM_PRNG_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PM_PRNG"); }

		virtual int gen( );
		Dynamic gen_dyn();

		virtual Float nextDoubleRange( Float min,Float max);
		Dynamic nextDoubleRange_dyn();

		virtual int nextIntRange( Float min,Float max);
		Dynamic nextIntRange_dyn();

		virtual Float nextDouble( );
		Dynamic nextDouble_dyn();

		int seed; /* REM */ 
};

} // end namespace de
} // end namespace polygonal
} // end namespace math

#endif /* INCLUDED_de_polygonal_math_PM_PRNG */ 

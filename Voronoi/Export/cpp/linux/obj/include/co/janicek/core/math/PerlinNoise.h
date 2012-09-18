#ifndef INCLUDED_co_janicek_core_math_PerlinNoise
#define INCLUDED_co_janicek_core_math_PerlinNoise

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(co,janicek,core,math,PerlinNoise)
namespace co{
namespace janicek{
namespace core{
namespace math{


class PerlinNoise_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PerlinNoise_obj OBJ_;
		PerlinNoise_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< PerlinNoise_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PerlinNoise_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PerlinNoise"); }

		static Array< int > p; /* REM */ 
		static Array< Array< int > > makePerlinNoise( int width,int height,Float _x,Float _y,Float _z,hx::Null< int >  seed,hx::Null< int >  octaves,hx::Null< Float >  falloff,Dynamic _);
		static Dynamic makePerlinNoise_dyn();

};

} // end namespace co
} // end namespace janicek
} // end namespace core
} // end namespace math

#endif /* INCLUDED_co_janicek_core_math_PerlinNoise */ 

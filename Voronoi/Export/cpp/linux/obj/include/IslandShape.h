#ifndef INCLUDED_IslandShape
#define INCLUDED_IslandShape

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IslandShape)
HX_DECLARE_CLASS2(neash,geom,Point)


class IslandShape_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef IslandShape_obj OBJ_;
		IslandShape_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< IslandShape_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~IslandShape_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("IslandShape"); }

		static Float ISLAND_FACTOR; /* REM */ 
		static Dynamic makeRadial( int seed);
		static Dynamic makeRadial_dyn();

		static Dynamic makePerlin( int seed);
		static Dynamic makePerlin_dyn();

		static Dynamic makeSquare( int seed);
		static Dynamic makeSquare_dyn();

		static Dynamic makeBlob( int seed);
		static Dynamic makeBlob_dyn();

};


#endif /* INCLUDED_IslandShape */ 

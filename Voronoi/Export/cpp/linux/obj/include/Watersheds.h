#ifndef INCLUDED_Watersheds
#define INCLUDED_Watersheds

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Map)
HX_DECLARE_CLASS0(Watersheds)


class Watersheds_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Watersheds_obj OBJ_;
		Watersheds_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Watersheds_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Watersheds_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Watersheds"); }

		virtual Void createWatersheds( ::Map map);
		Dynamic createWatersheds_dyn();

		Dynamic watersheds; /* REM */ 
		Dynamic lowestCorner; /* REM */ 
};


#endif /* INCLUDED_Watersheds */ 

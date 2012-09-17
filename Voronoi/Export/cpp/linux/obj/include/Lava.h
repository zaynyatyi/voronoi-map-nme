#ifndef INCLUDED_Lava
#define INCLUDED_Lava

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Lava)
HX_DECLARE_CLASS0(Map)


class Lava_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Lava_obj OBJ_;
		Lava_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Lava_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Lava_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Lava"); }

		virtual Void createLava( ::Map map,Dynamic randomDouble);
		Dynamic createLava_dyn();

		Dynamic lava; /* REM */ 
		static Float FRACTION_LAVA_FISSURES; /* REM */ 
};


#endif /* INCLUDED_Lava */ 

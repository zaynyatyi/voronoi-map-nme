#ifndef INCLUDED_Roads
#define INCLUDED_Roads

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Map)
HX_DECLARE_CLASS0(Roads)


class Roads_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Roads_obj OBJ_;
		Roads_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Roads_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Roads_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Roads"); }

		virtual Void createRoads( ::Map map);
		Dynamic createRoads_dyn();

		Dynamic roadConnections; /* REM */ 
		Dynamic road; /* REM */ 
};


#endif /* INCLUDED_Roads */ 

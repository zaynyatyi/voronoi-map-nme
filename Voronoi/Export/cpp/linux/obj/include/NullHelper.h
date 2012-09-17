#ifndef INCLUDED_NullHelper
#define INCLUDED_NullHelper

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(NullHelper)


class NullHelper_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef NullHelper_obj OBJ_;
		NullHelper_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< NullHelper_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NullHelper_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("NullHelper"); }

		static bool IsNull( Dynamic e);
		static Dynamic IsNull_dyn();

		static bool IsNotNull( Dynamic e);
		static Dynamic IsNotNull_dyn();

};


#endif /* INCLUDED_NullHelper */ 

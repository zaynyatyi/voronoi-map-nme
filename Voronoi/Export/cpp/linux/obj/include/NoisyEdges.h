#ifndef INCLUDED_NoisyEdges
#define INCLUDED_NoisyEdges

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Lava)
HX_DECLARE_CLASS0(Map)
HX_DECLARE_CLASS0(NoisyEdges)
HX_DECLARE_CLASS3(de,polygonal,math,PM_PRNG)
HX_DECLARE_CLASS2(neash,geom,Point)


class NoisyEdges_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef NoisyEdges_obj OBJ_;
		NoisyEdges_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< NoisyEdges_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NoisyEdges_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("NoisyEdges"); }

		virtual Void buildNoisyEdges( ::Map map,::Lava lava,::de::polygonal::math::PM_PRNG random);
		Dynamic buildNoisyEdges_dyn();

		Dynamic path1; /* REM */ 
		Dynamic path0; /* REM */ 
		static Float NOISY_LINE_TRADEOFF; /* REM */ 
		static Array< ::neash::geom::Point > buildNoisyLineSegments( ::de::polygonal::math::PM_PRNG random,::neash::geom::Point A,::neash::geom::Point B,::neash::geom::Point C,::neash::geom::Point D,Float minLength);
		static Dynamic buildNoisyLineSegments_dyn();

};


#endif /* INCLUDED_NoisyEdges */ 

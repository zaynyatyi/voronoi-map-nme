#ifndef INCLUDED_Map
#define INCLUDED_Map

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Map)
HX_DECLARE_CLASS3(com,nodename,delaunay,Voronoi)
HX_DECLARE_CLASS3(de,polygonal,math,PM_PRNG)
HX_DECLARE_CLASS1(graph,Center)
HX_DECLARE_CLASS1(graph,Corner)
HX_DECLARE_CLASS1(graph,Edge)
HX_DECLARE_CLASS2(neash,geom,Point)


class Map_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Map_obj OBJ_;
		Map_obj();
		Void __construct(Dynamic size);

	public:
		static hx::ObjectPtr< Map_obj > __new(Dynamic size);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Map_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Map"); }

		virtual bool inside( ::neash::geom::Point p);
		Dynamic inside_dyn();

		virtual ::graph::Edge lookupEdgeFromCorner( ::graph::Corner q,::graph::Corner s);
		Dynamic lookupEdgeFromCorner_dyn();

		virtual ::graph::Edge lookupEdgeFromCenter( ::graph::Center p,::graph::Center r);
		Dynamic lookupEdgeFromCenter_dyn();

		virtual Void assignBiomes( );
		Dynamic assignBiomes_dyn();

		virtual Void assignPolygonMoisture( );
		Dynamic assignPolygonMoisture_dyn();

		virtual Void assignCornerMoisture( );
		Dynamic assignCornerMoisture_dyn();

		virtual Void createRivers( );
		Dynamic createRivers_dyn();

		virtual Void calculateWatersheds( );
		Dynamic calculateWatersheds_dyn();

		virtual Void calculateDownslopes( );
		Dynamic calculateDownslopes_dyn();

		virtual Void assignPolygonElevations( );
		Dynamic assignPolygonElevations_dyn();

		virtual Void assignOceanCoastAndLand( );
		Dynamic assignOceanCoastAndLand_dyn();

		virtual Void redistributeMoisture( Dynamic locations);
		Dynamic redistributeMoisture_dyn();

		virtual Void redistributeElevations( Dynamic locations);
		Dynamic redistributeElevations_dyn();

		virtual Void assignCornerElevations( );
		Dynamic assignCornerElevations_dyn();

		virtual Void buildGraph( Array< ::neash::geom::Point > points,::com::nodename::delaunay::Voronoi voronoi);
		Dynamic buildGraph_dyn();

		virtual Dynamic landCorners( Array< ::graph::Corner > corners);
		Dynamic landCorners_dyn();

		virtual Void improveCorners( );
		Dynamic improveCorners_dyn();

		virtual Void improveRandomPoints( Array< ::neash::geom::Point > points);
		Dynamic improveRandomPoints_dyn();

		virtual Array< ::neash::geom::Point > generateRandomPoints( );
		Dynamic generateRandomPoints_dyn();

		virtual Void go( int first,int last);
		Dynamic go_dyn();

		virtual Void reset( );
		Dynamic reset_dyn();

		virtual Void newIsland( ::String type,int seed,int variant);
		Dynamic newIsland_dyn();

		Array< ::graph::Edge > edges; /* REM */ 
		Array< ::graph::Corner > corners; /* REM */ 
		Array< ::graph::Center > centers; /* REM */ 
		Array< ::neash::geom::Point > points; /* REM */ 
		::de::polygonal::math::PM_PRNG mapRandom; /* REM */ 
		Dynamic islandShape; /* REM */ 
		Dynamic &islandShape_dyn() { return islandShape;}
		Dynamic SIZE; /* REM */ 
		static int NUM_POINTS; /* REM */ 
		static Float LAKE_THRESHOLD; /* REM */ 
		static int NUM_LLOYD_ITERATIONS; /* REM */ 
		static ::String getBiome( ::graph::Center p);
		static Dynamic getBiome_dyn();

};


#endif /* INCLUDED_Map */ 

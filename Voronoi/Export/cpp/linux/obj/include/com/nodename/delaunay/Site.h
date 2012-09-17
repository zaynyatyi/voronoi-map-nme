#ifndef INCLUDED_com_nodename_delaunay_Site
#define INCLUDED_com_nodename_delaunay_Site

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/nodename/delaunay/ICoord.h>
HX_DECLARE_CLASS3(com,nodename,delaunay,Edge)
HX_DECLARE_CLASS3(com,nodename,delaunay,ICoord)
HX_DECLARE_CLASS3(com,nodename,delaunay,LR)
HX_DECLARE_CLASS3(com,nodename,delaunay,Site)
HX_DECLARE_CLASS2(neash,geom,Point)
HX_DECLARE_CLASS2(neash,geom,Rectangle)
namespace com{
namespace nodename{
namespace delaunay{


class Site_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Site_obj OBJ_;
		Site_obj();
		Void __construct(::neash::geom::Point p,int index,Float weight,int color);

	public:
		static hx::ObjectPtr< Site_obj > __new(::neash::geom::Point p,int index,Float weight,int color);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Site_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::com::nodename::delaunay::ICoord_obj *()
			{ return new ::com::nodename::delaunay::ICoord_delegate_< Site_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("Site"); }

		virtual Float dist( ::com::nodename::delaunay::ICoord p);
		Dynamic dist_dyn();

		virtual Float getY( );
		Dynamic getY_dyn();

		Float y; /* REM */ 
		virtual Float getX( );
		Dynamic getX_dyn();

		Float x; /* REM */ 
		virtual Void connect( Array< ::neash::geom::Point > points,int j,::neash::geom::Rectangle bounds,hx::Null< bool >  closingUp);
		Dynamic connect_dyn();

		virtual Array< ::neash::geom::Point > clipToBounds( ::neash::geom::Rectangle bounds);
		Dynamic clipToBounds_dyn();

		virtual Void reorderEdges( );
		Dynamic reorderEdges_dyn();

		virtual Array< ::neash::geom::Point > region( ::neash::geom::Rectangle clippingBounds);
		Dynamic region_dyn();

		virtual ::com::nodename::delaunay::Site neighborSite( ::com::nodename::delaunay::Edge edge);
		Dynamic neighborSite_dyn();

		virtual Array< ::com::nodename::delaunay::Site > neighborSites( );
		Dynamic neighborSites_dyn();

		virtual ::com::nodename::delaunay::Edge nearestEdge( );
		Dynamic nearestEdge_dyn();

		virtual Void addEdge( ::com::nodename::delaunay::Edge edge);
		Dynamic addEdge_dyn();

		virtual Void clear( );
		Dynamic clear_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void move( ::neash::geom::Point p);
		Dynamic move_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual ::com::nodename::delaunay::Site init( ::neash::geom::Point p,int index,Float weight,int color);
		Dynamic init_dyn();

		Array< ::neash::geom::Point > _region; /* REM */ 
		Array< ::com::nodename::delaunay::LR > _edgeOrientations; /* REM */ 
		virtual Array< ::com::nodename::delaunay::Edge > get_edges( );
		Dynamic get_edges_dyn();

		Array< ::com::nodename::delaunay::Edge > edges; /* REM */ 
		Array< ::com::nodename::delaunay::Edge > _edges; /* REM */ 
		int _siteIndex; /* REM */ 
		Float weight; /* REM */ 
		int color; /* REM */ 
		virtual ::neash::geom::Point get_coord( );
		Dynamic get_coord_dyn();

		::neash::geom::Point _coord; /* REM */ 
		::neash::geom::Point coord; /* REM */ 
		static Array< ::com::nodename::delaunay::Site > _pool; /* REM */ 
		static ::com::nodename::delaunay::Site create( ::neash::geom::Point p,int index,Float weight,int color);
		static Dynamic create_dyn();

		static Void sortSites( Array< ::com::nodename::delaunay::Site > sites);
		static Dynamic sortSites_dyn();

		static Float EPSILON; /* REM */ 
		static bool closeEnough( ::neash::geom::Point p0,::neash::geom::Point p1);
		static Dynamic closeEnough_dyn();

};

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#endif /* INCLUDED_com_nodename_delaunay_Site */ 

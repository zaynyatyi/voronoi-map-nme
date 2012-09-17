#ifndef INCLUDED_com_nodename_delaunay_SiteList
#define INCLUDED_com_nodename_delaunay_SiteList

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/nodename/utils/IDisposable.h>
HX_DECLARE_CLASS3(com,nodename,delaunay,ICoord)
HX_DECLARE_CLASS3(com,nodename,delaunay,Site)
HX_DECLARE_CLASS3(com,nodename,delaunay,SiteList)
HX_DECLARE_CLASS3(com,nodename,geom,Circle)
HX_DECLARE_CLASS3(com,nodename,utils,IDisposable)
HX_DECLARE_CLASS2(neash,display,BitmapData)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,geom,Point)
HX_DECLARE_CLASS2(neash,geom,Rectangle)
namespace com{
namespace nodename{
namespace delaunay{


class SiteList_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SiteList_obj OBJ_;
		SiteList_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< SiteList_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SiteList_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::com::nodename::utils::IDisposable_obj *()
			{ return new ::com::nodename::utils::IDisposable_delegate_< SiteList_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("SiteList"); }

		virtual ::neash::geom::Point nearestSitePoint( ::neash::display::BitmapData proximityMap,int x,int y);
		Dynamic nearestSitePoint_dyn();

		virtual Array< Array< ::neash::geom::Point > > regions( ::neash::geom::Rectangle plotBounds);
		Dynamic regions_dyn();

		virtual Array< ::com::nodename::geom::Circle > circles( );
		Dynamic circles_dyn();

		virtual Array< ::neash::geom::Point > siteCoords( );
		Dynamic siteCoords_dyn();

		virtual Array< int > siteColors( ::neash::display::BitmapData referenceImage);
		Dynamic siteColors_dyn();

		virtual ::neash::geom::Rectangle getSitesBounds( );
		Dynamic getSitesBounds_dyn();

		virtual ::com::nodename::delaunay::Site next( );
		Dynamic next_dyn();

		virtual int getLength( );
		Dynamic getLength_dyn();

		int length; /* REM */ 
		virtual int push( ::com::nodename::delaunay::Site site);
		Dynamic push_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		bool _sorted; /* REM */ 
		int _currentIndex; /* REM */ 
		Array< ::com::nodename::delaunay::Site > _sites; /* REM */ 
};

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#endif /* INCLUDED_com_nodename_delaunay_SiteList */ 

#ifndef INCLUDED_com_nodename_delaunay_EdgeList
#define INCLUDED_com_nodename_delaunay_EdgeList

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/nodename/utils/IDisposable.h>
HX_DECLARE_CLASS3(com,nodename,delaunay,EdgeList)
HX_DECLARE_CLASS3(com,nodename,delaunay,Halfedge)
HX_DECLARE_CLASS3(com,nodename,utils,IDisposable)
HX_DECLARE_CLASS2(neash,geom,Point)
namespace com{
namespace nodename{
namespace delaunay{


class EdgeList_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EdgeList_obj OBJ_;
		EdgeList_obj();
		Void __construct(Float xmin,Float deltax,int sqrt_nsites);

	public:
		static hx::ObjectPtr< EdgeList_obj > __new(Float xmin,Float deltax,int sqrt_nsites);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EdgeList_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::com::nodename::utils::IDisposable_obj *()
			{ return new ::com::nodename::utils::IDisposable_delegate_< EdgeList_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("EdgeList"); }

		virtual ::com::nodename::delaunay::Halfedge getHash( int b);
		Dynamic getHash_dyn();

		virtual ::com::nodename::delaunay::Halfedge edgeListLeftNeighbor( ::neash::geom::Point p);
		Dynamic edgeListLeftNeighbor_dyn();

		virtual Void remove( ::com::nodename::delaunay::Halfedge halfEdge);
		Dynamic remove_dyn();

		virtual Void insert( ::com::nodename::delaunay::Halfedge lb,::com::nodename::delaunay::Halfedge newHalfedge);
		Dynamic insert_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual ::com::nodename::delaunay::Halfedge getRightEnd( );
		Dynamic getRightEnd_dyn();

		::com::nodename::delaunay::Halfedge rightEnd; /* REM */ 
		::com::nodename::delaunay::Halfedge _rightEnd; /* REM */ 
		virtual ::com::nodename::delaunay::Halfedge getLeftEnd( );
		Dynamic getLeftEnd_dyn();

		::com::nodename::delaunay::Halfedge leftEnd; /* REM */ 
		::com::nodename::delaunay::Halfedge _leftEnd; /* REM */ 
		Array< ::com::nodename::delaunay::Halfedge > _hash; /* REM */ 
		int _hashsize; /* REM */ 
		Float _xmin; /* REM */ 
		Float _deltax; /* REM */ 
};

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#endif /* INCLUDED_com_nodename_delaunay_EdgeList */ 

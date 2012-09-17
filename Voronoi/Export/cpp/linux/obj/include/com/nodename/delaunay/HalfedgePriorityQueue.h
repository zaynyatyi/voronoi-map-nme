#ifndef INCLUDED_com_nodename_delaunay_HalfedgePriorityQueue
#define INCLUDED_com_nodename_delaunay_HalfedgePriorityQueue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,nodename,delaunay,Halfedge)
HX_DECLARE_CLASS3(com,nodename,delaunay,HalfedgePriorityQueue)
HX_DECLARE_CLASS2(neash,geom,Point)
namespace com{
namespace nodename{
namespace delaunay{


class HalfedgePriorityQueue_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef HalfedgePriorityQueue_obj OBJ_;
		HalfedgePriorityQueue_obj();
		Void __construct(Float ymin,Float deltay,int sqrt_nsites);

	public:
		static hx::ObjectPtr< HalfedgePriorityQueue_obj > __new(Float ymin,Float deltay,int sqrt_nsites);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HalfedgePriorityQueue_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HalfedgePriorityQueue"); }

		virtual ::com::nodename::delaunay::Halfedge extractMin( );
		Dynamic extractMin_dyn();

		virtual ::neash::geom::Point min( );
		Dynamic min_dyn();

		virtual bool empty( );
		Dynamic empty_dyn();

		virtual Void adjustMinBucket( );
		Dynamic adjustMinBucket_dyn();

		virtual bool isEmpty( int bucket);
		Dynamic isEmpty_dyn();

		virtual int bucket( ::com::nodename::delaunay::Halfedge halfEdge);
		Dynamic bucket_dyn();

		virtual Void remove( ::com::nodename::delaunay::Halfedge halfEdge);
		Dynamic remove_dyn();

		virtual Void insert( ::com::nodename::delaunay::Halfedge halfEdge);
		Dynamic insert_dyn();

		virtual Void initialize( );
		Dynamic initialize_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		Float _deltay; /* REM */ 
		Float _ymin; /* REM */ 
		int _hashsize; /* REM */ 
		int _minBucket; /* REM */ 
		int _count; /* REM */ 
		Array< ::com::nodename::delaunay::Halfedge > _hash; /* REM */ 
};

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#endif /* INCLUDED_com_nodename_delaunay_HalfedgePriorityQueue */ 

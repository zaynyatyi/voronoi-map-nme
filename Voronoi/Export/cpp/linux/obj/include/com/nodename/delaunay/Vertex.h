#ifndef INCLUDED_com_nodename_delaunay_Vertex
#define INCLUDED_com_nodename_delaunay_Vertex

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/nodename/delaunay/ICoord.h>
HX_DECLARE_CLASS3(com,nodename,delaunay,Halfedge)
HX_DECLARE_CLASS3(com,nodename,delaunay,ICoord)
HX_DECLARE_CLASS3(com,nodename,delaunay,Vertex)
HX_DECLARE_CLASS2(neash,geom,Point)
namespace com{
namespace nodename{
namespace delaunay{


class Vertex_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Vertex_obj OBJ_;
		Vertex_obj();
		Void __construct(Float x,Float y);

	public:
		static hx::ObjectPtr< Vertex_obj > __new(Float x,Float y);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Vertex_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::com::nodename::delaunay::ICoord_obj *()
			{ return new ::com::nodename::delaunay::ICoord_delegate_< Vertex_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("Vertex"); }

		virtual Float getY( );
		Dynamic getY_dyn();

		Float y; /* REM */ 
		virtual Float getX( );
		Dynamic getX_dyn();

		Float x; /* REM */ 
		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Void setIndex( );
		Dynamic setIndex_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual ::com::nodename::delaunay::Vertex init( Float x,Float y);
		Dynamic init_dyn();

		int vertexIndex; /* REM */ 
		virtual ::neash::geom::Point get_coord( );
		Dynamic get_coord_dyn();

		::neash::geom::Point coord; /* REM */ 
		::neash::geom::Point _coord; /* REM */ 
		static ::com::nodename::delaunay::Vertex VERTEX_AT_INFINITY; /* REM */ 
		static Array< ::com::nodename::delaunay::Vertex > _pool; /* REM */ 
		static ::com::nodename::delaunay::Vertex create( Float x,Float y);
		static Dynamic create_dyn();

		static int _nvertices; /* REM */ 
		static ::com::nodename::delaunay::Vertex intersect( ::com::nodename::delaunay::Halfedge halfedge0,::com::nodename::delaunay::Halfedge halfedge1);
		static Dynamic intersect_dyn();

};

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#endif /* INCLUDED_com_nodename_delaunay_Vertex */ 

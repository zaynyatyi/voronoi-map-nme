#ifndef INCLUDED_com_nodename_delaunay_Criterion
#define INCLUDED_com_nodename_delaunay_Criterion

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,nodename,delaunay,Criterion)
namespace com{
namespace nodename{
namespace delaunay{


class Criterion_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Criterion_obj OBJ_;

	public:
		Criterion_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("com.nodename.delaunay.Criterion"); }
		::String __ToString() const { return HX_CSTRING("Criterion.") + tag; }

		static ::com::nodename::delaunay::Criterion site;
		static inline ::com::nodename::delaunay::Criterion site_dyn() { return site; }
		static ::com::nodename::delaunay::Criterion vertex;
		static inline ::com::nodename::delaunay::Criterion vertex_dyn() { return vertex; }
};

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#endif /* INCLUDED_com_nodename_delaunay_Criterion */ 

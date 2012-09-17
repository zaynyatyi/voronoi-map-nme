#ifndef INCLUDED_com_nodename_delaunay_ICoord
#define INCLUDED_com_nodename_delaunay_ICoord

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,nodename,delaunay,ICoord)
HX_DECLARE_CLASS2(neash,geom,Point)
namespace com{
namespace nodename{
namespace delaunay{


class ICoord_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef ICoord_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual ::neash::geom::Point get_coord( )=0;
		Dynamic get_coord_dyn();
};

#define DELEGATE_com_nodename_delaunay_ICoord \
virtual ::neash::geom::Point get_coord( ) { return mDelegate->get_coord();}  \
virtual Dynamic get_coord_dyn() { return mDelegate->get_coord_dyn();}  \


template<typename IMPL>
class ICoord_delegate_ : public ICoord_obj
{
	protected:
		IMPL *mDelegate;
	public:
		ICoord_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_com_nodename_delaunay_ICoord
};

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#endif /* INCLUDED_com_nodename_delaunay_ICoord */ 

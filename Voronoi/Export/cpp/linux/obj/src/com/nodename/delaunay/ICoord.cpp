#include <hxcpp.h>

#ifndef INCLUDED_com_nodename_delaunay_ICoord
#include <com/nodename/delaunay/ICoord.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
namespace com{
namespace nodename{
namespace delaunay{

HX_DEFINE_DYNAMIC_FUNC0(ICoord_obj,get_coord,return )


static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ICoord_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ICoord_obj::__mClass,"__mClass");
};

Class ICoord_obj::__mClass;

void ICoord_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.delaunay.ICoord"), hx::TCanCast< ICoord_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ICoord_obj::__boot()
{
}

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#include <hxcpp.h>

#ifndef INCLUDED_com_nodename_delaunay_Criterion
#include <com/nodename/delaunay/Criterion.h>
#endif
namespace com{
namespace nodename{
namespace delaunay{

::com::nodename::delaunay::Criterion Criterion_obj::site;

::com::nodename::delaunay::Criterion Criterion_obj::vertex;

HX_DEFINE_CREATE_ENUM(Criterion_obj)

int Criterion_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("site")) return 1;
	if (inName==HX_CSTRING("vertex")) return 0;
	return super::__FindIndex(inName);
}

int Criterion_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("site")) return 0;
	if (inName==HX_CSTRING("vertex")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic Criterion_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("site")) return site;
	if (inName==HX_CSTRING("vertex")) return vertex;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("vertex"),
	HX_CSTRING("site"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Criterion_obj::site,"site");
	HX_MARK_MEMBER_NAME(Criterion_obj::vertex,"vertex");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Criterion_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Criterion_obj::site,"site");
	HX_VISIT_MEMBER_NAME(Criterion_obj::vertex,"vertex");
};

static ::String sMemberFields[] = { ::String(null()) };
Class Criterion_obj::__mClass;

Dynamic __Create_Criterion_obj() { return new Criterion_obj; }

void Criterion_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.delaunay.Criterion"), hx::TCanCast< Criterion_obj >,sStaticFields,sMemberFields,
	&__Create_Criterion_obj, &__Create,
	&super::__SGetClass(), &CreateCriterion_obj, sMarkStatics, sVisitStatic);
}

void Criterion_obj::__boot()
{
Static(site) = hx::CreateEnum< Criterion_obj >(HX_CSTRING("site"),1);
Static(vertex) = hx::CreateEnum< Criterion_obj >(HX_CSTRING("vertex"),0);
}


} // end namespace com
} // end namespace nodename
} // end namespace delaunay

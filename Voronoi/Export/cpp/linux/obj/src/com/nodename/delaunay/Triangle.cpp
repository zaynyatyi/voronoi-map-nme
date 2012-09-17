#include <hxcpp.h>

#ifndef INCLUDED_com_nodename_delaunay_ICoord
#include <com/nodename/delaunay/ICoord.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Site
#include <com/nodename/delaunay/Site.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Triangle
#include <com/nodename/delaunay/Triangle.h>
#endif
namespace com{
namespace nodename{
namespace delaunay{

Void Triangle_obj::__construct(::com::nodename::delaunay::Site a,::com::nodename::delaunay::Site b,::com::nodename::delaunay::Site c)
{
HX_STACK_PUSH("Triangle::new","com/nodename/delaunay/Triangle.hx",13);
{
	HX_STACK_LINE(13)
	this->_sites = Array_obj< ::com::nodename::delaunay::Site >::__new().Add(a).Add(b).Add(c);
}
;
	return null();
}

Triangle_obj::~Triangle_obj() { }

Dynamic Triangle_obj::__CreateEmpty() { return  new Triangle_obj; }
hx::ObjectPtr< Triangle_obj > Triangle_obj::__new(::com::nodename::delaunay::Site a,::com::nodename::delaunay::Site b,::com::nodename::delaunay::Site c)
{  hx::ObjectPtr< Triangle_obj > result = new Triangle_obj();
	result->__construct(a,b,c);
	return result;}

Dynamic Triangle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Triangle_obj > result = new Triangle_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Triangle_obj::dispose( ){
{
		HX_STACK_PUSH("Triangle::dispose","com/nodename/delaunay/Triangle.hx",18);
		HX_STACK_THIS(this);
		HX_STACK_LINE(18)
		this->_sites = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Triangle_obj,dispose,(void))

Array< ::com::nodename::delaunay::Site > Triangle_obj::get_sites( ){
	HX_STACK_PUSH("Triangle::get_sites","com/nodename/delaunay/Triangle.hx",8);
	HX_STACK_THIS(this);
	HX_STACK_LINE(8)
	return this->_sites;
}


HX_DEFINE_DYNAMIC_FUNC0(Triangle_obj,get_sites,return )


Triangle_obj::Triangle_obj()
{
}

void Triangle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Triangle);
	HX_MARK_MEMBER_NAME(sites,"sites");
	HX_MARK_MEMBER_NAME(_sites,"_sites");
	HX_MARK_END_CLASS();
}

void Triangle_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(sites,"sites");
	HX_VISIT_MEMBER_NAME(_sites,"_sites");
}

Dynamic Triangle_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"sites") ) { return inCallProp ? get_sites() : sites; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_sites") ) { return _sites; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_sites") ) { return get_sites_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Triangle_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"sites") ) { sites=inValue.Cast< Array< ::com::nodename::delaunay::Site > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_sites") ) { _sites=inValue.Cast< Array< ::com::nodename::delaunay::Site > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Triangle_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("sites"));
	outFields->push(HX_CSTRING("_sites"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("dispose"),
	HX_CSTRING("get_sites"),
	HX_CSTRING("sites"),
	HX_CSTRING("_sites"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Triangle_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Triangle_obj::__mClass,"__mClass");
};

Class Triangle_obj::__mClass;

void Triangle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.delaunay.Triangle"), hx::TCanCast< Triangle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Triangle_obj::__boot()
{
}

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

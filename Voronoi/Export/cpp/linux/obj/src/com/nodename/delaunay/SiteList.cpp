#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Edge
#include <com/nodename/delaunay/Edge.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_ICoord
#include <com/nodename/delaunay/ICoord.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Site
#include <com/nodename/delaunay/Site.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_SiteList
#include <com/nodename/delaunay/SiteList.h>
#endif
#ifndef INCLUDED_com_nodename_geom_Circle
#include <com/nodename/geom/Circle.h>
#endif
#ifndef INCLUDED_com_nodename_utils_IDisposable
#include <com/nodename/utils/IDisposable.h>
#endif
#ifndef INCLUDED_neash_display_BitmapData
#include <neash/display/BitmapData.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
#ifndef INCLUDED_neash_geom_Rectangle
#include <neash/geom/Rectangle.h>
#endif
namespace com{
namespace nodename{
namespace delaunay{

Void SiteList_obj::__construct()
{
HX_STACK_PUSH("SiteList::new","com/nodename/delaunay/SiteList.hx",23);
{
	HX_STACK_LINE(24)
	this->_sites = Array_obj< ::com::nodename::delaunay::Site >::__new();
	HX_STACK_LINE(25)
	this->_sorted = false;
}
;
	return null();
}

SiteList_obj::~SiteList_obj() { }

Dynamic SiteList_obj::__CreateEmpty() { return  new SiteList_obj; }
hx::ObjectPtr< SiteList_obj > SiteList_obj::__new()
{  hx::ObjectPtr< SiteList_obj > result = new SiteList_obj();
	result->__construct();
	return result;}

Dynamic SiteList_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SiteList_obj > result = new SiteList_obj();
	result->__construct();
	return result;}

hx::Object *SiteList_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::com::nodename::utils::IDisposable_obj)) return operator ::com::nodename::utils::IDisposable_obj *();
	return super::__ToInterface(inType);
}

::neash::geom::Point SiteList_obj::nearestSitePoint( ::neash::display::BitmapData proximityMap,int x,int y){
	HX_STACK_PUSH("SiteList::nearestSitePoint","com/nodename/delaunay/SiteList.hx",162);
	HX_STACK_THIS(this);
	HX_STACK_ARG(proximityMap,"proximityMap");
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(163)
	int index = proximityMap->getPixel(x,y);		HX_STACK_VAR(index,"index");
	HX_STACK_LINE(164)
	if (((index > (this->_sites->length - (int)1)))){
		HX_STACK_LINE(165)
		return null();
	}
	HX_STACK_LINE(168)
	return this->_sites->__get(index)->_coord;
}


HX_DEFINE_DYNAMIC_FUNC3(SiteList_obj,nearestSitePoint,return )

Array< Array< ::neash::geom::Point > > SiteList_obj::regions( ::neash::geom::Rectangle plotBounds){
	HX_STACK_PUSH("SiteList::regions","com/nodename/delaunay/SiteList.hx",144);
	HX_STACK_THIS(this);
	HX_STACK_ARG(plotBounds,"plotBounds");
	HX_STACK_LINE(145)
	Array< Array< ::neash::geom::Point > > regions = Array_obj< Array< ::neash::geom::Point > >::__new();		HX_STACK_VAR(regions,"regions");
	HX_STACK_LINE(146)
	{
		HX_STACK_LINE(146)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::com::nodename::delaunay::Site > _g1 = this->_sites;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(146)
		while(((_g < _g1->length))){
			HX_STACK_LINE(146)
			::com::nodename::delaunay::Site site = _g1->__get(_g);		HX_STACK_VAR(site,"site");
			HX_STACK_LINE(146)
			++(_g);
			HX_STACK_LINE(148)
			regions->push(site->region(plotBounds));
		}
	}
	HX_STACK_LINE(150)
	return regions;
}


HX_DEFINE_DYNAMIC_FUNC1(SiteList_obj,regions,return )

Array< ::com::nodename::geom::Circle > SiteList_obj::circles( ){
	HX_STACK_PUSH("SiteList::circles","com/nodename/delaunay/SiteList.hx",129);
	HX_STACK_THIS(this);
	HX_STACK_LINE(130)
	Array< ::com::nodename::geom::Circle > circles = Array_obj< ::com::nodename::geom::Circle >::__new();		HX_STACK_VAR(circles,"circles");
	HX_STACK_LINE(131)
	{
		HX_STACK_LINE(131)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::com::nodename::delaunay::Site > _g1 = this->_sites;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(131)
		while(((_g < _g1->length))){
			HX_STACK_LINE(131)
			::com::nodename::delaunay::Site site = _g1->__get(_g);		HX_STACK_VAR(site,"site");
			HX_STACK_LINE(131)
			++(_g);
			HX_STACK_LINE(134)
			::com::nodename::delaunay::Edge nearestEdge = site->nearestEdge();		HX_STACK_VAR(nearestEdge,"nearestEdge");
			HX_STACK_LINE(136)
			Float radius = (  ((!(nearestEdge->isPartOfConvexHull()))) ? Float((nearestEdge->sitesDistance() * 0.5)) : Float((int)0) );		HX_STACK_VAR(radius,"radius");
			HX_STACK_LINE(138)
			circles->push(::com::nodename::geom::Circle_obj::__new(site->_coord->x,site->_coord->y,radius));
		}
	}
	HX_STACK_LINE(140)
	return circles;
}


HX_DEFINE_DYNAMIC_FUNC0(SiteList_obj,circles,return )

Array< ::neash::geom::Point > SiteList_obj::siteCoords( ){
	HX_STACK_PUSH("SiteList::siteCoords","com/nodename/delaunay/SiteList.hx",113);
	HX_STACK_THIS(this);
	HX_STACK_LINE(114)
	Array< ::neash::geom::Point > coords = Array_obj< ::neash::geom::Point >::__new();		HX_STACK_VAR(coords,"coords");
	HX_STACK_LINE(115)
	{
		HX_STACK_LINE(115)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::com::nodename::delaunay::Site > _g1 = this->_sites;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(115)
		while(((_g < _g1->length))){
			HX_STACK_LINE(115)
			::com::nodename::delaunay::Site site = _g1->__get(_g);		HX_STACK_VAR(site,"site");
			HX_STACK_LINE(115)
			++(_g);
			HX_STACK_LINE(117)
			coords->push(site->_coord);
		}
	}
	HX_STACK_LINE(119)
	return coords;
}


HX_DEFINE_DYNAMIC_FUNC0(SiteList_obj,siteCoords,return )

Array< int > SiteList_obj::siteColors( ::neash::display::BitmapData referenceImage){
	HX_STACK_PUSH("SiteList::siteColors","com/nodename/delaunay/SiteList.hx",103);
	HX_STACK_THIS(this);
	HX_STACK_ARG(referenceImage,"referenceImage");
	HX_STACK_LINE(104)
	Array< int > colors = Array_obj< int >::__new();		HX_STACK_VAR(colors,"colors");
	HX_STACK_LINE(105)
	{
		HX_STACK_LINE(105)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::com::nodename::delaunay::Site > _g1 = this->_sites;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(105)
		while(((_g < _g1->length))){
			HX_STACK_LINE(105)
			::com::nodename::delaunay::Site site = _g1->__get(_g);		HX_STACK_VAR(site,"site");
			HX_STACK_LINE(105)
			++(_g);
			HX_STACK_LINE(107)
			colors->push((  (((referenceImage != null()))) ? int(referenceImage->getPixel(::Std_obj::_int(site->_coord->x),::Std_obj::_int(site->_coord->y))) : int(site->color) ));
		}
	}
	HX_STACK_LINE(109)
	return colors;
}


HX_DEFINE_DYNAMIC_FUNC1(SiteList_obj,siteColors,return )

::neash::geom::Rectangle SiteList_obj::getSitesBounds( ){
	HX_STACK_PUSH("SiteList::getSitesBounds","com/nodename/delaunay/SiteList.hx",69);
	HX_STACK_THIS(this);
	HX_STACK_LINE(70)
	if (((this->_sorted == false))){
		HX_STACK_LINE(72)
		::com::nodename::delaunay::Site_obj::sortSites(this->_sites);
		HX_STACK_LINE(73)
		this->_currentIndex = (int)0;
		HX_STACK_LINE(74)
		this->_sorted = true;
	}
	HX_STACK_LINE(76)
	Float xmin;		HX_STACK_VAR(xmin,"xmin");
	Float xmax;		HX_STACK_VAR(xmax,"xmax");
	Float ymin;		HX_STACK_VAR(ymin,"ymin");
	Float ymax;		HX_STACK_VAR(ymax,"ymax");
	HX_STACK_LINE(77)
	if (((this->_sites->length == (int)0))){
		HX_STACK_LINE(78)
		return ::neash::geom::Rectangle_obj::__new((int)0,(int)0,(int)0,(int)0);
	}
	HX_STACK_LINE(82)
	xmin = ::Math_obj::POSITIVE_INFINITY;
	HX_STACK_LINE(83)
	xmax = ::Math_obj::NEGATIVE_INFINITY;
	HX_STACK_LINE(84)
	{
		HX_STACK_LINE(84)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::com::nodename::delaunay::Site > _g1 = this->_sites;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(84)
		while(((_g < _g1->length))){
			HX_STACK_LINE(84)
			::com::nodename::delaunay::Site site = _g1->__get(_g);		HX_STACK_VAR(site,"site");
			HX_STACK_LINE(84)
			++(_g);
			HX_STACK_LINE(86)
			if (((site->_coord->x < xmin))){
				HX_STACK_LINE(87)
				xmin = site->_coord->x;
			}
			HX_STACK_LINE(90)
			if (((site->_coord->x > xmax))){
				HX_STACK_LINE(91)
				xmax = site->_coord->x;
			}
		}
	}
	HX_STACK_LINE(96)
	ymin = this->_sites->__get((int)0)->_coord->y;
	HX_STACK_LINE(97)
	ymax = this->_sites->__get((this->_sites->length - (int)1))->_coord->y;
	HX_STACK_LINE(99)
	return ::neash::geom::Rectangle_obj::__new(xmin,ymin,(xmax - xmin),(ymax - ymin));
}


HX_DEFINE_DYNAMIC_FUNC0(SiteList_obj,getSitesBounds,return )

::com::nodename::delaunay::Site SiteList_obj::next( ){
	HX_STACK_PUSH("SiteList::next","com/nodename/delaunay/SiteList.hx",53);
	HX_STACK_THIS(this);
	HX_STACK_LINE(54)
	if (((this->_sorted == false))){
		HX_STACK_LINE(55)
		hx::Throw (HX_CSTRING("SiteList::next():  sites have not been sorted"));
	}
	HX_STACK_LINE(58)
	if (((this->_currentIndex < this->_sites->length))){
		HX_STACK_LINE(59)
		return this->_sites->__get((this->_currentIndex)++);
	}
	else{
		HX_STACK_LINE(63)
		return null();
	}
	HX_STACK_LINE(58)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SiteList_obj,next,return )

int SiteList_obj::getLength( ){
	HX_STACK_PUSH("SiteList::getLength","com/nodename/delaunay/SiteList.hx",48);
	HX_STACK_THIS(this);
	HX_STACK_LINE(48)
	return this->_sites->length;
}


HX_DEFINE_DYNAMIC_FUNC0(SiteList_obj,getLength,return )

int SiteList_obj::push( ::com::nodename::delaunay::Site site){
	HX_STACK_PUSH("SiteList::push","com/nodename/delaunay/SiteList.hx",41);
	HX_STACK_THIS(this);
	HX_STACK_ARG(site,"site");
	HX_STACK_LINE(42)
	this->_sorted = false;
	HX_STACK_LINE(43)
	return this->_sites->push(site);
}


HX_DEFINE_DYNAMIC_FUNC1(SiteList_obj,push,return )

Void SiteList_obj::dispose( ){
{
		HX_STACK_PUSH("SiteList::dispose","com/nodename/delaunay/SiteList.hx",29);
		HX_STACK_THIS(this);
		HX_STACK_LINE(29)
		if (((this->_sites != null()))){
			HX_STACK_LINE(32)
			{
				HX_STACK_LINE(32)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::com::nodename::delaunay::Site > _g1 = this->_sites;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(32)
				while(((_g < _g1->length))){
					HX_STACK_LINE(32)
					::com::nodename::delaunay::Site site = _g1->__get(_g);		HX_STACK_VAR(site,"site");
					HX_STACK_LINE(32)
					++(_g);
					HX_STACK_LINE(34)
					site->dispose();
				}
			}
			HX_STACK_LINE(36)
			this->_sites = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SiteList_obj,dispose,(void))


SiteList_obj::SiteList_obj()
{
}

void SiteList_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SiteList);
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(_sorted,"_sorted");
	HX_MARK_MEMBER_NAME(_currentIndex,"_currentIndex");
	HX_MARK_MEMBER_NAME(_sites,"_sites");
	HX_MARK_END_CLASS();
}

void SiteList_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(_sorted,"_sorted");
	HX_VISIT_MEMBER_NAME(_currentIndex,"_currentIndex");
	HX_VISIT_MEMBER_NAME(_sites,"_sites");
}

Dynamic SiteList_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"next") ) { return next_dyn(); }
		if (HX_FIELD_EQ(inName,"push") ) { return push_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return inCallProp ? getLength() : length; }
		if (HX_FIELD_EQ(inName,"_sites") ) { return _sites; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"regions") ) { return regions_dyn(); }
		if (HX_FIELD_EQ(inName,"circles") ) { return circles_dyn(); }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"_sorted") ) { return _sorted; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getLength") ) { return getLength_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"siteCoords") ) { return siteCoords_dyn(); }
		if (HX_FIELD_EQ(inName,"siteColors") ) { return siteColors_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_currentIndex") ) { return _currentIndex; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getSitesBounds") ) { return getSitesBounds_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nearestSitePoint") ) { return nearestSitePoint_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SiteList_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_sites") ) { _sites=inValue.Cast< Array< ::com::nodename::delaunay::Site > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_sorted") ) { _sorted=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_currentIndex") ) { _currentIndex=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SiteList_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("_sorted"));
	outFields->push(HX_CSTRING("_currentIndex"));
	outFields->push(HX_CSTRING("_sites"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nearestSitePoint"),
	HX_CSTRING("regions"),
	HX_CSTRING("circles"),
	HX_CSTRING("siteCoords"),
	HX_CSTRING("siteColors"),
	HX_CSTRING("getSitesBounds"),
	HX_CSTRING("next"),
	HX_CSTRING("getLength"),
	HX_CSTRING("length"),
	HX_CSTRING("push"),
	HX_CSTRING("dispose"),
	HX_CSTRING("_sorted"),
	HX_CSTRING("_currentIndex"),
	HX_CSTRING("_sites"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SiteList_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SiteList_obj::__mClass,"__mClass");
};

Class SiteList_obj::__mClass;

void SiteList_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.delaunay.SiteList"), hx::TCanCast< SiteList_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SiteList_obj::__boot()
{
}

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

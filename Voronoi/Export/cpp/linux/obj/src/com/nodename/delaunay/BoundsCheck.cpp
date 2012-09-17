#include <hxcpp.h>

#ifndef INCLUDED_com_nodename_delaunay_BoundsCheck
#include <com/nodename/delaunay/BoundsCheck.h>
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

Void BoundsCheck_obj::__construct()
{
	return null();
}

BoundsCheck_obj::~BoundsCheck_obj() { }

Dynamic BoundsCheck_obj::__CreateEmpty() { return  new BoundsCheck_obj; }
hx::ObjectPtr< BoundsCheck_obj > BoundsCheck_obj::__new()
{  hx::ObjectPtr< BoundsCheck_obj > result = new BoundsCheck_obj();
	result->__construct();
	return result;}

Dynamic BoundsCheck_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BoundsCheck_obj > result = new BoundsCheck_obj();
	result->__construct();
	return result;}

int BoundsCheck_obj::TOP;

int BoundsCheck_obj::BOTTOM;

int BoundsCheck_obj::LEFT;

int BoundsCheck_obj::RIGHT;

int BoundsCheck_obj::check( ::neash::geom::Point point,::neash::geom::Rectangle bounds){
	HX_STACK_PUSH("BoundsCheck::check","com/nodename/delaunay/BoundsCheck.hx",24);
	HX_STACK_ARG(point,"point");
	HX_STACK_ARG(bounds,"bounds");
	HX_STACK_LINE(25)
	int value = (int)0;		HX_STACK_VAR(value,"value");
	HX_STACK_LINE(26)
	if (((point->x == bounds->nmeGetLeft()))){
		HX_STACK_LINE(27)
		hx::OrEq(value,(int)4);
	}
	HX_STACK_LINE(30)
	if (((point->x == bounds->nmeGetRight()))){
		HX_STACK_LINE(31)
		hx::OrEq(value,(int)8);
	}
	HX_STACK_LINE(34)
	if (((point->y == bounds->nmeGetTop()))){
		HX_STACK_LINE(35)
		hx::OrEq(value,(int)1);
	}
	HX_STACK_LINE(38)
	if (((point->y == bounds->nmeGetBottom()))){
		HX_STACK_LINE(39)
		hx::OrEq(value,(int)2);
	}
	HX_STACK_LINE(42)
	return value;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BoundsCheck_obj,check,return )


BoundsCheck_obj::BoundsCheck_obj()
{
}

void BoundsCheck_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BoundsCheck);
	HX_MARK_END_CLASS();
}

void BoundsCheck_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic BoundsCheck_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"TOP") ) { return TOP; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"LEFT") ) { return LEFT; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"RIGHT") ) { return RIGHT; }
		if (HX_FIELD_EQ(inName,"check") ) { return check_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"BOTTOM") ) { return BOTTOM; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BoundsCheck_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"TOP") ) { TOP=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"LEFT") ) { LEFT=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"RIGHT") ) { RIGHT=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"BOTTOM") ) { BOTTOM=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BoundsCheck_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("TOP"),
	HX_CSTRING("BOTTOM"),
	HX_CSTRING("LEFT"),
	HX_CSTRING("RIGHT"),
	HX_CSTRING("check"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BoundsCheck_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(BoundsCheck_obj::TOP,"TOP");
	HX_MARK_MEMBER_NAME(BoundsCheck_obj::BOTTOM,"BOTTOM");
	HX_MARK_MEMBER_NAME(BoundsCheck_obj::LEFT,"LEFT");
	HX_MARK_MEMBER_NAME(BoundsCheck_obj::RIGHT,"RIGHT");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BoundsCheck_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(BoundsCheck_obj::TOP,"TOP");
	HX_VISIT_MEMBER_NAME(BoundsCheck_obj::BOTTOM,"BOTTOM");
	HX_VISIT_MEMBER_NAME(BoundsCheck_obj::LEFT,"LEFT");
	HX_VISIT_MEMBER_NAME(BoundsCheck_obj::RIGHT,"RIGHT");
};

Class BoundsCheck_obj::__mClass;

void BoundsCheck_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.delaunay.BoundsCheck"), hx::TCanCast< BoundsCheck_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BoundsCheck_obj::__boot()
{
	TOP= (int)1;
	BOTTOM= (int)2;
	LEFT= (int)4;
	RIGHT= (int)8;
}

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

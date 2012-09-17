#include <hxcpp.h>

#ifndef INCLUDED_com_nodename_geom_Winding
#include <com/nodename/geom/Winding.h>
#endif
namespace com{
namespace nodename{
namespace geom{

Void Winding_obj::__construct(::String name)
{
HX_STACK_PUSH("Winding::new","com/nodename/geom/Winding.hx",12);
{
	HX_STACK_LINE(12)
	this->_name = name;
}
;
	return null();
}

Winding_obj::~Winding_obj() { }

Dynamic Winding_obj::__CreateEmpty() { return  new Winding_obj; }
hx::ObjectPtr< Winding_obj > Winding_obj::__new(::String name)
{  hx::ObjectPtr< Winding_obj > result = new Winding_obj();
	result->__construct(name);
	return result;}

Dynamic Winding_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Winding_obj > result = new Winding_obj();
	result->__construct(inArgs[0]);
	return result;}

::String Winding_obj::toString( ){
	HX_STACK_PUSH("Winding::toString","com/nodename/geom/Winding.hx",17);
	HX_STACK_THIS(this);
	HX_STACK_LINE(17)
	return this->_name;
}


HX_DEFINE_DYNAMIC_FUNC0(Winding_obj,toString,return )

::com::nodename::geom::Winding Winding_obj::CLOCKWISE;

::com::nodename::geom::Winding Winding_obj::COUNTERCLOCKWISE;

::com::nodename::geom::Winding Winding_obj::NONE;


Winding_obj::Winding_obj()
{
}

void Winding_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Winding);
	HX_MARK_MEMBER_NAME(_name,"_name");
	HX_MARK_END_CLASS();
}

void Winding_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_name,"_name");
}

Dynamic Winding_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"NONE") ) { return NONE; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_name") ) { return _name; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"CLOCKWISE") ) { return CLOCKWISE; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"COUNTERCLOCKWISE") ) { return COUNTERCLOCKWISE; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Winding_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"NONE") ) { NONE=inValue.Cast< ::com::nodename::geom::Winding >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_name") ) { _name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"CLOCKWISE") ) { CLOCKWISE=inValue.Cast< ::com::nodename::geom::Winding >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"COUNTERCLOCKWISE") ) { COUNTERCLOCKWISE=inValue.Cast< ::com::nodename::geom::Winding >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Winding_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_name"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("CLOCKWISE"),
	HX_CSTRING("COUNTERCLOCKWISE"),
	HX_CSTRING("NONE"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toString"),
	HX_CSTRING("_name"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Winding_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Winding_obj::CLOCKWISE,"CLOCKWISE");
	HX_MARK_MEMBER_NAME(Winding_obj::COUNTERCLOCKWISE,"COUNTERCLOCKWISE");
	HX_MARK_MEMBER_NAME(Winding_obj::NONE,"NONE");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Winding_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Winding_obj::CLOCKWISE,"CLOCKWISE");
	HX_VISIT_MEMBER_NAME(Winding_obj::COUNTERCLOCKWISE,"COUNTERCLOCKWISE");
	HX_VISIT_MEMBER_NAME(Winding_obj::NONE,"NONE");
};

Class Winding_obj::__mClass;

void Winding_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.geom.Winding"), hx::TCanCast< Winding_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Winding_obj::__boot()
{
	CLOCKWISE= ::com::nodename::geom::Winding_obj::__new(HX_CSTRING("clockwise"));
	COUNTERCLOCKWISE= ::com::nodename::geom::Winding_obj::__new(HX_CSTRING("counterclockwise"));
	NONE= ::com::nodename::geom::Winding_obj::__new(HX_CSTRING("none"));
}

} // end namespace com
} // end namespace nodename
} // end namespace geom

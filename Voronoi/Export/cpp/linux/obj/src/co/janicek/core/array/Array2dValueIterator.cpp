#include <hxcpp.h>

#ifndef INCLUDED_co_janicek_core_array_Array2dValueIterator
#include <co/janicek/core/array/Array2dValueIterator.h>
#endif
namespace co{
namespace janicek{
namespace core{
namespace array{

Void Array2dValueIterator_obj::__construct(Dynamic a)
{
HX_STACK_PUSH("Array2dValueIterator::new","co/janicek/core/array/Array2dValueIterator.hx",13);
{
	HX_STACK_LINE(14)
	this->yIterator = a->__Field(HX_CSTRING("iterator"),true)();
	HX_STACK_LINE(15)
	this->xIterator = null();
	HX_STACK_LINE(16)
	this->nextValue = null();
}
;
	return null();
}

Array2dValueIterator_obj::~Array2dValueIterator_obj() { }

Dynamic Array2dValueIterator_obj::__CreateEmpty() { return  new Array2dValueIterator_obj; }
hx::ObjectPtr< Array2dValueIterator_obj > Array2dValueIterator_obj::__new(Dynamic a)
{  hx::ObjectPtr< Array2dValueIterator_obj > result = new Array2dValueIterator_obj();
	result->__construct(a);
	return result;}

Dynamic Array2dValueIterator_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Array2dValueIterator_obj > result = new Array2dValueIterator_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic Array2dValueIterator_obj::next( ){
	HX_STACK_PUSH("Array2dValueIterator::next","co/janicek/core/array/Array2dValueIterator.hx",44);
	HX_STACK_THIS(this);
	HX_STACK_LINE(45)
	Dynamic n = this->nextValue;		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(46)
	this->nextValue = null();
	HX_STACK_LINE(47)
	return n;
}


HX_DEFINE_DYNAMIC_FUNC0(Array2dValueIterator_obj,next,return )

bool Array2dValueIterator_obj::hasNext( ){
	HX_STACK_PUSH("Array2dValueIterator::hasNext","co/janicek/core/array/Array2dValueIterator.hx",19);
	HX_STACK_THIS(this);
	HX_STACK_LINE(20)
	if (((this->nextValue != null()))){
		HX_STACK_LINE(20)
		return true;
	}
	HX_STACK_LINE(24)
	if (((this->xIterator != null()))){
		HX_STACK_LINE(24)
		while((this->xIterator->__Field(HX_CSTRING("hasNext"),true)())){
			HX_STACK_LINE(26)
			this->nextValue = this->xIterator->__Field(HX_CSTRING("next"),true)();
			HX_STACK_LINE(27)
			if (((this->nextValue != null()))){
				HX_STACK_LINE(27)
				return true;
			}
		}
	}
	HX_STACK_LINE(33)
	while((this->yIterator->__Field(HX_CSTRING("hasNext"),true)())){
		HX_STACK_LINE(34)
		Dynamic z = this->yIterator->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(z,"z");
		HX_STACK_LINE(35)
		if (((z != null()))){
			HX_STACK_LINE(36)
			this->xIterator = z->__Field(HX_CSTRING("iterator"),true)();
			HX_STACK_LINE(37)
			return this->hasNext();
		}
	}
	HX_STACK_LINE(41)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Array2dValueIterator_obj,hasNext,return )


Array2dValueIterator_obj::Array2dValueIterator_obj()
{
}

void Array2dValueIterator_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Array2dValueIterator);
	HX_MARK_MEMBER_NAME(nextValue,"nextValue");
	HX_MARK_MEMBER_NAME(xIterator,"xIterator");
	HX_MARK_MEMBER_NAME(yIterator,"yIterator");
	HX_MARK_END_CLASS();
}

void Array2dValueIterator_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(nextValue,"nextValue");
	HX_VISIT_MEMBER_NAME(xIterator,"xIterator");
	HX_VISIT_MEMBER_NAME(yIterator,"yIterator");
}

Dynamic Array2dValueIterator_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"next") ) { return next_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"hasNext") ) { return hasNext_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nextValue") ) { return nextValue; }
		if (HX_FIELD_EQ(inName,"xIterator") ) { return xIterator; }
		if (HX_FIELD_EQ(inName,"yIterator") ) { return yIterator; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Array2dValueIterator_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"nextValue") ) { nextValue=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"xIterator") ) { xIterator=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"yIterator") ) { yIterator=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Array2dValueIterator_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nextValue"));
	outFields->push(HX_CSTRING("xIterator"));
	outFields->push(HX_CSTRING("yIterator"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("next"),
	HX_CSTRING("hasNext"),
	HX_CSTRING("nextValue"),
	HX_CSTRING("xIterator"),
	HX_CSTRING("yIterator"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Array2dValueIterator_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Array2dValueIterator_obj::__mClass,"__mClass");
};

Class Array2dValueIterator_obj::__mClass;

void Array2dValueIterator_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("co.janicek.core.array.Array2dValueIterator"), hx::TCanCast< Array2dValueIterator_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Array2dValueIterator_obj::__boot()
{
}

} // end namespace co
} // end namespace janicek
} // end namespace core
} // end namespace array

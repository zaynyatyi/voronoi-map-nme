#include <hxcpp.h>

#ifndef INCLUDED_co_janicek_core_array_Array2dIterator
#include <co/janicek/core/array/Array2dIterator.h>
#endif
namespace co{
namespace janicek{
namespace core{
namespace array{

Void Array2dIterator_obj::__construct(Dynamic a)
{
HX_STACK_PUSH("Array2dIterator::new","co/janicek/core/array/Array2dIterator.hx",16);
{
	HX_STACK_LINE(17)
	this->a = a;
	HX_STACK_LINE(18)
	this->y = (int)0;
	HX_STACK_LINE(19)
	this->x = (int)0;
	HX_STACK_LINE(20)
	this->nextValue = null();
}
;
	return null();
}

Array2dIterator_obj::~Array2dIterator_obj() { }

Dynamic Array2dIterator_obj::__CreateEmpty() { return  new Array2dIterator_obj; }
hx::ObjectPtr< Array2dIterator_obj > Array2dIterator_obj::__new(Dynamic a)
{  hx::ObjectPtr< Array2dIterator_obj > result = new Array2dIterator_obj();
	result->__construct(a);
	return result;}

Dynamic Array2dIterator_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Array2dIterator_obj > result = new Array2dIterator_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic Array2dIterator_obj::next( ){
	HX_STACK_PUSH("Array2dIterator::next","co/janicek/core/array/Array2dIterator.hx",46);
	HX_STACK_THIS(this);
	HX_STACK_LINE(47)
	Dynamic n = this->nextValue;		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(48)
	this->nextValue = null();
	HX_STACK_LINE(49)
	return n;
}


HX_DEFINE_DYNAMIC_FUNC0(Array2dIterator_obj,next,return )

bool Array2dIterator_obj::hasNext( ){
	HX_STACK_PUSH("Array2dIterator::hasNext","co/janicek/core/array/Array2dIterator.hx",23);
	HX_STACK_THIS(this);
	HX_STACK_LINE(24)
	if (((this->nextValue != null()))){
		HX_STACK_LINE(24)
		return true;
	}
	HX_STACK_LINE(28)
	while(((this->y < this->a->__Field(HX_CSTRING("length"),true)))){
		HX_STACK_LINE(29)
		if (((this->a->__GetItem(this->y) != null()))){
			HX_STACK_LINE(30)
			while(((bool((this->x < this->a->__GetItem(this->y)->__Field(HX_CSTRING("length"),true))) && bool((this->a->__GetItem(this->y)->__GetItem(this->x) == null()))))){
				HX_STACK_LINE(30)
				(this->x)++;
			}
			HX_STACK_LINE(33)
			if (((this->a->__GetItem(this->y)->__GetItem(this->x) != null()))){
				struct _Function_4_1{
					inline static Dynamic Block( ::co::janicek::core::array::Array2dIterator_obj *__this){
						HX_STACK_PUSH("*::closure","co/janicek/core/array/Array2dIterator.hx",34);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("x") , __this->x,false);
							__result->Add(HX_CSTRING("y") , __this->y,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(34)
				this->nextValue = _Function_4_1::Block(this);
				HX_STACK_LINE(35)
				(this->x)++;
				HX_STACK_LINE(36)
				return true;
			}
			HX_STACK_LINE(38)
			this->x = (int)0;
		}
		HX_STACK_LINE(40)
		(this->y)++;
	}
	HX_STACK_LINE(43)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Array2dIterator_obj,hasNext,return )


Array2dIterator_obj::Array2dIterator_obj()
{
}

void Array2dIterator_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Array2dIterator);
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(nextValue,"nextValue");
	HX_MARK_MEMBER_NAME(a,"a");
	HX_MARK_END_CLASS();
}

void Array2dIterator_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(nextValue,"nextValue");
	HX_VISIT_MEMBER_NAME(a,"a");
}

Dynamic Array2dIterator_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"a") ) { return a; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"next") ) { return next_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"hasNext") ) { return hasNext_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nextValue") ) { return nextValue; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Array2dIterator_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"a") ) { a=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nextValue") ) { nextValue=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Array2dIterator_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("nextValue"));
	outFields->push(HX_CSTRING("a"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("next"),
	HX_CSTRING("hasNext"),
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("nextValue"),
	HX_CSTRING("a"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Array2dIterator_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Array2dIterator_obj::__mClass,"__mClass");
};

Class Array2dIterator_obj::__mClass;

void Array2dIterator_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("co.janicek.core.array.Array2dIterator"), hx::TCanCast< Array2dIterator_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Array2dIterator_obj::__boot()
{
}

} // end namespace co
} // end namespace janicek
} // end namespace core
} // end namespace array

#include <hxcpp.h>

#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_List
#include <List.h>
#endif

Void Lambda_obj::__construct()
{
	return null();
}

Lambda_obj::~Lambda_obj() { }

Dynamic Lambda_obj::__CreateEmpty() { return  new Lambda_obj; }
hx::ObjectPtr< Lambda_obj > Lambda_obj::__new()
{  hx::ObjectPtr< Lambda_obj > result = new Lambda_obj();
	result->__construct();
	return result;}

Dynamic Lambda_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Lambda_obj > result = new Lambda_obj();
	result->__construct();
	return result;}

Dynamic Lambda_obj::array( Dynamic it){
	HX_STACK_PUSH("Lambda::array","/usr/lib/haxe/std/Lambda.hx",35);
	HX_STACK_ARG(it,"it");
	HX_STACK_LINE(36)
	Dynamic a = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(37)
	for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(it->__Field(HX_CSTRING("iterator"),true)());  __it->hasNext(); ){
		Dynamic i = __it->next();
		a->__Field(HX_CSTRING("push"),true)(i);
	}
	HX_STACK_LINE(39)
	return a;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lambda_obj,array,return )

::List Lambda_obj::list( Dynamic it){
	HX_STACK_PUSH("Lambda::list","/usr/lib/haxe/std/Lambda.hx",45);
	HX_STACK_ARG(it,"it");
	HX_STACK_LINE(46)
	::List l = ::List_obj::__new();		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(47)
	for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(it->__Field(HX_CSTRING("iterator"),true)());  __it->hasNext(); ){
		Dynamic i = __it->next();
		l->add(i);
	}
	HX_STACK_LINE(49)
	return l;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lambda_obj,list,return )

::List Lambda_obj::map( Dynamic it,Dynamic f){
	HX_STACK_PUSH("Lambda::map","/usr/lib/haxe/std/Lambda.hx",56);
	HX_STACK_ARG(it,"it");
	HX_STACK_ARG(f,"f");
	HX_STACK_LINE(57)
	::List l = ::List_obj::__new();		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(58)
	for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(it->__Field(HX_CSTRING("iterator"),true)());  __it->hasNext(); ){
		Dynamic x = __it->next();
		l->add(f(x));
	}
	HX_STACK_LINE(60)
	return l;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lambda_obj,map,return )

::List Lambda_obj::mapi( Dynamic it,Dynamic f){
	HX_STACK_PUSH("Lambda::mapi","/usr/lib/haxe/std/Lambda.hx",66);
	HX_STACK_ARG(it,"it");
	HX_STACK_ARG(f,"f");
	HX_STACK_LINE(67)
	::List l = ::List_obj::__new();		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(68)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(69)
	for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(it->__Field(HX_CSTRING("iterator"),true)());  __it->hasNext(); ){
		Dynamic x = __it->next();
		l->add(f((i)++,x));
	}
	HX_STACK_LINE(71)
	return l;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lambda_obj,mapi,return )

bool Lambda_obj::has( Dynamic it,Dynamic elt,Dynamic cmp){
	HX_STACK_PUSH("Lambda::has","/usr/lib/haxe/std/Lambda.hx",81);
	HX_STACK_ARG(it,"it");
	HX_STACK_ARG(elt,"elt");
	HX_STACK_ARG(cmp,"cmp");
	HX_STACK_LINE(82)
	if (((cmp == null()))){
		HX_STACK_LINE(82)
		for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(it->__Field(HX_CSTRING("iterator"),true)());  __it->hasNext(); ){
			Dynamic x = __it->next();
			if (((x == elt))){
				HX_STACK_LINE(85)
				return true;
			}
;
		}
	}
	else{
		HX_STACK_LINE(86)
		for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(it->__Field(HX_CSTRING("iterator"),true)());  __it->hasNext(); ){
			Dynamic x = __it->next();
			if ((cmp(x,elt).Cast< bool >())){
				HX_STACK_LINE(89)
				return true;
			}
;
		}
	}
	HX_STACK_LINE(91)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Lambda_obj,has,return )

bool Lambda_obj::exists( Dynamic it,Dynamic f){
	HX_STACK_PUSH("Lambda::exists","/usr/lib/haxe/std/Lambda.hx",97);
	HX_STACK_ARG(it,"it");
	HX_STACK_ARG(f,"f");
	HX_STACK_LINE(98)
	for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(it->__Field(HX_CSTRING("iterator"),true)());  __it->hasNext(); ){
		Dynamic x = __it->next();
		if ((f(x).Cast< bool >())){
			HX_STACK_LINE(100)
			return true;
		}
;
	}
	HX_STACK_LINE(101)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lambda_obj,exists,return )

bool Lambda_obj::foreach( Dynamic it,Dynamic f){
	HX_STACK_PUSH("Lambda::foreach","/usr/lib/haxe/std/Lambda.hx",107);
	HX_STACK_ARG(it,"it");
	HX_STACK_ARG(f,"f");
	HX_STACK_LINE(108)
	for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(it->__Field(HX_CSTRING("iterator"),true)());  __it->hasNext(); ){
		Dynamic x = __it->next();
		if ((!(f(x).Cast< bool >()))){
			HX_STACK_LINE(110)
			return false;
		}
;
	}
	HX_STACK_LINE(111)
	return true;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lambda_obj,foreach,return )

Void Lambda_obj::iter( Dynamic it,Dynamic f){
{
		HX_STACK_PUSH("Lambda::iter","/usr/lib/haxe/std/Lambda.hx",117);
		HX_STACK_ARG(it,"it");
		HX_STACK_ARG(f,"f");
		HX_STACK_LINE(117)
		for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(it->__Field(HX_CSTRING("iterator"),true)());  __it->hasNext(); ){
			Dynamic x = __it->next();
			f(x).Cast< Void >();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lambda_obj,iter,(void))

::List Lambda_obj::filter( Dynamic it,Dynamic f){
	HX_STACK_PUSH("Lambda::filter","/usr/lib/haxe/std/Lambda.hx",125);
	HX_STACK_ARG(it,"it");
	HX_STACK_ARG(f,"f");
	HX_STACK_LINE(126)
	::List l = ::List_obj::__new();		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(127)
	for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(it->__Field(HX_CSTRING("iterator"),true)());  __it->hasNext(); ){
		Dynamic x = __it->next();
		if ((f(x).Cast< bool >())){
			HX_STACK_LINE(129)
			l->add(x);
		}
;
	}
	HX_STACK_LINE(130)
	return l;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lambda_obj,filter,return )

Dynamic Lambda_obj::fold( Dynamic it,Dynamic f,Dynamic first){
	HX_STACK_PUSH("Lambda::fold","/usr/lib/haxe/std/Lambda.hx",136);
	HX_STACK_ARG(it,"it");
	HX_STACK_ARG(f,"f");
	HX_STACK_ARG(first,"first");
	HX_STACK_LINE(137)
	for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(it->__Field(HX_CSTRING("iterator"),true)());  __it->hasNext(); ){
		Dynamic x = __it->next();
		first = f(x,first);
	}
	HX_STACK_LINE(139)
	return first;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Lambda_obj,fold,return )

int Lambda_obj::count( Dynamic it,Dynamic pred){
	HX_STACK_PUSH("Lambda::count","/usr/lib/haxe/std/Lambda.hx",145);
	HX_STACK_ARG(it,"it");
	HX_STACK_ARG(pred,"pred");
	HX_STACK_LINE(146)
	int n = (int)0;		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(147)
	if (((pred == null()))){
		HX_STACK_LINE(148)
		for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(it->__Field(HX_CSTRING("iterator"),true)());  __it->hasNext(); ){
			Dynamic _ = __it->next();
			(n)++;
		}
	}
	else{
		HX_STACK_LINE(151)
		for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(it->__Field(HX_CSTRING("iterator"),true)());  __it->hasNext(); ){
			Dynamic x = __it->next();
			if ((pred(x).Cast< bool >())){
				HX_STACK_LINE(153)
				(n)++;
			}
;
		}
	}
	HX_STACK_LINE(154)
	return n;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lambda_obj,count,return )

bool Lambda_obj::empty( Dynamic it){
	HX_STACK_PUSH("Lambda::empty","/usr/lib/haxe/std/Lambda.hx",160);
	HX_STACK_ARG(it,"it");
	HX_STACK_LINE(160)
	return !(it->__Field(HX_CSTRING("iterator"),true)()->__Field(HX_CSTRING("hasNext"),true)());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lambda_obj,empty,return )

int Lambda_obj::indexOf( Dynamic it,Dynamic v){
	HX_STACK_PUSH("Lambda::indexOf","/usr/lib/haxe/std/Lambda.hx",168);
	HX_STACK_ARG(it,"it");
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(169)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(170)
	for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(it->__Field(HX_CSTRING("iterator"),true)());  __it->hasNext(); ){
		Dynamic v2 = __it->next();
		{
			HX_STACK_LINE(171)
			if (((v == v2))){
				HX_STACK_LINE(172)
				return i;
			}
			HX_STACK_LINE(173)
			(i)++;
		}
;
	}
	HX_STACK_LINE(175)
	return (int)-1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lambda_obj,indexOf,return )

::List Lambda_obj::concat( Dynamic a,Dynamic b){
	HX_STACK_PUSH("Lambda::concat","/usr/lib/haxe/std/Lambda.hx",181);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(182)
	::List l = ::List_obj::__new();		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(183)
	for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(a->__Field(HX_CSTRING("iterator"),true)());  __it->hasNext(); ){
		Dynamic x = __it->next();
		l->add(x);
	}
	HX_STACK_LINE(185)
	for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(b->__Field(HX_CSTRING("iterator"),true)());  __it->hasNext(); ){
		Dynamic x = __it->next();
		l->add(x);
	}
	HX_STACK_LINE(187)
	return l;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lambda_obj,concat,return )


Lambda_obj::Lambda_obj()
{
}

void Lambda_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Lambda);
	HX_MARK_END_CLASS();
}

void Lambda_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Lambda_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"map") ) { return map_dyn(); }
		if (HX_FIELD_EQ(inName,"has") ) { return has_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { return list_dyn(); }
		if (HX_FIELD_EQ(inName,"mapi") ) { return mapi_dyn(); }
		if (HX_FIELD_EQ(inName,"iter") ) { return iter_dyn(); }
		if (HX_FIELD_EQ(inName,"fold") ) { return fold_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"array") ) { return array_dyn(); }
		if (HX_FIELD_EQ(inName,"count") ) { return count_dyn(); }
		if (HX_FIELD_EQ(inName,"empty") ) { return empty_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"exists") ) { return exists_dyn(); }
		if (HX_FIELD_EQ(inName,"filter") ) { return filter_dyn(); }
		if (HX_FIELD_EQ(inName,"concat") ) { return concat_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"foreach") ) { return foreach_dyn(); }
		if (HX_FIELD_EQ(inName,"indexOf") ) { return indexOf_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Lambda_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Lambda_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("array"),
	HX_CSTRING("list"),
	HX_CSTRING("map"),
	HX_CSTRING("mapi"),
	HX_CSTRING("has"),
	HX_CSTRING("exists"),
	HX_CSTRING("foreach"),
	HX_CSTRING("iter"),
	HX_CSTRING("filter"),
	HX_CSTRING("fold"),
	HX_CSTRING("count"),
	HX_CSTRING("empty"),
	HX_CSTRING("indexOf"),
	HX_CSTRING("concat"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Lambda_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Lambda_obj::__mClass,"__mClass");
};

Class Lambda_obj::__mClass;

void Lambda_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Lambda"), hx::TCanCast< Lambda_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Lambda_obj::__boot()
{
}


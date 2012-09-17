#include <hxcpp.h>

#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_nme_ObjectHash
#include <nme/ObjectHash.h>
#endif
namespace nme{

Void ObjectHash_obj::__construct()
{
HX_STACK_PUSH("ObjectHash::new","nme/ObjectHash.hx",22);
{
	HX_STACK_LINE(30)
	this->hashKeys = ::IntHash_obj::__new();
	HX_STACK_LINE(31)
	this->hashValues = ::IntHash_obj::__new();
}
;
	return null();
}

ObjectHash_obj::~ObjectHash_obj() { }

Dynamic ObjectHash_obj::__CreateEmpty() { return  new ObjectHash_obj; }
hx::ObjectPtr< ObjectHash_obj > ObjectHash_obj::__new()
{  hx::ObjectPtr< ObjectHash_obj > result = new ObjectHash_obj();
	result->__construct();
	return result;}

Dynamic ObjectHash_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ObjectHash_obj > result = new ObjectHash_obj();
	result->__construct();
	return result;}

Void ObjectHash_obj::set( Dynamic key,Dynamic value){
{
		HX_STACK_PUSH("ObjectHash::set","nme/ObjectHash.hx",155);
		HX_STACK_THIS(this);
		HX_STACK_ARG(key,"key");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(163)
		int id = ::__hxcpp_obj_id(key);		HX_STACK_VAR(id,"id");
		HX_STACK_LINE(165)
		this->hashKeys->set(id,key);
		HX_STACK_LINE(166)
		this->hashValues->set(id,value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ObjectHash_obj,set,(void))

Void ObjectHash_obj::remove( Dynamic key){
{
		HX_STACK_PUSH("ObjectHash::remove","nme/ObjectHash.hx",137);
		HX_STACK_THIS(this);
		HX_STACK_ARG(key,"key");
		HX_STACK_LINE(145)
		int id = ::__hxcpp_obj_id(key);		HX_STACK_VAR(id,"id");
		HX_STACK_LINE(147)
		this->hashKeys->remove(id);
		HX_STACK_LINE(148)
		this->hashValues->remove(id);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ObjectHash_obj,remove,(void))

Dynamic ObjectHash_obj::keys( ){
	HX_STACK_PUSH("ObjectHash::keys","nme/ObjectHash.hx",122);
	HX_STACK_THIS(this);
	HX_STACK_LINE(122)
	return this->hashKeys->iterator();
}


HX_DEFINE_DYNAMIC_FUNC0(ObjectHash_obj,keys,return )

Dynamic ObjectHash_obj::iterator( ){
	HX_STACK_PUSH("ObjectHash::iterator","nme/ObjectHash.hx",99);
	HX_STACK_THIS(this);
	HX_STACK_LINE(99)
	return this->hashValues->iterator();
}


HX_DEFINE_DYNAMIC_FUNC0(ObjectHash_obj,iterator,return )

int ObjectHash_obj::getID( Dynamic key){
	HX_STACK_PUSH("ObjectHash::getID","nme/ObjectHash.hx",68);
	HX_STACK_THIS(this);
	HX_STACK_ARG(key,"key");
	HX_STACK_LINE(68)
	return ::__hxcpp_obj_id(key);
}


HX_DEFINE_DYNAMIC_FUNC1(ObjectHash_obj,getID,return )

Dynamic ObjectHash_obj::get( Dynamic key){
	HX_STACK_PUSH("ObjectHash::get","nme/ObjectHash.hx",53);
	HX_STACK_THIS(this);
	HX_STACK_ARG(key,"key");
	HX_STACK_LINE(53)
	return this->hashValues->get(::__hxcpp_obj_id(key));
}


HX_DEFINE_DYNAMIC_FUNC1(ObjectHash_obj,get,return )

bool ObjectHash_obj::exists( Dynamic key){
	HX_STACK_PUSH("ObjectHash::exists","nme/ObjectHash.hx",38);
	HX_STACK_THIS(this);
	HX_STACK_ARG(key,"key");
	HX_STACK_LINE(38)
	return this->hashValues->exists(::__hxcpp_obj_id(key));
}


HX_DEFINE_DYNAMIC_FUNC1(ObjectHash_obj,exists,return )

int ObjectHash_obj::nextObjectID;


ObjectHash_obj::ObjectHash_obj()
{
}

void ObjectHash_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ObjectHash);
	HX_MARK_MEMBER_NAME(hashValues,"hashValues");
	HX_MARK_MEMBER_NAME(hashKeys,"hashKeys");
	HX_MARK_END_CLASS();
}

void ObjectHash_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(hashValues,"hashValues");
	HX_VISIT_MEMBER_NAME(hashKeys,"hashKeys");
}

Dynamic ObjectHash_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"keys") ) { return keys_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"getID") ) { return getID_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		if (HX_FIELD_EQ(inName,"exists") ) { return exists_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"iterator") ) { return iterator_dyn(); }
		if (HX_FIELD_EQ(inName,"hashKeys") ) { return hashKeys; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"hashValues") ) { return hashValues; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nextObjectID") ) { return nextObjectID; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ObjectHash_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"hashKeys") ) { hashKeys=inValue.Cast< ::IntHash >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"hashValues") ) { hashValues=inValue.Cast< ::IntHash >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nextObjectID") ) { nextObjectID=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ObjectHash_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("hashValues"));
	outFields->push(HX_CSTRING("hashKeys"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("nextObjectID"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set"),
	HX_CSTRING("remove"),
	HX_CSTRING("keys"),
	HX_CSTRING("iterator"),
	HX_CSTRING("getID"),
	HX_CSTRING("get"),
	HX_CSTRING("exists"),
	HX_CSTRING("hashValues"),
	HX_CSTRING("hashKeys"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ObjectHash_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(ObjectHash_obj::nextObjectID,"nextObjectID");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ObjectHash_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ObjectHash_obj::nextObjectID,"nextObjectID");
};

Class ObjectHash_obj::__mClass;

void ObjectHash_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.ObjectHash"), hx::TCanCast< ObjectHash_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ObjectHash_obj::__boot()
{
	nextObjectID= (int)0;
}

} // end namespace nme

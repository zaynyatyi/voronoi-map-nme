#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_neash_geom_Vector3D
#include <neash/geom/Vector3D.h>
#endif
namespace neash{
namespace geom{

Void Vector3D_obj::__construct(Dynamic __o_x,Dynamic __o_y,Dynamic __o_z,Dynamic __o_w)
{
HX_STACK_PUSH("Vector3D::new","neash/geom/Vector3D.hx",20);
Dynamic x = __o_x.Default(0.);
Dynamic y = __o_y.Default(0.);
Dynamic z = __o_z.Default(0.);
Dynamic w = __o_w.Default(0.);
{
	HX_STACK_LINE(21)
	this->w = w;
	HX_STACK_LINE(22)
	this->x = x;
	HX_STACK_LINE(23)
	this->y = y;
	HX_STACK_LINE(24)
	this->z = z;
}
;
	return null();
}

Vector3D_obj::~Vector3D_obj() { }

Dynamic Vector3D_obj::__CreateEmpty() { return  new Vector3D_obj; }
hx::ObjectPtr< Vector3D_obj > Vector3D_obj::__new(Dynamic __o_x,Dynamic __o_y,Dynamic __o_z,Dynamic __o_w)
{  hx::ObjectPtr< Vector3D_obj > result = new Vector3D_obj();
	result->__construct(__o_x,__o_y,__o_z,__o_w);
	return result;}

Dynamic Vector3D_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Vector3D_obj > result = new Vector3D_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Float Vector3D_obj::nmeGetLengthSquared( ){
	HX_STACK_PUSH("Vector3D::nmeGetLengthSquared","neash/geom/Vector3D.hx",154);
	HX_STACK_THIS(this);
	HX_STACK_LINE(154)
	return (((this->x * this->x) + (this->y * this->y)) + (this->z * this->z));
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3D_obj,nmeGetLengthSquared,return )

Float Vector3D_obj::nmeGetLength( ){
	HX_STACK_PUSH("Vector3D::nmeGetLength","neash/geom/Vector3D.hx",153);
	HX_STACK_THIS(this);
	HX_STACK_LINE(153)
	return ::Math_obj::sqrt((((this->x * this->x) + (this->y * this->y)) + (this->z * this->z)));
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3D_obj,nmeGetLength,return )

::String Vector3D_obj::toString( ){
	HX_STACK_PUSH("Vector3D::toString","neash/geom/Vector3D.hx",143);
	HX_STACK_THIS(this);
	HX_STACK_LINE(143)
	return ((((((HX_CSTRING("Vector3D(") + this->x) + HX_CSTRING(", ")) + this->y) + HX_CSTRING(", ")) + this->z) + HX_CSTRING(")"));
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3D_obj,toString,return )

::neash::geom::Vector3D Vector3D_obj::subtract( ::neash::geom::Vector3D a){
	HX_STACK_PUSH("Vector3D::subtract","neash/geom/Vector3D.hx",137);
	HX_STACK_THIS(this);
	HX_STACK_ARG(a,"a");
	HX_STACK_LINE(137)
	return ::neash::geom::Vector3D_obj::__new((this->x - a->x),(this->y - a->y),(this->z - a->z),null());
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3D_obj,subtract,return )

Void Vector3D_obj::scaleBy( Float s){
{
		HX_STACK_PUSH("Vector3D::scaleBy","neash/geom/Vector3D.hx",129);
		HX_STACK_THIS(this);
		HX_STACK_ARG(s,"s");
		HX_STACK_LINE(130)
		hx::MultEq(this->x,s);
		HX_STACK_LINE(131)
		hx::MultEq(this->y,s);
		HX_STACK_LINE(132)
		hx::MultEq(this->z,s);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3D_obj,scaleBy,(void))

Void Vector3D_obj::project( ){
{
		HX_STACK_PUSH("Vector3D::project","neash/geom/Vector3D.hx",121);
		HX_STACK_THIS(this);
		HX_STACK_LINE(122)
		hx::DivEq(this->x,this->w);
		HX_STACK_LINE(123)
		hx::DivEq(this->y,this->w);
		HX_STACK_LINE(124)
		hx::DivEq(this->z,this->w);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3D_obj,project,(void))

Float Vector3D_obj::normalize( ){
	HX_STACK_PUSH("Vector3D::normalize","neash/geom/Vector3D.hx",109);
	HX_STACK_THIS(this);
	HX_STACK_LINE(110)
	Float l = ::Math_obj::sqrt((((this->x * this->x) + (this->y * this->y)) + (this->z * this->z)));		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(111)
	if (((l != (int)0))){
		HX_STACK_LINE(112)
		hx::DivEq(this->x,l);
		HX_STACK_LINE(113)
		hx::DivEq(this->y,l);
		HX_STACK_LINE(114)
		hx::DivEq(this->z,l);
	}
	HX_STACK_LINE(116)
	return l;
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3D_obj,normalize,return )

Void Vector3D_obj::negate( ){
{
		HX_STACK_PUSH("Vector3D::negate","neash/geom/Vector3D.hx",101);
		HX_STACK_THIS(this);
		HX_STACK_LINE(102)
		hx::MultEq(this->x,(int)-1);
		HX_STACK_LINE(103)
		hx::MultEq(this->y,(int)-1);
		HX_STACK_LINE(104)
		hx::MultEq(this->z,(int)-1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3D_obj,negate,(void))

bool Vector3D_obj::nearEquals( ::neash::geom::Vector3D toCompare,Float tolerance,Dynamic __o_allFour){
Dynamic allFour = __o_allFour.Default(false);
	HX_STACK_PUSH("Vector3D::nearEquals","neash/geom/Vector3D.hx",95);
	HX_STACK_THIS(this);
	HX_STACK_ARG(toCompare,"toCompare");
	HX_STACK_ARG(tolerance,"tolerance");
	HX_STACK_ARG(allFour,"allFour");
{
		HX_STACK_LINE(95)
		return (bool((bool((bool((::Math_obj::abs((this->x - toCompare->x)) < tolerance)) && bool((::Math_obj::abs((this->y - toCompare->y)) < tolerance)))) && bool((::Math_obj::abs((this->z - toCompare->z)) < tolerance)))) && bool(((bool(!(allFour)) || bool((::Math_obj::abs((this->w - toCompare->w)) < tolerance))))));
	}
}


HX_DEFINE_DYNAMIC_FUNC3(Vector3D_obj,nearEquals,return )

Void Vector3D_obj::incrementBy( ::neash::geom::Vector3D a){
{
		HX_STACK_PUSH("Vector3D::incrementBy","neash/geom/Vector3D.hx",87);
		HX_STACK_THIS(this);
		HX_STACK_ARG(a,"a");
		HX_STACK_LINE(88)
		hx::AddEq(this->x,a->x);
		HX_STACK_LINE(89)
		hx::AddEq(this->y,a->y);
		HX_STACK_LINE(90)
		hx::AddEq(this->z,a->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3D_obj,incrementBy,(void))

bool Vector3D_obj::equals( ::neash::geom::Vector3D toCompare,Dynamic __o_allFour){
Dynamic allFour = __o_allFour.Default(false);
	HX_STACK_PUSH("Vector3D::equals","neash/geom/Vector3D.hx",81);
	HX_STACK_THIS(this);
	HX_STACK_ARG(toCompare,"toCompare");
	HX_STACK_ARG(allFour,"allFour");
{
		HX_STACK_LINE(81)
		return (bool((bool((bool((this->x == toCompare->x)) && bool((this->y == toCompare->y)))) && bool((this->z == toCompare->z)))) && bool(((bool(!(allFour)) || bool((this->w == toCompare->w))))));
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Vector3D_obj,equals,return )

Float Vector3D_obj::dotProduct( ::neash::geom::Vector3D a){
	HX_STACK_PUSH("Vector3D::dotProduct","neash/geom/Vector3D.hx",75);
	HX_STACK_THIS(this);
	HX_STACK_ARG(a,"a");
	HX_STACK_LINE(75)
	return (((this->x * a->x) + (this->y * a->y)) + (this->z * a->z));
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3D_obj,dotProduct,return )

Void Vector3D_obj::decrementBy( ::neash::geom::Vector3D a){
{
		HX_STACK_PUSH("Vector3D::decrementBy","neash/geom/Vector3D.hx",57);
		HX_STACK_THIS(this);
		HX_STACK_ARG(a,"a");
		HX_STACK_LINE(58)
		hx::SubEq(this->x,a->x);
		HX_STACK_LINE(59)
		hx::SubEq(this->y,a->y);
		HX_STACK_LINE(60)
		hx::SubEq(this->z,a->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3D_obj,decrementBy,(void))

::neash::geom::Vector3D Vector3D_obj::crossProduct( ::neash::geom::Vector3D a){
	HX_STACK_PUSH("Vector3D::crossProduct","neash/geom/Vector3D.hx",51);
	HX_STACK_THIS(this);
	HX_STACK_ARG(a,"a");
	HX_STACK_LINE(51)
	return ::neash::geom::Vector3D_obj::__new(((this->y * a->z) - (this->z * a->y)),((this->z * a->x) - (this->x * a->z)),((this->x * a->y) - (this->y * a->x)),(int)1);
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3D_obj,crossProduct,return )

::neash::geom::Vector3D Vector3D_obj::clone( ){
	HX_STACK_PUSH("Vector3D::clone","neash/geom/Vector3D.hx",45);
	HX_STACK_THIS(this);
	HX_STACK_LINE(45)
	return ::neash::geom::Vector3D_obj::__new(this->x,this->y,this->z,this->w);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3D_obj,clone,return )

::neash::geom::Vector3D Vector3D_obj::add( ::neash::geom::Vector3D a){
	HX_STACK_PUSH("Vector3D::add","neash/geom/Vector3D.hx",29);
	HX_STACK_THIS(this);
	HX_STACK_ARG(a,"a");
	HX_STACK_LINE(29)
	return ::neash::geom::Vector3D_obj::__new((this->x + a->x),(this->y + a->y),(this->z + a->z),null());
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3D_obj,add,return )

::neash::geom::Vector3D Vector3D_obj::X_AXIS;

::neash::geom::Vector3D Vector3D_obj::Y_AXIS;

::neash::geom::Vector3D Vector3D_obj::Z_AXIS;

Float Vector3D_obj::angleBetween( ::neash::geom::Vector3D a,::neash::geom::Vector3D b){
	HX_STACK_PUSH("Vector3D::angleBetween","neash/geom/Vector3D.hx",35);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(36)
	::neash::geom::Vector3D a0 = ::neash::geom::Vector3D_obj::__new(a->x,a->y,a->z,a->w);		HX_STACK_VAR(a0,"a0");
	HX_STACK_LINE(37)
	{
		HX_STACK_LINE(37)
		Float l = ::Math_obj::sqrt((((a0->x * a0->x) + (a0->y * a0->y)) + (a0->z * a0->z)));		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(37)
		if (((l != (int)0))){
			HX_STACK_LINE(37)
			hx::DivEq(a0->x,l);
			HX_STACK_LINE(37)
			hx::DivEq(a0->y,l);
			HX_STACK_LINE(37)
			hx::DivEq(a0->z,l);
		}
		HX_STACK_LINE(37)
		l;
	}
	HX_STACK_LINE(38)
	::neash::geom::Vector3D b0 = ::neash::geom::Vector3D_obj::__new(b->x,b->y,b->z,b->w);		HX_STACK_VAR(b0,"b0");
	HX_STACK_LINE(39)
	{
		HX_STACK_LINE(39)
		Float l = ::Math_obj::sqrt((((b0->x * b0->x) + (b0->y * b0->y)) + (b0->z * b0->z)));		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(39)
		if (((l != (int)0))){
			HX_STACK_LINE(39)
			hx::DivEq(b0->x,l);
			HX_STACK_LINE(39)
			hx::DivEq(b0->y,l);
			HX_STACK_LINE(39)
			hx::DivEq(b0->z,l);
		}
		HX_STACK_LINE(39)
		l;
	}
	HX_STACK_LINE(40)
	return ::Math_obj::acos((((a0->x * b0->x) + (a0->y * b0->y)) + (a0->z * b0->z)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector3D_obj,angleBetween,return )

Float Vector3D_obj::distance( ::neash::geom::Vector3D pt1,::neash::geom::Vector3D pt2){
	HX_STACK_PUSH("Vector3D::distance","neash/geom/Vector3D.hx",65);
	HX_STACK_ARG(pt1,"pt1");
	HX_STACK_ARG(pt2,"pt2");
	HX_STACK_LINE(66)
	Float x = (pt2->x - pt1->x);		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(67)
	Float y = (pt2->y - pt1->y);		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(68)
	Float z = (pt2->z - pt1->z);		HX_STACK_VAR(z,"z");
	HX_STACK_LINE(70)
	return ::Math_obj::sqrt((((x * x) + (y * y)) + (z * z)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector3D_obj,distance,return )

::neash::geom::Vector3D Vector3D_obj::nmeGetX_AXIS( ){
	HX_STACK_PUSH("Vector3D::nmeGetX_AXIS","neash/geom/Vector3D.hx",155);
	HX_STACK_LINE(155)
	return ::neash::geom::Vector3D_obj::__new((int)1,(int)0,(int)0,null());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Vector3D_obj,nmeGetX_AXIS,return )

::neash::geom::Vector3D Vector3D_obj::nmeGetY_AXIS( ){
	HX_STACK_PUSH("Vector3D::nmeGetY_AXIS","neash/geom/Vector3D.hx",156);
	HX_STACK_LINE(156)
	return ::neash::geom::Vector3D_obj::__new((int)0,(int)1,(int)0,null());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Vector3D_obj,nmeGetY_AXIS,return )

::neash::geom::Vector3D Vector3D_obj::nmeGetZ_AXIS( ){
	HX_STACK_PUSH("Vector3D::nmeGetZ_AXIS","neash/geom/Vector3D.hx",157);
	HX_STACK_LINE(157)
	return ::neash::geom::Vector3D_obj::__new((int)0,(int)0,(int)1,null());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Vector3D_obj,nmeGetZ_AXIS,return )


Vector3D_obj::Vector3D_obj()
{
}

void Vector3D_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Vector3D);
	HX_MARK_MEMBER_NAME(z,"z");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(w,"w");
	HX_MARK_MEMBER_NAME(lengthSquared,"lengthSquared");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_END_CLASS();
}

void Vector3D_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(z,"z");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(w,"w");
	HX_VISIT_MEMBER_NAME(lengthSquared,"lengthSquared");
	HX_VISIT_MEMBER_NAME(length,"length");
}

Dynamic Vector3D_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"z") ) { return z; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"w") ) { return w; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"X_AXIS") ) { return inCallProp ? nmeGetX_AXIS() : X_AXIS; }
		if (HX_FIELD_EQ(inName,"Y_AXIS") ) { return inCallProp ? nmeGetY_AXIS() : Y_AXIS; }
		if (HX_FIELD_EQ(inName,"Z_AXIS") ) { return inCallProp ? nmeGetZ_AXIS() : Z_AXIS; }
		if (HX_FIELD_EQ(inName,"negate") ) { return negate_dyn(); }
		if (HX_FIELD_EQ(inName,"equals") ) { return equals_dyn(); }
		if (HX_FIELD_EQ(inName,"length") ) { return inCallProp ? nmeGetLength() : length; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"scaleBy") ) { return scaleBy_dyn(); }
		if (HX_FIELD_EQ(inName,"project") ) { return project_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"distance") ) { return distance_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"subtract") ) { return subtract_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"normalize") ) { return normalize_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"nearEquals") ) { return nearEquals_dyn(); }
		if (HX_FIELD_EQ(inName,"dotProduct") ) { return dotProduct_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"incrementBy") ) { return incrementBy_dyn(); }
		if (HX_FIELD_EQ(inName,"decrementBy") ) { return decrementBy_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"angleBetween") ) { return angleBetween_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetX_AXIS") ) { return nmeGetX_AXIS_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetY_AXIS") ) { return nmeGetY_AXIS_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetZ_AXIS") ) { return nmeGetZ_AXIS_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetLength") ) { return nmeGetLength_dyn(); }
		if (HX_FIELD_EQ(inName,"crossProduct") ) { return crossProduct_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"lengthSquared") ) { return inCallProp ? nmeGetLengthSquared() : lengthSquared; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nmeGetLengthSquared") ) { return nmeGetLengthSquared_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Vector3D_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"z") ) { z=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"w") ) { w=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"X_AXIS") ) { X_AXIS=inValue.Cast< ::neash::geom::Vector3D >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Y_AXIS") ) { Y_AXIS=inValue.Cast< ::neash::geom::Vector3D >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Z_AXIS") ) { Z_AXIS=inValue.Cast< ::neash::geom::Vector3D >(); return inValue; }
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"lengthSquared") ) { lengthSquared=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Vector3D_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("z"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("w"));
	outFields->push(HX_CSTRING("lengthSquared"));
	outFields->push(HX_CSTRING("length"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("X_AXIS"),
	HX_CSTRING("Y_AXIS"),
	HX_CSTRING("Z_AXIS"),
	HX_CSTRING("angleBetween"),
	HX_CSTRING("distance"),
	HX_CSTRING("nmeGetX_AXIS"),
	HX_CSTRING("nmeGetY_AXIS"),
	HX_CSTRING("nmeGetZ_AXIS"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeGetLengthSquared"),
	HX_CSTRING("nmeGetLength"),
	HX_CSTRING("toString"),
	HX_CSTRING("subtract"),
	HX_CSTRING("scaleBy"),
	HX_CSTRING("project"),
	HX_CSTRING("normalize"),
	HX_CSTRING("negate"),
	HX_CSTRING("nearEquals"),
	HX_CSTRING("incrementBy"),
	HX_CSTRING("equals"),
	HX_CSTRING("dotProduct"),
	HX_CSTRING("decrementBy"),
	HX_CSTRING("crossProduct"),
	HX_CSTRING("clone"),
	HX_CSTRING("add"),
	HX_CSTRING("z"),
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	HX_CSTRING("w"),
	HX_CSTRING("lengthSquared"),
	HX_CSTRING("length"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Vector3D_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Vector3D_obj::X_AXIS,"X_AXIS");
	HX_MARK_MEMBER_NAME(Vector3D_obj::Y_AXIS,"Y_AXIS");
	HX_MARK_MEMBER_NAME(Vector3D_obj::Z_AXIS,"Z_AXIS");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Vector3D_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Vector3D_obj::X_AXIS,"X_AXIS");
	HX_VISIT_MEMBER_NAME(Vector3D_obj::Y_AXIS,"Y_AXIS");
	HX_VISIT_MEMBER_NAME(Vector3D_obj::Z_AXIS,"Z_AXIS");
};

Class Vector3D_obj::__mClass;

void Vector3D_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.geom.Vector3D"), hx::TCanCast< Vector3D_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Vector3D_obj::__boot()
{
}

} // end namespace neash
} // end namespace geom

#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_co_janicek_core_array_Array2dCore
#include <co/janicek/core/array/Array2dCore.h>
#endif
#ifndef INCLUDED_co_janicek_core_array_Array2dIterator
#include <co/janicek/core/array/Array2dIterator.h>
#endif
#ifndef INCLUDED_co_janicek_core_array_Array2dValueIterator
#include <co/janicek/core/array/Array2dValueIterator.h>
#endif
namespace co{
namespace janicek{
namespace core{
namespace array{

Void Array2dCore_obj::__construct()
{
	return null();
}

Array2dCore_obj::~Array2dCore_obj() { }

Dynamic Array2dCore_obj::__CreateEmpty() { return  new Array2dCore_obj; }
hx::ObjectPtr< Array2dCore_obj > Array2dCore_obj::__new()
{  hx::ObjectPtr< Array2dCore_obj > result = new Array2dCore_obj();
	result->__construct();
	return result;}

Dynamic Array2dCore_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Array2dCore_obj > result = new Array2dCore_obj();
	result->__construct();
	return result;}

Dynamic Array2dCore_obj::get( Dynamic a,int x,int y){
	HX_STACK_PUSH("Array2dCore::get","co/janicek/core/array/Array2dCore.hx",13);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(14)
	if (((a->__GetItem(y) == null()))){
		HX_STACK_LINE(14)
		return null();
	}
	HX_STACK_LINE(17)
	return a->__GetItem(y)->__GetItem(x);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Array2dCore_obj,get,return )

Dynamic Array2dCore_obj::set( Dynamic a,int x,int y,Dynamic value){
	HX_STACK_PUSH("Array2dCore::set","co/janicek/core/array/Array2dCore.hx",23);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(24)
	if (((a->__GetItem(y) == null()))){
		HX_STACK_LINE(24)
		hx::IndexRef((a).mPtr,y) = Dynamic( Array_obj<Dynamic>::__new() );
	}
	HX_STACK_LINE(27)
	hx::IndexRef((a->__GetItem(y)).mPtr,x) = value;
	HX_STACK_LINE(28)
	return a;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Array2dCore_obj,set,return )

Dynamic Array2dCore_obj::getIndices( int index,int width,hx::Null< int >  __o_blockSize){
int blockSize = __o_blockSize.Default(1);
	HX_STACK_PUSH("Array2dCore::getIndices","co/janicek/core/array/Array2dCore.hx",34);
	HX_STACK_ARG(index,"index");
	HX_STACK_ARG(width,"width");
	HX_STACK_ARG(blockSize,"blockSize");
{
		struct _Function_1_1{
			inline static Dynamic Block( int &index,int &width,int &blockSize){
				HX_STACK_PUSH("*::closure","co/janicek/core/array/Array2dCore.hx",35);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("x") , hx::Mod(::Std_obj::_int((Float(index) / Float(blockSize))),width),false);
					__result->Add(HX_CSTRING("y") , ::Std_obj::_int((Float((Float(index) / Float(blockSize))) / Float(width))),false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(34)
		return _Function_1_1::Block(index,width,blockSize);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Array2dCore_obj,getIndices,return )

Void Array2dCore_obj::foreachY( Dynamic a,Dynamic f){
{
		HX_STACK_PUSH("Array2dCore::foreachY","co/janicek/core/array/Array2dCore.hx",41);
		HX_STACK_ARG(a,"a");
		HX_STACK_ARG(f,"f");
		HX_STACK_LINE(42)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(42)
		while(((_g < a->__Field(HX_CSTRING("length"),true)))){
			HX_STACK_LINE(42)
			Dynamic y = a->__GetItem(_g);		HX_STACK_VAR(y,"y");
			HX_STACK_LINE(42)
			++(_g);
			HX_STACK_LINE(43)
			if (((y != null()))){
				HX_STACK_LINE(43)
				f(y).Cast< Void >();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Array2dCore_obj,foreachY,(void))

Void Array2dCore_obj::foreachXY( Dynamic a,Dynamic f){
{
		HX_STACK_PUSH("Array2dCore::foreachXY","co/janicek/core/array/Array2dCore.hx",49);
		HX_STACK_ARG(a,"a");
		HX_STACK_ARG(f,"f");
		HX_STACK_LINE(50)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = a->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(50)
		while(((_g1 < _g))){
			HX_STACK_LINE(50)
			int yIndex = (_g1)++;		HX_STACK_VAR(yIndex,"yIndex");
			HX_STACK_LINE(51)
			if (((a->__GetItem(yIndex) != null()))){
				HX_STACK_LINE(52)
				int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
				int _g2 = a->__GetItem(yIndex)->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(52)
				while(((_g3 < _g2))){
					HX_STACK_LINE(52)
					int xIndex = (_g3)++;		HX_STACK_VAR(xIndex,"xIndex");
					HX_STACK_LINE(53)
					Dynamic value = a->__GetItem(yIndex)->__GetItem(xIndex);		HX_STACK_VAR(value,"value");
					HX_STACK_LINE(54)
					if (((value != null()))){
						HX_STACK_LINE(54)
						f(xIndex,yIndex,value).Cast< Void >();
					}
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Array2dCore_obj,foreachXY,(void))

Dynamic Array2dCore_obj::any( Dynamic a,Dynamic f){
	HX_STACK_PUSH("Array2dCore::any","co/janicek/core/array/Array2dCore.hx",63);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(f,"f");
	HX_STACK_LINE(64)
	{
		HX_STACK_LINE(64)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = a->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(64)
		while(((_g1 < _g))){
			HX_STACK_LINE(64)
			int yIndex = (_g1)++;		HX_STACK_VAR(yIndex,"yIndex");
			HX_STACK_LINE(65)
			if (((a->__GetItem(yIndex) != null()))){
				HX_STACK_LINE(66)
				int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
				int _g2 = a->__GetItem(yIndex)->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(66)
				while(((_g3 < _g2))){
					HX_STACK_LINE(66)
					int xIndex = (_g3)++;		HX_STACK_VAR(xIndex,"xIndex");
					HX_STACK_LINE(67)
					Dynamic value = a->__GetItem(yIndex)->__GetItem(xIndex);		HX_STACK_VAR(value,"value");
					HX_STACK_LINE(68)
					if (((value != null()))){
						HX_STACK_LINE(68)
						if ((f(value).Cast< bool >())){
							struct _Function_7_1{
								inline static Dynamic Block( int &xIndex,int &yIndex){
									HX_STACK_PUSH("*::closure","co/janicek/core/array/Array2dCore.hx",70);
									{
										hx::Anon __result = hx::Anon_obj::Create();
										__result->Add(HX_CSTRING("x") , xIndex,false);
										__result->Add(HX_CSTRING("y") , yIndex,false);
										return __result;
									}
									return null();
								}
							};
							HX_STACK_LINE(69)
							return _Function_7_1::Block(xIndex,yIndex);
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(76)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Array2dCore_obj,any,return )

Dynamic Array2dCore_obj::dimensions( Dynamic array){
	HX_STACK_PUSH("Array2dCore::dimensions","co/janicek/core/array/Array2dCore.hx",82);
	HX_STACK_ARG(array,"array");
	HX_STACK_LINE(83)
	int height = array->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(height,"height");
	HX_STACK_LINE(84)
	Array< int > width = Array_obj< int >::__new().Add((int)0);		HX_STACK_VAR(width,"width");

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< int >,width)
	Void run(Dynamic y){
		HX_STACK_PUSH("*::_Function_1_1","co/janicek/core/array/Array2dCore.hx",86);
		HX_STACK_ARG(y,"y");
		{
			HX_STACK_LINE(86)
			width[(int)0] = ::Math_obj::max(width->__get((int)0),y->__Field(HX_CSTRING("length"),true));
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(86)
	::co::janicek::core::array::Array2dCore_obj::foreachY(array, Dynamic(new _Function_1_1(width)));
	struct _Function_1_2{
		inline static Dynamic Block( Array< int > &width,int &height){
			HX_STACK_PUSH("*::closure","co/janicek/core/array/Array2dCore.hx",90);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , width->__get((int)0),false);
				__result->Add(HX_CSTRING("y") , height,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(90)
	return _Function_1_2::Block(width,height);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Array2dCore_obj,dimensions,return )

Dynamic Array2dCore_obj::values( Dynamic array){
	HX_STACK_PUSH("Array2dCore::values","co/janicek/core/array/Array2dCore.hx",96);
	HX_STACK_ARG(array,"array");
	HX_STACK_LINE(96)
	Dynamic array1 = Dynamic( Array_obj<Dynamic>::__new().Add(array));		HX_STACK_VAR(array1,"array1");
	struct _Function_1_1{
		inline static Dynamic Block( Dynamic &array1){
			HX_STACK_PUSH("*::closure","co/janicek/core/array/Array2dCore.hx",97);
			{
				hx::Anon __result = hx::Anon_obj::Create();

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Dynamic,array1)
				::co::janicek::core::array::Array2dValueIterator run(){
					HX_STACK_PUSH("*::_Function_2_1","co/janicek/core/array/Array2dCore.hx",97);
					{
						HX_STACK_LINE(97)
						return ::co::janicek::core::array::Array2dValueIterator_obj::__new(array1->__GetItem((int)0));
					}
					return null();
				}
				HX_END_LOCAL_FUNC0(return)

				__result->Add(HX_CSTRING("iterator") ,  Dynamic(new _Function_2_1(array1)),true);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(96)
	return _Function_1_1::Block(array1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Array2dCore_obj,values,return )

Dynamic Array2dCore_obj::indexes( Dynamic array){
	HX_STACK_PUSH("Array2dCore::indexes","co/janicek/core/array/Array2dCore.hx",103);
	HX_STACK_ARG(array,"array");
	HX_STACK_LINE(103)
	Dynamic array1 = Dynamic( Array_obj<Dynamic>::__new().Add(array));		HX_STACK_VAR(array1,"array1");
	struct _Function_1_1{
		inline static Dynamic Block( Dynamic &array1){
			HX_STACK_PUSH("*::closure","co/janicek/core/array/Array2dCore.hx",104);
			{
				hx::Anon __result = hx::Anon_obj::Create();

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Dynamic,array1)
				::co::janicek::core::array::Array2dIterator run(){
					HX_STACK_PUSH("*::_Function_2_1","co/janicek/core/array/Array2dCore.hx",104);
					{
						HX_STACK_LINE(104)
						return ::co::janicek::core::array::Array2dIterator_obj::__new(array1->__GetItem((int)0));
					}
					return null();
				}
				HX_END_LOCAL_FUNC0(return)

				__result->Add(HX_CSTRING("iterator") ,  Dynamic(new _Function_2_1(array1)),true);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(103)
	return _Function_1_1::Block(array1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Array2dCore_obj,indexes,return )


Array2dCore_obj::Array2dCore_obj()
{
}

void Array2dCore_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Array2dCore);
	HX_MARK_END_CLASS();
}

void Array2dCore_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Array2dCore_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"any") ) { return any_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"values") ) { return values_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"indexes") ) { return indexes_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"foreachY") ) { return foreachY_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"foreachXY") ) { return foreachXY_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getIndices") ) { return getIndices_dyn(); }
		if (HX_FIELD_EQ(inName,"dimensions") ) { return dimensions_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Array2dCore_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Array2dCore_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("get"),
	HX_CSTRING("set"),
	HX_CSTRING("getIndices"),
	HX_CSTRING("foreachY"),
	HX_CSTRING("foreachXY"),
	HX_CSTRING("any"),
	HX_CSTRING("dimensions"),
	HX_CSTRING("values"),
	HX_CSTRING("indexes"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Array2dCore_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Array2dCore_obj::__mClass,"__mClass");
};

Class Array2dCore_obj::__mClass;

void Array2dCore_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("co.janicek.core.array.Array2dCore"), hx::TCanCast< Array2dCore_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Array2dCore_obj::__boot()
{
}

} // end namespace co
} // end namespace janicek
} // end namespace core
} // end namespace array

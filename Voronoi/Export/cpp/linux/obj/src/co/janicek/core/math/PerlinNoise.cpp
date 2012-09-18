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
#ifndef INCLUDED_co_janicek_core_math_PerlinNoise
#include <co/janicek/core/math/PerlinNoise.h>
#endif
namespace co{
namespace janicek{
namespace core{
namespace math{

Void PerlinNoise_obj::__construct()
{
	return null();
}

PerlinNoise_obj::~PerlinNoise_obj() { }

Dynamic PerlinNoise_obj::__CreateEmpty() { return  new PerlinNoise_obj; }
hx::ObjectPtr< PerlinNoise_obj > PerlinNoise_obj::__new()
{  hx::ObjectPtr< PerlinNoise_obj > result = new PerlinNoise_obj();
	result->__construct();
	return result;}

Dynamic PerlinNoise_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PerlinNoise_obj > result = new PerlinNoise_obj();
	result->__construct();
	return result;}

Array< int > PerlinNoise_obj::p;

Array< Array< int > > PerlinNoise_obj::makePerlinNoise( int width,int height,Float _x,Float _y,Float _z,hx::Null< int >  __o_seed,hx::Null< int >  __o_octaves,hx::Null< Float >  __o_falloff,Dynamic _){
int seed = __o_seed.Default(666);
int octaves = __o_octaves.Default(4);
Float falloff = __o_falloff.Default(0.5);
	HX_STACK_PUSH("PerlinNoise::makePerlinNoise","co/janicek/core/math/PerlinNoise.hx",74);
	HX_STACK_ARG(width,"width");
	HX_STACK_ARG(height,"height");
	HX_STACK_ARG(_x,"_x");
	HX_STACK_ARG(_y,"_y");
	HX_STACK_ARG(_z,"_z");
	HX_STACK_ARG(seed,"seed");
	HX_STACK_ARG(octaves,"octaves");
	HX_STACK_ARG(falloff,"falloff");
	HX_STACK_ARG(_,"_");
{
		HX_STACK_LINE(76)
		Float baseFactor = 0.015625;		HX_STACK_VAR(baseFactor,"baseFactor");
		HX_STACK_LINE(78)
		int iXoffset = seed = ::Std_obj::_int(hx::Mod((seed * 16807.),(int)2147483647));		HX_STACK_VAR(iXoffset,"iXoffset");
		HX_STACK_LINE(79)
		int iYoffset = seed = ::Std_obj::_int(hx::Mod((seed * 16807.),(int)2147483647));		HX_STACK_VAR(iYoffset,"iYoffset");
		HX_STACK_LINE(80)
		int iZoffset = seed = ::Std_obj::_int(hx::Mod((seed * 16807.),(int)2147483647));		HX_STACK_VAR(iZoffset,"iZoffset");
		HX_STACK_LINE(82)
		Array< Float > aOctFreq = Array_obj< Float >::__new();		HX_STACK_VAR(aOctFreq,"aOctFreq");
		HX_STACK_LINE(83)
		Array< Float > aOctPers = Array_obj< Float >::__new();		HX_STACK_VAR(aOctPers,"aOctPers");
		HX_STACK_LINE(84)
		Float fPersMax = 0.0;		HX_STACK_VAR(fPersMax,"fPersMax");
		HX_STACK_LINE(86)
		Float fFreq;		HX_STACK_VAR(fFreq,"fFreq");
		Float fPers;		HX_STACK_VAR(fPers,"fPers");
		HX_STACK_LINE(88)
		{
			HX_STACK_LINE(88)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(88)
			while(((_g < octaves))){
				HX_STACK_LINE(88)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(89)
				fFreq = ::Math_obj::pow((int)2,i);
				HX_STACK_LINE(90)
				fPers = ::Math_obj::pow(falloff,i);
				HX_STACK_LINE(91)
				hx::AddEq(fPersMax,fPers);
				HX_STACK_LINE(92)
				aOctFreq->push(fFreq);
				HX_STACK_LINE(93)
				aOctPers->push(fPers);
			}
		}
		HX_STACK_LINE(96)
		fPersMax = (Float((int)1) / Float(fPersMax));
		HX_STACK_LINE(98)
		Array< Array< int > > bitmap = Array_obj< Array< int > >::__new();		HX_STACK_VAR(bitmap,"bitmap");
		HX_STACK_LINE(100)
		Float baseX = ((_x * baseFactor) + iXoffset);		HX_STACK_VAR(baseX,"baseX");
		HX_STACK_LINE(101)
		_y = ((_y * baseFactor) + iYoffset);
		HX_STACK_LINE(102)
		_z = ((_z * baseFactor) + iZoffset);
		HX_STACK_LINE(104)
		{
			HX_STACK_LINE(104)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(104)
			while(((_g < height))){
				HX_STACK_LINE(104)
				int py = (_g)++;		HX_STACK_VAR(py,"py");
				HX_STACK_LINE(105)
				_x = baseX;
				HX_STACK_LINE(107)
				{
					HX_STACK_LINE(107)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(107)
					while(((_g1 < width))){
						HX_STACK_LINE(107)
						int px = (_g1)++;		HX_STACK_VAR(px,"px");
						HX_STACK_LINE(108)
						Float s = 0.;		HX_STACK_VAR(s,"s");
						HX_STACK_LINE(110)
						{
							HX_STACK_LINE(110)
							int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
							HX_STACK_LINE(110)
							while(((_g2 < octaves))){
								HX_STACK_LINE(110)
								int i = (_g2)++;		HX_STACK_VAR(i,"i");
								HX_STACK_LINE(111)
								Float fFreq1 = aOctFreq->__get(i);		HX_STACK_VAR(fFreq1,"fFreq1");
								HX_STACK_LINE(112)
								Float fPers1 = aOctPers->__get(i);		HX_STACK_VAR(fPers1,"fPers1");
								HX_STACK_LINE(114)
								Float x = (_x * fFreq1);		HX_STACK_VAR(x,"x");
								HX_STACK_LINE(115)
								Float y = (_y * fFreq1);		HX_STACK_VAR(y,"y");
								HX_STACK_LINE(116)
								Float z = (_z * fFreq1);		HX_STACK_VAR(z,"z");
								HX_STACK_LINE(118)
								Float xf = (x - hx::Mod(x,(int)1));		HX_STACK_VAR(xf,"xf");
								HX_STACK_LINE(119)
								Float yf = (y - hx::Mod(y,(int)1));		HX_STACK_VAR(yf,"yf");
								HX_STACK_LINE(120)
								Float zf = (z - hx::Mod(z,(int)1));		HX_STACK_VAR(zf,"zf");
								HX_STACK_LINE(122)
								int X = (int(::Std_obj::_int(xf)) & int((int)255));		HX_STACK_VAR(X,"X");
								HX_STACK_LINE(123)
								int Y = (int(::Std_obj::_int(yf)) & int((int)255));		HX_STACK_VAR(Y,"Y");
								HX_STACK_LINE(124)
								int Z = (int(::Std_obj::_int(zf)) & int((int)255));		HX_STACK_VAR(Z,"Z");
								HX_STACK_LINE(126)
								hx::SubEq(x,xf);
								HX_STACK_LINE(127)
								hx::SubEq(y,yf);
								HX_STACK_LINE(128)
								hx::SubEq(z,zf);
								HX_STACK_LINE(130)
								Float u = (((x * x) * x) * (((x * (((x * (int)6) - (int)15))) + (int)10)));		HX_STACK_VAR(u,"u");
								HX_STACK_LINE(131)
								Float v = (((y * y) * y) * (((y * (((y * (int)6) - (int)15))) + (int)10)));		HX_STACK_VAR(v,"v");
								HX_STACK_LINE(132)
								Float w = (((z * z) * z) * (((z * (((z * (int)6) - (int)15))) + (int)10)));		HX_STACK_VAR(w,"w");
								HX_STACK_LINE(134)
								int A = (::co::janicek::core::math::PerlinNoise_obj::p->__get(X) + Y);		HX_STACK_VAR(A,"A");
								HX_STACK_LINE(135)
								int AA = (::co::janicek::core::math::PerlinNoise_obj::p->__get(A) + Z);		HX_STACK_VAR(AA,"AA");
								HX_STACK_LINE(136)
								int AB = (::co::janicek::core::math::PerlinNoise_obj::p->__get((A + (int)1)) + Z);		HX_STACK_VAR(AB,"AB");
								HX_STACK_LINE(137)
								int B = (::co::janicek::core::math::PerlinNoise_obj::p->__get((X + (int)1)) + Y);		HX_STACK_VAR(B,"B");
								HX_STACK_LINE(138)
								int BA = (::co::janicek::core::math::PerlinNoise_obj::p->__get(B) + Z);		HX_STACK_VAR(BA,"BA");
								HX_STACK_LINE(139)
								int BB = (::co::janicek::core::math::PerlinNoise_obj::p->__get((B + (int)1)) + Z);		HX_STACK_VAR(BB,"BB");
								HX_STACK_LINE(141)
								Float x1 = (x - (int)1);		HX_STACK_VAR(x1,"x1");
								HX_STACK_LINE(142)
								Float y1 = (y - (int)1);		HX_STACK_VAR(y1,"y1");
								HX_STACK_LINE(143)
								Float z1 = (z - (int)1);		HX_STACK_VAR(z1,"z1");
								HX_STACK_LINE(145)
								int hash = (int(::co::janicek::core::math::PerlinNoise_obj::p->__get((BB + (int)1))) & int((int)15));		HX_STACK_VAR(hash,"hash");
								struct _Function_7_1{
									inline static Float Block( Float &y1,Float &x1,int &hash){
										HX_STACK_PUSH("*::closure","co/janicek/core/math/PerlinNoise.hx",146);
										{
											HX_STACK_LINE(146)
											return (  (((hash < (int)8))) ? Float(x1) : Float(y1) );
										}
										return null();
									}
								};
								struct _Function_7_2{
									inline static Float Block( Float &y1,Float &x1,int &hash,Float &z1){
										HX_STACK_PUSH("*::closure","co/janicek/core/math/PerlinNoise.hx",146);
										{
											HX_STACK_LINE(146)
											return (  (((hash < (int)4))) ? Float(y1) : Float((  (((hash == (int)12))) ? Float(x1) : Float(z1) )) );
										}
										return null();
									}
								};
								HX_STACK_LINE(146)
								Float g1 = (((  (((((int(hash) & int((int)1))) == (int)0))) ? Float(_Function_7_1::Block(y1,x1,hash)) : Float((  (((hash < (int)8))) ? Float(-(x1)) : Float(-(y1)) )) )) + ((  (((((int(hash) & int((int)2))) == (int)0))) ? Float(_Function_7_2::Block(y1,x1,hash,z1)) : Float((  (((hash < (int)4))) ? Float(-(y1)) : Float((  (((hash == (int)14))) ? Float(-(x1)) : Float(-(z1)) )) )) )));		HX_STACK_VAR(g1,"g1");
								HX_STACK_LINE(148)
								hash = (int(::co::janicek::core::math::PerlinNoise_obj::p->__get((AB + (int)1))) & int((int)15));
								struct _Function_7_3{
									inline static Float Block( Float &y1,int &hash,Float &x){
										HX_STACK_PUSH("*::closure","co/janicek/core/math/PerlinNoise.hx",149);
										{
											HX_STACK_LINE(149)
											return (  (((hash < (int)8))) ? Float(x) : Float(y1) );
										}
										return null();
									}
								};
								struct _Function_7_4{
									inline static Float Block( Float &y1,int &hash,Float &x,Float &z1){
										HX_STACK_PUSH("*::closure","co/janicek/core/math/PerlinNoise.hx",149);
										{
											HX_STACK_LINE(149)
											return (  (((hash < (int)4))) ? Float(y1) : Float((  (((hash == (int)12))) ? Float(x) : Float(z1) )) );
										}
										return null();
									}
								};
								HX_STACK_LINE(149)
								Float g2 = (((  (((((int(hash) & int((int)1))) == (int)0))) ? Float(_Function_7_3::Block(y1,hash,x)) : Float((  (((hash < (int)8))) ? Float(-(x)) : Float(-(y1)) )) )) + ((  (((((int(hash) & int((int)2))) == (int)0))) ? Float(_Function_7_4::Block(y1,hash,x,z1)) : Float((  (((hash < (int)4))) ? Float(-(y1)) : Float((  (((hash == (int)14))) ? Float(-(x)) : Float(-(z1)) )) )) )));		HX_STACK_VAR(g2,"g2");
								HX_STACK_LINE(151)
								hash = (int(::co::janicek::core::math::PerlinNoise_obj::p->__get((BA + (int)1))) & int((int)15));
								struct _Function_7_5{
									inline static Float Block( Float &x1,Float &y,int &hash){
										HX_STACK_PUSH("*::closure","co/janicek/core/math/PerlinNoise.hx",152);
										{
											HX_STACK_LINE(152)
											return (  (((hash < (int)8))) ? Float(x1) : Float(y) );
										}
										return null();
									}
								};
								struct _Function_7_6{
									inline static Float Block( Float &y,Float &x1,int &hash,Float &z1){
										HX_STACK_PUSH("*::closure","co/janicek/core/math/PerlinNoise.hx",152);
										{
											HX_STACK_LINE(152)
											return (  (((hash < (int)4))) ? Float(y) : Float((  (((hash == (int)12))) ? Float(x1) : Float(z1) )) );
										}
										return null();
									}
								};
								HX_STACK_LINE(152)
								Float g3 = (((  (((((int(hash) & int((int)1))) == (int)0))) ? Float(_Function_7_5::Block(x1,y,hash)) : Float((  (((hash < (int)8))) ? Float(-(x1)) : Float(-(y)) )) )) + ((  (((((int(hash) & int((int)2))) == (int)0))) ? Float(_Function_7_6::Block(y,x1,hash,z1)) : Float((  (((hash < (int)4))) ? Float(-(y)) : Float((  (((hash == (int)14))) ? Float(-(x1)) : Float(-(z1)) )) )) )));		HX_STACK_VAR(g3,"g3");
								HX_STACK_LINE(154)
								hash = (int(::co::janicek::core::math::PerlinNoise_obj::p->__get((AA + (int)1))) & int((int)15));
								struct _Function_7_7{
									inline static Float Block( Float &y,int &hash,Float &x){
										HX_STACK_PUSH("*::closure","co/janicek/core/math/PerlinNoise.hx",155);
										{
											HX_STACK_LINE(155)
											return (  (((hash < (int)8))) ? Float(x) : Float(y) );
										}
										return null();
									}
								};
								struct _Function_7_8{
									inline static Float Block( Float &y,int &hash,Float &x,Float &z1){
										HX_STACK_PUSH("*::closure","co/janicek/core/math/PerlinNoise.hx",155);
										{
											HX_STACK_LINE(155)
											return (  (((hash < (int)4))) ? Float(y) : Float((  (((hash == (int)12))) ? Float(x) : Float(z1) )) );
										}
										return null();
									}
								};
								HX_STACK_LINE(155)
								Float g4 = (((  (((((int(hash) & int((int)1))) == (int)0))) ? Float(_Function_7_7::Block(y,hash,x)) : Float((  (((hash < (int)8))) ? Float(-(x)) : Float(-(y)) )) )) + ((  (((((int(hash) & int((int)2))) == (int)0))) ? Float(_Function_7_8::Block(y,hash,x,z1)) : Float((  (((hash < (int)4))) ? Float(-(y)) : Float((  (((hash == (int)14))) ? Float(-(x)) : Float(-(z1)) )) )) )));		HX_STACK_VAR(g4,"g4");
								HX_STACK_LINE(157)
								hash = (int(::co::janicek::core::math::PerlinNoise_obj::p->__get(BB)) & int((int)15));
								struct _Function_7_9{
									inline static Float Block( Float &y1,Float &x1,int &hash){
										HX_STACK_PUSH("*::closure","co/janicek/core/math/PerlinNoise.hx",158);
										{
											HX_STACK_LINE(158)
											return (  (((hash < (int)8))) ? Float(x1) : Float(y1) );
										}
										return null();
									}
								};
								struct _Function_7_10{
									inline static Float Block( Float &y1,Float &z,Float &x1,int &hash){
										HX_STACK_PUSH("*::closure","co/janicek/core/math/PerlinNoise.hx",158);
										{
											HX_STACK_LINE(158)
											return (  (((hash < (int)4))) ? Float(y1) : Float((  (((hash == (int)12))) ? Float(x1) : Float(z) )) );
										}
										return null();
									}
								};
								HX_STACK_LINE(158)
								Float g5 = (((  (((((int(hash) & int((int)1))) == (int)0))) ? Float(_Function_7_9::Block(y1,x1,hash)) : Float((  (((hash < (int)8))) ? Float(-(x1)) : Float(-(y1)) )) )) + ((  (((((int(hash) & int((int)2))) == (int)0))) ? Float(_Function_7_10::Block(y1,z,x1,hash)) : Float((  (((hash < (int)4))) ? Float(-(y1)) : Float((  (((hash == (int)14))) ? Float(-(x1)) : Float(-(z)) )) )) )));		HX_STACK_VAR(g5,"g5");
								HX_STACK_LINE(160)
								hash = (int(::co::janicek::core::math::PerlinNoise_obj::p->__get(AB)) & int((int)15));
								struct _Function_7_11{
									inline static Float Block( Float &y1,int &hash,Float &x){
										HX_STACK_PUSH("*::closure","co/janicek/core/math/PerlinNoise.hx",161);
										{
											HX_STACK_LINE(161)
											return (  (((hash < (int)8))) ? Float(x) : Float(y1) );
										}
										return null();
									}
								};
								struct _Function_7_12{
									inline static Float Block( Float &y1,Float &z,int &hash,Float &x){
										HX_STACK_PUSH("*::closure","co/janicek/core/math/PerlinNoise.hx",161);
										{
											HX_STACK_LINE(161)
											return (  (((hash < (int)4))) ? Float(y1) : Float((  (((hash == (int)12))) ? Float(x) : Float(z) )) );
										}
										return null();
									}
								};
								HX_STACK_LINE(161)
								Float g6 = (((  (((((int(hash) & int((int)1))) == (int)0))) ? Float(_Function_7_11::Block(y1,hash,x)) : Float((  (((hash < (int)8))) ? Float(-(x)) : Float(-(y1)) )) )) + ((  (((((int(hash) & int((int)2))) == (int)0))) ? Float(_Function_7_12::Block(y1,z,hash,x)) : Float((  (((hash < (int)4))) ? Float(-(y1)) : Float((  (((hash == (int)14))) ? Float(-(x)) : Float(-(z)) )) )) )));		HX_STACK_VAR(g6,"g6");
								HX_STACK_LINE(163)
								hash = (int(::co::janicek::core::math::PerlinNoise_obj::p->__get(BA)) & int((int)15));
								struct _Function_7_13{
									inline static Float Block( Float &x1,Float &y,int &hash){
										HX_STACK_PUSH("*::closure","co/janicek/core/math/PerlinNoise.hx",164);
										{
											HX_STACK_LINE(164)
											return (  (((hash < (int)8))) ? Float(x1) : Float(y) );
										}
										return null();
									}
								};
								struct _Function_7_14{
									inline static Float Block( Float &z,Float &y,Float &x1,int &hash){
										HX_STACK_PUSH("*::closure","co/janicek/core/math/PerlinNoise.hx",164);
										{
											HX_STACK_LINE(164)
											return (  (((hash < (int)4))) ? Float(y) : Float((  (((hash == (int)12))) ? Float(x1) : Float(z) )) );
										}
										return null();
									}
								};
								HX_STACK_LINE(164)
								Float g7 = (((  (((((int(hash) & int((int)1))) == (int)0))) ? Float(_Function_7_13::Block(x1,y,hash)) : Float((  (((hash < (int)8))) ? Float(-(x1)) : Float(-(y)) )) )) + ((  (((((int(hash) & int((int)2))) == (int)0))) ? Float(_Function_7_14::Block(z,y,x1,hash)) : Float((  (((hash < (int)4))) ? Float(-(y)) : Float((  (((hash == (int)14))) ? Float(-(x1)) : Float(-(z)) )) )) )));		HX_STACK_VAR(g7,"g7");
								HX_STACK_LINE(166)
								hash = (int(::co::janicek::core::math::PerlinNoise_obj::p->__get(AA)) & int((int)15));
								struct _Function_7_15{
									inline static Float Block( Float &y,int &hash,Float &x){
										HX_STACK_PUSH("*::closure","co/janicek/core/math/PerlinNoise.hx",167);
										{
											HX_STACK_LINE(167)
											return (  (((hash < (int)8))) ? Float(x) : Float(y) );
										}
										return null();
									}
								};
								struct _Function_7_16{
									inline static Float Block( Float &z,Float &y,int &hash,Float &x){
										HX_STACK_PUSH("*::closure","co/janicek/core/math/PerlinNoise.hx",167);
										{
											HX_STACK_LINE(167)
											return (  (((hash < (int)4))) ? Float(y) : Float((  (((hash == (int)12))) ? Float(x) : Float(z) )) );
										}
										return null();
									}
								};
								HX_STACK_LINE(167)
								Float g8 = (((  (((((int(hash) & int((int)1))) == (int)0))) ? Float(_Function_7_15::Block(y,hash,x)) : Float((  (((hash < (int)8))) ? Float(-(x)) : Float(-(y)) )) )) + ((  (((((int(hash) & int((int)2))) == (int)0))) ? Float(_Function_7_16::Block(z,y,hash,x)) : Float((  (((hash < (int)4))) ? Float(-(y)) : Float((  (((hash == (int)14))) ? Float(-(x)) : Float(-(z)) )) )) )));		HX_STACK_VAR(g8,"g8");
								HX_STACK_LINE(169)
								hx::AddEq(g2,(u * ((g1 - g2))));
								HX_STACK_LINE(170)
								hx::AddEq(g4,(u * ((g3 - g4))));
								HX_STACK_LINE(171)
								hx::AddEq(g6,(u * ((g5 - g6))));
								HX_STACK_LINE(172)
								hx::AddEq(g8,(u * ((g7 - g8))));
								HX_STACK_LINE(174)
								hx::AddEq(g4,(v * ((g2 - g4))));
								HX_STACK_LINE(175)
								hx::AddEq(g8,(v * ((g6 - g8))));
								HX_STACK_LINE(177)
								hx::AddEq(s,(((g8 + (w * ((g4 - g8))))) * fPers1));
							}
						}
						HX_STACK_LINE(180)
						int color = ::Std_obj::_int(((((s * fPersMax) + (int)1)) * (int)128));		HX_STACK_VAR(color,"color");
						HX_STACK_LINE(182)
						::co::janicek::core::array::Array2dCore_obj::set(bitmap,px,py,(int((int((int((int)-16777216) | int((int(color) << int((int)16))))) | int((int(color) << int((int)8))))) | int(color)));
						HX_STACK_LINE(184)
						hx::AddEq(_x,baseFactor);
					}
				}
				HX_STACK_LINE(187)
				hx::AddEq(_y,baseFactor);
			}
		}
		HX_STACK_LINE(190)
		return bitmap;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC9(PerlinNoise_obj,makePerlinNoise,return )


PerlinNoise_obj::PerlinNoise_obj()
{
}

void PerlinNoise_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PerlinNoise);
	HX_MARK_END_CLASS();
}

void PerlinNoise_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic PerlinNoise_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"p") ) { return p; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"makePerlinNoise") ) { return makePerlinNoise_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PerlinNoise_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"p") ) { p=inValue.Cast< Array< int > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PerlinNoise_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("p"),
	HX_CSTRING("makePerlinNoise"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PerlinNoise_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(PerlinNoise_obj::p,"p");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PerlinNoise_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(PerlinNoise_obj::p,"p");
};

Class PerlinNoise_obj::__mClass;

void PerlinNoise_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("co.janicek.core.math.PerlinNoise"), hx::TCanCast< PerlinNoise_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void PerlinNoise_obj::__boot()
{
	p= Array_obj< int >::__new().Add((int)151).Add((int)160).Add((int)137).Add((int)91).Add((int)90).Add((int)15).Add((int)131).Add((int)13).Add((int)201).Add((int)95).Add((int)96).Add((int)53).Add((int)194).Add((int)233).Add((int)7).Add((int)225).Add((int)140).Add((int)36).Add((int)103).Add((int)30).Add((int)69).Add((int)142).Add((int)8).Add((int)99).Add((int)37).Add((int)240).Add((int)21).Add((int)10).Add((int)23).Add((int)190).Add((int)6).Add((int)148).Add((int)247).Add((int)120).Add((int)234).Add((int)75).Add((int)0).Add((int)26).Add((int)197).Add((int)62).Add((int)94).Add((int)252).Add((int)219).Add((int)203).Add((int)117).Add((int)35).Add((int)11).Add((int)32).Add((int)57).Add((int)177).Add((int)33).Add((int)88).Add((int)237).Add((int)149).Add((int)56).Add((int)87).Add((int)174).Add((int)20).Add((int)125).Add((int)136).Add((int)171).Add((int)168).Add((int)68).Add((int)175).Add((int)74).Add((int)165).Add((int)71).Add((int)134).Add((int)139).Add((int)48).Add((int)27).Add((int)166).Add((int)77).Add((int)146).Add((int)158).Add((int)231).Add((int)83).Add((int)111).Add((int)229).Add((int)122).Add((int)60).Add((int)211).Add((int)133).Add((int)230).Add((int)220).Add((int)105).Add((int)92).Add((int)41).Add((int)55).Add((int)46).Add((int)245).Add((int)40).Add((int)244).Add((int)102).Add((int)143).Add((int)54).Add((int)65).Add((int)25).Add((int)63).Add((int)161).Add((int)1).Add((int)216).Add((int)80).Add((int)73).Add((int)209).Add((int)76).Add((int)132).Add((int)187).Add((int)208).Add((int)89).Add((int)18).Add((int)169).Add((int)200).Add((int)196).Add((int)135).Add((int)130).Add((int)116).Add((int)188).Add((int)159).Add((int)86).Add((int)164).Add((int)100).Add((int)109).Add((int)198).Add((int)173).Add((int)186).Add((int)3).Add((int)64).Add((int)52).Add((int)217).Add((int)226).Add((int)250).Add((int)124).Add((int)123).Add((int)5).Add((int)202).Add((int)38).Add((int)147).Add((int)118).Add((int)126).Add((int)255).Add((int)82).Add((int)85).Add((int)212).Add((int)207).Add((int)206).Add((int)59).Add((int)227).Add((int)47).Add((int)16).Add((int)58).Add((int)17).Add((int)182).Add((int)189).Add((int)28).Add((int)42).Add((int)223).Add((int)183).Add((int)170).Add((int)213).Add((int)119).Add((int)248).Add((int)152).Add((int)2).Add((int)44).Add((int)154).Add((int)163).Add((int)70).Add((int)221).Add((int)153).Add((int)101).Add((int)155).Add((int)167).Add((int)43).Add((int)172).Add((int)9).Add((int)129).Add((int)22).Add((int)39).Add((int)253).Add((int)19).Add((int)98).Add((int)108).Add((int)110).Add((int)79).Add((int)113).Add((int)224).Add((int)232).Add((int)178).Add((int)185).Add((int)112).Add((int)104).Add((int)218).Add((int)246).Add((int)97).Add((int)228).Add((int)251).Add((int)34).Add((int)242).Add((int)193).Add((int)238).Add((int)210).Add((int)144).Add((int)12).Add((int)191).Add((int)179).Add((int)162).Add((int)241).Add((int)81).Add((int)51).Add((int)145).Add((int)235).Add((int)249).Add((int)14).Add((int)239).Add((int)107).Add((int)49).Add((int)192).Add((int)214).Add((int)31).Add((int)181).Add((int)199).Add((int)106).Add((int)157).Add((int)184).Add((int)84).Add((int)204).Add((int)176).Add((int)115).Add((int)121).Add((int)50).Add((int)45).Add((int)127).Add((int)4).Add((int)150).Add((int)254).Add((int)138).Add((int)236).Add((int)205).Add((int)93).Add((int)222).Add((int)114).Add((int)67).Add((int)29).Add((int)24).Add((int)72).Add((int)243).Add((int)141).Add((int)128).Add((int)195).Add((int)78).Add((int)66).Add((int)215).Add((int)61).Add((int)156).Add((int)180).Add((int)151).Add((int)160).Add((int)137).Add((int)91).Add((int)90).Add((int)15).Add((int)131).Add((int)13).Add((int)201).Add((int)95).Add((int)96).Add((int)53).Add((int)194).Add((int)233).Add((int)7).Add((int)225).Add((int)140).Add((int)36).Add((int)103).Add((int)30).Add((int)69).Add((int)142).Add((int)8).Add((int)99).Add((int)37).Add((int)240).Add((int)21).Add((int)10).Add((int)23).Add((int)190).Add((int)6).Add((int)148).Add((int)247).Add((int)120).Add((int)234).Add((int)75).Add((int)0).Add((int)26).Add((int)197).Add((int)62).Add((int)94).Add((int)252).Add((int)219).Add((int)203).Add((int)117).Add((int)35).Add((int)11).Add((int)32).Add((int)57).Add((int)177).Add((int)33).Add((int)88).Add((int)237).Add((int)149).Add((int)56).Add((int)87).Add((int)174).Add((int)20).Add((int)125).Add((int)136).Add((int)171).Add((int)168).Add((int)68).Add((int)175).Add((int)74).Add((int)165).Add((int)71).Add((int)134).Add((int)139).Add((int)48).Add((int)27).Add((int)166).Add((int)77).Add((int)146).Add((int)158).Add((int)231).Add((int)83).Add((int)111).Add((int)229).Add((int)122).Add((int)60).Add((int)211).Add((int)133).Add((int)230).Add((int)220).Add((int)105).Add((int)92).Add((int)41).Add((int)55).Add((int)46).Add((int)245).Add((int)40).Add((int)244).Add((int)102).Add((int)143).Add((int)54).Add((int)65).Add((int)25).Add((int)63).Add((int)161).Add((int)1).Add((int)216).Add((int)80).Add((int)73).Add((int)209).Add((int)76).Add((int)132).Add((int)187).Add((int)208).Add((int)89).Add((int)18).Add((int)169).Add((int)200).Add((int)196).Add((int)135).Add((int)130).Add((int)116).Add((int)188).Add((int)159).Add((int)86).Add((int)164).Add((int)100).Add((int)109).Add((int)198).Add((int)173).Add((int)186).Add((int)3).Add((int)64).Add((int)52).Add((int)217).Add((int)226).Add((int)250).Add((int)124).Add((int)123).Add((int)5).Add((int)202).Add((int)38).Add((int)147).Add((int)118).Add((int)126).Add((int)255).Add((int)82).Add((int)85).Add((int)212).Add((int)207).Add((int)206).Add((int)59).Add((int)227).Add((int)47).Add((int)16).Add((int)58).Add((int)17).Add((int)182).Add((int)189).Add((int)28).Add((int)42).Add((int)223).Add((int)183).Add((int)170).Add((int)213).Add((int)119).Add((int)248).Add((int)152).Add((int)2).Add((int)44).Add((int)154).Add((int)163).Add((int)70).Add((int)221).Add((int)153).Add((int)101).Add((int)155).Add((int)167).Add((int)43).Add((int)172).Add((int)9).Add((int)129).Add((int)22).Add((int)39).Add((int)253).Add((int)19).Add((int)98).Add((int)108).Add((int)110).Add((int)79).Add((int)113).Add((int)224).Add((int)232).Add((int)178).Add((int)185).Add((int)112).Add((int)104).Add((int)218).Add((int)246).Add((int)97).Add((int)228).Add((int)251).Add((int)34).Add((int)242).Add((int)193).Add((int)238).Add((int)210).Add((int)144).Add((int)12).Add((int)191).Add((int)179).Add((int)162).Add((int)241).Add((int)81).Add((int)51).Add((int)145).Add((int)235).Add((int)249).Add((int)14).Add((int)239).Add((int)107).Add((int)49).Add((int)192).Add((int)214).Add((int)31).Add((int)181).Add((int)199).Add((int)106).Add((int)157).Add((int)184).Add((int)84).Add((int)204).Add((int)176).Add((int)115).Add((int)121).Add((int)50).Add((int)45).Add((int)127).Add((int)4).Add((int)150).Add((int)254).Add((int)138).Add((int)236).Add((int)205).Add((int)93).Add((int)222).Add((int)114).Add((int)67).Add((int)29).Add((int)24).Add((int)72).Add((int)243).Add((int)141).Add((int)128).Add((int)195).Add((int)78).Add((int)66).Add((int)215).Add((int)61).Add((int)156).Add((int)180);
}

} // end namespace co
} // end namespace janicek
} // end namespace core
} // end namespace math

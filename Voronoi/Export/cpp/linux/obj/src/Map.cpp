#include <hxcpp.h>

#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_IslandShape
#include <IslandShape.h>
#endif
#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_Map
#include <Map.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_NullHelper
#include <NullHelper.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Edge
#include <com/nodename/delaunay/Edge.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Voronoi
#include <com/nodename/delaunay/Voronoi.h>
#endif
#ifndef INCLUDED_com_nodename_geom_LineSegment
#include <com/nodename/geom/LineSegment.h>
#endif
#ifndef INCLUDED_de_polygonal_math_PM_PRNG
#include <de/polygonal/math/PM_PRNG.h>
#endif
#ifndef INCLUDED_graph_Center
#include <graph/Center.h>
#endif
#ifndef INCLUDED_graph_Corner
#include <graph/Corner.h>
#endif
#ifndef INCLUDED_graph_Edge
#include <graph/Edge.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
#ifndef INCLUDED_neash_geom_Rectangle
#include <neash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_ObjectHash
#include <nme/ObjectHash.h>
#endif

Void Map_obj::__construct(Dynamic size)
{
HX_STACK_PUSH("Map::new","Map.hx",54);
{
	HX_STACK_LINE(55)
	this->mapRandom = ::de::polygonal::math::PM_PRNG_obj::__new();
	HX_STACK_LINE(56)
	this->SIZE = size;
	HX_STACK_LINE(57)
	this->reset();
}
;
	return null();
}

Map_obj::~Map_obj() { }

Dynamic Map_obj::__CreateEmpty() { return  new Map_obj; }
hx::ObjectPtr< Map_obj > Map_obj::__new(Dynamic size)
{  hx::ObjectPtr< Map_obj > result = new Map_obj();
	result->__construct(size);
	return result;}

Dynamic Map_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Map_obj > result = new Map_obj();
	result->__construct(inArgs[0]);
	return result;}

bool Map_obj::inside( ::neash::geom::Point p){
	HX_STACK_PUSH("Map::inside","Map.hx",891);
	HX_STACK_THIS(this);
	HX_STACK_ARG(p,"p");
	HX_STACK_LINE(891)
	return this->islandShape(::neash::geom::Point_obj::__new(((int)2 * (((Float(p->x) / Float(this->SIZE->__Field(HX_CSTRING("width"),true))) - 0.5))),((int)2 * (((Float(p->y) / Float(this->SIZE->__Field(HX_CSTRING("height"),true))) - 0.5)))));
}


HX_DEFINE_DYNAMIC_FUNC1(Map_obj,inside,return )

::graph::Edge Map_obj::lookupEdgeFromCorner( ::graph::Corner q,::graph::Corner s){
	HX_STACK_PUSH("Map::lookupEdgeFromCorner","Map.hx",882);
	HX_STACK_THIS(this);
	HX_STACK_ARG(q,"q");
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(883)
	{
		HX_STACK_LINE(883)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::graph::Edge > _g1 = q->protrudes;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(883)
		while(((_g < _g1->length))){
			HX_STACK_LINE(883)
			::graph::Edge edge = _g1->__get(_g);		HX_STACK_VAR(edge,"edge");
			HX_STACK_LINE(883)
			++(_g);
			HX_STACK_LINE(884)
			if (((bool((edge->v0 == s)) || bool((edge->v1 == s))))){
				HX_STACK_LINE(884)
				return edge;
			}
		}
	}
	HX_STACK_LINE(886)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Map_obj,lookupEdgeFromCorner,return )

::graph::Edge Map_obj::lookupEdgeFromCenter( ::graph::Center p,::graph::Center r){
	HX_STACK_PUSH("Map::lookupEdgeFromCenter","Map.hx",875);
	HX_STACK_THIS(this);
	HX_STACK_ARG(p,"p");
	HX_STACK_ARG(r,"r");
	HX_STACK_LINE(876)
	{
		HX_STACK_LINE(876)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::graph::Edge > _g1 = p->borders;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(876)
		while(((_g < _g1->length))){
			HX_STACK_LINE(876)
			::graph::Edge edge = _g1->__get(_g);		HX_STACK_VAR(edge,"edge");
			HX_STACK_LINE(876)
			++(_g);
			HX_STACK_LINE(877)
			if (((bool((edge->d0 == r)) || bool((edge->d1 == r))))){
				HX_STACK_LINE(877)
				return edge;
			}
		}
	}
	HX_STACK_LINE(879)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Map_obj,lookupEdgeFromCenter,return )

Void Map_obj::assignBiomes( ){
{
		HX_STACK_PUSH("Map::assignBiomes","Map.hx",865);
		HX_STACK_THIS(this);
		HX_STACK_LINE(866)
		::graph::Center p;		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(867)
		{
			HX_STACK_LINE(867)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Center > _g1 = this->centers;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(867)
			while(((_g < _g1->length))){
				HX_STACK_LINE(867)
				::graph::Center p1 = _g1->__get(_g);		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(867)
				++(_g);
				HX_STACK_LINE(868)
				p1->biome = ::Map_obj::getBiome(p1);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,assignBiomes,(void))

Void Map_obj::assignPolygonMoisture( ){
{
		HX_STACK_PUSH("Map::assignPolygonMoisture","Map.hx",815);
		HX_STACK_THIS(this);
		HX_STACK_LINE(816)
		::graph::Center p;		HX_STACK_VAR(p,"p");
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		Float sumMoisture;		HX_STACK_VAR(sumMoisture,"sumMoisture");
		HX_STACK_LINE(817)
		{
			HX_STACK_LINE(817)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Center > _g1 = this->centers;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(817)
			while(((_g < _g1->length))){
				HX_STACK_LINE(817)
				::graph::Center p1 = _g1->__get(_g);		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(817)
				++(_g);
				HX_STACK_LINE(818)
				sumMoisture = 0.0;
				HX_STACK_LINE(819)
				{
					HX_STACK_LINE(819)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Corner > _g3 = p1->corners;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(819)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(819)
						::graph::Corner q1 = _g3->__get(_g2);		HX_STACK_VAR(q1,"q1");
						HX_STACK_LINE(819)
						++(_g2);
						HX_STACK_LINE(820)
						if (((q1->moisture > 1.0))){
							HX_STACK_LINE(820)
							q1->moisture = 1.0;
						}
						HX_STACK_LINE(821)
						hx::AddEq(sumMoisture,q1->moisture);
					}
				}
				HX_STACK_LINE(823)
				p1->moisture = (Float(sumMoisture) / Float(p1->corners->length));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,assignPolygonMoisture,(void))

Void Map_obj::assignCornerMoisture( ){
{
		HX_STACK_PUSH("Map::assignCornerMoisture","Map.hx",782);
		HX_STACK_THIS(this);
		HX_STACK_LINE(783)
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		::graph::Corner r;		HX_STACK_VAR(r,"r");
		Float newMoisture;		HX_STACK_VAR(newMoisture,"newMoisture");
		HX_STACK_LINE(784)
		Dynamic queue = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(queue,"queue");
		HX_STACK_LINE(786)
		{
			HX_STACK_LINE(786)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Corner > _g1 = this->corners;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(786)
			while(((_g < _g1->length))){
				HX_STACK_LINE(786)
				::graph::Corner q1 = _g1->__get(_g);		HX_STACK_VAR(q1,"q1");
				HX_STACK_LINE(786)
				++(_g);
				HX_STACK_LINE(787)
				if (((bool(((bool(q1->water) || bool((q1->river > (int)0))))) && bool(!(q1->ocean))))){
					HX_STACK_LINE(788)
					q1->moisture = (  (((q1->river > (int)0))) ? Float(::Math_obj::min(3.0,(0.2 * q1->river))) : Float(1.0) );
					HX_STACK_LINE(789)
					queue->__Field(HX_CSTRING("push"),true)(q1);
				}
				else{
					HX_STACK_LINE(790)
					q1->moisture = 0.0;
				}
			}
		}
		HX_STACK_LINE(794)
		while(((queue->__Field(HX_CSTRING("length"),true) > (int)0))){
			HX_STACK_LINE(795)
			q = queue->__Field(HX_CSTRING("shift"),true)();
			HX_STACK_LINE(797)
			{
				HX_STACK_LINE(797)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::graph::Corner > _g1 = q->adjacent;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(797)
				while(((_g < _g1->length))){
					HX_STACK_LINE(797)
					::graph::Corner r1 = _g1->__get(_g);		HX_STACK_VAR(r1,"r1");
					HX_STACK_LINE(797)
					++(_g);
					HX_STACK_LINE(798)
					newMoisture = (q->moisture * 0.9);
					HX_STACK_LINE(799)
					if (((newMoisture > r1->moisture))){
						HX_STACK_LINE(800)
						r1->moisture = newMoisture;
						HX_STACK_LINE(801)
						queue->__Field(HX_CSTRING("push"),true)(r1);
					}
				}
			}
		}
		HX_STACK_LINE(806)
		{
			HX_STACK_LINE(806)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Corner > _g1 = this->corners;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(806)
			while(((_g < _g1->length))){
				HX_STACK_LINE(806)
				::graph::Corner q1 = _g1->__get(_g);		HX_STACK_VAR(q1,"q1");
				HX_STACK_LINE(806)
				++(_g);
				HX_STACK_LINE(807)
				if (((bool(q1->ocean) || bool(q1->coast)))){
					HX_STACK_LINE(807)
					q1->moisture = 1.0;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,assignCornerMoisture,(void))

Void Map_obj::createRivers( ){
{
		HX_STACK_PUSH("Map::createRivers","Map.hx",745);
		HX_STACK_THIS(this);
		HX_STACK_LINE(749)
		int i;		HX_STACK_VAR(i,"i");
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		::graph::Edge edge;		HX_STACK_VAR(edge,"edge");
		HX_STACK_LINE(751)
		{
			HX_STACK_LINE(751)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(751)
			while(((_g < (int)50))){
				HX_STACK_LINE(751)
				int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(752)
				q = this->corners->__get(this->mapRandom->nextIntRange((int)0,(this->corners->length - (int)1)));
				HX_STACK_LINE(755)
				if ((::NullHelper_obj::IsNotNull(q))){
					HX_STACK_LINE(760)
					if (((bool((bool((bool(q->ocean) || bool(q->water))) || bool((q->elevation < 0.3)))) || bool((q->elevation > 0.9))))){
						HX_STACK_LINE(761)
						continue;
					}
					HX_STACK_LINE(763)
					while((!(q->coast))){
						HX_STACK_LINE(764)
						if (((q == q->downslope))){
							HX_STACK_LINE(764)
							break;
						}
						HX_STACK_LINE(767)
						edge = this->lookupEdgeFromCorner(q,q->downslope);
						HX_STACK_LINE(768)
						edge->river = (edge->river + (int)1);
						HX_STACK_LINE(769)
						q->river = (((  ((::NullHelper_obj::IsNull(q->river))) ? int((int)0) : int(q->river) )) + (int)1);
						HX_STACK_LINE(770)
						q->downslope->river = (((  ((::NullHelper_obj::IsNull(q->downslope->river))) ? int((int)0) : int(q->downslope->river) )) + (int)1);
						HX_STACK_LINE(771)
						q = q->downslope;
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,createRivers,(void))

Void Map_obj::calculateWatersheds( ){
{
		HX_STACK_PUSH("Map::calculateWatersheds","Map.hx",709);
		HX_STACK_THIS(this);
		HX_STACK_LINE(710)
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		::graph::Corner r;		HX_STACK_VAR(r,"r");
		int i;		HX_STACK_VAR(i,"i");
		bool changed;		HX_STACK_VAR(changed,"changed");
		HX_STACK_LINE(713)
		{
			HX_STACK_LINE(713)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Corner > _g1 = this->corners;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(713)
			while(((_g < _g1->length))){
				HX_STACK_LINE(713)
				::graph::Corner q1 = _g1->__get(_g);		HX_STACK_VAR(q1,"q1");
				HX_STACK_LINE(713)
				++(_g);
				HX_STACK_LINE(714)
				q1->watershed = q1;
				HX_STACK_LINE(715)
				if (((bool(!(q1->ocean)) && bool(!(q1->coast))))){
					HX_STACK_LINE(715)
					q1->watershed = q1->downslope;
				}
			}
		}
		HX_STACK_LINE(724)
		{
			HX_STACK_LINE(724)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(724)
			while(((_g < (int)100))){
				HX_STACK_LINE(724)
				int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(725)
				changed = false;
				HX_STACK_LINE(726)
				{
					HX_STACK_LINE(726)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					Array< ::graph::Corner > _g2 = this->corners;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(726)
					while(((_g1 < _g2->length))){
						HX_STACK_LINE(726)
						::graph::Corner q1 = _g2->__get(_g1);		HX_STACK_VAR(q1,"q1");
						HX_STACK_LINE(726)
						++(_g1);
						HX_STACK_LINE(727)
						if (((bool((bool(!(q1->ocean)) && bool(!(q1->coast)))) && bool(!(q1->watershed->coast))))){
							HX_STACK_LINE(728)
							r = q1->downslope->watershed;
							HX_STACK_LINE(729)
							if ((!(r->ocean))){
								HX_STACK_LINE(729)
								q1->watershed = r;
							}
							HX_STACK_LINE(730)
							changed = true;
						}
					}
				}
				HX_STACK_LINE(733)
				if ((!(changed))){
					HX_STACK_LINE(733)
					break;
				}
			}
		}
		HX_STACK_LINE(736)
		{
			HX_STACK_LINE(736)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Corner > _g1 = this->corners;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(736)
			while(((_g < _g1->length))){
				HX_STACK_LINE(736)
				::graph::Corner q1 = _g1->__get(_g);		HX_STACK_VAR(q1,"q1");
				HX_STACK_LINE(736)
				++(_g);
				HX_STACK_LINE(737)
				r = q1->watershed;
				HX_STACK_LINE(738)
				r->watershed_size = ((int)1 + ((  ((::NullHelper_obj::IsNull(r->watershed_size))) ? int((int)0) : int(r->watershed_size) )));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,calculateWatersheds,(void))

Void Map_obj::calculateDownslopes( ){
{
		HX_STACK_PUSH("Map::calculateDownslopes","Map.hx",689);
		HX_STACK_THIS(this);
		HX_STACK_LINE(690)
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		::graph::Corner s;		HX_STACK_VAR(s,"s");
		::graph::Corner r;		HX_STACK_VAR(r,"r");
		HX_STACK_LINE(692)
		{
			HX_STACK_LINE(692)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Corner > _g1 = this->corners;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(692)
			while(((_g < _g1->length))){
				HX_STACK_LINE(692)
				::graph::Corner q1 = _g1->__get(_g);		HX_STACK_VAR(q1,"q1");
				HX_STACK_LINE(692)
				++(_g);
				HX_STACK_LINE(693)
				r = q1;
				HX_STACK_LINE(694)
				{
					HX_STACK_LINE(694)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Corner > _g3 = q1->adjacent;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(694)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(694)
						::graph::Corner s1 = _g3->__get(_g2);		HX_STACK_VAR(s1,"s1");
						HX_STACK_LINE(694)
						++(_g2);
						HX_STACK_LINE(695)
						if (((s1->elevation <= r->elevation))){
							HX_STACK_LINE(695)
							r = s1;
						}
					}
				}
				HX_STACK_LINE(699)
				q1->downslope = r;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,calculateDownslopes,(void))

Void Map_obj::assignPolygonElevations( ){
{
		HX_STACK_PUSH("Map::assignPolygonElevations","Map.hx",674);
		HX_STACK_THIS(this);
		HX_STACK_LINE(675)
		::graph::Center p;		HX_STACK_VAR(p,"p");
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		Float sumElevation;		HX_STACK_VAR(sumElevation,"sumElevation");
		HX_STACK_LINE(676)
		{
			HX_STACK_LINE(676)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Center > _g1 = this->centers;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(676)
			while(((_g < _g1->length))){
				HX_STACK_LINE(676)
				::graph::Center p1 = _g1->__get(_g);		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(676)
				++(_g);
				HX_STACK_LINE(677)
				sumElevation = 0.0;
				HX_STACK_LINE(678)
				{
					HX_STACK_LINE(678)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Corner > _g3 = p1->corners;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(678)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(678)
						::graph::Corner q1 = _g3->__get(_g2);		HX_STACK_VAR(q1,"q1");
						HX_STACK_LINE(678)
						++(_g2);
						HX_STACK_LINE(679)
						hx::AddEq(sumElevation,q1->elevation);
					}
				}
				HX_STACK_LINE(681)
				p1->elevation = (Float(sumElevation) / Float(p1->corners->length));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,assignPolygonElevations,(void))

Void Map_obj::assignOceanCoastAndLand( ){
{
		HX_STACK_PUSH("Map::assignOceanCoastAndLand","Map.hx",603);
		HX_STACK_THIS(this);
		HX_STACK_LINE(610)
		Dynamic queue = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(queue,"queue");
		HX_STACK_LINE(611)
		::graph::Center p = ::graph::Center_obj::__new();		HX_STACK_VAR(p,"p");
		::graph::Corner q = ::graph::Corner_obj::__new();		HX_STACK_VAR(q,"q");
		::graph::Center r = ::graph::Center_obj::__new();		HX_STACK_VAR(r,"r");
		int numWater = (int)0;		HX_STACK_VAR(numWater,"numWater");
		HX_STACK_LINE(613)
		{
			HX_STACK_LINE(613)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Center > _g1 = this->centers;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(613)
			while(((_g < _g1->length))){
				HX_STACK_LINE(613)
				::graph::Center p1 = _g1->__get(_g);		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(613)
				++(_g);
				HX_STACK_LINE(614)
				numWater = (int)0;
				HX_STACK_LINE(615)
				{
					HX_STACK_LINE(615)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Corner > _g3 = p1->corners;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(615)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(615)
						::graph::Corner q1 = _g3->__get(_g2);		HX_STACK_VAR(q1,"q1");
						HX_STACK_LINE(615)
						++(_g2);
						HX_STACK_LINE(616)
						if ((q1->border)){
							HX_STACK_LINE(617)
							p1->border = true;
							HX_STACK_LINE(618)
							p1->ocean = true;
							HX_STACK_LINE(619)
							q1->water = true;
							HX_STACK_LINE(620)
							queue->__Field(HX_CSTRING("push"),true)(p1);
						}
						HX_STACK_LINE(622)
						if ((q1->water)){
							HX_STACK_LINE(622)
							hx::AddEq(numWater,(int)1);
						}
					}
				}
				HX_STACK_LINE(626)
				p1->water = (bool(p1->ocean) || bool((numWater >= (p1->corners->length * ::Map_obj::LAKE_THRESHOLD))));
			}
		}
		HX_STACK_LINE(628)
		while(((queue->__Field(HX_CSTRING("length"),true) > (int)0))){
			HX_STACK_LINE(629)
			p = queue->__Field(HX_CSTRING("shift"),true)();
			HX_STACK_LINE(630)
			{
				HX_STACK_LINE(630)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::graph::Center > _g1 = p->neighbors;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(630)
				while(((_g < _g1->length))){
					HX_STACK_LINE(630)
					::graph::Center r1 = _g1->__get(_g);		HX_STACK_VAR(r1,"r1");
					HX_STACK_LINE(630)
					++(_g);
					HX_STACK_LINE(631)
					if (((bool(r1->water) && bool(!(r1->ocean))))){
						HX_STACK_LINE(632)
						r1->ocean = true;
						HX_STACK_LINE(633)
						queue->__Field(HX_CSTRING("push"),true)(r1);
					}
				}
			}
		}
		HX_STACK_LINE(641)
		{
			HX_STACK_LINE(641)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Center > _g1 = this->centers;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(641)
			while(((_g < _g1->length))){
				HX_STACK_LINE(641)
				::graph::Center p1 = _g1->__get(_g);		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(641)
				++(_g);
				HX_STACK_LINE(642)
				int numOcean = (int)0;		HX_STACK_VAR(numOcean,"numOcean");
				HX_STACK_LINE(643)
				int numLand = (int)0;		HX_STACK_VAR(numLand,"numLand");
				HX_STACK_LINE(644)
				{
					HX_STACK_LINE(644)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Center > _g3 = p1->neighbors;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(644)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(644)
						::graph::Center r1 = _g3->__get(_g2);		HX_STACK_VAR(r1,"r1");
						HX_STACK_LINE(644)
						++(_g2);
						HX_STACK_LINE(645)
						hx::AddEq(numOcean,(  ((r1->ocean)) ? int((int)1) : int((int)0) ));
						HX_STACK_LINE(646)
						hx::AddEq(numLand,(  ((!(r1->water))) ? int((int)1) : int((int)0) ));
					}
				}
				HX_STACK_LINE(648)
				p1->coast = (bool((numOcean > (int)0)) && bool((numLand > (int)0)));
			}
		}
		HX_STACK_LINE(656)
		{
			HX_STACK_LINE(656)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Corner > _g1 = this->corners;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(656)
			while(((_g < _g1->length))){
				HX_STACK_LINE(656)
				::graph::Corner q1 = _g1->__get(_g);		HX_STACK_VAR(q1,"q1");
				HX_STACK_LINE(656)
				++(_g);
				HX_STACK_LINE(657)
				int numOcean = (int)0;		HX_STACK_VAR(numOcean,"numOcean");
				HX_STACK_LINE(658)
				int numLand = (int)0;		HX_STACK_VAR(numLand,"numLand");
				HX_STACK_LINE(660)
				{
					HX_STACK_LINE(660)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Center > _g3 = q1->touches;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(660)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(660)
						::graph::Center p1 = _g3->__get(_g2);		HX_STACK_VAR(p1,"p1");
						HX_STACK_LINE(660)
						++(_g2);
						HX_STACK_LINE(662)
						hx::AddEq(numOcean,(  ((p1->ocean)) ? int((int)1) : int((int)0) ));
						HX_STACK_LINE(663)
						hx::AddEq(numLand,(  ((!(p1->water))) ? int((int)1) : int((int)0) ));
					}
				}
				HX_STACK_LINE(666)
				q1->ocean = (numOcean == q1->touches->length);
				HX_STACK_LINE(667)
				q1->coast = (bool((numOcean > (int)0)) && bool((numLand > (int)0)));
				HX_STACK_LINE(668)
				q1->water = (bool(q1->border) || bool((bool((numLand != q1->touches->length)) && bool(!(q1->coast)))));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,assignOceanCoastAndLand,(void))

Void Map_obj::redistributeMoisture( Dynamic locations){
{
		HX_STACK_PUSH("Map::redistributeMoisture","Map.hx",587);
		HX_STACK_THIS(this);
		HX_STACK_ARG(locations,"locations");
		HX_STACK_LINE(588)
		int i;		HX_STACK_VAR(i,"i");

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		int run(Dynamic c1,Dynamic c2){
			HX_STACK_PUSH("*::_Function_1_1","Map.hx",589);
			HX_STACK_ARG(c1,"c1");
			HX_STACK_ARG(c2,"c2");
			{
				HX_STACK_LINE(590)
				if (((c1->__Field(HX_CSTRING("moisture"),true) > c2->__Field(HX_CSTRING("moisture"),true)))){
					HX_STACK_LINE(590)
					return (int)1;
				}
				HX_STACK_LINE(591)
				if (((c1->__Field(HX_CSTRING("moisture"),true) < c2->__Field(HX_CSTRING("moisture"),true)))){
					HX_STACK_LINE(591)
					return (int)-1;
				}
				HX_STACK_LINE(592)
				if (((c1->__Field(HX_CSTRING("index"),true) > c2->__Field(HX_CSTRING("index"),true)))){
					HX_STACK_LINE(592)
					return (int)1;
				}
				HX_STACK_LINE(593)
				if (((c1->__Field(HX_CSTRING("index"),true) < c2->__Field(HX_CSTRING("index"),true)))){
					HX_STACK_LINE(593)
					return (int)-1;
				}
				HX_STACK_LINE(594)
				return (int)0;
			}
			return null();
		}
		HX_END_LOCAL_FUNC2(return)

		HX_STACK_LINE(589)
		locations->__Field(HX_CSTRING("sort"),true)( Dynamic(new _Function_1_1()));
		HX_STACK_LINE(596)
		{
			HX_STACK_LINE(596)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = locations->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(596)
			while(((_g1 < _g))){
				HX_STACK_LINE(596)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(597)
				locations->__GetItem(i1)->__FieldRef(HX_CSTRING("moisture")) = (Float(i1) / Float(((locations->__Field(HX_CSTRING("length"),true) - (int)1))));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Map_obj,redistributeMoisture,(void))

Void Map_obj::redistributeElevations( Dynamic locations){
{
		HX_STACK_PUSH("Map::redistributeElevations","Map.hx",554);
		HX_STACK_THIS(this);
		HX_STACK_ARG(locations,"locations");
		HX_STACK_LINE(557)
		Float SCALE_FACTOR = 1.1;		HX_STACK_VAR(SCALE_FACTOR,"SCALE_FACTOR");
		HX_STACK_LINE(558)
		int i;		HX_STACK_VAR(i,"i");
		Float y;		HX_STACK_VAR(y,"y");
		Float x;		HX_STACK_VAR(x,"x");

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		int run(Dynamic c1,Dynamic c2){
			HX_STACK_PUSH("*::_Function_1_1","Map.hx",561);
			HX_STACK_ARG(c1,"c1");
			HX_STACK_ARG(c2,"c2");
			{
				HX_STACK_LINE(562)
				if (((c1->__Field(HX_CSTRING("elevation"),true) > c2->__Field(HX_CSTRING("elevation"),true)))){
					HX_STACK_LINE(562)
					return (int)1;
				}
				HX_STACK_LINE(563)
				if (((c1->__Field(HX_CSTRING("elevation"),true) < c2->__Field(HX_CSTRING("elevation"),true)))){
					HX_STACK_LINE(563)
					return (int)-1;
				}
				HX_STACK_LINE(564)
				if (((c1->__Field(HX_CSTRING("index"),true) > c2->__Field(HX_CSTRING("index"),true)))){
					HX_STACK_LINE(564)
					return (int)1;
				}
				HX_STACK_LINE(565)
				if (((c1->__Field(HX_CSTRING("index"),true) < c2->__Field(HX_CSTRING("index"),true)))){
					HX_STACK_LINE(565)
					return (int)-1;
				}
				HX_STACK_LINE(566)
				return (int)0;
			}
			return null();
		}
		HX_END_LOCAL_FUNC2(return)

		HX_STACK_LINE(561)
		locations->__Field(HX_CSTRING("sort"),true)( Dynamic(new _Function_1_1()));
		HX_STACK_LINE(568)
		{
			HX_STACK_LINE(568)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = locations->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(568)
			while(((_g1 < _g))){
				HX_STACK_LINE(568)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(572)
				y = (Float(i1) / Float(((locations->__Field(HX_CSTRING("length"),true) - (int)1))));
				HX_STACK_LINE(579)
				x = (::Math_obj::sqrt(SCALE_FACTOR) - ::Math_obj::sqrt((SCALE_FACTOR * (((int)1 - y)))));
				HX_STACK_LINE(580)
				if (((x > 1.0))){
					HX_STACK_LINE(580)
					x = 1.0;
				}
				HX_STACK_LINE(581)
				locations->__GetItem(i1)->__FieldRef(HX_CSTRING("elevation")) = x;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Map_obj,redistributeElevations,(void))

Void Map_obj::assignCornerElevations( ){
{
		HX_STACK_PUSH("Map::assignCornerElevations","Map.hx",506);
		HX_STACK_THIS(this);
		HX_STACK_LINE(507)
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		::graph::Corner s;		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(508)
		Dynamic queue = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(queue,"queue");
		HX_STACK_LINE(510)
		{
			HX_STACK_LINE(510)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Corner > _g1 = this->corners;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(510)
			while(((_g < _g1->length))){
				HX_STACK_LINE(510)
				::graph::Corner q1 = _g1->__get(_g);		HX_STACK_VAR(q1,"q1");
				HX_STACK_LINE(510)
				++(_g);
				HX_STACK_LINE(511)
				q1->water = !(this->inside(q1->point));
			}
		}
		HX_STACK_LINE(514)
		{
			HX_STACK_LINE(514)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Corner > _g1 = this->corners;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(514)
			while(((_g < _g1->length))){
				HX_STACK_LINE(514)
				::graph::Corner q1 = _g1->__get(_g);		HX_STACK_VAR(q1,"q1");
				HX_STACK_LINE(514)
				++(_g);
				HX_STACK_LINE(516)
				if ((q1->border)){
					HX_STACK_LINE(517)
					q1->elevation = 0.0;
					HX_STACK_LINE(518)
					queue->__Field(HX_CSTRING("push"),true)(q1);
				}
				else{
					HX_STACK_LINE(519)
					q1->elevation = ::Math_obj::POSITIVE_INFINITY;
				}
			}
		}
		HX_STACK_LINE(527)
		while(((queue->__Field(HX_CSTRING("length"),true) > (int)0))){
			HX_STACK_LINE(528)
			q = queue->__Field(HX_CSTRING("shift"),true)();
			HX_STACK_LINE(530)
			{
				HX_STACK_LINE(530)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::graph::Corner > _g1 = q->adjacent;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(530)
				while(((_g < _g1->length))){
					HX_STACK_LINE(530)
					::graph::Corner s1 = _g1->__get(_g);		HX_STACK_VAR(s1,"s1");
					HX_STACK_LINE(530)
					++(_g);
					HX_STACK_LINE(534)
					Float newElevation = (0.01 + q->elevation);		HX_STACK_VAR(newElevation,"newElevation");
					HX_STACK_LINE(535)
					if (((bool(!(q->water)) && bool(!(s1->water))))){
						HX_STACK_LINE(535)
						hx::AddEq(newElevation,(int)1);
					}
					HX_STACK_LINE(540)
					if (((newElevation < s1->elevation))){
						HX_STACK_LINE(541)
						s1->elevation = newElevation;
						HX_STACK_LINE(542)
						queue->__Field(HX_CSTRING("push"),true)(s1);
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,assignCornerElevations,(void))

Void Map_obj::buildGraph( Array< ::neash::geom::Point > points,::com::nodename::delaunay::Voronoi voronoi){
{
		HX_STACK_PUSH("Map::buildGraph","Map.hx",371);
		HX_STACK_THIS(this);
		HX_STACK_ARG(points,"points");
		HX_STACK_ARG(voronoi,"voronoi");
		HX_STACK_LINE(371)
		Array< ::Map > _g = Array_obj< ::Map >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(372)
		::graph::Center p;		HX_STACK_VAR(p,"p");
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		::neash::geom::Point point;		HX_STACK_VAR(point,"point");
		::neash::geom::Point other;		HX_STACK_VAR(other,"other");
		HX_STACK_LINE(373)
		Array< ::com::nodename::delaunay::Edge > libedges = voronoi->edges();		HX_STACK_VAR(libedges,"libedges");
		HX_STACK_LINE(374)
		::nme::ObjectHash centerLookup = ::nme::ObjectHash_obj::__new();		HX_STACK_VAR(centerLookup,"centerLookup");
		HX_STACK_LINE(378)
		{
			HX_STACK_LINE(378)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(378)
			while(((_g1 < points->length))){
				HX_STACK_LINE(378)
				::neash::geom::Point point1 = points->__get(_g1);		HX_STACK_VAR(point1,"point1");
				HX_STACK_LINE(378)
				++(_g1);
				HX_STACK_LINE(379)
				p = ::graph::Center_obj::__new();
				HX_STACK_LINE(380)
				p->index = this->centers->length;
				HX_STACK_LINE(381)
				p->point = point1;
				HX_STACK_LINE(382)
				p->neighbors = Array_obj< ::graph::Center >::__new();
				HX_STACK_LINE(383)
				p->borders = Array_obj< ::graph::Edge >::__new();
				HX_STACK_LINE(384)
				p->corners = Array_obj< ::graph::Corner >::__new();
				HX_STACK_LINE(385)
				this->centers->push(p);
				HX_STACK_LINE(386)
				{
					HX_STACK_LINE(386)
					int id = ::__hxcpp_obj_id(point1);		HX_STACK_VAR(id,"id");
					HX_STACK_LINE(386)
					centerLookup->hashKeys->set(id,point1);
					HX_STACK_LINE(386)
					centerLookup->hashValues->set(id,p);
				}
			}
		}
		HX_STACK_LINE(391)
		{
			HX_STACK_LINE(391)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			Array< ::graph::Center > _g11 = this->centers;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(391)
			while(((_g1 < _g11->length))){
				HX_STACK_LINE(391)
				::graph::Center p1 = _g11->__get(_g1);		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(391)
				++(_g1);
				HX_STACK_LINE(392)
				voronoi->region(p1->point);
			}
		}
		HX_STACK_LINE(401)
		Array< Array< Array< ::graph::Corner > > > _cornerMap = Array_obj< Array< Array< ::graph::Corner > > >::__new().Add(Array_obj< Array< ::graph::Corner > >::__new());		HX_STACK_VAR(_cornerMap,"_cornerMap");

		HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Array< Array< Array< ::graph::Corner > > >,_cornerMap,Array< ::Map >,_g)
		::graph::Corner run(::neash::geom::Point point1){
			HX_STACK_PUSH("*::_Function_1_1","Map.hx",402);
			HX_STACK_ARG(point1,"point1");
			{
				HX_STACK_LINE(403)
				::graph::Corner q1;		HX_STACK_VAR(q1,"q1");
				HX_STACK_LINE(405)
				if (((point1 == null()))){
					HX_STACK_LINE(405)
					return null();
				}
				HX_STACK_LINE(406)
				int bucket;		HX_STACK_VAR(bucket,"bucket");
				HX_STACK_LINE(407)
				{
					HX_STACK_LINE(407)
					int _g1 = (::Std_obj::_int(point1->x) - (int)1);		HX_STACK_VAR(_g1,"_g1");
					int _g2 = (::Std_obj::_int(point1->x) + (int)2);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(407)
					while(((_g1 < _g2))){
						HX_STACK_LINE(407)
						int bucket1 = (_g1)++;		HX_STACK_VAR(bucket1,"bucket1");
						HX_STACK_LINE(408)
						if (((_cornerMap->__get((int)0)->__get(bucket1) != null()))){
							HX_STACK_LINE(409)
							int _g21 = (int)0;		HX_STACK_VAR(_g21,"_g21");
							Array< ::graph::Corner > _g3 = _cornerMap->__get((int)0)->__get(bucket1);		HX_STACK_VAR(_g3,"_g3");
							HX_STACK_LINE(409)
							while(((_g21 < _g3->length))){
								HX_STACK_LINE(409)
								::graph::Corner q2 = _g3->__get(_g21);		HX_STACK_VAR(q2,"q2");
								HX_STACK_LINE(409)
								++(_g21);
								HX_STACK_LINE(410)
								Float dx = (point1->x - q2->point->x);		HX_STACK_VAR(dx,"dx");
								HX_STACK_LINE(411)
								Float dy = (point1->y - q2->point->y);		HX_STACK_VAR(dy,"dy");
								HX_STACK_LINE(412)
								if (((((dx * dx) + (dy * dy)) < 1e-6))){
									HX_STACK_LINE(412)
									return q2;
								}
							}
						}
					}
				}
				HX_STACK_LINE(418)
				bucket = ::Std_obj::_int(point1->x);
				HX_STACK_LINE(419)
				if (((_cornerMap->__get((int)0)->__get(bucket) == null()))){
					HX_STACK_LINE(419)
					_cornerMap->__get((int)0)[bucket] = Array_obj< ::graph::Corner >::__new();
				}
				HX_STACK_LINE(420)
				q1 = ::graph::Corner_obj::__new();
				HX_STACK_LINE(421)
				q1->index = _g->__get((int)0)->corners->length;
				HX_STACK_LINE(422)
				_g->__get((int)0)->corners->push(q1);
				HX_STACK_LINE(423)
				q1->point = point1;
				HX_STACK_LINE(424)
				q1->border = (bool((bool((bool((point1->x == (int)0)) || bool((point1->x == _g->__get((int)0)->SIZE->__Field(HX_CSTRING("width"),true))))) || bool((point1->y == (int)0)))) || bool((point1->y == _g->__get((int)0)->SIZE->__Field(HX_CSTRING("height"),true))));
				HX_STACK_LINE(426)
				q1->touches = Array_obj< ::graph::Center >::__new();
				HX_STACK_LINE(427)
				q1->protrudes = Array_obj< ::graph::Edge >::__new();
				HX_STACK_LINE(428)
				q1->adjacent = Array_obj< ::graph::Corner >::__new();
				HX_STACK_LINE(429)
				_cornerMap->__get((int)0)->__get(bucket)->push(q1);
				HX_STACK_LINE(430)
				return q1;
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(402)
		Dynamic makeCorner =  Dynamic(new _Function_1_1(_cornerMap,_g));		HX_STACK_VAR(makeCorner,"makeCorner");
		HX_STACK_LINE(432)
		{
			HX_STACK_LINE(432)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(432)
			while(((_g1 < libedges->length))){
				HX_STACK_LINE(432)
				::com::nodename::delaunay::Edge libedge = libedges->__get(_g1);		HX_STACK_VAR(libedge,"libedge");
				HX_STACK_LINE(432)
				++(_g1);
				HX_STACK_LINE(433)
				::com::nodename::geom::LineSegment dedge = libedge->delaunayLine();		HX_STACK_VAR(dedge,"dedge");
				HX_STACK_LINE(434)
				::com::nodename::geom::LineSegment vedge = libedge->voronoiEdge();		HX_STACK_VAR(vedge,"vedge");
				HX_STACK_LINE(438)
				::graph::Edge edge = ::graph::Edge_obj::__new();		HX_STACK_VAR(edge,"edge");
				HX_STACK_LINE(439)
				edge->index = this->edges->length;
				HX_STACK_LINE(440)
				edge->river = (int)0;
				HX_STACK_LINE(441)
				this->edges->push(edge);
				HX_STACK_LINE(442)
				edge->midpoint = (  (((bool((vedge->p0 != null())) && bool((vedge->p1 != null()))))) ? ::neash::geom::Point(::neash::geom::Point_obj::interpolate(vedge->p0,vedge->p1,0.5)) : ::neash::geom::Point(null()) );
				HX_STACK_LINE(445)
				edge->v0 = makeCorner(vedge->p0).Cast< ::graph::Corner >();
				HX_STACK_LINE(446)
				edge->v1 = makeCorner(vedge->p1).Cast< ::graph::Corner >();
				HX_STACK_LINE(447)
				edge->d0 = centerLookup->hashValues->get(::__hxcpp_obj_id(dedge->p0));
				HX_STACK_LINE(448)
				edge->d1 = centerLookup->hashValues->get(::__hxcpp_obj_id(dedge->p1));
				HX_STACK_LINE(451)
				if (((edge->d0 != null()))){
					HX_STACK_LINE(451)
					edge->d0->borders->push(edge);
				}
				HX_STACK_LINE(452)
				if (((edge->d1 != null()))){
					HX_STACK_LINE(452)
					edge->d1->borders->push(edge);
				}
				HX_STACK_LINE(453)
				if (((edge->v0 != null()))){
					HX_STACK_LINE(453)
					edge->v0->protrudes->push(edge);
				}
				HX_STACK_LINE(454)
				if (((edge->v1 != null()))){
					HX_STACK_LINE(454)
					edge->v1->protrudes->push(edge);
				}

				HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_3_1)
				Void run(Array< ::graph::Corner > v,::graph::Corner x){
					HX_STACK_PUSH("*::_Function_3_1","Map.hx",456);
					HX_STACK_ARG(v,"v");
					HX_STACK_ARG(x,"x");
					{
						HX_STACK_LINE(456)
						if (((bool((x != null())) && bool((::Lambda_obj::indexOf(v,x) < (int)0))))){
							HX_STACK_LINE(457)
							v->push(x);
						}
					}
					return null();
				}
				HX_END_LOCAL_FUNC2((void))

				HX_STACK_LINE(456)
				Dynamic addToCornerList =  Dynamic(new _Function_3_1());		HX_STACK_VAR(addToCornerList,"addToCornerList");

				HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_3_2)
				Void run(Array< ::graph::Center > v,::graph::Center x){
					HX_STACK_PUSH("*::_Function_3_2","Map.hx",459);
					HX_STACK_ARG(v,"v");
					HX_STACK_ARG(x,"x");
					{
						HX_STACK_LINE(459)
						if (((bool((x != null())) && bool((::Lambda_obj::indexOf(v,x) < (int)0))))){
							HX_STACK_LINE(460)
							v->push(x);
						}
					}
					return null();
				}
				HX_END_LOCAL_FUNC2((void))

				HX_STACK_LINE(459)
				Dynamic addToCenterList =  Dynamic(new _Function_3_2());		HX_STACK_VAR(addToCenterList,"addToCenterList");
				HX_STACK_LINE(464)
				if (((bool((edge->d0 != null())) && bool((edge->d1 != null()))))){
					HX_STACK_LINE(465)
					addToCenterList(edge->d0->neighbors,edge->d1).Cast< Void >();
					HX_STACK_LINE(466)
					addToCenterList(edge->d1->neighbors,edge->d0).Cast< Void >();
				}
				HX_STACK_LINE(470)
				if (((bool((edge->v0 != null())) && bool((edge->v1 != null()))))){
					HX_STACK_LINE(471)
					addToCornerList(edge->v0->adjacent,edge->v1).Cast< Void >();
					HX_STACK_LINE(472)
					addToCornerList(edge->v1->adjacent,edge->v0).Cast< Void >();
				}
				HX_STACK_LINE(476)
				if (((edge->d0 != null()))){
					HX_STACK_LINE(477)
					addToCornerList(edge->d0->corners,edge->v0).Cast< Void >();
					HX_STACK_LINE(478)
					addToCornerList(edge->d0->corners,edge->v1).Cast< Void >();
				}
				HX_STACK_LINE(480)
				if (((edge->d1 != null()))){
					HX_STACK_LINE(481)
					addToCornerList(edge->d1->corners,edge->v0).Cast< Void >();
					HX_STACK_LINE(482)
					addToCornerList(edge->d1->corners,edge->v1).Cast< Void >();
				}
				HX_STACK_LINE(486)
				if (((edge->v0 != null()))){
					HX_STACK_LINE(487)
					addToCenterList(edge->v0->touches,edge->d0).Cast< Void >();
					HX_STACK_LINE(488)
					addToCenterList(edge->v0->touches,edge->d1).Cast< Void >();
				}
				HX_STACK_LINE(490)
				if (((edge->v1 != null()))){
					HX_STACK_LINE(491)
					addToCenterList(edge->v1->touches,edge->d0).Cast< Void >();
					HX_STACK_LINE(492)
					addToCenterList(edge->v1->touches,edge->d1).Cast< Void >();
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Map_obj,buildGraph,(void))

Dynamic Map_obj::landCorners( Array< ::graph::Corner > corners){
	HX_STACK_PUSH("Map::landCorners","Map.hx",352);
	HX_STACK_THIS(this);
	HX_STACK_ARG(corners,"corners");
	HX_STACK_LINE(353)
	::graph::Corner q;		HX_STACK_VAR(q,"q");
	Dynamic locations = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(locations,"locations");
	HX_STACK_LINE(354)
	{
		HX_STACK_LINE(354)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(354)
		while(((_g < corners->length))){
			HX_STACK_LINE(354)
			::graph::Corner q1 = corners->__get(_g);		HX_STACK_VAR(q1,"q1");
			HX_STACK_LINE(354)
			++(_g);
			HX_STACK_LINE(355)
			if (((bool(!(q1->ocean)) && bool(!(q1->coast))))){
				HX_STACK_LINE(355)
				locations->__Field(HX_CSTRING("push"),true)(q1);
			}
		}
	}
	HX_STACK_LINE(359)
	return locations;
}


HX_DEFINE_DYNAMIC_FUNC1(Map_obj,landCorners,return )

Void Map_obj::improveCorners( ){
{
		HX_STACK_PUSH("Map::improveCorners","Map.hx",312);
		HX_STACK_THIS(this);
		HX_STACK_LINE(314)
		Array< ::neash::geom::Point > newCorners = Array_obj< ::neash::geom::Point >::__new();		HX_STACK_VAR(newCorners,"newCorners");
		HX_STACK_LINE(315)
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		::graph::Center r;		HX_STACK_VAR(r,"r");
		::neash::geom::Point point;		HX_STACK_VAR(point,"point");
		int i;		HX_STACK_VAR(i,"i");
		::graph::Edge edge;		HX_STACK_VAR(edge,"edge");
		HX_STACK_LINE(318)
		{
			HX_STACK_LINE(318)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Corner > _g1 = this->corners;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(318)
			while(((_g < _g1->length))){
				HX_STACK_LINE(318)
				::graph::Corner q1 = _g1->__get(_g);		HX_STACK_VAR(q1,"q1");
				HX_STACK_LINE(318)
				++(_g);
				HX_STACK_LINE(319)
				if ((q1->border)){
					HX_STACK_LINE(319)
					newCorners[q1->index] = q1->point;
				}
				else{
					HX_STACK_LINE(322)
					point = ::neash::geom::Point_obj::__new(0.0,0.0);
					HX_STACK_LINE(323)
					{
						HX_STACK_LINE(323)
						int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
						Array< ::graph::Center > _g3 = q1->touches;		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(323)
						while(((_g2 < _g3->length))){
							HX_STACK_LINE(323)
							::graph::Center r1 = _g3->__get(_g2);		HX_STACK_VAR(r1,"r1");
							HX_STACK_LINE(323)
							++(_g2);
							HX_STACK_LINE(324)
							hx::AddEq(point->x,r1->point->x);
							HX_STACK_LINE(325)
							hx::AddEq(point->y,r1->point->y);
						}
					}
					HX_STACK_LINE(327)
					hx::DivEq(point->x,q1->touches->length);
					HX_STACK_LINE(328)
					hx::DivEq(point->y,q1->touches->length);
					HX_STACK_LINE(329)
					newCorners[q1->index] = point;
				}
			}
		}
		HX_STACK_LINE(334)
		{
			HX_STACK_LINE(334)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->corners->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(334)
			while(((_g1 < _g))){
				HX_STACK_LINE(334)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(335)
				this->corners->__get(i1)->point = newCorners->__get(i1);
			}
		}
		HX_STACK_LINE(340)
		{
			HX_STACK_LINE(340)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Edge > _g1 = this->edges;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(340)
			while(((_g < _g1->length))){
				HX_STACK_LINE(340)
				::graph::Edge edge1 = _g1->__get(_g);		HX_STACK_VAR(edge1,"edge1");
				HX_STACK_LINE(340)
				++(_g);
				HX_STACK_LINE(341)
				if (((bool((edge1->v0 != null())) && bool((edge1->v1 != null()))))){
					HX_STACK_LINE(341)
					edge1->midpoint = ::neash::geom::Point_obj::interpolate(edge1->v0->point,edge1->v1->point,0.5);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,improveCorners,(void))

Void Map_obj::improveRandomPoints( Array< ::neash::geom::Point > points){
{
		HX_STACK_PUSH("Map::improveRandomPoints","Map.hx",263);
		HX_STACK_THIS(this);
		HX_STACK_ARG(points,"points");
		HX_STACK_LINE(264)
		return null();
		HX_STACK_LINE(276)
		int i;		HX_STACK_VAR(i,"i");
		::com::nodename::delaunay::Voronoi voronoi;		HX_STACK_VAR(voronoi,"voronoi");
		Array< ::neash::geom::Point > region;		HX_STACK_VAR(region,"region");
		::neash::geom::Point tmp_p = ::neash::geom::Point_obj::__new(null(),null());		HX_STACK_VAR(tmp_p,"tmp_p");
		HX_STACK_LINE(277)
		{
			HX_STACK_LINE(277)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = ::Map_obj::NUM_LLOYD_ITERATIONS;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(277)
			while(((_g1 < _g))){
				HX_STACK_LINE(277)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(278)
				voronoi = ::com::nodename::delaunay::Voronoi_obj::__new(points,null(),::neash::geom::Rectangle_obj::__new((int)0,(int)0,this->SIZE->__Field(HX_CSTRING("width"),true),this->SIZE->__Field(HX_CSTRING("height"),true)));
				HX_STACK_LINE(279)
				{
					HX_STACK_LINE(279)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(279)
					while(((_g2 < points->length))){
						HX_STACK_LINE(279)
						::neash::geom::Point p = points->__get(_g2);		HX_STACK_VAR(p,"p");
						HX_STACK_LINE(279)
						++(_g2);
						HX_STACK_LINE(281)
						region = voronoi->region(p);
						HX_STACK_LINE(283)
						if (((region->length == (int)0))){
							HX_STACK_LINE(284)
							continue;
						}
						HX_STACK_LINE(288)
						p->x = 0.0;
						HX_STACK_LINE(289)
						p->y = 0.0;
						HX_STACK_LINE(290)
						{
							HX_STACK_LINE(290)
							int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
							HX_STACK_LINE(290)
							while(((_g3 < region->length))){
								HX_STACK_LINE(290)
								::neash::geom::Point q = region->__get(_g3);		HX_STACK_VAR(q,"q");
								HX_STACK_LINE(290)
								++(_g3);
								HX_STACK_LINE(291)
								hx::AddEq(p->x,q->x);
								HX_STACK_LINE(292)
								hx::AddEq(p->y,q->y);
							}
						}
						HX_STACK_LINE(294)
						tmp_p->x = (Float(tmp_p->x) / Float(region->length));
						HX_STACK_LINE(295)
						tmp_p->y = (Float(tmp_p->x) / Float(region->length));
						HX_STACK_LINE(297)
						region->splice((int)0,region->length);
					}
				}
				HX_STACK_LINE(299)
				voronoi->dispose();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Map_obj,improveRandomPoints,(void))

Array< ::neash::geom::Point > Map_obj::generateRandomPoints( ){
	HX_STACK_PUSH("Map::generateRandomPoints","Map.hx",241);
	HX_STACK_THIS(this);
	HX_STACK_LINE(242)
	::neash::geom::Point p;		HX_STACK_VAR(p,"p");
	int i;		HX_STACK_VAR(i,"i");
	Array< ::neash::geom::Point > points = Array_obj< ::neash::geom::Point >::__new();		HX_STACK_VAR(points,"points");
	HX_STACK_LINE(243)
	int h_step = ::Math_obj::ceil((Float(this->SIZE->__Field(HX_CSTRING("width"),true)) / Float(::Map_obj::NUM_COLUMNS)));		HX_STACK_VAR(h_step,"h_step");
	HX_STACK_LINE(244)
	int v_step = ::Math_obj::ceil((Float(this->SIZE->__Field(HX_CSTRING("height"),true)) / Float(::Map_obj::NUM_ROWS)));		HX_STACK_VAR(v_step,"v_step");
	HX_STACK_LINE(245)
	bool odd = true;		HX_STACK_VAR(odd,"odd");
	HX_STACK_LINE(246)
	{
		HX_STACK_LINE(246)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = ::Map_obj::NUM_COLUMNS;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(246)
		while(((_g1 < _g))){
			HX_STACK_LINE(246)
			int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
			HX_STACK_LINE(248)
			{
				HX_STACK_LINE(248)
				int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
				int _g2 = ::Map_obj::NUM_ROWS;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(248)
				while(((_g3 < _g2))){
					HX_STACK_LINE(248)
					int j = (_g3)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(250)
					odd = !(odd);
					HX_STACK_LINE(252)
					p = ::neash::geom::Point_obj::__new(((this->mapRandom->nextDoubleRange((int)10,h_step) + (h_step * i1)) + ((  ((odd)) ? Float((Float(h_step) / Float((int)2))) : Float((int)0) ))),(this->mapRandom->nextDoubleRange((int)10,v_step) + (v_step * j)));
					HX_STACK_LINE(254)
					points->push(p);
				}
			}
		}
	}
	HX_STACK_LINE(258)
	return points;
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,generateRandomPoints,return )

Void Map_obj::go( int first,int last){
{
		HX_STACK_PUSH("Map::go","Map.hx",123);
		HX_STACK_THIS(this);
		HX_STACK_ARG(first,"first");
		HX_STACK_ARG(last,"last");
		HX_STACK_LINE(123)
		Array< ::Map > _g = Array_obj< ::Map >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(124)
		Dynamic stages = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(stages,"stages");

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		Void run(::String name,Dynamic fn){
			HX_STACK_PUSH("*::_Function_1_1","Map.hx",126);
			HX_STACK_ARG(name,"name");
			HX_STACK_ARG(fn,"fn");
			{
				HX_STACK_LINE(126)
				fn().Cast< Void >();
			}
			return null();
		}
		HX_END_LOCAL_FUNC2((void))

		HX_STACK_LINE(126)
		Dynamic timeIt =  Dynamic(new _Function_1_1());		HX_STACK_VAR(timeIt,"timeIt");

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_2,Array< ::Map >,_g)
		Void run(){
			HX_STACK_PUSH("*::_Function_1_2","Map.hx",134);
			{
				HX_STACK_LINE(135)
				_g->__get((int)0)->reset();
				HX_STACK_LINE(136)
				::nme::Lib_obj::trace(HX_CSTRING("generating random points"));
				HX_STACK_LINE(137)
				_g->__get((int)0)->points = _g->__get((int)0)->generateRandomPoints();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(132)
		stages->__Field(HX_CSTRING("push"),true)(Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("Place points...")).Add( Dynamic(new _Function_1_2(_g)))));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_3,Array< ::Map >,_g)
		Void run(){
			HX_STACK_PUSH("*::_Function_1_3","Map.hx",142);
			{
				HX_STACK_LINE(143)
				::nme::Lib_obj::trace(HX_CSTRING("improving points"));
				HX_STACK_LINE(144)
				_g->__get((int)0)->improveRandomPoints(_g->__get((int)0)->points);
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(140)
		stages->__Field(HX_CSTRING("push"),true)(Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("Improve points...")).Add( Dynamic(new _Function_1_3(_g)))));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_4,Array< ::Map >,_g)
		Void run(){
			HX_STACK_PUSH("*::_Function_1_4","Map.hx",157);
			{
				HX_STACK_LINE(158)
				::nme::Lib_obj::trace(HX_CSTRING("building graph"));
				HX_STACK_LINE(159)
				::com::nodename::delaunay::Voronoi voronoi = ::com::nodename::delaunay::Voronoi_obj::__new(_g->__get((int)0)->points,null(),::neash::geom::Rectangle_obj::__new((int)0,(int)0,_g->__get((int)0)->SIZE->__Field(HX_CSTRING("width"),true),_g->__get((int)0)->SIZE->__Field(HX_CSTRING("height"),true)));		HX_STACK_VAR(voronoi,"voronoi");
				HX_STACK_LINE(160)
				_g->__get((int)0)->buildGraph(_g->__get((int)0)->points,voronoi);
				HX_STACK_LINE(161)
				_g->__get((int)0)->improveCorners();
				HX_STACK_LINE(162)
				voronoi->dispose();
				HX_STACK_LINE(163)
				voronoi = null();
				HX_STACK_LINE(164)
				_g->__get((int)0)->points = null();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(155)
		stages->__Field(HX_CSTRING("push"),true)(Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("Build graph...")).Add( Dynamic(new _Function_1_4(_g)))));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_5,Array< ::Map >,_g)
		Void run(){
			HX_STACK_PUSH("*::_Function_1_5","Map.hx",169);
			{
				HX_STACK_LINE(170)
				::nme::Lib_obj::trace(HX_CSTRING("assigning elevations"));
				HX_STACK_LINE(172)
				_g->__get((int)0)->assignCornerElevations();
				HX_STACK_LINE(175)
				_g->__get((int)0)->assignOceanCoastAndLand();
				HX_STACK_LINE(184)
				_g->__get((int)0)->redistributeElevations(_g->__get((int)0)->landCorners(_g->__get((int)0)->corners));
				HX_STACK_LINE(187)
				{
					HX_STACK_LINE(187)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					Array< ::graph::Corner > _g2 = _g->__get((int)0)->corners;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(187)
					while(((_g1 < _g2->length))){
						HX_STACK_LINE(187)
						::graph::Corner q = _g2->__get(_g1);		HX_STACK_VAR(q,"q");
						HX_STACK_LINE(187)
						++(_g1);
						HX_STACK_LINE(189)
						if (((bool(q->ocean) || bool(q->coast)))){
							HX_STACK_LINE(190)
							q->elevation = 0.0;
						}
					}
				}
				HX_STACK_LINE(196)
				_g->__get((int)0)->assignPolygonElevations();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(167)
		stages->__Field(HX_CSTRING("push"),true)(Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("Assign elevations...")).Add( Dynamic(new _Function_1_5(_g)))));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_6,Array< ::Map >,_g)
		Void run(){
			HX_STACK_PUSH("*::_Function_1_6","Map.hx",202);
			{
				HX_STACK_LINE(203)
				::nme::Lib_obj::trace(HX_CSTRING("assigning moisture"));
				HX_STACK_LINE(205)
				_g->__get((int)0)->calculateDownslopes();
				HX_STACK_LINE(209)
				_g->__get((int)0)->calculateWatersheds();
				HX_STACK_LINE(212)
				_g->__get((int)0)->createRivers();
				HX_STACK_LINE(219)
				_g->__get((int)0)->assignCornerMoisture();
				HX_STACK_LINE(220)
				_g->__get((int)0)->redistributeMoisture(_g->__get((int)0)->landCorners(_g->__get((int)0)->corners));
				HX_STACK_LINE(221)
				_g->__get((int)0)->assignPolygonMoisture();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(200)
		stages->__Field(HX_CSTRING("push"),true)(Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("Assign moisture...")).Add( Dynamic(new _Function_1_6(_g)))));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_7,Array< ::Map >,_g)
		Void run(){
			HX_STACK_PUSH("*::_Function_1_7","Map.hx",226);
			{
				HX_STACK_LINE(227)
				::nme::Lib_obj::trace(HX_CSTRING("decorating map"));
				HX_STACK_LINE(228)
				_g->__get((int)0)->assignBiomes();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(224)
		stages->__Field(HX_CSTRING("push"),true)(Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("Decorate map...")).Add( Dynamic(new _Function_1_7(_g)))));
		HX_STACK_LINE(231)
		{
			HX_STACK_LINE(231)
			int _g1 = first;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(231)
			while(((_g1 < last))){
				HX_STACK_LINE(231)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(232)
				timeIt(stages->__GetItem(i)->__GetItem((int)0),stages->__GetItem(i)->__GetItem((int)1)).Cast< Void >();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Map_obj,go,(void))

Void Map_obj::reset( ){
{
		HX_STACK_PUSH("Map::reset","Map.hx",80);
		HX_STACK_THIS(this);
		HX_STACK_LINE(81)
		::graph::Center p;		HX_STACK_VAR(p,"p");
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		::graph::Edge edge;		HX_STACK_VAR(edge,"edge");
		HX_STACK_LINE(84)
		if (((this->points != null()))){
			HX_STACK_LINE(84)
			this->points->splice((int)0,this->points->length);
		}
		HX_STACK_LINE(87)
		if (((this->edges != null()))){
			HX_STACK_LINE(88)
			{
				HX_STACK_LINE(88)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::graph::Edge > _g1 = this->edges;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(88)
				while(((_g < _g1->length))){
					HX_STACK_LINE(88)
					::graph::Edge edge1 = _g1->__get(_g);		HX_STACK_VAR(edge1,"edge1");
					HX_STACK_LINE(88)
					++(_g);
					HX_STACK_LINE(89)
					edge1->d0 = edge1->d1 = null();
					HX_STACK_LINE(90)
					edge1->v0 = edge1->v1 = null();
				}
			}
			HX_STACK_LINE(92)
			this->edges->splice((int)0,this->edges->length);
		}
		HX_STACK_LINE(94)
		if (((this->centers != null()))){
			HX_STACK_LINE(95)
			{
				HX_STACK_LINE(95)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::graph::Center > _g1 = this->centers;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(95)
				while(((_g < _g1->length))){
					HX_STACK_LINE(95)
					::graph::Center p1 = _g1->__get(_g);		HX_STACK_VAR(p1,"p1");
					HX_STACK_LINE(95)
					++(_g);
					HX_STACK_LINE(96)
					p1->neighbors->splice((int)0,p1->neighbors->length);
					HX_STACK_LINE(97)
					p1->corners->splice((int)0,p1->corners->length);
					HX_STACK_LINE(98)
					p1->borders->splice((int)0,p1->borders->length);
				}
			}
			HX_STACK_LINE(100)
			this->centers->splice((int)0,this->centers->length);
		}
		HX_STACK_LINE(102)
		if (((this->corners != null()))){
			HX_STACK_LINE(103)
			{
				HX_STACK_LINE(103)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::graph::Corner > _g1 = this->corners;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(103)
				while(((_g < _g1->length))){
					HX_STACK_LINE(103)
					::graph::Corner q1 = _g1->__get(_g);		HX_STACK_VAR(q1,"q1");
					HX_STACK_LINE(103)
					++(_g);
					HX_STACK_LINE(104)
					q1->adjacent->splice((int)0,q1->adjacent->length);
					HX_STACK_LINE(105)
					q1->touches->splice((int)0,q1->touches->length);
					HX_STACK_LINE(106)
					q1->protrudes->splice((int)0,q1->protrudes->length);
					HX_STACK_LINE(107)
					q1->downslope = null();
					HX_STACK_LINE(108)
					q1->watershed = null();
				}
			}
			HX_STACK_LINE(110)
			this->corners->splice((int)0,this->corners->length);
		}
		HX_STACK_LINE(114)
		if (((this->points == null()))){
			HX_STACK_LINE(114)
			this->points = Array_obj< ::neash::geom::Point >::__new();
		}
		HX_STACK_LINE(115)
		if (((this->edges == null()))){
			HX_STACK_LINE(115)
			this->edges = Array_obj< ::graph::Edge >::__new();
		}
		HX_STACK_LINE(116)
		if (((this->centers == null()))){
			HX_STACK_LINE(116)
			this->centers = Array_obj< ::graph::Center >::__new();
		}
		HX_STACK_LINE(117)
		if (((this->corners == null()))){
			HX_STACK_LINE(117)
			this->corners = Array_obj< ::graph::Corner >::__new();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,reset,(void))

Void Map_obj::newIsland( ::String type,int seed,int variant){
{
		HX_STACK_PUSH("Map::newIsland","Map.hx",61);
		HX_STACK_THIS(this);
		HX_STACK_ARG(type,"type");
		HX_STACK_ARG(seed,"seed");
		HX_STACK_ARG(variant,"variant");
		HX_STACK_LINE(63)
		::String _switch_1 = (type);
		if (  ( _switch_1==HX_CSTRING("Perlin"))){
			HX_STACK_LINE(65)
			this->islandShape = ::IslandShape_obj::makePerlin(seed);
		}
		else if (  ( _switch_1==HX_CSTRING("Square"))){
			HX_STACK_LINE(67)
			this->islandShape = ::IslandShape_obj::makeSquare(seed);
		}
		else if (  ( _switch_1==HX_CSTRING("Blob"))){
			HX_STACK_LINE(69)
			this->islandShape = ::IslandShape_obj::makeBlob(seed);
		}
		else if (  ( _switch_1==HX_CSTRING("Radial"))){
			HX_STACK_LINE(71)
			this->islandShape = ::IslandShape_obj::makeRadial(seed);
		}
		else  {
			HX_STACK_LINE(73)
			this->islandShape = ::IslandShape_obj::makePerlin(seed);
		}
;
;
		HX_STACK_LINE(76)
		this->mapRandom->seed = variant;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Map_obj,newIsland,(void))

int Map_obj::NUM_POINTS;

int Map_obj::NUM_ROWS;

int Map_obj::NUM_COLUMNS;

Float Map_obj::LAKE_THRESHOLD;

int Map_obj::NUM_LLOYD_ITERATIONS;

::String Map_obj::getBiome( ::graph::Center p){
	HX_STACK_PUSH("Map::getBiome","Map.hx",833);
	HX_STACK_ARG(p,"p");
	HX_STACK_LINE(833)
	if ((p->ocean)){
		HX_STACK_LINE(835)
		return HX_CSTRING("OCEAN");
	}
	else{
		HX_STACK_LINE(837)
		if ((p->water)){
			HX_STACK_LINE(838)
			if (((p->elevation < 0.1))){
				HX_STACK_LINE(838)
				return HX_CSTRING("MARSH");
			}
			HX_STACK_LINE(839)
			if (((p->elevation > 0.8))){
				HX_STACK_LINE(839)
				return HX_CSTRING("ICE");
			}
			HX_STACK_LINE(840)
			return HX_CSTRING("LAKE");
		}
		else{
			HX_STACK_LINE(841)
			if ((p->coast)){
				HX_STACK_LINE(841)
				return HX_CSTRING("BEACH");
			}
			else{
				HX_STACK_LINE(843)
				if (((p->elevation > 0.8))){
					HX_STACK_LINE(843)
					if (((p->moisture > 0.50))){
						HX_STACK_LINE(844)
						return HX_CSTRING("SNOW");
					}
					else{
						HX_STACK_LINE(845)
						if (((p->moisture > 0.33))){
							HX_STACK_LINE(845)
							return HX_CSTRING("TUNDRA");
						}
						else{
							HX_STACK_LINE(846)
							if (((p->moisture > 0.16))){
								HX_STACK_LINE(846)
								return HX_CSTRING("BARE");
							}
							else{
								HX_STACK_LINE(847)
								return HX_CSTRING("SCORCHED");
							}
						}
					}
				}
				else{
					HX_STACK_LINE(848)
					if (((p->elevation > 0.6))){
						HX_STACK_LINE(848)
						if (((p->moisture > 0.66))){
							HX_STACK_LINE(849)
							return HX_CSTRING("TAIGA");
						}
						else{
							HX_STACK_LINE(850)
							if (((p->moisture > 0.33))){
								HX_STACK_LINE(850)
								return HX_CSTRING("SHRUBLAND");
							}
							else{
								HX_STACK_LINE(851)
								return HX_CSTRING("TEMPERATE_DESERT");
							}
						}
					}
					else{
						HX_STACK_LINE(852)
						if (((p->elevation > 0.3))){
							HX_STACK_LINE(852)
							if (((p->moisture > 0.83))){
								HX_STACK_LINE(853)
								return HX_CSTRING("TEMPERATE_RAIN_FOREST");
							}
							else{
								HX_STACK_LINE(854)
								if (((p->moisture > 0.50))){
									HX_STACK_LINE(854)
									return HX_CSTRING("TEMPERATE_DECIDUOUS_FOREST");
								}
								else{
									HX_STACK_LINE(855)
									if (((p->moisture > 0.16))){
										HX_STACK_LINE(855)
										return HX_CSTRING("GRASSLAND");
									}
									else{
										HX_STACK_LINE(856)
										return HX_CSTRING("TEMPERATE_DESERT");
									}
								}
							}
						}
						else{
							HX_STACK_LINE(857)
							if (((p->moisture > 0.66))){
								HX_STACK_LINE(858)
								return HX_CSTRING("TROPICAL_RAIN_FOREST");
							}
							else{
								HX_STACK_LINE(859)
								if (((p->moisture > 0.33))){
									HX_STACK_LINE(859)
									return HX_CSTRING("TROPICAL_SEASONAL_FOREST");
								}
								else{
									HX_STACK_LINE(860)
									if (((p->moisture > 0.16))){
										HX_STACK_LINE(860)
										return HX_CSTRING("GRASSLAND");
									}
									else{
										HX_STACK_LINE(861)
										return HX_CSTRING("SUBTROPICAL_DESERT");
									}
								}
							}
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(833)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Map_obj,getBiome,return )


Map_obj::Map_obj()
{
}

void Map_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Map);
	HX_MARK_MEMBER_NAME(edges,"edges");
	HX_MARK_MEMBER_NAME(corners,"corners");
	HX_MARK_MEMBER_NAME(centers,"centers");
	HX_MARK_MEMBER_NAME(points,"points");
	HX_MARK_MEMBER_NAME(mapRandom,"mapRandom");
	HX_MARK_MEMBER_NAME(islandShape,"islandShape");
	HX_MARK_MEMBER_NAME(SIZE,"SIZE");
	HX_MARK_END_CLASS();
}

void Map_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(edges,"edges");
	HX_VISIT_MEMBER_NAME(corners,"corners");
	HX_VISIT_MEMBER_NAME(centers,"centers");
	HX_VISIT_MEMBER_NAME(points,"points");
	HX_VISIT_MEMBER_NAME(mapRandom,"mapRandom");
	HX_VISIT_MEMBER_NAME(islandShape,"islandShape");
	HX_VISIT_MEMBER_NAME(SIZE,"SIZE");
}

Dynamic Map_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"go") ) { return go_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"SIZE") ) { return SIZE; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"edges") ) { return edges; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"inside") ) { return inside_dyn(); }
		if (HX_FIELD_EQ(inName,"points") ) { return points; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"corners") ) { return corners; }
		if (HX_FIELD_EQ(inName,"centers") ) { return centers; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"NUM_ROWS") ) { return NUM_ROWS; }
		if (HX_FIELD_EQ(inName,"getBiome") ) { return getBiome_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"newIsland") ) { return newIsland_dyn(); }
		if (HX_FIELD_EQ(inName,"mapRandom") ) { return mapRandom; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"NUM_POINTS") ) { return NUM_POINTS; }
		if (HX_FIELD_EQ(inName,"buildGraph") ) { return buildGraph_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"NUM_COLUMNS") ) { return NUM_COLUMNS; }
		if (HX_FIELD_EQ(inName,"landCorners") ) { return landCorners_dyn(); }
		if (HX_FIELD_EQ(inName,"islandShape") ) { return islandShape; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"assignBiomes") ) { return assignBiomes_dyn(); }
		if (HX_FIELD_EQ(inName,"createRivers") ) { return createRivers_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"LAKE_THRESHOLD") ) { return LAKE_THRESHOLD; }
		if (HX_FIELD_EQ(inName,"improveCorners") ) { return improveCorners_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"calculateWatersheds") ) { return calculateWatersheds_dyn(); }
		if (HX_FIELD_EQ(inName,"calculateDownslopes") ) { return calculateDownslopes_dyn(); }
		if (HX_FIELD_EQ(inName,"improveRandomPoints") ) { return improveRandomPoints_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"NUM_LLOYD_ITERATIONS") ) { return NUM_LLOYD_ITERATIONS; }
		if (HX_FIELD_EQ(inName,"lookupEdgeFromCorner") ) { return lookupEdgeFromCorner_dyn(); }
		if (HX_FIELD_EQ(inName,"lookupEdgeFromCenter") ) { return lookupEdgeFromCenter_dyn(); }
		if (HX_FIELD_EQ(inName,"assignCornerMoisture") ) { return assignCornerMoisture_dyn(); }
		if (HX_FIELD_EQ(inName,"redistributeMoisture") ) { return redistributeMoisture_dyn(); }
		if (HX_FIELD_EQ(inName,"generateRandomPoints") ) { return generateRandomPoints_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"assignPolygonMoisture") ) { return assignPolygonMoisture_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"redistributeElevations") ) { return redistributeElevations_dyn(); }
		if (HX_FIELD_EQ(inName,"assignCornerElevations") ) { return assignCornerElevations_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"assignPolygonElevations") ) { return assignPolygonElevations_dyn(); }
		if (HX_FIELD_EQ(inName,"assignOceanCoastAndLand") ) { return assignOceanCoastAndLand_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Map_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"SIZE") ) { SIZE=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"edges") ) { edges=inValue.Cast< Array< ::graph::Edge > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"points") ) { points=inValue.Cast< Array< ::neash::geom::Point > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"corners") ) { corners=inValue.Cast< Array< ::graph::Corner > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"centers") ) { centers=inValue.Cast< Array< ::graph::Center > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"NUM_ROWS") ) { NUM_ROWS=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mapRandom") ) { mapRandom=inValue.Cast< ::de::polygonal::math::PM_PRNG >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"NUM_POINTS") ) { NUM_POINTS=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"NUM_COLUMNS") ) { NUM_COLUMNS=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"islandShape") ) { islandShape=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"LAKE_THRESHOLD") ) { LAKE_THRESHOLD=inValue.Cast< Float >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"NUM_LLOYD_ITERATIONS") ) { NUM_LLOYD_ITERATIONS=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Map_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("edges"));
	outFields->push(HX_CSTRING("corners"));
	outFields->push(HX_CSTRING("centers"));
	outFields->push(HX_CSTRING("points"));
	outFields->push(HX_CSTRING("mapRandom"));
	outFields->push(HX_CSTRING("SIZE"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("NUM_POINTS"),
	HX_CSTRING("NUM_ROWS"),
	HX_CSTRING("NUM_COLUMNS"),
	HX_CSTRING("LAKE_THRESHOLD"),
	HX_CSTRING("NUM_LLOYD_ITERATIONS"),
	HX_CSTRING("getBiome"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("inside"),
	HX_CSTRING("lookupEdgeFromCorner"),
	HX_CSTRING("lookupEdgeFromCenter"),
	HX_CSTRING("assignBiomes"),
	HX_CSTRING("assignPolygonMoisture"),
	HX_CSTRING("assignCornerMoisture"),
	HX_CSTRING("createRivers"),
	HX_CSTRING("calculateWatersheds"),
	HX_CSTRING("calculateDownslopes"),
	HX_CSTRING("assignPolygonElevations"),
	HX_CSTRING("assignOceanCoastAndLand"),
	HX_CSTRING("redistributeMoisture"),
	HX_CSTRING("redistributeElevations"),
	HX_CSTRING("assignCornerElevations"),
	HX_CSTRING("buildGraph"),
	HX_CSTRING("landCorners"),
	HX_CSTRING("improveCorners"),
	HX_CSTRING("improveRandomPoints"),
	HX_CSTRING("generateRandomPoints"),
	HX_CSTRING("go"),
	HX_CSTRING("reset"),
	HX_CSTRING("newIsland"),
	HX_CSTRING("edges"),
	HX_CSTRING("corners"),
	HX_CSTRING("centers"),
	HX_CSTRING("points"),
	HX_CSTRING("mapRandom"),
	HX_CSTRING("islandShape"),
	HX_CSTRING("SIZE"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Map_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Map_obj::NUM_POINTS,"NUM_POINTS");
	HX_MARK_MEMBER_NAME(Map_obj::NUM_ROWS,"NUM_ROWS");
	HX_MARK_MEMBER_NAME(Map_obj::NUM_COLUMNS,"NUM_COLUMNS");
	HX_MARK_MEMBER_NAME(Map_obj::LAKE_THRESHOLD,"LAKE_THRESHOLD");
	HX_MARK_MEMBER_NAME(Map_obj::NUM_LLOYD_ITERATIONS,"NUM_LLOYD_ITERATIONS");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Map_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Map_obj::NUM_POINTS,"NUM_POINTS");
	HX_VISIT_MEMBER_NAME(Map_obj::NUM_ROWS,"NUM_ROWS");
	HX_VISIT_MEMBER_NAME(Map_obj::NUM_COLUMNS,"NUM_COLUMNS");
	HX_VISIT_MEMBER_NAME(Map_obj::LAKE_THRESHOLD,"LAKE_THRESHOLD");
	HX_VISIT_MEMBER_NAME(Map_obj::NUM_LLOYD_ITERATIONS,"NUM_LLOYD_ITERATIONS");
};

Class Map_obj::__mClass;

void Map_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Map"), hx::TCanCast< Map_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Map_obj::__boot()
{
	NUM_POINTS= (::Map_obj::NUM_ROWS * ::Map_obj::NUM_COLUMNS);
	NUM_ROWS= (int)40;
	NUM_COLUMNS= (int)50;
	LAKE_THRESHOLD= 0.3;
	NUM_LLOYD_ITERATIONS= (int)2;
}


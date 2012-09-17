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
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
#ifndef INCLUDED_neash_geom_Rectangle
#include <neash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_nme_ObjectHash
#include <nme/ObjectHash.h>
#endif

Void Map_obj::__construct(Dynamic size)
{
HX_STACK_PUSH("Map::new","Map.hx",45);
{
	HX_STACK_LINE(46)
	this->mapRandom = ::de::polygonal::math::PM_PRNG_obj::__new();
	HX_STACK_LINE(47)
	this->SIZE = size;
	HX_STACK_LINE(48)
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
	HX_STACK_PUSH("Map::inside","Map.hx",850);
	HX_STACK_THIS(this);
	HX_STACK_ARG(p,"p");
	HX_STACK_LINE(850)
	return this->islandShape(::neash::geom::Point_obj::__new(((int)2 * (((Float(p->x) / Float(this->SIZE->__Field(HX_CSTRING("width"),true))) - 0.5))),((int)2 * (((Float(p->y) / Float(this->SIZE->__Field(HX_CSTRING("height"),true))) - 0.5)))));
}


HX_DEFINE_DYNAMIC_FUNC1(Map_obj,inside,return )

::graph::Edge Map_obj::lookupEdgeFromCorner( ::graph::Corner q,::graph::Corner s){
	HX_STACK_PUSH("Map::lookupEdgeFromCorner","Map.hx",841);
	HX_STACK_THIS(this);
	HX_STACK_ARG(q,"q");
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(842)
	{
		HX_STACK_LINE(842)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::graph::Edge > _g1 = q->protrudes;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(842)
		while(((_g < _g1->length))){
			HX_STACK_LINE(842)
			::graph::Edge edge = _g1->__get(_g);		HX_STACK_VAR(edge,"edge");
			HX_STACK_LINE(842)
			++(_g);
			HX_STACK_LINE(843)
			if (((bool((edge->v0 == s)) || bool((edge->v1 == s))))){
				HX_STACK_LINE(843)
				return edge;
			}
		}
	}
	HX_STACK_LINE(845)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Map_obj,lookupEdgeFromCorner,return )

::graph::Edge Map_obj::lookupEdgeFromCenter( ::graph::Center p,::graph::Center r){
	HX_STACK_PUSH("Map::lookupEdgeFromCenter","Map.hx",834);
	HX_STACK_THIS(this);
	HX_STACK_ARG(p,"p");
	HX_STACK_ARG(r,"r");
	HX_STACK_LINE(835)
	{
		HX_STACK_LINE(835)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::graph::Edge > _g1 = p->borders;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(835)
		while(((_g < _g1->length))){
			HX_STACK_LINE(835)
			::graph::Edge edge = _g1->__get(_g);		HX_STACK_VAR(edge,"edge");
			HX_STACK_LINE(835)
			++(_g);
			HX_STACK_LINE(836)
			if (((bool((edge->d0 == r)) || bool((edge->d1 == r))))){
				HX_STACK_LINE(836)
				return edge;
			}
		}
	}
	HX_STACK_LINE(838)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Map_obj,lookupEdgeFromCenter,return )

Void Map_obj::assignBiomes( ){
{
		HX_STACK_PUSH("Map::assignBiomes","Map.hx",824);
		HX_STACK_THIS(this);
		HX_STACK_LINE(825)
		::graph::Center p;		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(826)
		{
			HX_STACK_LINE(826)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Center > _g1 = this->centers;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(826)
			while(((_g < _g1->length))){
				HX_STACK_LINE(826)
				::graph::Center p1 = _g1->__get(_g);		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(826)
				++(_g);
				HX_STACK_LINE(827)
				p1->biome = ::Map_obj::getBiome(p1);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,assignBiomes,(void))

Void Map_obj::assignPolygonMoisture( ){
{
		HX_STACK_PUSH("Map::assignPolygonMoisture","Map.hx",774);
		HX_STACK_THIS(this);
		HX_STACK_LINE(775)
		::graph::Center p;		HX_STACK_VAR(p,"p");
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		Float sumMoisture;		HX_STACK_VAR(sumMoisture,"sumMoisture");
		HX_STACK_LINE(776)
		{
			HX_STACK_LINE(776)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Center > _g1 = this->centers;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(776)
			while(((_g < _g1->length))){
				HX_STACK_LINE(776)
				::graph::Center p1 = _g1->__get(_g);		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(776)
				++(_g);
				HX_STACK_LINE(777)
				sumMoisture = 0.0;
				HX_STACK_LINE(778)
				{
					HX_STACK_LINE(778)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Corner > _g3 = p1->corners;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(778)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(778)
						::graph::Corner q1 = _g3->__get(_g2);		HX_STACK_VAR(q1,"q1");
						HX_STACK_LINE(778)
						++(_g2);
						HX_STACK_LINE(779)
						if (((q1->moisture > 1.0))){
							HX_STACK_LINE(779)
							q1->moisture = 1.0;
						}
						HX_STACK_LINE(780)
						hx::AddEq(sumMoisture,q1->moisture);
					}
				}
				HX_STACK_LINE(782)
				p1->moisture = (Float(sumMoisture) / Float(p1->corners->length));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,assignPolygonMoisture,(void))

Void Map_obj::assignCornerMoisture( ){
{
		HX_STACK_PUSH("Map::assignCornerMoisture","Map.hx",741);
		HX_STACK_THIS(this);
		HX_STACK_LINE(742)
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		::graph::Corner r;		HX_STACK_VAR(r,"r");
		Float newMoisture;		HX_STACK_VAR(newMoisture,"newMoisture");
		HX_STACK_LINE(743)
		Dynamic queue = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(queue,"queue");
		HX_STACK_LINE(745)
		{
			HX_STACK_LINE(745)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Corner > _g1 = this->corners;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(745)
			while(((_g < _g1->length))){
				HX_STACK_LINE(745)
				::graph::Corner q1 = _g1->__get(_g);		HX_STACK_VAR(q1,"q1");
				HX_STACK_LINE(745)
				++(_g);
				HX_STACK_LINE(746)
				if (((bool(((bool(q1->water) || bool((q1->river > (int)0))))) && bool(!(q1->ocean))))){
					HX_STACK_LINE(747)
					q1->moisture = (  (((q1->river > (int)0))) ? Float(::Math_obj::min(3.0,(0.2 * q1->river))) : Float(1.0) );
					HX_STACK_LINE(748)
					queue->__Field(HX_CSTRING("push"),true)(q1);
				}
				else{
					HX_STACK_LINE(749)
					q1->moisture = 0.0;
				}
			}
		}
		HX_STACK_LINE(753)
		while(((queue->__Field(HX_CSTRING("length"),true) > (int)0))){
			HX_STACK_LINE(754)
			q = queue->__Field(HX_CSTRING("shift"),true)();
			HX_STACK_LINE(756)
			{
				HX_STACK_LINE(756)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::graph::Corner > _g1 = q->adjacent;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(756)
				while(((_g < _g1->length))){
					HX_STACK_LINE(756)
					::graph::Corner r1 = _g1->__get(_g);		HX_STACK_VAR(r1,"r1");
					HX_STACK_LINE(756)
					++(_g);
					HX_STACK_LINE(757)
					newMoisture = (q->moisture * 0.9);
					HX_STACK_LINE(758)
					if (((newMoisture > r1->moisture))){
						HX_STACK_LINE(759)
						r1->moisture = newMoisture;
						HX_STACK_LINE(760)
						queue->__Field(HX_CSTRING("push"),true)(r1);
					}
				}
			}
		}
		HX_STACK_LINE(765)
		{
			HX_STACK_LINE(765)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Corner > _g1 = this->corners;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(765)
			while(((_g < _g1->length))){
				HX_STACK_LINE(765)
				::graph::Corner q1 = _g1->__get(_g);		HX_STACK_VAR(q1,"q1");
				HX_STACK_LINE(765)
				++(_g);
				HX_STACK_LINE(766)
				if (((bool(q1->ocean) || bool(q1->coast)))){
					HX_STACK_LINE(766)
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
		HX_STACK_PUSH("Map::createRivers","Map.hx",712);
		HX_STACK_THIS(this);
		HX_STACK_LINE(714)
		return null();
		HX_STACK_LINE(716)
		int i;		HX_STACK_VAR(i,"i");
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		::graph::Edge edge;		HX_STACK_VAR(edge,"edge");
		HX_STACK_LINE(718)
		{
			HX_STACK_LINE(718)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = ::Math_obj::ceil((Float(this->SIZE->__Field(HX_CSTRING("width"),true)) / Float((int)2)));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(718)
			while(((_g1 < _g))){
				HX_STACK_LINE(718)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(719)
				q = this->corners->__get(this->mapRandom->nextIntRange((int)0,(this->corners->length - (int)1)));
				HX_STACK_LINE(720)
				::haxe::Log_obj::trace(q->ocean,hx::SourceInfo(HX_CSTRING("Map.hx"),720,HX_CSTRING("Map"),HX_CSTRING("createRivers")));
				HX_STACK_LINE(721)
				::haxe::Log_obj::trace(q->elevation,hx::SourceInfo(HX_CSTRING("Map.hx"),721,HX_CSTRING("Map"),HX_CSTRING("createRivers")));
				HX_STACK_LINE(722)
				if (((bool((bool(q->ocean) || bool((q->elevation < 0.3)))) || bool((q->elevation > 0.9))))){
					HX_STACK_LINE(722)
					continue;
				}
				HX_STACK_LINE(724)
				while((!(q->coast))){
					HX_STACK_LINE(725)
					if (((q == q->downslope))){
						HX_STACK_LINE(725)
						break;
					}
					HX_STACK_LINE(728)
					edge = this->lookupEdgeFromCorner(q,q->downslope);
					HX_STACK_LINE(729)
					edge->river = (edge->river + (int)1);
					HX_STACK_LINE(730)
					q->river = (((  ((::NullHelper_obj::IsNull(q->river))) ? int((int)0) : int(q->river) )) + (int)1);
					HX_STACK_LINE(731)
					q->downslope->river = (((  ((::NullHelper_obj::IsNull(q->downslope->river))) ? int((int)0) : int(q->downslope->river) )) + (int)1);
					HX_STACK_LINE(732)
					q = q->downslope;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,createRivers,(void))

Void Map_obj::calculateWatersheds( ){
{
		HX_STACK_PUSH("Map::calculateWatersheds","Map.hx",676);
		HX_STACK_THIS(this);
		HX_STACK_LINE(677)
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		::graph::Corner r;		HX_STACK_VAR(r,"r");
		int i;		HX_STACK_VAR(i,"i");
		bool changed;		HX_STACK_VAR(changed,"changed");
		HX_STACK_LINE(680)
		{
			HX_STACK_LINE(680)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Corner > _g1 = this->corners;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(680)
			while(((_g < _g1->length))){
				HX_STACK_LINE(680)
				::graph::Corner q1 = _g1->__get(_g);		HX_STACK_VAR(q1,"q1");
				HX_STACK_LINE(680)
				++(_g);
				HX_STACK_LINE(681)
				q1->watershed = q1;
				HX_STACK_LINE(682)
				if (((bool(!(q1->ocean)) && bool(!(q1->coast))))){
					HX_STACK_LINE(682)
					q1->watershed = q1->downslope;
				}
			}
		}
		HX_STACK_LINE(691)
		{
			HX_STACK_LINE(691)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(691)
			while(((_g < (int)100))){
				HX_STACK_LINE(691)
				int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(692)
				changed = false;
				HX_STACK_LINE(693)
				{
					HX_STACK_LINE(693)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					Array< ::graph::Corner > _g2 = this->corners;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(693)
					while(((_g1 < _g2->length))){
						HX_STACK_LINE(693)
						::graph::Corner q1 = _g2->__get(_g1);		HX_STACK_VAR(q1,"q1");
						HX_STACK_LINE(693)
						++(_g1);
						HX_STACK_LINE(694)
						if (((bool((bool(!(q1->ocean)) && bool(!(q1->coast)))) && bool(!(q1->watershed->coast))))){
							HX_STACK_LINE(695)
							r = q1->downslope->watershed;
							HX_STACK_LINE(696)
							if ((!(r->ocean))){
								HX_STACK_LINE(696)
								q1->watershed = r;
							}
							HX_STACK_LINE(697)
							changed = true;
						}
					}
				}
				HX_STACK_LINE(700)
				if ((!(changed))){
					HX_STACK_LINE(700)
					break;
				}
			}
		}
		HX_STACK_LINE(703)
		{
			HX_STACK_LINE(703)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Corner > _g1 = this->corners;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(703)
			while(((_g < _g1->length))){
				HX_STACK_LINE(703)
				::graph::Corner q1 = _g1->__get(_g);		HX_STACK_VAR(q1,"q1");
				HX_STACK_LINE(703)
				++(_g);
				HX_STACK_LINE(704)
				r = q1->watershed;
				HX_STACK_LINE(705)
				r->watershed_size = ((int)1 + ((  ((::NullHelper_obj::IsNull(r->watershed_size))) ? int((int)0) : int(r->watershed_size) )));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,calculateWatersheds,(void))

Void Map_obj::calculateDownslopes( ){
{
		HX_STACK_PUSH("Map::calculateDownslopes","Map.hx",656);
		HX_STACK_THIS(this);
		HX_STACK_LINE(657)
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		::graph::Corner s;		HX_STACK_VAR(s,"s");
		::graph::Corner r;		HX_STACK_VAR(r,"r");
		HX_STACK_LINE(659)
		{
			HX_STACK_LINE(659)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Corner > _g1 = this->corners;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(659)
			while(((_g < _g1->length))){
				HX_STACK_LINE(659)
				::graph::Corner q1 = _g1->__get(_g);		HX_STACK_VAR(q1,"q1");
				HX_STACK_LINE(659)
				++(_g);
				HX_STACK_LINE(660)
				r = q1;
				HX_STACK_LINE(661)
				{
					HX_STACK_LINE(661)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Corner > _g3 = q1->adjacent;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(661)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(661)
						::graph::Corner s1 = _g3->__get(_g2);		HX_STACK_VAR(s1,"s1");
						HX_STACK_LINE(661)
						++(_g2);
						HX_STACK_LINE(662)
						if (((s1->elevation <= r->elevation))){
							HX_STACK_LINE(662)
							r = s1;
						}
					}
				}
				HX_STACK_LINE(666)
				q1->downslope = r;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,calculateDownslopes,(void))

Void Map_obj::assignPolygonElevations( ){
{
		HX_STACK_PUSH("Map::assignPolygonElevations","Map.hx",641);
		HX_STACK_THIS(this);
		HX_STACK_LINE(642)
		::graph::Center p;		HX_STACK_VAR(p,"p");
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		Float sumElevation;		HX_STACK_VAR(sumElevation,"sumElevation");
		HX_STACK_LINE(643)
		{
			HX_STACK_LINE(643)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Center > _g1 = this->centers;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(643)
			while(((_g < _g1->length))){
				HX_STACK_LINE(643)
				::graph::Center p1 = _g1->__get(_g);		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(643)
				++(_g);
				HX_STACK_LINE(644)
				sumElevation = 0.0;
				HX_STACK_LINE(645)
				{
					HX_STACK_LINE(645)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Corner > _g3 = p1->corners;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(645)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(645)
						::graph::Corner q1 = _g3->__get(_g2);		HX_STACK_VAR(q1,"q1");
						HX_STACK_LINE(645)
						++(_g2);
						HX_STACK_LINE(646)
						hx::AddEq(sumElevation,q1->elevation);
					}
				}
				HX_STACK_LINE(648)
				p1->elevation = (Float(sumElevation) / Float(p1->corners->length));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,assignPolygonElevations,(void))

Void Map_obj::assignOceanCoastAndLand( ){
{
		HX_STACK_PUSH("Map::assignOceanCoastAndLand","Map.hx",573);
		HX_STACK_THIS(this);
		HX_STACK_LINE(580)
		Dynamic queue = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(queue,"queue");
		HX_STACK_LINE(581)
		::graph::Center p = ::graph::Center_obj::__new();		HX_STACK_VAR(p,"p");
		::graph::Corner q = ::graph::Corner_obj::__new();		HX_STACK_VAR(q,"q");
		::graph::Center r = ::graph::Center_obj::__new();		HX_STACK_VAR(r,"r");
		int numWater = (int)0;		HX_STACK_VAR(numWater,"numWater");
		HX_STACK_LINE(583)
		{
			HX_STACK_LINE(583)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Center > _g1 = this->centers;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(583)
			while(((_g < _g1->length))){
				HX_STACK_LINE(583)
				::graph::Center p1 = _g1->__get(_g);		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(583)
				++(_g);
				HX_STACK_LINE(584)
				numWater = (int)0;
				HX_STACK_LINE(585)
				{
					HX_STACK_LINE(585)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Corner > _g3 = p1->corners;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(585)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(585)
						::graph::Corner q1 = _g3->__get(_g2);		HX_STACK_VAR(q1,"q1");
						HX_STACK_LINE(585)
						++(_g2);
						HX_STACK_LINE(586)
						if ((q1->border)){
							HX_STACK_LINE(587)
							p1->border = true;
							HX_STACK_LINE(588)
							p1->ocean = true;
							HX_STACK_LINE(589)
							q1->water = true;
							HX_STACK_LINE(590)
							queue->__Field(HX_CSTRING("push"),true)(p1);
						}
						HX_STACK_LINE(592)
						if ((q1->water)){
							HX_STACK_LINE(592)
							hx::AddEq(numWater,(int)1);
						}
					}
				}
				HX_STACK_LINE(596)
				p1->water = (bool(p1->ocean) || bool((numWater >= (p1->corners->length * ::Map_obj::LAKE_THRESHOLD))));
			}
		}
		HX_STACK_LINE(598)
		while(((queue->__Field(HX_CSTRING("length"),true) > (int)0))){
			HX_STACK_LINE(599)
			p = queue->__Field(HX_CSTRING("shift"),true)();
			HX_STACK_LINE(600)
			{
				HX_STACK_LINE(600)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::graph::Center > _g1 = p->neighbors;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(600)
				while(((_g < _g1->length))){
					HX_STACK_LINE(600)
					::graph::Center r1 = _g1->__get(_g);		HX_STACK_VAR(r1,"r1");
					HX_STACK_LINE(600)
					++(_g);
					HX_STACK_LINE(601)
					if (((bool(r1->water) && bool(!(r1->ocean))))){
						HX_STACK_LINE(602)
						r1->ocean = true;
						HX_STACK_LINE(603)
						queue->__Field(HX_CSTRING("push"),true)(r1);
					}
				}
			}
		}
		HX_STACK_LINE(611)
		{
			HX_STACK_LINE(611)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Center > _g1 = this->centers;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(611)
			while(((_g < _g1->length))){
				HX_STACK_LINE(611)
				::graph::Center p1 = _g1->__get(_g);		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(611)
				++(_g);
				HX_STACK_LINE(612)
				int numOcean = (int)0;		HX_STACK_VAR(numOcean,"numOcean");
				HX_STACK_LINE(613)
				int numLand = (int)0;		HX_STACK_VAR(numLand,"numLand");
				HX_STACK_LINE(614)
				{
					HX_STACK_LINE(614)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Center > _g3 = p1->neighbors;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(614)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(614)
						::graph::Center r1 = _g3->__get(_g2);		HX_STACK_VAR(r1,"r1");
						HX_STACK_LINE(614)
						++(_g2);
						HX_STACK_LINE(615)
						hx::AddEq(numOcean,(  ((r1->ocean)) ? int((int)1) : int((int)0) ));
						HX_STACK_LINE(616)
						hx::AddEq(numLand,(  ((!(r1->water))) ? int((int)1) : int((int)0) ));
					}
				}
				HX_STACK_LINE(618)
				p1->coast = (bool((numOcean > (int)0)) && bool((numLand > (int)0)));
			}
		}
		HX_STACK_LINE(626)
		{
			HX_STACK_LINE(626)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Corner > _g1 = this->corners;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(626)
			while(((_g < _g1->length))){
				HX_STACK_LINE(626)
				::graph::Corner q1 = _g1->__get(_g);		HX_STACK_VAR(q1,"q1");
				HX_STACK_LINE(626)
				++(_g);
				HX_STACK_LINE(627)
				int numOcean = (int)0;		HX_STACK_VAR(numOcean,"numOcean");
				HX_STACK_LINE(628)
				int numLand = (int)0;		HX_STACK_VAR(numLand,"numLand");
				HX_STACK_LINE(629)
				{
					HX_STACK_LINE(629)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					Array< ::graph::Center > _g3 = q1->touches;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(629)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(629)
						::graph::Center p1 = _g3->__get(_g2);		HX_STACK_VAR(p1,"p1");
						HX_STACK_LINE(629)
						++(_g2);
						HX_STACK_LINE(630)
						hx::AddEq(numOcean,(  ((r->ocean)) ? int((int)1) : int((int)0) ));
						HX_STACK_LINE(631)
						hx::AddEq(numLand,(  ((!(r->water))) ? int((int)1) : int((int)0) ));
					}
				}
				HX_STACK_LINE(633)
				q1->ocean = (numOcean == q1->touches->length);
				HX_STACK_LINE(634)
				q1->coast = (bool((numOcean > (int)0)) && bool((numLand > (int)0)));
				HX_STACK_LINE(635)
				q1->water = (bool(q1->border) || bool((bool((numLand != q1->touches->length)) && bool(!(q1->coast)))));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,assignOceanCoastAndLand,(void))

Void Map_obj::redistributeMoisture( Dynamic locations){
{
		HX_STACK_PUSH("Map::redistributeMoisture","Map.hx",557);
		HX_STACK_THIS(this);
		HX_STACK_ARG(locations,"locations");
		HX_STACK_LINE(558)
		int i;		HX_STACK_VAR(i,"i");

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		int run(Dynamic c1,Dynamic c2){
			HX_STACK_PUSH("*::_Function_1_1","Map.hx",559);
			HX_STACK_ARG(c1,"c1");
			HX_STACK_ARG(c2,"c2");
			{
				HX_STACK_LINE(560)
				if (((c1->__Field(HX_CSTRING("moisture"),true) > c2->__Field(HX_CSTRING("moisture"),true)))){
					HX_STACK_LINE(560)
					return (int)1;
				}
				HX_STACK_LINE(561)
				if (((c1->__Field(HX_CSTRING("moisture"),true) < c2->__Field(HX_CSTRING("moisture"),true)))){
					HX_STACK_LINE(561)
					return (int)-1;
				}
				HX_STACK_LINE(562)
				if (((c1->__Field(HX_CSTRING("index"),true) > c2->__Field(HX_CSTRING("index"),true)))){
					HX_STACK_LINE(562)
					return (int)1;
				}
				HX_STACK_LINE(563)
				if (((c1->__Field(HX_CSTRING("index"),true) < c2->__Field(HX_CSTRING("index"),true)))){
					HX_STACK_LINE(563)
					return (int)-1;
				}
				HX_STACK_LINE(564)
				return (int)0;
			}
			return null();
		}
		HX_END_LOCAL_FUNC2(return)

		HX_STACK_LINE(559)
		locations->__Field(HX_CSTRING("sort"),true)( Dynamic(new _Function_1_1()));
		HX_STACK_LINE(566)
		{
			HX_STACK_LINE(566)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = locations->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(566)
			while(((_g1 < _g))){
				HX_STACK_LINE(566)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(567)
				locations->__GetItem(i1)->__FieldRef(HX_CSTRING("moisture")) = (Float(i1) / Float(((locations->__Field(HX_CSTRING("length"),true) - (int)1))));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Map_obj,redistributeMoisture,(void))

Void Map_obj::redistributeElevations( Dynamic locations){
{
		HX_STACK_PUSH("Map::redistributeElevations","Map.hx",524);
		HX_STACK_THIS(this);
		HX_STACK_ARG(locations,"locations");
		HX_STACK_LINE(527)
		Float SCALE_FACTOR = 1.1;		HX_STACK_VAR(SCALE_FACTOR,"SCALE_FACTOR");
		HX_STACK_LINE(528)
		int i;		HX_STACK_VAR(i,"i");
		Float y;		HX_STACK_VAR(y,"y");
		Float x;		HX_STACK_VAR(x,"x");

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		int run(Dynamic c1,Dynamic c2){
			HX_STACK_PUSH("*::_Function_1_1","Map.hx",531);
			HX_STACK_ARG(c1,"c1");
			HX_STACK_ARG(c2,"c2");
			{
				HX_STACK_LINE(532)
				if (((c1->__Field(HX_CSTRING("elevation"),true) > c2->__Field(HX_CSTRING("elevation"),true)))){
					HX_STACK_LINE(532)
					return (int)1;
				}
				HX_STACK_LINE(533)
				if (((c1->__Field(HX_CSTRING("elevation"),true) < c2->__Field(HX_CSTRING("elevation"),true)))){
					HX_STACK_LINE(533)
					return (int)-1;
				}
				HX_STACK_LINE(534)
				if (((c1->__Field(HX_CSTRING("index"),true) > c2->__Field(HX_CSTRING("index"),true)))){
					HX_STACK_LINE(534)
					return (int)1;
				}
				HX_STACK_LINE(535)
				if (((c1->__Field(HX_CSTRING("index"),true) < c2->__Field(HX_CSTRING("index"),true)))){
					HX_STACK_LINE(535)
					return (int)-1;
				}
				HX_STACK_LINE(536)
				return (int)0;
			}
			return null();
		}
		HX_END_LOCAL_FUNC2(return)

		HX_STACK_LINE(531)
		locations->__Field(HX_CSTRING("sort"),true)( Dynamic(new _Function_1_1()));
		HX_STACK_LINE(538)
		{
			HX_STACK_LINE(538)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = locations->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(538)
			while(((_g1 < _g))){
				HX_STACK_LINE(538)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(542)
				y = (Float(i1) / Float(((locations->__Field(HX_CSTRING("length"),true) - (int)1))));
				HX_STACK_LINE(549)
				x = (::Math_obj::sqrt(SCALE_FACTOR) - ::Math_obj::sqrt((SCALE_FACTOR * (((int)1 - y)))));
				HX_STACK_LINE(550)
				if (((x > 1.0))){
					HX_STACK_LINE(550)
					x = 1.0;
				}
				HX_STACK_LINE(551)
				locations->__GetItem(i1)->__FieldRef(HX_CSTRING("elevation")) = x;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Map_obj,redistributeElevations,(void))

Void Map_obj::assignCornerElevations( ){
{
		HX_STACK_PUSH("Map::assignCornerElevations","Map.hx",476);
		HX_STACK_THIS(this);
		HX_STACK_LINE(477)
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		::graph::Corner s;		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(478)
		Dynamic queue = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(queue,"queue");
		HX_STACK_LINE(480)
		{
			HX_STACK_LINE(480)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Corner > _g1 = this->corners;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(480)
			while(((_g < _g1->length))){
				HX_STACK_LINE(480)
				::graph::Corner q1 = _g1->__get(_g);		HX_STACK_VAR(q1,"q1");
				HX_STACK_LINE(480)
				++(_g);
				HX_STACK_LINE(481)
				q1->water = !(this->inside(q1->point));
			}
		}
		HX_STACK_LINE(484)
		{
			HX_STACK_LINE(484)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Corner > _g1 = this->corners;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(484)
			while(((_g < _g1->length))){
				HX_STACK_LINE(484)
				::graph::Corner q1 = _g1->__get(_g);		HX_STACK_VAR(q1,"q1");
				HX_STACK_LINE(484)
				++(_g);
				HX_STACK_LINE(486)
				if ((q1->border)){
					HX_STACK_LINE(487)
					q1->elevation = 0.0;
					HX_STACK_LINE(488)
					queue->__Field(HX_CSTRING("push"),true)(q1);
				}
				else{
					HX_STACK_LINE(489)
					q1->elevation = ::Math_obj::POSITIVE_INFINITY;
				}
			}
		}
		HX_STACK_LINE(497)
		while(((queue->__Field(HX_CSTRING("length"),true) > (int)0))){
			HX_STACK_LINE(498)
			q = queue->__Field(HX_CSTRING("shift"),true)();
			HX_STACK_LINE(500)
			{
				HX_STACK_LINE(500)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::graph::Corner > _g1 = q->adjacent;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(500)
				while(((_g < _g1->length))){
					HX_STACK_LINE(500)
					::graph::Corner s1 = _g1->__get(_g);		HX_STACK_VAR(s1,"s1");
					HX_STACK_LINE(500)
					++(_g);
					HX_STACK_LINE(504)
					Float newElevation = (0.01 + q->elevation);		HX_STACK_VAR(newElevation,"newElevation");
					HX_STACK_LINE(505)
					if (((bool(!(q->water)) && bool(!(s1->water))))){
						HX_STACK_LINE(505)
						hx::AddEq(newElevation,(int)1);
					}
					HX_STACK_LINE(510)
					if (((newElevation < s1->elevation))){
						HX_STACK_LINE(511)
						s1->elevation = newElevation;
						HX_STACK_LINE(512)
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
		HX_STACK_PUSH("Map::buildGraph","Map.hx",341);
		HX_STACK_THIS(this);
		HX_STACK_ARG(points,"points");
		HX_STACK_ARG(voronoi,"voronoi");
		HX_STACK_LINE(341)
		Array< ::Map > _g = Array_obj< ::Map >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(342)
		::graph::Center p;		HX_STACK_VAR(p,"p");
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		::neash::geom::Point point;		HX_STACK_VAR(point,"point");
		::neash::geom::Point other;		HX_STACK_VAR(other,"other");
		HX_STACK_LINE(343)
		Array< ::com::nodename::delaunay::Edge > libedges = voronoi->edges();		HX_STACK_VAR(libedges,"libedges");
		HX_STACK_LINE(344)
		::nme::ObjectHash centerLookup = ::nme::ObjectHash_obj::__new();		HX_STACK_VAR(centerLookup,"centerLookup");
		HX_STACK_LINE(348)
		{
			HX_STACK_LINE(348)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(348)
			while(((_g1 < points->length))){
				HX_STACK_LINE(348)
				::neash::geom::Point point1 = points->__get(_g1);		HX_STACK_VAR(point1,"point1");
				HX_STACK_LINE(348)
				++(_g1);
				HX_STACK_LINE(349)
				p = ::graph::Center_obj::__new();
				HX_STACK_LINE(350)
				p->index = this->centers->length;
				HX_STACK_LINE(351)
				p->point = point1;
				HX_STACK_LINE(352)
				p->neighbors = Array_obj< ::graph::Center >::__new();
				HX_STACK_LINE(353)
				p->borders = Array_obj< ::graph::Edge >::__new();
				HX_STACK_LINE(354)
				p->corners = Array_obj< ::graph::Corner >::__new();
				HX_STACK_LINE(355)
				this->centers->push(p);
				HX_STACK_LINE(356)
				{
					HX_STACK_LINE(356)
					int id = ::__hxcpp_obj_id(point1);		HX_STACK_VAR(id,"id");
					HX_STACK_LINE(356)
					centerLookup->hashKeys->set(id,point1);
					HX_STACK_LINE(356)
					centerLookup->hashValues->set(id,p);
				}
			}
		}
		HX_STACK_LINE(361)
		{
			HX_STACK_LINE(361)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			Array< ::graph::Center > _g11 = this->centers;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(361)
			while(((_g1 < _g11->length))){
				HX_STACK_LINE(361)
				::graph::Center p1 = _g11->__get(_g1);		HX_STACK_VAR(p1,"p1");
				HX_STACK_LINE(361)
				++(_g1);
				HX_STACK_LINE(362)
				voronoi->region(p1->point);
			}
		}
		HX_STACK_LINE(371)
		Array< Array< Array< ::graph::Corner > > > _cornerMap = Array_obj< Array< Array< ::graph::Corner > > >::__new().Add(Array_obj< Array< ::graph::Corner > >::__new());		HX_STACK_VAR(_cornerMap,"_cornerMap");

		HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Array< Array< Array< ::graph::Corner > > >,_cornerMap,Array< ::Map >,_g)
		::graph::Corner run(::neash::geom::Point point1){
			HX_STACK_PUSH("*::_Function_1_1","Map.hx",372);
			HX_STACK_ARG(point1,"point1");
			{
				HX_STACK_LINE(373)
				::graph::Corner q1;		HX_STACK_VAR(q1,"q1");
				HX_STACK_LINE(375)
				if (((point1 == null()))){
					HX_STACK_LINE(375)
					return null();
				}
				HX_STACK_LINE(376)
				int bucket;		HX_STACK_VAR(bucket,"bucket");
				HX_STACK_LINE(377)
				{
					HX_STACK_LINE(377)
					int _g1 = (::Std_obj::_int(point1->x) - (int)1);		HX_STACK_VAR(_g1,"_g1");
					int _g2 = (::Std_obj::_int(point1->x) + (int)2);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(377)
					while(((_g1 < _g2))){
						HX_STACK_LINE(377)
						int bucket1 = (_g1)++;		HX_STACK_VAR(bucket1,"bucket1");
						HX_STACK_LINE(378)
						if (((_cornerMap->__get((int)0)->__get(bucket1) != null()))){
							HX_STACK_LINE(379)
							int _g21 = (int)0;		HX_STACK_VAR(_g21,"_g21");
							Array< ::graph::Corner > _g3 = _cornerMap->__get((int)0)->__get(bucket1);		HX_STACK_VAR(_g3,"_g3");
							HX_STACK_LINE(379)
							while(((_g21 < _g3->length))){
								HX_STACK_LINE(379)
								::graph::Corner q2 = _g3->__get(_g21);		HX_STACK_VAR(q2,"q2");
								HX_STACK_LINE(379)
								++(_g21);
								HX_STACK_LINE(380)
								Float dx = (point1->x - q2->point->x);		HX_STACK_VAR(dx,"dx");
								HX_STACK_LINE(381)
								Float dy = (point1->y - q2->point->y);		HX_STACK_VAR(dy,"dy");
								HX_STACK_LINE(382)
								if (((((dx * dx) + (dy * dy)) < 1e-6))){
									HX_STACK_LINE(382)
									return q2;
								}
							}
						}
					}
				}
				HX_STACK_LINE(388)
				bucket = ::Std_obj::_int(point1->x);
				HX_STACK_LINE(389)
				if (((_cornerMap->__get((int)0)->__get(bucket) == null()))){
					HX_STACK_LINE(389)
					_cornerMap->__get((int)0)[bucket] = Array_obj< ::graph::Corner >::__new();
				}
				HX_STACK_LINE(390)
				q1 = ::graph::Corner_obj::__new();
				HX_STACK_LINE(391)
				q1->index = _g->__get((int)0)->corners->length;
				HX_STACK_LINE(392)
				_g->__get((int)0)->corners->push(q1);
				HX_STACK_LINE(393)
				q1->point = point1;
				HX_STACK_LINE(394)
				q1->border = (bool((bool((bool((point1->x == (int)0)) || bool((point1->x == _g->__get((int)0)->SIZE->__Field(HX_CSTRING("width"),true))))) || bool((point1->y == (int)0)))) || bool((point1->y == _g->__get((int)0)->SIZE->__Field(HX_CSTRING("height"),true))));
				HX_STACK_LINE(396)
				q1->touches = Array_obj< ::graph::Center >::__new();
				HX_STACK_LINE(397)
				q1->protrudes = Array_obj< ::graph::Edge >::__new();
				HX_STACK_LINE(398)
				q1->adjacent = Array_obj< ::graph::Corner >::__new();
				HX_STACK_LINE(399)
				_cornerMap->__get((int)0)->__get(bucket)->push(q1);
				HX_STACK_LINE(400)
				return q1;
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(372)
		Dynamic makeCorner =  Dynamic(new _Function_1_1(_cornerMap,_g));		HX_STACK_VAR(makeCorner,"makeCorner");
		HX_STACK_LINE(402)
		{
			HX_STACK_LINE(402)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(402)
			while(((_g1 < libedges->length))){
				HX_STACK_LINE(402)
				::com::nodename::delaunay::Edge libedge = libedges->__get(_g1);		HX_STACK_VAR(libedge,"libedge");
				HX_STACK_LINE(402)
				++(_g1);
				HX_STACK_LINE(403)
				::com::nodename::geom::LineSegment dedge = libedge->delaunayLine();		HX_STACK_VAR(dedge,"dedge");
				HX_STACK_LINE(404)
				::com::nodename::geom::LineSegment vedge = libedge->voronoiEdge();		HX_STACK_VAR(vedge,"vedge");
				HX_STACK_LINE(408)
				::graph::Edge edge = ::graph::Edge_obj::__new();		HX_STACK_VAR(edge,"edge");
				HX_STACK_LINE(409)
				edge->index = this->edges->length;
				HX_STACK_LINE(410)
				edge->river = (int)0;
				HX_STACK_LINE(411)
				this->edges->push(edge);
				HX_STACK_LINE(412)
				edge->midpoint = (  (((bool((vedge->p0 != null())) && bool((vedge->p1 != null()))))) ? ::neash::geom::Point(::neash::geom::Point_obj::interpolate(vedge->p0,vedge->p1,0.5)) : ::neash::geom::Point(null()) );
				HX_STACK_LINE(415)
				edge->v0 = makeCorner(vedge->p0).Cast< ::graph::Corner >();
				HX_STACK_LINE(416)
				edge->v1 = makeCorner(vedge->p1).Cast< ::graph::Corner >();
				HX_STACK_LINE(417)
				edge->d0 = centerLookup->hashValues->get(::__hxcpp_obj_id(dedge->p0));
				HX_STACK_LINE(418)
				edge->d1 = centerLookup->hashValues->get(::__hxcpp_obj_id(dedge->p1));
				HX_STACK_LINE(421)
				if (((edge->d0 != null()))){
					HX_STACK_LINE(421)
					edge->d0->borders->push(edge);
				}
				HX_STACK_LINE(422)
				if (((edge->d1 != null()))){
					HX_STACK_LINE(422)
					edge->d1->borders->push(edge);
				}
				HX_STACK_LINE(423)
				if (((edge->v0 != null()))){
					HX_STACK_LINE(423)
					edge->v0->protrudes->push(edge);
				}
				HX_STACK_LINE(424)
				if (((edge->v1 != null()))){
					HX_STACK_LINE(424)
					edge->v1->protrudes->push(edge);
				}

				HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_3_1)
				Void run(Array< ::graph::Corner > v,::graph::Corner x){
					HX_STACK_PUSH("*::_Function_3_1","Map.hx",426);
					HX_STACK_ARG(v,"v");
					HX_STACK_ARG(x,"x");
					{
						HX_STACK_LINE(426)
						if (((bool((x != null())) && bool((::Lambda_obj::indexOf(v,x) < (int)0))))){
							HX_STACK_LINE(427)
							v->push(x);
						}
					}
					return null();
				}
				HX_END_LOCAL_FUNC2((void))

				HX_STACK_LINE(426)
				Dynamic addToCornerList =  Dynamic(new _Function_3_1());		HX_STACK_VAR(addToCornerList,"addToCornerList");

				HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_3_2)
				Void run(Array< ::graph::Center > v,::graph::Center x){
					HX_STACK_PUSH("*::_Function_3_2","Map.hx",429);
					HX_STACK_ARG(v,"v");
					HX_STACK_ARG(x,"x");
					{
						HX_STACK_LINE(429)
						if (((bool((x != null())) && bool((::Lambda_obj::indexOf(v,x) < (int)0))))){
							HX_STACK_LINE(430)
							v->push(x);
						}
					}
					return null();
				}
				HX_END_LOCAL_FUNC2((void))

				HX_STACK_LINE(429)
				Dynamic addToCenterList =  Dynamic(new _Function_3_2());		HX_STACK_VAR(addToCenterList,"addToCenterList");
				HX_STACK_LINE(434)
				if (((bool((edge->d0 != null())) && bool((edge->d1 != null()))))){
					HX_STACK_LINE(435)
					addToCenterList(edge->d0->neighbors,edge->d1).Cast< Void >();
					HX_STACK_LINE(436)
					addToCenterList(edge->d1->neighbors,edge->d0).Cast< Void >();
				}
				HX_STACK_LINE(440)
				if (((bool((edge->v0 != null())) && bool((edge->v1 != null()))))){
					HX_STACK_LINE(441)
					addToCornerList(edge->v0->adjacent,edge->v1).Cast< Void >();
					HX_STACK_LINE(442)
					addToCornerList(edge->v1->adjacent,edge->v0).Cast< Void >();
				}
				HX_STACK_LINE(446)
				if (((edge->d0 != null()))){
					HX_STACK_LINE(447)
					addToCornerList(edge->d0->corners,edge->v0).Cast< Void >();
					HX_STACK_LINE(448)
					addToCornerList(edge->d0->corners,edge->v1).Cast< Void >();
				}
				HX_STACK_LINE(450)
				if (((edge->d1 != null()))){
					HX_STACK_LINE(451)
					addToCornerList(edge->d1->corners,edge->v0).Cast< Void >();
					HX_STACK_LINE(452)
					addToCornerList(edge->d1->corners,edge->v1).Cast< Void >();
				}
				HX_STACK_LINE(456)
				if (((edge->v0 != null()))){
					HX_STACK_LINE(457)
					addToCenterList(edge->v0->touches,edge->d0).Cast< Void >();
					HX_STACK_LINE(458)
					addToCenterList(edge->v0->touches,edge->d1).Cast< Void >();
				}
				HX_STACK_LINE(460)
				if (((edge->v1 != null()))){
					HX_STACK_LINE(461)
					addToCenterList(edge->v1->touches,edge->d0).Cast< Void >();
					HX_STACK_LINE(462)
					addToCenterList(edge->v1->touches,edge->d1).Cast< Void >();
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Map_obj,buildGraph,(void))

Dynamic Map_obj::landCorners( Array< ::graph::Corner > corners){
	HX_STACK_PUSH("Map::landCorners","Map.hx",322);
	HX_STACK_THIS(this);
	HX_STACK_ARG(corners,"corners");
	HX_STACK_LINE(323)
	::graph::Corner q;		HX_STACK_VAR(q,"q");
	Dynamic locations = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(locations,"locations");
	HX_STACK_LINE(324)
	{
		HX_STACK_LINE(324)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(324)
		while(((_g < corners->length))){
			HX_STACK_LINE(324)
			::graph::Corner q1 = corners->__get(_g);		HX_STACK_VAR(q1,"q1");
			HX_STACK_LINE(324)
			++(_g);
			HX_STACK_LINE(325)
			if (((bool(!(q1->ocean)) && bool(!(q1->coast))))){
				HX_STACK_LINE(325)
				locations->__Field(HX_CSTRING("push"),true)(q1);
			}
		}
	}
	HX_STACK_LINE(329)
	return locations;
}


HX_DEFINE_DYNAMIC_FUNC1(Map_obj,landCorners,return )

Void Map_obj::improveCorners( ){
{
		HX_STACK_PUSH("Map::improveCorners","Map.hx",282);
		HX_STACK_THIS(this);
		HX_STACK_LINE(284)
		Array< ::neash::geom::Point > newCorners = Array_obj< ::neash::geom::Point >::__new();		HX_STACK_VAR(newCorners,"newCorners");
		HX_STACK_LINE(285)
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		::graph::Center r;		HX_STACK_VAR(r,"r");
		::neash::geom::Point point;		HX_STACK_VAR(point,"point");
		int i;		HX_STACK_VAR(i,"i");
		::graph::Edge edge;		HX_STACK_VAR(edge,"edge");
		HX_STACK_LINE(288)
		{
			HX_STACK_LINE(288)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Corner > _g1 = this->corners;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(288)
			while(((_g < _g1->length))){
				HX_STACK_LINE(288)
				::graph::Corner q1 = _g1->__get(_g);		HX_STACK_VAR(q1,"q1");
				HX_STACK_LINE(288)
				++(_g);
				HX_STACK_LINE(289)
				if ((q1->border)){
					HX_STACK_LINE(289)
					newCorners[q1->index] = q1->point;
				}
				else{
					HX_STACK_LINE(292)
					point = ::neash::geom::Point_obj::__new(0.0,0.0);
					HX_STACK_LINE(293)
					{
						HX_STACK_LINE(293)
						int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
						Array< ::graph::Center > _g3 = q1->touches;		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(293)
						while(((_g2 < _g3->length))){
							HX_STACK_LINE(293)
							::graph::Center r1 = _g3->__get(_g2);		HX_STACK_VAR(r1,"r1");
							HX_STACK_LINE(293)
							++(_g2);
							HX_STACK_LINE(294)
							hx::AddEq(point->x,r1->point->x);
							HX_STACK_LINE(295)
							hx::AddEq(point->y,r1->point->y);
						}
					}
					HX_STACK_LINE(297)
					hx::DivEq(point->x,q1->touches->length);
					HX_STACK_LINE(298)
					hx::DivEq(point->y,q1->touches->length);
					HX_STACK_LINE(299)
					newCorners[q1->index] = point;
				}
			}
		}
		HX_STACK_LINE(304)
		{
			HX_STACK_LINE(304)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->corners->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(304)
			while(((_g1 < _g))){
				HX_STACK_LINE(304)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(305)
				this->corners->__get(i1)->point = newCorners->__get(i1);
			}
		}
		HX_STACK_LINE(310)
		{
			HX_STACK_LINE(310)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::graph::Edge > _g1 = this->edges;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(310)
			while(((_g < _g1->length))){
				HX_STACK_LINE(310)
				::graph::Edge edge1 = _g1->__get(_g);		HX_STACK_VAR(edge1,"edge1");
				HX_STACK_LINE(310)
				++(_g);
				HX_STACK_LINE(311)
				if (((bool((edge1->v0 != null())) && bool((edge1->v1 != null()))))){
					HX_STACK_LINE(311)
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
		HX_STACK_PUSH("Map::improveRandomPoints","Map.hx",242);
		HX_STACK_THIS(this);
		HX_STACK_ARG(points,"points");
		HX_STACK_LINE(254)
		int i;		HX_STACK_VAR(i,"i");
		::neash::geom::Point p;		HX_STACK_VAR(p,"p");
		::neash::geom::Point q;		HX_STACK_VAR(q,"q");
		::com::nodename::delaunay::Voronoi voronoi;		HX_STACK_VAR(voronoi,"voronoi");
		Array< ::neash::geom::Point > region;		HX_STACK_VAR(region,"region");
		HX_STACK_LINE(255)
		{
			HX_STACK_LINE(255)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = ::Map_obj::NUM_LLOYD_ITERATIONS;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(255)
			while(((_g1 < _g))){
				HX_STACK_LINE(255)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(256)
				voronoi = ::com::nodename::delaunay::Voronoi_obj::__new(points,null(),::neash::geom::Rectangle_obj::__new((int)0,(int)0,this->SIZE->__Field(HX_CSTRING("width"),true),this->SIZE->__Field(HX_CSTRING("height"),true)));
				HX_STACK_LINE(257)
				{
					HX_STACK_LINE(257)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(257)
					while(((_g2 < points->length))){
						HX_STACK_LINE(257)
						::neash::geom::Point p1 = points->__get(_g2);		HX_STACK_VAR(p1,"p1");
						HX_STACK_LINE(257)
						++(_g2);
						HX_STACK_LINE(258)
						region = voronoi->region(p1);
						HX_STACK_LINE(259)
						p1->x = 0.0;
						HX_STACK_LINE(260)
						p1->y = 0.0;
						HX_STACK_LINE(261)
						{
							HX_STACK_LINE(261)
							int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
							HX_STACK_LINE(261)
							while(((_g3 < region->length))){
								HX_STACK_LINE(261)
								::neash::geom::Point q1 = region->__get(_g3);		HX_STACK_VAR(q1,"q1");
								HX_STACK_LINE(261)
								++(_g3);
								HX_STACK_LINE(262)
								hx::AddEq(p1->x,q1->x);
								HX_STACK_LINE(263)
								hx::AddEq(p1->y,q1->y);
							}
						}
						HX_STACK_LINE(265)
						hx::DivEq(p1->x,region->length);
						HX_STACK_LINE(266)
						hx::DivEq(p1->y,region->length);
						HX_STACK_LINE(267)
						region->splice((int)0,region->length);
					}
				}
				HX_STACK_LINE(269)
				voronoi->dispose();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Map_obj,improveRandomPoints,(void))

Array< ::neash::geom::Point > Map_obj::generateRandomPoints( ){
	HX_STACK_PUSH("Map::generateRandomPoints","Map.hx",230);
	HX_STACK_THIS(this);
	HX_STACK_LINE(231)
	::neash::geom::Point p;		HX_STACK_VAR(p,"p");
	int i;		HX_STACK_VAR(i,"i");
	Array< ::neash::geom::Point > points = Array_obj< ::neash::geom::Point >::__new();		HX_STACK_VAR(points,"points");
	HX_STACK_LINE(232)
	{
		HX_STACK_LINE(232)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = ::Map_obj::NUM_POINTS;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(232)
		while(((_g1 < _g))){
			HX_STACK_LINE(232)
			int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
			HX_STACK_LINE(233)
			p = ::neash::geom::Point_obj::__new(this->mapRandom->nextDoubleRange((int)10,(this->SIZE->__Field(HX_CSTRING("width"),true) - (int)10)),this->mapRandom->nextDoubleRange((int)10,(this->SIZE->__Field(HX_CSTRING("height"),true) - (int)10)));
			HX_STACK_LINE(235)
			points->push(p);
		}
	}
	HX_STACK_LINE(237)
	return points;
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,generateRandomPoints,return )

Void Map_obj::go( int first,int last){
{
		HX_STACK_PUSH("Map::go","Map.hx",112);
		HX_STACK_THIS(this);
		HX_STACK_ARG(first,"first");
		HX_STACK_ARG(last,"last");
		HX_STACK_LINE(112)
		Array< ::Map > _g = Array_obj< ::Map >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(113)
		Dynamic stages = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(stages,"stages");

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		Void run(::String name,Dynamic fn){
			HX_STACK_PUSH("*::_Function_1_1","Map.hx",115);
			HX_STACK_ARG(name,"name");
			HX_STACK_ARG(fn,"fn");
			{
				HX_STACK_LINE(115)
				fn().Cast< Void >();
			}
			return null();
		}
		HX_END_LOCAL_FUNC2((void))

		HX_STACK_LINE(115)
		Dynamic timeIt =  Dynamic(new _Function_1_1());		HX_STACK_VAR(timeIt,"timeIt");

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_2,Array< ::Map >,_g)
		Void run(){
			HX_STACK_PUSH("*::_Function_1_2","Map.hx",123);
			{
				HX_STACK_LINE(124)
				_g->__get((int)0)->reset();
				HX_STACK_LINE(125)
				::haxe::Log_obj::trace(HX_CSTRING("generating random points"),hx::SourceInfo(HX_CSTRING("Map.hx"),125,HX_CSTRING("Map"),HX_CSTRING("go")));
				HX_STACK_LINE(126)
				_g->__get((int)0)->points = _g->__get((int)0)->generateRandomPoints();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(121)
		stages->__Field(HX_CSTRING("push"),true)(Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("Place points...")).Add( Dynamic(new _Function_1_2(_g)))));

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_3)
		Void run(){
			HX_STACK_PUSH("*::_Function_1_3","Map.hx",131);
			{
				HX_STACK_LINE(131)
				::haxe::Log_obj::trace(HX_CSTRING("improving points"),hx::SourceInfo(HX_CSTRING("Map.hx"),132,HX_CSTRING("Map"),HX_CSTRING("go")));
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(129)
		stages->__Field(HX_CSTRING("push"),true)(Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("Improve points...")).Add( Dynamic(new _Function_1_3()))));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_4,Array< ::Map >,_g)
		Void run(){
			HX_STACK_PUSH("*::_Function_1_4","Map.hx",146);
			{
				HX_STACK_LINE(147)
				::haxe::Log_obj::trace(HX_CSTRING("building graph"),hx::SourceInfo(HX_CSTRING("Map.hx"),147,HX_CSTRING("Map"),HX_CSTRING("go")));
				HX_STACK_LINE(148)
				::com::nodename::delaunay::Voronoi voronoi = ::com::nodename::delaunay::Voronoi_obj::__new(_g->__get((int)0)->points,null(),::neash::geom::Rectangle_obj::__new((int)0,(int)0,_g->__get((int)0)->SIZE->__Field(HX_CSTRING("width"),true),_g->__get((int)0)->SIZE->__Field(HX_CSTRING("height"),true)));		HX_STACK_VAR(voronoi,"voronoi");
				HX_STACK_LINE(149)
				_g->__get((int)0)->buildGraph(_g->__get((int)0)->points,voronoi);
				HX_STACK_LINE(150)
				_g->__get((int)0)->improveCorners();
				HX_STACK_LINE(151)
				voronoi->dispose();
				HX_STACK_LINE(152)
				voronoi = null();
				HX_STACK_LINE(153)
				_g->__get((int)0)->points = null();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(144)
		stages->__Field(HX_CSTRING("push"),true)(Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("Build graph...")).Add( Dynamic(new _Function_1_4(_g)))));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_5,Array< ::Map >,_g)
		Void run(){
			HX_STACK_PUSH("*::_Function_1_5","Map.hx",158);
			{
				HX_STACK_LINE(159)
				::haxe::Log_obj::trace(HX_CSTRING("assigning elevations"),hx::SourceInfo(HX_CSTRING("Map.hx"),159,HX_CSTRING("Map"),HX_CSTRING("go")));
				HX_STACK_LINE(161)
				_g->__get((int)0)->assignCornerElevations();
				HX_STACK_LINE(164)
				_g->__get((int)0)->assignOceanCoastAndLand();
				HX_STACK_LINE(173)
				_g->__get((int)0)->redistributeElevations(_g->__get((int)0)->landCorners(_g->__get((int)0)->corners));
				HX_STACK_LINE(176)
				{
					HX_STACK_LINE(176)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					Array< ::graph::Corner > _g2 = _g->__get((int)0)->corners;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(176)
					while(((_g1 < _g2->length))){
						HX_STACK_LINE(176)
						::graph::Corner q = _g2->__get(_g1);		HX_STACK_VAR(q,"q");
						HX_STACK_LINE(176)
						++(_g1);
						HX_STACK_LINE(178)
						if (((bool(q->ocean) || bool(q->coast)))){
							HX_STACK_LINE(179)
							q->elevation = 0.0;
						}
					}
				}
				HX_STACK_LINE(185)
				_g->__get((int)0)->assignPolygonElevations();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(156)
		stages->__Field(HX_CSTRING("push"),true)(Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("Assign elevations...")).Add( Dynamic(new _Function_1_5(_g)))));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_6,Array< ::Map >,_g)
		Void run(){
			HX_STACK_PUSH("*::_Function_1_6","Map.hx",191);
			{
				HX_STACK_LINE(192)
				::haxe::Log_obj::trace(HX_CSTRING("assigning moisture"),hx::SourceInfo(HX_CSTRING("Map.hx"),192,HX_CSTRING("Map"),HX_CSTRING("go")));
				HX_STACK_LINE(194)
				_g->__get((int)0)->calculateDownslopes();
				HX_STACK_LINE(198)
				_g->__get((int)0)->calculateWatersheds();
				HX_STACK_LINE(201)
				_g->__get((int)0)->createRivers();
				HX_STACK_LINE(208)
				_g->__get((int)0)->assignCornerMoisture();
				HX_STACK_LINE(209)
				_g->__get((int)0)->redistributeMoisture(_g->__get((int)0)->landCorners(_g->__get((int)0)->corners));
				HX_STACK_LINE(210)
				_g->__get((int)0)->assignPolygonMoisture();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(189)
		stages->__Field(HX_CSTRING("push"),true)(Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("Assign moisture...")).Add( Dynamic(new _Function_1_6(_g)))));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_7,Array< ::Map >,_g)
		Void run(){
			HX_STACK_PUSH("*::_Function_1_7","Map.hx",215);
			{
				HX_STACK_LINE(216)
				::haxe::Log_obj::trace(HX_CSTRING("decorating map"),hx::SourceInfo(HX_CSTRING("Map.hx"),216,HX_CSTRING("Map"),HX_CSTRING("go")));
				HX_STACK_LINE(217)
				_g->__get((int)0)->assignBiomes();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(213)
		stages->__Field(HX_CSTRING("push"),true)(Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("Decorate map...")).Add( Dynamic(new _Function_1_7(_g)))));
		HX_STACK_LINE(220)
		{
			HX_STACK_LINE(220)
			int _g1 = first;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(220)
			while(((_g1 < last))){
				HX_STACK_LINE(220)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(221)
				timeIt(stages->__GetItem(i)->__GetItem((int)0),stages->__GetItem(i)->__GetItem((int)1)).Cast< Void >();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Map_obj,go,(void))

Void Map_obj::reset( ){
{
		HX_STACK_PUSH("Map::reset","Map.hx",69);
		HX_STACK_THIS(this);
		HX_STACK_LINE(70)
		::graph::Center p;		HX_STACK_VAR(p,"p");
		::graph::Corner q;		HX_STACK_VAR(q,"q");
		::graph::Edge edge;		HX_STACK_VAR(edge,"edge");
		HX_STACK_LINE(73)
		if (((this->points != null()))){
			HX_STACK_LINE(73)
			this->points->splice((int)0,this->points->length);
		}
		HX_STACK_LINE(76)
		if (((this->edges != null()))){
			HX_STACK_LINE(77)
			{
				HX_STACK_LINE(77)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::graph::Edge > _g1 = this->edges;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(77)
				while(((_g < _g1->length))){
					HX_STACK_LINE(77)
					::graph::Edge edge1 = _g1->__get(_g);		HX_STACK_VAR(edge1,"edge1");
					HX_STACK_LINE(77)
					++(_g);
					HX_STACK_LINE(78)
					edge1->d0 = edge1->d1 = null();
					HX_STACK_LINE(79)
					edge1->v0 = edge1->v1 = null();
				}
			}
			HX_STACK_LINE(81)
			this->edges->splice((int)0,this->edges->length);
		}
		HX_STACK_LINE(83)
		if (((this->centers != null()))){
			HX_STACK_LINE(84)
			{
				HX_STACK_LINE(84)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::graph::Center > _g1 = this->centers;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(84)
				while(((_g < _g1->length))){
					HX_STACK_LINE(84)
					::graph::Center p1 = _g1->__get(_g);		HX_STACK_VAR(p1,"p1");
					HX_STACK_LINE(84)
					++(_g);
					HX_STACK_LINE(85)
					p1->neighbors->splice((int)0,p1->neighbors->length);
					HX_STACK_LINE(86)
					p1->corners->splice((int)0,p1->corners->length);
					HX_STACK_LINE(87)
					p1->borders->splice((int)0,p1->borders->length);
				}
			}
			HX_STACK_LINE(89)
			this->centers->splice((int)0,this->centers->length);
		}
		HX_STACK_LINE(91)
		if (((this->corners != null()))){
			HX_STACK_LINE(92)
			{
				HX_STACK_LINE(92)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				Array< ::graph::Corner > _g1 = this->corners;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(92)
				while(((_g < _g1->length))){
					HX_STACK_LINE(92)
					::graph::Corner q1 = _g1->__get(_g);		HX_STACK_VAR(q1,"q1");
					HX_STACK_LINE(92)
					++(_g);
					HX_STACK_LINE(93)
					q1->adjacent->splice((int)0,q1->adjacent->length);
					HX_STACK_LINE(94)
					q1->touches->splice((int)0,q1->touches->length);
					HX_STACK_LINE(95)
					q1->protrudes->splice((int)0,q1->protrudes->length);
					HX_STACK_LINE(96)
					q1->downslope = null();
					HX_STACK_LINE(97)
					q1->watershed = null();
				}
			}
			HX_STACK_LINE(99)
			this->corners->splice((int)0,this->corners->length);
		}
		HX_STACK_LINE(103)
		if (((this->points == null()))){
			HX_STACK_LINE(103)
			this->points = Array_obj< ::neash::geom::Point >::__new();
		}
		HX_STACK_LINE(104)
		if (((this->edges == null()))){
			HX_STACK_LINE(104)
			this->edges = Array_obj< ::graph::Edge >::__new();
		}
		HX_STACK_LINE(105)
		if (((this->centers == null()))){
			HX_STACK_LINE(105)
			this->centers = Array_obj< ::graph::Center >::__new();
		}
		HX_STACK_LINE(106)
		if (((this->corners == null()))){
			HX_STACK_LINE(106)
			this->corners = Array_obj< ::graph::Corner >::__new();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Map_obj,reset,(void))

Void Map_obj::newIsland( ::String type,int seed,int variant){
{
		HX_STACK_PUSH("Map::newIsland","Map.hx",52);
		HX_STACK_THIS(this);
		HX_STACK_ARG(type,"type");
		HX_STACK_ARG(seed,"seed");
		HX_STACK_ARG(variant,"variant");
		HX_STACK_LINE(54)
		::String _switch_1 = (type);
		if (  ( _switch_1==HX_CSTRING("Perlin"))){
			HX_STACK_LINE(56)
			this->islandShape = ::IslandShape_obj::makePerlin(seed);
		}
		else if (  ( _switch_1==HX_CSTRING("Square"))){
			HX_STACK_LINE(58)
			this->islandShape = ::IslandShape_obj::makeSquare(seed);
		}
		else if (  ( _switch_1==HX_CSTRING("Blob"))){
			HX_STACK_LINE(60)
			this->islandShape = ::IslandShape_obj::makeBlob(seed);
		}
		else  {
			HX_STACK_LINE(62)
			this->islandShape = ::IslandShape_obj::makePerlin(seed);
		}
;
;
		HX_STACK_LINE(65)
		this->mapRandom->seed = variant;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Map_obj,newIsland,(void))

int Map_obj::NUM_POINTS;

Float Map_obj::LAKE_THRESHOLD;

int Map_obj::NUM_LLOYD_ITERATIONS;

::String Map_obj::getBiome( ::graph::Center p){
	HX_STACK_PUSH("Map::getBiome","Map.hx",792);
	HX_STACK_ARG(p,"p");
	HX_STACK_LINE(792)
	if ((p->ocean)){
		HX_STACK_LINE(794)
		return HX_CSTRING("OCEAN");
	}
	else{
		HX_STACK_LINE(796)
		if ((p->water)){
			HX_STACK_LINE(797)
			if (((p->elevation < 0.1))){
				HX_STACK_LINE(797)
				return HX_CSTRING("MARSH");
			}
			HX_STACK_LINE(798)
			if (((p->elevation > 0.8))){
				HX_STACK_LINE(798)
				return HX_CSTRING("ICE");
			}
			HX_STACK_LINE(799)
			return HX_CSTRING("LAKE");
		}
		else{
			HX_STACK_LINE(800)
			if ((p->coast)){
				HX_STACK_LINE(800)
				return HX_CSTRING("BEACH");
			}
			else{
				HX_STACK_LINE(802)
				if (((p->elevation > 0.8))){
					HX_STACK_LINE(802)
					if (((p->moisture > 0.50))){
						HX_STACK_LINE(803)
						return HX_CSTRING("SNOW");
					}
					else{
						HX_STACK_LINE(804)
						if (((p->moisture > 0.33))){
							HX_STACK_LINE(804)
							return HX_CSTRING("TUNDRA");
						}
						else{
							HX_STACK_LINE(805)
							if (((p->moisture > 0.16))){
								HX_STACK_LINE(805)
								return HX_CSTRING("BARE");
							}
							else{
								HX_STACK_LINE(806)
								return HX_CSTRING("SCORCHED");
							}
						}
					}
				}
				else{
					HX_STACK_LINE(807)
					if (((p->elevation > 0.6))){
						HX_STACK_LINE(807)
						if (((p->moisture > 0.66))){
							HX_STACK_LINE(808)
							return HX_CSTRING("TAIGA");
						}
						else{
							HX_STACK_LINE(809)
							if (((p->moisture > 0.33))){
								HX_STACK_LINE(809)
								return HX_CSTRING("SHRUBLAND");
							}
							else{
								HX_STACK_LINE(810)
								return HX_CSTRING("TEMPERATE_DESERT");
							}
						}
					}
					else{
						HX_STACK_LINE(811)
						if (((p->elevation > 0.3))){
							HX_STACK_LINE(811)
							if (((p->moisture > 0.83))){
								HX_STACK_LINE(812)
								return HX_CSTRING("TEMPERATE_RAIN_FOREST");
							}
							else{
								HX_STACK_LINE(813)
								if (((p->moisture > 0.50))){
									HX_STACK_LINE(813)
									return HX_CSTRING("TEMPERATE_DECIDUOUS_FOREST");
								}
								else{
									HX_STACK_LINE(814)
									if (((p->moisture > 0.16))){
										HX_STACK_LINE(814)
										return HX_CSTRING("GRASSLAND");
									}
									else{
										HX_STACK_LINE(815)
										return HX_CSTRING("TEMPERATE_DESERT");
									}
								}
							}
						}
						else{
							HX_STACK_LINE(816)
							if (((p->moisture > 0.66))){
								HX_STACK_LINE(817)
								return HX_CSTRING("TROPICAL_RAIN_FOREST");
							}
							else{
								HX_STACK_LINE(818)
								if (((p->moisture > 0.33))){
									HX_STACK_LINE(818)
									return HX_CSTRING("TROPICAL_SEASONAL_FOREST");
								}
								else{
									HX_STACK_LINE(819)
									if (((p->moisture > 0.16))){
										HX_STACK_LINE(819)
										return HX_CSTRING("GRASSLAND");
									}
									else{
										HX_STACK_LINE(820)
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
	HX_STACK_LINE(792)
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
	case 9:
		if (HX_FIELD_EQ(inName,"mapRandom") ) { mapRandom=inValue.Cast< ::de::polygonal::math::PM_PRNG >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"NUM_POINTS") ) { NUM_POINTS=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
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
	HX_MARK_MEMBER_NAME(Map_obj::LAKE_THRESHOLD,"LAKE_THRESHOLD");
	HX_MARK_MEMBER_NAME(Map_obj::NUM_LLOYD_ITERATIONS,"NUM_LLOYD_ITERATIONS");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Map_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Map_obj::NUM_POINTS,"NUM_POINTS");
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
	NUM_POINTS= (int)2000;
	LAKE_THRESHOLD= 0.3;
	NUM_LLOYD_ITERATIONS= (int)2;
}


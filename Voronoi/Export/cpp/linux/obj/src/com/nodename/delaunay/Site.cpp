#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_BoundsCheck
#include <com/nodename/delaunay/BoundsCheck.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Criterion
#include <com/nodename/delaunay/Criterion.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Edge
#include <com/nodename/delaunay/Edge.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_EdgeReorderer
#include <com/nodename/delaunay/EdgeReorderer.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_ICoord
#include <com/nodename/delaunay/ICoord.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_LR
#include <com/nodename/delaunay/LR.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Site
#include <com/nodename/delaunay/Site.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Voronoi
#include <com/nodename/delaunay/Voronoi.h>
#endif
#ifndef INCLUDED_com_nodename_geom_Polygon
#include <com/nodename/geom/Polygon.h>
#endif
#ifndef INCLUDED_com_nodename_geom_Winding
#include <com/nodename/geom/Winding.h>
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
namespace com{
namespace nodename{
namespace delaunay{

Void Site_obj::__construct(::neash::geom::Point p,int index,Float weight,int color)
{
HX_STACK_PUSH("Site::new","com/nodename/delaunay/Site.hx",77);
{
	HX_STACK_LINE(77)
	this->init(p,index,weight,color);
}
;
	return null();
}

Site_obj::~Site_obj() { }

Dynamic Site_obj::__CreateEmpty() { return  new Site_obj; }
hx::ObjectPtr< Site_obj > Site_obj::__new(::neash::geom::Point p,int index,Float weight,int color)
{  hx::ObjectPtr< Site_obj > result = new Site_obj();
	result->__construct(p,index,weight,color);
	return result;}

Dynamic Site_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Site_obj > result = new Site_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

hx::Object *Site_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::com::nodename::delaunay::ICoord_obj)) return operator ::com::nodename::delaunay::ICoord_obj *();
	return super::__ToInterface(inType);
}

Float Site_obj::dist( ::com::nodename::delaunay::ICoord p){
	HX_STACK_PUSH("Site::dist","com/nodename/delaunay/Site.hx",395);
	HX_STACK_THIS(this);
	HX_STACK_ARG(p,"p");
	HX_STACK_LINE(395)
	return ::neash::geom::Point_obj::distance(p->get_coord(),this->_coord);
}


HX_DEFINE_DYNAMIC_FUNC1(Site_obj,dist,return )

Float Site_obj::getY( ){
	HX_STACK_PUSH("Site::getY","com/nodename/delaunay/Site.hx",390);
	HX_STACK_THIS(this);
	HX_STACK_LINE(390)
	return this->_coord->y;
}


HX_DEFINE_DYNAMIC_FUNC0(Site_obj,getY,return )

Float Site_obj::getX( ){
	HX_STACK_PUSH("Site::getX","com/nodename/delaunay/Site.hx",385);
	HX_STACK_THIS(this);
	HX_STACK_LINE(385)
	return this->_coord->x;
}


HX_DEFINE_DYNAMIC_FUNC0(Site_obj,getX,return )

Void Site_obj::connect( Array< ::neash::geom::Point > points,int j,::neash::geom::Rectangle bounds,hx::Null< bool >  __o_closingUp){
bool closingUp = __o_closingUp.Default(false);
	HX_STACK_PUSH("Site::connect","com/nodename/delaunay/Site.hx",239);
	HX_STACK_THIS(this);
	HX_STACK_ARG(points,"points");
	HX_STACK_ARG(j,"j");
	HX_STACK_ARG(bounds,"bounds");
	HX_STACK_ARG(closingUp,"closingUp");
{
		HX_STACK_LINE(240)
		::neash::geom::Point rightPoint = points->__get((points->length - (int)1));		HX_STACK_VAR(rightPoint,"rightPoint");
		HX_STACK_LINE(241)
		::com::nodename::delaunay::Edge newEdge = this->_edges->__get(j);		HX_STACK_VAR(newEdge,"newEdge");
		HX_STACK_LINE(242)
		::com::nodename::delaunay::LR newOrientation = this->_edgeOrientations->__get(j);		HX_STACK_VAR(newOrientation,"newOrientation");
		HX_STACK_LINE(244)
		::neash::geom::Point newPoint = newEdge->clippedEnds->get(newOrientation->toString());		HX_STACK_VAR(newPoint,"newPoint");
		HX_STACK_LINE(245)
		if ((!(::com::nodename::delaunay::Site_obj::closeEnough(rightPoint,newPoint)))){
			HX_STACK_LINE(249)
			if (((bool((rightPoint->x != newPoint->x)) && bool((rightPoint->y != newPoint->y))))){
				HX_STACK_LINE(257)
				int rightCheck = ::com::nodename::delaunay::BoundsCheck_obj::check(rightPoint,bounds);		HX_STACK_VAR(rightCheck,"rightCheck");
				HX_STACK_LINE(258)
				int newCheck = ::com::nodename::delaunay::BoundsCheck_obj::check(newPoint,bounds);		HX_STACK_VAR(newCheck,"newCheck");
				HX_STACK_LINE(259)
				Float px;		HX_STACK_VAR(px,"px");
				Float py;		HX_STACK_VAR(py,"py");
				HX_STACK_LINE(260)
				if (((((int(rightCheck) & int((int)8))) != (int)0))){
					HX_STACK_LINE(262)
					px = bounds->nmeGetRight();
					HX_STACK_LINE(263)
					if (((((int(newCheck) & int((int)2))) != (int)0))){
						HX_STACK_LINE(265)
						py = bounds->nmeGetBottom();
						HX_STACK_LINE(266)
						points->push(::neash::geom::Point_obj::__new(px,py));
					}
					else{
						HX_STACK_LINE(268)
						if (((((int(newCheck) & int((int)1))) != (int)0))){
							HX_STACK_LINE(270)
							py = bounds->nmeGetTop();
							HX_STACK_LINE(271)
							points->push(::neash::geom::Point_obj::__new(px,py));
						}
						else{
							HX_STACK_LINE(273)
							if (((((int(newCheck) & int((int)4))) != (int)0))){
								HX_STACK_LINE(275)
								if ((((((rightPoint->y - bounds->y) + newPoint->y) - bounds->y) < bounds->height))){
									HX_STACK_LINE(276)
									py = bounds->nmeGetTop();
								}
								else{
									HX_STACK_LINE(280)
									py = bounds->nmeGetBottom();
								}
								HX_STACK_LINE(283)
								points->push(::neash::geom::Point_obj::__new(px,py));
								HX_STACK_LINE(284)
								points->push(::neash::geom::Point_obj::__new(bounds->nmeGetLeft(),py));
							}
						}
					}
				}
				else{
					HX_STACK_LINE(287)
					if (((((int(rightCheck) & int((int)4))) != (int)0))){
						HX_STACK_LINE(289)
						px = bounds->nmeGetLeft();
						HX_STACK_LINE(290)
						if (((((int(newCheck) & int((int)2))) != (int)0))){
							HX_STACK_LINE(292)
							py = bounds->nmeGetBottom();
							HX_STACK_LINE(293)
							points->push(::neash::geom::Point_obj::__new(px,py));
						}
						else{
							HX_STACK_LINE(295)
							if (((((int(newCheck) & int((int)1))) != (int)0))){
								HX_STACK_LINE(297)
								py = bounds->nmeGetTop();
								HX_STACK_LINE(298)
								points->push(::neash::geom::Point_obj::__new(px,py));
							}
							else{
								HX_STACK_LINE(300)
								if (((((int(newCheck) & int((int)8))) != (int)0))){
									HX_STACK_LINE(302)
									if ((((((rightPoint->y - bounds->y) + newPoint->y) - bounds->y) < bounds->height))){
										HX_STACK_LINE(303)
										py = bounds->nmeGetTop();
									}
									else{
										HX_STACK_LINE(307)
										py = bounds->nmeGetBottom();
									}
									HX_STACK_LINE(310)
									points->push(::neash::geom::Point_obj::__new(px,py));
									HX_STACK_LINE(311)
									points->push(::neash::geom::Point_obj::__new(bounds->nmeGetRight(),py));
								}
							}
						}
					}
					else{
						HX_STACK_LINE(314)
						if (((((int(rightCheck) & int((int)1))) != (int)0))){
							HX_STACK_LINE(316)
							py = bounds->nmeGetTop();
							HX_STACK_LINE(317)
							if (((((int(newCheck) & int((int)8))) != (int)0))){
								HX_STACK_LINE(319)
								px = bounds->nmeGetRight();
								HX_STACK_LINE(320)
								points->push(::neash::geom::Point_obj::__new(px,py));
							}
							else{
								HX_STACK_LINE(322)
								if (((((int(newCheck) & int((int)4))) != (int)0))){
									HX_STACK_LINE(324)
									px = bounds->nmeGetLeft();
									HX_STACK_LINE(325)
									points->push(::neash::geom::Point_obj::__new(px,py));
								}
								else{
									HX_STACK_LINE(327)
									if (((((int(newCheck) & int((int)2))) != (int)0))){
										HX_STACK_LINE(329)
										if ((((((rightPoint->x - bounds->x) + newPoint->x) - bounds->x) < bounds->width))){
											HX_STACK_LINE(330)
											px = bounds->nmeGetLeft();
										}
										else{
											HX_STACK_LINE(334)
											px = bounds->nmeGetRight();
										}
										HX_STACK_LINE(337)
										points->push(::neash::geom::Point_obj::__new(px,py));
										HX_STACK_LINE(338)
										points->push(::neash::geom::Point_obj::__new(px,bounds->nmeGetBottom()));
									}
								}
							}
						}
						else{
							HX_STACK_LINE(341)
							if (((((int(rightCheck) & int((int)2))) != (int)0))){
								HX_STACK_LINE(343)
								py = bounds->nmeGetBottom();
								HX_STACK_LINE(344)
								if (((((int(newCheck) & int((int)8))) != (int)0))){
									HX_STACK_LINE(346)
									px = bounds->nmeGetRight();
									HX_STACK_LINE(347)
									points->push(::neash::geom::Point_obj::__new(px,py));
								}
								else{
									HX_STACK_LINE(349)
									if (((((int(newCheck) & int((int)4))) != (int)0))){
										HX_STACK_LINE(351)
										px = bounds->nmeGetLeft();
										HX_STACK_LINE(352)
										points->push(::neash::geom::Point_obj::__new(px,py));
									}
									else{
										HX_STACK_LINE(354)
										if (((((int(newCheck) & int((int)1))) != (int)0))){
											HX_STACK_LINE(356)
											if ((((((rightPoint->x - bounds->x) + newPoint->x) - bounds->x) < bounds->width))){
												HX_STACK_LINE(357)
												px = bounds->nmeGetLeft();
											}
											else{
												HX_STACK_LINE(361)
												px = bounds->nmeGetRight();
											}
											HX_STACK_LINE(364)
											points->push(::neash::geom::Point_obj::__new(px,py));
											HX_STACK_LINE(365)
											points->push(::neash::geom::Point_obj::__new(px,bounds->nmeGetTop()));
										}
									}
								}
							}
						}
					}
				}
			}
			HX_STACK_LINE(369)
			if ((closingUp)){
				HX_STACK_LINE(370)
				return null();
			}
			HX_STACK_LINE(374)
			points->push(newPoint);
		}
		HX_STACK_LINE(376)
		::neash::geom::Point newRightPoint = newEdge->clippedEnds->get(::com::nodename::delaunay::LR_obj::other(newOrientation)->toString());		HX_STACK_VAR(newRightPoint,"newRightPoint");
		HX_STACK_LINE(377)
		if ((!(::com::nodename::delaunay::Site_obj::closeEnough(points->__get((int)0),newRightPoint)))){
			HX_STACK_LINE(378)
			points->push(newRightPoint);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Site_obj,connect,(void))

Array< ::neash::geom::Point > Site_obj::clipToBounds( ::neash::geom::Rectangle bounds){
	HX_STACK_PUSH("Site::clipToBounds","com/nodename/delaunay/Site.hx",202);
	HX_STACK_THIS(this);
	HX_STACK_ARG(bounds,"bounds");
	HX_STACK_LINE(203)
	Array< ::neash::geom::Point > points = Array_obj< ::neash::geom::Point >::__new();		HX_STACK_VAR(points,"points");
	HX_STACK_LINE(204)
	int n = this->_edges->length;		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(205)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(206)
	::com::nodename::delaunay::Edge edge;		HX_STACK_VAR(edge,"edge");
	HX_STACK_LINE(207)
	while(((bool((i < n)) && bool(((this->_edges->__get(i)->clippedEnds != null()) == false))))){
		HX_STACK_LINE(208)
		++(i);
	}
	HX_STACK_LINE(212)
	if (((i == n))){
		HX_STACK_LINE(213)
		return Array_obj< ::neash::geom::Point >::__new();
	}
	HX_STACK_LINE(218)
	edge = this->_edges->__get(i);
	HX_STACK_LINE(219)
	::com::nodename::delaunay::LR orientation = this->_edgeOrientations->__get(i);		HX_STACK_VAR(orientation,"orientation");
	HX_STACK_LINE(220)
	points->push(edge->clippedEnds->get(orientation->toString()));
	HX_STACK_LINE(221)
	points->push(edge->clippedEnds->get(::com::nodename::delaunay::LR_obj::other(orientation)->toString()));
	HX_STACK_LINE(223)
	{
		HX_STACK_LINE(223)
		int _g = (i + (int)1);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(223)
		while(((_g < n))){
			HX_STACK_LINE(223)
			int j = (_g)++;		HX_STACK_VAR(j,"j");
			HX_STACK_LINE(225)
			edge = this->_edges->__get(j);
			HX_STACK_LINE(226)
			if ((((edge->clippedEnds != null()) == false))){
				HX_STACK_LINE(227)
				continue;
			}
			HX_STACK_LINE(230)
			this->connect(points,j,bounds,null());
		}
	}
	HX_STACK_LINE(233)
	this->connect(points,i,bounds,true);
	HX_STACK_LINE(235)
	return points;
}


HX_DEFINE_DYNAMIC_FUNC1(Site_obj,clipToBounds,return )

Void Site_obj::reorderEdges( ){
{
		HX_STACK_PUSH("Site::reorderEdges","com/nodename/delaunay/Site.hx",192);
		HX_STACK_THIS(this);
		HX_STACK_LINE(194)
		::com::nodename::delaunay::EdgeReorderer reorderer = ::com::nodename::delaunay::EdgeReorderer_obj::__new(this->_edges,::com::nodename::delaunay::Criterion_obj::vertex_dyn());		HX_STACK_VAR(reorderer,"reorderer");
		HX_STACK_LINE(195)
		this->_edges = reorderer->edges;
		HX_STACK_LINE(197)
		this->_edgeOrientations = reorderer->edgeOrientations;
		HX_STACK_LINE(198)
		reorderer->dispose();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Site_obj,reorderEdges,(void))

Array< ::neash::geom::Point > Site_obj::region( ::neash::geom::Rectangle clippingBounds){
	HX_STACK_PUSH("Site::region","com/nodename/delaunay/Site.hx",170);
	HX_STACK_THIS(this);
	HX_STACK_ARG(clippingBounds,"clippingBounds");
	HX_STACK_LINE(172)
	if (((bool((this->_edges == null())) || bool((this->_edges->length == (int)0))))){
		HX_STACK_LINE(174)
		::nme::Lib_obj::trace(HX_CSTRING("empty region array"));
		HX_STACK_LINE(175)
		return Array_obj< ::neash::geom::Point >::__new();
	}
	HX_STACK_LINE(177)
	if (((this->_edgeOrientations == null()))){
		HX_STACK_LINE(180)
		this->reorderEdges();
		HX_STACK_LINE(181)
		this->_region = this->clipToBounds(clippingBounds);
		HX_STACK_LINE(182)
		if (((::com::nodename::geom::Polygon_obj::__new(this->_region)->winding() == ::com::nodename::geom::Winding_obj::CLOCKWISE))){
			HX_STACK_LINE(183)
			this->_region->reverse();
		}
	}
	HX_STACK_LINE(188)
	return this->_region;
}


HX_DEFINE_DYNAMIC_FUNC1(Site_obj,region,return )

::com::nodename::delaunay::Site Site_obj::neighborSite( ::com::nodename::delaunay::Edge edge){
	HX_STACK_PUSH("Site::neighborSite","com/nodename/delaunay/Site.hx",157);
	HX_STACK_THIS(this);
	HX_STACK_ARG(edge,"edge");
	HX_STACK_LINE(158)
	if (((hx::ObjectPtr<OBJ_>(this) == edge->leftSite))){
		HX_STACK_LINE(159)
		return edge->rightSite;
	}
	HX_STACK_LINE(162)
	if (((hx::ObjectPtr<OBJ_>(this) == edge->rightSite))){
		HX_STACK_LINE(163)
		return edge->leftSite;
	}
	HX_STACK_LINE(166)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Site_obj,neighborSite,return )

Array< ::com::nodename::delaunay::Site > Site_obj::neighborSites( ){
	HX_STACK_PUSH("Site::neighborSites","com/nodename/delaunay/Site.hx",138);
	HX_STACK_THIS(this);
	HX_STACK_LINE(139)
	if (((bool((this->_edges == null())) || bool((this->_edges->length == (int)0))))){
		HX_STACK_LINE(140)
		return Array_obj< ::com::nodename::delaunay::Site >::__new();
	}
	HX_STACK_LINE(143)
	if (((this->_edgeOrientations == null()))){
		HX_STACK_LINE(144)
		this->reorderEdges();
	}
	HX_STACK_LINE(147)
	Array< ::com::nodename::delaunay::Site > list = Array_obj< ::com::nodename::delaunay::Site >::__new();		HX_STACK_VAR(list,"list");
	HX_STACK_LINE(148)
	::com::nodename::delaunay::Edge edge;		HX_STACK_VAR(edge,"edge");
	HX_STACK_LINE(149)
	{
		HX_STACK_LINE(149)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::com::nodename::delaunay::Edge > _g1 = this->_edges;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(149)
		while(((_g < _g1->length))){
			HX_STACK_LINE(149)
			::com::nodename::delaunay::Edge edge1 = _g1->__get(_g);		HX_STACK_VAR(edge1,"edge1");
			HX_STACK_LINE(149)
			++(_g);
			HX_STACK_LINE(151)
			list->push(this->neighborSite(edge1));
		}
	}
	HX_STACK_LINE(153)
	return list;
}


HX_DEFINE_DYNAMIC_FUNC0(Site_obj,neighborSites,return )

::com::nodename::delaunay::Edge Site_obj::nearestEdge( ){
	HX_STACK_PUSH("Site::nearestEdge","com/nodename/delaunay/Site.hx",132);
	HX_STACK_THIS(this);
	HX_STACK_LINE(133)
	this->_edges->sort(::com::nodename::delaunay::Edge_obj::compareSitesDistances_dyn());
	HX_STACK_LINE(134)
	return this->_edges->__get((int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(Site_obj,nearestEdge,return )

Void Site_obj::addEdge( ::com::nodename::delaunay::Edge edge){
{
		HX_STACK_PUSH("Site::addEdge","com/nodename/delaunay/Site.hx",127);
		HX_STACK_THIS(this);
		HX_STACK_ARG(edge,"edge");
		HX_STACK_LINE(127)
		this->_edges->push(edge);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Site_obj,addEdge,(void))

Void Site_obj::clear( ){
{
		HX_STACK_PUSH("Site::clear","com/nodename/delaunay/Site.hx",111);
		HX_STACK_THIS(this);
		HX_STACK_LINE(112)
		if (((this->_edges != null()))){
			HX_STACK_LINE(113)
			this->_edges = null();
		}
		HX_STACK_LINE(116)
		if (((this->_edgeOrientations != null()))){
			HX_STACK_LINE(117)
			this->_edgeOrientations = null();
		}
		HX_STACK_LINE(120)
		if (((this->_region != null()))){
			HX_STACK_LINE(121)
			this->_region = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Site_obj,clear,(void))

Void Site_obj::dispose( ){
{
		HX_STACK_PUSH("Site::dispose","com/nodename/delaunay/Site.hx",104);
		HX_STACK_THIS(this);
		HX_STACK_LINE(105)
		this->_coord = null();
		HX_STACK_LINE(106)
		this->clear();
		HX_STACK_LINE(107)
		::com::nodename::delaunay::Site_obj::_pool->push(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Site_obj,dispose,(void))

Void Site_obj::move( ::neash::geom::Point p){
{
		HX_STACK_PUSH("Site::move","com/nodename/delaunay/Site.hx",98);
		HX_STACK_THIS(this);
		HX_STACK_ARG(p,"p");
		HX_STACK_LINE(99)
		this->clear();
		HX_STACK_LINE(100)
		this->_coord = p;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Site_obj,move,(void))

::String Site_obj::toString( ){
	HX_STACK_PUSH("Site::toString","com/nodename/delaunay/Site.hx",93);
	HX_STACK_THIS(this);
	HX_STACK_LINE(93)
	return (((HX_CSTRING("Site ") + this->_siteIndex) + HX_CSTRING(": ")) + ::Std_obj::string(this->_coord));
}


HX_DEFINE_DYNAMIC_FUNC0(Site_obj,toString,return )

::com::nodename::delaunay::Site Site_obj::init( ::neash::geom::Point p,int index,Float weight,int color){
	HX_STACK_PUSH("Site::init","com/nodename/delaunay/Site.hx",82);
	HX_STACK_THIS(this);
	HX_STACK_ARG(p,"p");
	HX_STACK_ARG(index,"index");
	HX_STACK_ARG(weight,"weight");
	HX_STACK_ARG(color,"color");
	HX_STACK_LINE(83)
	this->_coord = p;
	HX_STACK_LINE(84)
	this->_siteIndex = index;
	HX_STACK_LINE(85)
	this->weight = weight;
	HX_STACK_LINE(86)
	this->color = color;
	HX_STACK_LINE(87)
	this->_edges = Array_obj< ::com::nodename::delaunay::Edge >::__new();
	HX_STACK_LINE(88)
	this->_region = null();
	HX_STACK_LINE(89)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC4(Site_obj,init,return )

Array< ::com::nodename::delaunay::Edge > Site_obj::get_edges( ){
	HX_STACK_PUSH("Site::get_edges","com/nodename/delaunay/Site.hx",68);
	HX_STACK_THIS(this);
	HX_STACK_LINE(68)
	return this->_edges;
}


HX_DEFINE_DYNAMIC_FUNC0(Site_obj,get_edges,return )

::neash::geom::Point Site_obj::get_coord( ){
	HX_STACK_PUSH("Site::get_coord","com/nodename/delaunay/Site.hx",54);
	HX_STACK_THIS(this);
	HX_STACK_LINE(54)
	return this->_coord;
}


HX_DEFINE_DYNAMIC_FUNC0(Site_obj,get_coord,return )

Array< ::com::nodename::delaunay::Site > Site_obj::_pool;

::com::nodename::delaunay::Site Site_obj::create( ::neash::geom::Point p,int index,Float weight,int color){
	HX_STACK_PUSH("Site::create","com/nodename/delaunay/Site.hx",20);
	HX_STACK_ARG(p,"p");
	HX_STACK_ARG(index,"index");
	HX_STACK_ARG(weight,"weight");
	HX_STACK_ARG(color,"color");
	HX_STACK_LINE(20)
	if (((::com::nodename::delaunay::Site_obj::_pool->length > (int)0))){
		HX_STACK_LINE(22)
		return ::com::nodename::delaunay::Site_obj::_pool->pop()->init(p,index,weight,color);
	}
	else{
		HX_STACK_LINE(26)
		return ::com::nodename::delaunay::Site_obj::__new(p,index,weight,color);
	}
	HX_STACK_LINE(20)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Site_obj,create,return )

Void Site_obj::sortSites( Array< ::com::nodename::delaunay::Site > sites){
{
		HX_STACK_PUSH("Site::sortSites","com/nodename/delaunay/Site.hx",40);
		HX_STACK_ARG(sites,"sites");
		HX_STACK_LINE(41)
		sites->sort(::com::nodename::delaunay::Voronoi_obj::compareSiteByYThenX_dyn());
		HX_STACK_LINE(42)
		{
			HX_STACK_LINE(42)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = sites->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(42)
			while(((_g1 < _g))){
				HX_STACK_LINE(42)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(43)
				sites->__get(i)->_siteIndex = i;
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Site_obj,sortSites,(void))

Float Site_obj::EPSILON;

bool Site_obj::closeEnough( ::neash::geom::Point p0,::neash::geom::Point p1){
	HX_STACK_PUSH("Site::closeEnough","com/nodename/delaunay/Site.hx",49);
	HX_STACK_ARG(p0,"p0");
	HX_STACK_ARG(p1,"p1");
	HX_STACK_LINE(49)
	return (::neash::geom::Point_obj::distance(p0,p1) < .005);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Site_obj,closeEnough,return )


Site_obj::Site_obj()
{
}

void Site_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Site);
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(_region,"_region");
	HX_MARK_MEMBER_NAME(_edgeOrientations,"_edgeOrientations");
	HX_MARK_MEMBER_NAME(edges,"edges");
	HX_MARK_MEMBER_NAME(_edges,"_edges");
	HX_MARK_MEMBER_NAME(_siteIndex,"_siteIndex");
	HX_MARK_MEMBER_NAME(weight,"weight");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_MEMBER_NAME(_coord,"_coord");
	HX_MARK_MEMBER_NAME(coord,"coord");
	HX_MARK_END_CLASS();
}

void Site_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(_region,"_region");
	HX_VISIT_MEMBER_NAME(_edgeOrientations,"_edgeOrientations");
	HX_VISIT_MEMBER_NAME(edges,"edges");
	HX_VISIT_MEMBER_NAME(_edges,"_edges");
	HX_VISIT_MEMBER_NAME(_siteIndex,"_siteIndex");
	HX_VISIT_MEMBER_NAME(weight,"weight");
	HX_VISIT_MEMBER_NAME(color,"color");
	HX_VISIT_MEMBER_NAME(_coord,"_coord");
	HX_VISIT_MEMBER_NAME(coord,"coord");
}

Dynamic Site_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return inCallProp ? getY() : y; }
		if (HX_FIELD_EQ(inName,"x") ) { return inCallProp ? getX() : x; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"dist") ) { return dist_dyn(); }
		if (HX_FIELD_EQ(inName,"getY") ) { return getY_dyn(); }
		if (HX_FIELD_EQ(inName,"getX") ) { return getX_dyn(); }
		if (HX_FIELD_EQ(inName,"move") ) { return move_dyn(); }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_pool") ) { return _pool; }
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		if (HX_FIELD_EQ(inName,"edges") ) { return inCallProp ? get_edges() : edges; }
		if (HX_FIELD_EQ(inName,"color") ) { return color; }
		if (HX_FIELD_EQ(inName,"coord") ) { return inCallProp ? get_coord() : coord; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"region") ) { return region_dyn(); }
		if (HX_FIELD_EQ(inName,"_edges") ) { return _edges; }
		if (HX_FIELD_EQ(inName,"weight") ) { return weight; }
		if (HX_FIELD_EQ(inName,"_coord") ) { return _coord; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"EPSILON") ) { return EPSILON; }
		if (HX_FIELD_EQ(inName,"connect") ) { return connect_dyn(); }
		if (HX_FIELD_EQ(inName,"addEdge") ) { return addEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"_region") ) { return _region; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"sortSites") ) { return sortSites_dyn(); }
		if (HX_FIELD_EQ(inName,"get_edges") ) { return get_edges_dyn(); }
		if (HX_FIELD_EQ(inName,"get_coord") ) { return get_coord_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_siteIndex") ) { return _siteIndex; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"closeEnough") ) { return closeEnough_dyn(); }
		if (HX_FIELD_EQ(inName,"nearestEdge") ) { return nearestEdge_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"clipToBounds") ) { return clipToBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"reorderEdges") ) { return reorderEdges_dyn(); }
		if (HX_FIELD_EQ(inName,"neighborSite") ) { return neighborSite_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"neighborSites") ) { return neighborSites_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_edgeOrientations") ) { return _edgeOrientations; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Site_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_pool") ) { _pool=inValue.Cast< Array< ::com::nodename::delaunay::Site > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"edges") ) { edges=inValue.Cast< Array< ::com::nodename::delaunay::Edge > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"color") ) { color=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"coord") ) { coord=inValue.Cast< ::neash::geom::Point >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_edges") ) { _edges=inValue.Cast< Array< ::com::nodename::delaunay::Edge > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"weight") ) { weight=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_coord") ) { _coord=inValue.Cast< ::neash::geom::Point >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"EPSILON") ) { EPSILON=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_region") ) { _region=inValue.Cast< Array< ::neash::geom::Point > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_siteIndex") ) { _siteIndex=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_edgeOrientations") ) { _edgeOrientations=inValue.Cast< Array< ::com::nodename::delaunay::LR > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Site_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("_region"));
	outFields->push(HX_CSTRING("_edgeOrientations"));
	outFields->push(HX_CSTRING("edges"));
	outFields->push(HX_CSTRING("_edges"));
	outFields->push(HX_CSTRING("_siteIndex"));
	outFields->push(HX_CSTRING("weight"));
	outFields->push(HX_CSTRING("color"));
	outFields->push(HX_CSTRING("_coord"));
	outFields->push(HX_CSTRING("coord"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_pool"),
	HX_CSTRING("create"),
	HX_CSTRING("sortSites"),
	HX_CSTRING("EPSILON"),
	HX_CSTRING("closeEnough"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("dist"),
	HX_CSTRING("getY"),
	HX_CSTRING("y"),
	HX_CSTRING("getX"),
	HX_CSTRING("x"),
	HX_CSTRING("connect"),
	HX_CSTRING("clipToBounds"),
	HX_CSTRING("reorderEdges"),
	HX_CSTRING("region"),
	HX_CSTRING("neighborSite"),
	HX_CSTRING("neighborSites"),
	HX_CSTRING("nearestEdge"),
	HX_CSTRING("addEdge"),
	HX_CSTRING("clear"),
	HX_CSTRING("dispose"),
	HX_CSTRING("move"),
	HX_CSTRING("toString"),
	HX_CSTRING("init"),
	HX_CSTRING("_region"),
	HX_CSTRING("_edgeOrientations"),
	HX_CSTRING("get_edges"),
	HX_CSTRING("edges"),
	HX_CSTRING("_edges"),
	HX_CSTRING("_siteIndex"),
	HX_CSTRING("weight"),
	HX_CSTRING("color"),
	HX_CSTRING("get_coord"),
	HX_CSTRING("_coord"),
	HX_CSTRING("coord"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Site_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Site_obj::_pool,"_pool");
	HX_MARK_MEMBER_NAME(Site_obj::EPSILON,"EPSILON");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Site_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Site_obj::_pool,"_pool");
	HX_VISIT_MEMBER_NAME(Site_obj::EPSILON,"EPSILON");
};

Class Site_obj::__mClass;

void Site_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.delaunay.Site"), hx::TCanCast< Site_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Site_obj::__boot()
{
	_pool= Array_obj< ::com::nodename::delaunay::Site >::__new();
	EPSILON= .005;
}

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

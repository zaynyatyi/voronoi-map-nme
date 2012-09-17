#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Edge
#include <com/nodename/delaunay/Edge.h>
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
#ifndef INCLUDED_com_nodename_delaunay_Vertex
#include <com/nodename/delaunay/Vertex.h>
#endif
#ifndef INCLUDED_com_nodename_geom_LineSegment
#include <com/nodename/geom/LineSegment.h>
#endif
#ifndef INCLUDED_neash_display_BitmapData
#include <neash/display/BitmapData.h>
#endif
#ifndef INCLUDED_neash_display_CapsStyle
#include <neash/display/CapsStyle.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_Graphics
#include <neash/display/Graphics.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_JointStyle
#include <neash/display/JointStyle.h>
#endif
#ifndef INCLUDED_neash_display_LineScaleMode
#include <neash/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_geom_ColorTransform
#include <neash/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_neash_geom_Matrix
#include <neash/geom/Matrix.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
#ifndef INCLUDED_neash_geom_Rectangle
#include <neash/geom/Rectangle.h>
#endif
namespace com{
namespace nodename{
namespace delaunay{

Void Edge_obj::__construct()
{
HX_STACK_PUSH("Edge::new","com/nodename/delaunay/Edge.hx",247);
{
	HX_STACK_LINE(248)
	this->_edgeIndex = (::com::nodename::delaunay::Edge_obj::_nedges)++;
	HX_STACK_LINE(249)
	this->init();
}
;
	return null();
}

Edge_obj::~Edge_obj() { }

Dynamic Edge_obj::__CreateEmpty() { return  new Edge_obj; }
hx::ObjectPtr< Edge_obj > Edge_obj::__new()
{  hx::ObjectPtr< Edge_obj > result = new Edge_obj();
	result->__construct();
	return result;}

Dynamic Edge_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Edge_obj > result = new Edge_obj();
	result->__construct();
	return result;}

Void Edge_obj::clipVertices( ::neash::geom::Rectangle bounds){
{
		HX_STACK_PUSH("Edge::clipVertices","com/nodename/delaunay/Edge.hx",272);
		HX_STACK_THIS(this);
		HX_STACK_ARG(bounds,"bounds");
		HX_STACK_LINE(273)
		Float xmin = bounds->x;		HX_STACK_VAR(xmin,"xmin");
		HX_STACK_LINE(274)
		Float ymin = bounds->y;		HX_STACK_VAR(ymin,"ymin");
		HX_STACK_LINE(275)
		Float xmax = bounds->nmeGetRight();		HX_STACK_VAR(xmax,"xmax");
		HX_STACK_LINE(276)
		Float ymax = bounds->nmeGetBottom();		HX_STACK_VAR(ymax,"ymax");
		HX_STACK_LINE(278)
		::com::nodename::delaunay::Vertex vertex0;		HX_STACK_VAR(vertex0,"vertex0");
		::com::nodename::delaunay::Vertex vertex1;		HX_STACK_VAR(vertex1,"vertex1");
		HX_STACK_LINE(279)
		Float x0;		HX_STACK_VAR(x0,"x0");
		Float x1;		HX_STACK_VAR(x1,"x1");
		Float y0;		HX_STACK_VAR(y0,"y0");
		Float y1;		HX_STACK_VAR(y1,"y1");
		HX_STACK_LINE(281)
		if (((bool((this->a == 1.0)) && bool((this->b >= 0.0))))){
			HX_STACK_LINE(283)
			vertex0 = this->rightVertex;
			HX_STACK_LINE(284)
			vertex1 = this->leftVertex;
		}
		else{
			HX_STACK_LINE(288)
			vertex0 = this->leftVertex;
			HX_STACK_LINE(289)
			vertex1 = this->rightVertex;
		}
		HX_STACK_LINE(292)
		if (((this->a == 1.0))){
			HX_STACK_LINE(294)
			y0 = ymin;
			HX_STACK_LINE(295)
			if (((bool((vertex0 != null())) && bool((vertex0->_coord->y > ymin))))){
				HX_STACK_LINE(296)
				y0 = vertex0->_coord->y;
			}
			HX_STACK_LINE(299)
			if (((y0 > ymax))){
				HX_STACK_LINE(300)
				return null();
			}
			HX_STACK_LINE(303)
			x0 = (this->c - (this->b * y0));
			HX_STACK_LINE(305)
			y1 = ymax;
			HX_STACK_LINE(306)
			if (((bool((vertex1 != null())) && bool((vertex1->_coord->y < ymax))))){
				HX_STACK_LINE(307)
				y1 = vertex1->_coord->y;
			}
			HX_STACK_LINE(310)
			if (((y1 < ymin))){
				HX_STACK_LINE(311)
				return null();
			}
			HX_STACK_LINE(314)
			x1 = (this->c - (this->b * y1));
			HX_STACK_LINE(316)
			if (((bool((bool((x0 > xmax)) && bool((x1 > xmax)))) || bool((bool((x0 < xmin)) && bool((x1 < xmin))))))){
				HX_STACK_LINE(317)
				return null();
			}
			HX_STACK_LINE(321)
			if (((x0 > xmax))){
				HX_STACK_LINE(323)
				x0 = xmax;
				HX_STACK_LINE(323)
				y0 = (Float(((this->c - x0))) / Float(this->b));
			}
			else{
				HX_STACK_LINE(325)
				if (((x0 < xmin))){
					HX_STACK_LINE(327)
					x0 = xmin;
					HX_STACK_LINE(327)
					y0 = (Float(((this->c - x0))) / Float(this->b));
				}
			}
			HX_STACK_LINE(330)
			if (((x1 > xmax))){
				HX_STACK_LINE(332)
				x1 = xmax;
				HX_STACK_LINE(332)
				y1 = (Float(((this->c - x1))) / Float(this->b));
			}
			else{
				HX_STACK_LINE(334)
				if (((x1 < xmin))){
					HX_STACK_LINE(336)
					x1 = xmin;
					HX_STACK_LINE(336)
					y1 = (Float(((this->c - x1))) / Float(this->b));
				}
			}
		}
		else{
			HX_STACK_LINE(341)
			x0 = xmin;
			HX_STACK_LINE(342)
			if (((bool((vertex0 != null())) && bool((vertex0->_coord->x > xmin))))){
				HX_STACK_LINE(343)
				x0 = vertex0->_coord->x;
			}
			HX_STACK_LINE(346)
			if (((x0 > xmax))){
				HX_STACK_LINE(347)
				return null();
			}
			HX_STACK_LINE(350)
			y0 = (this->c - (this->a * x0));
			HX_STACK_LINE(352)
			x1 = xmax;
			HX_STACK_LINE(353)
			if (((bool((vertex1 != null())) && bool((vertex1->_coord->x < xmax))))){
				HX_STACK_LINE(354)
				x1 = vertex1->_coord->x;
			}
			HX_STACK_LINE(357)
			if (((x1 < xmin))){
				HX_STACK_LINE(358)
				return null();
			}
			HX_STACK_LINE(361)
			y1 = (this->c - (this->a * x1));
			HX_STACK_LINE(363)
			if (((bool((bool((y0 > ymax)) && bool((y1 > ymax)))) || bool((bool((y0 < ymin)) && bool((y1 < ymin))))))){
				HX_STACK_LINE(364)
				return null();
			}
			HX_STACK_LINE(368)
			if (((y0 > ymax))){
				HX_STACK_LINE(370)
				y0 = ymax;
				HX_STACK_LINE(370)
				x0 = (Float(((this->c - y0))) / Float(this->a));
			}
			else{
				HX_STACK_LINE(372)
				if (((y0 < ymin))){
					HX_STACK_LINE(374)
					y0 = ymin;
					HX_STACK_LINE(374)
					x0 = (Float(((this->c - y0))) / Float(this->a));
				}
			}
			HX_STACK_LINE(377)
			if (((y1 > ymax))){
				HX_STACK_LINE(379)
				y1 = ymax;
				HX_STACK_LINE(379)
				x1 = (Float(((this->c - y1))) / Float(this->a));
			}
			else{
				HX_STACK_LINE(381)
				if (((y1 < ymin))){
					HX_STACK_LINE(383)
					y1 = ymin;
					HX_STACK_LINE(383)
					x1 = (Float(((this->c - y1))) / Float(this->a));
				}
			}
		}
		HX_STACK_LINE(387)
		this->clippedEnds = ::Hash_obj::__new();
		HX_STACK_LINE(388)
		if (((vertex0 == this->leftVertex))){
			HX_STACK_LINE(390)
			this->clippedEnds->set(::com::nodename::delaunay::LR_obj::LEFT->toString(),::neash::geom::Point_obj::__new(x0,y0));
			HX_STACK_LINE(391)
			this->clippedEnds->set(::com::nodename::delaunay::LR_obj::RIGHT->toString(),::neash::geom::Point_obj::__new(x1,y1));
		}
		else{
			HX_STACK_LINE(395)
			this->clippedEnds->set(::com::nodename::delaunay::LR_obj::RIGHT->toString(),::neash::geom::Point_obj::__new(x0,y0));
			HX_STACK_LINE(396)
			this->clippedEnds->set(::com::nodename::delaunay::LR_obj::LEFT->toString(),::neash::geom::Point_obj::__new(x1,y1));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Edge_obj,clipVertices,(void))

::String Edge_obj::toString( ){
	HX_STACK_PUSH("Edge::toString","com/nodename/delaunay/Edge.hx",259);
	HX_STACK_THIS(this);
	HX_STACK_LINE(259)
	return ((((((((((HX_CSTRING("Edge ") + this->_edgeIndex) + HX_CSTRING("; sites ")) + ::Std_obj::string(this->leftSite)) + HX_CSTRING(", ")) + ::Std_obj::string(this->rightSite)) + HX_CSTRING("; endVertices ")) + ((  (((this->leftVertex != null()))) ? ::String(::Std_obj::string(this->leftVertex->vertexIndex)) : ::String(HX_CSTRING("null")) ))) + HX_CSTRING(", ")) + ((  (((this->rightVertex != null()))) ? ::String(::Std_obj::string(this->rightVertex->vertexIndex)) : ::String(HX_CSTRING("null")) ))) + HX_CSTRING("::"));
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,toString,return )

Void Edge_obj::init( ){
{
		HX_STACK_PUSH("Edge::init","com/nodename/delaunay/Edge.hx",253);
		HX_STACK_THIS(this);
		HX_STACK_LINE(254)
		this->leftSite = null();
		HX_STACK_LINE(255)
		this->rightSite = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,init,(void))

Void Edge_obj::dispose( ){
{
		HX_STACK_PUSH("Edge::dispose","com/nodename/delaunay/Edge.hx",225);
		HX_STACK_THIS(this);
		HX_STACK_LINE(226)
		if (((this->_delaunayLineBmp != null()))){
			HX_STACK_LINE(228)
			this->_delaunayLineBmp->dispose();
			HX_STACK_LINE(229)
			this->_delaunayLineBmp = null();
		}
		HX_STACK_LINE(231)
		this->leftVertex = null();
		HX_STACK_LINE(232)
		this->rightVertex = null();
		HX_STACK_LINE(233)
		if (((this->clippedEnds != null()))){
			HX_STACK_LINE(235)
			this->clippedEnds->set(::com::nodename::delaunay::LR_obj::LEFT->toString(),null());
			HX_STACK_LINE(236)
			this->clippedEnds->set(::com::nodename::delaunay::LR_obj::RIGHT->toString(),null());
			HX_STACK_LINE(237)
			this->clippedEnds = null();
		}
		HX_STACK_LINE(240)
		this->leftSite = null();
		HX_STACK_LINE(241)
		this->rightSite = null();
		HX_STACK_LINE(243)
		::com::nodename::delaunay::Edge_obj::_pool->push(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,dispose,(void))

::com::nodename::delaunay::Site Edge_obj::site( ::com::nodename::delaunay::LR leftRight){
	HX_STACK_PUSH("Edge::site","com/nodename/delaunay/Edge.hx",218);
	HX_STACK_THIS(this);
	HX_STACK_ARG(leftRight,"leftRight");
	HX_STACK_LINE(218)
	return (  (((leftRight == ::com::nodename::delaunay::LR_obj::LEFT))) ? ::com::nodename::delaunay::Site(this->leftSite) : ::com::nodename::delaunay::Site(this->rightSite) );
}


HX_DEFINE_DYNAMIC_FUNC1(Edge_obj,site,return )

bool Edge_obj::getVisible( ){
	HX_STACK_PUSH("Edge::getVisible","com/nodename/delaunay/Edge.hx",207);
	HX_STACK_THIS(this);
	HX_STACK_LINE(207)
	return (this->clippedEnds != null());
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,getVisible,return )

Float Edge_obj::sitesDistance( ){
	HX_STACK_PUSH("Edge::sitesDistance","com/nodename/delaunay/Edge.hx",175);
	HX_STACK_THIS(this);
	HX_STACK_LINE(175)
	return ::neash::geom::Point_obj::distance(this->leftSite->_coord,this->rightSite->_coord);
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,sitesDistance,return )

bool Edge_obj::isPartOfConvexHull( ){
	HX_STACK_PUSH("Edge::isPartOfConvexHull","com/nodename/delaunay/Edge.hx",170);
	HX_STACK_THIS(this);
	HX_STACK_LINE(170)
	return (bool((this->leftVertex == null())) || bool((this->rightVertex == null())));
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,isPartOfConvexHull,return )

Void Edge_obj::setVertex( ::com::nodename::delaunay::LR leftRight,::com::nodename::delaunay::Vertex v){
{
		HX_STACK_PUSH("Edge::setVertex","com/nodename/delaunay/Edge.hx",158);
		HX_STACK_THIS(this);
		HX_STACK_ARG(leftRight,"leftRight");
		HX_STACK_ARG(v,"v");
		HX_STACK_LINE(158)
		if (((leftRight == ::com::nodename::delaunay::LR_obj::LEFT))){
			HX_STACK_LINE(160)
			this->leftVertex = v;
		}
		else{
			HX_STACK_LINE(164)
			this->rightVertex = v;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Edge_obj,setVertex,(void))

::com::nodename::delaunay::Vertex Edge_obj::vertex( ::com::nodename::delaunay::LR leftRight){
	HX_STACK_PUSH("Edge::vertex","com/nodename/delaunay/Edge.hx",153);
	HX_STACK_THIS(this);
	HX_STACK_ARG(leftRight,"leftRight");
	HX_STACK_LINE(153)
	return (  (((leftRight == ::com::nodename::delaunay::LR_obj::LEFT))) ? ::com::nodename::delaunay::Vertex(this->leftVertex) : ::com::nodename::delaunay::Vertex(this->rightVertex) );
}


HX_DEFINE_DYNAMIC_FUNC1(Edge_obj,vertex,return )

::com::nodename::geom::LineSegment Edge_obj::voronoiEdge( ){
	HX_STACK_PUSH("Edge::voronoiEdge","com/nodename/delaunay/Edge.hx",133);
	HX_STACK_THIS(this);
	HX_STACK_LINE(134)
	if ((!(((this->clippedEnds != null()))))){
		HX_STACK_LINE(134)
		return ::com::nodename::geom::LineSegment_obj::__new(null(),null());
	}
	HX_STACK_LINE(135)
	return ::com::nodename::geom::LineSegment_obj::__new(this->clippedEnds->get(::com::nodename::delaunay::LR_obj::LEFT->toString()),this->clippedEnds->get(::com::nodename::delaunay::LR_obj::RIGHT->toString()));
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,voronoiEdge,return )

::com::nodename::geom::LineSegment Edge_obj::delaunayLine( ){
	HX_STACK_PUSH("Edge::delaunayLine","com/nodename/delaunay/Edge.hx",127);
	HX_STACK_THIS(this);
	HX_STACK_LINE(127)
	return ::com::nodename::geom::LineSegment_obj::__new(this->leftSite->_coord,this->rightSite->_coord);
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,delaunayLine,return )

::neash::display::BitmapData Edge_obj::makeDelaunayLineBmp( ){
	HX_STACK_PUSH("Edge::makeDelaunayLineBmp","com/nodename/delaunay/Edge.hx",95);
	HX_STACK_THIS(this);
	HX_STACK_LINE(98)
	::neash::geom::Point p0 = this->leftSite->_coord;		HX_STACK_VAR(p0,"p0");
	HX_STACK_LINE(99)
	::neash::geom::Point p1 = this->rightSite->_coord;		HX_STACK_VAR(p1,"p1");
	HX_STACK_LINE(101)
	int w = ::Std_obj::_int(::Math_obj::ceil(::Math_obj::max(p0->x,p1->x)));		HX_STACK_VAR(w,"w");
	HX_STACK_LINE(102)
	if (((w < (int)1))){
		HX_STACK_LINE(103)
		w = (int)1;
	}
	HX_STACK_LINE(106)
	int h = ::Std_obj::_int(::Math_obj::ceil(::Math_obj::max(p0->y,p1->y)));		HX_STACK_VAR(h,"h");
	HX_STACK_LINE(107)
	if (((h < (int)1))){
		HX_STACK_LINE(108)
		h = (int)1;
	}
	HX_STACK_LINE(111)
	::neash::display::BitmapData bmp = ::neash::display::BitmapData_obj::__new(w,h,true,(int)0);		HX_STACK_VAR(bmp,"bmp");
	HX_STACK_LINE(114)
	::com::nodename::delaunay::Edge_obj::GRAPHICS->clear();
	HX_STACK_LINE(116)
	::com::nodename::delaunay::Edge_obj::GRAPHICS->lineStyle((int)0,(int)0,1.0,false,::neash::display::LineScaleMode_obj::NONE_dyn(),::neash::display::CapsStyle_obj::NONE_dyn(),null(),null());
	HX_STACK_LINE(117)
	::com::nodename::delaunay::Edge_obj::GRAPHICS->moveTo(p0->x,p0->y);
	HX_STACK_LINE(118)
	::com::nodename::delaunay::Edge_obj::GRAPHICS->lineTo(p1->x,p1->y);
	HX_STACK_LINE(122)
	bmp->draw(::com::nodename::delaunay::Edge_obj::LINESPRITE,null(),null(),null(),null(),null());
	HX_STACK_LINE(123)
	return bmp;
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,makeDelaunayLineBmp,return )

::neash::display::BitmapData Edge_obj::getDelaunayLineBmp( ){
	HX_STACK_PUSH("Edge::getDelaunayLineBmp","com/nodename/delaunay/Edge.hx",85);
	HX_STACK_THIS(this);
	HX_STACK_LINE(86)
	if (((this->_delaunayLineBmp == null()))){
		HX_STACK_LINE(87)
		this->_delaunayLineBmp = this->makeDelaunayLineBmp();
	}
	HX_STACK_LINE(90)
	return this->_delaunayLineBmp;
}


HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,getDelaunayLineBmp,return )

Array< ::com::nodename::delaunay::Edge > Edge_obj::_pool;

::com::nodename::delaunay::Edge Edge_obj::createBisectingEdge( ::com::nodename::delaunay::Site site0,::com::nodename::delaunay::Site site1){
	HX_STACK_PUSH("Edge::createBisectingEdge","com/nodename/delaunay/Edge.hx",30);
	HX_STACK_ARG(site0,"site0");
	HX_STACK_ARG(site1,"site1");
	HX_STACK_LINE(31)
	Float dx;		HX_STACK_VAR(dx,"dx");
	Float dy;		HX_STACK_VAR(dy,"dy");
	Float absdx;		HX_STACK_VAR(absdx,"absdx");
	Float absdy;		HX_STACK_VAR(absdy,"absdy");
	HX_STACK_LINE(32)
	Float a;		HX_STACK_VAR(a,"a");
	Float b;		HX_STACK_VAR(b,"b");
	Float c;		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(34)
	dx = (site1->_coord->x - site0->_coord->x);
	HX_STACK_LINE(35)
	dy = (site1->_coord->y - site0->_coord->y);
	HX_STACK_LINE(36)
	absdx = (  (((dx > (int)0))) ? Float(dx) : Float(-(dx)) );
	HX_STACK_LINE(37)
	absdy = (  (((dy > (int)0))) ? Float(dy) : Float(-(dy)) );
	HX_STACK_LINE(38)
	c = (((site0->_coord->x * dx) + (site0->_coord->y * dy)) + ((((dx * dx) + (dy * dy))) * 0.5));
	HX_STACK_LINE(39)
	if (((absdx > absdy))){
		HX_STACK_LINE(41)
		a = 1.0;
		HX_STACK_LINE(41)
		b = (Float(dy) / Float(dx));
		HX_STACK_LINE(41)
		hx::DivEq(c,dx);
	}
	else{
		HX_STACK_LINE(45)
		b = 1.0;
		HX_STACK_LINE(45)
		a = (Float(dx) / Float(dy));
		HX_STACK_LINE(45)
		hx::DivEq(c,dy);
	}
	HX_STACK_LINE(48)
	::com::nodename::delaunay::Edge edge = ::com::nodename::delaunay::Edge_obj::create();		HX_STACK_VAR(edge,"edge");
	HX_STACK_LINE(50)
	edge->leftSite = site0;
	HX_STACK_LINE(51)
	edge->rightSite = site1;
	HX_STACK_LINE(52)
	site0->addEdge(edge);
	HX_STACK_LINE(53)
	site1->addEdge(edge);
	HX_STACK_LINE(55)
	edge->leftVertex = null();
	HX_STACK_LINE(56)
	edge->rightVertex = null();
	HX_STACK_LINE(58)
	edge->a = a;
	HX_STACK_LINE(58)
	edge->b = b;
	HX_STACK_LINE(58)
	edge->c = c;
	HX_STACK_LINE(61)
	return edge;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Edge_obj,createBisectingEdge,return )

::com::nodename::delaunay::Edge Edge_obj::create( ){
	HX_STACK_PUSH("Edge::create","com/nodename/delaunay/Edge.hx",65);
	HX_STACK_LINE(66)
	::com::nodename::delaunay::Edge edge;		HX_STACK_VAR(edge,"edge");
	HX_STACK_LINE(67)
	if (((::com::nodename::delaunay::Edge_obj::_pool->length > (int)0))){
		HX_STACK_LINE(69)
		edge = ::com::nodename::delaunay::Edge_obj::_pool->pop();
		HX_STACK_LINE(70)
		edge->init();
	}
	else{
		HX_STACK_LINE(73)
		edge = ::com::nodename::delaunay::Edge_obj::__new();
	}
	HX_STACK_LINE(76)
	return edge;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Edge_obj,create,return )

::neash::display::Sprite Edge_obj::LINESPRITE;

::neash::display::Graphics Edge_obj::GRAPHICS;

int Edge_obj::_nedges;

::com::nodename::delaunay::Edge Edge_obj::DELETED;

int Edge_obj::compareSitesDistances_MAX( ::com::nodename::delaunay::Edge edge0,::com::nodename::delaunay::Edge edge1){
	HX_STACK_PUSH("Edge::compareSitesDistances_MAX","com/nodename/delaunay/Edge.hx",180);
	HX_STACK_ARG(edge0,"edge0");
	HX_STACK_ARG(edge1,"edge1");
	HX_STACK_LINE(181)
	Float length0 = edge0->sitesDistance();		HX_STACK_VAR(length0,"length0");
	HX_STACK_LINE(182)
	Float length1 = edge1->sitesDistance();		HX_STACK_VAR(length1,"length1");
	HX_STACK_LINE(183)
	if (((length0 < length1))){
		HX_STACK_LINE(184)
		return (int)1;
	}
	HX_STACK_LINE(187)
	if (((length0 > length1))){
		HX_STACK_LINE(188)
		return (int)-1;
	}
	HX_STACK_LINE(191)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Edge_obj,compareSitesDistances_MAX,return )

int Edge_obj::compareSitesDistances( ::com::nodename::delaunay::Edge edge0,::com::nodename::delaunay::Edge edge1){
	HX_STACK_PUSH("Edge::compareSitesDistances","com/nodename/delaunay/Edge.hx",195);
	HX_STACK_ARG(edge0,"edge0");
	HX_STACK_ARG(edge1,"edge1");
	HX_STACK_LINE(195)
	return -(::com::nodename::delaunay::Edge_obj::compareSitesDistances_MAX(edge0,edge1));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Edge_obj,compareSitesDistances,return )


Edge_obj::Edge_obj()
{
}

void Edge_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Edge);
	HX_MARK_MEMBER_NAME(_edgeIndex,"_edgeIndex");
	HX_MARK_MEMBER_NAME(rightSite,"rightSite");
	HX_MARK_MEMBER_NAME(leftSite,"leftSite");
	HX_MARK_MEMBER_NAME(visible,"visible");
	HX_MARK_MEMBER_NAME(clippedEnds,"clippedEnds");
	HX_MARK_MEMBER_NAME(rightVertex,"rightVertex");
	HX_MARK_MEMBER_NAME(leftVertex,"leftVertex");
	HX_MARK_MEMBER_NAME(c,"c");
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_MEMBER_NAME(a,"a");
	HX_MARK_MEMBER_NAME(_delaunayLineBmp,"_delaunayLineBmp");
	HX_MARK_MEMBER_NAME(delaunayLineBmp,"delaunayLineBmp");
	HX_MARK_END_CLASS();
}

void Edge_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_edgeIndex,"_edgeIndex");
	HX_VISIT_MEMBER_NAME(rightSite,"rightSite");
	HX_VISIT_MEMBER_NAME(leftSite,"leftSite");
	HX_VISIT_MEMBER_NAME(visible,"visible");
	HX_VISIT_MEMBER_NAME(clippedEnds,"clippedEnds");
	HX_VISIT_MEMBER_NAME(rightVertex,"rightVertex");
	HX_VISIT_MEMBER_NAME(leftVertex,"leftVertex");
	HX_VISIT_MEMBER_NAME(c,"c");
	HX_VISIT_MEMBER_NAME(b,"b");
	HX_VISIT_MEMBER_NAME(a,"a");
	HX_VISIT_MEMBER_NAME(_delaunayLineBmp,"_delaunayLineBmp");
	HX_VISIT_MEMBER_NAME(delaunayLineBmp,"delaunayLineBmp");
}

Dynamic Edge_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"c") ) { return c; }
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		if (HX_FIELD_EQ(inName,"a") ) { return a; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"site") ) { return site_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_pool") ) { return _pool; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"vertex") ) { return vertex_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_nedges") ) { return _nedges; }
		if (HX_FIELD_EQ(inName,"DELETED") ) { return DELETED; }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"visible") ) { return inCallProp ? getVisible() : visible; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"GRAPHICS") ) { return GRAPHICS; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"leftSite") ) { return leftSite; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"rightSite") ) { return rightSite; }
		if (HX_FIELD_EQ(inName,"setVertex") ) { return setVertex_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"LINESPRITE") ) { return LINESPRITE; }
		if (HX_FIELD_EQ(inName,"_edgeIndex") ) { return _edgeIndex; }
		if (HX_FIELD_EQ(inName,"getVisible") ) { return getVisible_dyn(); }
		if (HX_FIELD_EQ(inName,"leftVertex") ) { return leftVertex; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"clippedEnds") ) { return clippedEnds; }
		if (HX_FIELD_EQ(inName,"rightVertex") ) { return rightVertex; }
		if (HX_FIELD_EQ(inName,"voronoiEdge") ) { return voronoiEdge_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"clipVertices") ) { return clipVertices_dyn(); }
		if (HX_FIELD_EQ(inName,"delaunayLine") ) { return delaunayLine_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"sitesDistance") ) { return sitesDistance_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"delaunayLineBmp") ) { return inCallProp ? getDelaunayLineBmp() : delaunayLineBmp; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_delaunayLineBmp") ) { return _delaunayLineBmp; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"isPartOfConvexHull") ) { return isPartOfConvexHull_dyn(); }
		if (HX_FIELD_EQ(inName,"getDelaunayLineBmp") ) { return getDelaunayLineBmp_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"createBisectingEdge") ) { return createBisectingEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"makeDelaunayLineBmp") ) { return makeDelaunayLineBmp_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"compareSitesDistances") ) { return compareSitesDistances_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"compareSitesDistances_MAX") ) { return compareSitesDistances_MAX_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Edge_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"c") ) { c=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"a") ) { a=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_pool") ) { _pool=inValue.Cast< Array< ::com::nodename::delaunay::Edge > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_nedges") ) { _nedges=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DELETED") ) { DELETED=inValue.Cast< ::com::nodename::delaunay::Edge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"visible") ) { visible=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"GRAPHICS") ) { GRAPHICS=inValue.Cast< ::neash::display::Graphics >(); return inValue; }
		if (HX_FIELD_EQ(inName,"leftSite") ) { leftSite=inValue.Cast< ::com::nodename::delaunay::Site >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"rightSite") ) { rightSite=inValue.Cast< ::com::nodename::delaunay::Site >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"LINESPRITE") ) { LINESPRITE=inValue.Cast< ::neash::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_edgeIndex") ) { _edgeIndex=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"leftVertex") ) { leftVertex=inValue.Cast< ::com::nodename::delaunay::Vertex >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"clippedEnds") ) { clippedEnds=inValue.Cast< ::Hash >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rightVertex") ) { rightVertex=inValue.Cast< ::com::nodename::delaunay::Vertex >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"delaunayLineBmp") ) { delaunayLineBmp=inValue.Cast< ::neash::display::BitmapData >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_delaunayLineBmp") ) { _delaunayLineBmp=inValue.Cast< ::neash::display::BitmapData >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Edge_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_edgeIndex"));
	outFields->push(HX_CSTRING("rightSite"));
	outFields->push(HX_CSTRING("leftSite"));
	outFields->push(HX_CSTRING("visible"));
	outFields->push(HX_CSTRING("clippedEnds"));
	outFields->push(HX_CSTRING("rightVertex"));
	outFields->push(HX_CSTRING("leftVertex"));
	outFields->push(HX_CSTRING("c"));
	outFields->push(HX_CSTRING("b"));
	outFields->push(HX_CSTRING("a"));
	outFields->push(HX_CSTRING("_delaunayLineBmp"));
	outFields->push(HX_CSTRING("delaunayLineBmp"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_pool"),
	HX_CSTRING("createBisectingEdge"),
	HX_CSTRING("create"),
	HX_CSTRING("LINESPRITE"),
	HX_CSTRING("GRAPHICS"),
	HX_CSTRING("_nedges"),
	HX_CSTRING("DELETED"),
	HX_CSTRING("compareSitesDistances_MAX"),
	HX_CSTRING("compareSitesDistances"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("clipVertices"),
	HX_CSTRING("toString"),
	HX_CSTRING("init"),
	HX_CSTRING("dispose"),
	HX_CSTRING("_edgeIndex"),
	HX_CSTRING("site"),
	HX_CSTRING("rightSite"),
	HX_CSTRING("leftSite"),
	HX_CSTRING("getVisible"),
	HX_CSTRING("visible"),
	HX_CSTRING("clippedEnds"),
	HX_CSTRING("sitesDistance"),
	HX_CSTRING("isPartOfConvexHull"),
	HX_CSTRING("setVertex"),
	HX_CSTRING("vertex"),
	HX_CSTRING("rightVertex"),
	HX_CSTRING("leftVertex"),
	HX_CSTRING("c"),
	HX_CSTRING("b"),
	HX_CSTRING("a"),
	HX_CSTRING("voronoiEdge"),
	HX_CSTRING("delaunayLine"),
	HX_CSTRING("makeDelaunayLineBmp"),
	HX_CSTRING("getDelaunayLineBmp"),
	HX_CSTRING("_delaunayLineBmp"),
	HX_CSTRING("delaunayLineBmp"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Edge_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Edge_obj::_pool,"_pool");
	HX_MARK_MEMBER_NAME(Edge_obj::LINESPRITE,"LINESPRITE");
	HX_MARK_MEMBER_NAME(Edge_obj::GRAPHICS,"GRAPHICS");
	HX_MARK_MEMBER_NAME(Edge_obj::_nedges,"_nedges");
	HX_MARK_MEMBER_NAME(Edge_obj::DELETED,"DELETED");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Edge_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Edge_obj::_pool,"_pool");
	HX_VISIT_MEMBER_NAME(Edge_obj::LINESPRITE,"LINESPRITE");
	HX_VISIT_MEMBER_NAME(Edge_obj::GRAPHICS,"GRAPHICS");
	HX_VISIT_MEMBER_NAME(Edge_obj::_nedges,"_nedges");
	HX_VISIT_MEMBER_NAME(Edge_obj::DELETED,"DELETED");
};

Class Edge_obj::__mClass;

void Edge_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.delaunay.Edge"), hx::TCanCast< Edge_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Edge_obj::__boot()
{
	_pool= Array_obj< ::com::nodename::delaunay::Edge >::__new();
	LINESPRITE= ::neash::display::Sprite_obj::__new();
	GRAPHICS= ::com::nodename::delaunay::Edge_obj::LINESPRITE->nmeGetGraphics();
	_nedges= (int)0;
	DELETED= ::com::nodename::delaunay::Edge_obj::__new();
}

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

#include <hxcpp.h>

#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Criterion
#include <com/nodename/delaunay/Criterion.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Delaunay
#include <com/nodename/delaunay/Delaunay.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Edge
#include <com/nodename/delaunay/Edge.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_EdgeList
#include <com/nodename/delaunay/EdgeList.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_EdgeReorderer
#include <com/nodename/delaunay/EdgeReorderer.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Halfedge
#include <com/nodename/delaunay/Halfedge.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_HalfedgePriorityQueue
#include <com/nodename/delaunay/HalfedgePriorityQueue.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_ICoord
#include <com/nodename/delaunay/ICoord.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Kruskal
#include <com/nodename/delaunay/Kruskal.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_LR
#include <com/nodename/delaunay/LR.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Site
#include <com/nodename/delaunay/Site.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_SiteList
#include <com/nodename/delaunay/SiteList.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Triangle
#include <com/nodename/delaunay/Triangle.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Vertex
#include <com/nodename/delaunay/Vertex.h>
#endif
#ifndef INCLUDED_com_nodename_delaunay_Voronoi
#include <com/nodename/delaunay/Voronoi.h>
#endif
#ifndef INCLUDED_com_nodename_geom_Circle
#include <com/nodename/geom/Circle.h>
#endif
#ifndef INCLUDED_com_nodename_geom_LineSegment
#include <com/nodename/geom/LineSegment.h>
#endif
#ifndef INCLUDED_com_nodename_utils_IDisposable
#include <com/nodename/utils/IDisposable.h>
#endif
#ifndef INCLUDED_de_polygonal_math_PM_PRNG
#include <de/polygonal/math/PM_PRNG.h>
#endif
#ifndef INCLUDED_neash_display_BitmapData
#include <neash/display/BitmapData.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
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
namespace com{
namespace nodename{
namespace delaunay{

Void Voronoi_obj::__construct(Array< ::neash::geom::Point > points,Array< int > colors,::neash::geom::Rectangle plotBounds)
{
HX_STACK_PUSH("Voronoi::new","com/nodename/delaunay/Voronoi.hx",63);
{
	HX_STACK_LINE(65)
	(this->_prng = ::de::polygonal::math::PM_PRNG_obj::__new())->seed = (int)1;
	HX_STACK_LINE(66)
	this->_sites = ::com::nodename::delaunay::SiteList_obj::__new();
	HX_STACK_LINE(67)
	this->_sitesIndexedByLocation = ::nme::ObjectHash_obj::__new();
	HX_STACK_LINE(68)
	this->addSites(points,colors);
	HX_STACK_LINE(69)
	this->plotBounds = plotBounds;
	HX_STACK_LINE(70)
	this->_triangles = Array_obj< ::com::nodename::delaunay::Triangle >::__new();
	HX_STACK_LINE(71)
	this->_edges = Array_obj< ::com::nodename::delaunay::Edge >::__new();
	HX_STACK_LINE(72)
	this->fortunesAlgorithm();
}
;
	return null();
}

Voronoi_obj::~Voronoi_obj() { }

Dynamic Voronoi_obj::__CreateEmpty() { return  new Voronoi_obj; }
hx::ObjectPtr< Voronoi_obj > Voronoi_obj::__new(Array< ::neash::geom::Point > points,Array< int > colors,::neash::geom::Rectangle plotBounds)
{  hx::ObjectPtr< Voronoi_obj > result = new Voronoi_obj();
	result->__construct(points,colors,plotBounds);
	return result;}

Dynamic Voronoi_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Voronoi_obj > result = new Voronoi_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Voronoi_obj::fortunesAlgorithm( ){
{
		HX_STACK_PUSH("Voronoi::fortunesAlgorithm","com/nodename/delaunay/Voronoi.hx",241);
		HX_STACK_THIS(this);
		HX_STACK_LINE(242)
		::com::nodename::delaunay::Site newSite;		HX_STACK_VAR(newSite,"newSite");
		::com::nodename::delaunay::Site bottomSite;		HX_STACK_VAR(bottomSite,"bottomSite");
		::com::nodename::delaunay::Site topSite;		HX_STACK_VAR(topSite,"topSite");
		::com::nodename::delaunay::Site tempSite;		HX_STACK_VAR(tempSite,"tempSite");
		HX_STACK_LINE(243)
		::com::nodename::delaunay::Vertex v;		HX_STACK_VAR(v,"v");
		::com::nodename::delaunay::Vertex vertex;		HX_STACK_VAR(vertex,"vertex");
		HX_STACK_LINE(244)
		::neash::geom::Point newintstar;		HX_STACK_VAR(newintstar,"newintstar");
		HX_STACK_LINE(245)
		::com::nodename::delaunay::LR leftRight;		HX_STACK_VAR(leftRight,"leftRight");
		HX_STACK_LINE(246)
		::com::nodename::delaunay::Halfedge lbnd;		HX_STACK_VAR(lbnd,"lbnd");
		::com::nodename::delaunay::Halfedge rbnd;		HX_STACK_VAR(rbnd,"rbnd");
		::com::nodename::delaunay::Halfedge llbnd;		HX_STACK_VAR(llbnd,"llbnd");
		::com::nodename::delaunay::Halfedge rrbnd;		HX_STACK_VAR(rrbnd,"rrbnd");
		::com::nodename::delaunay::Halfedge bisector;		HX_STACK_VAR(bisector,"bisector");
		HX_STACK_LINE(247)
		::com::nodename::delaunay::Edge edge;		HX_STACK_VAR(edge,"edge");
		HX_STACK_LINE(249)
		::neash::geom::Rectangle dataBounds = this->_sites->getSitesBounds();		HX_STACK_VAR(dataBounds,"dataBounds");
		HX_STACK_LINE(251)
		int sqrt_nsites = ::Std_obj::_int(::Math_obj::sqrt((this->_sites->_sites->length + (int)4)));		HX_STACK_VAR(sqrt_nsites,"sqrt_nsites");
		HX_STACK_LINE(252)
		::com::nodename::delaunay::HalfedgePriorityQueue heap = ::com::nodename::delaunay::HalfedgePriorityQueue_obj::__new(dataBounds->y,dataBounds->height,sqrt_nsites);		HX_STACK_VAR(heap,"heap");
		HX_STACK_LINE(253)
		::com::nodename::delaunay::EdgeList edgeList = ::com::nodename::delaunay::EdgeList_obj::__new(dataBounds->x,dataBounds->width,sqrt_nsites);		HX_STACK_VAR(edgeList,"edgeList");
		HX_STACK_LINE(254)
		Array< ::com::nodename::delaunay::Halfedge > halfEdges = Array_obj< ::com::nodename::delaunay::Halfedge >::__new();		HX_STACK_VAR(halfEdges,"halfEdges");
		HX_STACK_LINE(255)
		Array< ::com::nodename::delaunay::Vertex > vertices = Array_obj< ::com::nodename::delaunay::Vertex >::__new();		HX_STACK_VAR(vertices,"vertices");
		HX_STACK_LINE(257)
		Array< ::com::nodename::delaunay::Site > bottomMostSite = Array_obj< ::com::nodename::delaunay::Site >::__new().Add(this->_sites->next());		HX_STACK_VAR(bottomMostSite,"bottomMostSite");
		HX_STACK_LINE(258)
		newSite = this->_sites->next();

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::com::nodename::delaunay::Site >,bottomMostSite)
		::com::nodename::delaunay::Site run(::com::nodename::delaunay::Halfedge he){
			HX_STACK_PUSH("*::_Function_1_1","com/nodename/delaunay/Voronoi.hx",261);
			HX_STACK_ARG(he,"he");
			{
				HX_STACK_LINE(262)
				::com::nodename::delaunay::Edge edge1 = he->edge;		HX_STACK_VAR(edge1,"edge1");
				HX_STACK_LINE(263)
				if (((edge1 == null()))){
					HX_STACK_LINE(264)
					return bottomMostSite->__get((int)0);
				}
				HX_STACK_LINE(267)
				return edge1->site(he->leftRight);
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(260)
		Dynamic leftRegion =  Dynamic(new _Function_1_1(bottomMostSite));		HX_STACK_VAR(leftRegion,"leftRegion");

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_2,Array< ::com::nodename::delaunay::Site >,bottomMostSite)
		::com::nodename::delaunay::Site run(::com::nodename::delaunay::Halfedge he){
			HX_STACK_PUSH("*::_Function_1_2","com/nodename/delaunay/Voronoi.hx",271);
			HX_STACK_ARG(he,"he");
			{
				HX_STACK_LINE(272)
				::com::nodename::delaunay::Edge edge1 = he->edge;		HX_STACK_VAR(edge1,"edge1");
				HX_STACK_LINE(273)
				if (((edge1 == null()))){
					HX_STACK_LINE(274)
					return bottomMostSite->__get((int)0);
				}
				HX_STACK_LINE(277)
				return edge1->site(::com::nodename::delaunay::LR_obj::other(he->leftRight));
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(270)
		Dynamic rightRegion =  Dynamic(new _Function_1_2(bottomMostSite));		HX_STACK_VAR(rightRegion,"rightRegion");
		HX_STACK_LINE(280)
		while((true)){
			HX_STACK_LINE(282)
			if (((heap->empty() == false))){
				HX_STACK_LINE(283)
				newintstar = heap->min();
			}
			HX_STACK_LINE(287)
			if (((bool((newSite != null())) && bool(((bool(heap->empty()) || bool((::com::nodename::delaunay::Voronoi_obj::comparePointByYThenX(newSite,newintstar) < (int)0)))))))){
				HX_STACK_LINE(294)
				lbnd = edgeList->edgeListLeftNeighbor(newSite->_coord);
				HX_STACK_LINE(296)
				rbnd = lbnd->edgeListRightNeighbor;
				HX_STACK_LINE(298)
				bottomSite = rightRegion(lbnd).Cast< ::com::nodename::delaunay::Site >();
				HX_STACK_LINE(303)
				edge = ::com::nodename::delaunay::Edge_obj::createBisectingEdge(bottomSite,newSite);
				HX_STACK_LINE(305)
				this->_edges->push(edge);
				HX_STACK_LINE(307)
				bisector = ::com::nodename::delaunay::Halfedge_obj::create(edge,::com::nodename::delaunay::LR_obj::LEFT);
				HX_STACK_LINE(308)
				halfEdges->push(bisector);
				HX_STACK_LINE(311)
				edgeList->insert(lbnd,bisector);
				HX_STACK_LINE(314)
				vertex = ::com::nodename::delaunay::Vertex_obj::intersect(lbnd,bisector);
				HX_STACK_LINE(315)
				if (((vertex != null()))){
					HX_STACK_LINE(317)
					vertices->push(vertex);
					HX_STACK_LINE(318)
					heap->remove(lbnd);
					HX_STACK_LINE(319)
					lbnd->vertex = vertex;
					HX_STACK_LINE(320)
					lbnd->ystar = (vertex->_coord->y + newSite->dist(vertex));
					HX_STACK_LINE(321)
					heap->insert(lbnd);
				}
				HX_STACK_LINE(324)
				lbnd = bisector;
				HX_STACK_LINE(325)
				bisector = ::com::nodename::delaunay::Halfedge_obj::create(edge,::com::nodename::delaunay::LR_obj::RIGHT);
				HX_STACK_LINE(326)
				halfEdges->push(bisector);
				HX_STACK_LINE(329)
				edgeList->insert(lbnd,bisector);
				HX_STACK_LINE(332)
				vertex = ::com::nodename::delaunay::Vertex_obj::intersect(bisector,rbnd);
				HX_STACK_LINE(333)
				if (((vertex != null()))){
					HX_STACK_LINE(335)
					vertices->push(vertex);
					HX_STACK_LINE(336)
					bisector->vertex = vertex;
					HX_STACK_LINE(337)
					bisector->ystar = (vertex->_coord->y + newSite->dist(vertex));
					HX_STACK_LINE(338)
					heap->insert(bisector);
				}
				HX_STACK_LINE(341)
				newSite = this->_sites->next();
			}
			else{
				HX_STACK_LINE(343)
				if (((heap->empty() == false))){
					HX_STACK_LINE(346)
					lbnd = heap->extractMin();
					HX_STACK_LINE(347)
					llbnd = lbnd->edgeListLeftNeighbor;
					HX_STACK_LINE(348)
					rbnd = lbnd->edgeListRightNeighbor;
					HX_STACK_LINE(349)
					rrbnd = rbnd->edgeListRightNeighbor;
					HX_STACK_LINE(350)
					bottomSite = leftRegion(lbnd).Cast< ::com::nodename::delaunay::Site >();
					HX_STACK_LINE(351)
					topSite = rightRegion(rbnd).Cast< ::com::nodename::delaunay::Site >();
					HX_STACK_LINE(356)
					v = lbnd->vertex;
					HX_STACK_LINE(357)
					v->setIndex();
					HX_STACK_LINE(358)
					lbnd->edge->setVertex(lbnd->leftRight,v);
					HX_STACK_LINE(359)
					rbnd->edge->setVertex(rbnd->leftRight,v);
					HX_STACK_LINE(360)
					edgeList->remove(lbnd);
					HX_STACK_LINE(361)
					heap->remove(rbnd);
					HX_STACK_LINE(362)
					edgeList->remove(rbnd);
					HX_STACK_LINE(363)
					leftRight = ::com::nodename::delaunay::LR_obj::LEFT;
					HX_STACK_LINE(364)
					if (((bottomSite->_coord->y > topSite->_coord->y))){
						HX_STACK_LINE(366)
						tempSite = bottomSite;
						HX_STACK_LINE(366)
						bottomSite = topSite;
						HX_STACK_LINE(366)
						topSite = tempSite;
						HX_STACK_LINE(366)
						leftRight = ::com::nodename::delaunay::LR_obj::RIGHT;
					}
					HX_STACK_LINE(368)
					edge = ::com::nodename::delaunay::Edge_obj::createBisectingEdge(bottomSite,topSite);
					HX_STACK_LINE(369)
					this->_edges->push(edge);
					HX_STACK_LINE(370)
					bisector = ::com::nodename::delaunay::Halfedge_obj::create(edge,leftRight);
					HX_STACK_LINE(371)
					halfEdges->push(bisector);
					HX_STACK_LINE(372)
					edgeList->insert(llbnd,bisector);
					HX_STACK_LINE(373)
					edge->setVertex(::com::nodename::delaunay::LR_obj::other(leftRight),v);
					HX_STACK_LINE(374)
					if ((((vertex = ::com::nodename::delaunay::Vertex_obj::intersect(llbnd,bisector)) != null()))){
						HX_STACK_LINE(376)
						vertices->push(vertex);
						HX_STACK_LINE(377)
						heap->remove(llbnd);
						HX_STACK_LINE(378)
						llbnd->vertex = vertex;
						HX_STACK_LINE(379)
						llbnd->ystar = (vertex->_coord->y + bottomSite->dist(vertex));
						HX_STACK_LINE(380)
						heap->insert(llbnd);
					}
					HX_STACK_LINE(382)
					if ((((vertex = ::com::nodename::delaunay::Vertex_obj::intersect(bisector,rrbnd)) != null()))){
						HX_STACK_LINE(384)
						vertices->push(vertex);
						HX_STACK_LINE(385)
						bisector->vertex = vertex;
						HX_STACK_LINE(386)
						bisector->ystar = (vertex->_coord->y + bottomSite->dist(vertex));
						HX_STACK_LINE(387)
						heap->insert(bisector);
					}
				}
				else{
					HX_STACK_LINE(391)
					break;
				}
			}
		}
		HX_STACK_LINE(397)
		heap->dispose();
		HX_STACK_LINE(398)
		edgeList->dispose();
		HX_STACK_LINE(400)
		{
			HX_STACK_LINE(400)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(400)
			while(((_g < halfEdges->length))){
				HX_STACK_LINE(400)
				::com::nodename::delaunay::Halfedge halfEdge = halfEdges->__get(_g);		HX_STACK_VAR(halfEdge,"halfEdge");
				HX_STACK_LINE(400)
				++(_g);
				HX_STACK_LINE(402)
				halfEdge->reallyDispose();
			}
		}
		HX_STACK_LINE(407)
		{
			HX_STACK_LINE(407)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::com::nodename::delaunay::Edge > _g1 = this->_edges;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(407)
			while(((_g < _g1->length))){
				HX_STACK_LINE(407)
				::com::nodename::delaunay::Edge edge1 = _g1->__get(_g);		HX_STACK_VAR(edge1,"edge1");
				HX_STACK_LINE(407)
				++(_g);
				HX_STACK_LINE(409)
				edge1->clipVertices(this->plotBounds);
			}
		}
		HX_STACK_LINE(412)
		{
			HX_STACK_LINE(412)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(412)
			while(((_g < vertices->length))){
				HX_STACK_LINE(412)
				::com::nodename::delaunay::Vertex vertex1 = vertices->__get(_g);		HX_STACK_VAR(vertex1,"vertex1");
				HX_STACK_LINE(412)
				++(_g);
				HX_STACK_LINE(414)
				vertex1->dispose();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Voronoi_obj,fortunesAlgorithm,(void))

Array< ::neash::geom::Point > Voronoi_obj::siteCoords( ){
	HX_STACK_PUSH("Voronoi::siteCoords","com/nodename/delaunay/Voronoi.hx",236);
	HX_STACK_THIS(this);
	HX_STACK_LINE(236)
	return this->_sites->siteCoords();
}


HX_DEFINE_DYNAMIC_FUNC0(Voronoi_obj,siteCoords,return )

::neash::geom::Point Voronoi_obj::nearestSitePoint( ::neash::display::BitmapData proximityMap,int x,int y){
	HX_STACK_PUSH("Voronoi::nearestSitePoint","com/nodename/delaunay/Voronoi.hx",231);
	HX_STACK_THIS(this);
	HX_STACK_ARG(proximityMap,"proximityMap");
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(231)
	return this->_sites->nearestSitePoint(proximityMap,x,y);
}


HX_DEFINE_DYNAMIC_FUNC3(Voronoi_obj,nearestSitePoint,return )

Array< int > Voronoi_obj::siteColors( ::neash::display::BitmapData referenceImage){
	HX_STACK_PUSH("Voronoi::siteColors","com/nodename/delaunay/Voronoi.hx",218);
	HX_STACK_THIS(this);
	HX_STACK_ARG(referenceImage,"referenceImage");
	HX_STACK_LINE(218)
	return this->_sites->siteColors(referenceImage);
}


HX_DEFINE_DYNAMIC_FUNC1(Voronoi_obj,siteColors,return )

Array< Array< ::neash::geom::Point > > Voronoi_obj::regions( ){
	HX_STACK_PUSH("Voronoi::regions","com/nodename/delaunay/Voronoi.hx",213);
	HX_STACK_THIS(this);
	HX_STACK_LINE(213)
	return this->_sites->regions(this->plotBounds);
}


HX_DEFINE_DYNAMIC_FUNC0(Voronoi_obj,regions,return )

Array< ::com::nodename::geom::LineSegment > Voronoi_obj::spanningTree( ::String __o_type,::neash::display::BitmapData keepOutMask){
::String type = __o_type.Default(HX_CSTRING("minimum"));
	HX_STACK_PUSH("Voronoi::spanningTree","com/nodename/delaunay/Voronoi.hx",206);
	HX_STACK_THIS(this);
	HX_STACK_ARG(type,"type");
	HX_STACK_ARG(keepOutMask,"keepOutMask");
{
		HX_STACK_LINE(207)
		Array< ::com::nodename::delaunay::Edge > edges = ::com::nodename::delaunay::Delaunay_obj::selectNonIntersectingEdges(keepOutMask,this->_edges);		HX_STACK_VAR(edges,"edges");
		HX_STACK_LINE(208)
		Array< ::com::nodename::geom::LineSegment > segments = ::com::nodename::delaunay::Delaunay_obj::delaunayLinesForEdges(edges);		HX_STACK_VAR(segments,"segments");
		HX_STACK_LINE(209)
		return ::com::nodename::delaunay::Kruskal_obj::kruskal(segments,type);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Voronoi_obj,spanningTree,return )

Array< ::neash::geom::Point > Voronoi_obj::hullPointsInOrder( ){
	HX_STACK_PUSH("Voronoi::hullPointsInOrder","com/nodename/delaunay/Voronoi.hx",179);
	HX_STACK_THIS(this);
	HX_STACK_LINE(180)
	Array< ::com::nodename::delaunay::Edge > hullEdges = this->hullEdges();		HX_STACK_VAR(hullEdges,"hullEdges");
	HX_STACK_LINE(182)
	Array< ::neash::geom::Point > points = Array_obj< ::neash::geom::Point >::__new();		HX_STACK_VAR(points,"points");
	HX_STACK_LINE(183)
	if (((hullEdges->length == (int)0))){
		HX_STACK_LINE(184)
		return points;
	}
	HX_STACK_LINE(188)
	::com::nodename::delaunay::EdgeReorderer reorderer = ::com::nodename::delaunay::EdgeReorderer_obj::__new(hullEdges,::com::nodename::delaunay::Criterion_obj::site_dyn());		HX_STACK_VAR(reorderer,"reorderer");
	HX_STACK_LINE(189)
	hullEdges = reorderer->edges;
	HX_STACK_LINE(190)
	Array< ::com::nodename::delaunay::LR > orientations = reorderer->edgeOrientations;		HX_STACK_VAR(orientations,"orientations");
	HX_STACK_LINE(191)
	reorderer->dispose();
	HX_STACK_LINE(193)
	::com::nodename::delaunay::LR orientation;		HX_STACK_VAR(orientation,"orientation");
	HX_STACK_LINE(195)
	int n = hullEdges->length;		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(196)
	{
		HX_STACK_LINE(196)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(196)
		while(((_g < n))){
			HX_STACK_LINE(196)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(198)
			::com::nodename::delaunay::Edge edge = hullEdges->__get(i);		HX_STACK_VAR(edge,"edge");
			HX_STACK_LINE(199)
			orientation = orientations->__get(i);
			HX_STACK_LINE(200)
			points->push(edge->site(orientation)->_coord);
		}
	}
	HX_STACK_LINE(202)
	return points;
}


HX_DEFINE_DYNAMIC_FUNC0(Voronoi_obj,hullPointsInOrder,return )

Array< ::com::nodename::delaunay::Edge > Voronoi_obj::hullEdges( ){
	HX_STACK_PUSH("Voronoi::hullEdges","com/nodename/delaunay/Voronoi.hx",172);
	HX_STACK_THIS(this);

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
	bool run(::com::nodename::delaunay::Edge edge){
		HX_STACK_PUSH("*::_Function_1_1","com/nodename/delaunay/Voronoi.hx",173);
		HX_STACK_ARG(edge,"edge");
		{
			HX_STACK_LINE(173)
			return edge->isPartOfConvexHull();
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(172)
	return ::Lambda_obj::array(::Lambda_obj::filter(this->_edges, Dynamic(new _Function_1_1())));
}


HX_DEFINE_DYNAMIC_FUNC0(Voronoi_obj,hullEdges,return )

Array< ::com::nodename::geom::LineSegment > Voronoi_obj::hull( ){
	HX_STACK_PUSH("Voronoi::hull","com/nodename/delaunay/Voronoi.hx",167);
	HX_STACK_THIS(this);
	HX_STACK_LINE(167)
	return ::com::nodename::delaunay::Delaunay_obj::delaunayLinesForEdges(this->hullEdges());
}


HX_DEFINE_DYNAMIC_FUNC0(Voronoi_obj,hull,return )

Array< ::com::nodename::geom::LineSegment > Voronoi_obj::delaunayTriangulation( ::neash::display::BitmapData keepOutMask){
	HX_STACK_PUSH("Voronoi::delaunayTriangulation","com/nodename/delaunay/Voronoi.hx",162);
	HX_STACK_THIS(this);
	HX_STACK_ARG(keepOutMask,"keepOutMask");
	HX_STACK_LINE(162)
	return ::com::nodename::delaunay::Delaunay_obj::delaunayLinesForEdges(::com::nodename::delaunay::Delaunay_obj::selectNonIntersectingEdges(keepOutMask,this->_edges));
}


HX_DEFINE_DYNAMIC_FUNC1(Voronoi_obj,delaunayTriangulation,return )

Array< ::com::nodename::geom::LineSegment > Voronoi_obj::voronoiDiagram( ){
	HX_STACK_PUSH("Voronoi::voronoiDiagram","com/nodename/delaunay/Voronoi.hx",157);
	HX_STACK_THIS(this);
	HX_STACK_LINE(157)
	return ::com::nodename::delaunay::Delaunay_obj::visibleLineSegments(this->_edges);
}


HX_DEFINE_DYNAMIC_FUNC0(Voronoi_obj,voronoiDiagram,return )

Array< ::com::nodename::geom::LineSegment > Voronoi_obj::delaunayLinesForSite( ::neash::geom::Point coord){
	HX_STACK_PUSH("Voronoi::delaunayLinesForSite","com/nodename/delaunay/Voronoi.hx",152);
	HX_STACK_THIS(this);
	HX_STACK_ARG(coord,"coord");
	HX_STACK_LINE(152)
	return ::com::nodename::delaunay::Delaunay_obj::delaunayLinesForEdges(::com::nodename::delaunay::Delaunay_obj::selectEdgesForSitePoint(coord,this->_edges));
}


HX_DEFINE_DYNAMIC_FUNC1(Voronoi_obj,delaunayLinesForSite,return )

Array< ::com::nodename::geom::LineSegment > Voronoi_obj::voronoiBoundaryForSite( ::neash::geom::Point coord){
	HX_STACK_PUSH("Voronoi::voronoiBoundaryForSite","com/nodename/delaunay/Voronoi.hx",147);
	HX_STACK_THIS(this);
	HX_STACK_ARG(coord,"coord");
	HX_STACK_LINE(147)
	return ::com::nodename::delaunay::Delaunay_obj::visibleLineSegments(::com::nodename::delaunay::Delaunay_obj::selectEdgesForSitePoint(coord,this->_edges));
}


HX_DEFINE_DYNAMIC_FUNC1(Voronoi_obj,voronoiBoundaryForSite,return )

Array< ::com::nodename::geom::Circle > Voronoi_obj::circles( ){
	HX_STACK_PUSH("Voronoi::circles","com/nodename/delaunay/Voronoi.hx",142);
	HX_STACK_THIS(this);
	HX_STACK_LINE(142)
	return this->_sites->circles();
}


HX_DEFINE_DYNAMIC_FUNC0(Voronoi_obj,circles,return )

Array< ::neash::geom::Point > Voronoi_obj::neighborSitesForSite( ::neash::geom::Point coord){
	HX_STACK_PUSH("Voronoi::neighborSitesForSite","com/nodename/delaunay/Voronoi.hx",125);
	HX_STACK_THIS(this);
	HX_STACK_ARG(coord,"coord");
	HX_STACK_LINE(126)
	Array< ::neash::geom::Point > points = Array_obj< ::neash::geom::Point >::__new();		HX_STACK_VAR(points,"points");
	HX_STACK_LINE(127)
	::com::nodename::delaunay::Site site = this->_sitesIndexedByLocation->hashValues->get(::__hxcpp_obj_id(coord));		HX_STACK_VAR(site,"site");
	HX_STACK_LINE(128)
	if (((site == null()))){
		HX_STACK_LINE(129)
		return points;
	}
	HX_STACK_LINE(132)
	Array< ::com::nodename::delaunay::Site > sites = site->neighborSites();		HX_STACK_VAR(sites,"sites");
	HX_STACK_LINE(133)
	::com::nodename::delaunay::Site neighbor;		HX_STACK_VAR(neighbor,"neighbor");
	HX_STACK_LINE(134)
	{
		HX_STACK_LINE(134)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(134)
		while(((_g < sites->length))){
			HX_STACK_LINE(134)
			::com::nodename::delaunay::Site neighbor1 = sites->__get(_g);		HX_STACK_VAR(neighbor1,"neighbor1");
			HX_STACK_LINE(134)
			++(_g);
			HX_STACK_LINE(136)
			points->push(neighbor1->_coord);
		}
	}
	HX_STACK_LINE(138)
	return points;
}


HX_DEFINE_DYNAMIC_FUNC1(Voronoi_obj,neighborSitesForSite,return )

Array< ::neash::geom::Point > Voronoi_obj::region( ::neash::geom::Point p){
	HX_STACK_PUSH("Voronoi::region","com/nodename/delaunay/Voronoi.hx",114);
	HX_STACK_THIS(this);
	HX_STACK_ARG(p,"p");
	HX_STACK_LINE(115)
	::com::nodename::delaunay::Site site = this->_sitesIndexedByLocation->hashValues->get(::__hxcpp_obj_id(p));		HX_STACK_VAR(site,"site");
	HX_STACK_LINE(116)
	if (((site == null()))){
		HX_STACK_LINE(117)
		return Array_obj< ::neash::geom::Point >::__new();
	}
	HX_STACK_LINE(120)
	return site->region(this->plotBounds);
}


HX_DEFINE_DYNAMIC_FUNC1(Voronoi_obj,region,return )

Array< ::com::nodename::delaunay::Edge > Voronoi_obj::edges( ){
	HX_STACK_PUSH("Voronoi::edges","com/nodename/delaunay/Voronoi.hx",109);
	HX_STACK_THIS(this);
	HX_STACK_LINE(109)
	return this->_edges;
}


HX_DEFINE_DYNAMIC_FUNC0(Voronoi_obj,edges,return )

Void Voronoi_obj::addSite( ::neash::geom::Point p,int color,int index){
{
		HX_STACK_PUSH("Voronoi::addSite","com/nodename/delaunay/Voronoi.hx",101);
		HX_STACK_THIS(this);
		HX_STACK_ARG(p,"p");
		HX_STACK_ARG(color,"color");
		HX_STACK_ARG(index,"index");
		HX_STACK_LINE(102)
		Float weight = (this->_prng->nextDouble() * (int)100);		HX_STACK_VAR(weight,"weight");
		HX_STACK_LINE(103)
		::com::nodename::delaunay::Site site = ::com::nodename::delaunay::Site_obj::create(p,index,weight,color);		HX_STACK_VAR(site,"site");
		HX_STACK_LINE(104)
		this->_sites->push(site);
		HX_STACK_LINE(105)
		{
			HX_STACK_LINE(105)
			::nme::ObjectHash _this = this->_sitesIndexedByLocation;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(105)
			int id = ::__hxcpp_obj_id(p);		HX_STACK_VAR(id,"id");
			HX_STACK_LINE(105)
			_this->hashKeys->set(id,p);
			HX_STACK_LINE(105)
			_this->hashValues->set(id,site);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Voronoi_obj,addSite,(void))

Void Voronoi_obj::addSites( Array< ::neash::geom::Point > points,Array< int > colors){
{
		HX_STACK_PUSH("Voronoi::addSites","com/nodename/delaunay/Voronoi.hx",92);
		HX_STACK_THIS(this);
		HX_STACK_ARG(points,"points");
		HX_STACK_ARG(colors,"colors");
		HX_STACK_LINE(93)
		int length = points->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(94)
		{
			HX_STACK_LINE(94)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(94)
			while(((_g < length))){
				HX_STACK_LINE(94)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(96)
				this->addSite(points->__get(i),(  (((colors != null()))) ? int(colors->__get(i)) : int((int)0) ),i);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Voronoi_obj,addSites,(void))

Void Voronoi_obj::dispose( ){
{
		HX_STACK_PUSH("Voronoi::dispose","com/nodename/delaunay/Voronoi.hx",31);
		HX_STACK_THIS(this);
		HX_STACK_LINE(32)
		int i;		HX_STACK_VAR(i,"i");
		int n;		HX_STACK_VAR(n,"n");
		HX_STACK_LINE(33)
		if (((this->_sites != null()))){
			HX_STACK_LINE(35)
			this->_sites->dispose();
			HX_STACK_LINE(36)
			this->_sites = null();
		}
		HX_STACK_LINE(38)
		if (((this->_triangles != null()))){
			HX_STACK_LINE(40)
			n = this->_triangles->length;
			HX_STACK_LINE(41)
			{
				HX_STACK_LINE(41)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(41)
				while(((_g < n))){
					HX_STACK_LINE(41)
					int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
					HX_STACK_LINE(43)
					this->_triangles->__get(i1)->dispose();
				}
			}
			HX_STACK_LINE(46)
			this->_triangles = null();
		}
		HX_STACK_LINE(48)
		if (((this->_edges != null()))){
			HX_STACK_LINE(50)
			n = this->_edges->length;
			HX_STACK_LINE(51)
			{
				HX_STACK_LINE(51)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(51)
				while(((_g < n))){
					HX_STACK_LINE(51)
					int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
					HX_STACK_LINE(53)
					this->_edges->__get(i1)->dispose();
				}
			}
			HX_STACK_LINE(56)
			this->_edges = null();
		}
		HX_STACK_LINE(58)
		this->plotBounds = null();
		HX_STACK_LINE(59)
		this->_sitesIndexedByLocation = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Voronoi_obj,dispose,(void))

bool Voronoi_obj::isInfSite( ::com::nodename::delaunay::Site s1,::com::nodename::delaunay::Site s2){
	HX_STACK_PUSH("Voronoi::isInfSite","com/nodename/delaunay/Voronoi.hx",423);
	HX_STACK_ARG(s1,"s1");
	HX_STACK_ARG(s2,"s2");
	HX_STACK_LINE(423)
	return (bool((s1->_coord->y < s2->_coord->y)) || bool((bool((s1->_coord->y == s2->_coord->y)) && bool((s1->_coord->x < s2->_coord->x)))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Voronoi_obj,isInfSite,return )

int Voronoi_obj::comparePointByYThenX( ::com::nodename::delaunay::Site s1,::neash::geom::Point s2){
	HX_STACK_PUSH("Voronoi::comparePointByYThenX","com/nodename/delaunay/Voronoi.hx",428);
	HX_STACK_ARG(s1,"s1");
	HX_STACK_ARG(s2,"s2");
	HX_STACK_LINE(428)
	return ::com::nodename::delaunay::Voronoi_obj::compareByYThenX(s1->_coord->x,s1->_coord->y,s2->x,s2->y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Voronoi_obj,comparePointByYThenX,return )

int Voronoi_obj::compareSiteByYThenX( ::com::nodename::delaunay::Site s1,::com::nodename::delaunay::Site s2){
	HX_STACK_PUSH("Voronoi::compareSiteByYThenX","com/nodename/delaunay/Voronoi.hx",433);
	HX_STACK_ARG(s1,"s1");
	HX_STACK_ARG(s2,"s2");
	HX_STACK_LINE(433)
	return ::com::nodename::delaunay::Voronoi_obj::compareByYThenX(s1->_coord->x,s1->_coord->y,s2->_coord->x,s2->_coord->y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Voronoi_obj,compareSiteByYThenX,return )

int Voronoi_obj::compareByYThenX( Float s1x,Float s1y,Float s2x,Float s2y){
	HX_STACK_PUSH("Voronoi::compareByYThenX","com/nodename/delaunay/Voronoi.hx",438);
	HX_STACK_ARG(s1x,"s1x");
	HX_STACK_ARG(s1y,"s1y");
	HX_STACK_ARG(s2x,"s2x");
	HX_STACK_ARG(s2y,"s2y");
	HX_STACK_LINE(439)
	if (((s1y < s2y))){
		HX_STACK_LINE(439)
		return (int)-1;
	}
	HX_STACK_LINE(440)
	if (((s1y > s2y))){
		HX_STACK_LINE(440)
		return (int)1;
	}
	HX_STACK_LINE(441)
	if (((s1x < s2x))){
		HX_STACK_LINE(441)
		return (int)-1;
	}
	HX_STACK_LINE(442)
	if (((s1x > s2x))){
		HX_STACK_LINE(442)
		return (int)1;
	}
	HX_STACK_LINE(443)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Voronoi_obj,compareByYThenX,return )


Voronoi_obj::Voronoi_obj()
{
}

void Voronoi_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Voronoi);
	HX_MARK_MEMBER_NAME(plotBounds,"plotBounds");
	HX_MARK_MEMBER_NAME(_edges,"_edges");
	HX_MARK_MEMBER_NAME(_triangles,"_triangles");
	HX_MARK_MEMBER_NAME(_sitesIndexedByLocation,"_sitesIndexedByLocation");
	HX_MARK_MEMBER_NAME(_sites,"_sites");
	HX_MARK_MEMBER_NAME(_prng,"_prng");
	HX_MARK_END_CLASS();
}

void Voronoi_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(plotBounds,"plotBounds");
	HX_VISIT_MEMBER_NAME(_edges,"_edges");
	HX_VISIT_MEMBER_NAME(_triangles,"_triangles");
	HX_VISIT_MEMBER_NAME(_sitesIndexedByLocation,"_sitesIndexedByLocation");
	HX_VISIT_MEMBER_NAME(_sites,"_sites");
	HX_VISIT_MEMBER_NAME(_prng,"_prng");
}

Dynamic Voronoi_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"hull") ) { return hull_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"edges") ) { return edges_dyn(); }
		if (HX_FIELD_EQ(inName,"_prng") ) { return _prng; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"region") ) { return region_dyn(); }
		if (HX_FIELD_EQ(inName,"_edges") ) { return _edges; }
		if (HX_FIELD_EQ(inName,"_sites") ) { return _sites; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"regions") ) { return regions_dyn(); }
		if (HX_FIELD_EQ(inName,"circles") ) { return circles_dyn(); }
		if (HX_FIELD_EQ(inName,"addSite") ) { return addSite_dyn(); }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"addSites") ) { return addSites_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"isInfSite") ) { return isInfSite_dyn(); }
		if (HX_FIELD_EQ(inName,"hullEdges") ) { return hullEdges_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"siteCoords") ) { return siteCoords_dyn(); }
		if (HX_FIELD_EQ(inName,"siteColors") ) { return siteColors_dyn(); }
		if (HX_FIELD_EQ(inName,"plotBounds") ) { return plotBounds; }
		if (HX_FIELD_EQ(inName,"_triangles") ) { return _triangles; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"spanningTree") ) { return spanningTree_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"voronoiDiagram") ) { return voronoiDiagram_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"compareByYThenX") ) { return compareByYThenX_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nearestSitePoint") ) { return nearestSitePoint_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"fortunesAlgorithm") ) { return fortunesAlgorithm_dyn(); }
		if (HX_FIELD_EQ(inName,"hullPointsInOrder") ) { return hullPointsInOrder_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"compareSiteByYThenX") ) { return compareSiteByYThenX_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"comparePointByYThenX") ) { return comparePointByYThenX_dyn(); }
		if (HX_FIELD_EQ(inName,"delaunayLinesForSite") ) { return delaunayLinesForSite_dyn(); }
		if (HX_FIELD_EQ(inName,"neighborSitesForSite") ) { return neighborSitesForSite_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"delaunayTriangulation") ) { return delaunayTriangulation_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"voronoiBoundaryForSite") ) { return voronoiBoundaryForSite_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_sitesIndexedByLocation") ) { return _sitesIndexedByLocation; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Voronoi_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_prng") ) { _prng=inValue.Cast< ::de::polygonal::math::PM_PRNG >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_edges") ) { _edges=inValue.Cast< Array< ::com::nodename::delaunay::Edge > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_sites") ) { _sites=inValue.Cast< ::com::nodename::delaunay::SiteList >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"plotBounds") ) { plotBounds=inValue.Cast< ::neash::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_triangles") ) { _triangles=inValue.Cast< Array< ::com::nodename::delaunay::Triangle > >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_sitesIndexedByLocation") ) { _sitesIndexedByLocation=inValue.Cast< ::nme::ObjectHash >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Voronoi_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("plotBounds"));
	outFields->push(HX_CSTRING("_edges"));
	outFields->push(HX_CSTRING("_triangles"));
	outFields->push(HX_CSTRING("_sitesIndexedByLocation"));
	outFields->push(HX_CSTRING("_sites"));
	outFields->push(HX_CSTRING("_prng"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("isInfSite"),
	HX_CSTRING("comparePointByYThenX"),
	HX_CSTRING("compareSiteByYThenX"),
	HX_CSTRING("compareByYThenX"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("fortunesAlgorithm"),
	HX_CSTRING("siteCoords"),
	HX_CSTRING("nearestSitePoint"),
	HX_CSTRING("siteColors"),
	HX_CSTRING("regions"),
	HX_CSTRING("spanningTree"),
	HX_CSTRING("hullPointsInOrder"),
	HX_CSTRING("hullEdges"),
	HX_CSTRING("hull"),
	HX_CSTRING("delaunayTriangulation"),
	HX_CSTRING("voronoiDiagram"),
	HX_CSTRING("delaunayLinesForSite"),
	HX_CSTRING("voronoiBoundaryForSite"),
	HX_CSTRING("circles"),
	HX_CSTRING("neighborSitesForSite"),
	HX_CSTRING("region"),
	HX_CSTRING("edges"),
	HX_CSTRING("addSite"),
	HX_CSTRING("addSites"),
	HX_CSTRING("dispose"),
	HX_CSTRING("plotBounds"),
	HX_CSTRING("_edges"),
	HX_CSTRING("_triangles"),
	HX_CSTRING("_sitesIndexedByLocation"),
	HX_CSTRING("_sites"),
	HX_CSTRING("_prng"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Voronoi_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Voronoi_obj::__mClass,"__mClass");
};

Class Voronoi_obj::__mClass;

void Voronoi_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.delaunay.Voronoi"), hx::TCanCast< Voronoi_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Voronoi_obj::__boot()
{
}

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

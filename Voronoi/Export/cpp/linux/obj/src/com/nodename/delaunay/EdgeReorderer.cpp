#include <hxcpp.h>

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
#ifndef INCLUDED_com_nodename_delaunay_Vertex
#include <com/nodename/delaunay/Vertex.h>
#endif
namespace com{
namespace nodename{
namespace delaunay{

Void EdgeReorderer_obj::__construct(Array< ::com::nodename::delaunay::Edge > origEdges,::com::nodename::delaunay::Criterion criterion)
{
HX_STACK_PUSH("EdgeReorderer::new","com/nodename/delaunay/EdgeReorderer.hx",12);
{
	HX_STACK_LINE(13)
	if (((bool((criterion != ::com::nodename::delaunay::Criterion_obj::vertex_dyn())) && bool((criterion != ::com::nodename::delaunay::Criterion_obj::site_dyn()))))){
		HX_STACK_LINE(14)
		hx::Throw (HX_CSTRING("Edges: criterion must be Vertex or Site"));
	}
	HX_STACK_LINE(17)
	this->edges = Array_obj< ::com::nodename::delaunay::Edge >::__new();
	HX_STACK_LINE(18)
	this->edgeOrientations = Array_obj< ::com::nodename::delaunay::LR >::__new();
	HX_STACK_LINE(19)
	if (((origEdges->length > (int)0))){
		HX_STACK_LINE(20)
		this->edges = this->reorderEdges(origEdges,criterion);
	}
}
;
	return null();
}

EdgeReorderer_obj::~EdgeReorderer_obj() { }

Dynamic EdgeReorderer_obj::__CreateEmpty() { return  new EdgeReorderer_obj; }
hx::ObjectPtr< EdgeReorderer_obj > EdgeReorderer_obj::__new(Array< ::com::nodename::delaunay::Edge > origEdges,::com::nodename::delaunay::Criterion criterion)
{  hx::ObjectPtr< EdgeReorderer_obj > result = new EdgeReorderer_obj();
	result->__construct(origEdges,criterion);
	return result;}

Dynamic EdgeReorderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EdgeReorderer_obj > result = new EdgeReorderer_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Array< ::com::nodename::delaunay::Edge > EdgeReorderer_obj::reorderEdges( Array< ::com::nodename::delaunay::Edge > origEdges,::com::nodename::delaunay::Criterion criterion){
	HX_STACK_PUSH("EdgeReorderer::reorderEdges","com/nodename/delaunay/EdgeReorderer.hx",32);
	HX_STACK_THIS(this);
	HX_STACK_ARG(origEdges,"origEdges");
	HX_STACK_ARG(criterion,"criterion");
	HX_STACK_LINE(33)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(34)
	int j;		HX_STACK_VAR(j,"j");
	HX_STACK_LINE(35)
	int n = origEdges->length;		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(36)
	::com::nodename::delaunay::Edge edge;		HX_STACK_VAR(edge,"edge");
	HX_STACK_LINE(38)
	Array< bool > done = Array_obj< bool >::__new();		HX_STACK_VAR(done,"done");
	HX_STACK_LINE(39)
	int nDone = (int)0;		HX_STACK_VAR(nDone,"nDone");
	HX_STACK_LINE(40)
	{
		HX_STACK_LINE(40)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(40)
		while(((_g < done->length))){
			HX_STACK_LINE(40)
			bool b = done->__get(_g);		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(40)
			++(_g);
			HX_STACK_LINE(42)
			b = false;
		}
	}
	HX_STACK_LINE(44)
	Array< ::com::nodename::delaunay::Edge > newEdges = Array_obj< ::com::nodename::delaunay::Edge >::__new();		HX_STACK_VAR(newEdges,"newEdges");
	HX_STACK_LINE(46)
	i = (int)0;
	HX_STACK_LINE(47)
	edge = origEdges->__get(i);
	HX_STACK_LINE(48)
	newEdges->push(edge);
	HX_STACK_LINE(49)
	this->edgeOrientations->push(::com::nodename::delaunay::LR_obj::LEFT);
	HX_STACK_LINE(50)
	::com::nodename::delaunay::ICoord firstPoint;		HX_STACK_VAR(firstPoint,"firstPoint");
	HX_STACK_LINE(51)
	::com::nodename::delaunay::ICoord lastPoint;		HX_STACK_VAR(lastPoint,"lastPoint");
	HX_STACK_LINE(52)
	if (((criterion == ::com::nodename::delaunay::Criterion_obj::vertex_dyn()))){
		HX_STACK_LINE(53)
		firstPoint = edge->leftVertex;
		HX_STACK_LINE(54)
		lastPoint = edge->rightVertex;
	}
	else{
		HX_STACK_LINE(57)
		firstPoint = edge->leftSite;
		HX_STACK_LINE(58)
		lastPoint = edge->rightSite;
	}
	HX_STACK_LINE(61)
	if (((bool((firstPoint == ::com::nodename::delaunay::Vertex_obj::VERTEX_AT_INFINITY)) || bool((lastPoint == ::com::nodename::delaunay::Vertex_obj::VERTEX_AT_INFINITY))))){
		HX_STACK_LINE(62)
		return Array_obj< ::com::nodename::delaunay::Edge >::__new();
	}
	HX_STACK_LINE(66)
	done[i] = true;
	HX_STACK_LINE(67)
	++(nDone);
	HX_STACK_LINE(69)
	while(((nDone < n))){
		HX_STACK_LINE(71)
		int _g = (int)1;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(71)
		while(((_g < n))){
			HX_STACK_LINE(71)
			int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
			HX_STACK_LINE(73)
			if ((done->__get(i1))){
				HX_STACK_LINE(74)
				continue;
			}
			HX_STACK_LINE(77)
			edge = origEdges->__get(i1);
			HX_STACK_LINE(78)
			::com::nodename::delaunay::ICoord leftPoint;		HX_STACK_VAR(leftPoint,"leftPoint");
			HX_STACK_LINE(79)
			::com::nodename::delaunay::ICoord rightPoint;		HX_STACK_VAR(rightPoint,"rightPoint");
			HX_STACK_LINE(80)
			if (((criterion == ::com::nodename::delaunay::Criterion_obj::vertex_dyn()))){
				HX_STACK_LINE(81)
				leftPoint = edge->leftVertex;
				HX_STACK_LINE(82)
				rightPoint = edge->rightVertex;
			}
			else{
				HX_STACK_LINE(85)
				leftPoint = edge->leftSite;
				HX_STACK_LINE(86)
				rightPoint = edge->rightSite;
			}
			HX_STACK_LINE(89)
			if (((bool((leftPoint == ::com::nodename::delaunay::Vertex_obj::VERTEX_AT_INFINITY)) || bool((rightPoint == ::com::nodename::delaunay::Vertex_obj::VERTEX_AT_INFINITY))))){
				HX_STACK_LINE(90)
				return Array_obj< ::com::nodename::delaunay::Edge >::__new();
			}
			HX_STACK_LINE(93)
			if (((leftPoint == lastPoint))){
				HX_STACK_LINE(95)
				lastPoint = rightPoint;
				HX_STACK_LINE(96)
				this->edgeOrientations->push(::com::nodename::delaunay::LR_obj::LEFT);
				HX_STACK_LINE(97)
				newEdges->push(edge);
				HX_STACK_LINE(98)
				done[i1] = true;
			}
			else{
				HX_STACK_LINE(100)
				if (((rightPoint == firstPoint))){
					HX_STACK_LINE(102)
					firstPoint = leftPoint;
					HX_STACK_LINE(103)
					this->edgeOrientations->unshift(::com::nodename::delaunay::LR_obj::LEFT);
					HX_STACK_LINE(104)
					newEdges->unshift(edge);
					HX_STACK_LINE(105)
					done[i1] = true;
				}
				else{
					HX_STACK_LINE(107)
					if (((leftPoint == firstPoint))){
						HX_STACK_LINE(109)
						firstPoint = rightPoint;
						HX_STACK_LINE(110)
						this->edgeOrientations->unshift(::com::nodename::delaunay::LR_obj::RIGHT);
						HX_STACK_LINE(111)
						newEdges->unshift(edge);
						HX_STACK_LINE(112)
						done[i1] = true;
					}
					else{
						HX_STACK_LINE(114)
						if (((rightPoint == lastPoint))){
							HX_STACK_LINE(116)
							lastPoint = leftPoint;
							HX_STACK_LINE(117)
							this->edgeOrientations->push(::com::nodename::delaunay::LR_obj::RIGHT);
							HX_STACK_LINE(118)
							newEdges->push(edge);
							HX_STACK_LINE(119)
							done[i1] = true;
						}
					}
				}
			}
			HX_STACK_LINE(121)
			if ((done->__get(i1))){
				HX_STACK_LINE(122)
				++(nDone);
			}
		}
	}
	HX_STACK_LINE(128)
	return newEdges;
}


HX_DEFINE_DYNAMIC_FUNC2(EdgeReorderer_obj,reorderEdges,return )

Void EdgeReorderer_obj::dispose( ){
{
		HX_STACK_PUSH("EdgeReorderer::dispose","com/nodename/delaunay/EdgeReorderer.hx",26);
		HX_STACK_THIS(this);
		HX_STACK_LINE(27)
		this->edges = null();
		HX_STACK_LINE(28)
		this->edgeOrientations = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(EdgeReorderer_obj,dispose,(void))


EdgeReorderer_obj::EdgeReorderer_obj()
{
}

void EdgeReorderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EdgeReorderer);
	HX_MARK_MEMBER_NAME(edgeOrientations,"edgeOrientations");
	HX_MARK_MEMBER_NAME(edges,"edges");
	HX_MARK_END_CLASS();
}

void EdgeReorderer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(edgeOrientations,"edgeOrientations");
	HX_VISIT_MEMBER_NAME(edges,"edges");
}

Dynamic EdgeReorderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"edges") ) { return edges; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"reorderEdges") ) { return reorderEdges_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"edgeOrientations") ) { return edgeOrientations; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EdgeReorderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"edges") ) { edges=inValue.Cast< Array< ::com::nodename::delaunay::Edge > >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"edgeOrientations") ) { edgeOrientations=inValue.Cast< Array< ::com::nodename::delaunay::LR > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EdgeReorderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("edgeOrientations"));
	outFields->push(HX_CSTRING("edges"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("reorderEdges"),
	HX_CSTRING("dispose"),
	HX_CSTRING("edgeOrientations"),
	HX_CSTRING("edges"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EdgeReorderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EdgeReorderer_obj::__mClass,"__mClass");
};

Class EdgeReorderer_obj::__mClass;

void EdgeReorderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.nodename.delaunay.EdgeReorderer"), hx::TCanCast< EdgeReorderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void EdgeReorderer_obj::__boot()
{
}

} // end namespace com
} // end namespace nodename
} // end namespace delaunay

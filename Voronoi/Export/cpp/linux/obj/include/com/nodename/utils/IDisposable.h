#ifndef INCLUDED_com_nodename_utils_IDisposable
#define INCLUDED_com_nodename_utils_IDisposable

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,nodename,utils,IDisposable)
namespace com{
namespace nodename{
namespace utils{


class IDisposable_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IDisposable_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual Void dispose( )=0;
		Dynamic dispose_dyn();
};

#define DELEGATE_com_nodename_utils_IDisposable \
virtual Void dispose( ) { return mDelegate->dispose();}  \
virtual Dynamic dispose_dyn() { return mDelegate->dispose_dyn();}  \


template<typename IMPL>
class IDisposable_delegate_ : public IDisposable_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IDisposable_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_com_nodename_utils_IDisposable
};

} // end namespace com
} // end namespace nodename
} // end namespace utils

#endif /* INCLUDED_com_nodename_utils_IDisposable */ 

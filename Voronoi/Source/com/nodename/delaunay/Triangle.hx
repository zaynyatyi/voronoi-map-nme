package com.nodename.delaunay;

//import as3.TypeDefs;

class Triangle {
	private var _sites:Array<Site>;
	public var sites(get_sites, null) : Array<Site>;
	inline public function get_sites():Array<Site> {
		return _sites;
	}
	
	public function new(a:Site, b:Site, c:Site)
	{
		_sites = [ a, b, c ];
	}
	
	public function dispose():Void
	{
		_sites = null;
	}
	
}
#include<iostream>
template <typename T1, typename T2, typename T3>
class triple{
	T1 v1;
	T2 v2;
	T3 v3;
public:
	auto & operator[] (int k) {
		if(k==0) return v1;
		else if(k==1) return v2;
		return v3;
	}
	void operator=(const triple&a) {
		v1 = a.v1;
		v2 = a.v2;
		v3 = a.v3;
	}
	friend std::ostream & operator<<( std::ostream & os,const triple & c) {
		os << "("<<c.v1<<","<<c.v2<<","<<c.v3<<")";
		return os;
	}
	triple() {};
	triple(T1 _v1, T2 _v2, T3 _v3) {
		v1 = _v1;
		v2 = _v2;
		v3 = _v3;
	}
};

#include<iostream>/*{{{*/
#include<vector>
#include<set>
#include<math.h>
#include<map>
#include "../template/bigint.cpp"
const int e2 = 100;
const int e3 = e2*10;
const int e4 = e3*10;
const int e5 = e4*10;
const int e6 = e4*e2;
const int e7 = e6*10;
const int e8 = e7*10;
const int mod = 1e9+7;
using namespace std;/*}}}*/

/*add{{{*/
template <typename T>
T base_add(T a, T b) {
	a %= mod;
	b %= mod;
	return (a+b)%mod;
}
template <typename T>
T add(const T &t) { return t; }
template <typename T, typename ... Args>
T add(const T &t, const Args&... args) { return base_add(t, add(args...)); }
/*}}}*/

/*{{{mul*/
template <typename T>
T base_mul(T a, T b) {
	a%=mod;
	b%=mod;
	T ret(0);
	while(b) {
		if(b&1) ret = (ret + a) % mod;
		b>>=1;
		a = (a+a)%mod;
	}
	return ret;
}
template <typename T>
T mul(const T &t) { return t; }
template <typename T, typename ... Args>
T mul(const T &t, const Args&... args) { return base_mul(t, mul(args...)); }
/*}}}*/

/*{{{qpow*/
template <typename T>
T qpow(T a, T b) {
	T ret(1);
	while(b) {
		if(b&1) ret = mul(ret, a);
		a = mul(a, a);
		b>>=1;
	}
	return ret;
}
/*}}}*/

const long long n = 1e16;
const long long inv_2 = qpow(2, mod-2);
long long cal(long long l) {
	long long x = n-l*(l+1)/2 + 1;
	if(x<=0) return 0;
	long long ans1 = mul(x/l, x/l+1, l, inv_2);
	long long ans2 = mul(x%l, x/l+1);
	return add(ans1, ans2);
}

int main() {
	long long ans = 0;
	for(int i = 1;;i++) {
		long long now = cal(i);
		if(i%e6==0) {
			cout<<i/e6<<endl;
		}
		if(now == 0) break;
		ans = add(ans, now);
	}
	cout<<ans<<endl;
	return 0;
}

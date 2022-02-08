#include<iostream>/*{{{*/
#include<vector>
#include<set>
#include<math.h>
#include<map>
const int e4 = 10000;
const int e8 = e4*e4;
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

const long long upper = 1e14;

//set<long long> s;
vector<long long> vals;
int main() {
	for(long long i = 1;i*i*(i+1)*(i+1)<=upper;i++) {
		for(long long j = i;i*j*(i+1)*(j+1)<=upper;j++) {
			vals.push_back(i*j*(i+1)*(j+1));
		}
	}
	sort(vals.begin(), vals.end());
	cout<<unique(vals.begin(), vals.end()) - vals.begin()<<endl;
	return 0;
}

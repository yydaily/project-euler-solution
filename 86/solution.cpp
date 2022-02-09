#include<iostream>/*{{{*/
#include<vector>
#include<set>
#include<math.h>
#include<map>
#include "../template/bigint.cpp"
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

map<int, int> sqr;
void init(int m) {
	for(int i = 1;i<=m;i++) sqr[i*i] = i;
}

int cal(int a, int b_and_c) {
	int lower = b_and_c/2 + b_and_c%2;
	int upper = min(b_and_c-1, a);
	return max(0, upper-lower+1);
}

int count(int a) {/*{{{*/
	int ret = 0;
	for(int b_and_c = 1;b_and_c<=2*a;b_and_c++) {
		if(sqr[a*a+b_and_c*b_and_c]) {
			ret += cal(a, b_and_c);
		}
	}
	return ret;
}/*}}}*/

int main() {
	init(10000);
	int ans = 0;
	for(int i = 1;i<=10000;i++) {
		ans += count(i);
		if(ans>=1e6) {
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}

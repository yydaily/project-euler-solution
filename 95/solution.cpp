#include<iostream>/*{{{*/
#include<vector>
#include<set>
#include<math.h>
#include<map>
#include "../template/bigint.cpp"
const int e4 = 10000;
const int e8 = e4*e4;
const int e6 = e4*100;
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

int num[e6+10];
bool vis[e6+10];
int cal_next(int a) {
	int ret = 1;
	for(int i = 2;i*i<=a;i++) if(a%i==0) {
		ret += i;
		if(a/i != i) ret += a/i;
	}
	return ret;
}
int cal_len(int i, int origin, bool show = false) {
	if(i<=2 || i > e6) return -100;
	if(vis[i] && i == origin) return 0;
	if(vis[i]) return -100;
	
	if(show) cout<<i<<' ';

	int ret = 1;
	vis[i] = true;
	ret += cal_len(num[i], origin, show);
	vis[i] = false;
	return ret;
}

int main() {
	for(int i = 2;i<=e6;i++) num[i] = cal_next(i);
	int max_len = 0;
	int index = 0;
	for(int i = 2;i<=e6;i++) {
		int len = cal_len(i, i);
		if(len>0) {
			cal_len(i, i, true);
			cout<<": "<<len<<endl;
		}
		if(len > max_len) {
			max_len = len;
			index = i;
		}
	}
	cout<<max_len<<' '<<index<<endl;
	return 0;
}

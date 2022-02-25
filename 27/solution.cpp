#include<iostream>/*{{{*/
#include<vector>
#include<set>
#include<math.h>
#include<map>
#include "../template/bigint.cpp"
#include "../template/prime_cnt.cpp"
const long long e2 = 100;
const long long e3 = e2*10;
const long long e4 = e3*10;
const long long e5 = e4*10;
const long long e6 = e4*e2;
const long long e7 = e6*10;
const long long e8 = e7*10;
const long long mod = 1e9+7;
using namespace std;/*}}}*/

/*add{{{*/
long long base_add(long long a, long long b) {
	a %= mod;
	b %= mod;
	return (a+b)%mod;
}
long long add(long long a, long long b) {
	return base_add(a, b);
}
long long add(initializer_list<long long> args) {
	long long ret = 0;
	for(auto i : args) ret = base_add(ret, i);
	return ret;
}
/*}}}*/

/*{{{mul*/
long long base_mul(long long a, long long b) {
	a%=mod;
	b%=mod;
	long long ret = 0;
	while(b) {
		if(b&1) ret = (ret + a) % mod;
		b>>=1;
		a = (a+a)%mod;
	}
	return ret;
}
long long mul(long long a, long long b) {
	return base_mul(a, b);
}
long long mul(initializer_list<long long> args) {
	long long ret = 1;
	for(auto i : args) ret = base_mul(ret, i);
	return ret;
}/*}}}*/

/*{{{qpow*/
long long qpow(long long a, long long b) {
	long long ret = 1;
	while(b) {
		if(b&1) ret = mul({ret, a});
		a = mul({a, a});
		b>>=1;
	}
	return ret;
} /*}}}*/

int p[e7];
int cal(int a, int b) {
	for(int n = 0;;n++) {
		if(n*n+a*n+b < 0) return n-1;
		if(p[n*n + a*n + b]) return n-1;
	}
}
int main() {
	for(int i = 2;i<e7;i++) if(!p[i]) for(int j = i<<1;j<e7;j+=i) p[j] = true;
	int max_len = 0;
	int ans = 0;
	for(int b = 2;b<1000;b++) {
		if(p[b]) continue;
		for(int a = -999;a<1000;a++) {
			if(cal(a, b) > max_len) {
				max_len = cal(a, b);
				ans = a*b;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

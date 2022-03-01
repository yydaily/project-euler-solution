#include<iostream>/*{{{*/
#include<vector>
#include<set>
#include<math.h>
#include<map>
#include "../template/bigint.cpp"
#include "../template/prime_cnt.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
#include "../template/prime.cpp"
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
long long fib[90];
map<long long,long long> m;
long long cal(long long a) {/*{{{*/
	long long maxm = 0;
	for(long long i = 0;i<90;i++) {
		if(a==fib[i]) return a;
		if(a>fib[i]) maxm = fib[i];
		else break;
	}
	return c[a-maxm];
}/*}}}*/
void init() {
	fib[0] = 1;
	fib[1] = 1;
	for(int i = 2;i<90;i++) {
		fib[i] = fib[i-1]+fib[i-2];
	}
}
long long S(long long a) {/*{{{*/
	cout<<"S("<<a<<")"<<endl;
	if(a<=3) return a*(a+1)/2;
	if(m[a]) return m[a];
	long long maxm = 0;
	for(int i = 0;i<90;i++) {
		if(a>=fib[i]) maxm = fib[i];
		else break;
	}
	m[a] = S(maxm-1) + maxm + S(a-maxm);
	assert(m.size() < e7);
	return m[a];
}/*}}}*/
int main() {
	init();
	cout<<S(13)<<endl;
	cout<<S(23416728348467685LL)<<endl;
	return 0;
}

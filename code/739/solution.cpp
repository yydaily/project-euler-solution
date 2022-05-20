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
#include "../template/pell.cpp"
const long long e2 = 100;
const long long e3 = e2*10;
const long long e4 = e3*10;
const long long e5 = e4*10;
const long long e6 = e4*e2;
const long long e7 = e6*10;
const long long e8 = e7*10;
const long long e9 = e8*10;
long long mod = e9+7;
using namespace std;/*}}}*/
long long add(long long a, long long b) { return ((a+b)%mod+mod)%mod; }
long long mul(long long a, long long b) { return a * b%mod; }
long long mul(long long a, long long b, long long c) { return a*b%mod*c%mod; }
long long qpow(long long a, long long b) {/*{{{*/
	long long ret = 1;
	while(b) {
		if(b&1) ret = mul(ret, a);
		a = mul(a, a);
		b>>=1;
	}
	return ret;
}/*}}}*/
const long long upper = 2e8;
long long fac[upper+1];
long long inv[upper+1];
void init() {/*{{{*/
	fac[0] = 1;
	for(int i = 1;i<=upper;i++) fac[i] = fac[i-1]*i%mod;
	inv[upper] = qpow(fac[upper], mod-2);
	for(int i = upper-1;i>=0;i--) inv[i] = inv[i+1]*(i+1)%mod;
}/*}}}*/
long long C(long long a, long long b) {
	return mul(fac[a], inv[b], inv[a-b]);
}
long long cal_f(long long n) {
	n--;
	if(n==1) return 1;
	long long ret = 0;
	long long x = 1, y = 3;
	for(int i = 1;i<=n;i++) {
		long long t = add(C(2*n-i-1, n-i), -C(2*n-i-1, n-i-1));
		ret = add(ret, mul(t, y));
		swap(x, y);
		y += x;
		if(y>mod) y-=mod;
	}
	return ret;
}
int main() {
	init();
	cout<<cal_f(8)<<endl;
	cout<<cal_f(20)<<endl;
	cout<<cal_f(e8)<<endl;
	return 0;
}

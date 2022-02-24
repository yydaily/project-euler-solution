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
	assert(a>=0 && b>=0);
	return (a+b)%mod;
}
long long add(initializer_list<long long> args) {
	long long ret = 0;
	for(auto i : args) ret = base_add(ret, i);
	return ret;
}
long long add(long long a, long long b) {
	return base_add(a, b);
}
/*}}}*/

/*{{{mul*/
long long base_mul(long long a, long long b) {
	a%=mod;
	b%=mod;
	assert(a>=0 && b>=0);
	long long ret = 0;
	while(b) {
		if(b&1) ret = (ret + a) % mod;
		b>>=1;
		a = (a+a)%mod;
	}
	return ret;
}
long long mul(initializer_list<long long> args) {
	long long ret = 1;
	for(auto i : args) ret = base_mul(ret, i);
	return ret;
}
long long mul(long long a, long long b) {
	return base_mul(a, b);
}
/*}}}*/

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

const long long upper = 1e12;
const long long prime_upper = e7;
bool p[prime_upper+10];
long long cnt[100];
long long cal_p(long long prime) { // 对每个素数算贡献
	long long copy = upper;
	int ind = 0;
	while(cnt[ind]) cnt[ind++] = 0;
	ind = 0;
	while(copy) {
		cnt[ind++] = copy - copy/prime;
		copy/=prime;
	}
	long long ret = 0;
	for(int i = 0;cnt[i];i++) {
		for(int j = i+1;cnt[j];j++) {
			ret = add(ret, mul({j-i, cnt[i], cnt[j]}));
		}
	}
	return ret;
}
long long cal1() {
	cout<<"start cal1()"<<endl;
	long long ret = 0;
	for(int i = 2;i<=prime_upper;i++) {
		if(!p[i]) {
			ret = add(cal_p(i), ret);
			for(int j = i<<1;j<=prime_upper;j+=i) p[j] = true;
		}
	}
	cout<<"cal1 over!"<<endl;
	return mul(ret, 2);
}

long long cal2() {
	cout<<"start cal2()"<<endl;
	long long ans = 0;
	long long last = PrimeCnt::solve(upper);
	for(int i = 1;i<upper/prime_upper;i++) {
		cout<<i<<' '<<endl;
		long long now = PrimeCnt::solve(upper/(i+1));
		long long cnt = add(last, mod-(now%mod));
		ans = add(ans, mul({upper-i, 2, i, cnt}));
		last = now;
	}
	cout<<"cal2 over!"<<endl;
	return ans;
}

int main() {
	cout<<add(cal1(), cal2())<<endl;
	return 0;
}

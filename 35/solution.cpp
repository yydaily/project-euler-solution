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
bool p[e6];
int pow10[7];
vector<int>prime;
int check(int a) {
	if(a<10) return 1;
	int length = 0;
	int copy = a;
	while(copy) {
		if((copy&1) == 0) return 0;
		copy /= 10;
		length++;
	}

	copy = a/10 + (a%10)*pow10[length-1];
	while(copy != a) {
		if(p[copy]) return 0;
		copy = copy/10 + (copy%10)*pow10[length-1];
	}
	cout<<a<<endl;
	return 1;
}
int main() {
	pow10[0] = 1;
	for(int i = 1;i<7;i++) pow10[i] = pow10[i-1]*10;
	for(int i = 2;i<e6;i++) {
		if(!p[i]) {
			prime.push_back(i);
			for(int j = i<<1;j<e6;j+=i) p[j] = true;
		}
	}
	int ans = 0;
	for(auto i:prime) ans += check(i);
	cout<<ans<<endl;
	return 0;
}

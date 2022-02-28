#include<iostream>/*{{{*/
#include<vector>
#include<set>
#include<math.h>
#include<map>
#include "../template/bigint.cpp"
#include "../template/prime_cnt.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
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
int num[10];
int p[10] = {0, 2, 3, 5, 7, 11, 13, 17};
bool check() {
	for(int i = 1;i<=7;i++) {
		int now = 0;
		for(int j = i;j<i+3;j++) now = now*10 + num[j];
		if(now % p[i]) return false;
	}
	return true;
}
int main() {
	for(int i = 0;i<10;i++) num[i] = i;
	swap(num[0], num[1]);
	long long ans = 0;
	do {
		if(check()) {
			long long n = 0;
			for(int i = 0;i<10;i++) {
				n = n*10 + num[i];
			}
			ans += n;
		}
	} while(next_permutation(num, num+10));
	cout<<ans<<endl;
	return 0;
}

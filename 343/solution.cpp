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

vector<long long> prime;
void init() {/*{{{*/
	prime.push_back(2);
	for(int i = 3;i<2e6;i+=2) {
		bool isPrime = true;
		for(auto j : prime) {
			if(j*j>i) break;
			if(i%j==0) {
				isPrime = false;
				break;
			}
		}
		if(isPrime) prime.push_back(i);
	}
}/*}}}*/
long long cal(long long b) {
	long long max_prime = -1;
	for(auto i : prime) {
		if(i*i>b) break;
		if(b%i==0) {
			b/=i;
			max_prime = max(max_prime, i);
			while(b%i==0) b/=i;
		}
	}
	return max(b, max_prime);
}
int main() {
	init();
	long long ans = 0;
	auto start = clock();
	for(long long i = 1;i<=2000000;i++) {
		ans += max(cal(i+1), cal(i*i-i+1)) - 1;
		if(i%20000 == 0) cout<<i/20000<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

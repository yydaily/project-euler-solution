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

int cnt(long long a) {
	int ret = 0;
	while(a) {
		ret += a%10;
		a/=10;
	}
	return ret;
}
vector<long long> gen(vector<long long> buf) {
	vector<long long> ret;
	for(auto i : buf) {
		long long now = i*10;
		for(int j = 0;j<10;j++) {
			if(now%cnt(now) == 0) ret.push_back(now);
			now++;
		}
	}
	return ret;
}
int main() {
	Prime::init(e7);
	vector<long long> now;
	vector<long long> buf = now;
	for(int i = 1;i<10;i++) buf.push_back(i);
	long long index = 10;
	while(index<1e13) {
		buf = gen(buf);
		for(auto i : buf) {
			if(Prime::is_prime(i/cnt(i))) {
				now.push_back(i);
			}
		}
		index*=10;
	}
	long long ans = 0;
	for(auto i : now) {
		for(int j = 1;j<10;j+=2) {
			if(Prime::is_prime(i*10+j)) {
				ans+=i*10+j;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

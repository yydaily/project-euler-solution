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

bool ok(int a, int b) {
	string c = to_string(a) + to_string(b);
	return Prime::is_prime(stoi(c));
}
int num[10];
void dfs(int cnt, int start) {
	if(cnt == 5) {
		int sum = 0;
		for(int i = 0;i<5;i++) sum += num[i];
		cout<<sum<<endl;
		exit(0);
	}
	for(int i = start;i<1200;i++) {
		bool can = true;
		for(int j = 0;j<cnt;j++) {
			if(!ok(Prime::prime[i], num[j]) || !ok(num[j], Prime::prime[i])) {
				can = false;
				break;
			}
		}
		if(can) {
			num[cnt] = Prime::prime[i];
			dfs(cnt+1, i+1);
			num[cnt] = 0;
		}
	}
}
int main() {
	Prime::init(e6);
	dfs(0, 0);
	return 0;
}

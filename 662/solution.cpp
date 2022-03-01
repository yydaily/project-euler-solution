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
struct p {
	int x, y;
	int len;
};
vector<p> v;
void add(int a) {/*{{{*/
	for(int i = 0;i<=a;i++) {
		int x = sqrt(a*a-i*i);
		if(x*x + i*i == a*a && i<10000 && x<10000) {
			v.push_back(p{i, x, a});
		}
	}
}/*}}}*/
void init() {
	int a = 0, b = 1;
	while(b<=15000) {
		swap(a, b);
		b+=a;
		add(b);
	}
}
const int x=10000, y=10000;
long long ans[x+1][y+1];
int main() {
	init();
	ans[0][0] = 1;
	for(int i = 0;i<=x;i++) {
		for(int j = 0;j<=y;j++) {
			for(auto dir : v) {
				if(i+dir.x<=x && j+dir.y<=y) ans[i+dir.x][j+dir.y] = add(ans[i+dir.x][j+dir.y], ans[i][j]);
			}
		}
	}
	cout<<ans[x][y]<<endl;
	return 0;
}

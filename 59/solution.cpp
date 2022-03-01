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
int len = 0;
int num[100000];
int base[3];
bool check(char a) {
	if('0' <= a && a <= '9') return true;
	if('a' <= a && a <= 'z') return true;
	if('A' <= a && a <= 'Z') return true;
	if(a == ' ' || a == ',' || a == '.') return true;
	if(a == '(' || a == ')' || a == '[' || a == ']') return true;
	if(a == '?' || a == '!' || a == ';' || a == ':') return true;
	if(a == '-' || a == '+' || a == '*' || a == '/') return true; 
	if(a == '\'' || a == '\"') return true;
	return false;
}
bool check() {
	for(int i = 0;i<len;i++) {
		int now = num[i] ^ base[i%3];
		if(!check(now)) {
			return false;
		}
	}
	return true;
}
int cal() {
	int ans = 0;
	for(int i = 0;i<len;i++) {
		ans += num[i] ^ base[i%3];
	}
	return ans;
}
int main() {
	freopen("./in", "r", stdin);
	int a;
	while(cin>>a) {
		num[len++] = a;
	}
	for(char a = 'a';a<='z';a++) {
		base[0] = a;
		for(char b = 'a';b<='z';b++) {
			base[1] = b;
			for(char c = 'a';c<='z';c++) {
				base[2] = c;
				if(check()) cout<<cal()<<endl;
			}
		}
	}
	return 0;
}

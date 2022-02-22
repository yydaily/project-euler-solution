#include<iostream>/*{{{*/
#include<vector>
#include<set>
#include<math.h>
#include<map>
#include "../template/bigint.cpp"
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

int num1[5] = {6, 7, 8, 9, 10};
int num2[5] = {1, 2, 3, 4, 5};

bool check() {
	int sum = num1[0] + num2[0] + num2[1];
	for(int i = 1;i<5;i++) {
		if(sum != num1[i] + num2[i] + num2[(i+1)%5]) return false;
	}
	return true;
}
string str() {
	string ret = "";
	for(int i = 0;i<5;i++) {
		ret += to_string(num1[i]) + to_string(num2[i]) + to_string(num2[(i+1)%5]);
	}
	return ret;
}
int main() {
	string a = "1111111111111111";
	do {
		for(int i = 0;i<5;i++) num2[i]=i+1;
		do {
			if(check()) {
				if(a.compare(str())<0) {
					a = str();
				}
			}
		} while(next_permutation(num2, num2+5));
	} while(next_permutation(num1+1, num1+5));
	cout<<a<<endl;
	return 0;
}

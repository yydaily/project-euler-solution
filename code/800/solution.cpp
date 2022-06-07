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
long long _mod = e9+7;
using namespace std;/*}}}*/

long double cal(int a, int b) {
	return b * log10(a) + a * log10(b);
}
long double x = 800800;
long double upper = x * log10(x);
int main() {
	Prime::init(5e7);
	long long ans = 0;
	cout<<upper - cal(Prime::prime[0], Prime::prime[Prime::prime.size()-1])<<endl;// < 0
	for(int i = 0;i<Prime::prime.size();i++) {
		for(int j = i+1;j<Prime::prime.size();j++) {
			if(cal(Prime::prime[i], Prime::prime[j]) > upper) break;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

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
#include "../template/fibonacci.cpp"
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

const int mod = 1e9;

int index(int cnt, int mod) {
	return cnt*23 + mod;
}

struct matrix {/*{{{*/
	int num[600][600];
	void show() {
		for(int i = 0;i<600;i++) {
			for(int j = 0;j<600;j++) cout<<num[i][j]<<' ';
			cout<<endl;
		}
		exit(0);
	}
};/*}}}*/

matrix mul(matrix &a, matrix &b) {/*{{{*/
	matrix ret;
	memset(ret.num, 0, sizeof(ret.num));
	for(int i = 0;i<600;i++) {
		for(int j = 0;j<600;j++) {
			for(int k = 0;k<600;k++) {
				ret.num[i][k] = (ret.num[i][k] + 1LL*a.num[i][j]*b.num[j][k]%mod)%mod;
			}
		}
	}
	return ret;
}/*}}}*/

matrix qpow(matrix a, long long cnt) {/*{{{*/
	matrix ret;
	memset(ret.num, 0, sizeof(ret.num));
	for(int i = 0;i<600;i++) ret.num[i][i] = 1;
	while(cnt>0) {
		if(cnt&1) {
			ret = mul(ret, a);
		}
		a = mul(a, a);
		cnt>>=1;
	}
	return ret;
}/*}}}*/

int main() {
	matrix base;
	for(int i = 0;i<=23;i++) { 
		for(int j = 0;j<23;j++) { 
			for(int k = i;k<=min(i+9, 23);k++) { 
				int l = ((j*10) + k-i) % 23;
				base.num[index(i, j)][index(k, l)] += 1;
			}
		}
	}
	long long x = 1;
	for(int i = 1;i<=12;i++) x *= 11;
	base = qpow(base, x);
	cout<<base.num[0][index(23, 0)]<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long add(long long a, long long b) { return (a + b) % mod; }
long long mul(long long a, long long b) {/*{{{*/
	a %= mod; 
	b %= mod;
    return a * b % mod;
}/*}}}*/
long long C[100][100];
void init() {/*{{{*/
    for (int i = 0; i < 100; i++) {
        C[i][0] = 1;
        C[i][i] = 1;
        for (int j = 1; j < i; j++) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
    }
}/*}}}*/
long long cal2(long long x, long long a) {/*{{{*/
	long long ret = 0;
	for(long long i = 0;i<x;i++) {
		for(long long j = 0;j<=i;j++) {
			if(i==j) ret = add(ret, mul(C[x-1][a-1], mul(1LL<<i, 1LL<<i)));
			else if(a>=2) {
				ret = add(ret, mul(mul(2, C[x-2][a-2]), mul(1LL<<i, 1LL<<j)));
			}
		}
	}
	return ret;
}/*}}}*/
long long cal(long long x, long long a) {/*{{{*/
	return mul(C[x-1][a-1], add(1LL<<x, -1));
}/*}}}*/
long long Sum(long long x, long long add_cnt, long long add_val) {/*{{{*/
    long long ans = mul(add_cnt, add_val);
    ans = mul(ans, ans); 
	for(long long i = 1;i<=x;i++) {
		long long base = mul(add_cnt+i, add_cnt+i);
		long long prefix = mul(mul(add_val, add_val), C[x][i]);
		long long suffix =  cal2(x, i);
		long long mid = mul(2, mul(add_val, cal(x, i)));
		ans = add(ans, mul(base, add(prefix, add(suffix, mid))));
	}
	return ans;
}/*}}}*/
int main() {
    init();
    long long upper = 10000LL * 10000 * 10000 * 10000+1;
    long long lower = 0;
    long long cnt = 0;
    long long ans = 0;
    while (upper != lower) {
        long long diff = 0;
        while (upper - lower >= (1LL << diff))
            diff++;
        diff--;
        ans = add(ans, Sum(diff, cnt, lower));
        cnt++;
        lower += 1LL << diff;
    }
    cout << ans << endl;
    return 0;
}

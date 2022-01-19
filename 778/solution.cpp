#include<iostream>
using namespace std;
const long long mod = 1e9+9;
long long upper = 765432;
long long total_cnt = 234567;
long long cnt[10][10]; // the count of i's index is j
void add(long long a) {
	long long x = 0;
	while(a) {
		cnt[x++][a%10]++;
		a/=10;
	}
}
long long cc[10];
long long cc_back[10];
long long cal(long long ind) {
	for(long long i = 0;i<10;i++) cc[i] = cnt[ind][i], cc_back[i] = 0;
	for(long long i = 1;i<total_cnt;i++) {
		for(long long i = 1;i<10;i++) { 
			for(long long j = 1;j<10;j++) {
				cc_back[(i*j)%10] = (cc_back[(i*j)%10] + cc[i] * cnt[ind][j])%mod;
			}
		}
		for(long long i = 1;i<10;i++) {
			cc[i] = cc_back[i];
			cc_back[i] = 0;
		}
	}
	long long ans = 0;
	for(long long i = 1;i<10;i++) ans = (ans + i * cc[i])%mod;
	return ans;
}
int main() {
	for(long long i = 0;i<=upper;i++) add(i);
	long long ans = 0;
	long long base = 1;
	for(long long i = 0;i<10;i++) {
		ans = (ans+cal(i)*base)%mod;
		base*=10;
	}
	cout<<ans<<endl;
	return 0;
}

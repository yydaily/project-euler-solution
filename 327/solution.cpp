#include<bits/stdc++.h>
using namespace std;
long long cal(long long a, long long b) {
	if(a>=b) return b;
	long long base = cal(a, b-1);
	long long cnt = max(0LL, base / (a-2) - 4);
	long long ans = cnt * a; base -= cnt * (a-2);
	if(base <= a-1) {
		return ans + base + 1;
	}
	ans += a; base -= a-1;
	while(base >= a-2) {
		ans += a;
		base -= a-2;
	}
	if(base) ans += base+2;
	return ans;
}
int main() {
	long long ans = 0;
	for(int i = 3;i<=40;i++) {
		ans += cal(i, 31);
	}
	cout<<ans<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int ok(int a) {
	int ret = 0;
	while(a) {
		ret = ret * 10 + a % 10;
		a/=10;
	}
	return ret;
}
int main() {
	int ans = 0;
	for(int i = 100;i<=999;i++) for(int j = 100;j<=999;j++) if(ok(i*j) == i * j) ans = max(ans, i*j);
	cout<<ans<<endl;
	return 0;
}

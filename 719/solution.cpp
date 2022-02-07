#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
long long num[20];
bool check(long long a) {
	auto upper = a*a;
	memset(num, 0, sizeof(num));
	while(upper) {
		num[++num[0]] = upper%10;
		upper/=10;
	}
	for(long long i = (1<<(num[0]-1))-1;i>=1;i--) {
		long long sum = 0;
		long long now = 0;
		for(long long j = 19;j>0;j--) {
			now = now * 10 + num[j];
			if(i&(1<<(j-2))) {
				sum+=now;
				now = 0;
			}
		}
		if(sum+now==a) return true;
	}
	return false;
}
int main() {
	long long ans = 0;
	for(long long i = 1;i<=1000000;i++) if(check(i)) {
		cout<<i<<endl;
		ans+=i*i;
	}
	cout<<ans<<endl;
	return 0;
}

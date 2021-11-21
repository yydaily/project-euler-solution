#include<iostream>
using namespace std;
const int mod = 1e9+7;
int add(int a, int b) { return (a+b)% mod; }
int mul(int a, int b) { return 1ll*a*b%mod; }
const int upper = 1e8;
bool p[upper];
int cal(long long ind) {
	long long buffer = ind;
	while(buffer <= upper) buffer *= ind;
	buffer /= ind;
	return buffer;
}
int main() {
	int ans = 1;
	for(int i = 2;i<upper;i++) {
		if(!p[i]) {
			ans = mul(ans, cal(i));
			for(int j = i<<1;j<upper;j+=i) p[j] = true;
		}
	}
	cout<<mul(ans,2)<<endl;
	return 0;
}

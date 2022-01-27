#include<iostream>
using namespace std;
long long num[10000]; // black end
long long num1[10000]; // red end
long long cal(long long n, long long m) {
	// n blocks, m at least
	memset(num, 0, sizeof(num));
	memset(num1, 0, sizeof(num1));
	num[0] = 1;

	for(long long i = 1;i<=n;i++) {
		num[i] = num[i-1] + num1[i-1];
		if(i>=m) {
			for(long long j = i-m;j>=0;j--) {
				num1[i] += num[j];
			}
		}
	}
	return num[n] + num1[n];
}
int main() {
	for(int i = 10;;i++) {
		long long value = cal(i, 50);
		cout<<i<<' '<<value<<endl;
		if(value >= 1000000) {
			break;
		}
	}
	return 0;
}

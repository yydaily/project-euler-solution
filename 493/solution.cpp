#include<iostream>
#include <iomanip>
using namespace std;
int fac(int a) {
	if(a <= 1) return 1;
	return a * fac(a-1);
}
int C(int a, int b) {
	return fac(a) / fac(b) / fac(a-b);
}
long long get_cnt(int a[10]) {
	long long ret = 1;
	for(int i = 0;i<7;i++) ret *= C(10, a[i]);
	return ret;
}
int main() {
	long long sum = 0;
	long long color = 0;
	int num[10];
	int upper = 11 * 11 * 11 * 11 * 11 * 11 * 11;
	for(int i = 1;i<upper;i++) {
		auto buf = i;
		auto total = 0;
		int c = 0;
		for(int i = 0;i<7;i++) {
			num[i] = buf%11;
			buf/=11;
			c+=num[i]!=0;
			total += num[i];
		}
		if(total == 20) {
			long long cnt = get_cnt(num);
			color += c * cnt;
			sum += cnt;
		}
	}
	cout<<setprecision(11)<<color*1.0/sum<<endl;
	return 0;
}

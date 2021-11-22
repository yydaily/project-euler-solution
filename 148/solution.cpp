#include<iostream>
using namespace std;
long long cal(long long a) {
	if(a<=7) return a*(a+1)/2;
	long long base = 1;
	long long row = 1;
	while(a>row*7) {
		row *= 7;
		base *= 28;
	}
	long long cnt = a / row;
	long long ret = cnt * (cnt + 1) / 2 * base;
	return ret + (cnt+1) * cal(a-cnt*row);
}
int main() {
	cout<<cal(1000 * 1000 * 1000)<<endl;
	return 0;
}

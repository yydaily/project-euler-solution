#include<iostream>
using namespace std;
const int upper = 2e6;
bool p[upper];
int main() {
	long long sum = 0;
	for(int i = 2;i<upper;i++) {
		if(p[i]) continue;
		sum += i;
		for(int j = i<<1;j<upper;j+=i) p[j] = true;
	}
	cout<<sum<<endl;
	return 0;
}

#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
int main() {
	double a = 1.0;
	int ind = 0;
	int cnt = 0;
	while(cnt < 678910) {
		a *= 2;
		ind++;
		if(a>10) a/=10;
		if(1.23<=a && a<1.24) cnt++;
	}
	cout<<ind<<endl;
	return 0;
}

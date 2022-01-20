#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
vector<long long> number;
void gen(long long a) {
	long long len = 0;
	long long digit[5];
	while(a) {
		digit[len++] = a%10;
		a/=10;
	}

	long long v = 0, v2=0;
	for(long long i = len-1;i>=0;i--) {
		v = v*10 + digit[i];
		if(i) v2 = v2*10 + digit[i];
	}
	for(long long i = 0;i<len;i++) {
		v = v*10 + digit[i];
		v2 = v2*10 + digit[i];
	}
	number.push_back(v);
	number.push_back(v2);
}
bool check(long long a) {
	long long cnt = 0;
	for(long long i = 2;i*i*i<=a;i++) {
		long long x = sqrt(a-i*i*i);
		if(x>1 && x*x + i*i*i == a) cnt++;
	}
	return cnt == 4;
}
int main() {
	long long cnt = 0;
	long long sum = 0;
	for(long long i = 0;i<100000;i++) gen(i);
	sort(number.begin(), number.end());
	for(auto i : number) {
		if(check(i)) {
			cnt++;
			cout<<"found "<<i<<endl;
			sum+=i;
		}
		if(cnt==5) break;
	}
	cout<<sum<<endl;
	return 0;
}

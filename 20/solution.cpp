#include<iostream>
#include<vector>
#include<set>
#include<map>
#include "../templete/bigint.cpp"
using namespace std;

int cal(BigInteger a) {
	int ret = 0;
	while(a>0) {
		ret += a.num[0]%10;
		a/=10;
	}
	return ret;
}

int main() {
	auto val = BigInteger(1);
	for(int i= 1;i<=100;i++) {
		val *= i;
	}
	cout<<cal(val)<<endl;
	return 0;
}

#include<iostream>
using namespace std;
int main() {
	int upper = 100;
	int a1 = upper*upper*(upper+1)*(upper+1)/4;
	int a2 = upper*(upper+1)*(upper<<1|1)/6;
	cout<<a1-a2<<endl;
	return 0;
}

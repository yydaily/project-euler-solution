#include<iostream>
#include<math.h>
using namespace std;
int main() {
	for(int i = 3;i<500;i++) {
		for(int j = i+1;j<500;j++) {
			double k = sqrt(i*i+j*j);
			if(fabs(k-int(k)) <=1e-8 && i + j + k == 1000) {
				cout<<i*j*int(k)<<endl;
			}
		}
	}
	return 0;
}

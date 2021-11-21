#include<bits/stdc++.h>
using namespace std;

const int mod = 1e6;
const int length = 1e5;
long long  pp[length];
long long asist[length<<1];
void myinit() {
	for(int i=0;i<length;i++) {
		asist[i<<1]=i*(i*3-1)/2;
		asist[i<<1|1]=i*(i*3+1)/2;
	}
}
void mymethod() {
	pp[1]=1;
	pp[2]=2;
	pp[0]=1;
	for(int i=3;i<length;i++) {
		int k=0;
		int flags;
		for(int j=2;asist[j]<=i;j++) {
			flags=k&2;
			if(!flags) pp[i]=(pp[i]+pp[i-asist[j]]+mod)%mod;
			else pp[i]=(pp[i]-pp[i-asist[j]]+mod)%mod;
			k++;
			k&=7;
		}
	}
}
 
int main() { 
	myinit();
	mymethod();
	for(int i = 1;i<length;i++) {
		cout<<i<<' '<<pp[i]<<endl;
		if(pp[i] == 0) return 0;
	}
    return 0;
}

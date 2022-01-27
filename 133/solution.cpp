#include<iostream>
using namespace std;
int remind;
int base;
int mod;
void init(int mod_) {
	remind = 1;
	base = 10;
	mod = mod_;
}
int gen() {
	int basic = remind;
	for(int i = 1;i<10;i++) remind = (1LL * remind*base + basic)%mod;
	basic = base;
	for(int i = 1;i<10;i++) base = (1LL * base*basic)%mod;
	return remind;
}

bool flag[123456];

bool handle(int a) {
	init(a);
	for(int i = 0;i<a;i++) flag[i] = false;
	for(int i = 0;;i++) {
		if(remind == 0) {
			return true;
		}
		if(flag[remind]) return false;
		flag[remind] = true;
		gen();
	}
}

bool prime[123456];

int main() {
	long long sum = 0;
	for(int i = 2;i<100000;i++) {
		if(!prime[i]) {
			if(!handle(i)) sum+=i;
			for(int j = i<<1;j<100000;j+=i) prime[j] = true;
		}
	}
	cout<<sum<<endl;
	return 0;
}

#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
const int upper = 2e7+10;
bool p[upper];
long long minn[upper];
void init() {
	for(int i = 2;i<upper;i++) {
		if(!p[i]) {
			for(int j = i;j<upper;j+=i) {
				p[j] = true;
				minn[j] = i;
			}
		}
		minn[i] = minn[i/minn[i]] + minn[i];
	}
}
int main() {
	init();
	int lower = 15000000, upper = 20000000;
	long long ans = 0;
	for(int i = 1;i<=upper-lower;i++) {
		ans += minn[lower+i] - minn[i];
		assert(ans > 0);
	}
	cout<<ans<<endl;
	return 0;
}

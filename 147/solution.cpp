#include<iostream>
int cal(int a, int b) {
	if(a>b) std::swap(a, b);
	a<<=1, b<<=1;

	int ret = 0;
	// parallel
	for(int i = 0;i<a;i+=2) {
		for(int j = 0;j<b;j+=2) {
			for(int l = i+1;l<=a;l+=2) {
				ret += (b-j)/2;
			}
		}
	}

	// vertical
	for(int i = 0;i<a;i++) {
		for(int j = i&1;j<b;j+=2) {
			for(int l = std::min(j, a-i);l>=1;l--) {
				int upper = std::min(a-i-l+1, b-j+1);
				ret+=upper-std::max(1, l-j);
			}
		}
	}
	
	return ret;
}
int main() {
	int ans = 0;
	for(int i = 1;i<=47;i++) {
		for(int j = 1;j<=43;j++) {
			ans += cal(i, j);
		}
	}
	std::cout<<ans<<std::endl;
	return 0;
}

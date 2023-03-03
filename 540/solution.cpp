#include<iostream>/*{{{*/
#include<math.h>
#include<vector>
#include "../template/prime.cpp"
using namespace std;/*}}}*/
const long long upper = 1e6;
long long gcd(long long a, long long b) {
	if(a==0) return b;
	return gcd(b%a, a);
}
long long cal(long long a, long long b) {
	// [1, b] 范围内与a互质数的个数
	vector<long long> factor_a;
	while(a!=1) {
		auto p = Prime::MinPrime(a);
		factor_a.push_back(p);
		while(a%p==0) a/=p;
	}
	long long ret = b;
	for(long long i = (1<<factor_a.size())-1;i>0;i--) {
		bool add = true;
		long long now = 1;
		for(int j = 0;j<factor_a.size();j++) {
			if(i&(1<<j)) {
				add = !add;
				now *= factor_a[j];
			}
		}
		ret += (add?1:-1) * (b/now);
	}
	return ret;
}
long long P(long long upper) {
	long long ans = 0;
	for(long long i = 1;2*i*i <= upper;i++) {
		long long j_upper = sqrt(upper-i*i);
		long long j_lower = i-1;
		if(i&1) {
			j_upper>>=1;
			j_lower>>=1;
		}

		auto val = max(0LL, cal(i, j_upper) - cal(i, j_lower));
		if((i&65535) == 0) cout<<i<<' '<<val<<endl;
		ans+=val;
	}
	return ans;
}
int main() {
	Prime::init(3e7);
	cout<<P(20)<<endl;
	cout<<P(1e6)<<endl;
	cout<<P(3141592653589793)<<endl;
	return 0;
}

#include<vector>
namespace Prime {
	std::vector<bool> p;
	std::vector<int> max_prime;
	std::vector<int> prime;
	bool inited = false;
	void init(int upper) {
		if(inited) return ;
		inited = true;
		p = std::vector<bool>(upper, true);
		max_prime = std::vector<int>(upper, 0);
		for(int i = 2;i<upper;i++) {
			if(p[i]) {
				prime.push_back(i);
				for(int j = i;j<upper;j+=i) {
					max_prime[j] = i;
					p[j] = false;
				}
			}
		}
	}
	bool is_prime(long long a) {
		for(auto i : prime) {
			if(1LL*i*i>a) return true;
			if(a%i==0) return false;
		}
		return true;
	}
};

#include<map>
namespace euler {
	std::map<int, int> Phi;
	int upper = 0;
	void init(int n) {
		upper = n;
		for (int i = 1; i <= n; i++) Phi[i] = i;
		for (int i = 2; i <= n; i++) if (Phi[i] == i) 
			for (int j = i; j <= n; j += i) Phi[j] = Phi[j] / i * (i - 1);
	}
	inline long long phi(long long n) {
		if(n<upper) return Phi[n];
		long long ans = n;
		for (long long i = 2; i * i <= n; ++i)
			if (n % i == 0) {
				ans = ans / i * (i - 1);
				while (n % i == 0) n /= i;
			}
		if (n > 1) ans = ans / n * (n - 1);
		return ans;
	}
};

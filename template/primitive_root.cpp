#include <vector>
namespace primitive_root {
	int gcd(int a, int b) {
		if(a==0) return b;
		return gcd(b%a, a);
	}
	std::vector<int> get_factors(int a) {
		std::vector<int> v;
		for (int i = 1; i * i <= a; ++i)
			if (a % i == 0) {
				v.push_back(i);
				if (i * i != a) v.push_back(a / i);
			}
		return v;
	}
	int qpow(long long a, int b, int mod) {
		long long ret = 1;
		while(b) {
			if(b&1) ret = (ret*a) % mod;
			a = (a*a) % mod;
			b>>=1;
		}
		return ret;
	}

	// remember to call euler::init()
	int get_minimum_primitive_root(int m) {
		int phiM = euler::phi(m);
		auto factors = get_factors(phiM);
		for (int i = 1;i<m; ++i) {
			if (gcd(i, m) != 1)
				continue;
			bool ok = true;
			for (auto e : factors)
				if (e != phiM && qpow(i, e, m) == 1) {
					ok = false;
					break;
				}
			if (ok)
				return i;
		}
		return -1;
	}

	// 调用方需要保证一定有原根
	std::vector<int> get_primative_roots(int m) {
		std::vector<int> v;
		long long phiM = euler::phi(m), fst;
		auto factors = get_factors(phiM);
		for (int i = 1;; ++i) {
			if (gcd(i, m) != 1)
				continue;
			bool ok = true;
			for (auto e : factors)
				if (e != phiM && qpow(i, e, m) == 1) {
					ok = false;
					break;
				}
			if (ok) {
				fst = i;
				break;
			}
		}
		long long cur = fst;
		for (int i = 1; i <= phiM; ++i) {
			if (gcd(phiM, i) == 1)
				v.push_back(cur);
			cur = cur * fst % m;
		}
		return v;
	}
}

#include <vector>
#include <map>
namespace Prime {
	std::vector<bool> p;
	std::vector<int> max_prime;
	std::vector<int> min_prime;
	std::vector<int> prime;
	std::map<int, int> prime_index; // index[2] = 1, index[3] = 2, index[5] = 3, index[7] = 4
	bool inited = false;
	int upper;
	void init(int _upper) {/*{{{*/
		if(inited) return ;
		upper = _upper;
		inited = true;
		p = std::vector<bool>(_upper, true);
		max_prime = std::vector<int>(_upper, 0);
		min_prime = std::vector<int>(_upper, 0);
		p[0] = p[1] = false;
		int index = 0;
		for(int i = 2;i<_upper;i++) {
			if(p[i]) {
				prime_index[i] = ++index;
				prime.push_back(i);
				for(int j = i;j<_upper;j+=i) {
					max_prime[j] = i;
					p[j] = false;
					if(min_prime[j]) continue;
					min_prime[j] = i;
				}
				p[i] = true;
			}
		}
	}/*}}}*/
	long long MinPrime(long long a) {/*{{{*/
		if(a<upper) return min_prime[a];
		for(auto i : prime) {
			if(1LL*i*i>a) break;
			if(a%i==0) return i;
		}
		assert(a!=1);
		return a;
	}/*}}}*/
	bool is_prime(long long a) {/*{{{*/
		return MinPrime(a) == a;
	}/*}}}*/
	int coprime(int a) {/*{{{*/
		// return the count of i where i is coprime of a and i in [1, a)
		std::vector<int> p;
		int copy = a;
		while(copy != 1) {
			int now = max_prime[copy];
			p.push_back(now);
			while(copy%now==0) copy/=now;
		}

		int ret = a;
		for(int i = 1;i<(1<<p.size());i++) {
			int now = 1;
			int cnt = 0;
			for(int j = 0;j<p.size();j++) {
				if(i&(1<<j)) {
					now *= p[j];
					cnt ^= 1;
				}
			}
			if(cnt) ret -= a/now;
			else ret += a/now;
		}
		return ret;
	}/*}}}*/
	
	// miller-rabin
	long long mul(long long a, long long b, long long mod) {/*{{{*/
		long long ret = 0;
		while(b) {
			if(b&1) ret = (ret + a) % mod;
			a = (a+a)%mod;
			b>>=1;
		}
		return ret;
	}/*}}}*/
	long long qpow(long long a, long long n, long long mod) {/*{{{*/
		long long ret = 1;
		while(n) {
			if(n&1) ret = mul(ret, a, mod);
			a = mul(a, a, mod);
			n>>=1;
		}
		return ret;
	}/*}}}*/
	bool miller_rabin(long long n) {/*{{{*/
		if (n == 2) return true;
		if (n < 2 || !(n & 1)) return false;
		long long m = n - 1, k = 0;
		while (!(m & 1)) {
			k++;
			m >>= 1;
		}
		for (int i = 1; i <= 20; i++) {
			long long a = rand() % (n - 1) + 1;
			long long x = qpow(a, m, n);
			long long y;
			for (int j = 1; j <= k; j++) {
				y = mul(x, x, n);
				if (y == 1 && x != 1 && x != n - 1)
					return false;
				x = y;
			}
			if (y != 1) return false;
		}
		return true;
	}/*}}}*/

	std::map<int, int> factor(long long a) {
		std::map<int, int> ret;
		while(a!=1) {
			auto p = MinPrime(a);
			a/=p;
			ret[p] = 1;
			while(a%p==0) {
				ret[p]++;
				a/=p;
			}
		}
		return ret;
	}

	std::vector<int> all_factor(long long a, bool with_sort=false) {
		auto m = factor(a);
		std::vector<int> ret(1, 1);
		for(auto i : m) {
			long long l = ret.size();
			long long base = 1;
			for(int j = 1;j<=i.second;j++) {
				base *= i.first;
				for(int k = 0;k<l;k++) ret.push_back(ret[k] * base);
			}
		}
		if(with_sort) sort(ret.begin(), ret.end());
		return ret;
	}
};

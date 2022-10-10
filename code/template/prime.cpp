#include <vector>
namespace Prime {
	std::vector<bool> p;
	std::vector<int> max_prime;
	std::vector<int> min_prime;
	std::vector<int> prime;
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
		for(int i = 2;i<_upper;i++) {
			if(p[i]) {
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
	bool is_prime(long long a) {/*{{{*/
		if(a<=1) return false;
		for(auto i : prime) {
			if(1LL*i*i>a) return true;
			if(a%i==0) return false;
		}
		return true;
	}/*}}}*/
	long long MinPrime(long long a) {/*{{{*/
		assert(a>1);
		if(a<upper) return min_prime[a];
		for(auto i : prime) {
			if(1LL*i*i>a) break;
			if(a%i==0) return i;
		}
		assert(a!=1);
		return a;
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
};

#include<iostream>
#include<vector>
#include<math.h>
#include<map>

/*
PN筛的原理是：
要求 F(n) = \sum_{i=1}^n f(i)，我们构造一个容易求前缀和的极性函数 g(x)，满足对所有的prime，有g(prime) = f(prime)，并令G(n) = \sum_{i=1}^n g(i)
令 h = f/g，除法是狄利克雷卷积除法，用于f,g都是积性函数，容易得到h也是积性函数，且容易得到 h(1) = f(1) / g(1) = 1。且对于prime, f(prime) = g(1)*h(prime) + g(prime)*h(1) = h(prime)+g(prime)。由于g(prime) = f(prime)，所以h(prime) = 0，也即对于所有非PN，都有h(n) = 0。

F(n) = \sum_{d=1, d is PN}^n h(d) G(n/d)

由于PN的数量是 O(\sqrt(n)) 的，如果G(n/d) 能快速求，则F(n) 能快速求

算法过程：
1. 构造 g
2. 构造 G 的快速算法
3. 搜索 PN，并累加答案，这个过程中会需要计算 h(prime^c)，缓存化加速
4. 输出结果

本模板你需要实现的部分:
1. G(n) 函数
2. f(prime, c) 函数, return f(prime^c)
3. g(prime, c) 函数, return g(prime^c)

使用方法：
1. init(mod, f, g, G);
2. cout<<dfs(n)<<endl;
 */

class PNSieve {
private:
	std::vector<long long> prime;
	long long _mod;
	long long (*f)(long long, long long);
	long long (*g)(long long, long long);
	long long (*G)(long long);

public:
	void init(long long mod, 
			long long (*_f)(long long, long long),
			long long (*_g)(long long, long long),
			long long (*_G)(long long)) {
		_mod = mod;
		f = _f;
		g = _g;
		G = _G;
	}

private:
	void sieve(int _upper) {
		std::vector<bool> p(_upper+1, true);
		p[0] = p[1] = false;
		for(int i = 2;i<=_upper;i++) {
			if(p[i]) {
				prime.push_back(i);
			}
			for(auto prim : prime) {
				if(prim*i > _upper) break;
				p[prim*i] = false;
				if(i%prim==0) break;
			}
		}
	}

	std::map<std::string, long long> cache;
	long long H(long long p, long long c) {
		if(c==0) return 1;
		if(c==1) return 0;
		std::string key = std::to_string(p) + " " + std::to_string(c);
		if(cache[key]) return cache[key];

		long long ret = f(p, c);
		for(int i = 1;i<=c;i++) {
			ret = (ret - g(p, i) * H(p, c-i) % _mod) % _mod;
		}
		cache[key] = ret;
		return ret;
	}

	long long ans;
	long long upper;
	void dfs(int prime_index = 0, long long now = 1, long long h_now = 1) {
		std::cout<<"dfs: "<<prime_index<<" "<<now<<" "<<h_now<<std::endl;
		// now 是 一个 PN
		if(prime_index >= prime.size() || now * prime[prime_index] > upper) {
			ans = (ans + h_now * G(upper / now) % _mod) % _mod;
			return ;
		}
		dfs(prime_index + 1, now, h_now);
		long long p = prime[prime_index] * prime[prime_index];
		for(int e = 2; now <= upper / p; p *= prime[prime_index], e++) {
			dfs(prime_index + 1, now * p, h_now * H(prime[prime_index], e));
		}
	}

public: 
	long long solve(long long n) {
		sieve(sqrt(n));	
		std::cout<<prime.size()<<std::endl;
		ans = 0;
		upper = n;
		dfs();
		return ans;
	}
};

long long qpow(long long a, long long b, long long _mod) {
	a%=_mod;
	long long ret = 1;
	while(b) {
		if(b&1) ret = ret * a % _mod;
		a = a * a % _mod;
		b >>= 1;
	}
	return ret;
}

const long long mod = 1e9+7;
long long f(long long p, long long c) {
	return qpow(p, c-1, mod) * (p-1) % mod;
}

long long inv2 = 5e8+4;

long long g(long long p, long long c) {
	if(c==0) return 1;
	return (qpow(p, c, mod) - 1 + mod) % mod;
}

long long G(long long n) {
	return n*(n-1)%mod*inv2%mod + 1;
}
int main() {
	auto pns = PNSieve();
	pns.init(mod, f, g, G);
	std::cout<<pns.solve(6)<<std::endl;
	return 0;
}

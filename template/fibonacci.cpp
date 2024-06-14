#include<iostream>

// f(1) = 1, f(2) = 1, f(3) = 2
namespace Fibonacci {
	long long mod;
	void init(long long _mod) {/*{{{*/
		mod = _mod;
	}/*}}}*/
	long long mul(long long a, long long b) {/*{{{*/
		long long ret = 0;
		while(b) {
			if(b&1) ret = (ret + a) % mod;
			a = (a + a) % mod;
			b>>=1;
		}
		return ret;
	}/*}}}*/

	struct m {
		long long num[2][2];
	};
	m mul(m &a, m &b) {/*{{{*/
		m ret;
		ret.num[0][0] = (mul(a.num[0][0], b.num[0][0]) + mul(a.num[0][1], b.num[1][0])) % mod;
		ret.num[0][1] = (mul(a.num[0][0], b.num[0][1]) + mul(a.num[0][1], b.num[1][1])) % mod;
		ret.num[1][0] = (mul(a.num[1][0], b.num[0][0]) + mul(a.num[1][1], b.num[1][0])) % mod;
		ret.num[1][1] = (mul(a.num[1][0], b.num[0][1]) + mul(a.num[1][1], b.num[1][1])) % mod;
		return ret;
	}/*}}}*/
	m qpow(m a, long long b) {/*{{{*/
		m ret;
		ret.num[0][0] = ret.num[1][1] = 1;
		ret.num[0][1] = ret.num[1][0] = 0;
		while(b) {
			if(b&1) ret = mul(ret, a);
			a = mul(a, a);
			b>>=1;
		}
		return ret;
	}/*}}}*/

	void gen_fib(long long x, long long &a, long long &b) {
		if(x == 0) {a = 0; b = 1; return ;}
		long long a_, b_;
		gen_fib(x/2, a_, b_);
		if(x%2 == 0){
			a = mul(a_, (b_*2 - a_ + mod) % mod);
			b = (mul(a_,a_) + mul(b_,b_)) % mod;
			return ;
		} 
		a = (mul(a_,a_) + mul(b_,b_)) % mod;
		b = (a + mul(a_, (b_*2 - a_ + mod) % mod)) % mod;
		return ;
	}

	long long fib(long long index) {
		long long ret, _;
		gen_fib(index, ret, _);
		return ret;
	////if(index<=2) return 1;
	////m buf;
	////buf.num[0][0] = buf.num[0][1] = buf.num[1][0] = 1;
	////buf.num[1][1] = 0;
	////buf = qpow(buf, index-1);
	////return buf.num[0][0];
	}
}



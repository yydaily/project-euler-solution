#include <math.h>
#include <string.h>

namespace PrimeCnt {
	typedef long long LL;
	LL n, lim, top;
	const LL maxn = 2*1e6+5, maxnn = 1e6+5;
	bool isprime[maxn], flag;
	LL g[maxn], h[maxn], primes[maxn];
	bool has_sieve = false;
	void sieve() {/*{{{*/
		memset(isprime, true, sizeof(isprime));
		for (LL i = 2; i<maxnn; i++) {
			if (isprime[i]) {
				primes[++top] = i;
				for (LL j = (i<<1); j<maxnn; j+=i) {
					isprime[j] = false;
				}
			}
		}
	}/*}}}*/
	LL sz(LL x) {/*{{{*/
		if (flag) {
			if (x>=lim) {
				return n/x;
			}
			return (lim<<1)-x;
		}
		if (x>lim) {
			return n/x;
		}
		return (lim<<1)+1-x;
	}/*}}}*/
	void init() {/*{{{*/
		flag = false;
		lim = sqrt(1.0*n);
		for (LL i = 1; i<=lim; i++) {
			h[i] = n/i;
			g[i] = n/i-1;
		}
		if (lim*lim<n) {
			for (LL i = lim+1; i<=(lim<<1); i++) {
				h[i] = (lim<<1)+1-i;
				g[i] = (lim<<1)-i;
			}
		}
		else {
			for (LL i = lim+1; i<=(lim<<1)-1; i++) {
				h[i] = (lim<<1)-i;
				g[i] = (lim<<1)-i-1;
			}
			flag = true;
		}
	}/*}}}*/
	LL gettot() {/*{{{*/
		LL lo = 1, hi = top;
		while(lo < hi) {
			LL mid = (lo+hi)>>1;
			primes[mid]> lim?hi = mid:lo = mid+1;
		}
		return --lo;
	}/*}}}*/
	LL solve(long long n_) {/*{{{*/
		if(!has_sieve) {
			sieve();
			has_sieve = true;
		}
		n = n_;
		init();
		LL tot = gettot();
		for (LL i = 1; i<=tot; i++) {
			for (LL j = 1; h[j]>=primes[i]*primes[i]; j++) {
				int t = sz(h[j]/primes[i]); 
				g[j] -= g[t]-(i-1);
			}
		}
		return g[1];
	}/*}}}*/
}

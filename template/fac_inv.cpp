#include <vector>
#include <iostream>

namespace FacInv {
	std::vector<long long> fac, inv, fac_inv;
	long long _mod = 1e9+7;

	long long pow(long long a, long long b, long long mod) {
		long long ret = 1;
		while(b) {
			if(b&1) ret = ret*a % mod;
			a = a*a % mod;
			b >>= 1;
		}
		return ret;
	}

	void init(int length = 1e6, int mod = 1e9+7) {
		_mod = mod;
		fac.resize(length+1);
		inv.resize(length+1);
		fac_inv.resize(length+1);

		fac[0] = 1;
		for(int i = 1;i<=length;i++) fac[i] = fac[i-1]*i % _mod;

		fac_inv[length] = pow(fac[length], _mod-2, _mod);
		for(int i = length-1;i>=0;i--) {
			fac_inv[i] = fac_inv[i+1]*(i+1) % _mod;
			inv[i+1] = fac_inv[i+1]*fac[i] % _mod;
		}
	}

	long long C(int n, int k) {
		if(n < k) return 0;
		if(n >= fac.size()) {
			std::cout<<"n >= fac.size()"<<std::endl;
			exit(0);
		}
		return fac[n]*fac_inv[k] % _mod*fac_inv[n-k] % _mod;
	}
}

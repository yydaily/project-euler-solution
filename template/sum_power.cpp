#include<vector>
using namespace std;
namespace sum_power { // cal \sum_{i=1}^n i^k
	int N = 0;
	long long mod;
	vector<int> bernoulli, inv;
	vector<vector<int>>combinations;
	long long solve(long long n,int k){ /*{{{*/
		n = (n+1)%mod;
		long long tmp=n;
		long long ans=0;
		for(int i=1;i<=k+1;i++){
			ans=(ans+(long long)combinations[k+1][i]*bernoulli[k+1-i]%mod*n%mod)%mod;
			n=(long long)n*tmp % mod;
		}
		ans=(long long)ans*inv[k+1] % mod;
		return ans;
	}/*}}}*/
	void init_combinations() {/*{{{*/
		combinations[0][0]=1;
		for (int i=1;i<N;i++){
			for (int j=1;j<=i;j++)
				combinations[i][j]=(combinations[i-1][j-1]+combinations[i-1][j])%mod;
			combinations[i][0]=1;
		}
	}/*}}}*/
	void init_inv() {/*{{{*/
		inv[1]=1;
		for(int i=2;i<N;i++) inv[i]=(long long)inv[mod%i]*(mod-mod/i)%mod;
	}/*}}}*/
	void init_bernoulli() {/*{{{*/
		bernoulli[0]=1;
		for(int i=1;i<N;i++){
			bernoulli[i]=0;
			for(int k=0;k<i;k++)
				bernoulli[i]=(bernoulli[i]+(long long)combinations[i+1][k]*bernoulli[k]%mod)%mod;
			bernoulli[i]=((long long)bernoulli[i]*(-inv[i+1]) % mod+mod)%mod;
		}
	}/*}}}*/
	void init(int _N, int _mod = 1e9+7){/*{{{*/
		mod = _mod;
		if(N == 0) {
			N = _N;
			bernoulli.resize(N+5);
			inv.resize(N+5);
			combinations.resize(N+5);
			for(int i = 0;i<=N+4;i++) combinations[i].resize(N+5);
		}
		
		init_combinations();
		init_inv();
		init_bernoulli();	
	}/*}}}*/
};

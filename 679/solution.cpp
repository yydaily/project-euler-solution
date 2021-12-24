#include<bits/stdc++.h>
using namespace std;
long long dp[34][4*4*4*4][16];
// A E F R
// 2311 = 2 * 64 + 3 * 16 + 1 * 4 + 1 * 1 = 128 + 48 + 4 + 1 = 181
// 2031 = 2 * 64 + 0 * 16 + 3 * 4 + 1 * 1 = 128 +  0 +12 + 1 = 141
// 0310 = 0 * 64 + 3 * 16 + 1 * 4 + 0 * 1 =   0 + 48 + 4 + 0 = 52
// 3112 = 3 * 64 + 1 * 16 + 1 * 4 + 2 * 1 = 192 + 16 + 4 + 2 = 214
// 03100
long long len = 30;

int num[4] = {181, 141, 52, 214};
int get_next(int val) {
	for(int i = 0;i<4;i++) if(val == num[i]) return 1<<i;
	return 0;
}

int main() {
	for(long long i = 0 ;i<256;i++) dp[4][i][0] = 1;
	for(long long i = 0;i<4;i++) dp[4][num[i]][1<<i] = 1, dp[4][num[i]][0] = 0;
	for(long long i = 5;i<=len;i++) {
		for(long long j = 0;j<256;j++) {
			for(long long k = 0;k<4;k++) {
				long long now = ((j&63)<<2) | k;
				int next = get_next(now);
				for(long long vis = 0;vis < 16;vis++) {
					if(vis&next) continue;
					dp[i][now][vis|next] += dp[i-1][j][vis];
					cout<<i<<' '<<now<<' '<<(vis|next)<<' '<<dp[i][now][vis|next]<<' '<<vis<<endl;
				}
			}
		}
	}
	long long ans = 0;
	for(long long i = 0;i<256;i++) ans+=dp[len][i][15];
	cout<<ans<<endl;
	return 0;
}

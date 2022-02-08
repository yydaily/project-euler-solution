#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
const int mod = 1e6;
long long cnt[8]; // count of palindromic
long long cnt2[8]; // count of palindromic contains 2
void display(int ind) {
	cout<<"ind = "<<ind<<", mod = "<<cnt2[ind&7]<<endl;
}
int main() {
	cnt[0] = 1;
	cnt2[2] = 1;

	long long summary_cnt[2] = {1, 0};
	long long summary_cnt2[2] = {0, 0};

	for(int i = 1;;i++) {
		int ind = i&7;
		int sum_ind = i&1;

		cnt[ind] = 1;
		if(i>=4) cnt2[ind] = (-cnt2[ind^4] + cnt[ind^4])%mod;

		cnt[ind] = (cnt[ind] + summary_cnt[sum_ind])%mod;
		cnt2[ind] = (cnt2[ind] + summary_cnt2[sum_ind])%mod;
		if(i==42||i==6||i==20) display(i);
		if(i > 42 && cnt2[ind] == 0) {
			display(i);
			break;
		}
		summary_cnt[sum_ind] = (summary_cnt[sum_ind] + cnt[ind])%mod;
		summary_cnt2[sum_ind] = (summary_cnt2[sum_ind] + cnt2[ind]) % mod;
	}
	return 0;
}

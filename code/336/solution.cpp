#include<iostream>/*{{{*/
#include<vector>
#include<set>
#include<math.h>
#include<map>
#include "../template/bigint.cpp"
#include "../template/prime_cnt.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
#include "../template/prime.cpp"
#include "../template/pell.cpp"
#include "../template/fibonacci.cpp"
const long long e2 = 100;
const long long e3 = e2*10;
const long long e4 = e3*10;
const long long e5 = e4*10;
const long long e6 = e4*e2;
const long long e7 = e6*10;
const long long e8 = e7*10;
const long long e9 = e8*10;
long long _mod = e9+7;
using namespace std;/*}}}*/

void my_swap(vector<int> &num, int index1, int index2) {
	while(index1 < index2) {
		swap(num[index1], num[index2]);
		index1++;
		index2--;
	}
}
int cal(vector<int> num) {
	int ans = 0;
	for(int i = 1;i<=num.size();i++) {
		if(num[i-1] == i) continue;
		if(num[num.size()-1] == i) {
			my_swap(num, i-1, num.size()-1);
			ans++;
		}
		for(int j = i;j<num.size();j++) {
			if(num[j] == i) {
				ans+=2;
				my_swap(num, j, num.size()-1);
				my_swap(num, i-1, num.size()-1);
			}
		}
	}
	return ans;
}

void solve(int n, int index) {
	vector<int> num(n);
	for(int i = 1;i<=n;i++) num[i-1] = i;
	int count = 0;
	while(next_permutation(num.begin(), num.end())) {
		count = max(count, cal(num));
	}

	cout<<n<<' '<<count<<endl;

	for(int i = 1;i<=n;i++) num[i-1] = i;
	while(next_permutation(num.begin(), num.end())) {
		if(cal(num) == count) {
			index --;
		}
		if(index <= 0) {
			for(auto i : num) cout<<char(i+'A'-1);
			cout<<endl;
			return ;
		}
	}
}
int main() {
	solve(11, 2011);
	return 0;
}

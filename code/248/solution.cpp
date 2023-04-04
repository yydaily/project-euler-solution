#include<iostream>/*{{{*/
#include<vector>
#include "../template/prime.cpp"
using namespace std;/*}}}*/
int cache[] = {2, 3, 5, 7, 11, 13};
struct poi {
	int cnt[6];
	long long now;
	poi() {};
	poi(int * a, long long _n) {
		for(int i = 0;i<6;i++) {
			cnt[i] = a[i];
		}
		now = _n;
	}
	poi(long long _n) {
		memset(cnt, 0, sizeof(cnt));
		now = _n;
		for(int i = 0;i<6;i++) {
			while(_n % cache[i] == 0) {
				_n /= cache[i];
				cnt[i]++;
			}
		}
		assert(_n == 1);
	}
	bool contains(poi & ano) {
		for(int i = 0;i<6;i++) if(ano.cnt[i] > cnt[i]) return false;
		return true;
	}
	poi merge(poi & ano) {
		poi res(cnt, now * ano.now);
		for(int i = 0;i<6;i++) res.cnt[i] -= ano.cnt[i];
		return res;
	}
	bool check() {
		for(int i = 0;i<6;i++) if(cnt[i]) return false;
		return true;
	}
	void display() {
		for(int i = 0;i<6;i++) cout<<cnt[i]<<' ';
		cout<<now<<endl;
	}
};
vector<poi> v;
long long power(long long a, long long b) {
	if(b<=0) return 1;
	return a * power(a, b-1);
}
void add(int *cnt) {
	long long a = power(2, cnt[0]) * power(3, cnt[1]) * power(5, cnt[2]) * power(7, cnt[3]) * power(11, cnt[4]) * power(13, cnt[5]);
	if(Prime::is_prime(a+1)) {
		v.push_back(poi(cnt, a+1));
	}
}


bool add(vector<int> & p, long long val, int cnt) {
	if(val==1) return true;
	bool ok = true;
	while(val != 1) {
		auto pri = Prime::MinPrime(val);
		val /= pri;
		for(int i = 0;i<6;i++) if(pri == cache[i]) {
			p[i]+=cnt;
			if(p[i] < 0) ok = false;
		}
	}
	return ok;
}

vector<poi> res;
vector<long long> ans;

void merge(poi & x) {
	int l = res.size();
	for(int i = 0 ;i<l;i++) {
		if(!res[i].contains(x)) continue;

		auto origin = res[i].merge(x);
		res.push_back(origin);

		if(x.now>13) continue;
		auto y = poi(x.now);
		while(origin.contains(y)) {
			origin = origin.merge(y);
			res.push_back(origin);
		}
	}
	for(int i = l;i<res.size();i++) {
		if(res[i].check()) {
			ans.push_back(res[i].now);
		}
	}
}

int main() {
	Prime::init(1e6);
	for(int i = 0;i<=10;i++) for(int j = 0;j<=5;j++) for(int k = 0;k<=2;k++) for(int l = 0;l<8;l++) {
		int gar[6] = {i, j, k, (l&1)>0?1:0, (l&2)>0?1:0, (l&4)>0?1:0};
		add(gar);
	}
	int gar[6] = {10, 5, 2, 1, 1, 1};
	res.push_back(poi(gar, 1));
	for(auto i : v) merge(i);
	sort(ans.begin(), ans.end());
	cout<<ans[0]<<endl;
	cout<<ans[150000 - 1]<<endl;
	return 0;
}

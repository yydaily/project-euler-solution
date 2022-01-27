#include<iostream>
#include<math.h>
#include<map>
#include<vector>
using namespace std;
const long long upper = 2500;
const long long mod = 50515093;
long long *x, *y;
long long start = 290797;
long long gen(long long &a) {/*{{{*/
	a = (a*a)%mod;
	return (a%2000)-1000;
}/*}}}*/
long long gcd(long long a, long long b) {/*{{{*/
	if(a==0) return b;
	return gcd(b%a, a);
}/*}}}*/
map<long long, vector<pair<long long, long long>>> edges;
void gen(long long ind1, long long ind2) {/*{{{*/
	long long dirx = x[ind1]-x[ind2], diry = y[ind1]-y[ind2];
	if(dirx<0) {
		dirx = -dirx;
		diry = -diry;
	}
	if(dirx == 0) {
		diry = abs(diry);
	}
	long long g = gcd(dirx, abs(diry));
	dirx/=g;
	diry/=g;
	edges[dirx*10000 + (diry+3000)].emplace_back(x[ind1], y[ind1]);
}/*}}}*/
vector<long long> a;
long long sum_a = 0;
void handle() {
	for(auto i = edges.begin();i!=edges.end();i++) {
		long long dirx = i->first / 10000;
		long long diry = i->first - dirx*10000 - 3000;
		auto &pois = i->second;
		long long edge_cnt = 0;
		for(long long i = 0;i<pois.size();i++) {
			bool unique = true;
			for(long long j = i+1;j<pois.size();j++) {
				if(diry * (pois[j].first-pois[i].first) == dirx * (pois[j].second-pois[i].second)) {
					unique = false;
					break;
				}
			}
			if(unique) edge_cnt++;
		}
		sum_a += edge_cnt;
		a.emplace_back(edge_cnt);
		i->second.clear();
	}
	edges.clear();
	long long ans = 0;
	cout<<sum_a<<endl;
	for(auto i : a) {
		ans += (sum_a - i) * i;
	}
	cout<<ans<<endl;
}
int main() {
	x = (long long*)malloc(upper*sizeof(long long));
	y = (long long*)malloc(upper*sizeof(long long));
	for(long long i = 0;i<upper;i++) {
		x[i] = gen(start);
		y[i] = gen(start);
	}
	cout<<"gen point success"<<endl;
	for(long long i = 0;i<upper;i++) {
		for(long long j = i+1;j<upper;j++) {
			gen(i, j);
		}
	}
	free(x);
	free(y);
	cout<<"gen edge success"<<endl;
	handle();
	return 0;
}

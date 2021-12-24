#include<bits/stdc++.h>
using namespace std;
int w, h;
vector<int> ll;
vector<long long> l;
void generate(int num2, int num3) {/*{{{*/
	if(num2 + num3 == 1) {
		long long a = 0;
		for(auto i : ll) a |= (1<<i);
		l.push_back(a);
	}
	else {
		auto base = 0;
		if(ll.size() != 0) base = ll[ll.size()-1];
		if(num2 > 0) {
			ll.push_back(base + 2);
			generate(num2-1, num3);
			ll.pop_back();
		}
		if(num3 > 0) {
			ll.push_back(base + 3);
			generate(num2, num3-1);
			ll.pop_back();
		}
	}
}/*}}}*/
vector<vector<int>> mat;
vector<long long> ans;
vector<long long> gen(vector<long long>&buf) {/*{{{*/
	vector<long long> ret;
	ret.resize(buf.size());
	for(int i = 0;i<mat.size();i++) {
		for(auto j : mat[i]) {
			ret[i] += buf[j];
		}
	}
	return ret;
}/*}}}*/

int main() {
    h = 10;
	w = 32;
	for(int i = w%2;i*3 <= w;i+=2) {
		int j = (w - i*3) / 2;
		generate(j, i);
	}
	mat.resize(l.size());
	int cnt = 0;
	for(int i = 0;i<l.size();i++) for(int j = i+1;j<l.size();j++) if((l[i]&l[j]) == 0) {
		mat[i].push_back(j); 
		mat[j].push_back(i); 
	}
	ans.resize(l.size());
	for(int i = 0;i<ans.size();i++) ans[i] = 1;
	for(int i = 1;i<h;i++) ans = gen(ans);
	long long answer = 0;
	for(auto i : ans) answer+=i;
	cout<<answer<<endl;
	return 0;
}

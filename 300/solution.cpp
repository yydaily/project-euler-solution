#include<iostream>
#include<map>
#include<vector>
using namespace std;
const int len = 13;
int mat[len<<1][len<<1];
int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};

bool need_cal[1<<len];
vector<int> need;
map<int, int> v;

void init() {
	memset(mat, -1, sizeof(mat));
	for(int i = 0;i<(1<<len);i++) {
		need_cal[i] = __builtin_popcount(i) > 1;
		need.emplace_back(i);
	}
}
void cal() {
	int x = len, y = len;
	int xx, yy;
	vector<int> inter;
	for(int i = 0;i<len;i++) {
		for(int j = 0;j<4;j++) {
			int index = mat[x+dirx[j]][y+diry[j]];
			if(index>i) inter.emplace_back((1<<i) | (1<<index));
			if(index==i+1) xx = x+dirx[j], yy = y+diry[j];
		}
		x = xx;
		y = yy;
	}
	for(auto i : need) {
		int cnt = 0;
		for(auto j : inter) cnt += (i&j) == j;
		v[i] = max(v[i], cnt);
	}
}
int cnt = 0;
void dfs(int x, int y, int len) {
	if(len==0) {
		cal();
		cnt++;
		if(cnt % 6000 == 0) {
			cout<<cnt/6000<<"%"<<endl;
		}
		return ;
	}
	for(int i = 0;i<4;i++) {
		int xx = x + dirx[i];
		int yy = y + diry[i];
		if(mat[xx][yy] == -1) {
			mat[xx][yy] = mat[x][y] + 1;
			dfs(xx, yy, len-1);
			mat[xx][yy] = -1;
		}
	}
}
int main() {
	init();
	mat[len][len] = 0;
	mat[len][len+1] = 1;
	dfs(len, len+1, len-2);
	long long ans = 0;
	for(auto i : need) {
		ans += v[i];
	}
	cout<<ans<<endl;
	return 0;
}

#include<iostream>
using namespace std;
int num[20][20];
int dirx[4] = {1,1,0,1};
int diry[4] = {1,0,1,-1};
int cal(int x, int y, int dir, int ind) {
	if(x<0 || x>=20 || y<0 || y>=20) return 0;
	if(ind==3) return num[x][y];
	return num[x][y] * cal(x+dirx[dir], y+diry[dir], dir, ind+1);
}
int main() {
	freopen("./in", "r", stdin);
	for(int i = 0;i<20;i++) for(int j = 0;j<20;j++) cin>>num[i][j];
	int ans = 0;
	for(int dir = 0;dir<4;dir++) {
		for(int i = 0;i<20;i++) {
			for(int j = 0;j<20;j++) {
				int value = cal(i, j, dir, 0);
				ans = max(ans, value);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

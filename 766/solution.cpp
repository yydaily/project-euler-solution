#include<iostream>
#include<queue>
#include<map>
using namespace std;
const int r = 5;
const int c = 6;
struct m {
    char mat[r][c];
    __int128 get_val() {
        __int128 ret = 0;
        __int128 base = 1;
        for(int i = 0;i<r;i++) {
            for(int j = 0;j<c;j++) {
				int x = mat[i][j];
                if(x == 0) ;
                else if(x == 1||x==3) ret += base; // 红色
				else if(x == 2 || x == 8) ret += base*2; // 绿色
				else if(x == 4) ret += base*3; // 蓝色
				else if(x == 5 || x == 6) ret+=base*4; // 黄色
				else if(x == 7) ret += base*5; // 浅蓝色
                else ret += base*6;
                base *= 7;
            }
        }
        return ret;
    }
    void show() {
        for(int i = 0;i<r;i++) {
            for(int j = 0;j<c;j++) {
				int x = mat[i][j];
                if(x == 0) cout<<"\033[47m  \033[0m";
                else if(x == 1 || x == 3) cout<<"\033[41m  \033[0m";
				else if(x == 2 || x == 8) cout<<"\033[42m  \033[0m";
				else if(x == 4) cout<<"\033[44m  \033[0m";
				else if(x == 5 || x == 6) cout<<"\033[43m  \033[0m";
				else if(x == 7) cout<<"\033[46m  \033[0m";
				else cout<<"\033[45m  \033[0m";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};
map<__int128, bool> x;
struct q {
    queue<m> que;
    void push(m buffer) {
		if(que.size()>100000) {
			cout<<"que too large"<<endl;
			exit(0);
		}
        if(x[buffer.get_val()]) return ;
        x[buffer.get_val()] = true;
        que.push(buffer);
    }
    m pop() {
        auto ret = que.front();
        que.pop();
        return ret;
    }
    bool empty() {
        return que.empty();
    }
} que;
int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};
bool check(m mat, int ind, int dir) {
    for(int i = 0;i<r;i++) {
        for(int j = 0;j<c;j++) {
            if(mat.mat[i][j] == ind) {
                int x = i+dirx[dir];
                int y = j+diry[dir];
                if(x<0||x>=r) return false;
                if(y<0||y>=c) return false;
                if (mat.mat[x][y] != 0 && mat.mat[x][y] != ind) {
                    return false;
                }
            }
        }
    }
    return true;
}
m move(m a, int ind, int dir) {
    pair<int, int> remove[10];
    int index = 0;
    pair<int, int> add[10];
    for(int i = 0;i<r;i++) {
        for(int j = 0;j<c;j++) {
            if(a.mat[i][j] == ind) {
                remove[index].first = i, remove[index].second = j;
                add[index].first = i+dirx[dir], add[index].second = j+diry[dir];
                index++;
            }
        }
    }
    for(int i = 0;i<index;i++) a.mat[remove[i].first][remove[i].second] = 0;
    for(int i = 0;i<index;i++) a.mat[add[i].first][add[i].second] = ind;
    return a;
}
void handle(m a) {
    for(int i = 1;i<=14;i++) for(int dir = 0;dir<4;dir++)
            if(check(a, i, dir))
                que.push(move(a, i, dir));
}
int main() {
    m origin;
	origin.mat[0][0] = 0; origin.mat[0][1] = 1; origin.mat[0][2] = 1; origin.mat[0][3] = 2; origin.mat[0][4] = 3; origin.mat[0][5] = 3;
	origin.mat[1][0] = 0; origin.mat[1][1] = 1; origin.mat[1][2] = 2; origin.mat[1][3] = 2; origin.mat[1][4] = 3; origin.mat[1][5] = 6;
	origin.mat[2][0] = 9; origin.mat[2][1] = 10; origin.mat[2][2] = 4; origin.mat[2][3] = 4; origin.mat[2][4] = 5; origin.mat[2][5] = 6;
	origin.mat[3][0] = 11; origin.mat[3][1] = 12; origin.mat[3][2] = 4; origin.mat[3][3] = 4; origin.mat[3][4] = 5; origin.mat[3][5] = 8;
	origin.mat[4][0] = 13; origin.mat[4][1] = 14; origin.mat[4][2] = 7; origin.mat[4][3] = 7; origin.mat[4][4] = 8; origin.mat[4][5] = 8;
	origin.show();
    que.push(origin);
    while(!que.empty()) {
        handle(que.pop());
    }
    cout<<x.size()<<endl;
    return 0;
}

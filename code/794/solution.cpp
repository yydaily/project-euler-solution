#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <vector>
using namespace std;
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
struct p { /*{{{*/
    int x, y;
    p() {}
    p(int _x, int _y) { x = _x, y = _y; }
    bool operator<(const p &a) const { return x * a.y < y * a.x; }
}; /*}}}*/

int siz = 0;
p can[200];
int layer = 15;
int ans[20];
int Meet[100][100][20];
bool meet(int index1, int index2, int lay) { /*{{{*/
    if (Meet[index1][index2][lay])
        return Meet[index1][index2][lay] == 1;
    for (int i = lay; i <= layer; i++) {
        if (can[index1].x * i / can[index1].y == can[index2].x * i / can[index2].y) {
            Meet[index1][index2][lay] = 1;
            return true;
        }
    }
    Meet[index1][index2][lay] = false;
    return false;
} /*}}}*/
long double rans = 100;
map<vector<int>, bool> m;
void dfs(int index, vector<int> nouse) {
    sort(nouse.begin(), nouse.end());
    if (m[nouse])
        return;
    m[nouse] = true;
    if (index == layer + 1) {
        long double now = 0;
        for (int i = 1; i <= layer; i++) {
            now += (long double)1.0 * can[ans[i]].x / can[ans[i]].y;
        }
        rans = min(rans, now);
        return;
    }
    for (int i = 0; i < siz; i++) {
        bool ok = true;
        for (int j = 1; j < index; j++) {
            if (meet(i, ans[j], index)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans[index] = i;
            nouse.push_back(i);
            dfs(index + 1, nouse);
            nouse.pop_back();
        }
    }
}
int main() {
    // not the first 100, so sad T_T
    for (int i = 1; i <= layer; i++) {
        for (int j = 0; j < i; j++) {
            if (gcd(i, j) != 1)
                continue;
            can[siz++] = p(j, i);
        }
    }
    sort(can, can + siz);
    vector<int> nouse;
    dfs(1, nouse);
    printf("%d %.12Lf\n", layer, rans);
    return 0;
}

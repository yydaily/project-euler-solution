#include "../template/bigint.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
#include "../template/fibonacci.cpp"
#include "../template/pell.cpp"
#include "../template/prime.cpp"
#include "../template/prime_cnt.cpp"
#include <iostream>/*{{{*/
#include <map>
#include <math.h>
#include <set>
#include <vector>
const long long e2 = 100;
const long long e3 = e2 * 10;
const long long e4 = e3 * 10;
const long long e5 = e4 * 10;
const long long e6 = e4 * e2;
const long long e7 = e6 * 10;
const long long e8 = e7 * 10;
const long long e9 = e8 * 10;
long long _mod     = e9 + 7;
using namespace std; /*}}}*/
int upper = 75000000;
map<string, bool> vis;
long long ans = 0;
void dfs(int a, int b, int c) {
    if (a > b)
        swap(a, b);
    if (a > c)
        swap(a, c);
    if (b > c)
        swap(b, c);
    if (a + b + c > upper)
        return;
    auto s = to_string(a) + ' ' + to_string(b) + ' ' + to_string(c);
    if (vis[s])
        return;
    vis[s] = true;
    ans++;
    dfs(2 * c + b - 2 * a, 2 * c + 2 * b - a, 3 * c + 2 * b - 2 * a);
    dfs(2 * c + b + 2 * a, 2 * c + 2 * b + a, 3 * c + 2 * b + 2 * a);
    dfs(2 * c - 2 * b + a, 2 * c - b + 2 * a, 3 * c - 2 * b + 2 * a);
}
int main() {
    dfs(2, 2, 3);
    cout << ans << endl;
    return 0;
}

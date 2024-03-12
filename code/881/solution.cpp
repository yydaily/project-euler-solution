#include <iostream>/*{{{*/
#include <map>
#include <vector>
using namespace std; /*}}}*/
unsigned long long ans    = 6;
const long long prime[30] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113};
map<int, int> gen(int a) {
    map<int, int> ret;
    for (int i = 0; i <= a; i++)
        ret[i] = 1;
    return ret;
}
map<int, int> merge(const map<int, int> &a, const map<int, int> &b) {
    map<int, int> ret;
    for (auto i : a) {
        for (auto j : b) {
            ret[i.first + j.first] += i.second * j.second;
        }
    }
    return ret;
}
long long cal(const vector<int> &v) {
    map<int, int> x;
    x[0] = 1;
    for (auto i : v) {
        x = merge(x, gen(i));
    }
    int cnt = 0;
    for (auto i : x) {
        cnt = max(cnt, i.second);
    }
    return cnt;
}
void dfs(int prime_index, int max_cnt = 62, unsigned long long now = 1, vector<int> v = {}) {
    if (prime_index >= 15)
        return;
    if (cal(v) >= 10000) {
        ans = min(ans, now);
        return;
    }
    int p = prime[prime_index];
    for (int i = 1; i <= max_cnt; i++) {
        if (now > ans / p)
            return;
        now *= p;
        v.push_back(i);
        dfs(prime_index + 1, i, now, v);
        v.pop_back();
    }
}
int main() {
    for (int i = 0; i < 15; i++) {
        ans *= prime[i];
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}

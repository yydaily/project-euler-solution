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
int ans[e6 + 10];
vector<int> num;

void init() {
    int a = 1;
    while (a < e6) {
        int b = a;
        while (b < e6) {
            if (b == 1) {
                b = 3;
                continue;
            }
            num.push_back(b);
            b *= 3;
        }
        a *= 2;
    }
    sort(num.begin(), num.end());
}

void dfs(int now, int index, vector<int> &cache) {
    ans[now]++;
    for (int i = index; i < num.size(); i++) {
        if (now + num[i] > e6)
            break;
        bool can_add = true;
        for (auto j : cache) {
            if (num[i] % j == 0) {
                can_add = false;
                break;
            }
        }
        if (can_add) {
            cache.push_back(num[i]);
            dfs(now + num[i], i + 1, cache);
            cache.pop_back();
        }
    }
}

int main() {
    Prime::init(e6);
    init();
    vector<int> cache;
    dfs(0, 0, cache);
    long long rans = 0;
    for (auto i : Prime::prime) {
        if (ans[i] == 1) {
            rans += i;
        }
    }
    cout << rans << endl;
    return 0;
}

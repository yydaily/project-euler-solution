#include "../template/prime.cpp"
#include <iostream>  /*{{{*/
using namespace std; /*}}}*/
map<vector<int>, long long> v;
vector<int> format(vector<int> &x) {
    vector<int> ret;
    for (auto i : x)
        if (i)
            ret.push_back(i);
    sort(ret.begin(), ret.end(), greater<int>());
    return ret;
}
long long cal(vector<int> x) {
    if (x.size() == 0)
        return 1;
    if (x.size() == 1)
        return 1LL << (x[0] - 1);
    if (v[x])
        return v[x];

    long long ret = 0;

    vector<vector<int>> now;
    now.push_back(vector<int>());
    for (auto i : x) {
        vector<vector<int>> nxt;
        for (int j = 0; j <= i; j++) {
            for (auto k : now) {
                vector<int> vv = k;
                vv.push_back(j);
                nxt.push_back(vv);
            }
        }
        now = nxt;
    }

    for (auto i : now) {
        if (i == x)
            continue;
        ret += cal(format(i));
    }

    v[x] = ret;
    return ret;
}

bool check(long long v) {
    long long cache = v;
    vector<int> now;
    while (v != 1) {
        long long p = Prime::MinPrime(v);
        int cnt     = 0;
        while (v % p == 0) {
            cnt++;
            v /= p;
        }
        now.push_back(cnt);
    }
    sort(now.begin(), now.end(), greater<int>());
    return cal(now) == cache;
}

long long G(long long n) {
    // return \sum_{i=1}^n [g(n)=n]*n
    long long ans = 0;
    freopen("./out", "r", stdin); // OEIS A034776
    long long a;
    while (cin >> a) {
        if (a > n)
            break;
        if (check(a))
            ans += a;
    }
    return ans;
}
int main() {
    Prime::init(1e5);
    cout << G(1e16) << endl;
    return 0;
}

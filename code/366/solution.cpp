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
struct p {
    long long l, r;
    p() {}
    p(long long _l, long long _r) : l(_l), r(_r) {}
    bool operator<(const p &a) const {
        if (l != a.l)
            return l < a.l;
        return r < a.r;
    }
};
map<p, long long> cache;

long long fib[86];

long long cal(long long l, long long r) {
    if (l > r)
        return 0;
    p now(l, r);
    if (cache[now])
        return cache[now];

    long long l_add = (3 * l - 3) / 2;
    while (true) {
        if (l_add % 3 != 0 && l_add - l + 1 >= l_add / 3)
            break;
        if (l_add % 3 == 0 && l_add - l + 1 > l_add / 3)
            break;
        l_add--;
    }
    l_add = max(l_add, l);
    if (l_add >= r) {
        // l 1
        // r r+1-l
        __int128 buf = r + 1 - l;
        buf          = (buf * (buf + 1) / 2) % e8;
        cache[now]   = buf;
        return buf;
    }

    int index = 1;
    while (fib[index] <= l_add - l + 1)
        index++;
    index--;

    // 1 ~ fib[index], fib[index], fib[index]
    __int128 buf  = fib[index];
    long long ret = (buf * (buf + 1) / 2) % e8;
    ret           = (ret + (l_add - l + 1 - buf) * buf) % e8;

    ret = (ret + cal(fib[index] + 1, r - l + 1)) % e8;

    cache[now] = ret;
    cout << l << ' ' << r << ' ' << ret << endl;
    return ret;
}

// [1, upper]
long long upper = 100;

void init_fib() {
    fib[0] = 2, fib[1] = 3;
    for (int i = 2; i < 86; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

void solve(long long u) {
    upper         = u;
    long long ans = 0;
    int index     = 1;
    while (fib[index++] <= upper) {
        ans = (ans + cal(fib[index - 1] + 1, min(fib[index] - 1, upper))) % e8;
    }
    cout << ans << endl;
}

int main() {
    init_fib();
    solve(e9 * e9);
    return 0;
}

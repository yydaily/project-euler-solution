#include <iostream>
#include <vector>
using namespace std;
const long long sizz = 30 * 30 * 30 * 30 * 30 * 3;
struct poi { /*{{{*/
    long long x, y;
    bool operator<(const poi &b) const {
        if (x != b.x)
            return x < b.x;
        return y < b.y;
    }
    bool operator==(const poi &b) const { return x == b.x && y == b.y; }
    poi(){};
    poi(long long _x, long long _y) {
        x = _x;
        y = _y;
    }
}; /*}}}*/
poi l[sizz];
long long a[sizz];
long long d[sizz];
void gen(long long n) { /*{{{*/
    long long cnt = 0;
    a[0]          = 0;

    long long x = 1, y = 1;
    for (long long i = 0; i <= 2 * n; i++) {
        l[cnt++] = poi(x % n, y % n);
        x        = (x << 1) % n;
        y        = y * 3 % n;
    }
    sort(l, l + cnt);
    cnt = (unique(l, l + cnt) - l);
    for (int i = 0; i < cnt; i++) {
        a[++a[0]] = l[i].y;
    }
    memset(d, 0, a[0] + 10);
} /*}}}*/
long long cal() {         /*{{{*/
    d[1]          = a[1]; //初始化
    long long len = 1;
    for (long long i = 2; i <= a[0]; i++) {
        if (a[i] >= d[len])
            d[++len] = a[i]; //如果可以接在len后面就接上，如果是最长上升子序列，这里变成>
        else                 //否则就找一个最该替换的替换掉
        {
            long long j = upper_bound(d + 1, d + len + 1, a[i]) - d; //找到第一个大于它的d的下标，如果是最长上升子序列，这里变成lower_bound
            d[j]        = a[i];
        }
    }
    return len;
} /*}}}*/
int main() {
    long long ans = 0;
    for (long long a = 1; a <= 30; a++) {
        long long b = a * a * a * a * a;
        gen(b);
        auto buf = cal();
        cout << a << ' ' << buf << endl;
        ans += buf;
    }
    cout << ans << endl;
    return 0;
}

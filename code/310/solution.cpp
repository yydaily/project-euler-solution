#include <iostream>/*{{{*/
#include <map>
const long long e2 = 100;
const long long e3 = e2 * 10;
const long long e4 = e3 * 10;
const long long e5 = e4 * 10;
using namespace std; /*}}}*/
long long sg[2 * e5];
long long cnt[2 * e5]; // 75
void init_sg(long long upper) {
    memset(sg, 0, sizeof(sg));
    memset(cnt, 0, sizeof(cnt));
    cnt[0] = 1;
    for (long long i = 1; i <= upper; i++) {
        map<long long, bool> m;
        for (long long j = 1; j * j <= i; j++) {
            m[sg[i - j * j]] = true;
        }
        for (long long j = 0;; j++) {
            if (m[j])
                continue;
            sg[i] = j;
            cnt[j]++;
            break;
        }
    }
}

long long S(long long upper) {
    init_sg(upper);
    // 答案包括四部分
    // 1. a < b < c
    // 2. a < b = c   ->   sg[a]
    // 3. a = b < c   ->   sg[c]
    // 4. a = b = c   ->   sg[a]
    long long ans1 = 0, ans2 = 0, ans3 = 0, ans4 = cnt[0];
    for (long long i = 0; i <= upper; i++) {
        if (sg[i] == 0) {
            // case2: i=a
            ans2 += upper - i;
            // case3: i=c
            ans3 += i;
        }
    }
    // 关键是如何统计 ans1
    // 不妨可以简化问题，我们去掉 a<=b<=c 的限制统计出全量的方案数 buf
    // 那么buf中，对于ans1统计了6次，ans2统计了3次，ans3统计了3次，ans4统计了一次
    // 所以 ans1 = (buf - ans2*3 - ans3*3 - ans4) / 6
    long long buf = 0;
    for (long long i = 0; cnt[i] > 0; i++) {
        for (long long j = 0; cnt[j] > 0; j++) {
            for (long long k = 0; cnt[k] > 0; k++) {
                if ((i ^ j ^ k) == 0)
                    buf += cnt[i] * cnt[j] * cnt[k];
            }
        }
    }
    ans1 = (buf - ans2 * 3 - ans3 * 3 - ans4) / 6;
    return ans1 + ans2 + ans3 + ans4;
}
int main() {
    cout << S(29) << endl;
    cout << S(100000) << endl;
    return 0;
}

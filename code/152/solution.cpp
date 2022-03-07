#include <iostream>
#include <map>
using namespace std;
long long target = 309086668800LL;
long long val[]  = {154543334400, 68685926400, 38635833600, 24726933504, 17171481600, 12615782400, 9658958400, 7631769600, 6181733376, 4292870400, 3657830400, 3153945600, 2747437056,
                   2414739600,   1907942400,  1545433344,  1401753600,  1073217600,  847974400,   788486400,  686859264,  603684900,  504631296,  476985600,  406425600,  386358336,
                   350438400,    305270784,   268304400,   228614400,   211993600,   197121600,   171714816,  155750400,  150921225,  146313216,  126157824,  119246400,  96589584};
map<long long, int> m;
int left_maxm = 1 << 20, right_maxm = 1 << 19;
int main() {
    int ans = 0;
    for (int i = 0; i < left_maxm; i++) {
        long long now = 0;
        for (int j = 0; j < 20; j++) {
            if (i & (1 << j)) {
                now += val[j];
                if (now >= target)
                    break;
            }
        }
        if (now == target)
            ans++;
        else if (now < target)
            m[now]++;
    }
    // 22~38
    for (int i = 0; i < right_maxm; i++) {
        long long need = target;
        for (int j = 0; j < 19; j++)
            if (i & (1 << j))
                need -= val[j + 20];
        ans += m[need];
    }
    cout << ans << endl;
    return 0;
}

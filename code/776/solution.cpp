#include <iomanip>
#include <iostream>
using namespace std;
double cnt[20][200];
double val[20][200];
void init() { /*{{{*/
    cnt[0][0] = 1;
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 200; j++) {
            for (int add = 0; add < 10 && j + add < 200; add++) {
                cnt[i + 1][j + add] += cnt[i][j];
                val[i + 1][j + add] += val[i][j] * 10 + cnt[i][j] * add;
            }
        }
    }
} /*}}}*/
const double upper = 1234567890123456789LL;
double gao(long long a) { /*{{{*/
    double ret = 0;
    while (a) {
        ret += a % 10;
        a /= 10;
    }
    return ret;
} /*}}}*/
double cal(long long prefix = 0) {
    if (prefix > upper)
        return 0;
    double prefix_sum = gao(prefix);
    double max_diff   = upper - prefix;
    long long diff = 1, index = 0;
    while (diff * 10.0 <= max_diff)
        diff *= 10, index++;

    double ret = 0;
    for (int i = 0; i < 200; i++) {
        if (cnt[index][i] && i + prefix_sum) {
            ret += 1.0 * (val[index][i] + prefix * cnt[index][i]) / (i + prefix_sum);
        }
    }

    return ret + cal(prefix + diff);
}
int main() {
    init();
    cout << scientific << setprecision(12) << cal() << endl;
    return 0;
}

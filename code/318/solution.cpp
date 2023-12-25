#include <iostream>/*{{{*/
#include <math.h>
using namespace std; /*}}}*/
int main() {
    long long ans = 0;
    for (int p = 1; p < 2011; p++) {
        for (int q = p + 1; p + q <= 2011; q++) {
            double buf = p + q - 2 * sqrt(p * q);
            if (buf <= 0 || buf >= 1)
                continue;
            ans += ceil(-2011 / log10(buf));
        }
    }
    cout << ans << endl;
    return 0;
}

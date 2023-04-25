#include "../template/prime.cpp"
#include <iostream>/*{{{*/
#include <math.h>
using namespace std; /*}}}*/
double f(int k = 1) {
    double ret   = 0;
    double alpha = 1;
    for (auto p : Prime::prime) {
        double now_alpha = alpha / p;
        alpha -= now_alpha;
        for (int i = 2; now_alpha >= 1e-200; i++) {
            now_alpha /= p;
            ret += now_alpha / pow(p, k);
        }
    }
    return ret;
}
int main() {
    Prime::init(1e5);
    double ans = 0;
    for (int i = 1;; i++) {
        double now = f(i);
        if (now <= 1e-200)
            break;
        cout << i << ' ' << now << endl;
        ans += now;
    }
    printf("%.12f\n", ans);
    return 0;
}

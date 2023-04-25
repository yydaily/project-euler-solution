#include <iostream>/*{{{*/
#include <math.h>
using namespace std; /*}}}*/
typedef pair<double, double> point;
double f(double x, double y) { return x * x + y * y; }
point cal1(point a, point b, point c) {
    // 返回三个点对应的三角形的外接圆圆心
    double d1 = f(b.first, b.second) - f(a.first, a.second), d2 = f(c.first, c.second) - f(b.first, b.second);
    double fm    = 2 * ((c.second - b.second) * (b.first - a.first) - (b.second - a.second) * (c.first - b.first));
    double ans_x = ((c.second - b.second) * d1 - (b.second - a.second) * d2) / fm;
    double ans_y = ((b.first - a.first) * d2 - (c.first - b.first) * d1) / fm;
    return make_pair(ans_x, ans_y);
}
point cal2(double ra, double rb, double rc) {
    // 返回三个相切圆的公切圆圆心，经典问题，参考: soddy circles
    double r = (ra * rb * rc) / (ra * rb + rb * rc + ra * rc + 2 * sqrt(ra * rb * rc * (ra + rb + rc)));

    double cos_alpha = (f(ra + r, ra + rb) - f(rb + r, 0)) / 2 / (ra + r) / (ra + rb);
    return make_pair(cos_alpha * (ra + r), (ra + r) * sin(acos(cos_alpha)));
}

double cal(double ra, double rb, double rc) {
    double cos_alpha = (f(ra + rb, ra + rc) - f(rb + rc, 0)) / 2 / (ra + rb) / (ra + rc);

    double cos_beta = (f(ra + rb, rb + rc) - f(ra + rc, 0)) / 2 / (ra + rb) / (rb + rc);

    point O1 = cal1(make_pair(ra, 0), make_pair(cos_alpha * ra, sin(acos(cos_alpha)) * ra), make_pair(ra + rb - cos_beta * rb, rb * sin(acos(cos_beta))));
    point O2 = cal2(ra, rb, rc);

    return sqrt(f(O1.first - O2.first, O1.second - O2.second));
}

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int gcd(int a, int b, int c) { return gcd(a, gcd(b, c)); }
int main() {
    double cnt = 0;
    double ans = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = i + 1; j <= 100; j++) {
            for (int k = j + 1; k <= 100; k++) {
                if (gcd(i, j, k) != 1)
                    continue;
                ans += cal(i, j, k);
                cnt++;
            }
        }
    }
    printf("%.8f\n", ans / cnt);
    return 0;
}

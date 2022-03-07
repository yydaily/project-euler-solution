#include <iostream>
#include <math.h>
using namespace std;
double r = 100000;
double cal(double i) { return r - sqrt(r * r - (r - i) * (r - i)); }
double check(double n) {
    double sum = 0, buf = 0;
    for (double i = 0; i < r; i = i + 1) {
        double upper1 = cal(i);
        double upper2 = i / n;
        sum += upper1;
        buf += min(upper1, upper2);
    }
    return buf / sum * 1000;
}
int main() {
    double l = 15, r = 1e10;
    while (l + 0.1 < r) {
        double mid = (l + r) / 2;
        if (check(mid) > 1) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << ceil(l) << endl;
    return 0;
}

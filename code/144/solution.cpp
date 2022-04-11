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

struct line {
    double x1, y1; // from (x1, y1) to (x2, y2)
    double x2, y2;
    double dir;
};

line gen(line before) {
    // 4x^2 + y^2 = 100
    line ret;
    ret.x1  = before.x2;
    ret.y1  = before.y2;
    ret.dir = tan(2 * atan(before.y2 / before.x2 / 4) - atan((before.y2 - before.y1) / (before.x2 - before.x1)));

    double a     = 4 + ret.dir * ret.dir;
    double b     = -2 * ret.x1 * ret.dir * ret.dir + 2 * ret.y1 * ret.dir;
    double c     = ret.y1 * ret.y1 + ret.x1 * ret.x1 * ret.dir * ret.dir - 2 * ret.x1 * ret.y1 * ret.dir - 100;
    double delta = sqrt(b * b - 4 * a * c);

    double maybe  = (-b + delta) / a / 2;
    double maybe2 = (-b - delta) / a / 2;

    if (fabs(maybe - ret.x1) < fabs(maybe2 - ret.x1)) {
        ret.x2 = maybe2;
    } else {
        ret.x2 = maybe;
    }

    ret.y2 = ret.y1 + (ret.x2 - ret.x1) * ret.dir;
    return ret;
}
int main() {
    line x;
    x.x1 = 0, x.y1 = 10.1;
    x.x2 = 1.4, x.y2 = -9.6;
    for (int i = 1;; i++) {
        x = gen(x);
        if (fabs(x.x2) <= 0.01 && x.y2 > 0) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}

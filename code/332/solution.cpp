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
struct point {
    int x, y, z;
    point(){};
    point(int _x, int _y, int _z) {
        x = _x;
        y = _y;
        z = _z;
    };
};
inline int sqr(int a) { return a * a; }
double dis(point a, point b) { return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y) + sqr(a.z - b.z)); }

double get_angle(point a, point b, point c) { // angle abc
    long long ax = b.y * a.z - a.y * b.z, ay = b.z * a.x - b.x * a.z, az = b.x * a.y - a.x * b.y;
    long long bx = b.y * c.z - c.y * b.z, by = b.z * c.x - b.x * c.z, bz = b.x * c.y - c.x * b.y;
    long long dot = ax * bx + ay * by + az * bz;
    long long l1 = ax * ax + ay * ay + az * az, l2 = bx * bx + by * by + bz * bz;
    if (dot * dot == l1 * l2)
        return 1e100;
    return acos(dot / sqrt(l1) / sqrt(l2));
}
double cal(point x, point y, point z, int r) {
    double A = get_angle(x, y, z);
    double B = get_angle(y, z, x);
    double C = get_angle(z, x, y);

    return r * r * (A + B + C - acos(-1));
}
double A(int r) {
    vector<point> v;
    for (int i = -r; i <= r; i++) {
        for (int j = -r; j <= r; j++) {
            for (int k = -r; k <= r; k++) {
                if (i * i + j * j + k * k == r * r) {
                    v.push_back(point(i, j, k));
                }
            }
        }
    }

    double ans = 1e10;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            for (int k = j + 1; k < v.size(); k++) {
                ans = min(ans, cal(v[i], v[j], v[k], r));
            }
        }
    }
    return ans;
}
int main() {
    cout << A(14) << endl;
    double ans = 0;
    for (int i = 1; i <= 50; i++) {
        auto buf = A(i);
        cout << i << ' ' << buf << endl;
        ans += buf;
    }
    printf("%.6f\n", ans);
    return 0;
}

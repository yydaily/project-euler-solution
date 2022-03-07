#include "../template/bigint.cpp"
#include <iostream>/*{{{*/
#include <map>
#include <math.h>
#include <set>
#include <vector>
const int e2  = 100;
const int e3  = e2 * 10;
const int e4  = e3 * 10;
const int e5  = e4 * 10;
const int e6  = e4 * e2;
const int e7  = e6 * 10;
const int e8  = e7 * 10;
const int mod = 1e9 + 7;
using namespace std; /*}}}*/

/*add{{{*/
template <typename T> T base_add(T a, T b) {
    a %= mod;
    b %= mod;
    return (a + b) % mod;
}
template <typename T> T add(const T &t) { return t; }
template <typename T, typename... Args> T add(const T &t, const Args &...args) { return base_add(t, add(args...)); }
/*}}}*/

/*{{{mul*/
template <typename T> T base_mul(T a, T b) {
    a %= mod;
    b %= mod;
    T ret(0);
    while (b) {
        if (b & 1)
            ret = (ret + a) % mod;
        b >>= 1;
        a = (a + a) % mod;
    }
    return ret;
}
template <typename T> T mul(const T &t) { return t; }
template <typename T, typename... Args> T mul(const T &t, const Args &...args) { return base_mul(t, mul(args...)); }
/*}}}*/

/*{{{qpow*/
template <typename T> T qpow(T a, T b) {
    T ret(1);
    while (b) {
        if (b & 1)
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}
/*}}}*/

double area(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a, b, c, p, s;
    a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    c = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    p = (a + b + c) / 2;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
    return s;
}

bool check(double x1, double y1, double x2, double y2, double x3, double y3) {
    double origin = area(x1, y1, x2, y2, x3, y3);
    double s1     = area(0, 0, x1, y1, x2, y2);
    double s2     = area(0, 0, x2, y2, x3, y3);
    double s3     = area(0, 0, x1, y1, x3, y3);
    return fabs(origin - s1 - s2 - s3) <= 1e-6;
}

void split(const std::string &s, std::vector<std::string> &sv, const char *delim = " ") {
    sv.clear();                                // 1.
    char *buffer     = new char[s.size() + 1]; // 2.
    buffer[s.size()] = '\0';
    std::copy(s.begin(), s.end(), buffer); // 3.
    char *p = std::strtok(buffer, delim);  // 4.
    do {
        sv.push_back(p);                      // 5.
    } while ((p = std::strtok(NULL, delim))); // 6.
    delete[] buffer;
    return;
}

int main() {
    freopen("./in", "r", stdin);
    string a;
    int ans = 0;
    while (cin >> a) {
        vector<string> x;
        split(a, x, ",");
        assert(x.size() == 6);
        double num[10];
        for (int i = 0; i < 6; i++)
            num[i] = stod(x[i]);
        if (check(num[0], num[1], num[2], num[3], num[4], num[5])) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

#include "../template/bigint.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
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
int num[6][2] = {{-4, 5}, {-4, -5}, {0, -1}, {0, 1}, {-3, 2}, {-3, -2}};
void gen(long long &a, long long &b) {
    auto aa = -9 * a - 4 * b - 14;
    b       = -20 * a - 9 * b - 28;
    a       = aa;
}
int main() {
    // G(x) = (x+3x^2)/(1-x-x^2)
    // 5n^2 + 14n + 1 = t^2
    // (-4,5), (-4,-5), (0,-1), (0,1), (-3,2), (-3,-2)
    // n = -9n-4t-14
    // t = -20n-9t-28
    vector<long long> v;
    for (int i = 0; i < 6; i++) {
        long long n = num[i][0], t = num[i][1];
        while (abs(n) < 3197021343560) {
            gen(n, t);
            if (n > 0)
                v.push_back(n);
        }
        ////	for(int j = 0;j<12;j++) {
        ////		gen(n, t);
        ////		if(n>0) v.push_back(n);
        ////	}
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for (int i = 0; i < 30; i++)
        ans += v[i];
    cout << ans << endl;
    return 0;
}

/*
s = xG_1 + x^2G_2
*/

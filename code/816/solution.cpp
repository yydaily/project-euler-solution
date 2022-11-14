#include "../template/bigint.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
#include "../template/fibonacci.cpp"
#include "../template/mini_dis_points.cpp"
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
long long now    = 290797;
const int length = 2e6;
void gen_point(int &x, int &y) {
    x   = now;
    now = now * now % 50515093;
    y   = now;
    now = now * now % 50515093;
}
int main() {
    MiniDisPoints::init(length);
    for (int i = 0; i < length; i++) {
        int x, y;
        gen_point(x, y);
        MiniDisPoints::add_point(x, y);
    }
    MiniDisPoints::add_over();
    MiniDisPoints::rec(0, length - 1);
    printf("%.9f\n", MiniDisPoints::mini_dis());
    return 0;
}

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
string query = "UDDDUdddDDUDDddDdDddDDUDDdUUDd";
bool meet(long long a, int index) {
    for (int i = 0; i <= index; i++) {
        if (query[i] == 'D') {
            if (a % 3 != 0)
                return false;
            a /= 3;
        } else if (query[i] == 'd') {
            if (a % 3 != 2)
                return false;
            a = (a * 2 - 1) / 3;
        } else {
            if (a % 3 != 1)
                return false;
            a = (a * 4 + 2) / 3;
        }
    }
    return true;
}
int main() {
    long long base = 1;
    long long x1 = 0, x2 = 0;
    for (int i = 0; i < query.length(); i++) {
        while (!meet(x1, i))
            x1 += base;
        x2 = x1 + base;
        while (!meet(x2, i))
            x2 += base;

        base = x2 - x1;
    }
    while (x2 <= 1e15)
        x2 += base;
    cout << x2 << endl;
    return 0;
}

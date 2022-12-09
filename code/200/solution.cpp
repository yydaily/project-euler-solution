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
const long long e2    = 100;
const long long e3    = e2 * 10;
const long long e4    = e3 * 10;
const long long e5    = e4 * 10;
const long long e6    = e4 * e2;
const long long e7    = e6 * 10;
const long long e8    = e7 * 10;
const long long e9    = e8 * 10;
const long long upper = e9 * e3;
long long _mod        = e9 + 7;
using namespace std; /*}}}*/
bool check(long long a) {
    vector<int> num;
    long long cc = a;
    while (cc) {
        num.push_back(cc % 10);
        cc /= 10;
    }
    bool exist_200 = false;
    for (int i = 2; i < num.size(); i++) {
        if (num[i] == 2 && num[i - 1] == 0 && num[i - 2] == 0) {
            exist_200 = true;
        }
    }
    if (!exist_200)
        return false;

    long long base = 1;
    for (int i = 0; i < num.size(); i++) {
        for (int j = (i == num.size() - 1 ? 1 : 0); j < 10; j++) {
            if (Prime::is_prime(a - num[i] * base + j * base)) {
                return false;
            }
        }
        base = base * 10;
    }

    return true;
}
vector<long long> a;
void gen() {
    for (int i = 0; i < Prime::prime.size(); i++) {
        long long p1      = Prime::prime[i];
        long long p2      = p1 * p1;
        long long upper_j = upper / p2;
        for (int j = i + 1; j < Prime::prime.size(); j++) {
            long long q1 = Prime::prime[j];
            long long q2 = q1 * q1;
            if (q2 > upper_j)
                break;

            q2 *= p2;

            bool exit = true;
            if (upper / q2 >= p1) {
                a.push_back(q2 * p1);
                exit = false;
            }
            if (upper / q2 >= q1) {
                a.push_back(q2 * q1);
                exit = false;
            }
            if (exit)
                break;
        }
    }
    sort(a.begin(), a.end());
}
int main() {
    Prime::init(e7);
    gen();
    int cnt = 0;
    for (auto i : a) {
        if (check(i))
            cnt++;
        if (cnt == 200) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}

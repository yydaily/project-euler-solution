#include "../template/bigint.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
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
long long mod      = 1e9 + 7;
using namespace std; /*}}}*/

int to_int(string &roman) {
    int result    = 0;
    int last      = 0;
    bool subtract = false;
    for (auto i = roman.rbegin(); i != roman.rend(); i++) {
        int current = 0;
        switch (*i) {
        case 'M':
            current = 1000;
            break;
        case 'D':
            current = 500;
            break;
        case 'C':
            current = 100;
            break;
        case 'L':
            current = 50;
            break;
        case 'X':
            current = 10;
            break;
        case 'V':
            current = 5;
            break;
        case 'I':
            current = 1;
            break;
        }
        if (current < last) {
            subtract = true;
            last     = current;
        } else if (current > last) {
            subtract = false;
            last     = current;
        }
        if (subtract)
            result -= current;
        else
            result += current;
    }
    return result;
}

int to_str(int number) {
    const int NumRules   = 13;
    int rules[NumRules]  = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    int action[NumRules] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1};
    int ret              = 0;
    for (int i = 0; i < NumRules; i++)
        while (number >= rules[i]) {
            number -= rules[i];
            ret += action[i];
        }
    return ret;
}

int main() {
    int saved = 0;
    string roman;
    while (cin >> roman) {
        auto number    = to_int(roman);
        auto optimized = to_str(number);
        saved += roman.length() - optimized;
    }
    cout << saved << endl;
    return 0;
}

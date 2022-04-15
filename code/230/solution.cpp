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
string a = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
string b = "8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196";
long long len[1000];
char D(long long index) {
    len[0]  = a.length();
    len[1]  = b.length();
    int ind = 1;
    while (len[ind] < index) {
        len[ind + 1] = len[ind] + len[ind - 1];
        ind++;
    }
    while (ind > 1) {
        if (len[ind - 2] >= index)
            ind -= 2;
        else {
            index -= len[ind - 2];
            ind--;
        }
    }
    return ind == 1 ? b[index] : a[index];
}
int main() {
    long long base = 1;
    string ans     = "";
    for (long long i = 0; i <= 17; i++) {
        ans += D((127 + 19 * i) * base - 1);
        base *= 7;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}

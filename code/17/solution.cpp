#include "../template/bigint.cpp"
#include <iostream>/*{{{*/
#include <map>
#include <math.h>
#include <set>
#include <vector>
const long long e2  = 100;
const long long e3  = e2 * 10;
const long long e4  = e3 * 10;
const long long e5  = e4 * 10;
const long long e6  = e4 * e2;
const long long e7  = e6 * 10;
const long long e8  = e7 * 10;
const long long mod = 1e9 + 7;
using namespace std; /*}}}*/

/*add{{{*/
long long base_add(long long a, long long b) {
    a %= mod;
    b %= mod;
    return (a + b) % mod;
}
long long add(initializer_list<long long> args) {
    long long ret = 0;
    for (auto i : args)
        ret = base_add(ret, i);
    return ret;
}
/*}}}*/

/*{{{mul*/
long long base_mul(long long a, long long b) {
    a %= mod;
    b %= mod;
    long long ret = 0;
    while (b) {
        if (b & 1)
            ret = (ret + a) % mod;
        b >>= 1;
        a = (a + a) % mod;
    }
    return ret;
}
long long mul(initializer_list<long long> args) {
    long long ret = 1;
    for (auto i : args)
        ret = base_mul(ret, i);
    return ret;
} /*}}}*/

/*{{{qpow*/
long long qpow(long long a, long long b) {
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = mul({ret, a});
        a = mul({a, a});
        b >>= 1;
    }
    return ret;
} /*}}}*/

string num[30]  = {"",       "One",    "Two",      "Three",    "Four",    "Five",    "Six",       "Seven",    "Eight",    "Nine",  "Ten",
                   "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"};
string num2[20] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string cal(int a) {
    int hundred = a / 100;
    int ten     = a / 10 - hundred * 10;
    int single  = a % 10;

    string ret = "";
    if (hundred > 0) {
        ret += num[hundred] + "Hundred"; // hundred
        if (ten + single > 0)
            ret += "And"; // and
    }
    if (a % 100 <= 20)
        return ret + num[a % 100];
    return ret + num2[ten] + num[single];
}
int main() {
    int ans = 11; // one thousand
    for (int i = 1; i < 1000; i++) {
        cout << i << ' ' << cal(i) << endl;
        ans += cal(i).length();
    }
    cout << ans << endl;
    return 0;
}

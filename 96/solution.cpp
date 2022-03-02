#include "../template/bigint.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
#include "../template/prime_cnt.cpp"
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
long long add(long long a, long long b) { return base_add(a, b); }
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
long long mul(long long a, long long b) { return base_mul(a, b); }
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

int num[9][9];
void gen(string a, int index) { /*{{{*/
    for (int i = 0; i < 9; i++) {
        num[index][i] = a[i] - '0';
    }
} /*}}}*/
bool isPlace(int count) { /*{{{*/
    int row = count / 9;
    int col = count % 9;
    int j;
    //同一行
    for (j = 0; j < 9; ++j) {
        if (num[row][j] == num[row][col] && j != col) {
            return false;
        }
    }
    //同一列
    for (j = 0; j < 9; ++j) {
        if (num[j][col] == num[row][col] && j != row) {
            return false;
        }
    }
    //同一小格
    int tempRow = row / 3 * 3;
    int tempCol = col / 3 * 3;
    for (j = tempRow; j < tempRow + 3; ++j) {
        for (int k = tempCol; k < tempCol + 3; ++k) {
            if (num[j][k] == num[row][col] && j != row && k != col) {
                return false;
            }
        }
    }
    return true;
} /*}}}*/
int ans = 0;
void backtrace(int count) { /*{{{*/
    if (count == 81) {
        ans += num[0][0] * 100 + num[0][1] * 10 + num[0][2];
    }
    int row = count / 9;
    int col = count % 9;
    if (num[row][col] == 0) {
        for (int i = 1; i <= 9; ++i) {
            num[row][col] = i;        //赋值
            if (isPlace(count)) {     //可以放
                backtrace(count + 1); //进入下一层
            }
        }
        num[row][col] = 0; //回溯
    } else {
        backtrace(count + 1);
    }
} /*}}}*/
int main() {
    freopen("./in", "r", stdin);
    string a;
    while (cin >> a) {
        gen(a, 0);
        for (int i = 1; i < 9; i++) {
            cin >> a;
            gen(a, i);
        }
        backtrace(0);
    }
    cout << ans << endl;
    return 0;
}

#include <iostream>/*{{{*/
#include <map>
#include <math.h>
#include <set>
#include <vector>
const int e4  = 10000;
const int e8  = e4 * e4;
const int mod = 1e9 + 7;
using namespace std; /*}}}*/
vector<int> need_check;
bool p[e8];
bool check(int a) {
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0 && p[i + a / i])
            return false;
    }
    return true;
}
int main() {
    p[0] = p[1] = true;
    for (int i = 2; i < e8; i++)
        if (!p[i]) {
            need_check.push_back(i - 1);
            for (int j = i << 1; j < e8; j += i)
                p[j] = true;
        }
    long long sum = 0;
    for (auto i : need_check)
        if (check(i))
            sum += i;
    cout << sum << endl;
    return 0;
}

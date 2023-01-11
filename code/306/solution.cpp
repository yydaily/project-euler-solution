#include <iostream>/*{{{*/
const long long e3 = 1000;
const long long e6 = e3 * e3;
using namespace std; /*}}}*/
int solve(int upper) {
    int ret    = upper / 34 * 5 + (upper >= 15) + (upper >= 35) + (upper >= 1);
    int data[] = {5, 9, 21, 25, 29};
    for (int i = 0; i < 5; i++)
        if (upper % 34 >= data[i])
            ret++;
    return upper - ret;
}
int main() {
    cout << solve(5) << endl;
    cout << solve(50) << endl;
    cout << solve(e6) << endl;
    return 0;
}

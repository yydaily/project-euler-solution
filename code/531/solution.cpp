#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
#include <iostream>  /*{{{*/
using namespace std; /*}}}*/
int main() {
    euler::init(1005000);
    long long ans = 0;
    for (int n = 1000000; n < 1005000; n++) {
        for (int m = n + 1; m < 1005000; m++) {
            ChinaReminder::clear();
            ChinaReminder::add(euler::phi(n), n);
            ChinaReminder::add(euler::phi(m), m);
            ans += ChinaReminder::China();
        }
    }
    cout << ans << endl;
    return 0;
}

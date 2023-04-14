#include <iostream>  /*{{{*/
using namespace std; /*}}}*/
int main() {
    double ans  = 0;
    double base = 2;
    for (int i = 2; i <= 30; i++) {
        ans += (base - 1) / i;
        base *= 2;
    }
    printf("%.2f\n", ans);
    return 0;
}

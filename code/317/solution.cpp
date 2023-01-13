#include <iostream>/*{{{*/
#include <math.h>
using namespace std; /*}}}*/
long double solve(long double hight, long double v, long double g) {
    long double upper = v * v / g / 2 + hight;
    return acos(-1) * upper * upper / g * v * v;
}
int main() {
    printf("%.4Lf\n", solve(100, 20, 9.81));
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int cal(int a, int upper = 999) {
    int b = upper / a;
    return a * b * (b + 1) / 2;
}
int main() {
    printf("%d\n", cal(3) + cal(5) - cal(15));
    return 0;
}

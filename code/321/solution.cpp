#include <iostream>/*{{{*/
#include <set>
using namespace std; /*}}}*/
long long n[50], k[50];
int main() {
    n[0] = 1, k[0] = 2;
    n[1] = 3, k[1] = 5;
    long long ans = 0;
    for (int index = 0; index < 40; index++) {
        n[index + 2] = 3 * n[index] + 2 * k[index] + 3;
        k[index + 2] = 4 * n[index] + 3 * k[index] + 5;
        ans += n[index];
    }
    cout << ans << endl;
    return 0;
}

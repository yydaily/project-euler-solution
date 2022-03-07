#include <bits/stdc++.h>
using namespace std;
int main() {
    long long a = 600851475143;
    for (long long i = 2; i <= a; i++) {
        while (a % i == 0) {
            cout << i << endl;
            a /= i;
        }
    }
    return 0;
}

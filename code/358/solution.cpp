#include <iostream>  /*{{{*/
using namespace std; /*}}}*/

bool check(long long a, long long &ret) {
    for (long long i = 2; i * i <= a; i++)
        if (a % i == 0)
            return false;

    long long remind = 1;
    long long l      = 0;
    while (remind != 1 || l == 0) {
        l++;
        ret += (remind * 10) / a;
        remind = (remind * 10) % a;
    }
    return l + 1 == a;
}

int main() {
    long long v = 0;
    check(7, v);
    cout << v << endl;
    v = 0;
    check(17, v);
    cout << v << endl;

    for (long long a = 724709891; a < 729909892; a += 100000) {
        v = 0;
        if (check(a, v)) {
            printf("%lld\n", v);
        }
    }
    return 0;
}

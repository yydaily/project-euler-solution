#include "../templete/bigint.cpp"
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int cal(BigInteger a) {
    int ret = 0;
    while (a > 0) {
        ret += a.num[0] % 10;
        a /= 10;
    }
    return ret;
}

int main() {
    auto val = BigInteger(1);
    for (int i = 1; i <= 100; i++) {
        val *= i;
    }
    cout << cal(val) << endl;
    return 0;
}

#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int cal(int a) {
    int cnt = 0;
    for (int i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            cnt += 2;
            if (a / i == i)
                cnt--;
        }
    }
    return cnt;
}
int main() {
    int val = 1;
    for (int i = 1; cal(val) <= 500; i++, val += i)
        ;
    cout << val << endl;
    return 0;
}

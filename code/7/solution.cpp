#include <iostream>
using namespace std;
const int len = 1e6;
bool prime[len];
int main() {
    int cnt = 0;
    for (int i = 2; i < len; i++) {
        if (!prime[i]) {
            cnt++;
            if (cnt == 10001)
                cout << i << endl;
            for (int j = i << 1; j < len; j += i)
                prime[j] = true;
        }
    }
    return 0;
}

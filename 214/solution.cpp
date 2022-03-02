#include <bits/stdc++.h>
using namespace std;
const int maxm = 4e7 + 1;
int num[maxm];
int e[maxm];
int main() {
    for (int i = 1; i < maxm; i++)
        num[i] = i;
    for (int i = 2; i < maxm; i++)
        if (num[i] == i)
            for (int j = i; j < maxm; j += i)
                num[j] = num[j] / i * (i - 1);
    e[1]          = 1;
    long long ans = 0;
    for (int i = 2; i < maxm; i++) {
        e[i] = e[num[i]] + 1;
        if (e[i] == 25 && num[i] == i - 1)
            ans += i;
    }
    cout << ans << endl;
    return 0;
}

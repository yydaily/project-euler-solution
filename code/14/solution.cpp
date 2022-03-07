#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
const int upper = 1e7;
int val[upper];
int get(long long a) {
    if (a < upper && val[a])
        return val[a];
    if (a == 1)
        return 1;
    long long b = a >> 1;
    if (a & 1)
        b = a * 3 + 1;

    int v = get(b) + 1;
    if (a < upper)
        val[a] = v;
    return v;
}
int main() {
    int ans = 0;
    int ind = 0;
    for (int i = 1; i < 1000000; i++) {
        int v = get(i);
        if (v > ans) {
            ans = v;
            ind = i;
        }
    }
    cout << ind << endl;
    return 0;
}

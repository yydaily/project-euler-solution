#include <iostream>
#include <vector>
using namespace std;
const int upper = 50;
long long num[upper + 1];

long long cal(int count, ...) {
    va_list arg_ptr;
    va_start(arg_ptr, count);
    vector<int> step;
    for (int i = 0; i < count; i++)
        step.emplace_back(va_arg(arg_ptr, int));
    va_end(arg_ptr);

    memset(num, 0, sizeof(num));
    num[0] = 1;
    for (int i = 1; i <= upper; i++)
        for (auto s : step) {
            if (i - s >= 0)
                num[i] += num[i - s];
        }
    return num[upper];
}

int main() {
    long long ans = 0;
    for (int i = 2; i <= 4; i++) {
        ans += cal(2, 1, i) - 1;
    }
    cout << ans << endl;
    return 0;
}

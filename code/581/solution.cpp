#include "../template/prime.cpp"
#include <iostream>  /*{{{*/
using namespace std; /*}}}*/

bool check(long long a) {
    for (auto i : Prime::prime) {
        if (i > 47)
            break;
        while (a % i == 0)
            a /= i;
        if (a == 1)
            break;
    }
    return a == 1;
}

long long dfs(long long upper, long long index = 0, long long now = 1) {
    __int128 p = Prime::prime[index];
    if (p > 47)
        return 0;
    long long ret = 0;
    while (true) {
        ret += dfs(upper, index + 1, now);
        if (p * now > upper)
            break;
        now *= p;
        if ((now % 2 == 1) && check((now + 1) / 2)) {
            ret += now;
        } else if ((now % 2 == 0) && check(now + 1)) {
            ret += now;
        }
    }
    return ret;
}
int main() {
    Prime::init(100);
    long long last_ans = -1;
    for (long long i = 1;; i *= 37) {
        long long now = dfs(i) + 1;
        cout << i << ' ' << now << endl;
        if (now == last_ans)
            break;
        last_ans = now;
    }
    cout << last_ans << endl;
    return 0;
}

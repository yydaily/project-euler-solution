#include <iostream>/*{{{*/
#include <map>
#include <math.h>
const long long e7 = 1e7;
using namespace std; /*}}}*/
map<long long, long long> cache;
long long cal(long long N) {
    if (N == 0)
        return 0;
    if (cache[N])
        return cache[N];
    // return \sum_{i=1}^N D(i)
    long long r = floor(cbrt(N));
    while ((r + 1) * (r + 1) * (r + 1) <= N)
        r++;
    while (r * r * r > N)
        r--;
    r = r * r * r;
    // r*r*r ~ N
    return cache[N] = cal(N - r) + (N - r + 1) + cal(r - 1);
}

long long S(long long N) {
    N--;
    for (long long i = 1; i * i * i <= N; i++) {
        cal(i * i * i);
    }
    return cal(N);
}
int main() {
    cout << S(100) << endl;
    cout << S(1e17) << endl;
    return 0;
}

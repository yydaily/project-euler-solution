#include <iostream>/*{{{*/
#include <map>
using namespace std; /*}}}*/
long long gcd(long long a, long long b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void add(map<pair<long long, long long>, bool> &x, long long fir, long long sec) {
    long long g = gcd(abs(fir), abs(sec));
    if (abs(sec) != 1)
        fir /= g, sec /= g;
    if (sec < 0)
        fir = -fir, sec = -sec;
    x[make_pair(fir, sec)] = true;
}

map<pair<long long, long long>, bool> handle(string s) {
    map<pair<long long, long long>, bool> ret;
    ret[make_pair(stoi(s), 1)] = true;
    if (s.length() == 1) {
        return ret;
    }

    for (int i = 1; i < s.length(); i++) {
        auto l = handle(s.substr(0, i));
        auto r = handle(s.substr(i));

        for (auto a : l)
            for (auto b : r) {
                // +
                long long fir = a.first.first * b.first.second + a.first.second * b.first.first;
                long long sec = a.first.second * b.first.second;
                if (fir || sec)
                    add(ret, fir, sec);

                // -
                fir = a.first.first * b.first.second - a.first.second * b.first.first;
                if (fir || sec)
                    add(ret, fir, sec);

                // *
                fir = a.first.first * b.first.first;
                if (fir || sec)
                    add(ret, fir, sec);

                // /
                fir = a.first.first * b.first.second;
                sec = a.first.second * b.first.first;
                if (fir || sec)
                    add(ret, fir, sec);
            }
    }

    return ret;
}
int main() {
    string req    = "123456789";
    long long ans = 0;
    for (auto i : handle(req)) {
        if (i.first.second == 1 && i.first.first > 0) {
            ans += i.first.first;
        }
    }
    cout << ans << endl;
    return 0;
}

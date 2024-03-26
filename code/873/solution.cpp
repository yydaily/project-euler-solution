#include "../template/fac_inv.cpp"
#include <iostream>/*{{{*/
long long _mod = 1e9 + 7;
using namespace std; /*}}}*/
long long cal(long long a, long long b) {
    // a 个相同的球，b个不同的桶，桶可以为空
    return FacInv::C(a + b - 1, b - 1);
}
long long W(long long a, long long b, long long c) {
    FacInv::init(a + b + c + 100, _mod);

    long long ans = 0;

    // 1. a 插入 b 中
    for (long long i = 1; i <= a; i++) {
        // a 被分成了 i 段
        // 1.1 头尾都是 b, 会造成 2*i 个空，用c填充
        long long base1 = FacInv::C(b - 1, i);                      // b-1个空中，选出i个空
        base1           = (base1 * FacInv::C(a - 1, i - 1)) % _mod; // a个球放到i个桶中，每个桶不为空，隔板法，桶是隔板
        ans             = (ans + cal(c - 2 * i * 2, a + b + 1) * base1 % _mod) % _mod;

        // 1.2 头或者尾是a，会造成 2*i-1 个空，用c填充
        long long base2 = FacInv::C(b - 1, i - 1) * 2 % _mod;       // b-1个空中，选出i-1个空
        base2           = (base2 * FacInv::C(a - 1, i - 1)) % _mod; // a个球放到i个桶中，每个桶不为空，隔板法，桶是隔板
        ans             = (ans + cal(c - (2 * i - 1) * 2, a + b + 1) * base2 % _mod) % _mod;

        if (i == 1)
            continue;
        // 1.3 头或者尾是a，会造成 2*i-2 个空，用c填充
        long long base3 = FacInv::C(b - 1, i - 2) % _mod;           // b-1个空中，选出i-2个空
        base3           = (base3 * FacInv::C(a - 1, i - 1)) % _mod; // a个球放到i个桶中，每个桶不为空，隔板法，桶是隔板
        ans             = (ans + cal(c - (2 * i - 2) * 2, a + b + 1) * base3 % _mod) % _mod;
    }

    return ans;
}
int main() {
    cout << W(2, 2, 4) << endl;
    cout << W(4, 4, 44) << endl;
    cout << W(1e6, 1e7, 1e8) << endl;
    return 0;
}

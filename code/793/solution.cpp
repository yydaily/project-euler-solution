#include <iostream>
using namespace std;
const int MAXN = 5e6;
struct treapNode {
    long long val;
    int s, p;
    treapNode *c[2];
} buf[MAXN];
int cnt_buf = 0;
int size(treapNode *root) { return root == nullptr ? 0 : root->s; }
void rotate(treapNode *&root, int d) { /*{{{*/
    treapNode *y = root->c[d];

    y->s    = root->s;
    root->s = size(root->c[d ^ 1]) + size(y->c[d ^ 1]) + 1;

    root->c[d] = y->c[d ^ 1], y->c[d ^ 1] = root, root = y;
} /*}}}*/
void insert(treapNode *&root, const long long &val) { /*{{{*/
    if (root == nullptr) {
        root       = &buf[cnt_buf++];
        root->val  = val;
        root->s    = 1;
        root->p    = rand();
        root->c[0] = root->c[1] = nullptr;
    } else {
        int d = val < root->val ? 0 : 1;
        insert(root->c[d], val);
        ++root->s;
        if (root->c[d]->p < root->p)
            rotate(root, d);
    }
} /*}}}*/
int lower_bound(treapNode *root, long long val) { /*{{{*/
    int ans = 0;
    while (root != nullptr) {
        if (root->val >= val)
            root = root->c[0];
        else {
            ans += size(root->c[0]) + 1;
            root = root->c[1];
        }
    }
    return ans;
} /*}}}*/
int upper_bound(treapNode *root, long long val) { /*{{{*/
    int ans = 0;
    while (root != nullptr) {
        if (root->val > val)
            root = root->c[0];
        else {
            ans += size(root->c[0]) + 1;
            root = root->c[1];
        }
    }
    return ans;
} /*}}}*/

const int e6 = 1000000;
long long s[e6 + 10];
const int length = 1000003;
void gen() {
    s[0] = 290797;
    for (int i = 1; i < length; i++) {
        s[i] = s[i - 1] * s[i - 1] % 50515093;
    }
}
long long cnt(long long bound) {
    // l = cnt(<bound), r = cnt(>bound), return r-l
    for (int i = 0; i < cnt_buf; i++) {
        buf[i].s = buf[i].p = buf[i].val = 0;
        buf[i].c[0] = buf[i].c[1] = nullptr;
    }
    cnt_buf = 0;

    treapNode *root = nullptr;
    long long ret   = 0;
    for (int i = length - 1; i >= 0; i--) {
        ret -= lower_bound(root, bound / s[i] + (bound % s[i] != 0));
        ret += length - 1 - i - upper_bound(root, bound / s[i] + (bound % s[i] == 0));
        insert(root, s[i]);
    }
    return ret;
}
int main() {
    auto start = clock();
    gen();
    long long l = 0, r = 50515093LL * 50515093LL;
    while (r - l >= 0) {
        cout << l << ' ' << r << ' ' << (clock() - start) * 1.0 / CLOCKS_PER_SEC << endl;
        long long mid = (l + r) >> 1;
        long long v   = cnt(mid);
        if (v > 0) {
            l = mid + 1;
        } else if (v < 0) {
            r = mid - 1;
        } else {
            cout << mid << endl;
            cout << 467284136913168 << endl;
            return 0;
        }
    }
    return 0;
}

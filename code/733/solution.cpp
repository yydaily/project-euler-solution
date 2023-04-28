#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const long long mod = 1e9 + 7;
const int _         = 1e6 + 10;
struct poi {
    long long value; // the real value
    int index;       // only for reorder
    int hash;        // record how big the value is, and for building trees
} d[_];
bool cmp1(const poi &a, const poi &b) { return a.value < b.value; }
bool cmp2(const poi &a, const poi &b) { return a.index < b.index; }
void init(int len) {
    long long base = 1;
    for (int i = 1; i <= len; i++) {
        d[i].value = base = (base * 153) % 10000019;
        d[i].index        = i;
    }
    sort(d + 1, d + len + 1, cmp1);
    for (int i = 1; i <= len; i++) {
        d[i].hash = i;
    }
    sort(d + 1, d + len + 1, cmp2);
}

struct tree {
    struct nouse {
        long long cnt;
        long long value;

        nouse operator+(const nouse &a) {
            nouse ret;
            ret.cnt   = (cnt + a.cnt) % mod;
            ret.value = (value + a.value) % mod;
            return ret;
        }
    } data[_ << 2];
    int len; // [1, len]
    void init(int _l) {
        len = _l;
        memset(data, 0, sizeof(data));
    }

    void add(int index, long long add_cnt, long long add_value, int tree_index = 1, int tree_l = 1, int tree_r = -1) {
        if (tree_r == -1)
            tree_r = len + 1;
        if (tree_l == tree_r) {
            data[tree_index].cnt   = (data[tree_index].cnt + add_cnt) % mod;
            data[tree_index].value = (data[tree_index].value + add_value) % mod;
            return;
        }
        int mid = (tree_l + tree_r) / 2;
        if (index <= mid)
            add(index, add_cnt, add_value, tree_index << 1, tree_l, mid);
        else
            add(index, add_cnt, add_value, tree_index << 1 | 1, mid + 1, tree_r);
        data[tree_index] = data[tree_index << 1] + data[tree_index << 1 | 1];
    }

    nouse get(int query_r, int tree_index = 1, int tree_l = 1, int tree_r = -1) {
        if (tree_r == -1)
            tree_r = len + 1;
        if (tree_l == tree_r)
            return data[tree_index];
        int mid = (tree_l + tree_r) / 2;
        if (query_r <= mid)
            return get(query_r, tree_index << 1, tree_l, mid);
        else {
            return data[tree_index << 1] + get(query_r, tree_index << 1 | 1, mid + 1, tree_r);
        }
    }
} t[3];

long long S(int len) {
    init(len);
    long long ans = 0;
    t[0].init(len);
    t[1].init(len);
    t[2].init(len);
    for (int i = 1; i <= len; i++) {
        auto x = t[2].get(d[i].hash - 1);
        ans    = (ans + x.value + x.cnt * d[i].value) % mod;
        x      = t[1].get(d[i].hash - 1);
        t[2].add(d[i].hash, x.cnt, (x.value + x.cnt * d[i].value) % mod);
        x = t[0].get(d[i].hash - 1);
        t[1].add(d[i].hash, x.cnt, (x.value + x.cnt * d[i].value) % mod);
        t[0].add(d[i].hash, 1, d[i].value);
    }
    return ans;
}
int main() {
    cout << S(6) << endl;
    cout << S(100) << endl;
    cout << S(1e6) << endl;
    return 0;
}

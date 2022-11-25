#include <iostream>/*{{{*/
#include <map>
#include <vector>
using namespace std; /*}}}*/
const long long mod = 1e9;
vector<vector<int>> conditions;
map<vector<int>, int> m;
long long c[30][30];

void init_c() {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
}

void add_condition(vector<int> &v) {
    m[v] = conditions.size();
    conditions.push_back(v);
}
void gen_condition(int guagua_cnt) {
    for (int i = 0; i <= guagua_cnt; i++) {
        for (int j = 0; i + j <= guagua_cnt; j++) {
            if (i == 0 && j == 0)
                continue;
            vector<int> buf(4);
            buf[0] = i;
            buf[1] = j;
            buf[2] = guagua_cnt - i - j;
            buf[3] = (buf[0] == 0 ? 1 : 0);
            add_condition(buf);
            if (buf[3] == 0) {
                buf[3] = 1;
                add_condition(buf);
            }
        }
    }
}

long long cal(vector<int> &a, vector<int> &b) {
    if (a[3] == 1 && b[3] == 0)
        return 0;
    if (a[3] == 1 && b[3] == 1 && b[0] == 0)
        return 0; // 已经有一列为空了，那么新增的列不能为空
    if (a[3] == 0 && b[3] == 1 && b[0] != 0)
        return 0; // 之前一列不为空，当前这一列也不为空，不可能变成空
    // a[0] a[1] a[2]
    //      b[0] b[1] b[2]
    if (b[0] < a[1] || b[1] < a[2])
        return 0;
    long long ans1 = c[a[0]][b[2]];
    long long ans2 = c[a[0] - b[2]][b[1] - a[2]];
    return ans1 * ans2 % mod;
}

vector<vector<long long>> gen_base_matrix() {
    int length = conditions.size();
    vector<vector<long long>> matrix(length);
    for (int i = 0; i < length; i++)
        matrix[i] = vector<long long>(length);
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            matrix[i][j] = cal(conditions[i], conditions[j]);
        }
    }
    return matrix;
}

vector<vector<long long>> mul(const vector<vector<long long>> &a, const vector<vector<long long>> &b) {
    vector<vector<long long>> ret(a.size());
    for (int i = 0; i < a.size(); i++)
        ret[i] = vector<long long>(a[0].size(), 0);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            for (int k = 0; k < b[0].size(); k++) {
                ret[i][k] = (ret[i][k] + a[i][j] * b[j][k] % mod) % mod;
            }
        }
    }
    return ret;
}

vector<vector<long long>> qpow(vector<vector<long long>> v, long long power) {
    vector<vector<long long>> ret(v.size());
    for (int i = 0; i < v.size(); i++) {
        ret[i]    = vector<long long>(v[0].size(), 0);
        ret[i][i] = 1;
    }
    while (power) {
        if (power & 1)
            ret = mul(ret, v);
        v = mul(v, v);
        power >>= 1;
    }
    return ret;
}

void F(int guagua_cnt, long long length) {
    conditions.clear();
    m.clear();

    guagua_cnt *= 2; // 来回看成两个青蛙
    length--;
    gen_condition(guagua_cnt);
    auto base = gen_base_matrix();
    base      = qpow(base, length);

    vector<int> ans1(4);
    ans1[0] = guagua_cnt;
    ans1[1] = ans1[2] = 0;
    ans1[3]           = 0;

    vector<int> ans2(4);
    ans2[0] = guagua_cnt;
    ans2[1] = ans2[2] = 0;
    ans2[3]           = 1;

    cout << "F(" << guagua_cnt / 2 << ", " << length + 1 << ") = " << (base[m[ans1]][m[ans1]] + base[m[ans1]][m[ans2]]) % mod << endl;
}

int main() {
    init_c();
    F(1, 3);
    F(1, 4);
    F(1, 5);
    F(2, 3);
    F(2, 100);
    F(10, 1e12);
    return 0;
}

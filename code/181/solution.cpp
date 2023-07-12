#include <iostream>  /*{{{*/
using namespace std; /*}}}*/
long long cache[61][41][61][41];
long long cal(int b, int w, int b_cnt, int w_cnt) {
    if (b * w_cnt > b_cnt * w)
        return 0; // 总体浓度不能高于上界
    if (b == 0 && w == 0)
        return 1;
    if (cache[b][w][b_cnt][w_cnt])
        return cache[b][w][b_cnt][w_cnt];

    long long ret = 0;
    for (int i = 0; i <= b; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 && j == 0)
                continue;
            if (i * w_cnt > b_cnt * j)
                continue;
            if (i * w_cnt == b_cnt * j && i > b_cnt)
                continue;
            if (i * w_cnt == b_cnt * j && i == b_cnt && j > w_cnt)
                continue;
            ret += cal(b - i, w - j, i, j);
        }
    }
    cache[b][w][b_cnt][w_cnt] = ret;
    return ret;
}
int main() {
    // (BBBW), (B, BBW), (BB, BW), (BBB, W), (B, B, BW), (B, BB, W), (B, B, B, W);
    // 60:40
    cout << cal(3, 1, 60, 0) << endl;
    cout << cal(60, 40, 60, 0) << endl;
    return 0;
}

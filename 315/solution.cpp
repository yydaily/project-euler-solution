#include <iostream>

using namespace std;
int trans[10][10];

void init() { /*{{{*/
    bool light[10][10];
    memset(light, false, sizeof(light));
    light[0][1] = light[0][2] = light[0][3] = light[0][5] = light[0][6] = light[0][7] = true;
    light[1][3] = light[1][6] = true;
    light[2][1] = light[2][3] = light[2][4] = light[2][5] = light[2][7] = true;
    light[3][1] = light[3][3] = light[3][4] = light[3][6] = light[3][7] = true;
    light[4][2] = light[4][3] = light[4][4] = light[4][6] = true;
    light[5][1] = light[5][2] = light[5][4] = light[5][6] = light[5][7] = true;
    light[6][1] = light[6][2] = light[6][4] = light[6][5] = light[6][6] = light[6][7] = true;
    light[7][1] = light[7][2] = light[7][3] = light[7][6] = true;
    light[8][1] = light[8][2] = light[8][3] = light[8][4] = light[8][5] = light[8][6] = light[8][7] = true;
    light[9][1] = light[9][2] = light[9][3] = light[9][4] = light[9][6] = light[9][7] = true;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            trans[i][j] = 0;
            for (int x = 1; x <= 7; x++) {
                if (light[i][x] != light[j][x])
                    trans[i][j]--;
                if (light[i][x])
                    trans[i][j]++;
                if (light[j][x])
                    trans[i][j]++;
            }
        }
} /*}}}*/
void cal(int a, int &len, int &sum) {
    len = sum = 0;
    while (a) {
        len++;
        sum += a % 10;
        a /= 10;
    }
}
int cal(int a, int b) {
    int ret = 0;
    while (b) {
        ret += trans[a % 10][b % 10];
        a /= 10;
        b /= 10;
    }
    return ret;
}
int cal(int a) { /*{{{*/
    int len, sum;
    int ret = 0;
    // cout<<a;
    while (a) {
        cal(a, len, sum);
        if (a == sum)
            return ret;
        ret += cal(a, sum);
        a = sum;
        /// cout<<"->"<<a;
    }
    // cout<<endl;
    return ret;
} /*}}}*/
bool p[20000007];
int main() {
    init();
    memset(p, false, sizeof(p));
    long long ans = 0;
    for (int i = 2; i <= 20000000; i++) {
        if (!p[i]) {
            for (int j = i << 1; j <= 20000000; j += i)
                p[j] = true;
            if (i >= 10000000)
                ans += cal(i);
        }
    }
    cout << ans << endl;
    return 0;
}

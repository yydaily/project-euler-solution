#include<bits/stdc++.h>
using namespace std;
long long num[100];
long long sum[100];
void init() {
    num[1] = 1;
    sum[1] = 1;
    num[2] = 2;
    sum[2] = 3;
    for(int i = 3;i<63;i++) {
        num[i] = num[i-1] + num[i-2];
        sum[i] = sum[i-1] + num[i];
    }
}
long long gao(int a, long long upper) {
    if(upper >= sum[a]) return 1ll<<a;
    auto ret = gao(a-1, upper);
    if(upper >= num[a]) ret += gao(a-1, upper-num[a]);
    return ret;
}
int main() {
    init();
    cout<<gao(62, 1e13)<<endl;
    return 0;
}


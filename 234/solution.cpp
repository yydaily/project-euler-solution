#include<iostream>
#include<math.h>
using namespace std;
const long long upper = 999966663333;
bool p[1000000+10];
long long cnt = 0;
long long sum = 0;
void handle(long long pi, long long pj) {/*{{{*/
	auto l = pi*pi+1;
	auto r = pj*pj-1;
	r = min(r, upper);
	if(l>r) return ;
	// [l, r];
	for(auto i = l/pi*pi;i<=r;i+=pi) {
		if(i<l||i%pj==0) continue;
		cnt++;
		sum+=i;
	}
	for(auto i = l/pj*pj;i<=r;i+=pj) {
		if(i<l||i%pi==0) continue;
		cnt++;
		sum+=i;
	}
}/*}}}*/

void handle() {/*{{{*/
	int last = -1;
	for(int i = 2;i<1000000;i++) {
		if(!p[i]) {
			if(last != -1) handle(last, i);
			last = i;
			for(int j = i<<1;j<1000000;j+=i) p[j] = true;
		}
	}
}/*}}}*/

int main() {
	handle();
	cout<<cnt<<' '<<sum<<endl;
	return 0;
}

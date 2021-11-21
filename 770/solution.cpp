#include<math.h>
#include<iostream>
using namespace std;
bool cal(int n) {
	return sqrt(3.141592653589793238462643383279502884197169399375105820974944592307816406286 * n) > 19999;
}
int main() {
	for(int i = 1;;i++) {
		if(cal(i)) {
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}

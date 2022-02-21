#include<iostream>/*{{{*/
#include<vector>
#include<set>
#include<math.h>
#include<map>
#include "../template/bigint.cpp"
const int e2 = 100;
const int e3 = e2*10;
const int e4 = e3*10;
const int e5 = e4*10;
const int e6 = e4*e2;
const int e7 = e6*10;
const int e8 = e7*10;
const int mod = 1e9+7;
using namespace std;/*}}}*/

/*add{{{*/
template <typename T>
T base_add(T a, T b) {
	a %= mod;
	b %= mod;
	return (a+b)%mod;
}
template <typename T>
T add(const T &t) { return t; }
template <typename T, typename ... Args>
T add(const T &t, const Args&... args) { return base_add(t, add(args...)); }
/*}}}*/

/*{{{mul*/
template <typename T>
T base_mul(T a, T b) {
	a%=mod;
	b%=mod;
	T ret(0);
	while(b) {
		if(b&1) ret = (ret + a) % mod;
		b>>=1;
		a = (a+a)%mod;
	}
	return ret;
}
template <typename T>
T mul(const T &t) { return t; }
template <typename T, typename ... Args>
T mul(const T &t, const Args&... args) { return base_mul(t, mul(args...)); }
/*}}}*/

/*{{{qpow*/
template <typename T>
T qpow(T a, T b) {
	T ret(1);
	while(b) {
		if(b&1) ret = mul(ret, a);
		a = mul(a, a);
		b>>=1;
	}
	return ret;
}
/*}}}*/

void split(const std::string& s,
    std::vector<std::string>& sv,
                  const char* delim = " ") {/*{{{*/
    sv.clear();                                 // 1.
    char* buffer = new char[s.size() + 1];      // 2.
    buffer[s.size()] = '\0';
    std::copy(s.begin(), s.end(), buffer);      // 3.
    char* p = std::strtok(buffer, delim);       // 4.
    do {
        sv.push_back(p);                        // 5.
    } while ((p = std::strtok(NULL, delim)));   // 6.
    delete[] buffer;
    return;
}/*}}}*/

int num[20] = {0};
map<int, int> m;
bool check() {
	m.clear();
	vector<int> val;
	for(int i = 1;i<(1<<num[0]);i++) {
		int sum = 0;
		int cnt = 0;
		for(int j = 0;j<num[0];j++) {
			if(i&(1<<j)) {
				sum+=num[j+1];
				cnt++;
			}
		}
		if(m[sum]) return false;
		val.emplace_back(sum);
		m[sum] = cnt;
	}
	sort(val.begin(), val.end());
	for(int i = 1;i<val.size();i++) {
		if(m[val[i]] < m[val[i-1]]) return false;
	}
	return true;
}
int main() {
	freopen("./in", "r", stdin);
	string a;
	int ans = 0;
	int case_cnt = 0;
	while(cin>>a) {
		vector<string> x;
		split(a, x, ",");
		num[0] = 0;
		for(auto i : x) {
			num[++num[0]] = stoi(i);
		}
		if(check()) {
			for(int i = 1;i<=num[0];i++) ans+=num[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}

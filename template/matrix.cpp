#include <vector>
namespace matrix {
	long long _mod = 1000000007;
	void init(long long mod) {
		_mod = mod;
	}
	void format(std::vector<std::vector<long long>> &a) {
		if(a.size()&1) {
			a.resize(a.size()+1);
			a[a.size()-1] = std::vector<long long>(a[0].size(), 0);
		}
		if(a[0].size()&1) {
			for(int i = 0;i<a.size();i++) {
				a[i].push_back(0);
			}
		}
	}

	std::vector<std::vector<long long>> add(const std::vector<std::vector<long long>> &a, const std::vector<std::vector<long long>> &b) {
		if(a.size() != b.size() || a[0].size() != b[0].size()) {
			assert(false);
		}
		std::vector<std::vector<long long>> ret(a.size(), std::vector<long long>(a[0].size(), 0));
		for(int i = 0;i<a.size();i++) {
			for(int j = 0;j<a[0].size();j++) {
				ret[i][j] = (a[i][j] + b[i][j]) % _mod;
			}
		}
		return ret;
	}
	std::vector<std::vector<long long>> sub(const std::vector<std::vector<long long>> &a, const std::vector<std::vector<long long>> &b) {
		if(a.size() != b.size() || a[0].size() != b[0].size()) {
			assert(false);
		}
		std::vector<std::vector<long long>> ret(a.size(), std::vector<long long>(a[0].size(), 0));
		for(int i = 0;i<a.size();i++) {
			for(int j = 0;j<a[0].size();j++) {
				ret[i][j] = ((a[i][j] - b[i][j])%_mod + _mod)%_mod;
			}
		}
		return ret;
	}

	std::vector<std::vector<long long>> force_mul(const std::vector<std::vector<long long>> &a, const std::vector<std::vector<long long>> &b) {
		std::vector<std::vector<long long>> ret(a.size(), std::vector<long long>(b[0].size(), 0));
		for(int i = 0;i<a.size();i++) {
			for(int j = 0;j<b[0].size();j++) {
				for(int k = 0;k<b.size();k++) {
					ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]%_mod)%_mod;
				}
			}
		}
		return ret;
	}

	std::vector<std::vector<long long>> sub_graph(const std::vector<std::vector<long long>> &a, int x, int y) {
		int x_start = 0, x_end = a.size() / 2;
		if(x==2) {
			x_start = x_end;
			x_end = a.size();
		}
		int y_start = 0, y_end = a[0].size() / 2;
		if(y==2) {
			y_start = y_end;
			y_end = a[0].size();
		}

		std::vector<std::vector<long long>> ret(x_end - x_start, std::vector<long long>(y_end - y_start, 0));
		for(int i = x_start;i<x_end;i++) {
			for(int j = y_start;j<y_end;j++) {
				ret[i-x_start][j-y_start] = a[i][j];
			}
		}
		return ret;
	}
	void copy_graph(const std::vector<std::vector<long long>> &a, std::vector<std::vector<long long>> &b, int x, int y) {
		int x_start = 0, x_end = b.size() / 2;
		if(x==2) {
			x_start = x_end;
			x_end = b.size();
		}
		int y_start = 0, y_end = b[0].size() / 2;
		if(y==2) {
			y_start = y_end;
			y_end = b[0].size();
		}

		for(int i = x_start;i<x_end;i++) {
			for(int j = y_start;j<y_end;j++) {
				b[i][j] = a[i-x_start][j-y_start];
			}
		}
	}

	std::vector<std::vector<long long>> mul(std::vector<std::vector<long long>> a, std::vector<std::vector<long long>>b) {
		if(a[0].size() != b.size()) {
			assert(false);
		}
		int n = a.size(); // 最后返回的必须是 n*k 的矩阵，可能需要裁剪
		int k = b[0].size();

		if(n < 10 && b.size()<4 && k < 4) {
			return force_mul(a, b);
		}

		format(a);
		format(b);

		auto a21 = sub_graph(a, 2, 1);
		auto a22 = sub_graph(a, 2, 2);
		auto a11 = sub_graph(a, 1, 1);
		auto a12 = sub_graph(a, 1, 2);

		auto b21 = sub_graph(b, 2, 1);
		auto b22 = sub_graph(b, 2, 2);
		auto b11 = sub_graph(b, 1, 1);
		auto b12 = sub_graph(b, 1, 2);

		auto s1 = add(a21, a22);
		auto s2 = sub(s1, a11);
		auto s3 = sub(a11, a21);
		auto s4 = sub(a12, s2);

		auto t1 = sub(b12, b11);
		auto t2 = sub(b22, t1);
		auto t3 = sub(b22, b12);
		auto t4 = sub(t2, b21);

		auto m1 = mul(a11, b11);
		auto m2 = mul(a12, b21);
		auto m3 = mul(s4, b22);
		auto m4 = mul(a22, t4);
		auto m5 = mul(s1, t1);
		auto m6 = mul(s2, t2);
		auto m7 = mul(s3, t3);

		auto u1 = add(m1, m2);
		auto u2 = add(m1, m6);
		auto u3 = add(u2, m7);
		auto u4 = add(u2, m5);
		auto u5 = add(u4, m3);
		auto u6 = sub(u3, m4);
		auto u7 = add(u3, m5);

		std::vector<std::vector<long long>> ret(a.size(), std::vector<long long>(b[0].size(), 0));
		copy_graph(u1, ret, 1, 1);
		copy_graph(u5, ret, 1, 2);
		copy_graph(u6, ret, 2, 1);
		copy_graph(u7, ret, 2, 2);

		ret.resize(n);
		for(auto &i : ret) {
			i.resize(k);
		}

		return ret;
	}
};

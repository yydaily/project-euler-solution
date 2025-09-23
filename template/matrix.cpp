#include <vector>
#include <cassert>
namespace Matrix {
	long long _mod = 1000000007;
	void init(long long mod) {
		_mod = mod;
	}
    template<typename T>
    class matrix {
    public:
        std::vector<std::vector<T>> a_;
        matrix(int n = 0, T v = 0) {
            a_ = std::vector<std::vector<T>>(n, std::vector<T>(n, v));
        }
        void format() {
            if(a_.size()&1) {
                a_.resize(a_.size()+1);
                a_[a_.size()-1] = std::vector<T>(a_[0].size(), 0);
            }
            if(a_[0].size()&1) {
                for(int i = 0;i<a_.size();i++) {
                    a_[i].emplace_back(0);
                }
            }
        }

        matrix add(const matrix & a, const matrix & b) {
            if(a.a_.size() != b.a_.size() || a.a_[0].size() != b.a_[0].size()) {
                assert(false);
            }
            matrix ret(a.a_.size(), 0);
            for(int i = 0;i<a.a_.size();i++) {
                for(int j = 0;j<a.a_[0].size();j++) {
                    ret.a_[i][j] = (a.a_[i][j] + b.a_[i][j]) % _mod;
                }
            }
            return ret;
        }

        matrix sub(const matrix & a, const matrix & b) {
            if(a.a_.size() != b.a_.size() || a.a_[0].size() != b.a_[0].size()) {
                assert(false);
            }
            matrix ret(a.a_.size(), 0);
            for(int i = 0;i<a.a_.size();i++) {
                for(int j = 0;j<a.a_[0].size();j++) {
                    ret.a_[i][j] = (a.a_[i][j] - b.a_[i][j] + _mod) % _mod;
                }
            }
            return ret;
        }

        matrix force_mul(const matrix & a, const matrix & b) {
            matrix ret(a.a_.size(), 0);
            for(int i = 0;i<a.a_.size();i++) {
                for(int j = 0;j<a.a_[0].size();j++) {
                    for(int k = 0;k<a.a_[0].size();k++) {
                        ret.a_[i][j] = (ret.a_[i][j] + a.a_[i][k] * b.a_[k][j] % _mod) % _mod;
                    }
                }
            }
            return ret;
        }

        matrix sub_graph(const matrix & a, int x, int y) {
            int x_start = 0, x_end = a.a_.size() / 2;
            if(x==2) {
                x_start = x_end;
                x_end = a.a_.size();
            }
            int y_start = 0, y_end = a.a_[0].size() / 2;
            if(y==2) {
                y_start = y_end;
                y_end = a.a_[0].size();
            }

            matrix ret(x_end - x_start, 0);
            for(int i = x_start;i<x_end;i++) {
                for(int j = y_start;j<y_end;j++) {
                    ret.a_[i-x_start][j-y_start] = a.a_[i][j];
                }
            }
            return ret;
        }

        void copy_graph(const matrix & a, matrix & b, int x, int y) {
            int x_start = 0, x_end = b.a_.size() / 2;
            if(x==2) {
                x_start = x_end;
                x_end = b.a_.size();
            }
            int y_start = 0, y_end = b.a_[0].size() / 2;
            if(y==2) {
                y_start = y_end;
                y_end = b.a_[0].size();
            }

            for(int i = x_start;i<x_end;i++) {
                for(int j = y_start;j<y_end;j++) {
                    b.a_[i][j] = a.a_[i-x_start][j-y_start];
                }
            }
        }

        matrix mul(const matrix & a, const matrix & b) {
            if(a.a_[0].size() != b.a_[0].size()) {
                assert(false);
            }

            int n = a.a_.size();
            int k = b.a_[0].size();

            if(n<10 && b.a_.size()<4 && k<4) {
                return force_mul(a, b);
            }
            a.format();
            b.format();

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

            matrix ret(n, 0);
            copy_graph(u1, ret, 1, 1);
            copy_graph(u5, ret, 1, 2);
            copy_graph(u6, ret, 2, 1);
            copy_graph(u7, ret, 2, 2);

            ret.a_.resize(n);
            for(auto &i : ret) i.resize(k);

            return ret;
        }

        matrix qpow(matrix a, long long n) {
            assert(a.a_.size() == a.a_[0].size());
            matrix ret(a.a_.size(), 0);
            for(int i = 0;i<a.a_.size();i++) {
                ret.a_[i][i] = 1;
            }
            while(n) {
                if(n&1) {
                    ret = mul(ret, a);
                }
                a = mul(a, a);
                n >>= 1;
            }
            return ret;
        }
    };
};

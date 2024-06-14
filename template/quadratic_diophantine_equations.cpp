#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
namespace QDE { // QDE : Quadratic Diophantine Equations
	typedef long long int64;
	inline int64 square(int64 a) {/*{{{*/
		return a*a;
	}
	int64 gcd(int64 a, int64 b) {
		if(a==0) return b;
		return gcd(b%a, a);
	}
	int64 exgcd(int64 a,int64 b,int64 &x,int64 &y) {
		if(b==0) {            
			x=1;
			y=0;
			return a;
		}
		int64 r=exgcd(b, a%b, x, y);
		int64 t=y;
		y=x-(a/b)*y;    
		x=t;
		return r;
	}/*}}}*/
	inline bool multi(int64 a, int64 b) {/*{{{*/
		return a%b==0;
	}/*}}}*/
	struct ans {/*{{{*/
		int64 x, y;
		int64 A, B, C, D, E, F;
		ans() {}
		ans(int64 _x, int64 _y) {
			x = _x, y = _y;
			A = 1, B = 0, C = 0;
			D = 0, E = 1, F = 0;
		}
		ans(int64 _x, int64 _y, int64 a, int64 b, int64 c, int64 d, int64 e, int64 f) {
			x = _x, y = _y;
			A = a, B = b, C = c, D = d, E = e, F = f;
		}
		// x = Ax + By + C
		// y = Dx + Ey + F
		ans gen() {
			return ans(A*x+B*y+C, D*x+E*y+F, A, B, C, D, E, F);
		}
		void show() {
			cout<<x<<' '<<y<<endl;
		}
	};/*}}}*/
	struct Solver {
		int64 A, B, C, D, E, F;
		bool check(ans a) {
			return A*a.x*a.x + B*a.x*a.y + C*a.y*a.y + D*a.x + E*a.y + F == 0;
		}
		bool show(int64 v, bool prefix, string suffix) {/*{{{*/
			if(v==0) return false;
			if(prefix) {
				printf(v>0?" + ":" - ");
				if(abs(v) == 1 && suffix != "") {
					printf("%s", suffix.c_str());
				} else {
					printf("%lld%s", abs(v), suffix.c_str());
				}
			} else {
				if(v == 1 && suffix != "") {
					printf("%s", suffix.c_str());
				} else if(v==-1 && suffix != "") {
					printf("-%s", suffix.c_str());
				} else {
					printf("%lld%s", v, suffix.c_str());
				}
			}
			return true;
		}
		void show() {
			bool prefix = false;
			prefix |= show(A, prefix, "x^2");
			prefix |= show(B, prefix, "xy");
			prefix |= show(C, prefix, "y^2");
			prefix |= show(D, prefix, "x");
			prefix |= show(E, prefix, "y");
			prefix |= show(F, prefix, "");
			printf(" = 0\n");
		}/*}}}*/
		Solver(int64 a, int64 b, int64 c, int64 d, int64 e, int64 f) {/*{{{*/
			if(a<0) {
				a = -a, b = -b, c = -c, d = -d, e = -e, f = -f;
			}
			A = a, B = b, C = c, D = d, E = e, F = f;
		}/*}}}*/
		vector<ans> solve() {/*{{{*/
			if(A==0&&B==0&&C==0) {
				return solve1();
			} else if(A==0&&C==0){
				return solve2();
			} else {
				int64 delta = B*B-4*A*C;
				if(delta < 0) {
					return solve3();
				} else if(delta==0) {
					return solve4();
				} else if(D==0&&E==0) {
					return solve5();
				} else {
				}
			}
		}/*}}}*/
		vector<ans> solve1() {/*{{{*/
			// Dx + Ey + F = 0 -- 无穷多解
			// D = 1, E = 2, F = -1
			vector<ans> ret;
			int64 G = gcd(D, E);
			if(F%G!=0) return ret;
			D/=G, E/=G, F/=G;
			int64 x, y;
			exgcd(D, E, x, y);
			// Dx+Ey=1
			x*=-F, y*=-F;
			// Dx + Ey + F = 0
			ret.push_back(ans(x, y, 1, 0, E, 0, 1, -D));
			ret.push_back(ans(x-E, y+D, 1, 0, -E, 0, 1, D));
			return ret;
		}/*}}}*/
		vector<ans> solve2() {/*{{{*/
			printf("%lldxy + %lldx + %lldy + %lld = 0\n", B, D, E, F);
			// Bxy + Dx + Ey + F = 0
			// (Bx+E)(By+D) = DE-BF
			vector<ans> ret;
			if(D*E-B*F==0) {/*{{{*/
				// 可能有无穷多解
				if(E%B==0) {
					ret.push_back(ans(-E/D, 0, 1, 0, 0, 0, 1, 1));
					ret.push_back(ans(-E/D, 0, 1, 0, 0, 0, 1, -1));
				}
				if(D%B==0) {
					ret.push_back(ans(0, -D/B, 1, 0, 1, 1, 0, 0));
					ret.push_back(ans(0, -D/B, 1, 0, -1, 1, 0, 0));
				}
				return ret;
			}/*}}}*/

			// 有限解
			auto now = D*E-B*F;
			for(int64 i = 1;i*i<=now;i++) {
				if(now%i!=0) continue;
				// 1. Bx+E = ±i, By+D = ±now/i
				if((i-E)%B==0 && (now/i-D)%B==0) {
					ret.push_back(ans((i-E)/B, (now/i-D)/B));
					ret.push_back(ans((-i-E)/B, (-now/i-D)/B));
				}
				// 2. Bx+E = ±now/i, By+D = ±i
				if((now/i-E)%B==0 && (i-D)%B==0) {
					ret.push_back(ans((now/i-E)/B, (i-D)/B));
					ret.push_back(ans((-now/i-E)/B, (-i-D)/B));
				}
			}
			return ret;
		}/*}}}*/
		vector<ans> solve3() {/*{{{*/
			// Ax^2 + Bxy + Cy^2 + Dx + Ey + F = 0
			// B^2 - 4AC < 0;
			vector<ans> ret;
			int64 a = (B*B-4*A*C);
			int64 b = 2*(B*E-2*C*D);
			int64 c = E*E-4*C*F;
			int64 delta = b*b-4*a*c;
			int64 s = sqrt(delta);
			int64 l = (-b-s)/(2*a), r = (-b+s)/(2*a);
			if(l>r) swap(l, r);
			for(int64 i = l;i<=r;i++) {
				int64 d = square(B*i+E) - 4*C*(A*i*i+ D*i + F);
				int64 ds = sqrt(d);
				if(ds*ds != d) continue;

				if((-B*i-E + ds)%(C*2) == 0) {
					ret.push_back(ans(i, (-B*i-E+ds)/C/2));
				}
				if((-B*i-E-ds)%(C*2) == 0) {
					ret.push_back(ans(i, (-B*i-E-ds)/C/2));
				}
			}
			return ret;
		}/*}}}*/
		vector<ans> solve4() {/*{{{*/
			vector<ans> ret;
			int64 g = gcd(A, C);
			int64 a = A/g; // square
			int64 sqr_a = sqrt(a);
			int64 c = C/g; // square
			int64 sqr_c = sqrt(c);
			int64 b = B/g;
			if(B/A < 0) sqr_c = -sqr_c;
			// (sqr_c*D-sqr_A*E) * y = sqr_a*g*u^2 + D*u + sqr_a*F
			// u = sqr_a*x + sqr_c*y
			if(sqr_c*D == sqr_a*E) {/*{{{*/
				// sqr_a*g*u^2 + D*u + sqr_a*F = 0
				int64 now = D*D - 4*sqr_a*F*sqr_a*g;
				int64 s = sqrt(now);
				if(s*s != now) return ret; // no result
				// (-D ± s) / (2*sqr_a*g)
				if((D+s)%(2*sqr_a*g) == 0) {
					// sqr_a*x + sqr_c*y - x_1 = 0
					int64 x_1 = (-D-s) / (2*sqr_a*g);
					for(auto i : Solver(0, 0, 0, sqr_a, sqr_c, -x_1).solve()) {
						ret.push_back(i);
					}
				}
				if(s != 0 && (D-s)%(2*sqr_a*g) == 0) {
					// sqr_a*x + sqr_c*y - x_2 = 0
					int64 x_2 = (-D+s) / (2*sqr_a*g);
					for(auto i : Solver(0, 0, 0, sqr_a, sqr_c, -x_2).solve()) {
						ret.push_back(i);
					}
				}
				return ret;
			}/*}}}*/
			int64 mod = sqr_c*D - sqr_a*E;
			for(int64 u = abs(mod)-1;u>=0;u--) {
				if((sqr_a*g%mod*u%mod*u%mod + D*u%mod + sqr_a*F%mod)%mod!=0) continue;
				cout<<E<<' '<<sqr_c<<' '<<g<<' '<<u<<endl;
				cout<<"x = "<<sqr_c*g*(-mod)<<"t^2 + "<<-(E+2*sqr_c*g*u)<<"t + "<<-(sqr_c*g*u*u + E*u + sqr_c*F)/mod<<endl;
				cout<<"y = "<<sqr_a*g*mod<<"t^2 + "<<(D+2*sqr_a*g*u)<<"t + "<<(sqr_a*g*u*u+D*u+sqr_a*F)/mod<<endl;
				cout<<"t in (-\\infty, \\infty)"<<endl;
			////ret.push_back(ans(-(sqr_c*g*u*u + E*u + sqr_c*F)/mod, 
			////	(sqr_a*g*u*u+D*u+sqr_a*F)/mod, 
			////	2*sqr_c*g*(sqr_a*E-sqr_c*D)+1, 0, 
			////	sqr_c*g*(sqr_a*E-sqr_c*D) - (E + 2*sqr_c*g*u),
			////	0, 2*sqr_a*g*mod+1,
			////	sqr_a*g*mod + D + 2*sqr_a*g));
			}
			return ret;
		}/*}}}*/
		vector<ans> solve5() {/*{{{*/
			vector<ans> ret;
			int64 delta = B*B - 4*A*C;
			if(F==0) {/*{{{*/
				ret.push_back(ans(0, 0));
				if(delta<0) return ret;
				int64 s = sqrt(delta);
				if(s*s != delta) return ret;
				// 7*x*x - 24*x*y + 18*y*y = 0
				for(auto i : Solver(0, 0, 0, 2*A, B+s, 0).solve()) {
					ret.push_back(i);
				}
				if(s==0) return ret;
				for(auto i : Solver(0, 0, 0, 2*A, B-s, 0).solve()) {
					ret.push_back(i);
				}
				return ret;
			}/*}}}*/
			if(delta < 0) return ret;
			int64 k = sqrt(delta);
			if(k*k == delta) {/*{{{*/
				// (2Ax + (B+k)*y) (2Ax + (B-k)*y) = -4AF
				for(int64 i = 1;i*i<=abs(4*A*F);i++) {
					if(!multi(4*A*F, i)) continue;
					int64 ui[4] = {i, -i, 4*A*F/i, -4*A*F/i};
					for(int j = 0;j<4;j++) {
						int64 u = ui[j];
						if((u+4*A*F/u) % (2*k) != 0) continue;
						int64 y = (u+4*A*F/u)/k/2;
						if((u-(B+k)*y) % (2*A) != 0) continue;
						int64 x = (u-(B+k)*y)/A/2;
						ret.push_back(ans(x, y));
					}
				}
				return ret;
			}/*}}}*/
			// F != 0 && k*k != delta
			int64 g = gcd(gcd(A, B), C);
			if(F%g != 0) return ret;
			A/=g, B/=g, C/=g, F/=g;
			assert(4*F*F >= B*B - 4*A*F); // 否则有无穷多不规则的解
			// todo xzn : 太复杂了，看不懂了
		}/*}}}*/
	};
}

int main() {
	auto s = QDE::Solver(1, 5, 4, 0, 0, 0);
	for(auto i : s.solve()) {
		i.show();
		assert(s.check(i));
		i.gen().show();
		assert(s.check(i.gen()));
		i.gen().gen().show();
		assert(s.check(i.gen().gen()));
		cout<<endl;
	}
	return 0;
}

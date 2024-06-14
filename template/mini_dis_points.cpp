#include<math.h>
#include<iostream>
#include<vector>
namespace MiniDisPoints {
	struct point {
		double x, y;
		int id;
		point() {};
		point(int _x, int _y, int _id): x(_x), y(_y), id(_id) {};
	};

	bool cmp_x(const point& a, const point& b) {
		return a.x < b.x || (a.x == b.x && a.y < b.y);
	}

	bool cmp_y(const point& a, const point& b) { return a.y < b.y; }

	int n;
	std::vector<point> a;
	double mindist;
	int ansa, ansb;

	void init(int length) {
		n = length;
		mindist = 1e100;
	}

	void add_point(double x, double y) {
		a.push_back(point(x, y, a.size()));
	}

	void add_over() {
		sort(a.begin(), a.end(), cmp_x);
	}

	double mini_dis() {
		return mindist;
	}

	inline void upd_ans(const point& a, const point& b) {
		double dist =
			sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + .0);
		if (dist < mindist) mindist = dist, ansa = a.id, ansb = b.id;
	}
	
	void rec(int l, int r) {
		if (r - l <= 3) {
			for (int i = l; i <= r; ++i)
				for (int j = i + 1; j <= r; ++j) upd_ans(a[i], a[j]);
			sort(a.begin() + l, a.begin() + r + 1, cmp_y);
			return;
		}

		int m = (l + r) >> 1;
		int midx = a[m].x;
		rec(l, m), rec(m + 1, r);
		inplace_merge(a.begin() + l, a.begin() + m + 1, a.begin() + r + 1, cmp_y);

		static point t[1000000];
		int tsz = 0;
		for (int i = l; i <= r; ++i)
			if (abs(a[i].x - midx) < mindist) {
				for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)
					upd_ans(a[i], t[j]);
				t[tsz++] = a[i];
			}
	}
};


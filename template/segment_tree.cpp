#include<stdlib.h>
#include<iostream>
namespace SegTree {
	template<typename T, size_t len>
	struct SegmentTree {
		T data[len<<2];
		void (*push_down)(T a, T lson, T rson);
		void (*push_up)(T a, T lson, T rson);
		T (*merge)(T lson, T rson);

		void SetPushDown(void (*push)(const T &a, const T &lson, const T &rson)) {
			push_down = push;
		}

		void SetPushUp(void (*push)(const T &a, const T &lson, const T &rson)) {
			push_up = push;
		}

		void SetMerge(T (*merge)(const T &lson, const T &rson)) {
			this->merge = merge;
		}

		T& operator[](int idx) {
			return data[idx];
		}

		T query(int lind, int rind, int l = 1, int r = len, int idx = 1) {
			if(lind <= l && r <= rind) {
				return data[idx];
			}

			int mid = (l + r) >> 1;
			if(rind <= mid) {
				return query(lind, rind, l, mid, idx<<1);
			} else if(lind > mid) {
				return query(lind, rind, mid+1, r, idx<<1|1);
			} else {
				push_down(data[idx], data[idx<<1], data[idx<<1|1]);
				T a = query(lind, rind, l, mid, idx<<1);
				T b = query(lind, rind, mid+1, r, idx<<1|1);
				push_up(data[idx], data[idx<<1], data[idx<<1|1]);
				return merge(a, b);
			}
		}

		void update(int ind, T val, int l = 1, int r = len, int idx = 1) {
			if(l <= ind && ind <= r) {
				
				data[idx] = update_one_node(data[idx], val);
				return;
			}

			int mid = (l + r) >> 1;
			if (ind <= mid) {
				update(ind, val, l, mid, idx<<1);
			} else {
				update(ind, val, mid+1, r, idx<<1|1);
			}

			data[idx] = merge_son(data[idx<<1], data[idx<<1|1]);
		}
	};
};

int min(int a, int b) {
	if(a<b) return a;
	return b;
}

int main() {
	SegTree::SegmentTree<int, 100> a;
	a[1] = 1;
	std::cout<<a[1]<<std::endl;
	return 0;
}

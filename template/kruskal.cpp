#include<vector>

namespace Kruskal {
	struct edge {/*{{{*/
		int from, to, value;
		edge() {};
		edge(int _from, int _to, int _value) {
			from = _from;
			to = _to;
			value = _value;
		}
		bool operator<(const edge&a) const {
			if(value != a.value) return value < a.value;
			if(from != a.from) return from < a.from;
			return to < a.to;
			return true;
		}
	};/*}}}*/
	int n;
	vector<edge> v;
	vector<int> pre;
	int find(int a) {/*{{{*/
		if(pre[a] == a) return a;
		pre[a] = find(pre[a]);
		return pre[a];
	}/*}}}*/
	void merge(int a, int b) {
		pre[find(a)] = find(b);
	}
	int min_tree() {/*{{{*/
		pre.resize(n+1);
		for(int i = 1;i<=n;i++) pre[i] = i;
		sort(v.begin(), v.end());
		int ret = 0;
		for(auto i : v) {
			if(find(i.from) != find(i.to)) {
				merge(i.from, i.to);
				ret += i.value;
			}
		}
		return ret;
	}/*}}}*/
}

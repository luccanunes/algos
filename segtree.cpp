#include <bits/stdc++.h>

using namespace std;

int n;

struct Segtree {
	vector<int> tree;
	void build(const vector<int>& v) { // !! do this with a constructor
		while (__builtin_popcount(n) != 1) {
			v.push_back(0);
			n++;
		}
		tree.resize(2*n);
		for (int i = 0; i < n; i++)
			tree[n+i] = v[i];
		for (int i = n - 1; i >= 1; i--)
			tree[i] = tree[2*i] + tree[2*i+1];
	}	
	int query(int node, int ql, int qr, int nl, int nr) const {
		if (ql <= nl && qr >= nr) return tree[node];
		if (ql > nr || qr < nl) return 0;
		int k = (nl + nr)/2;
		return query(2*node, ql, qr, nl, k) + query(2*node + 1, ql, qr, k+1, nr);
	}
};

int main() {
	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);
	Segtree st;
	st.build(v);
	int Q, a, b;
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", st.query(1, a, b, 0, n-1));
	}
	return 0;
}
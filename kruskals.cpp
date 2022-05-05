#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

struct Edge {
	int w, a, b;
	void read() {
		scanf("%d%d%d", &a, &b, &w);
	}
	bool operator<(const Edge& e) {
		return make_tuple(w, a, b) < make_tuple(e.w, e.a, e.b);
	}
};

int link[MAXN], sizes[MAXN];

int find(int x) {
	while (x != link[x]) x = link[x];
	return x;
}
bool same(int a, int b) {
	return find(a) == find(b);
}
void unite(int a, int b) {
	a = find(a), b = find(b);
	if (sizes[a] < sizes[b]) swap(a, b);
	sizes[a] += sizes[b];
	link[b] = a;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) link[i] = i, sizes[i] = 1;
	vector<Edge> edges(m);
	for (Edge& e : edges) 
		e.read();
	sort(edges.begin(), edges.end());
	int min_weight = 0;
	for (auto e : edges) {
		if (!same(e.a, e.b)) {
			unite(e.a, e.b);
			printf("%d <-> %d\n", e.a, e.b);
			min_weight += e.w;
		}
	}
	printf("%d\n", min_weight);
	return 0;
}
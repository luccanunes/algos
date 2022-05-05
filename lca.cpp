#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10, LOG = 20;

vector<int> adj[MAXN];
int depth[MAXN], anc[MAXN][LOG];
bool visited[MAXN];

void dfs(int s) {
	for (int u : adj[s]) {
		if (visited[u]) continue;
		visited[u] = true;
		depth[u] = depth[s] + 1;
		anc[u][0] = s;
		for (int i = 1; i < LOG; i++)
			anc[u][i] = anc[anc[u][i-1]][i-1];
		dfs(u);
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	int k = depth[a] - depth[b];
	for (int i = LOG-1; i >= 0; i--)
		if (k & (1 << i))
			a = anc[a][i];
	if (a == b) return a;
	for (int i = LOG-1; i >= 0; i--) {
		if (anc[a][i] == anc[b][i]) continue;
		a = anc[a][i];
		b = anc[b][i];
	}
	return anc[a][0];
}

int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n-1; i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	visited[0] = true;
	dfs(0);
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", lca(a, b));
	}
	return 0;
}
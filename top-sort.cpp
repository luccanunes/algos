#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	vector<int> adj[n];
	int indeg[n] = {0};
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		indeg[b]++;
	}
	queue<int> q; // ? is priority_queue needed? dts
	for (int i = 0; i < n; i++)
		if (indeg[i] == 0)
			q.push(i);
	vector<int> ans;
	while (!q.empty()) {
		int s = q.front(); q.pop();
		for (int u : adj[s]) {
			indeg[u]--;
			if (indeg[u] == 0)
				q.push(u);
		}
		ans.push_back(s);
	}
	if (ans.size() != n) {
		printf("impossible\n");
		return 0;
	}
	for (int x : ans)
		printf("%d ", x);
	printf("\n");
	return 0;
}
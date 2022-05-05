#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
	int n, m, a, b, w, x, y;
	scanf("%d%d%d%d", &n, &m, &x, &y);
	vector<pair<int, int>> adj[n];
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &w);
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}
	priority_queue<pair<int, int>> q;
	bool visited[n] = {0};
	int dist[n];
	for (int i = 0; i < n; i++) dist[i] = INF;
	dist[x] = 0;
	q.push({0, x});
	while (!q.empty()) {
		int node = q.top().second; q.pop();
		if (visited[node]) continue;
		for (auto p : adj[node]) {
			b = p.first, w = p.second;
			if (dist[b] > dist[node] + w) {
				dist[b] = dist[node] + w;
				q.push({-dist[b], b});
			}
		}
		visited[node] = true;
	}
	printf("%d\n", dist[y]);
	return 0;
}
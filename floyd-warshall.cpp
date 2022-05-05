#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
	int n, m, a, b, x, y;
	scanf("%d%d%d%d", &n, &m, &x, &y);
	int adj[n][n];
	memset(adj, 0, sizeof(adj));
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &w);
		adj[a][b] = w;
		adj[b][a] = w;
	}
	int dist[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (adj[i][j]) dist[i][j] = adj[i][j];
			else if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dist[i][j] = min(dist[i][k], dist[i][k] + dist[k][j]);
	printf("%d\n", dist[x][y]);
	return 0;
}
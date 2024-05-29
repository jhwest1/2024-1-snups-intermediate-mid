#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 110;

int n, m, v1, v2, e, g[SZ][SZ];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> m >> v1 >> v2 >> e;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			g[i][j] = 5e8;
			if (i == j) {
				g[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		g[u][v] = min(g[u][v], w);
		g[v][u] = min(g[v][u], w);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}

	int ans = 5e8;
	for (int x = 1; x <= n; x++) {
		ans = min(ans, g[v1][x] + g[v2][x] + g[x][e]);
	}

	if (ans == 5e8) {
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
	}

}
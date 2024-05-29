#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 110;

int n, m, g[SZ][SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			g[i][j] = 1e9;
			if (i == j) {
				g[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		g[u][v] = min(g[u][v], w);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}

	int ans = 1e9;
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v < u; v++) {
			ans = min(ans, g[u][v] + g[v][u]);
		}
	}

	cout << ans << '\n';

}
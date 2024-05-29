#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 110;

int n, m, dist[SZ], done[SZ];
int g[SZ][SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		g[u][v] = w;
	}

	for (int i = 1; i <= n; i++) {
		dist[i] = 1e9;
	}
	dist[1] = 0;

	for (int i = 1; i <= n; i++) {
		int p = -1;
		for (int j = 1; j <= n; j++) {
			if (!done[j] && (p == -1 || dist[p] > dist[j])) {
				p = j;
			}
		}

		if (dist[p] == 1e9) break;
		done[p] = true;
		
		for (int j = 1; j <= n; j++) {
			if (g[p][j] && dist[j] > dist[p] + g[p][j]) {
				dist[j] = dist[p] + g[p][j];
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (dist[i] == 1e9) {
			cout << -1 << '\n';
		}
		else {
			cout << dist[i] << '\n';
		}
	}

}
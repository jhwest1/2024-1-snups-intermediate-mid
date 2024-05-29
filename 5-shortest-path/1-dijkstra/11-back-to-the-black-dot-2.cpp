#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 101010;

int n, m, r[2], dist[2][SZ];
vector<pii> g[SZ];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> n >> m >> r[0] >> r[1];

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		g[u].push_back({w, v});
		g[v].push_back({w, u});
	}
	
	for (int t = 0; t < 2; t++) {
		for (int i = 1; i <= n; i++) {
			dist[t][i] = 5e8;
		}
		dist[t][r[t]] = 0;

		priority_queue<pii> pq;
		pq.push({0, r[t]});

		while (!pq.empty()) {
			int d = -pq.top().ff;
			int v = pq.top().ss;

			pq.pop();
			if (dist[t][v] != d) {
				continue;
			}

			for (auto [w, x] : g[v]) {
				if (dist[t][x] > dist[t][v] + w) {
					dist[t][x] = dist[t][v] + w;
					pq.push({-dist[t][x], x});
				}
			}
		}
	}

	int minv = 1e9;
	for (int i = 1; i <= n; i++) {
		if (i == r[0] || i == r[1]) {
			continue;
		}
		minv = min(minv, dist[0][i] + dist[1][i] + dist[0][r[1]]);
	}

	if (minv == 1e9) {
		cout << -1 << '\n';
	}
	else {
		cout << minv << '\n';
	}
}
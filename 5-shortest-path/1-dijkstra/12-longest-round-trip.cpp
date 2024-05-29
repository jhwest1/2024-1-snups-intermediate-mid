#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 1010;

int n, m, x, dist[2][SZ];
vector<pii> g[2][SZ];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		g[0][u].push_back({w, v});
		g[1][v].push_back({w, u});
	}

	for (int t = 0; t < 2; t++) {
		for (int i = 1; i <= n; i++) {
			dist[t][i] = 1e9;
		}

		priority_queue<pii> pq;
		pq.push({0, x});

		dist[t][x] = 0;

		while (!pq.empty()) {
			int d = -pq.top().ff;
			int v = pq.top().ss;

			pq.pop();
			if (dist[t][v] != d) {
				continue;
			}

			for (auto [w, x] : g[t][v]) {
				if (dist[t][x] > dist[t][v] + w) {
					dist[t][x] = dist[t][v] + w;
					pq.push({-dist[t][x], x});
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i != x) {
			ans = max(ans, dist[0][i] + dist[1][i]);
		}
	}
	cout << ans << '\n';

}
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 505;

int n, m, x;
pair<int, pair<int, pii>> e[SZ];

int dist[SZ];
vector<pii> g[SZ];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int u, v, l, c;
		cin >> u >> v >> l >> c;

		e[i] = {c, {l, {u, v}}};
	}
	sort(e, e + m);

	int minv = 2e9 + 10;
	for (int i = m - 1; i >= 0; i--) {
		int w = e[i].ss.ff;
		auto [u, v] = e[i].ss.ss;

		g[u].push_back({w, v});
		g[v].push_back({w, u});

		for (int j = 1; j <= n; j++) {
			dist[j] = 1e9;
		}
		dist[1] = 0;
		
		priority_queue<pii> pq;
		pq.push({0, 1});

		while (!pq.empty()) {
			int d = -pq.top().ff;
			int v = pq.top().ss;

			pq.pop();
			if (dist[v] != d) {
				continue;
			}

			for (auto [w, x] : g[v]) {
				if (dist[x] > dist[v] + w) {
					dist[x] = dist[v] + w;
					pq.push({-dist[x], x});
				}
			}
		}

		minv = min(minv, dist[n] + x / e[i].ff);
	}
	cout << minv << '\n';
}
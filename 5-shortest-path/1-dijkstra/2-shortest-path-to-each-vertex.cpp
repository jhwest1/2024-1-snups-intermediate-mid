#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 20202;

int n, m, k, dist[SZ];
vector<pii> g[SZ];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		g[u].push_back({w, v});
		g[v].push_back({w, u});
	}

	priority_queue<pii> pq;
	pq.push({0, k});

	for (int i = 1; i <= n; i++) {
		dist[i] = 1e9;
	}
	dist[k] = 0;

	while (!pq.empty()) {
		int d = -pq.top().ff;
		int v = pq.top().ss;

		pq.pop();
		if (dist[v] != d) {
			continue;
		}

		for (auto [w, x] : g[v]) {
			if (dist[x] > w + dist[v]) {
				dist[x] = w + dist[v];
				pq.push({-dist[x], x});
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i] == 1e9) {
			cout << -1 << '\n';
		}
		else {
			cout << dist[i] << '\n';
		}
	}
}
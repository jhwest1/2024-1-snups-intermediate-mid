#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 50505;

int n, m, u[SZ], v[SZ], w[2][SZ], cost[SZ], dist[SZ];
vector<pii> g[SZ];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i] >> w[0][i] >> w[1][i];

		g[v[i]].push_back({i, u[i]});
	}	

	for (int t = 0; t < 2; t++) {
		for (int i = 1; i <= n; i++) {
			dist[i] = 1e9;
		}
		dist[n] = 0;

		priority_queue<pii> pq;
		pq.push({0, n});

		while (!pq.empty()) {
			int d = -pq.top().ff;
			int v = pq.top().ss;

			pq.pop();
			if (dist[v] != d) {
				continue;
			}

			for (auto [i, x] : g[v]) {
				if (dist[x] > dist[v] + w[t][i]) {
					dist[x] = dist[v] + w[t][i];
					pq.push({-dist[x], x});
				}
			}
		}
		for (int i = 0; i < m; i++) {
			if (dist[u[i]] != dist[v[i]] + w[t][i]) {
				cost[i]++;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		dist[i] = 1e9;
	}
	dist[n] = 0;

	priority_queue<pii> pq;
	pq.push({0, n});

	while (!pq.empty()) {
		int d = -pq.top().ff;
		int v = pq.top().ss;

		pq.pop();
		if (dist[v] != d) {
			continue;
		}

		for (auto [i, x] : g[v]) {
			if (dist[x] > dist[v] + cost[i]) {
				dist[x] = dist[v] + cost[i];
				pq.push({-dist[x], x});
			}
		}
	}

	cout << dist[1] << '\n';
}
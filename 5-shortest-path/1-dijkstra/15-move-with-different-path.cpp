#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 101010;

int n, m, u[SZ], v[SZ], w[SZ], dist[SZ], dead[SZ];
vector<pii> g[SZ];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i] >> w[i];

		g[u[i]].push_back({i, v[i]});
		g[v[i]].push_back({i, u[i]});
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
			if (dist[x] > dist[v] + w[i]) {
				dist[x] = dist[v] + w[i];
				pq.push({-dist[x], x});
			}
		}
	}

	for (int v = 1; v != n; ) {
		int p = -1;
		int e = -1;
		for (auto [i, x] : g[v]) {
			if (dist[v] == dist[x] + w[i] && (p == -1 || p > x)) {
				p = x;
				e = i;
			}
		}
		v = p;
		dead[e] = true;
	}

	for (int i = 1; i <= n; i++) {
		dist[i] = 1e9;
	}
	dist[1] = 0;
	
	pq.push({0, 1});

	while (!pq.empty()) {
		int d = -pq.top().ff;
		int v = pq.top().ss;

		pq.pop();
		if (dist[v] != d) {
			continue;
		}

		for (auto [i, x] : g[v]) {
			if (!dead[i] && dist[x] > dist[v] + w[i]) {
				dist[x] = dist[v] + w[i];
				pq.push({-dist[x], x});
			}
		}
	}

	cout << dist[n] << '\n';

}
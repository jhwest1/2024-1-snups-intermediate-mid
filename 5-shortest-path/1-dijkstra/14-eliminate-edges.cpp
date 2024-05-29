#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 5050;

int n, m, u[SZ], v[SZ], w[SZ], dist[SZ], back[SZ];
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

		for (auto [i, x] : g[v]) {
			if (dist[x] > dist[v] + w[i]) {
				dist[x] = dist[v] + w[i];
				back[x] = i;
				pq.push({-dist[x], x});
			}
		}
	}

	int shortest = dist[n];

	vector<int> V;
	for (int x = n; x != 1; x = (u[back[x]] ^ v[back[x]] ^ x)) {
		V.push_back(back[x]);
	}

	int ans = 0;
	for (auto e : V) {
		for (int i = 1; i <= n; i++) {
			g[i].clear();
			dist[i] = 1e9;
		}
		dist[1] = 0;

		for (int i = 0; i < m; i++) {
			if (i != e) {
				g[u[i]].push_back({w[i], v[i]});
				g[v[i]].push_back({w[i], u[i]});
			}
		}

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

		if (dist[n] != shortest) {
			++ans;
		}
	}

	cout << ans << '\n';

}
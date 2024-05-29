#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 101010;

int n, m, a[3], dist[3][SZ];
vector<pii> g[SZ];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> n >> m;
	
	for (int t = 0; t < 3; t++) {
		cin >> a[t];
	}

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		g[u].push_back({w, v});
		g[v].push_back({w, u});
	}

	for (int t = 0; t < 3; t++) {
		priority_queue<pii> pq;
		pq.push({0, a[t]});

		for (int i = 1; i <= n; i++) {
			dist[t][i] = 1e9;
		}
		dist[t][a[t]] = 0;

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

	int maxv = -1;
	for (int v = 1; v <= n; v++) {
		maxv = max(maxv, min(dist[0][v], min(dist[1][v], dist[2][v])));	
	}

	cout << maxv << '\n';

}
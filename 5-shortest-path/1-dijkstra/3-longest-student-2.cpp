#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 101010;

int n, m, dist[SZ];
vector<pii> g[SZ];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		g[v].push_back({w, u});
	}

	priority_queue<pii> pq;
	pq.push({0, n});

	for (int i = 1; i <= n; i++) {
		dist[i] = 1e9;
	}
	dist[n] = 0;

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

	cout << *max_element(dist + 1, dist + 1 + n) << '\n';

}
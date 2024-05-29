#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 101010;

int n, m, a, b, dist[SZ];
vector<pii> g[SZ];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		g[u].push_back({w, v});
		g[v].push_back({w, u});
	}

	cin >> a >> b;

	priority_queue<pii> pq;
	pq.push({0, b});

	for (int i = 1; i <= n; i++) {
		dist[i] = 1e9;
	}
	dist[b] = 0;

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

	vector<int> ans;
	for (int v = a; v != b; ) {
		int p = -1;
		for (auto [w, x] : g[v]) {
			if (w + dist[x] == dist[v] && (p == -1 || p > x)) {
				p = x;
			}
		}
		ans.push_back(v);
		v = p;
	}
	ans.push_back(b);

	cout << dist[a] << '\n';
	for (int x : ans) {
		cout << x << ' ';
	}
	cout << '\n';
	
}
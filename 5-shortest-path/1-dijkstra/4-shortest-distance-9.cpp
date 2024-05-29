#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 101010;

int n, m, a, b, dist[SZ], back[SZ];
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
	pq.push({0, a});

	for (int i = 1; i <= n; i++) {
		dist[i] = 1e9;
	}
	dist[a] = 0;

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
				back[x] = v;
				pq.push({-dist[x], x});
			}
		}
	}

	vector<int> ans;
	for (int v = b; v != a; v = back[v]) {
		ans.push_back(v);
	}
	ans.push_back(a);

	reverse(ans.begin(), ans.end());

	cout << dist[b] << '\n';
	for (int x : ans) {
		cout << x << ' ';
	}
	cout << '\n';
	
}
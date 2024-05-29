#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 1010;
const int INF = 1e9 + 10;

int n, a, b, done[SZ]; pll dist[SZ];
pii g[SZ][SZ];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> a >> b >> n;

	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			if (i != j) {
				g[i][j] = {INF, INF};
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int cost, sz;
		cin >> cost >> sz;

		vector<int> V(sz);
		for (int j = 0; j < sz; j++) {
			cin >> V[j];
		}

		for (int j = 0; j < sz; j++) {
			for (int k = 0; k < j; k++) {
				g[V[k]][V[j]] = min(g[V[k]][V[j]], {cost, j - k});
			}
		}
	}

	for (int i = 0; i < SZ; i++) {
		dist[i] = {1e15, 1e15};
	}
	dist[a] = {0, 0};

	for (int i = 0; i < SZ; i++) {
		int p = -1;
		for (int j = 0; j < SZ; j++) {
			if (!done[j] && (p == -1 || dist[p] > dist[j])) {
				p = j;
			}
		}

		if (dist[p].ff == 1e15) break;
		done[p] = true;

		for (int j = 0; j < SZ; j++) {
			if (g[p][j].ff != INF) {
				ll new_cost = dist[p].ff + g[p][j].ff;
				ll new_time = dist[p].ss + g[p][j].ss;

				if (new_cost < dist[j].ff || (new_cost == dist[j].ff && new_time < dist[j].ss)) {
					dist[j].ff = new_cost;
					dist[j].ss = new_time;
				}
			}
		}
	}

	if (dist[b].ff == 1e15) {
		cout << "-1 -1\n";
	}
	else {
		cout << dist[b].ff << ' ' << dist[b].ss << '\n';
	}
}
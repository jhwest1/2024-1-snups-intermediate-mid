#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 110;

int n, m, g[SZ][SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		g[u][v] = true;
	}
	for (int i = 1; i <= n; i++) g[i][i] = true;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				g[i][j] |= (g[i][k] & g[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			if (g[i][j] || g[j][i]) {
				++ans;
			}
		}

		cout << n - ans << '\n';
	}
}
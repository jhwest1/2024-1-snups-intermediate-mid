#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 110;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, a[SZ][SZ], vis[SZ][SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 1e9;

	for (int i = 1; i <= 500; i++) {
		int s = 0, e = 500;
		while (s < e) {
			int d = (s + e) / 2;

			int L = i;
			int R = i + d;

			if (a[0][0] < L || a[0][0] > R) {
				s = d + 1;
				continue;
			}

			queue<pii> Q;
			Q.push({0, 0});
			vis[0][0] = true;

			while (!Q.empty()) {
				auto [x, y] = Q.front();
				Q.pop();

				for (int t = 0; t < 4; t++) {
					int nx = x + dx[t];
					int ny = y + dy[t];

					if (0 <= nx && nx < n && 0 <= ny && ny < m && L <= a[nx][ny] && a[nx][ny] <= R && !vis[nx][ny]) {
						vis[nx][ny] = true;
						Q.push({nx, ny});
					}
				}
			}

			if (vis[n - 1][m - 1]) {
				e = d;
			}
			else {
				s = d + 1;
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					vis[i][j] = false;
				}
			}
		}
		ans = min(ans, s);
	}
	cout << ans << '\n';

}
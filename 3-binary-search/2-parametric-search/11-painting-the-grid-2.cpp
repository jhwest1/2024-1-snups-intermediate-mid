#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 110;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, a[SZ][SZ], vis[SZ][SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int s = 0, e = 1e6;
	while (s < e) {
		int d = (s + e) / 2;

		int mx = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (vis[i][j]) continue;

				queue<pii> Q;
				Q.push({i, j});
				vis[i][j] = true;

				int cnt = 0;
				while (!Q.empty()) {
					auto [x, y] = Q.front();
					Q.pop();

					cnt++;
					for (int t = 0; t < 4; t++) {
						int nx = x + dx[t];
						int ny = y + dy[t];

						if (0 <= nx && nx < n && 0 <= ny && ny < n && abs(a[x][y] - a[nx][ny]) <= d && !vis[nx][ny]) {
							vis[nx][ny] = true;
							Q.push({nx, ny});
						}
					}
				}
				mx = max(mx, cnt);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				vis[i][j] = false;
			}
		}

		if (mx >= (n * n + 1) / 2) e = d;
		else s = d + 1;
	}

	cout << s << '\n';

}
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 110;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, a[SZ][SZ], b[SZ][SZ], vis[SZ][SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int px, py;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
			if (b[i][j] == 1) {
				px = i;
				py = j;
			}
		}
	}

	int s = 0, e = 1e9;
	while (s < e) {
		int d = (s + e) / 2;

		queue<pii> Q;
		Q.push({px, py});
		vis[px][py] = true;

		while (!Q.empty()) {
			auto [x, y] = Q.front();
			Q.pop();

			for (int t = 0; t < 4; t++) {
				int nx = x + dx[t];
				int ny = y + dy[t];

				if (0 <= nx && nx < n && 0 <= ny && ny < m && abs(a[x][y] - a[nx][ny]) <= d && !vis[nx][ny]) {
					vis[nx][ny] = true;
					Q.push({nx, ny});
				}
			}
		}
		bool flag = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (b[i][j] && !vis[i][j]) {
					flag = false;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vis[i][j] = false;
			}
		}

		if (flag) e = d;
		else s = d + 1;
	}
	cout << s << '\n';

}

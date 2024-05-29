#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 33;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, a, b, dist[SZ][SZ];
string S[SZ];

bool in(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		cin >> S[i];
	}

	int maxv = -1;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			
			if (x != 0 && x != n - 1 && y != 0 && y != n - 1) {
				continue;
			}
			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					dist[i][j] = 1e9;
				}
			}

			priority_queue<pair<int, pii>> pq;
			pq.push({0, {x, y}});

			dist[x][y] = 0;

			while (!pq.empty()) {
				int d = -pq.top().ff;
				auto [x, y] = pq.top().ss;

				pq.pop();
				if (dist[x][y] != d) {
					continue;
				}

				for (int t = 0; t < 4; t++) {
					int nx = x + dx[t];
					int ny = y + dy[t];

					if (!in(nx, ny)) continue;

					int cost = (S[x][y] == S[nx][ny]) ? a : b;

					if (dist[nx][ny] > dist[x][y] + cost) {
						dist[nx][ny] = dist[x][y] + cost;
						pq.push({-dist[nx][ny], {nx, ny}});
					}
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					maxv = max(maxv, dist[i][j]);
				}
			}
		}
	}
	cout << maxv << '\n';

}
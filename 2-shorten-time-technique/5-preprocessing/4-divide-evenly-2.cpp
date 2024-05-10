#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 1010;

int n, a[SZ][SZ];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		a[x][y]++;
	}	

	for (int i = 1; i < SZ; i++) {
		for (int j = 1; j < SZ; j++) {
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	}

	int minv = n;
	for (int x = 0; x < SZ; x += 2) {
		for (int y = 0; y < SZ; y += 2) {
			int cnt[4] = {};

			cnt[0] = a[x][y];
			cnt[1] = a[x][SZ - 1] - a[x][y];
			cnt[2] = a[SZ - 1][y] - a[x][y];
			cnt[3] = n - cnt[0] - cnt[1] - cnt[2];

			minv = min(minv, *max_element(cnt, cnt + 4));
		}
	}
	cout << minv << '\n';
}
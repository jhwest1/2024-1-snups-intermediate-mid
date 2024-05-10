#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 505;

int n, k, a[SZ][SZ];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	}

	int maxv = a[k][k];
	for (int i = k; i <= n; i++) {
		for (int j = k; j <= n; j++) {
			maxv = max(maxv, a[i][j] - a[i - k][j] - a[i][j - k] + a[i - k][j - k]);
		}
	}

	cout << maxv << '\n';
}
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int n;
	cin >> n;

	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {
			if (!a[i][j]) {
				a[i][j] ^= 1;
				a[i + 1][j] ^= 1;
				if (j > 0) a[i + 1][j - 1] ^= 1;
				if (j < n - 1) a[i + 1][j + 1] ^= 1;
				if (i < n - 2) a[i + 2][j] ^= 1;

				++ans;
			}
		}
	}

	for (int j = 0; j < n; j++) {
		if (!a[n - 1][j]) {
			return !(cout << -1 << '\n');
		}
	}

	cout << ans << '\n';
}
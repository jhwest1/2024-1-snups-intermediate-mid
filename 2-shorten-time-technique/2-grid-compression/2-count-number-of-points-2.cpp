#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 1010;

int n, q, x[SZ], y[SZ], a[SZ][SZ];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> q;

	vector<int> vecx, vecy;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];

		vecx.push_back(x[i]);
		vecy.push_back(y[i]);
	}

	// grid compression
	sort(vecx.begin(), vecx.end());
	vecx.erase(unique(vecx.begin(), vecx.end()), vecx.end());

	sort(vecy.begin(), vecy.end());
	vecy.erase(unique(vecy.begin(), vecy.end()), vecy.end());

	for (int i = 0; i < n; i++) {
		int posx = lower_bound(vecx.begin(), vecx.end(), x[i]) - vecx.begin() + 1;
		int posy = lower_bound(vecy.begin(), vecy.end(), y[i]) - vecy.begin() + 1;

		a[posx][posy]++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
		}
	}

	while (q--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		r1 = lower_bound(vecx.begin(), vecx.end(), r1) - vecx.begin();
		r2 = upper_bound(vecx.begin(), vecx.end(), r2) - vecx.begin();
		
		c1 = lower_bound(vecy.begin(), vecy.end(), c1) - vecy.begin();
		c2 = upper_bound(vecy.begin(), vecy.end(), c2) - vecy.begin();

		cout << a[r2][c2] - a[r1][c2] - a[r2][c1] + a[r1][c1] << '\n';
	}
}
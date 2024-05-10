#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int tot[101010];
int occ[101010];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int out = 0;
	int ins = 0;

	for (int i = 0; i < n; i++) {
		if (!tot[a[i]]) {
			++out;
		}
		tot[a[i]]++;
	}

	int ans = 1e9;
	for (int i = 0, p = 0; i < n; i++) {
		while (p < n && ins < k) {
			if (!occ[a[p]]) {
				++ins;
			}
			occ[a[p]]++;
			tot[a[p]]--;
			if (!tot[a[p]]) {
				--out;
			}
			++p;
		}

		if (out == k && ins == k) {
			ans = min(ans, p - i);
		}

		if (!tot[a[i]]) {
			++out;
		}
		tot[a[i]]++;
		occ[a[i]]--;
		if (!occ[a[i]]) {
			--ins;
		}
	}

	if (ans == 1e9) cout << -1 << '\n';
	else {
		cout << ans << '\n';
	}
}
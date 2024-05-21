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

	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].second >> a[i].first;
	}

	sort(a.begin(), a.end());

	int ans = 0;
	for (int i = 0, p = n - 1; i < n; i++) {
		while (a[i].second > 0) {
			while (p >= 0 && a[p].second == 0) {
				--p;
			}
			ans = max(ans, a[i].first + a[p].first);

			int mn = min(a[i].second, a[p].second);
			a[i].second -= mn;
			a[p].second -= mn;
		}
	}
	cout << ans << '\n';
}
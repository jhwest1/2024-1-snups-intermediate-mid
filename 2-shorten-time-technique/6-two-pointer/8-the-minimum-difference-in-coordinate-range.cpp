#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int n, k;
	cin >> n >> k;

	vector<pii> a(n);
	for (auto &[x, y] : a) {
		cin >> x >> y;
	}
	sort(a.begin(), a.end());

	set<pii> st;

	int ans = 1e9;
	for (int i = 0, p = 0; i < n; i++) {
		while (p < n && (st.empty() || prev(st.end())->first - st.begin()->first < k)) {
			st.insert({a[p].second, p});
			++p;
		}
		if (!st.empty() && prev(st.end())->first - st.begin()->first >= k) {
			ans = min(ans, a[p - 1].first - a[i].first);
		}

		st.erase({a[i].second, i});
	}

	if (ans == 1e9) cout << -1 << '\n';
	else {
		cout << ans << '\n';
	}
}
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int c, n;
	cin >> c >> n;

	set<int> st;
	for (int i = 0; i < c; i++) {
		int x;
		cin >> x;

		st.insert(x);
	}

	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	sort(a.begin(), a.end(), [&](pair<int, int> p, pair<int, int> q) {
		return p.second < q.second;
	});

	int ans = 0;
	for (int i = 0; i < n; i++) {
		auto it = st.lower_bound(a[i].first);
		if (it != st.end() && *it <= a[i].second) {
			++ans;
			st.erase(it);
		}
	}

	cout << ans << '\n';
}
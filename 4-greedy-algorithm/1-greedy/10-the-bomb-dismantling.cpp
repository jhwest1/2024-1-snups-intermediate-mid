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
		cin >> a[i].first >> a[i].second;
	}

	sort(a.rbegin(), a.rend());

	set<int> st;
	for (int i = 1; i <= 10000; i++) {
		st.insert(i);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		auto it = st.upper_bound(a[i].second);
		if (it != st.begin()) {
			st.erase(prev(it));
			ans += a[i].first;
		}
	}

	cout << ans << '\n';
	
}
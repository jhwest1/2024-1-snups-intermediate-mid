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

	vector<pair<int, int>> a(n + 2);

	map<int, int> mp;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;

		a[i] = {x, y};
		mp[x]++;
		mp[y]--;
	}
	
	// compute the total length
	int prv = -1;
	int tot = 0;
	int cur = 0;

	for (auto [x, k] : mp) {
		if (cur != 0) {
			tot += x - prv;
		}
		cur += k;
		prv = x;
	}

	sort(a.begin() + 1, a.end() - 1);
	a[n + 1].first = 1e9;

	for (int i = 2; i <= n; i++) {
		if (a[i - 1].second > a[i].second) {
			// one segment contains one another
			return !(cout << tot << '\n');
		}
	}

	// compute the minimum possible decreasing length
	int minv = 1e9;
	for (int i = 1; i <= n; i++) {
		minv = min(minv, min(a[i + 1].first, a[i].second) - max(a[i - 1].second, a[i].first));
	}

	cout << tot - minv << '\n';
}
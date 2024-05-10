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
		cin >> y >> x;
	}
	sort(a.begin(), a.end());

	int maxv = 0;
	for (int i = 0, p = 0, s = 0; i < n; i++) {
		while (p < n && a[p].first - a[i].first <= 2 * k + 1) {
			s += a[p].second;
			++p;
		}
		maxv = max(maxv, s);
		s -= a[i].second;
	}

	cout << maxv << '\n';
}
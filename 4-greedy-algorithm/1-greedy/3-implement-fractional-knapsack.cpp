#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	sort(a.begin(), a.end(), [&](pair<int, int> p, pair<int, int> q) {
		return (double)p.second / p.first > (double)q.second / q.first;
	});

	double ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].first < m) {
			m -= a[i].first;
			ans += a[i].second;
		}
		else {
			ans += m * (double)a[i].second / a[i].first;
			break;
		}
	}

	cout.precision(3);
	cout << fixed << ans << '\n';

}
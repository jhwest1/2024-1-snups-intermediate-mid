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

	sort(a.begin(), a.end(), [&](pair<int, int> p, pair<int, int> q) {
		return p.second < q.second;
	});

	int cnt = 0;
	int mx = -1;
	for (int i = 0; i < n; i++) {
		if (mx <= a[i].first) {
			mx = a[i].second;
			cnt++;
		}
	}

	cout << cnt << '\n';
	
}
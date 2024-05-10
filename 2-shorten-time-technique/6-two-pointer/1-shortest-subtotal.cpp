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

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int minv = 1e9;
	for (int i = 0, p = 0, s = 0; i < n; i++) {
		while (p < n && s < k) {
			s += a[p];
			++p;
		}
		if (s >= k) minv = min(minv, p - i);
		s -= a[i];
	}
	
	if (minv == 1e9) cout << -1 << '\n';
	else {
		cout << minv << '\n';
	}
}
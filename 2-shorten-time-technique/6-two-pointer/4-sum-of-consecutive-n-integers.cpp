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

	int ans = 0;
	for (int i = 0, p = 0, s = 0; i < n; i++) {
		while (p < n && s < k) {
			s += a[p];
			++p;
		}
		if (s == k) ++ans;

		s -= a[i];
	}
	cout << ans << '\n';
}
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int n, k;
	cin >> n >> k;

	vector<pll> a(k);
	for (int i = 0; i < k; i++) {
		cin >> a[i].ff >> a[i].ss;
	}
	sort(a.begin(), a.end());

	ll s = 0, e = 1e18;
	while (s < e) {
		ll x = (s + e + 1) / 2;

		ll cnt = 0;
		ll pos = -1e18;

		for (int i = 0; i < k; i++) {
			ll p = max(pos + x, a[i].ff);

			if (p <= a[i].ss) {
				cnt += 1 + (a[i].ss - p) / x;
				pos = p + (a[i].ss - p) / x * x;
			}
		}

		if (cnt >= n) s = x;
		else e = x - 1;
	}
	cout << s << '\n';
}
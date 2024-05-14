#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	ll n, k;
	cin >> n >> k;

	ll s = 0, e = n * n;
	while (s < e) {
		ll x = (s + e) / 2;

		ll cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += min(n, x / i);
		}
		if (cnt < k) {
			s = x + 1;
		}
		else {
			e = x;
		}
	}
	cout << s << '\n';

}
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	ll m, a, b;
	cin >> m >> a >> b;

	int mnv = 1e9, mxv = -1;

	for (ll x = a; x <= b; x++) {
		int cnt = 0;
		ll s = 1, e = m;
		while (true) {
			ll k = (s + e) / 2;
			++cnt;

			if (x == k) {
				break;
			}
			else if (x < k) {
				e = k - 1;
			}
			else {
				s = k + 1;
			}
		}

		if (mnv > cnt) {
			mnv = cnt;
		}
		if (mxv < cnt) {
			mxv = cnt;
		}
	}
	cout << mnv << ' ' << mxv << '\n';
}
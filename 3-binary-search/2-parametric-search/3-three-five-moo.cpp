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

	ll s = 0, e = 2e9;
	while (s < e) {
		ll x = (s + e) / 2;
		ll cnt = x - (x / 3) - (x / 5) + (x / 15);

		if (cnt < n) {
			s = x + 1;
		}
		else {
			e = x;
		}
	}
	cout << s << '\n';

}
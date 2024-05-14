#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	ll x;
	cin >> x;

	ll s = 0, e = 2e9;
	while (s < e) {
		ll n = (s + e + 1) / 2;

		if (n * (n + 1) / 2 <= x) {
			s = n;
		}
		else {
			e = n - 1;
		}
	}
	cout << s << '\n';
	
}
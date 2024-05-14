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

	vector<int> a(k);
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}

	ll s = 0, e = 1e15;
	while (s < e) {
		ll t = (s + e) / 2;

		ll cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += t / a[i];
		}
		
		if (cnt < n) {
			s = t + 1;
		}
		else {
			e = t;
		}
	}
	cout << s << '\n';

}
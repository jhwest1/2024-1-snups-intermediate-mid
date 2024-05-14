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

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int s = 0, e = 1e5;

	while (s < e) {
		int k = (s + e + 1) / 2;

		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += a[i] / k;
		}
		if (cnt >= m) {
			s = k;
		}
		else {
			e = k - 1;
		}
	}
	cout << s << '\n';

}
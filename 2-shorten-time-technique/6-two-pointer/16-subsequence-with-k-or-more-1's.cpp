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

	int ans = 1e9;
	int cnt = 0;

	for (int i = 0, p = 0; i < n; i++) {
		while (p < n && cnt < k) {
			if (a[p] == 1) {
				++cnt;
			}
			++p;			
		}
		if (cnt >= k) {
			ans = min(ans, p - i);
		}
		if (a[i] == 1) {
			--cnt;
		}
	}

	if (ans == 1e9) cout << -1 << '\n';
	else {
		cout << ans << '\n';
	}
}
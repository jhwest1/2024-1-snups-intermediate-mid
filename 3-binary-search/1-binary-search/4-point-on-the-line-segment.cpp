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
	sort(a.begin(), a.end());

	for (int i = 0; i < k; i++) {
		int l, r;
		cin >> l >> r;

		int ans = 0;
		{
			int s = 0, e = n;
			while (s < e) {
				int m = (s + e) / 2;

				if (a[m] < l) {
					s = m + 1;
				}
				else {
					e = m;
				}
			}
			ans -= s;
		}
		{
			int s = 0, e = n;
			while (s < e) {
				int m = (s + e) / 2;

				if (a[m] <= r) {
					s = m + 1;
				}
				else {
					e = m;
				}
			}
			ans += s;
		}
		cout << ans << '\n';
	}
}
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

	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;

		int cnt = 0;
		{
			int s = 0, e = n;
			while (s < e) {
				int m = (s + e) / 2;

				if (a[m] < x) {
					s = m + 1;
				}
				else {
					e = m;
				}
			}
			cnt -= s;
		}
		{
			int s = 0, e = n;
			while (s < e) {
				int m = (s + e) / 2;

				if (a[m] <= x) {
					s = m + 1;
				}
				else {
					e = m;
				}
			}
			cnt += s;
		}
		cout << cnt << '\n';
	}
}
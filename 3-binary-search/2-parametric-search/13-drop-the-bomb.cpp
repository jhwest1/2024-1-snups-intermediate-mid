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

	int s = 0, e = 5e8;
	while (s < e) {
		int m = (s + e) / 2;

		int cnt = 0;
		for (int i = 0, p = 0; i < n; i = p) {
			while (p < n && a[p] - a[i] <= 2 * m) {
				++p;
			}
			++cnt;
		}

		if (cnt <= k) e = m;
		else s = m + 1;
	}
	cout << s << '\n';
	
}
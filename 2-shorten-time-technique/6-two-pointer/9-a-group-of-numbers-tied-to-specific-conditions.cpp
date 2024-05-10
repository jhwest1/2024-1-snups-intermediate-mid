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

	vector<int> pre(n + 1), suf(n + 1);

	for (int i = 0, p = 0; i < n; i++) {
		while (p < n && a[p] - a[i] <= k) {
			++p;
		}
		suf[i + 1] = p - i;
	}
	for (int i = n - 1, p = n - 1; i >= 0; i--) {
		while (p >= 0 && a[i] - a[p] <= k) {
			--p;
		}
		pre[i + 1] = i - p;
	}

	for (int i = 1; i <= n; i++) pre[i] = max(pre[i], pre[i - 1]);
	for (int i = n; i >= 1; i--) suf[i - 1] = max(suf[i - 1], suf[i]);

	int ans = 0;
	for (int i = 0; i <= n; i++) {
		ans = max(ans, pre[i] + suf[i + 1]);
	}

	cout << ans << '\n';
}
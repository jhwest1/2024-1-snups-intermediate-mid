#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 101010;

int n, pre[SZ], suf[SZ];
pair<int, int> a[SZ];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a + 1, a + 1 + n);

	pre[0] = -1e9;
	for (int i = 1; i <= n; i++) {
		pre[i] = max(pre[i - 1], a[i].second);
	}

	suf[n + 1] = 1e9;
	for (int i = n; i >= 1; i--) {
		suf[i] = min(suf[i + 1], a[i].second);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (pre[i - 1] < a[i].second && a[i].second < suf[i + 1]) {
			++ans;
		}
	}
	cout << ans << '\n';

}
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 101010;

int n, a[SZ], pre[SZ], suf[SZ];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n;

	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % 4 != 0) {
		return !(cout << 0 << '\n');
	}

	long long cur = 0;
	for (int i = 1; i <= n; i++) {
		cur += a[i];
		if (cur == sum / 4) {
			pre[i]++;
		}
	}
	for (int i = 1; i <= n; i++) pre[i] += pre[i - 1];

	cur = 0;
	for (int i = n; i >= 1; i--) {
		cur += a[i];
		if (cur == sum / 4) {
			suf[i]++;
		}
	}
	for (int i = n; i >= 1; i--) suf[i] += suf[i + 1];

	long long ans = 0;

	cur = 0;
	for (int i = 1; i <= n; i++) {
		cur += a[i];
		if (cur == sum / 2) {
			ans += (long long)pre[i - 1] * suf[i + 2];
		}
	}
	cout << ans << '\n';
}
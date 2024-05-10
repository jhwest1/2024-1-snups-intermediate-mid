#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 101010;

int n, q, a[SZ], pre[SZ], suf[SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}	

	pre[0] = -1e9;
	for (int i = 1; i <= n; i++) {
		pre[i] = max(pre[i - 1], a[i]);
	}

	suf[n + 1] = -1e9;
	for (int i = n; i >= 1; i--) {
		suf[i] = max(suf[i + 1], a[i]);
	}

	while (q--) {
		int l, r;
		cin >> l >> r;

		cout << max(pre[l - 1], suf[r + 1]) << '\n';
	}
}
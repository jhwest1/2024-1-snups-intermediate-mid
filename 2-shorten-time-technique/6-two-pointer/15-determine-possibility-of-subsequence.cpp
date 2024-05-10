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

	vector<int> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	vector<int> pre(m + 2), suf(m + 2);

	pre[0] = -1;
	suf[m + 1] = n;

	for (int i = 0, p = 0; i < m; i++) {
		while (p < n && a[p] != b[i]) {
			++p;
		}
		pre[i + 1] = p;
		++p;
	}

	for (int i = m - 1, p = n - 1; i >= 0; i--) {
		while (p >= 0 && a[p] != b[i]) {
			--p;
		}
		suf[i + 1] = p;
		--p;
	}

	int ans = 0;
	for (int i = 1; i <= m; i++) {
		if (pre[i - 1] < suf[i + 1]) {
			++ans;
		}
	}
	cout << ans << '\n';
}
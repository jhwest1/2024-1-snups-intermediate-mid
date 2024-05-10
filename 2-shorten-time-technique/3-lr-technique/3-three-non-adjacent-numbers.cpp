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
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		pre[i] = max(pre[i - 1], a[i]);
	}
	for (int i = n; i >= 1; i--) {
		suf[i] = max(suf[i + 1], a[i]);
	}

	int ans = 0;
	for (int i = 3; i <= n - 2; i++) {
		ans = max(ans, a[i] + pre[i - 2] + suf[i + 2]);
	}
	cout << ans << '\n';
	
}
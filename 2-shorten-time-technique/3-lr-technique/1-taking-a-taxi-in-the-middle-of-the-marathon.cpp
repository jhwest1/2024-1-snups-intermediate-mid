#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 101010;

int n, x[SZ], y[SZ], pre[SZ], suf[SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 2; i <= n; i++) {
		pre[i] = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
	}
	for (int i = n - 1; i >= 1; i--) {
		suf[i] = abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]);
	}

	for (int i = 1; i <= n; i++) pre[i] += pre[i - 1];
	for (int i = n; i >= 1; i--) suf[i] += suf[i + 1];

	int minv = 2e9;
	for (int i = 2; i < n; i++) {
		minv = min(minv, pre[i - 1] + suf[i + 1] + abs(x[i - 1] - x[i + 1]) + abs(y[i - 1] - y[i + 1]));
	}
	cout << minv << '\n';
}
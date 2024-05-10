#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	int minv = 2e9;
	for (int i = 0, p = n - 1; i < n; i++) {
		while (p >= 0 && a[i] + a[p] >= 0) {
			--p;
		}
		if (i < p && p < n) minv = min(minv, abs(a[i] + a[p]));
		if (i < p + 1 && p + 1 < n) minv = min(minv, abs(a[i] + a[p + 1]));
		if (i != n - 1) minv = min(minv, abs(a[i] + a[i + 1]));
	}

	cout << minv << '\n';
}
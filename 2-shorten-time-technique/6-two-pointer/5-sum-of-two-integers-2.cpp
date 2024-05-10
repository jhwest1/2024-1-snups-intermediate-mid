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

	long long ans = 0;
	for (int i = 0, p = n - 1; i < n; i++) {
		while (p >= 0 && a[i] + a[p] > k) {
			--p;
		}
		ans += max(0, p - i);
	}
	cout << ans << '\n';

}
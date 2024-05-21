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

	int ans = 0;
	int mn = a[0];
	for (int i = 1; i < n; i++) {
		ans = max(ans, a[i] - mn);
		mn = min(mn, a[i]);
	}

	cout << ans << '\n';
}
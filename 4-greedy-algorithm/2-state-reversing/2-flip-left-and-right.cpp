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

	vector<int> a(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (!a[i]) {
			a[i] ^= 1;
			a[i + 1] ^= 1;
			a[i + 2] ^= 1;
			++ans;
		}
	}

	if (a[n - 1]) {
		cout << ans << '\n';
	}
	else {
		cout << -1 << '\n';
	}
}
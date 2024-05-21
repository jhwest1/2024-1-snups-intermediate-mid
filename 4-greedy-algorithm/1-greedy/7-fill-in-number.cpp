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

	int ans = 1e9;
	for (int i = 0; 2 * i <= n; i++) {
		if ((n - 2 * i) % 5 == 0) {
			ans = min(ans, i + (n - 2 * i) / 5);
		}
	}

	if (ans == 1e9) {
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
	}
}
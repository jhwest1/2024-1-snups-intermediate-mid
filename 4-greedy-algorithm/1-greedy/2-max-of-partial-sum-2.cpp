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

	int ans = -1e9;
	for (int i = 0, p = 0; i < n; i = p) {
		int s = 0;
		while (p < n && s >= 0) {
			s += a[p++];
			ans = max(ans, s);
		}
	}
	cout << ans << '\n';

}
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

	map<int, int> mp;
	int ans = 0;

	for (int i = 0, p = 0; i < n; i++) {
		while (p < n && mp[a[p]] + 1 <= k) {
			mp[a[p]]++;
			++p;
		}
		ans = max(ans, p - i);
		mp[a[i]]--;
	}

	cout << ans << '\n';

}
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

	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		mp[x]++;
		mp[y]--;
	}

	int ans = 0;
	int cur = 0;
	for (auto [x, k] : mp) {
		if (cur == 0) {
			++ans;
		}
		cur += k;
	}
	cout << ans << '\n';
}
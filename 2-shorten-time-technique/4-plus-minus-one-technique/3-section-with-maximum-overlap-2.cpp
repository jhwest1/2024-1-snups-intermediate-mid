#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 101010;

int n, x[SZ], y[SZ], a[2 * SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	// solution using grid compression
	
	if (false) {
		cin >> n;

		vector<int> vec;
		for (int i = 1; i <= n; i++) {
			cin >> x[i] >> y[i];

			vec.push_back(x[i]);
			vec.push_back(y[i]);
		}
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());

		for (int i = 1; i <= n; i++) {
			int posx = lower_bound(vec.begin(), vec.end(), x[i]) - vec.begin() + 1;
			int posy = lower_bound(vec.begin(), vec.end(), y[i]) - vec.begin() + 1;

			a[posx]++;
			a[posy]--;
		}

		for (int i = 1; i <= vec.size(); i++) a[i] += a[i - 1];

		cout << *max_element(a, a + 2 * SZ) << '\n';
	}

	// solution using std::map

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
		cur += k;
		ans = max(ans, cur);
	}
	cout << ans << '\n';
}
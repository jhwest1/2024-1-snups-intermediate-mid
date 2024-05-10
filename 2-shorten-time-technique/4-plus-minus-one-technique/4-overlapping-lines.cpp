#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 101010;

int n, k, a[SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> n >> k;

	int pos = 0;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		string S; cin >> S;

		if (S == "L") pos -= x;
		else pos += x;

		a[i] = pos;
	}

	map<int, int> mp;
	for (int i = 1; i <= n; i++) {
		int s = a[i - 1];
		int e = a[i];
		if (s > e) swap(s, e);

		mp[s]++;
		mp[e]--;
	}

	int prv = -1;
	int ans = 0;
	int cur = 0;

	for (auto [x, t] : mp) {
		if (cur >= k) {
			ans += x - prv;
		}
		cur += t;
		prv = x;
	}
	cout << ans << '\n';
}
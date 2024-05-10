#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 101010;

int n, a[SZ], pre[3][SZ], suf[3][SZ];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n;

	string S;
	cin >> S;

	map<char, int> mp;
	mp['C'] = 0;
	mp['O'] = 1;
	mp['W'] = 2;

	for (int i = 1; i <= n; i++) {
		a[i] = mp[S[i - 1]];

		pre[a[i]][i]++;
		suf[a[i]][i]++;
	}
	for (int t = 0; t < 3; t++) {
		for (int i = 1; i <= n; i++) pre[t][i] += pre[t][i - 1];
		for (int i = n; i >= 1; i--) suf[t][i] += suf[t][i + 1];
	}

	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			ans += (long long)pre[0][i - 1] * suf[2][i + 1];
		}
	}
	cout << ans << '\n';
}
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 101010;

int n, pre[3][SZ], suf[3][SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> n;

	map<char, int> mp;
	mp['R'] = 0;
	mp['P'] = 1;
	mp['S'] = 2;

	for (int i = 1; i <= n; i++) {
		string S; cin >> S;
		int k = mp[S[0]];

		pre[k][i]++;
		suf[k][i]++;
	}

	for (int t = 0; t < 3; t++) {
		for (int i = 1; i <= n; i++) pre[t][i] += pre[t][i - 1];
		for (int i = n; i >= 1; i--) suf[t][i] += suf[t][i + 1];
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int s = 0; s < 3; s++) {
			for (int t = 0; t < 3; t++) {
				ans = max(ans, pre[s][i - 1] + suf[t][i]);
			}
		}
	}
	cout << ans << '\n';
	
}
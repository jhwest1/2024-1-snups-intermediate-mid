#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int cnt[26];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	string S;
	cin >> S;

	int n, k;
	n = S.size();
	cin >> k;
	
	int ans = 0;
	int diff = 0;
	for (int i = 0, p = 0; i < n; i++) {
		while (p < n && diff + !cnt[S[p] - 'a'] <= k) {
			if (cnt[S[p] - 'a'] == 0) {
				++diff;
			}
			cnt[S[p] - 'a']++;
			++p;
		}
		ans = max(ans, p - i);

		--cnt[S[i] - 'a'];
		if (cnt[S[i] - 'a'] == 0) {
			--diff;
		}
	}
	cout << ans << '\n';

}
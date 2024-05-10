#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	string S;
	cin >> S;

	int n = S.size();

	vector<int> cnt(n);
	for (int i = 1; i < n; i++) {
		if (S[i] == '(' && S[i - 1] == '(') {
			cnt[i]++;
		}
	}
	for (int i = 1; i < n; i++) cnt[i] += cnt[i - 1];

	long long ans = 0;
	for (int i = 1; i < n; i++) {
		if (S[i] == ')' && S[i - 1] == ')') {
			ans += cnt[i];
		}
	}
	cout << ans << '\n';
}
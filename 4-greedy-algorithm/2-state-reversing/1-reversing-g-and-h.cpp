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

	string S, T;
	cin >> S >> T;

	vector<int> a(n + 1);
	for (int i = 0; i < n; i++) {
		a[i] = (S[i] != T[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] && !a[i + 1]) {
			++ans;
		}
	}
	cout << ans << '\n';
}
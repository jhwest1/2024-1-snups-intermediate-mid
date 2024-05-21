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

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = (S[i] != T[i]);
	}

	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i]) {
			for (int j = 0; j <= i; j++) {
				a[j] ^= 1;
			}
			++ans;
		}
	}

	cout << ans << '\n';
	
}
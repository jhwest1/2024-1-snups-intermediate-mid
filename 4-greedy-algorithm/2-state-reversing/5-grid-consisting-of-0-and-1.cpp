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

	vector<vector<int>> a(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		string S;
		cin >> S;

		for (int j = 0; j < n; j++) {
			a[i][j] = (S[j] - '0');
		}
	}

	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (a[i][j]) {
				for (int k = 0; k <= i; k++) {
					for (int l = 0; l <= j; l++) {
						a[k][l] ^= 1;
					}
				}
				++ans;
			}
		}
	}

	cout << ans << '\n';
}
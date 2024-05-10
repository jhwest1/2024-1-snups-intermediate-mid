#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 1010;

int n, m, k, a[3][SZ][SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		string S;
		cin >> S;

		for (int j = 1; j <= m; j++) {
			a[S[j - 1] - 'a'][i][j]++;
		}
	}
	for (int t = 0; t < 3; t++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				a[t][i][j] += a[t][i - 1][j] + a[t][i][j - 1] - a[t][i - 1][j - 1];
			}
		}
	}

	while (k--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		for (int t = 0; t < 3; t++) {
			cout << a[t][r2][c2] - a[t][r1 - 1][c2] - a[t][r2][c1 - 1] + a[t][r1 - 1][c1 - 1] << ' ';
		}
		cout << '\n';
	}
}
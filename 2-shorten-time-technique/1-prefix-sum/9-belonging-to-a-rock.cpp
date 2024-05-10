#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 101010;

int n, q, a[3][SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		a[x - 1][i]++;
	}
	for (int t = 0; t < 3; t++) {
		for (int i = 1; i <= n; i++) {
			a[t][i] += a[t][i - 1];
		}
	}

	while (q--) {
		int l, r;
		cin >> l >> r;

		for (int t = 0; t < 3; t++) {
			cout << a[t][r] - a[t][l - 1] << ' ';
		}
		cout << '\n';
	}
}
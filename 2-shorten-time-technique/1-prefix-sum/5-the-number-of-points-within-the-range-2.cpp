#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 1010101;

int n, q, a[SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a[x + 1]++;
	}
	for (int i = 1; i < SZ; i++) {
		a[i] += a[i - 1];
	}

	while (q--) {
		int l, r;
		cin >> l >> r;

		cout << a[r + 1] - a[l] << '\n';
	}
}
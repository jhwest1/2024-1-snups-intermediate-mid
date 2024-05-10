#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int pos[1010101];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;

	int maxv = -1;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;

		if (pos[x] && pos[x] >= i - k) {
			maxv = max(maxv, x);
		}
		pos[x] = i;
	}

	cout << maxv << '\n';
}
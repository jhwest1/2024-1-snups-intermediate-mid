#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 404;

int n, k, a[SZ][SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			a[i][j] += a[i][j - 1];
		}
	}

	int maxv = 0;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			int sum = 0;
			for (int i = max(1, x - k); i <= min(n, x + k); i++) {
				sum += a[i][min(n, y + k - abs(x - i))] - a[i][max(1, y - k + abs(x - i)) - 1];
			}
			maxv = max(maxv, sum);
		}
	}
	cout << maxv << '\n';
}
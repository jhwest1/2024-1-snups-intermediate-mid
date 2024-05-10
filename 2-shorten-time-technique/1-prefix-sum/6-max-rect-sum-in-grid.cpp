#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 303;

int n, a[SZ][SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			a[i][j] += a[i][j - 1];
		}
	}

	int maxv = a[1][1];
	for (int e = 1; e <= n; e++) {
		for (int s = 0; s < e; s++) {
			int cur = 0;
			for (int i = 1; i <= n; i++) {
				maxv = max(maxv, cur + a[i][e] - a[i][s]);
				cur = max(0, cur + a[i][e] - a[i][s]);
			}
		}
	}
	cout << maxv << '\n';
}
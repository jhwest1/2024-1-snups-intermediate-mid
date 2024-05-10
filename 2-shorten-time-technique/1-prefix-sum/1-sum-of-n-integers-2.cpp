#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 101010;

int n, k, a[SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		a[i] += a[i - 1];
	}

	int maxv = a[k];
	for (int i = k; i <= n; i++) {
		maxv = max(maxv, a[i] - a[i - k]);
	}
	cout << maxv << '\n';
}
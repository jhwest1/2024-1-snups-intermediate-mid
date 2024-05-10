#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 101010;

int n, k, b, a[SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> n >> k >> b;
	for (int i = 1; i <= b; i++) {
		int x; cin >> x;
		a[x]++;
	}
	for (int i = 1; i <= n; i++) {
		a[i] += a[i - 1];
	}

	int minv = a[k];
	for (int i = k; i <= n; i++) {
		minv = min(minv, a[i] - a[i - k]);
	}
	cout << minv << '\n';
}
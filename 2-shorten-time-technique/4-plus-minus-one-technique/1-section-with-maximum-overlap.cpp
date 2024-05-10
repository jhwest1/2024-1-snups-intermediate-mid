#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 202020;

int n, a[SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		a[x]++;
		a[y]--;
	}
	for (int i = 1; i < SZ; i++) a[i] += a[i - 1];

	cout << *max_element(a, a + SZ) << '\n';
}
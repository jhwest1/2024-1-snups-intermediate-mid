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

	vector<int> a(n - 1);
	vector<int> b(n);

	for (int i = 0; i < n - 1; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	long long ans = 0;

	int minv = b[0];
	for (int i = 0; i < n - 1; i++) {
		ans += (long long)a[i] * minv;
		minv = min(minv, b[i + 1]);
	}

	cout << ans << '\n';
}
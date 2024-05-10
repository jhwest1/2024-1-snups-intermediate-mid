#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	bool ans = true;
	for (int i = 0, p = 0; i < m; i++) {
		while (p < n && a[p] != b[i]) {
			++p;
		}
		if (p == n) {
			ans = false;
			break;
		}
		++p;
	}

	cout << (ans ? "Yes\n" : "No\n");
}
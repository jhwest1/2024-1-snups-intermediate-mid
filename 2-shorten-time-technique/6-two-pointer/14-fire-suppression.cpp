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
	sort(a.begin(), a.end());

	vector<int> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(b.begin(), b.end());
	
	vector<int> t(n, 1e9);
	for (int i = 0, p = 0; i < n; i++) {
		while (p < m && b[p] < a[i]) {
			++p;
		}
		if (p < m) t[i] = min(t[i], b[p] - a[i]);
	}
	for (int i = n - 1, p = m - 1; i >= 0; i--) {
		while (p >= 0 && b[p] > a[i]) {
			--p;
		}
		if (p >= 0) t[i] = min(t[i], a[i] - b[p]);
	}

	cout << *max_element(t.begin(), t.end()) << '\n';
}
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int n, b, c;
	cin >> n >> b >> c;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	int s = 0, e = 1e9;
	while (s < e) {
		int m = (s + e) / 2;

		int cnt = 0;
		for (int i = 0, p = 0; i < n; i = p) {
			while (p < min(n, i + c) && a[p] - a[i] <= m) {
				++p;
			}
			++cnt;
		}
		
		if (cnt <= b) e = m;
		else s = m + 1;
	}
	cout << s << '\n';
	
}
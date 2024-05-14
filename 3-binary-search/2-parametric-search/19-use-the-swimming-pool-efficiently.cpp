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

	int s = *max_element(a.begin(), a.end()), e = 1e9;
	while (s < e) {
		int k = (s + e) / 2;

		int cnt = 0;
		for (int i = 0, p = 0; i < n; i = p) {
			int s = 0;
			while (p < n && s + a[p] <= k) {
				s += a[p++];
			}
			++cnt;
		}

		if (cnt <= m) e = k;
		else s = k + 1;
	}
	cout << s << '\n';

}
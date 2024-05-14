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

	vector<pii> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].ff >> a[i].ss;
	}
	sort(a.begin(), a.end());

	int s = 0, e = 1e9;
	while (s < e) {
		int x = (s + e + 1) / 2;

		int pos = -1e9;

		bool flag = true;
		for (int i = 0; i < n; i++) {
			int k = max(a[i].ff, pos + x);
			if (k <= a[i].ss) {
				pos = k;
			}
			else {
				flag = false;
				break;
			}
		}

		if (flag) s = x;
		else e = x - 1;
	}
	cout << s << '\n';
	
}
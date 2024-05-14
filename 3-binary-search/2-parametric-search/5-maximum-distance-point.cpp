#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	int s = 0, e = 1e9;
	while (s < e) {
		int x = (s + e + 1) / 2;

		int cnt = 0, pos = -1e9;
		for (int i = 0; i < n; i++) {
			if (a[i] - pos >= x) {
				cnt++;
				pos = a[i];
			}
		}

		if (cnt < k) {
			e = x - 1;
		}
		else {
			s = x;
		}
	}
	cout << s << '\n';
}
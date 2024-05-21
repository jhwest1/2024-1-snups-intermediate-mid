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

	vector<int> chk(2 * n);
	for (int i = 0; i < n; i++) {
		int x; 
		cin >> x;

		chk[x - 1] = true;
	}

	vector<int> a, b;
	for (int i = 0; i < 2 * n; i++) {
		if (chk[i]) b.push_back(i);
		else a.push_back(i);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());


	int s = 0, e = n;
	while (s < e) { 
		int m = (s + e + 1) / 2;

		bool flag = true;
		for (int i = 0; i < m; i++) {
			if (a[n - m + i] < b[i]) {
				flag = false;
			}
		}

		if (flag) {
			s = m;
		}
		else {
			e = m - 1;
		}
	}

	cout << s << '\n';
}
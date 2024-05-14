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

	vector<int> x(n), v(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	double s = 0, e = 1e9;
	while (e - s > 1e-9) {
		double t = (s + e) / 2;

		double L = -1e18;
		double R = 1e18;

		for (int i = 0; i < n; i++) {
			L = max(L, x[i] - v[i] * t);
			R = min(R, x[i] + v[i] * t);
		}

		if (L < R - 1e-9) {
			e = t;
		}
		else {
			s = t;
		}
	}
	cout.precision(4);
	cout << fixed << s << '\n';
}
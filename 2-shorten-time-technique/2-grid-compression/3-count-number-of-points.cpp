#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SZ = 101010;

int n, q, x[SZ], a[SZ];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> q;

	vector<int> vec;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		vec.push_back(x[i]);		
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int i = 0; i < n; i++) {
		int pos = lower_bound(vec.begin(), vec.end(), x[i]) - vec.begin() + 1;
		a[pos]++;
	}
	for (int i = 1; i <= n; i++) {
		a[i] += a[i - 1];
	}

	while (q--) {
		int l, r;
		cin >> l >> r;

		r = upper_bound(vec.begin(), vec.end(), r) - vec.begin();
		l = lower_bound(vec.begin(), vec.end(), l) - vec.begin();

		cout << a[r] - a[l] << '\n';
	}
}
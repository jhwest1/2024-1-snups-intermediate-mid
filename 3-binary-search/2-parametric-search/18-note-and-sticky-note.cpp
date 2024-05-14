#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int N, K, L;
	cin >> N >> K >> L;

	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());

	int s = 0, e = N;
	while (s < e) {
		int h = (s + e + 1) / 2;

		ll sum = 0;
		for (int i = 0; i < h; i++) {
			sum += max(0, h - a[i]);
		}

		if (sum <= (ll)K * L && h - a[h - 1] <= K) {
			s = h;
		}
		else {
			e = h - 1;
		}
	}
	cout << s << '\n';
}
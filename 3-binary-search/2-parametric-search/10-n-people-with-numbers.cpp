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

	int s = 0, e = n;
	while (s < e) {
		int k = (s + e) / 2;

		priority_queue<int> pq;
		for (int i = 0; i < k; i++) {
			pq.push(-a[i]);
		}

		for (int i = k; i < n; i++) {
			int cur = -pq.top();
			pq.pop();

			pq.push(-cur - a[i]);
		}

		int mx = 0;
		while (!pq.empty()) {
			mx = max(mx, -pq.top());
			pq.pop();
		}

		if (mx <= m) e = k;
		else s = k + 1;
	}
	cout << s << '\n';
	
}
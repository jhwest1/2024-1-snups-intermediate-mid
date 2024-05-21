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

	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		pq.push(-x);
	}

	long long ans = 0;
	while (pq.size() >= 2) {
		int x = -pq.top(); pq.pop();
		int y = -pq.top(); pq.pop();

		ans += x + y;
		pq.push(-x - y);
	}
	cout << ans << '\n';
	
}
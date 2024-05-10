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

	vector<pair<int, int>> vec;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;

		vec.push_back({x, -i});
		vec.push_back({y, i});
	}
	sort(vec.begin(), vec.end());

	priority_queue<int> pq;
	for (int i = 1; i <= n; i++) {
		pq.push(-i);
	}
	
	vector<int> ans(n + 1);

	for (auto [x, k] : vec) {
		if (k < 0) {
			ans[-k] = -pq.top();
			pq.pop();
		}
		else {
			pq.push(-ans[k]);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}
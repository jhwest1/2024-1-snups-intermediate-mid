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

	vector<int> y(n + 1);
	vector<pair<int, int>> vec;

	for (int i = 1; i <= n; i++) {
		cin >> y[i];

		int s, e;
		cin >> s >> e;
		if (s > e) {
			swap(s, e);
		}

		vec.push_back({s, -i});
		vec.push_back({e, i});
	}
	sort(vec.begin(), vec.end());

	unordered_set<int> seen;
	set<pair<int, int>> cur;

	for (auto [x, k] : vec) {
		if (k < 0) {
			cur.insert({y[-k], -k});
		}
		else {
			cur.erase({y[k], k});
		}

		if (!cur.empty()) {
			seen.insert(cur.begin()->second);
		}
	}
	cout << seen.size() << '\n';
}
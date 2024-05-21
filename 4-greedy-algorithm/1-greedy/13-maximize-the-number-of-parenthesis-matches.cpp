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

	long long ans = 0;
	vector<pair<int, int>> a(n);

	for (int i = 0; i < n; i++) {
		string S;
		cin >> S;

		int o = 0, c = 0;
		for (int j = 0; j < S.size(); j++) {
			if (S[j] == '(') {
				++o;
			}
			else {
				ans += o;
				++c;
			}
		}
		a[i] = {o, c};
	}
	
	sort(a.begin(), a.end(), [&](pair<int, int> p, pair<int, int> q) {
		return p.first * q.second > p.second * q.first;
	});

	int o = 0;
	for (int i = 0; i < n; i++) {
		ans += (long long)o * a[i].second;
		o += a[i].first;
	}

	cout << ans << '\n';

}
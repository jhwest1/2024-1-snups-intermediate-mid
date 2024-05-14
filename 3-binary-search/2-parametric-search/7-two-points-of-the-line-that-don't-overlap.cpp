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

	vector<pair<ll, ll>> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());

	
}
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int cnt[101010];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int maxv = 0;
	for (int i = 0, p = 0; i < n; i++) {
		while (p < n && !cnt[a[p]]) {
			cnt[a[p]]++;
			++p;
		}
		maxv = max(maxv, p - i);

		--cnt[a[i]];
	}
	cout << maxv << '\n';

}
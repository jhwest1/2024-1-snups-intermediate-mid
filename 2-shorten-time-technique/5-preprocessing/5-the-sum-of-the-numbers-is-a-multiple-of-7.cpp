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

	int pos[7] = {};
	for (int i = 0; i < 7; i++) {
		pos[i] = -1;
	}
	pos[0] = 0;

	int cur = 0;
	int maxv = 0;

	for (int i = 1; i <= n; i++) {
		int x; cin >> x;

		cur = (cur + x) % 7;
		if (pos[cur] != -1) {
			maxv = max(maxv, i - pos[cur]);
		}
		else {
			pos[cur] = i;
		}
	}

	cout << maxv << '\n';
}
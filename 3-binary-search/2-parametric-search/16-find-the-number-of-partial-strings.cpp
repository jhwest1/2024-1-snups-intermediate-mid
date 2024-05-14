#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	string S, T;
	cin >> S >> T;

	int n = S.size();
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int s = 0, e = n;
	while (s < e) {
		int t = (s + e + 1) / 2;

		vector<int> chk(n);
		for (int i = t - 1; i < n; i++) {
			chk[a[i] - 1] = true;
		}

		string P;
		for (int i = 0; i < n; i++) {
			if (chk[i]) P += S[i];
		}

		bool flag = true;
		for (int i = 0, p = 0; i < T.size(); i++) {
			while (p < P.size() && T[i] != P[p]) {
				++p;
			}
			if (p == P.size()) {
				flag = false;
				break;
			}
			++p;
		}
		if (!flag) e = t - 1;
		else s = t;
	}
	cout << s << '\n';
}
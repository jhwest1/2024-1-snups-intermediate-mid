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

	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end(), [&](string S, string T) {
		return S + T > T + S;
	});

	for (int i = 0; i < n; i++) {
		cout << a[i];
	}
	cout << '\n';
	
}
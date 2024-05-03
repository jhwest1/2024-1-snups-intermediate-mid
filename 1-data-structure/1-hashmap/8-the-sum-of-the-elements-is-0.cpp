#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;

    vector<int> a(n), b(n), c(n), d(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) cin >> d[i];

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mp[a[i] + b[j]]++;
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += mp[-c[i] - d[j]];
        }
    }

    cout << ans << '\n';
}
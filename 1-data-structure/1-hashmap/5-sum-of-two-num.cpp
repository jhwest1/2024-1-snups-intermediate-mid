#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; long long k;
    cin >> n >> k;

    map<long long, int> mp;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (k - a[i] == a[i]) {
            ans += mp[a[i]] - 1;
        }
        else if (mp.find(k - a[i]) != mp.end()) {
            ans += mp[k - a[i]];
        }
    }
    cout << ans / 2 << '\n';
}
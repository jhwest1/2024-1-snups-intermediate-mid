#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if (mp.find(x) == mp.end() || mp[x] > y) {
            mp[x] = y;
        }
    }

    long long ans = 0;
    for (auto [k, v] : mp) {
        ans += v;
    }
    cout << ans << '\n';
}
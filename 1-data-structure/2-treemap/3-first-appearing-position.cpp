#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;

    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;

        if (mp.find(x) == mp.end()) {
            mp[x] = i;
        }
    }

    for (auto [k, v] : mp) {
        cout << k << ' ' << v << '\n';
    }
}
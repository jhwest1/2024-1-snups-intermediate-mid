#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }

    while (q--) {
        int x; cin >> x;
        cout << mp[x] << ' ';
    }
    cout << '\n';
}
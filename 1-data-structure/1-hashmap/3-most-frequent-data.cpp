#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;

    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string S; cin >> S;
        mp[S]++;
    }

    int maxv = 0;
    for (auto &[k, v] : mp) {
        maxv = max(maxv, v);
    }

    cout << maxv << '\n';
}
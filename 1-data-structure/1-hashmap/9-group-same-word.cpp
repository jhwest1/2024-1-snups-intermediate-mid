#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;

    unordered_map<string, int> mp;

    for (int i = 0; i < n; i++) {
        string S;
        cin >> S;

        sort(S.begin(), S.end());
        mp[S]++;
    }

    int maxv = 0;
    for (auto &[S, x] : mp) {
        maxv = max(maxv, x);
    }
    cout << maxv << '\n';
    
}
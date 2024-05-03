#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }

    vector<pair<int, int>> vec;
    for (auto [k, v] : mp) {
        vec.push_back({v, k});
    }

    sort(vec.begin(), vec.end());
    for (int i = vec.size(); i > vec.size() - k; i--) {
        cout << vec[i - 1].second << ' ';
    }
    cout << '\n';

}
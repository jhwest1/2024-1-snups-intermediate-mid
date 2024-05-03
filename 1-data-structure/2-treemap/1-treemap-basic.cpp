#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int q; cin >> q;

    map<int, int> mp;
    while (q--) {
        string S; cin >> S;
        if (S == "add") {
            int k, v;
            cin >> k >> v;
            mp[k] = v;
        }
        else if (S == "remove") {
            int k;
            cin >> k;
            mp.erase(k);
        }
        else if (S == "find") {
            int k;
            cin >> k;

            if (mp.find(k) == mp.end()) {
                cout << "None\n";
            }
            else cout << mp[k] << '\n';
        }
        else {
            if (mp.empty()) {
                cout << "None\n";
            }
            else {
                for (auto [k, v] : mp) {
                    cout << v << ' ';
                }
                cout << '\n';
            }
        }
    }
}
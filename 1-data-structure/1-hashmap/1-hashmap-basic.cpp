#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        string S;
        cin >> S;

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
            else {
                cout << mp[k] << '\n';
            }

        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    string S; cin >> S;

    map<char, int> mp;
    for (int i = 0; i < S.size(); i++) {
        mp[S[i]]++;
    }

    char ans = -1;
    for (int i = 0; i < S.size(); i++) {
        if (mp[S[i]] == 1) {
            ans = S[i];
            break;
        }
    }

    if (ans == -1) {
        cout << "None\n";
    }
    else {
        cout << ans << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    vector<string> a(n);
    map<string, int> b;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]] = i;
    }
    for (int i = 0; i < q; i++) {
        string S; cin >> S;
        
        if ('0' <= S[0] && S[0] <= '9') {
            cout << a[stoi(S.c_str()) - 1] << '\n';
        }
        else {
            cout << b[S] + 1 << '\n';
        }
    }
}
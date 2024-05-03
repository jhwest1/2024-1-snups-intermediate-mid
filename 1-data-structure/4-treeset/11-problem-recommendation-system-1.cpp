#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;

    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        int p, l;
        cin >> p >> l;

        st.insert({l, p});
    }

    int m; cin >> m;

    for (int i = 0; i < m; i++) {
        string S; cin >> S;
        if (S == "ad") {
            int p, l;
            cin >> p >> l;

            st.insert({l, p});
        }
        else if (S == "sv") {
            int p, l;
            cin >> p >> l;

            st.erase({l, p});
        }
        else {
            int x;
            cin >> x;

            if (x == 1) {
                cout << st.rbegin()->second << '\n';
            }
            else {
                cout << st.begin()->second << '\n';
            }
        }
    }
}
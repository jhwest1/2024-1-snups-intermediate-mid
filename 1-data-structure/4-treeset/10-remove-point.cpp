#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        st.insert({x, y});
    }

    for (int i = 0; i < m; i++) {
        int k; cin >> k;

        auto it = st.lower_bound({k, 0});
        if (it == st.end()) {
            cout << "-1 -1\n";
        }
        else {
            cout << it->first << ' ' << it->second << '\n';
            st.erase(it);
        }
    }
}
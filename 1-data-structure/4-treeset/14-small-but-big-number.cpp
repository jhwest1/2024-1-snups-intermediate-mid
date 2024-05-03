#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    set<int> st;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        st.insert(x);
    }

    for (int i = 0; i < m; i++) {
        int x; cin >> x;

        auto it = st.upper_bound(x);
        if (it != st.begin()) {
            int k = *prev(it);
            st.erase(k);

            cout << k << '\n';
        }
        else {
            cout << "-1\n";
        }
    }
}
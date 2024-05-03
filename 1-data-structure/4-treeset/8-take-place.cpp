#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    set<int> st;
    for (int i = 1; i <= m; i++) {
        st.insert(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;

        auto it = st.upper_bound(x);
        if (it != st.begin()) {
            st.erase(prev(it));
            ++ans;
        }
        else break;
    }
    cout << ans << '\n';
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    int ans = 2e9 + 10;
    for (int i = 0; i < n; i++) {
        auto it = st.lower_bound(a[i] + m);
        if (it != st.end()) {
            ans = min(ans, *it - a[i]);
        }
    }

    if (ans > 2e9) {
        cout << "-1\n";
    }
    else {
        cout << ans << '\n';
    }
}
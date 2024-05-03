#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    unordered_set<int> st_a, st_b;
    for (int i = 0; i < n; i++) {
        st_a.insert(a[i]);
    }
    for (int i = 0; i < m; i++) {
        st_b.insert(b[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (st_b.find(a[i]) == st_b.end()) {
            ++ans;
        }
    }
    for (int i = 0; i < m; i++) {
        if (st_a.find(b[i]) == st_a.end()) {
            ++ans;
        }
    }

    cout << ans << '\n';
}
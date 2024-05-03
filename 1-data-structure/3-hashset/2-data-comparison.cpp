#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m;

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    for (int i = 0; i < m; i++) {
        cout << (st.find(b[i]) == st.end() ? 0 : 1) << ' ';
    }
    cout << '\n';
}
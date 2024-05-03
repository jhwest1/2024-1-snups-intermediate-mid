#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;

    set<int> st;
    st.insert(0);

    int minv = 1e9;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;

        auto it = st.insert(x).first;
        if (it != prev(st.end())) {
            minv = min(minv, *next(it) - *it);
        }
        if (it != st.begin()) {
            minv = min(minv, *it - *prev(it));
        }

        cout << minv << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    set<int> st;
    st.insert(-1);
    st.insert(n + 1);

    set<pair<int, int>> st2;
    st2.insert({n + 2, -1});

    for (int i = 0; i < m; i++) {
        int x; cin >> x;

        auto it = st.lower_bound(x);
        st2.erase({ *it - *prev(it), *prev(it) });

        it = st.insert(x).first;
        st2.insert({ *next(it) - *it, *it });
        st2.insert({ *it - *prev(it), *prev(it) });

        cout << st2.rbegin()->first - 1 << '\n';
    }
}
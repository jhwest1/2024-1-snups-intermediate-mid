#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    set<int> st;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        st.insert(x);
    }

    auto it = st.end();
    for (int i = 0; i < k; i++) {
        it = prev(it);
        cout << *it << ' ';
    }
    cout << '\n';
    
}
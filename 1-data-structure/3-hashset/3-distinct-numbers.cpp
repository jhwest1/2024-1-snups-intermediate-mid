#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;

    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        st.insert(x);
    }
    cout << st.size() << '\n';
}
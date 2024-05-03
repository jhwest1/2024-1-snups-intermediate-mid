#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int TC; cin >> TC;
    while (TC--) {
        int q; cin >> q;

        set<int> st;
        for (int i = 0; i < q; i++) {
            string S; cin >> S;
            if (S == "I") {
                int x; cin >> x;
                st.insert(x);
            }
            else {
                int k; cin >> k;
                if (!st.empty()) {
                    if (k == -1) {
                        st.erase(st.begin());
                    }
                    else {
                        st.erase(prev(st.end()));
                    }
                }
            }
        }

        if (st.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << *st.rbegin() << ' ' << *st.begin() << '\n';
        }
    }
}
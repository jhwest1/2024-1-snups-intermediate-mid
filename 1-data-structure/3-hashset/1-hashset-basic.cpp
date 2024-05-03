#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int q; cin >> q;

    unordered_set<int> st;
    for (int i = 0; i < q; i++) {
        string S; cin >> S;
        if (S == "add") {
            int x; cin >> x;
            st.insert(x);
        }
        else if (S == "remove") {
            int x; cin >> x;
            st.erase(x);
        }
        else {
            int x; cin >> x;

            if (st.find(x) == st.end()) {
                cout << "false\n";
            }
            else {
                cout << "true\n";
            }
        }
    }
}
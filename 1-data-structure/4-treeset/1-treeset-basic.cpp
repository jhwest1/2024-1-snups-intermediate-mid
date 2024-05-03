#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int q; cin >> q;

    set<int> st;
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
        else if (S == "find") {
            int x; cin >> x;
            cout << (st.find(x) != st.end() ? "true\n" : "false\n");
        }
        else if (S == "lower_bound") {
            int x; cin >> x;
            auto it = st.lower_bound(x);

            if (it != st.end()) {
                cout << *it << '\n';
            }
            else {
                cout << "None\n";
            }
        }
        else if (S == "upper_bound") {
            int x; cin >> x;
            auto it = st.upper_bound(x);

            if (it != st.end()) {
                cout << *it << '\n';
            }
            else {
                cout << "None\n";
            }
        }
        else if (S == "largest") {
            if (st.empty()) {
                cout << "None\n";
            }
            else {
                cout << *st.rbegin() << '\n';
            }
        }
        else {
            if (st.empty()) {
                cout << "None\n";
            }
            else {
                cout << *st.begin() << '\n';
            }
        }
    }
}
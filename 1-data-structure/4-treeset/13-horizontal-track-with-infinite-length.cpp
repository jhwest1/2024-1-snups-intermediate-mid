#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, t;
    cin >> n >> t;

    vector<int> s(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> v[i];
    }

    set<pair<double, pair<int, int>>> st;
    set<int> alive;

    for (int i = 1; i < n; i++) {
        if (v[i] < v[i - 1]) {
            st.insert({ (double)(s[i] - s[i - 1]) / (v[i - 1] - v[i]), {i - 1, i} });
        }
    }
    for (int i = 0; i < n; i++) {
        alive.insert(i);
    }

    while (!st.empty() && st.begin()->first <= t) {
        auto [x, y] = st.begin()->second;
        st.erase(st.begin());

        // x랑 y가 충돌함
        if (alive.find(x) != alive.begin()) {
            int k = *prev(alive.find(x));

            if (v[x] < v[k]) {
                st.erase({ (double)(s[x] - s[k]) / (v[k] - v[x]), { k, x } });
            }
            if (v[y] < v[k]) {
                st.insert({ (double)(s[y] - s[k]) / (v[k] - v[y]), { k, y } });
            }
        }
        alive.erase(x);
    }
    cout << alive.size() << '\n';

}
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(k), b(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i] >> b[i];
    }

    vector<unordered_set<int>> st(n);
    for (int i = 0; i < n; i++) {
        st[i].insert(i);
    }

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = i;
    }

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < k; i++) {
            int x = a[i] - 1;
            int y = b[i] - 1;

            swap(c[x], c[y]);
            st[c[x]].insert(x);
            st[c[y]].insert(y);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << st[i].size() << '\n';
    }
}
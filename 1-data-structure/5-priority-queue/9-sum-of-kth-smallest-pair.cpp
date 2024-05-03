#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    priority_queue<pair<int, pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({ -a[i] - b[0], {i, 0} });
    }

    for (int i = 0; i < k; i++) {
        auto [x, y] = pq.top().second;
        pq.pop();

        if (i == k - 1) {
            cout << a[x] + b[y] << '\n';
            return 0;
        }

        if (y + 1 < m) pq.push({ -a[x] - b[y + 1], {x, y + 1} });
    }
}
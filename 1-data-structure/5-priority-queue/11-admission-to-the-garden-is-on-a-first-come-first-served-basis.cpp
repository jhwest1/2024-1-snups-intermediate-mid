#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;

    vector<int> t(n), a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> t[i];
    }

    priority_queue<pair<int, int>> arrive;
    priority_queue<int> wait;

    for (int i = 0; i < n; i++) {
        arrive.push({-a[i], i});
    }

    int maxv = 0;
    int curt = 0;
    for (int i = 0; i < n; i++) {
        while (!arrive.empty() && -arrive.top().first <= curt) {
            int k = arrive.top().second;
            arrive.pop();

            wait.push(-k);
        }

        if (wait.empty()) {
            int k = arrive.top().second;
            curt = a[k];

            while (!arrive.empty() && -arrive.top().first <= curt) {
                int x = arrive.top().second;
                arrive.pop();

                wait.push(-x);
            }
        }

        int k = -wait.top();
        wait.pop();

        maxv = max(maxv, curt - a[k]);
        curt += t[k];
    }
    cout << maxv << '\n';
}
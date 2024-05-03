#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pq.push(x);
    }

    for (int i = 0; i < m; i++) {
        int k = pq.top();
        pq.pop();

        pq.push(k - 1);
    }
    cout << pq.top() << '\n';
}
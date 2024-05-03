#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pq.push(x);
    }

    while (pq.size() >= 2) {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();

        if (x != y) {
            pq.push(x - y);
        }
    }

    if (pq.size() == 1) {
        cout << pq.top() << '\n';
    }
    else {
        cout << "-1\n";
    }
}
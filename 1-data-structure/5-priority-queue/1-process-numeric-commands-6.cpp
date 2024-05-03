#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int q; cin >> q;

    priority_queue<int> pq;
    for (int i = 0; i < q; i++) {
        string S; cin >> S;
        if (S == "push") {
            int x; cin >> x;
            pq.push(x);
        }
        else if (S == "pop") {
            cout << pq.top() << '\n';
            pq.pop();
        }
        else if (S == "size") {
            cout << pq.size() << '\n';
        }
        else if (S == "empty") {
            cout << pq.empty() << '\n';
        }
        else {
            cout << pq.top() << '\n';
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        
        if (x == 0) {
            if (pq.empty()) {
                cout << "0\n";
            }
            else {
                cout << -pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(-x);
        }
    }
}
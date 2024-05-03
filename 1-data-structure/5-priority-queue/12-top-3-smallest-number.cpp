#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; 
    cin >> n;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pq.push(-x);

        if (i >= 2) {
            int x = -pq.top(); pq.pop();
            int y = -pq.top(); pq.pop();
            int z = -pq.top(); pq.pop();

            cout << (long long)x * y * z << '\n';
            pq.push(-x);
            pq.push(-y);
            pq.push(-z);
        }
        else cout << "-1\n";
    }
}
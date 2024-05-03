#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int TC; cin >> TC;
    while (TC--) {
        int n; cin >> n;

        priority_queue<int> big, small;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;

            if (small.empty() || x <= small.top()) {
                small.push(x);
            }
            else {
                big.push(-x);                
            }

            if (i % 2 == 0) {
                if (big.size() > i / 2) {
                    small.push(-big.top());
                    big.pop();
                }
                if (small.size() > i / 2 + 1) {
                    big.push(-small.top());
                    small.pop();
                }

                cout << small.top() << ' ';
            }
        }
        cout << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first + a.second != b.first + b.second) {
            return a.first + a.second > b.first + b.second;
        }
        else return a > b;
    }
};

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        pq.push({x, y});
    }

    for (int i = 0; i < m; i++) {
        auto [x, y] = pq.top();
        pq.pop();

        pq.push({x + 2, y + 2});
    }

    auto [x, y] = pq.top();
    cout << x << ' ' << y << '\n';

}
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, g;
    cin >> n >> g;

    vector<vector<int>> grp(n); // i번 사람이 속하는 그룹의 목록
    vector<int> cnt(g), sum(g); // i번 그룹 중 아직 초대장을 못 받은 사람의 수, 번호의 XOR

    for (int i = 0; i < g; i++) {
        int sz; cin >> sz;
        for (int j = 0; j < sz; j++) {
            int x; cin >> x;

            grp[x - 1].push_back(i);
            cnt[i]++;
            sum[i] ^= x - 1;
        }
    }

    queue<int> q; // 초대장을 받은 사람들의 큐
    q.push(0);

    vector<bool> invited(n);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (invited[x]) continue;
        invited[x] = true;

        for (int k : grp[x]) {
            --cnt[k];
            sum[k] ^= x;
            if (cnt[k] == 1) {
                q.push(sum[k]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (invited[i]) {
            ++ans;
        }
    }
    cout << ans << '\n';
}
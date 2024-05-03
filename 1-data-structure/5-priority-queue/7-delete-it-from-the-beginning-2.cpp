#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    double ans = 0;
    int sum = 0;
    int minv = 1e9;
    for (int i = n - 1; i >= 0; i--) {
        sum += a[i];
        minv = min(minv, a[i]);

        if (i != n - 1) {
            ans = max(ans, (double)(sum - minv) / (n - 1 - i));
        }
    }

    cout.precision(2);
    cout << fixed << ans << '\n';
}
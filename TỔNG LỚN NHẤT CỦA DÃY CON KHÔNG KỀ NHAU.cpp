#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;

void solution() {
    ll ans = 0;
    cin >> n;
    vector <int> v(n);
    for (auto& i : v) cin >> i;

    vector <ll> dp(n, 0);
    dp[0] = v[0];
    dp[1] = max(v[0], v[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + v[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}
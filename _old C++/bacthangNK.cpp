#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll oo = 1e9 + 7;

ll count_ways(int n, int k) {
    vector <ll> dp(n + 1, 0);
    dp[1] = 1;
    for (ll i = 2; i <= n; i++) {
        if (i <= k) {
            for (int j = 1; j < i; j++) dp[i] = (dp[i] + dp[j]) % oo;
            dp[i]++;
        }
        else {
            for (int j = i - 1; j >= i - k; j--) {
                dp[i] = (dp[i] + dp[j]) % oo;
            }
        }
    }
    return dp[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << count_ways(n, k) << endl;
    }
}
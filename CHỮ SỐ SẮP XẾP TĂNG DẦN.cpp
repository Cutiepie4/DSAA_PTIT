#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll oo = 1e9 + 7;

int main() {
    vector <vector <ll>> dp(1001, vector<ll>(1001, 1));
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % oo;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n + 9][n] << endl;
    }
}
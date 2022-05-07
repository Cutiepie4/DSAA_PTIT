// 100 = 10^2 = 5^2 + 5^2 + 5^2 + 5^2 -> output là 1
#include <bits/stdc++.h>
using namespace std;

int n, t;
vector <int> dp(10002, INT32_MAX);

void init() {
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < 10001; i++) {
        if (i == (int)sqrt(i) * (int)sqrt(i)) {
            dp[i] = 1;
            continue;
        }
        for (int j = 1; j <= i / 2; j++) {
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
        }
    }
}

int main() {
    cin >> t;
    init();
    while (t--) {
        cin >> n;
        cout << dp[n] << endl;
    }
}
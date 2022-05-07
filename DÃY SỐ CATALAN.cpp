#include <bits/stdc++.h>
using namespace std;

vector <long long> dp(31, 1);
void init() {
    for (int i = 2; i <= 30; i++) {
        dp[i] = dp[i-1] * (4 * i - 2) / (i + 1);
    }
}

int main() {
    int t;
    cin >> t;
    init();
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}
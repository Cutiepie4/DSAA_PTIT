// // có 2 code
// #include <bits/stdc++.h>
// using namespace std;

// int factorial(int x) {
//     if (x == 1) return 1;
//     return x * factorial(x - 1);
// }

// int combination(int n, int k) {
//     if (n == k) return 1;
//     int t = factorial(n);
//     int m = factorial(k) * factorial(n - k);
//     return t / m;
// }

// int main() {
//     int n, k;
//     cin >> n >> k;
//     cout << combination(n, k);
// }

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
        int n, k;
        cin >> n >> k;
        cout << dp[n][k] << endl;
    }
}
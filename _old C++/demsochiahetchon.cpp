#include <bits/stdc++.h>
using namespace std;

long long countDivisibleSubseq(string str, long long n)
{
    int len = str.length();
    long long dp[len][n];
    memset(dp, 0, sizeof(dp));

    dp[0][(str[0] - '0') % n]++;

    for (int i = 1; i < len; i++)
    {
        dp[i][(str[i] - '0') % n]++;

        for (int j = 0; j < n; j++)
        {
            dp[i][j] += dp[i - 1][j];
            dp[i][(j * 10 + (str[i] - '0')) % n] += dp[i - 1][j];
        }
    }
    return dp[len - 1][0];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        string s;
        cin >> n >> k >> s;
        cout << countDivisibleSubseq(s, k) << endl;
    }
}
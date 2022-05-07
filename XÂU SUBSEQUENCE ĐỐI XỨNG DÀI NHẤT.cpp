/*

*/
#include <bits/stdc++.h>
using namespace std;
#define mt vector <vector <int>>

int back(int i, int j, string& s, mt& dp) {
    if (dp[i][j] == -1)
        if (i > j) {
            dp[i][j] = 0;
        }
        else {
            if (i == j) {
                dp[i][j] = 1;
            }
            else {
                if (s[i] == s[j]) {
                    dp[i][j] = back(i + 1, j - 1, s, dp) + 2;
                }
                else dp[i][j] = max(back(i + 1, j, s, dp), back(i, j - 1, s, dp));
            }
        }
    return dp[i][j];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        mt dp(s.size(), vector <int>(s.size(), -1));
        cout << back(0, s.size() - 1, s, dp) << endl;
    }
}

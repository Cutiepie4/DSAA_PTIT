#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long inf = 100000000000000007LL;
long long dp[16][16][3];
class Solution {
public:
    long long nonValue(int type) {
        if (type == 0) {
            return inf;
        }
        else if (type == 1) {
            return -inf;
        }
        else {
            return -1;
        }
    }
    int maxProductPath(vector<vector<int>>& a) {
        int n = (int)a.size();
        int m = (int)a[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int type = 0; type <= 2; type++) {
                    dp[i][j][type] = nonValue(type);
                }
            }
        }
        if (a[0][0] < 0) {
            dp[0][0][0] = a[0][0];
        }
        else if (a[0][0] == 0) {
            dp[0][0][2] = 0;
        }
        else {
            dp[0][0][1] = a[0][0];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int type = 0; type <= 2; type++) {
                    if (dp[i][j][type] == nonValue(type)) {
                        continue;
                    }
                    if (i < n - 1) {
                        if (a[i + 1][j] == 0) {
                            dp[i + 1][j][2] = 0;
                        }
                        else if (a[i + 1][j] < 0) {
                            if (type == 0) {
                                dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j][type] * a[i + 1][j]);
                            }
                            else if (type == 1) {
                                dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][type] * a[i + 1][j]);
                            }
                            else {
                                dp[i + 1][j][2] = 0;
                            }
                        }
                        else {
                            if (type == 0) {
                                dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][type] * a[i + 1][j]);
                            }
                            else if (type == 1) {
                                dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j][type] * a[i + 1][j]);
                            }
                            else {
                                dp[i + 1][j][2] = 0;
                            }
                        }
                    }
                    if (j < m - 1) {
                        if (a[i][j + 1] == 0) {
                            dp[i][j + 1][2] = 0;
                        }
                        else if (a[i][j + 1] < 0) {
                            if (type == 0) {
                                dp[i][j + 1][1] = max(dp[i][j + 1][1], dp[i][j][type] * a[i][j + 1]);
                            }
                            else if (type == 1) {
                                dp[i][j + 1][0] = min(dp[i][j + 1][0], dp[i][j][type] * a[i][j + 1]);
                            }
                            else {
                                dp[i][j + 1][2] = 0;
                            }
                        }
                        else {
                            if (type == 0) {
                                dp[i][j + 1][0] = min(dp[i][j + 1][0], dp[i][j][type] * a[i][j + 1]);
                            }
                            else if (type == 1) {
                                dp[i][j + 1][1] = max(dp[i][j + 1][1], dp[i][j][type] * a[i][j + 1]);
                            }
                            else {
                                dp[i][j + 1][2] = 0;
                            }
                        }
                    }
                }
            }
        }
        if (dp[n - 1][m - 1][1] != -inf) {
            return dp[n - 1][m - 1][1] % MOD;
        }
        if (dp[n - 1][m - 1][2] != -1) {
            return 0;
        }
        return -1;
    }
};

int main() {

}
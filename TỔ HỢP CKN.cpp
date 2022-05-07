/*
Cho 2 số nguyên n, k. Bạn hãy tính C(n, k) modulo 109+7.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm 2 số nguyên n, k (1 ≤ k ≤ n ≤ 1000).
Output:

Với mỗi test, in ra đáp án trên một dòng.
Ví dụ:

Input

2

5 2

10 3

Output

10

120
*/

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
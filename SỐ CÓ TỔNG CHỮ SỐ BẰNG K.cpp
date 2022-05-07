/*
Cho 2 số nguyên N và K. Bạn hãy đếm số lượng các số có N chữ số mà tổng các chữ số của nó bằng K. Lưu ý, chữ số 0 ở đầu không được chấp nhận.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 50).
Mỗi test gồm 2 số nguyên N và K (1 ≤ N ≤ 100, 0 ≤ K ≤ 50000).
Output:

Với mỗi test, in ra đáp số tìm được theo modulo 109+7 trên một dòng.


Ví dụ:

Input:
3
2 2
2 5
3 6

Output
2
5
21
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

vector <vector <ll>> dp(101, vector <ll>(5001, 0));

void init() {
    for (int i = 1; i < 10; i++) dp[1][i] = 1;
    for (int i = 2; i <= 100; i++) {
        for (int j = 1; j <= 5000; j++) {
            for (int k = 0; k < 10; k++) {
                if (j > k)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
            }
        }
    }
}

void solution() {
    int n, k;
    cin >> n >> k;
    if (k == 0) cout << 0;
    else cout << dp[n][k];
}

int main() {
    init();
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}
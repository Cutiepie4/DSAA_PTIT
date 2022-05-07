/*
Cho số hai số n, k. Hãy tìm P(n,k) theo modulo 109+7.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một cặp số n, k được viết trên một dòng.
T, n, k thỏa mãn ràng buộc: 1 ≤ T ≤ 100;  1 ≤ n,k ≤ 1000.
Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <int>
#define matrixl vector <vector <ll>>
#define vtl vector <ll>
const ll MOD = 1e9 + 7;

matrixl dp(1001, vtl(1001, 1));
vtl f(1001, 1);

void init() {
    for (int i = 1; i <= 1000; i++) {
        f[i] = f[i - 1] % MOD * i % MOD;
        for (int j = 1; j < i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] % MOD + dp[i - 1][j]) % MOD;
        }
    }
}

ll process(int n, int k) {
    return dp[n][k] % MOD * f[k] % MOD;
}

void solution() {
    int n, k;
    cin >> n >> k;
    cout << process(n, k) << endl;
}

int main() {
    int t;
    cin >> t;
    init();
    while (t--) {
        solution();
    }
    return 0;
}
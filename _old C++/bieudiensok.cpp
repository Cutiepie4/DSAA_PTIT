/*
Cho một mảng A[] gồm N số nguyên dương và số K. Người ta gọi “biểu diễn số K trên mảng A[]” là một cách liệt kê các phần tử trong mảng A[] sao cho tổng các phần tử đó đúng bằng K. Các số được phép lặp lại và một cách sắp đặt lại thứ tự các số cũng được xem là một cách biểu diễn khác.

Hãy đếm số cách biểu diễn số K trên mảng A[].

Ví dụ với mảng A[] = {1, 5, 6}, K = 7 ta có 6 cách sau:

7 = 1 + 1 + 1+1 + 1 + 1+1 (lặp số 1 7 lần)

7 = 1 + 1 + 5 (lặp số 1)

7 = 1 + 5 + 1 (lặp và sắp đặt lại số 1)

7 = 1 + 6

7 = 6 + 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <int>
#define matrixl vector <vector <ll>>
#define vtl vector <ll>
const ll MOD = 1e9 + 7;

void solution() {
    ll n, total;
    cin >> n >> total;
    vt step(n);
    vtl dp(total + 1, 0);
    dp[0] = 1;
    for (auto& i : step) {
        cin >> i;
    }
    for (int i = 1; i <= total; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= step[j]) {
                dp[i] = (dp[i] + dp[i - step[j]]) % MOD;
            }
        }
    }
    cout << dp[total] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}
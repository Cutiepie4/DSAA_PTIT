/*
Một chiếc cầu thang có N bậc. Mỗi bước, bạn được phép bước lên trên tối đa K bước. Hỏi có tất cả bao nhiêu cách bước để đi hết cầu thang? (Tổng số bước đúng bằng N).

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
Mỗi test gồm hai số nguyên dương N và K(1 ≤ N ≤ 100000, 1 ≤ K ≤ 100).
Output: 

Với mỗi test, in ra đáp án tìm được trên một dòng theo modulo 109+7.
Ví dụ:

Input

2

2 2

4 2

Output
2
5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll oo = 1e9 + 7;

ll count_ways(int n, int k) {
    vector <ll> dp(n + 1, 0);
    dp[1] = 1;
    for (ll i = 2; i <= n; i++) {
        if (i <= k) {
            for (int j = 1; j < i; j++) dp[i] = (dp[i] + dp[j]) % oo;
            dp[i]++;
        }
        else {
            for (int j = i - 1; j >= i - k; j--) {
                dp[i] = (dp[i] + dp[j]) % oo;
            }
        }
    }
    return dp[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << count_ways(n, k) << endl;
    }
}
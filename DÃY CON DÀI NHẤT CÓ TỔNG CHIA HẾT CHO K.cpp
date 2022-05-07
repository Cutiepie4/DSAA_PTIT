/*
Cho một dãy gồm n ( n ≤ 1000) số nguyên dương A1, A2, ..., An và số nguyên dương k (k ≤ 50). Hãy tìm dãy con gồm nhiều phần tử nhất của dãy đã cho sao cho tổng các phần tử của dãy con này chia hết cho k. 

Input: Dòng đầu ghi số bộ test T (T<10). Mỗi bộ test gồm 2 dòng. Dòng đầu tiên chứa hai số n, k.  Dòng tiếp theo ghi n số của dãy A. Các số đều không vượt quá 100.   

Output: Gồm 1 dòng duy nhất ghi số lượng phần tử của dãy con dài nhất thoả mãn. Dữ liệu vào luôn đảm bảo sẽ có ít nhất một dãy con có tổng chia hết cho k.

Ví dụ:

Input
1
10 3
2 3 5 7 9 6 12 7 11 15
Output:
9
*/
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector <int> v;

int prs() {
    vector <vector <int>> dp(n, vector <int>(k, 0));
    dp[0] = vector <int>(k, -1000);
    dp[0][v[0]] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < k; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][(k + j - v[i]) % k] + 1);
        }
    }
    return dp[n - 1][0];
}

void solution() {
    cin >> n >> k;
    v = vector <int>(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] %= k;
    }
    cout << prs();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}
/*
Mọi số nguyên dương N đều có thể phân tích thành tổng các bình phương của các số nhỏ hơn N. Ví dụ số 100 = 102 hoặc 100 = 52 + 52 + 52 + 52. Cho số nguyên dương N. Nhiệm vụ của bạn là tìm số lượng ít nhất các số nhỏ hơn N mà có tổng bình phương bằng N.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi test là một số tự nhiên N được viết trên 1 dòng.
T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤10000.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:



Input
3
100
6
25

Output
1
3
1
*/

#include <bits/stdc++.h>
using namespace std;

int n, t;
vector <int> dp(10001, INT32_MAX);

void init() {
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < 10001; i++) {
        int x = sqrt(i);
        if (i == x * x) {
            dp[i] = 1;
            continue;
        }
        for (int j = 1; j <= i / 2; j++) {
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
        }
    }
}

int main() {
    cin >> t;
    init();
    while (t--) {
        cin >> n;
        cout << dp[n] << endl;
    }
}
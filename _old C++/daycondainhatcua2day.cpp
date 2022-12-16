/*
Cho hai dãy số thực A[] và B[] đều có N phần tử, 
các giá trị là số thực và không quá 100.

Hãy tính độ dài dài nhất của dãy các vị trí (không cần liên tiếp) thỏa mãn cả hai điều kiện:

Nếu xét các vị trí đó trên dãy A[] thì dãy con thu được thỏa mãn tính chất tăng dần (giá trị bằng nhau không được tính vào dãy tăng).
Nếu xét các vị trí đó trên dãy B[] thì dãy con thu được thỏa mãn tính chất giảm dần (giá trị bằng nhau không được tính vào dãy giảm).
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
    int n;
    float ans = 1;
    cin >> n;
    vector <float> a(n), b(n), dp(n, 1);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[i] > a[j] && b[i] < b[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}
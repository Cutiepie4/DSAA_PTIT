/*
Cho hai dãy số thực A[] và B[] đều có N phần tử, các giá trị là số thực và không quá 100.

Hãy tính độ dài dài nhất của dãy các vị trí (không cần liên tiếp) thỏa mãn cả hai điều kiện:

Nếu xét các vị trí đó trên dãy A[] thì dãy con thu được thỏa mãn tính chất tăng dần (giá trị bằng nhau không được tính vào dãy tăng).
Nếu xét các vị trí đó trên dãy B[] thì dãy con thu được thỏa mãn tính chất giảm dần (giá trị bằng nhau không được tính vào dãy giảm).
Input

Dòng đầu ghi số bộ test (không quá 100).

Mỗi bộ test bắt đầu bởi số N (không quá 500).

Tiếp theo là N dòng, mỗi dòng ghi 2 giá trị A[i] và B[i]

Output

Với mỗi test, ghi ra độ dài tính được trên một dòng.

Ví dụ

Input

Output

3

2

1.0 1.0

1.5 0.0

3

1.0 1.0

1.0 1.0

1.0 1.0

6

1.5 9.0

2.0 2.0

2.5 6.0

3.0 5.0

4.0 2.0

10.0 5.5

2

1

4
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, res = 1;
        cin >> n;
        double a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        vector <int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j] && b[i] < b[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        cout << res << endl;
    }
}
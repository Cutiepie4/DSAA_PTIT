/*
Giả sử bạn cần viết N ký tự giống nhau lên màn hình. 
Bạn chỉ được phép thực hiện ba thao tác dưới đây với chi phí thời gian khác nhau:

Thao tác insert: chèn một ký tự với thời gian là X.
Thao tác delete: loại bỏ ký tự cuối cùng với thời gian là Y.
Thao tác copying: copy và paste tất cả các ký tự đã 
viết để số ký tự được nhân đôi với thời gian là Z.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <int>
#define matrixl vector <vector <ll>>
#define vtl vector <ll>

void solution() {
    int n, add, cp, del;
    cin >> n >> add >> del >> cp;
    vt dp(n + 1);
    dp[1] = add;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            if (dp[i / 2] + cp < dp[i - 1] + add) {
                dp[i] = dp[i / 2] + cp;
            }
            else {
                if (dp[i / 2] + cp == dp[i - 1] + add) {
                    dp[i] = dp[i / 2] + cp;
                }
                else dp[i] = dp[i - 1] + add;
            }
        }
        else {
            if (dp[i / 2 + 1] + cp + del < dp[i - 1] + add) {
                dp[i] = dp[i / 2 + 1] + cp + del;
            }
            else {
                if (dp[i / 2 + 1] + cp + del == dp[i - 1] + add) {
                    dp[i] = dp[i - 1] + add;
                }
                else dp[i] = dp[i - 1] + add;
            }
        }
    }
    cout << dp[n] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}
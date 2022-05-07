/*
Cho xâu ký tự S. Nhiệm vụ của bạn là tìm số phép loại bỏ ít nhất các ký tự trong S để S trở thành xâu đối xứng. Chú ý, phép loại bỏ phải bảo toàn tính trước sau của các ký tự trong S.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự được viết trên một dòng
T, str thỏa mãn ràng buộc: 1≤T≤100;  1≤length(S)≤100.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

 Input

Output

2
aebcbda
geeksforgeeks

2
8
*/
#include <bits/stdc++.h>
using namespace std;
#define mt vector <vector <int>>

int back(int i, int j, string& s, mt& dp) {
    if (dp[i][j] == -1)
        if (i > j) {
            dp[i][j] = 0;
        }
        else {
            if (i == j) {
                dp[i][j] = 1;
            }
            else {
                if (s[i] == s[j]) {
                    dp[i][j] = back(i + 1, j - 1, s, dp) + 2;
                }
                else dp[i][j] = max(back(i + 1, j, s, dp), back(i, j - 1, s, dp));
            }
        }
    return dp[i][j];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        mt dp(s.size(), vector <int>(s.size(), -1));
        cout << s.size() - back(0, s.size() - 1, s, dp) << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
#define vt vector <int>
#define matrix vector <vector <int>>
// check tat ca xau con co phai la palindrome ko
/*
Mở rộng vấn đề : nếu như ta muốn kiểm tra 1 lượng lớn xâu con của S có phải
là xâu palindrome không,
vậy có cách nào để kiểm tra nhanh không ?
Nhận xét : với xâu S, nếu xâu con S[L, R] là xâu palin
TH1 : L = R. Điều này hiển nhiên phải không các bạn ?
TH2 : L < R
kí tự S[L] = S[R]
hoặc L = R - 1, hoặc S[L + 1, R - 1] cũng phải là xâu palin
Từ nhận xét trên, ta có thể dùng 1 mảng CheckPalin[][] để lưu lại
kết quả khi kiểm tra với các xâu con của S. Ta sẽ kiểm tra CheckPalin[i][j] dựa vào S[i], S[j] và CheckPalin[i + 1][j - 1]
Khi cần kiểm tra 1 đoạn [L, R] có là xâu palin không, ta chỉ việc
lấy ra CheckPalin[L][R] là được. 1 bước, quá nhanh gọn.
*/

int buildCheck(string s) {
    matrix CheckPalin(s.size(), vt(s.size(), 0));
    int n = s.size(), ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        CheckPalin[i][i] = 1;
        for (int j = i + 1; j < n; ++j) {
            CheckPalin[i][j] = (s[i] == s[j]) && (i == j - 1 || CheckPalin[i + 1][j - 1]);
            if (CheckPalin[i][j]) ans = max(ans, j - i + 1);
        }
    }
    return ans;
}

void solution() {
    string s;
    cin >> s;
    cout << buildCheck(s) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}
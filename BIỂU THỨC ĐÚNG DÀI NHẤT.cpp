/*
Cho biểu thức P chỉ bao gồm các ký tự mở ngoặc ‘(’ hoặc đóng ngoặc ‘)’. Biểu thức P có thể viết đúng hoặc không đúng. Nhiệm vụ của bạn là tìm tổng độ dài lớn nhất của các biểu thức con viết đúng trong P (các biểu thức đúng không nhất thiết phải liên tiếp nhau).

Chú ý: Độ dài của biểu thức đúng ngắn nhất là 2.



Input:

Dòng đầu tiên đưa vào số lượng bộ test T (không quá 100)
Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức P được viết trên một dòng (độ dài của P không quá 100).
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

Output

4
(()(
()()((
((()()())))
()(())(

2

4

10

6
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        stack <char> st;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(s[i]);
            else {
                if (!st.empty()) {
                    st.pop();
                    cnt += 2;
                }
            }
        }
        cout << cnt << endl;
    }
}
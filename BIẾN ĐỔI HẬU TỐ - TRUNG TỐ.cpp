/*
Hãy viết chương trình chuyển đổi biểu thức biểu diễn dưới dạng hậu tố về dạng trung tố.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T;
Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức tiền tố exp.
T, exp thỏa màng ràng buộc: 1≤T≤100; 2≤length(exp)≤106.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ràng buộc:

T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤106.
Ví dụ:

Input

Output

2

ABC++

AB*C+

(A+(B+C)

((A*B)+C)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack <string> st;

        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                string tmp;
                st.push(tmp + s[i]);
            }
            else {
                string x = st.top();
                st.pop();
                string y = st.top();
                st.pop();
                string z = "(" + y + s[i] + x + ")";
                st.push(z);
            }
        }
        cout << st.top() << endl;
    }
}
/*
Cho một mảng S gồm 2×N ký tự, trong đó có N ký tự ‘[’ và N ký tự ‘]’. Xâu S được gọi là viết đúng nếu S có dạng S2[S1] trong đó S, S2 là các xâu viết đúng. Nhiệm vụ của bạn là tìm số các phép đổi chỗ ít nhất các ký tự kề nhau của xâu S viết sai để  S trở thành viết đúng. Ví dụ với xâu S =”[]][][” ta có số phép đổi chỗ kề nhau ít nhất là 2.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu S viết sai theo nguyên tắc kể trên.
T, S thòa mãn ràng buộc: 1≤T≤100; 1≤length(S)≤100000.
Output:

Đưa kết quả trên một dòng.
Ví dụ:

Input

Output

2

[]][][

[][][]

2
0
*/
#include <bits/stdc++.h>
using namespace std;

int prs(string s) {
    stack <char> st;
    int cnt = 0, ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (st.empty() || st.top() == s[i]) {
            st.push(s[i]);
        }
        else if (st.top() == '[' && s[i] == ']') {
            st.pop();
            cnt += 2;
        }
        else if (st.top() == ']' && s[i] == '[') {
            ans += st.size() + cnt;
            st.pop();
        }
        if (st.empty()) cnt = 0;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << prs(s) << endl;
    }
}
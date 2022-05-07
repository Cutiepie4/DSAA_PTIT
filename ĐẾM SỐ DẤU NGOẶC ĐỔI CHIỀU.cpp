/*
Cho một xâu chỉ gồm các kí tự ‘(‘, ‘) và có độ dài chẵn. Hãy đếm số lượng dấu ngoặc cần phải đổi chiều ít nhất, sao cho xâu mới thu được là một dãy ngoặc đúng.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm 1 xâu S có độ dài không vượt quá 100 000, chỉ gồm dấu ( và ).

Output:

Với mỗi test, in ra đáp án tìm được trên một dòng.

Ví dụ:

Input:

Output

4

))((

((((

(((())

)(())(((

2

2

1

3
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
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')' && !st.empty() && st.top() == '(') st.pop();
            else st.push(s[i]);
        }
        if (st.empty()) {
            cout << 0 << endl;
            continue;
        }
        s.clear();
        while (!st.empty()) {
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size() - 1; i += 2) {
            if (s[i] == ')') ans++;
            if (s[i + 1] == '(') ans++;
        }
        cout << ans << endl;
    }
}
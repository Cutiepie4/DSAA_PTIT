/*
Cho một xâu chỉ gồm các kí tự ‘(‘, ‘) và có độ dài chẵn. Hãy đếm số lượng dấu ngoặc cần phải đổi chiều ít nhất, sao cho xâu mới thu được là một dãy ngoặc đúng.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm 1 xâu S có độ dài không vượt quá 100 000, chỉ gồm dấu ( và ).

Output: 

Với mỗi test, in ra đáp án tìm được trên một dòng.

Ví dụ:

Input:
4
))((
((((
(((())
)(())(((

Output
2
2
1
3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vt vector <int>
#define vtl vector <ll>
#define matrix vector <vector <int>>
#define matrixl vector <vector <ll>>
const ll MOD = 1e9 + 7;

int process(string s){
    int ans = 0;
    stack <char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') st.push(s[i]);
        else {
            if (st.empty()) {
                ans++;
                st.push('(');
            }
            else st.pop();
        }
    }
    return ans + st.size() / 2;
}

void solution() {
    string s;
    cin >> s;
    cout << process(s) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}
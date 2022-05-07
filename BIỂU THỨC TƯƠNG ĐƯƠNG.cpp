/*
Cho biểu thức đúng P chỉ bao gồm các phép toán +, -, các toán hạng cùng với các ký tự ‘(’, ‘)’. Hãy bỏ tất cả các ký tự ‘(’, ‘)’ trong P để nhận được biểu thức tương đương. Ví dụ với P = a – (b + c) ta có kết quả P = a – b – c .

Input:

Dòng đầu tiên đưa vào số lượng bộ test T;
Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức P được viết trên một dòng.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ràng buộc:

T, P thỏa mãn ràng buộc: 1≤T≤100; 1≤length(P)≤103.
Ví dụ:
Input
2
a–(b+c)
a-(b-c-(d+e))-f

Output
a-b-c
a-b+c+d+e-f
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define vtp vector <pair <int,int>>
#define matrix vector <vector <int>>
#define matrixl vector <vector <ll>>
const int MOD = 1e9 + 7;

void solution() {
    string s;
    cin >> s;
    stack <int> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') st.push(i);
        else if (s[i] == ')') {
            int last = st.top();
            st.pop();
            if (last > 0 && s[last - 1] == '-') {
                for (int j = last + 1; j < i; j++) {
                    if (s[j] == '+') s[j] = '-';
                    else if (s[j] == '-') s[j] = '+';
                }
            }
        }
    }
    for (auto i : s) {
        if (i != ')' && i != '(') cout << i;
    }
}

int main() {
    faster();
    int T;
    cin >> T;
    while (T--) {
        solution();
        cout << endl;
    }
    return 0;
}
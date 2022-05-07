/*
Cho P1, P2 là hai biểu thức đúng chỉ bao gồm các ký tự mở ngoặc ‘(’ hoặc đóng ngoặc ‘)’ và các toán hạng in thường. Nhiệm vụ của bạn là định xem P1 và P2 có giống nhau hay không.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T;
Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào P1, dòng tiếp theo đưa vào P2.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ràng buộc:

T, P thỏa mãn ràng buộc: 1≤T≤100; 1≤length(P) ≤100.
Ví dụ:

 

Input
2
-(a+b+c)
-a-b-c
a-b-(c-d)
a-b-c-d

Output
YES
NO
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

void rutgon(string& s) {
    string tmp;
    stack <int> st; // stack lưu index của ( gần nhất
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
        if (i != ')' && i != '(') tmp.push_back(i);
    }
    s = tmp;
}

void solution() {
    string a, b;
    cin >> a >> b;
    rutgon(a);
    rutgon(b);
    cout << (a == b ? "YES" : "NO");
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
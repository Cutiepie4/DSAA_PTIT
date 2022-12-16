/*
Cho biểu thức số họcbất kỳ. 
Nhiệm vụ của bạn là xác định đ dài lớn nhất 
của các cặp đóng mở ngoặc đúg lồng nhau. 
Ví dụ với biểu thức P = “( ((X))(((Y))) )” 
ta có độ dài các cặp đóng mở ngoc lồng nhau 
đúng là 4.

Nếu biểu thức không đúng hãy đưa ra -1.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <int>
#define matrixl vector <vector <ll>>
#define vtl vector <ll>
const ll MOD = 1e9 + 7;

int process(string s) {
    int cnt = 0, ans = 0;
    stack <char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push('(');
            cnt = st.size();
        }
        if (s[i] == ')') {
            ans = max(ans, cnt);
            if (st.empty()) return -1;
            st.pop();
        }
    }
    if (!st.empty()) return -1;
    return ans;
}

void solution() {
    string s;
    cin >> s;
    cout << process(s) << endl;
}

int main() {
    int t;
    cin >> t;
    // cin.ignore();
    while (t--) {
        solution();
    }
    return 0;
}
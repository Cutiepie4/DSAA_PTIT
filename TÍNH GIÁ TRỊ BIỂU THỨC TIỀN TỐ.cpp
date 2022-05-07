/*
Hãy viết chương trình tính toán giá trị của biểu thức tiền tố.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T;
Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức tiền tố exp. Các số xuất hiện trong biểu thức là các số đơn có 1 chữ số.
Output:

Đưa ra kết quả mỗi test theo từng dòng, chỉ lấy giá trị phần nguyên.
Ràng buộc:

T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤20.
Ví dụ:

Input
2
-+8/632
-+7*45+20

Output
8
25
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vt vector <int>
#define vtl vector <ll>
#define matrix vector <vector <int>>
#define matrixl vector <vector <ll>>
const ll MOD = 1e9 + 7;

int cal(string s) {
    stack <int> st;
    int z = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (isdigit(s[i])) st.push(s[i] - '0');
        else {
            int y = st.top();
            st.pop();
            int x = st.top();
            st.pop();
            if (s[i] == '*') z = y * x;
            if (s[i] == '+') z = y + x;
            if (s[i] == '/') z = y / x;
            if (s[i] == '-') z = y - x;
            st.push(z);
        }
    }
    return z;
}

void solution() {
    string s;
    cin >> s;
    cout << cal(s) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}
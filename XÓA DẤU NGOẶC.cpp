/*
Cho biểu thức toán học đúng, bạn cần tìm tất cả các biểu thức đúng có thể bằng cách xóa bỏ các cặp dấu ngoặc tương ứng với nhau từ biểu thức ban đầu.

Ví dụ: Cho biểu thức: (2+(2*2)+2) Các biểu thức tìm được:

(2+2*2+2)

2+(2*2)+2

2+2*2+2

Các biểu thức (2+2*2)+2 và 2+(2*2+2) không được chấp nhận vì không xóa đi các cặp dấu ngoặc tương ứng với nhau

Input: Một dòng chứa biểu thức gồm các số nguyên không âm, các dấu +, -, *, / và dấu ngoặc đơn.

Biểu thức không quá 200 kí tự, có chứa ít nhất 1 và không quá 10 cặp dấu ngoặc.

Output: In ra tất các các biểu thức khác nhau thỏa mãn đầu bài theo thứ tự từ điển

Ví dụ

Input

Output

(1+(2*(3+4)))



(1+(2*3+4))

(1+2*(3+4))

(1+2*3+4)

1+(2*(3+4))

1+(2*3+4)

1+2*(3+4)

1+2*3+4
*/
#include <bits/stdc++.h>
using namespace std;

int n;
set <string> Data;
vector <pair <int, int>> v;

void back(int inx, string s, string o) {
    if (inx == v.size()) {
        string tmp;
        for (auto i : s) if (i != '@') tmp.push_back(i);
        if (tmp != o)
            Data.insert(tmp);
        return;
    }
    back(inx + 1, s, o);
    string tmp = s;
    tmp[v[inx].first] = '@';
    tmp[v[inx].second] = '@';
    back(inx + 1, tmp, o);
}

void solution() {
    string s;
    cin >> s;
    n = s.size();
    stack <int> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') st.push(i);
        else if (s[i] == ')') {
            v.push_back({ st.top(), i });
            st.pop();
        }
    }
    back(0, s, s);
    for (auto i : Data) cout << i << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}
/*
Cho một biểu thức trong phạm vi hai chữ số với các phép toán cộng trừ nhân chia. Các toán hạng và kết quả đảm bảo là số nguyên dương có hai chữ số, nếu có phép chia thì phải thỏa mãn tính chia hết.

Người ta có thể ẩn đi một số chữ số hoặc phép toán bằng cách điền dấu chấm hỏi (?). Nhiệm vụ của bạn là khôi phục các dấu chấm hỏi và in ra phép toán chính xác ban đầu. Nếu không thể có kết quả đúng thì ghi ra WRONG PROBLEM!

Dữ liệu vào

Dòng đầu ghi số bộ test T (1 ≤ T ≤ 100).

T dòng tiếp theo, mỗi dòng là một biểu thức có thể có các dấu ?.

Nếu có thể có nhiều kết quả đúng thì in ra kết quả đầu tiên theo thứ tự từ điển, tức là số nhỏ nhất có thể tính từ trái sang phải.

Kết quả

Với mỗi bộ test, ghi ra biểu thức đúng tìm được. Hoặc WRONG PROBLEM!

Ví dụ

Input
2
?0 ? 12 = 28
40 / ?3 = ??

Output
40 - 12 = 28
WRONG PROBLEM!
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define pi pair <int,int>
#define matrix vector <vt>
#define matrixl vector <vtl>
const int MOD = 1e9 + 7;

int si(string s) {
    int res = 0;
    for (auto i : s) {
        if (isdigit(i)) res = res * 10 + i - '0';
    }
    return res;
}

int check(string s) {
    for (auto i : s) if (i == '?') return 0;
    vt v;
    string a;
    stringstream ss(s);
    string tmp;
    while (ss >> tmp) {
        if (tmp != "+" && tmp != "-" && tmp != "*" && tmp != "/" && tmp != "=") {
            if (si(tmp) >= 10) v.push_back(si(tmp));
            else return 0;
        }
        else if (tmp != "=") a = tmp;
    }
    if (a == "+" && v[0] + v[1] == v[2]) return 1;
    if (a == "-" && v[0] - v[1] == v[2]) return 1;
    if (a == "*" && v[0] * v[1] == v[2]) return 1;
    if (a == "/" && v[2] * v[1] == v[0]) return 1;
    return 0;
}

int back(int index, string s) {
    if (check(s)) {
        cout << s;
        return 1;
    }
    for (int i = index; i < s.size(); i++) {
        if (s[i] == '?') {
            if (i > 0 && i < s.size() - 1 && s[i - 1] == ' ' && s[i + 1] == ' ') {
                s[i] = '+';
                if (back(i + 1, s)) return 1;
                s[i] = '-';
                if (back(i + 1, s)) return 1;
                s[i] = '*';
                if (back(i + 1, s)) return 1;
                s[i] = '/';
                if (back(i + 1, s)) return 1;
            }
            else {
                for (char j = '0'; j <= '9'; j++) {
                    s[i] = j;
                    if (back(i + 1, s)) return 1;
                }
            }
        }
    }
    return 0;
}

void solution() {
    string s;
    getline(cin, s);
    if (!back(0, s)) cout << "WRONG PROBLEM!";
}

int main() {
    faster();
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        solution();
        cout << endl;
    }
    return 0;
}
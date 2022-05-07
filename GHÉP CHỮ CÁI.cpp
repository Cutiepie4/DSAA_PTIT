/*
Trong 8 chữ cái Tiếng Anh đầu tiên (ABCDEFGH) thì có 2 nguyên âm là ‘A’, ‘E’, còn lại là phụ âm.

Người ta muốn ghép các chữ cái bắt đầu từ chữ cái ‘A’ cho đến chữ cái c (‘D’ <= c <= ‘H’) sao cho mỗi chữ cái được sử dụng đúng một lần và xâu kết quả không có nguyên âm nào bị kẹp giữa bởi hai phụ âm.

Hãy liệt kê các xâu thỏa mãn theo thứ tự từ điển.

Input

Chỉ có một dòng ghi chữ cái c (đảm bảo từ ‘D’ đến ‘H’).

Output

Liệt kê các xâu thỏa mãn, mỗi xâu trên một dòng.
Ví dụ
Input
D

Output
ABCD
ABDC
ACBD
ACDB
ADBC
ADCB
BCDA
BDCA
CBDA
CDBA
DBCA
DCBA
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

string ABC = "ABCDEFGH";
vts S;

int check(string s) {
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == 'A' && s[i - 1] != 'E' && s[i + 1] != 'E') {
            return 0;
        }
        if (s[i] == 'E' && s[i - 1] != 'A' && s[i + 1] != 'A') {
            return 0;
        }
    }
    return 1;
}

void solution() {
    string c;
    cin >> c;
    while (ABC.back() != c.back()) {
        ABC.pop_back();
    }
    string tmp = ABC;
    reverse(tmp.begin(), tmp.end());
    while (tmp != ABC) {
        if (check(ABC)) S.push_back(ABC);
        next_permutation(ABC.begin(), ABC.end());
    }
    if (check(tmp)) S.push_back(tmp);
    sort(S.begin(), S.end());
    for (auto i : S) cout << i << endl;
}

int main() {
    faster();
    solution();
    return 0;
}
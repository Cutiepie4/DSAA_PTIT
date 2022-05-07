/*
Khi chat chit vui vẻ, anh em chiến hữu thường hay gõ HAHA để thể hiện sự sảng khoái. Đôi khi cũng có thể gõ HAHAAAAA chẳng hạn cho thêm phần nhấn mạnh.

Giả sử một xâu ký tự được coi là HAHA nếu thỏa mãn các điều kiện:

Ký tự đầu tiên phải là chữ H, ký tự cuối cùng phải là chữ A
Không có hai chữ H nào liền nhau
Cho trước độ dài N, hãy liệt kê tất cả các xâu ký tự HAHA theo thứ tự từ điển.

Input

Dòng đầu ghi số bộ test T (không quá 10)
Mỗi bộ test ghi độ dài N (2 <= N < 16)
Output

Với mỗi bộ test, ghi ra tất cả các xâu HAHA tìm được theo thứ tự từ điển, mỗi xâu viết trên một dòng.
Ví dụ

Input
2
2
4
Output
HA
HAAA
HAHA
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

int n;
vts S;

void back(string s, int i) {
    if (i >= n) {
        S.push_back(s);
    }
    else {
        if (s[i - 1] == 'H') {
            back(s, i + 1);
        }
        else {
            if (i != n - 1) {
                s[i] = 'H';
                back(s, i + 1);
            }
            s[i] = 'A';
            back(s, i + 1);
        }
    }
}

void solution() {
    cin >> n;
    S.clear();
    string s = "H";
    for (int i = 0; i < n - 1; i++) s += "A";
    back(s, 1);
    sort(S.begin(), S.end());
    for (auto i : S) cout << i << endl;
}

int main() {
    faster();
    int T;
    cin >> T;
    while (T--) {
        solution();
    }
    return 0;
}
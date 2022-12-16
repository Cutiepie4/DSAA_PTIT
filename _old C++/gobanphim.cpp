/*
Trong quá trình gõ một dòng văn bản, chúng ta thường sử dụng phím sang trái, sang phải hoặc xóa lùi (backspace). Cho một dãy ký tự mô tả các thao tác gõ phím, trong đó:

Ký tự ‘-’ mô tả phím backspace (xóa lùi). Ký tự ở phía trước con trỏ (nếu có) sẽ bị xóa.
Ký tự ‘<’ mô tả phím di chuyển sang trái. Con trỏ sẽ sang trái 1 ký tự nếu có thể.
Ký tự ‘>’ mô tả phím di chuyển sang phải. Con trỏ sẽ sang phải 1 ký tự nếu có thể.
Các ký tự khác là các chữ cái Tiếng Anh (in hoa hoặc in thường). Bàn phím để ở chế độ Insert. Tức là nếu con trỏ không ở cuối dòng thì khi chèn các ký tự sẽ đẩy các ký tự khác sang phải một vị trí.
Hãy thử tính toán và viết ra kết quả tương ứng.

Input

Có một dòng không quá 106 ký tự mô tả dãy gõ bàn phím.

Output

Ghi ra kết quả.

Ví dụ

Input
<<PI<T>>Ta-

Output
PTIT
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define matrix vector <vector <int>>
#define matrixl vector <vector <ll>>
const ll MOD = 1e9 + 7;

void prs(string s) {
    int index = 0;
    deque <char> dq;
    for (auto i : s) {
        if (i == '<' && index > 0) index--;
        else {
            if (i == '>' && index < dq.size()) index++;
            else {
                if (i == '-' && index > 0) {
                    dq.erase(dq.begin() + index - 1);
                    index--;
                }
                else if (i != '>' && i != '-' && i != '<') {
                    dq.insert(dq.begin() + index, i);
                    index++;
                }
            }
        }
    }
    for (auto i : dq) cout << i;
}

void solution() {
    string s;
    cin >> s;
    prs(s);
}

int main() {
    solution();
}
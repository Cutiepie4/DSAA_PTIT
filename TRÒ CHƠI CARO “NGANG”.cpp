/*
Ai cũng đã biết trò chơi caro với hai ký hiệu X và O. Hai người chơi lần lượt viết ký hiệu của mình lên trên lưới các ô vuông. Một bên được gọi là thắng cuộc nếu có 5 ký hiệu của mình xếp thành một đường thẳng (ngang, dọc, chéo).

Phiên bản caro ngang đơn giản hơn nhiều. Trò chơi chỉ thực hiện trên một đường thẳng với không quá N ô vuông. Luật chơi thay đổi một chút để cho mỗi người chơi có thể “tranh nhau” viết càng nhanh càng tốt ký hiệu của mình, không cần chờ đến lượt.

Khi kết thúc một ván chơi thì tất cả N ô vuông đều đã được điền O hoặc X. Người chơi thắng cuộc khi có dãy ký hiệu giống nhau liên tiếp dài hơn người kia và đảm bảo lớn hơn hoặc bằng 5. Nếu hai người chơi đều có dãy liên tiếp dài nhất bằng nhau thì coi như “hòa”.

Cho số N là số ô vuông thẳng hàng cùng với ký hiệu được lựa chọn. Hãy liệt kê tất cả các trường hợp giúp người chơi có ký hiệu đó thắng cuộc. Các trường hợp cần liệt kê theo thứ tự từ điển.

Input

Dòng đầu ghi số bộ test T (T < 10).

Mỗi bộ test viết trên một dòng số N và ký hiệu c (5 < N < 16; c = ‘O’ hoặc c = ‘X’).

Output

Ghi ra tất cả các trường hợp giúp người chơi có ký hiệu là chữ cái c trong dữ liệu vào thắng cuộc. Các chữ cái đều viết hoa, mỗi trường hợp thắng cuộc ghi trên một dòng.

Ví dụ

Input

1

6 X

Output
OXXXXX

XXXXXO

XXXXXX
*/

#include <bits/stdc++.h>
using namespace std;

vector <vector <string>> Data(16);

void back(string s, int cnto, int cntx, int okx, int oko) {
    if (s.size() == 16) return;
    okx = max(okx, cntx);
    oko = max(oko, cnto);
    if (oko < okx && okx >= 5) Data[s.size()].push_back(s);

    if (s.back() == 'X') {
        back(s + 'X', 0, cntx + 1, okx, oko);
        back(s + 'O', 1, 0, okx, oko);
    }
    else {
        back(s + 'X', 0, 1, okx, oko);
        if (cnto + 1 < 8) back(s + 'O', cnto + 1, 0, okx, oko);
    }
}

void solution() {
    int n;
    char c;
    cin >> n >> c;

    vector <string> tmp;
    if (c == 'X') {
        for (auto i : Data[n]) tmp.push_back(i);
    }
    else {
        for (auto i : Data[n]) {
            for (auto& j : i) {
                if (j == 'X') j = 'O';
                else j = 'X';
            }
            tmp.push_back(i);
        }
    }
    sort(tmp.begin(), tmp.end());
    for (auto i : tmp) cout << i << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    back("", 0, 0, 0, 0);
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}
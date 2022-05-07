/*
Cho chữ cái c in hoa (‘A’ < c < ’K’) và số nguyên K (0 < K < (c – ‘A’)).

Hãy tìm cách  liệt kê tất cả các xâu ký tự khác nhau được tạo ra bởi các chữ cái tính từ ‘A’ đến ký tự c. Các ký tự được phép lặp lại nhưng không tính các xâu là hoán vị của xâu nào đó đã liệt kê trước đó.

Xem ví dụ để hiểu thêm yêu cầu đề bài.

Input

Chỉ có một dòng ghi chữ cái c và số nguyên K thỏa mãn ràng buộc đề bài.

Output
Ghi ra lần lượt các xâu ký tự kết quả theo thứ tự từ điển, mỗi xâu trên một dòng.
Input
D 2

Output
AA
AB
AC
AD
BB
BC
BD
CC
CD
DD
*/
#include <bits/stdc++.h>
using namespace std;

set <string> Data;

void process(char a, char n, int k, string tmp1) {
    if (k == 0) {
        Data.insert(tmp1);
        return;
    }
    for (char i = a; i <= n; i++) {
        string tmp = tmp1;
        tmp.push_back(i);
        process(i, n, k - 1, tmp);
    }
}

int main() {
    char n;
    int k;
    cin >> n >> k;
    for (char i = 'A'; i <= n; i++) {
        string tmp;
        tmp.push_back(i);
        process(i, n, k - 1, tmp);
    }
    for (auto i : Data) cout << i << endl;
}
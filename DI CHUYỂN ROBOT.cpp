/*
Một robot xuất phát từ vị trí (0,0) mặt quay về hướng Bắc. Mỗi lần chỉ có một trong 4 lệnh chuyển động là G, L, R, B tương ứng là tiến về phía trước, tiến sang trái, tiến sang phải, lùi về phía sau một đơn vị.

Cho dãy lệnh chuyển động. Hãy tính xem vị trí cuối cùng của robot là vị trí nào?

Input

Dòng đầu tiên ghi n (n≤100) là số lệnh robot cần thực hiện.
Dòng thứ hai là dãy n ký tự mô tả dãy lệnh robot thực hiện
Output
Ghi ra hai số nguyên là tọa độ (x,y) của vị trí cuối cùng robot
Ví dụ

Input
5
GLLRB
Output
-1 0

Input
2
RG
Output
2 0
*/
#include <bits/stdc++.h>
using namespace std;

void rotate(string& s, int x) {
    // right
    if (x == 1) {
        s.push_back(s.front());
        s.erase(s.begin());
    }
    // left
    else  if (x == -1) {
        s.insert(s.begin(), s.back());
        s.pop_back();
    }
    // back
    else if (x == 0) {
        s.push_back(s.front());
        s.erase(s.begin());
        s.push_back(s.front());
        s.erase(s.begin());
    }
}

void go(int& x, int& y, string& move) {
    int p = move.find('G');
    if (p == 0) y++;
    else if (p == 1) x--;
    else if (p == 2) y--;
    else if (p == 3) x++;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0, y = 0, status;
    string move = "GLBR";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R') {
            rotate(move, 1);
            go(x, y, move);
        }
        else if (s[i] == 'L') {
            rotate(move, -1);
            go(x, y, move);
        }
        else if (s[i] == 'B') {
            rotate(move, 0);
            go(x, y, move);
        }
        else {
            go(x, y, move);
        }
    }
    cout << x << " " << y;
}
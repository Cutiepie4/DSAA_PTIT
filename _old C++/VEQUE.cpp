/*
Input
Chứa số tự nhiên n là số khách hàng đã lên xe (0 ≤ n ≤ 34).
Output
Chứa bản phác họa xe khách như trong test ví dụ.
Kí tự ‘#’ thể hiện ghế chưa có người ngồi, ‘O’ thể hiện ghế đã có
người ngồi, ‘D’ là bác tài xế, các kí tự còn lại thể hiện xe khách.

Example
Input:
20

Output:
+------------------------+

|O.O.O.O.O.O.O.#.#.#.#.|D|)

|O.O.O.O.O.O.#.#.#.#.#.|.|

|O.......................|

|O.O.O.O.O.O.#.#.#.#.#.|.|)

+------------------------+
*/

#include <bits/stdc++.h>
using namespace std;
string a[6] = { "" };
int n;

void prt() {
    for (int i = 0; i < 6; i++) cout << a[i] << endl;
}

void init() {
    for (int i = 0; i < 6; i++) a[i].resize(26);
    a[0] = "+------------------------+";
    a[5] = "+------------------------+";
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < 26; j++) {
            if (j % 2 == 0 || (i == 3 && j != 1)) a[i][j] = '.';
            else a[i][j] = 'O';
        }
    }
    a[1][24] = 'D';
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 26; j++) {
            if (j == 0 || j == 23 || j == 25) a[i][j] = '|';
        }
    }
    a[3][23] = '.';
    a[1].push_back(')');
    a[4].push_back(')');
}

void process(int x) {
    int kt = 0;
    for (int j = 21; j >= 1; j -= 2) {
        if (kt) break;
        for (int i = 4; i >= 1; i--) {
            if (a[i][j] == 'O') {
                a[i][j] = '#'; x--;
            }
            if (x == 0) {
                kt = 1; break;
            }
        }
    }
}

int main() {
    cin >> n;
    int x = 34 - n;

    init();

    if (x != 0) process(x);

    prt();
}
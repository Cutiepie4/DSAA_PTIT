/*
Cho ma trận A[N][M] có các phần tử hoặc là ký tự ‘’O’’ hoặc là ký tự ‘’X’’. Hãy thay thế các miền bao quanh ‘O’ bằng ‘X’. Một miền các ký tự ‘O’ bị bao quang bởi ký tự ‘X’ nếu các ký tự ‘X’ xuất hiện ở phía dưới, phía trên, bên trái, bên phải các ký tự ‘O’. Ví dụ với ma trận dưới đây ta sẽ có kết quả như sau:

X         X         X         X                     X         X         X         X

X         O         X         X                     X         X         X         X

X         O         O         X                     X         X         X         X

X         O         X         X                     X         X         X         X

X         X         O         O                     X         X         O         O

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: Dòng đầu tiên đưa vào hai số N, M ; dòng tiếp là N×M các phần tử của ma trận A[][]; các phần tử được viết cách nhau một vài khoảng trống.
T, N, M thỏa mãn ràng buộc: 1≤T≤100; 1≤ N, M ≤20.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input:
2
1 5
X O X O X 
3 3
X X X
X O X
X X X

OUTPUT:
X O X O X
X X X
X X X
X X X
*/
#include <bits/stdc++.h>
using namespace std;

char a[25][25] = {};

void process(int i, int j) {
    if (a[i - 1][j] == 'O') {
        a[i - 1][j] = '1';
        process(i - 1, j);
    }
    if (a[i + 1][j] == 'O') {
        a[i + 1][j] = '1';
        process(i + 1, j);
    }
    if (a[i][j - 1] == 'O') {
        a[i][j - 1] = '1';
        process(i, j - 1);
    }
    if (a[i][j + 1] == 'O') {
        a[i][j + 1] = '1';
        process(i, j + 1);
    }
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        for (int i = 0; i <= r + 1; i++)
            for (int j = 0; j <= c + 1; j++)
                a[i][j] = '0';
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                cin >> a[i][j];

        for (int i = 1; i <= c; i++) {
            if (a[1][i] == 'O') {
                a[1][i] = '1'; process(1, i);
            }
            if (a[r][i] == 'O') {
                a[r][i] = '1'; process(r, i);
            }
        }
        for (int i = 1; i <= r; i++) {
            if (a[i][1] == 'O') {
                a[i][1] = '1'; process(i, 1);
            }
            if (a[i][c] == 'O') {
                a[i][c] = '1'; process(i, c);
            }
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (a[i][j] == 'O') a[i][j] = 'X';
                if (a[i][j] == '1') a[i][j] = 'O';
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}
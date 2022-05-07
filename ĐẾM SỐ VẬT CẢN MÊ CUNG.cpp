/*
Một mê cung được mô tả dưới dạng ma trận ký tự trong đó dấu ‘.’ là mô tả ô trống, không có vật cản, dấu ‘#’ mô tả một vật cản. Các vật cản sẽ ghép lại với nhau thành vật cản lớn hơn nếu nó liền kề theo hàng hoặc cột.
Hãy đếm xem trong mê cung có bao nhiêu vật cản.
Input
Dong đầu ghi số hai số N, M là số hàng và số cột của mê cung.
N dòng tiếp theo mô tả mê cung trong đó chỉ có các ký tự ‘.’ và ‘#’.
Output
Ghi ra số vật cản đếm được.
Ví dụ
Input
5 6
.#....
..#...
..#..#
...##.
.#....
OUTPUT:
5
*/
#include <bits/stdc++.h>
using namespace std;

void process(vector <vector <char>>& a, int i, int j) {
    if (a[i - 1][j] == '#') {
        a[i - 1][j] = '.';
        process(a, i - 1, j);
    }
    if (a[i][j + 1] == '#') {
        a[i][j + 1] = '.';
        process(a, i, j + 1);
    }
    if (a[i][j - 1] == '#') {
        a[i][j - 1] = '.';
        process(a, i, j - 1);
    }
    if (a[i + 1][j] == '#') {
        a[i + 1][j] = '.';
        process(a, i + 1, j);
    }
}

int main() {
    //input
    int r, c;
    cin >> r >> c;
    vector <vector <char>> a(r + 2, vector <char>(c + 2, '.'));
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> a[i][j];

    //process
    int value = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (a[i][j] == '#') {
                a[i][j] = '.';
                process(a, i, j);
                value++;
            }
        }
    }
    cout << value;
}
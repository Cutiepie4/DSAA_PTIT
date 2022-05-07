/*
Cho ma trận A[N][M] bao gồm các số 0 và 1. Ta gọi mỗi miền của ma trận A[][] là nhóm các số 1 được bao quanh bởi các số 0. Hãy tìm số miền của ma trận. Ví dụ số miền của ma trận A[][] là 4.
Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào N, M là cấp của ma trận A[][]; dòng tiếp theo đưa vào N×M số A[i][j] ; các số được viết cách nhau một vài khoảng trống.
T, M, N, A[i][j] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ M, N ≤100; 0≤ A[i][j] ≤1.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input:
2
3 3
1 1 0 0 0 1 1 0 1
4 4
1 1 0 0 0 0 1 0 0 0 0 1 0 1 0 0

Output:
2
2
*/
#include <bits/stdc++.h>
using namespace std;

int a[102][102] = {};

void process(int i, int j, int& value) {
    for (int z = i - 1; z <= i + 1; z++) {
        for (int q = j - 1; q <= j + 1; q++) {
            if (a[z][q] == 1) {
                a[z][q] = value;
                process(z, q, value);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        //input
        int r, c;
        cin >> r >> c;
        for (int i = 0; i <= 101; i++)
            for (int j = 0; j <= 101; j++)
                a[i][j] = 0;
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                cin >> a[i][j];

        //process
        int value = 2;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (a[i][j] == 1) {
                    a[i][j] = value;
                    process(i, j, value);
                    value++;
                }
            }
        }
        
        cout << value - 2 << endl;
    }
}
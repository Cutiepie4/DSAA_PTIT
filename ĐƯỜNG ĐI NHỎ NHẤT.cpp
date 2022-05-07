/*
Cho bảng A[] kích thước N x M (N hàng, M cột). Bạn được phép đi xuống dưới, đi sang phải và đi xuống ô chéo dưới. Khi đi qua ô (i, j), điểm nhận được bằng A[i][j].

Hãy tìm đường đi từ ô (1, 1) tới ô (N, M) sao cho tổng điểm là nhỏ nhất.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm số nguyên dương N và M.
N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j] (0 ≤ A[i] ≤ 1000).
Output: 

Với mỗi test, in ra độ dài dãy con tăng dài nhất trên một dòng.
Ví dụ:

Input
1
3 3
1 2 3
4 8 2
1 5 3

Output
8
*/
#include <bits/stdc++.h>
using namespace std;

int process(vector <vector <int>>& v, int r, int c) {
    for (int i = 1; i < c; i++) v[0][i] += v[0][i - 1];
    for (int i = 1; i < r; i++) v[i][0] += v[i - 1][0];
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            v[i][j] += min(v[i - 1][j], min(v[i][j - 1], v[i - 1][j - 1]));
        }
    }
    return v[r - 1][c - 1];
}

void init(vector <vector <int>>& v, int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> v[i][j];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector <vector <int>> v(r, vector <int>(c, 0));
        init(v, r, c);
        cout << process(v, r, c) << endl;
    }
}
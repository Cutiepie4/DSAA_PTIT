/*
Cho một bảng số N hàng, M cột chỉ gồm 0 và 1. Bạn hãy tìm hình vuông có kích thước lớn nhất, sao cho các số trong hình vuông toàn là số 1.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test bắt đầu bởi 2 số nguyên N, M (1 ≤ N, M ≤ 500).
N dòng tiếp theo, mỗi dòng gồm M số mô tả một hàng của bảng.
Output: 

Với mỗi test, in ra đáp án là kích thước của hình vuông lớn nhất tìm được trên một dòng.
Ví dụ:

Input:
2
6 5
0 1 1 0 1
1 1 0 1 0
0 1 1 1 0
1 1 1 1 0
1 1 1 1 1
0 0 0 0 0
2 2
0 0
0 0

Output
3
0
*/


#include <bits/stdc++.h>
using namespace std;

int process(vector <vector <int>> a, int r, int c) {
    int ans = 0;
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (a[i][j] == 1) {
                a[i][j] = min(a[i][j - 1], min(a[i - 1][j - 1], a[i - 1][j])) + 1;
                ans = max(ans, a[i][j]);
            }
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector <vector <int>> a(r, vector <int>(c, 0));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> a[i][j];

        cout << process(a, r, c) << endl;
    }
}
/*
Cho một bảng số kích thước N x M. Chi phí khi đi qua ô (i,j) bằng A[i][j]. Nhiệm vụ của bạn là hãy tìm một đường đi từ ô (1, 1) tới ô (N, M) sao cho chi phí là nhỏ nhất. Tại mỗi ô, bạn được phép đi sang trái, sang phải, đi lên trên và xuống dưới.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test bắt đầu bởi hai số nguyên N và M (1 ≤ N, M ≤ 500).
N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j] (0 ≤ A[i][j] ≤ 9).
Output:

Với mỗi test, in ra một số nguyên là chi phí nhỏ nhất cho đường đi tìm được.


Ví dụ:

Input:
3
4
5
0 3 1 2 9
7 3 4 9 9
1 7 5 5 3
2 3 4 2 5
1
6
0 1 2 3 4 5
5 5
1 1 1 9 9
9 9 1 9 9
1 1 1 9 9
1 9 9 9 9
1 1 1 1 1
Output:
24
15
13
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vt vector <int>
#define pi pair <int,pair <int,int>>
#define matrix vector <vector <int>>

const int X[] = { 1, 0, -1, 0 };
const int Y[] = { 0, 1, 0, -1 };

int r, c;
matrix M;

void Dijkstra() {
    matrix D(r, vt(c, 1e9));
    priority_queue <pi, vector <pi>, greater <pi>> Q;
    D[0][0] = M[0][0];
    Q.push({ D[0][0], {0,0} });

    while (!Q.empty()) {
        int x = Q.top().second.first, y = Q.top().second.second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int x1 = x + X[i], y1 = y + Y[i];
            if (x1 >= 0 && y1 >= 0 && x1 < r && y1 < c && D[x1][y1] > D[x][y] + M[x1][y1]) {
                D[x1][y1] = D[x][y] + M[x1][y1];
                Q.push({ D[x1][y1], {x1,y1} });
            }
        }
    }
    cout << D[r - 1][c - 1];
}

void solution() {
    cin >> r >> c;
    M = matrix(r, vt(c + 1));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> M[i][j];
    Dijkstra();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solution();
        cout << endl;
    }
    return 0;
}
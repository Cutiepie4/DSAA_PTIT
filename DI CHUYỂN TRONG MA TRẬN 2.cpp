/*
Cho ma trận A[M][N]. Nhiệm vụ của bạn hãy tìm số bước đi ít nhất dịch chuyển từ vị trí A[1][1] đến vị trí A[M][N]. Biết mỗi bước đi ta chỉ được phép dịch chuyển đến vị trí A[i][j+A[i][j]] hoặc vị trí A[i+A[i][j]][j] bên trong ma trận.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số M, N; phần thứ hai là các phần tử của ma trận A[][]; các số được viết cách nhau một vài khoảng trống.
T, M, N, A[i][j] thỏa mãn ràng buộc: 1≤T≤100; 1≤M, N, A[i][j]≤103.
Output:

Đưa ra kết quả mỗi test theo từng dòng. In ra -1 nếu không tìm được đáp án.
Ví dụ:

Input
1
3  3
2  1  2
1  1  1
1  1  1

Output
2
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <int>

int r, c;
matrix M, mark;

int bfs() {
    queue <pair <pair <int, int>, int>> Q;
    Q.push({ { 0,0 }, 0 });
    while (!Q.empty()) {
        int x = Q.front().first.first, y = Q.front().first.second, z = Q.front().second;
        Q.pop();
        if (x == r - 1 && y == c - 1) return z;

        if (x + M[x][y] < r && mark[x + M[x][y]][y]) {
            Q.push({ { x + M[x][y], y }, z + 1 });
            mark[x + M[x][y]][y] = 0;
        }
        if (y + M[x][y] < c && mark[x][y + M[x][y]]) {
            Q.push({ { x, y + M[x][y] }, z + 1 });
            mark[x][y + M[x][y]] = 0;
        }
    }
    return -1;
}

void solution() {
    cin >> r >> c;
    M = matrix(r, vt(c));
    mark = matrix(r, vt(c, 1));

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> M[i][j];

    cout << bfs();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}
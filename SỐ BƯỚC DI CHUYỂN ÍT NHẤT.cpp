/*
Cho ma trận A kích thước N*M.

Hãy tìm số bước đi ít nhất để di chuyển từ vị trí A[1][1] đến vị trí A[N][M].

Biết rằng mỗi bước từ vị trí (i, j) ta có thể di chuyển theo một trong ba hướng:

Hướng xuống dưới với số ô di chuyển là hiệu hai giá trị A[i][j] và A[i+1][j]
Hướng sang phải với số ô di chuyển là hiệu hai giá trị A[i][j] và A[i][j+1]
Hướng chéo xuống với số ô di chuyển là hiệu của hai giá trị A[i][j] và A[i+1][j+1]
Input:

Dòng đầu tiên đưa vào số lượng test T.
Dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số N, M; phần thứ hai là các phần tử của ma trận A[][]; các số được viết cách nhau một vài khoảng trống.
T, N, M, A[i][j] thỏa mãn ràng buộc: 1≤T≤100; 1≤ N, M, A[i][j]≤103.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Nếu không tìm được đường đi ghi ra -1
Ví dụ:

Input
1
3 3
2 1 2
1 2 4
1 3 2

Output
3
*/
#include <bits/stdc++.h>
using namespace std;
#define vt vector <int>
#define mt vector <vt>

struct point {
    int x, y;
    point() {}
    point(int a, int b) {
        x = a;
        y = b;
    }
};

int r, c;
mt M;

int bfs() {
    int ans = -1;
    point P;
    mt mark = mt(1001, vt(1001, 1));
    queue <pair <point, int>> Q;
    Q.push({ {0,0}, 0 });

    while (!Q.empty()) {
        P = Q.front().first;
        int cnt = Q.front().second;
        Q.pop();
        if (P.x == r - 1 && P.y == c - 1) return cnt;

        int step;
        // right
        step = abs(M[P.x][P.y] - M[P.x][P.y + 1]);
        if (P.y + step >= 0 && P.y + step < c && mark[P.x][P.y + step]) {
            Q.push({ {P.x, P.y + step}, cnt + 1 });
            mark[P.x][P.y + step] = 0;
        }

        // down
        step = abs(M[P.x][P.y] - M[P.x + 1][P.y]);
        if (P.x + step >= 0 && P.x + step < r && mark[P.x + step][P.y]) {
            Q.push({ {P.x + step, P.y}, cnt + 1 });
            mark[P.x + step][P.y] = 0;
        }

        //diagonal
        step = abs(M[P.x][P.y] - M[P.x + 1][P.y + 1]);
        if (P.x + step >= 0 && P.x + step < r && P.y + step >= 0 && P.y + step < c && mark[P.x + step][P.y + step]) {
            Q.push({ {P.x + step, P.y + step}, cnt + 1 });
            mark[P.x + step][P.y + step] = 0;
        }
    }
    return -1;
}

void solution() {
    cin >> r >> c;
    M = mt(1001, vt(1001));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> M[i][j];

    cout << bfs();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}
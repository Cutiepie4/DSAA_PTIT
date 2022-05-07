/*
Cho một bảng kích thước N x N, trong đó có các ô trống ‘.’ và vật cản ‘X’. Các hàng và các cột được đánh số từ 0.

Mỗi bước di chuyển, bạn có thể đi từ ô (x, y) tới ô (u, v) nếu như 2 ô này nằm trên cùng một hàng hoặc một cột, và không có vật cản nào ở giữa.

Cho điểm xuất phát và điểm đích. Bạn hãy tính số bước di chuyển ít nhất?

Input:

Dòng đầu ghi số bộ test (không quá 10). Mỗi test gồm:
Dòng đầu tiên là số nguyên dương N (1 ≤ N ≤ 100).
N dòng tiếp theo, mỗi dòng gồm N kí tự mô tả bảng.
Cuối cùng là 4 số nguyên a, b, c, d với (a, b) là tọa độ điểm xuất phát, (c, d) là tọa độ đích. Dữ liệu đảm bảo hai vị trí này không phải là ô có vật cản.
 

Output: 

Với mỗi test, in ra một số nguyên là đáp số của bài toán.
Ví dụ:
Input
1
3
.X.
.X.
...
0 0 0 2
Output
3
*/
#include <bits/stdc++.h>
using namespace std;
#define pi pair <int,int>
#define mt vector <vector <int>>
#define f first
#define s second

int n;
char H[101][101];

int letsgo(pi st, pi en) {
    queue <pair <pi, int>> Q;
    Q.push({ st, 0 });
    mt mark(n, vector <int>(n, 1));
    mark[st.f][st.s] = 0;

    while (!Q.empty()) {
        pi x = Q.front().f;
        int cnt = Q.front().s;
        Q.pop();
        if (x == en) return cnt;

        for (int r = x.f + 1; r < n; r++) {
            if (H[r][x.s] == '.' && mark[r][x.s]) {
                Q.push({ {r, x.s}, cnt + 1 });
                mark[r][x.s] = 0;
            }
            if(H[r][x.s] == 'X') break;
        }
        for (int r = x.f - 1; r >= 0; r--) {
            if (H[r][x.s] == '.' && mark[r][x.s]) {
                Q.push({ {r, x.s}, cnt + 1 });
                mark[r][x.s] = 0;
            }
            if(H[r][x.s] == 'X') break;
        }
        for (int c = x.s + 1; c < n; c++) {
            if (H[x.f][c] == '.' && mark[x.f][c]) {
                Q.push({ {x.f, c}, cnt + 1 });
                mark[x.f][c] = 0;
            }
            if(H[x.f][c] == 'X') break;
        }
        for (int c = x.s - 1; c >= 0; c--) {
            if (H[x.f][c] == '.' && mark[x.f][c]) {
                Q.push({ {x.f, c}, cnt + 1 });
                mark[x.f][c] = 0;
            }
            if(H[x.f][c] == 'X') break;
        }
    }
    return -1;
}

void solution() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> H[i][j];
    pi st, en;
    cin >> st.first >> st.second >> en.first >> en.second;
    cout << letsgo(st, en);
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
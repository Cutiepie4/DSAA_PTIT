#include <bits/stdc++.h>
using namespace std;
#define mt vector <vector <int>>

int n, e, ok;
mt M;  // first: previous vertex, second: value
vector <int> Pv, D;  // D: distance from start to current vertex, Pv: Previous vertex of this index

/*
Duyệt lần lượt các đỉnh, xem có những đỉnh nào có thể đi đến đỉnh
hiện tại, cập nhật khoảng cách từ đỉnh xuất phát tới đỉnh hiện tại
bằng (khoảng cách từ đỉnh đó đến đỉnh hiện tại + khoảng cách từ đỉnh xuất phát tới đỉnh đó)
Khi không còn thay đổi thì dừng
*/

void Bellman_Ford(int s = 1) {
    D[s] = ok = 0;
    while (!ok) {
        ok = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (D[i] > M[j][i] + D[j]) {
                    ok = 0;
                    D[i] = M[j][i] + D[j];
                    Pv[i] = j;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << i << ": " << D[i] << "|" << Pv[i] << endl;
    }
}

int main() {
    cin >> n >> e;
    M = mt(n + 1, vector <int>(n + 1, 100));
    Pv = vector <int>(n + 1, 0);
    D = vector <int>(n + 1, 1e9);
    for (int i = 1; i <= n; i++) M[i][i] = 0;

    for (int i = 0, a, b, c; i < e; i++) {
        cin >> a >> b >> c;
        M[b][a] = M[a][b] = c;
    }
    Bellman_Ford(2);
}
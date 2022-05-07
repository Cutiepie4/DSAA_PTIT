/*
Cho một hình hộp chữ nhật có kích thước A x B x C, trong đó A là chiều cao, B là chiều rộng và C là chiều dài. Mỗi ô có thể là một ô trống ‘.’ hoặc vật cản ‘#’.

Mỗi bước, bạn được phép di chuyển sang một ô kề bên cạnh (không được đi chéo). Nhiệm vụ của bạn là tìm đường đi ngắn nhất bắt đầu ‘S’ tới vị trí kết thúc ‘E’.

Input:

Dòng đầu tiên là số lượng bộ test T (1 ≤ N ≤ 50).
Mỗi test bắt đầu bởi 3 số nguyên A, B, C (A, B, C ≤ 30).
Tiếp theo là A khối, mỗi khối gồm B x C kí tự mô tả một lát cắt của hình hộp chữ nhật. Giữa 2 khối có một dấu xuống dòng.
Output:

In ra một số nguyên là đường đi ngắn nhất từ S tới E. Nếu không di chuyển được, in ra -1.
Ví dụ:



Input
2
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

Output
11

-1

*/
#include <bits/stdc++.h>
using namespace std;
#define mt3d vector <vector <vector <int>>>
#define vt vector <int>

const int X[] = { 1, -1, 0, 0, 0, 0 };
const int Y[] = { 0, 0, 1, -1, 0, 0 };
const int Z[] = { 0, 0, 0, 0, 1, -1 };

char H[35][35][35];
int x, y, z;

struct cube {
    int x, y, z;
};

int letsgo(cube st) {
    queue <pair <cube, int>> Q;
    mt3d mark(x, vector <vt>(y, vt(z, 1)));
    Q.push({ st, 0 });

    while (!Q.empty()) {
        cube c = Q.front().first;
        int cnt = Q.front().second;
        Q.pop();
        if (H[c.x][c.y][c.z] == 'E') return cnt;

        for (int i = 0; i < 6; i++) {
            int t1 = c.x + X[i], t2 = c.y + Y[i], t3 = c.z + Z[i];
            if (t1 >= 0 && t1 < x && t2 >= 0 && t2 < y && t3 >= 0 && t3 < z && mark[t1][t2][t3] && H[t1][t2][t3] != '#') {
                mark[t1][t2][t3] = 0;
                Q.push({ { t1,t2,t3 }, cnt + 1 });
            }
        }
    }
    return -1;
}

void solution() {
    cin >> x >> y >> z;
    cube st;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cin >> H[i][j][k];
                if (H[i][j][k] == 'S') {
                    st = { i,j,k };
                }
            }
        }
    }

    cout << letsgo(st);
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
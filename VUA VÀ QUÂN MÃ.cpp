/*
1 lượt đi là tất cả các quân cờ đều di chuyển
đếm số lượt đi ít nhất để tất cả gặp nhau
*/
#include <bits/stdc++.h>
using namespace std;
#define vt vector <int>
#define mt vector <vt>
#define point pair <int,int>

const int Xk[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int Yk[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int X[] = { 1, 2, -1, 2, 1, -2, -1, -2 };
const int Y[] = { 2, 1, 2, -1, -2, 1, -2, -1 };

int n;
mt M, Data;
vector <point> Knight;
point King;

void bfs_knight(point st) {
    mt mark(n, vt(n, 1));
    queue <pair <point, int>> Q;
    Q.push({ st, 0 });

    while (Q.size()) {
        point curr = Q.front().first;
        int cnt = Q.front().second;
        Q.pop();

        Data[curr.first][curr.second] = max(Data[curr.first][curr.second], cnt);
        for (int i = 0; i < 8; i++) {
            int x = curr.first + X[i], y = curr.second + Y[i];
            if (x >= 0 && x < n && y >= 0 && y < n && mark[x][y] && M[x][y]) {
                mark[x][y] = 0;
                Q.push({ {x,y} , cnt + 1 });
            }
        }
    }
}

int bfs_king(point st) {
    int Min = 100;
    mt mark(n, vt(n, 1));
    queue <pair <point, int>> Q;
    Q.push({ st, 0 });

    while (Q.size()) {
        point curr = Q.front().first;
        int cnt = Q.front().second;
        Q.pop();

        if (Data[curr.first][curr.second != -1]) {
            Data[curr.first][curr.second] = max(Data[curr.first][curr.second], cnt);
            Min = min(Data[curr.first][curr.second], Min);
        }
        for (int i = 0; i < 8; i++) {
            int x = curr.first + Xk[i], y = curr.second + Yk[i];
            if (x >= 0 && x < n && y >= 0 && y < n && mark[x][y] && M[x][y]) {
                mark[x][y] = 0;
                Q.push({ {x,y} , cnt + 1 });
            }
        }
    }

    return Min;
}

void init() {
    cin >> n;
    M = mt(n, vt(n, 0));
    Data = mt(n, vt(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c != '#') M[i][j] = 1;
            if (c == '#') M[i][j] = 0;
            if (c == 'T') King = { i,j };
            if (c == 'M') Knight.push_back({ i,j });
        }
    }
}

int main() {
    init();
    for (auto i : Knight) bfs_knight(i);
    cout << bfs_king(King);
}
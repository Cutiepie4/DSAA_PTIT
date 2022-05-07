/*
Cho một quân mã trên bàn cờ vua tại vị trí ST. Nhiệm vụ của bạn là hãy tìm số bước di chuyển ít nhất để đưa quân mã tới vị trí EN.



Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm 2 xâu dạng “xy” và “uv”, trong đó x, y là kí tự trong “abcdefgh” còn y, v là số thuộc 1, 2, 3, 4, 5, 6, 7, 8.

Output:

Với mỗi test, in ra đáp án tìm được trên một dòng.

Ví dụ:
Input:
8
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6

Output
2
4
2
6
5
6
1
0
*/
#include <bits/stdc++.h>
using namespace std;
#define mt vector <vector <int>>
#define f first
#define s second

const int X[] = { 1, 2, -1, 2, 1, -2, -1, -2 };
const int Y[] = { 2, 1, 2, -1, -2, 1, -2, -1 };
const string ROW = "abcdefgh";
mt Table, mark;

int bfs(pair <int, int> st, pair <int, int> en) {
    queue <pair <pair <int, int>, int>> Q;
    Q.push({ st, 0 });
    Table[st.f][st.s] = 0;

    while (1) {
        int r = Q.front().f.f, c = Q.front().f.s;
        int cnt = Q.front().s;
        Q.pop();
        if (r == en.f && c == en.s) return cnt;

        for (int i = 0; i < 8; i++) {
            int x = r + X[i], y = c + Y[i];
            if (x >= 0 && x < 8 && y >= 0 && y < 8 && Table[x][y]) {
                Q.push({ { x,y }, cnt + 1 });
                Table[x][y] = 0;
            }
        }
    }
}

void solution() {
    string a, b;
    cin >> a >> b;
    Table = mt(8, vector <int>(8, 1));
    pair <int, int> st, en;
    st.first = ROW.find(a[0]), st.second = a[1] - '0' - 1;
    en.first = ROW.find(b[0]), en.second = b[1] - '0' - 1;
    cout << bfs(st, en);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}
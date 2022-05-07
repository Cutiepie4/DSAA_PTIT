/*
Cho một bảng S[][] kích thước N x M, bao gồm các ô trống, các vật cản. Ban đầu bạn ở vị trí S. Nhiệm vụ của bạn là hãy di chuyển tới vị trí T, sao cho số lần đổi hướng không quá hai lần.
Input:
Dòng đầu tiên là số lượng bộ test T (T <= 20).
Mỗi test bắt đầu bởi hai số nguyên N và M (1 <= N, M <= 500).
N dòng tiếp theo, mỗi dòng gồm M kí tự mô tả bảng S. Trong đó: ‘.’ là một ô trống, ‘*’ là vật cản, ‘S’ là vị trí xuất phát và ‘T’ là vị trí đích. (Chỉ có một vị trí S và T duy nhất).
Output: 
Với mỗi test, in ra “YES” nếu tìm được đường đi, ra in “NO” trong trường hợp ngược lại.
Test ví dụ:
Input:
2
5 5
..S..
****.
T....
****.
.....
5 5
S....
****.
.....
.****
..T..

OUTPUT:
YES
NO
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define matrix vector <vector <int>>
#define matrixl vector <vector <ll>>
const ll MOD = 1e9 + 7;

struct f {
    int s, cnt;
    pair <int, int> p;
};

int r, c, s1, s2, d1, d2, check = 1;
vts M;

void dfs(matrix& mark, f tmp) {
    if (check == 0) return;
    int x = tmp.p.first, y = tmp.p.second;
    mark[x][y] = 0;
    if (x == d1 && y == d2) {
        check = 0;
        cout << "YES" << endl;
        return;
    }
    if (x > 0 && M[x - 1][y] != '*' && mark[x - 1][y]) {
        f temp;
        if (tmp.s != 2 && tmp.s != 0) temp.cnt = tmp.cnt + 1;
        else temp.cnt = tmp.cnt;
        if (temp.cnt < 3) {
            temp.s = 2, temp.p.first = x - 1, temp.p.second = y;
            dfs(mark, temp);
            mark[x - 1][y] = 1;
        }
    }
    if (y > 0 && M[x][y - 1] != '*' && mark[x][y - 1]) {
        f temp;
        if (tmp.s != 4 && tmp.s != 0) temp.cnt = tmp.cnt + 1;
        else temp.cnt = tmp.cnt;
        if (temp.cnt < 3) {
            temp.s = 4, temp.p.first = x, temp.p.second = y - 1;
            dfs(mark, temp);
            mark[x][y - 1] = 1;
        }
    }
    if (x < r - 1 && M[x + 1][y] != '*' && mark[x + 1][y]) {
        f temp;
        if (tmp.s != 8 && tmp.s != 0) temp.cnt = tmp.cnt + 1;
        else temp.cnt = tmp.cnt;
        if (temp.cnt < 3) {
            temp.s = 8, temp.p.first = x + 1, temp.p.second = y;
            dfs(mark, temp);
            mark[x + 1][y] = 1;
        }
    }
    if (y < c - 1 && M[x][y + 1] != '*' && mark[x][y + 1]) {
        f temp;
        if (tmp.s != 6 && tmp.s != 0) temp.cnt = tmp.cnt + 1;
        else temp.cnt = tmp.cnt;
        if (temp.cnt < 3) {
            temp.s = 6, temp.p.first = x, temp.p.second = y + 1;
            dfs(mark, temp);
            mark[x][y + 1] = 1;
        }
    }
}

void find_path() {
    matrix mark(r, vt(c, 1));
    f tmp;
    tmp.s = 0, tmp.p.first = s1, tmp.p.second = s2, tmp.cnt = 0;
    dfs(mark, tmp);
    if (check) cout << "NO" << endl;
}

void solution() {
    cin >> r >> c;
    check = 1;
    M = vts(r);
    for (int i = 0; i < r; i++) {
        cin >> M[i];
        for (int j = 0; j < c; j++) {
            if (M[i][j] == 'S') s1 = i, s2 = j;
            else if (M[i][j] == 'T') d1 = i, d2 = j;
        }
    }
    find_path();
}

int main() {
    faster();
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}
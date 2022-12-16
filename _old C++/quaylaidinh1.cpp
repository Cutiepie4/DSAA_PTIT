/*
Cho đồ thị có hướng với N đỉnh và M cạnh. 
Người ta muốn thực hiện hành trình với hai bước di chuyển sau:

- Bước 1: tìm đường đi từ đỉnh 1 qua các cạnh đến đỉnh 2.

- Bước 2: từ đỉnh 2 lại đi qua các cạnh nào đó để quay lại đỉnh 1.

Không có cạnh nào được đi qua 2 lần. Hãy tính xem  số đỉnh ít nhất cần phải đi qua trong hành trình đó là bao nhiêu.


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

int n, e;
matrix M;

int intersec(vt& a, vt& b) {
    set <int> D;
    for (auto i : a) D.insert(i);
    for (auto i : b) D.insert(i);
    return D.size();
}

void dfs(int s, int d, vt mark, vt path, matrix& Path) {
    mark[s] = 0;
    if (s == d) {
        Path.push_back(path);
        return;
    }
    path.push_back(s);
    for (auto i : M[s]) {
        if (mark[i]) {
            dfs(i, d, mark, path, Path);
        }
    }
}

void process() {
    int ans = INT32_MAX;
    matrix Path1, Path2;
    vt mark(n + 1, 1), path;
    dfs(1, 2, mark, path, Path1);
    path.clear();
    dfs(2, 1, mark, path, Path2);
    for (auto i : Path1) {
        for (auto j : Path2) {
            ans = min(ans, intersec(i, j));
        }
    }
    cout << ans << endl;
}

void solution() {
    cin >> n >> e;
    M = matrix(n + 1);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
    }
    process();
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
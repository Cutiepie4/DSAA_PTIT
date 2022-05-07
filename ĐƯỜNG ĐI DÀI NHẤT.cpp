/*
Cho đồ thị vô hướng có N đỉnh và M cạnh. Bạn hãy tìm đường đi dài nhất trên đồ thị, sao cho mỗi cạnh chỉ được đi qua nhiều nhất 1 lần.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 10). Mỗi test bắt đầu bằng số nguyên N và M (1 ≤ N, M ≤ 20). Các đỉnh đánh dấu từ 0, 1, …, N-1. M dòng tiếp theo, mỗi dòng gồm 2 số u, v cho biết có cạnh nối giữa uàv.

Output: Với mỗi test, in ra đáp án tìm được, mỗi xâu in ra trên một dòng.

Ví dụ

Input
2
3 2
0 1
1 2
15 16
0 2
1 2
2 3
3 4
3 5
4 6
5 7
6 8
7 8
7 9
8 10
9 11
10 12
11 12
10 13
12 14

Output
2
12
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define pi pair <int,int>
#define matrix vector <vt>
#define matrixl vector <vtl>
const int MOD = 1e9 + 7;

int n, e, ans;
vt v, mark;
matrix M, E;

void dfs(int u, int cnt) {
    ans = max(ans, cnt);
    for (auto i : M[u]) {
        if (E[u][i]) {
            E[u][i] = 0;
            E[i][u] = 0;
            dfs(i, cnt + 1);
            E[u][i] = 1;
            E[i][u] = 1;
        }
    }
}

void solution() {
    ans = 0;
    cin >> n >> e;
    M = matrix(n + 1);
    E = matrix(n + 1, vt(n + 1, 0));
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
        E[a][b] = 1;
        E[b][a] = 1;
    }
    for (int i = 0; i <= n; i++) dfs(i, 0);
    cout << ans;
}

int main() {
    faster();
    int T;
    cin >> T;
    while (T--) {
        solution();
        cout << endl;
    }
    return 0;
}
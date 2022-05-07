/*
Cho đồ thị có hướng liên thông G có N đỉnh và M cạnh. 
Với một cặp đỉnh (u,v), đỉnh thắt của p đỉnh này được 
định nghĩa là một đỉnh mà tất cả đưng đi từ u tới v 
đều đi qua nó.

Hãy đếm số đỉnh thắt với cặp đỉnh (u,v).
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

int n, e, s, d;
matrix M;
set <int> D;

int bfs(int k) {
    vt mark(n + 1, 1);
    queue <int> q;
    q.push(s);
    mark[s] = 0, mark[k] = 0;
    while (!q.empty()) {
        int x = q.front();
        if (x == d) return 0;
        q.pop();
        for (auto i : M[x]) {
            if (mark[i]) {
                mark[i] = 0;
                q.push(i);
            }
        }
    }
    return 1;
}

void prs() {
    int ans = 0;
    for (auto i : D) {
        if (bfs(i)) ans++;
    }
    cout << ans << endl;
}

void merge(vt path) {
    path.erase(path.begin());
    for (auto i : path) D.insert(i);
}

void dfs(int x, vt mark, vt path) {
    mark[x] = 0;
    if (x == d) {
        merge(path);
        return;
    }
    path.push_back(x);
    for (auto i : M[x]) {
        if (mark[i]) {
            dfs(i, mark, path);
        }
    }
}

void solution() {
    cin >> n >> e >> s >> d;
    M = matrix(n + 1);
    vt mark(n + 1, 1);
    vt path;
    D.clear();
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
    }
    dfs(s, mark, path);
    prs();
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
/*
Cho đồ thị có hướng liên thông G có N đỉnh và M cạnh. 
Với một cặp đỉnh (u,v), đỉnh thắt củp đỉnh này được 
định nghĩa là một đỉnh mà tất cả đưng đi từ u tới v 
đều đi qua nó.

Hãy đếm số đỉnh thắt với cặp đỉnh (u,v).
*/
#include <bits/stdc++.h>
using namespace std;
#define vt vector <int>
#define matrix vector <vector <int>>

int n, e, s, d;
matrix M;
set <int> D;

int bfs(int k) { //  xoá thử đỉnh đó đi xem có đường đi từ s đến d ko
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

void merge(vt path) { // tìm tất cả các đỉnh đi qua từ s đến d
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
    vt mark(n + 1, 1), path;
    D.clear();
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
    }

    dfs(s, mark, path);

    int ans = 0;
    for (auto i : D) {
        if (bfs(i)) ans++;
    }
    cout << ans;
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
#include <bits/stdc++.h>
using namespace std;
#define matrix vector <vector <int>>

int n, e, ok;
matrix M;
vector <int> mark;

void dfs(int x, int s, int cnt) {
    mark[x] = 0;
    for (auto i : M[x]) {
        if (i == s && cnt > 2) {
            ok = 1;
            return;
        }
        if (mark[i]) {
            dfs(i, s, cnt + 1);
        }
    }
}

void solution() {
    ok = 0;
    cin >> n >> e;
    M = matrix(n + 1);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        mark = vector <int>(n + 1, 1);
        dfs(i, i, 1);
        if (ok) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define vt vector <int>
#define mt vector <vt>

mt M;
int n, e;
vt mark;

void dfs(int x) {
    mark[x] = 0;
    for (auto i : M[x]) {
        if (mark[i]) {
            dfs(i);
        }
    }
}

int tplt(int del) {
    int ans = 0;
    mark = vt(n + 1, 1);
    mark[del] = 0;
    for (int i = 1; i <= n; i++) {
        if (mark[i]) {
            dfs(i);
            ans++;
        }
    }
    return ans;
}

void solution() {
    int x = 1, node = 0;
    cin >> n >> e;
    M = mt(n + 1);
    mark = vt(n + 1, 1);
    for (int i = 0, u, v; i < e; i++) {
        cin >> u >> v;
        M[u].push_back(v);
        M[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        int tmp = tplt(i);
        if (tmp > x) {
            node = i;
            x = tmp;
        }
    }
    cout << node;
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
#include <bits/stdc++.h>
using namespace std;
#define vt vector <int>
#define mt vector <vt>

int n, e, cnt_tplt;
mt M;
vt mark;
vector <pair <int, int>> edge;

void dfs1(int x, int u, int v) {
    mark[x] = 0;
    for (auto i : M[x]) {
        if (mark[i] && ((x != u && x != v) || (i != u && i != v))) {
            dfs1(i, u, v);
        }
    }
}

void dfs(int x) {
    mark[x] = 0;
    for (auto i : M[x]) {
        if (mark[i]) {
            dfs(i);
        }
    }
}

int tplt() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (mark[i]) {
            dfs(i);
            ans++;
        }
    }
    return ans;
}

int canhcau() {
    int ans = 0;
    for (auto i : edge) {
        mark = vt(n + 1, 1);
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (mark[j]) {
                dfs1(j, i.first, i.second);
                cnt++;
            }
        }
        if (cnt > cnt_tplt) ans++;
    }
    return ans;
}

int dinhtru() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        mark = vt(n + 1, 1);
        mark[i] = 0;
        if (cnt_tplt < tplt()) ans++;
    }
    return ans;
}

void solution() {
    cin >> n >> e;
    edge.clear();
    M = mt(n + 1);
    mark = vt(n + 1, 1);
    for (int i = 0, u, v; i < e; i++) {
        cin >> u >> v;
        edge.push_back({ u,v });
        M[u].push_back(v);
        M[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) sort(M[i].begin(), M[i].end());
    cnt_tplt = tplt();
    cout << dinhtru() << " " << canhcau();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solution();
}
#include <bits/stdc++.h>
using namespace std;

struct node {
    int w, v;
    node(int a, int b) {
        w = a, v = b;
    }
};

int n, m;
vector <vector <node>> M;
vector <int> Prv;

int Prim(int st = 1) {
    int ans = 0;
    set <node> S;
    vector <node> D(n + 1); // Data
    vector <int> mark(n + 1); // đánh 

    for (int i = 1; i <= n; i++) {
        D[i] = node(1e9, i);
    }
    Prv[st] = st;
    D[st] = node(0, st);
    for (int i = 1; i <= n; i++) {
        S.insert(D[i]);
    }

    while (!S.empty()) {
        int u = S.begin()->v;
        mark[u] = 0;
        ans += S.begin()->w;
        S.erase(S.begin());

        for (auto i : M[u]) {
            int v = i.v, w = i.w;
            if (mark[v] && D[v].w > w) {
                S.erase(D[v]);
                D[v].w = w;
                S.insert(D[v]);
                Prv[v] = u;
            }
        }
    }
    return ans;
}

void solution() {
    int st;
    cin >> n >> m >> st;
    M = vector <vector <node>>(n + 1);
    Prv = vector <int>(n + 1, 0);

    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        M[u].push_back({ w,v });
        M[v].push_back({ w,u });
    }
    cout << Prim(st);
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
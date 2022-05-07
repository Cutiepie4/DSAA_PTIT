#include <bits/stdc++.h>
using namespace std;
#define mt vector <vector <int>>

int n, e;
mt W = mt(101, vector <int>(101, 1e9));

void Floyd() {
    for (int k = 1; k <= n; k++) { //i -> j = min(i->k, k->j) with all k
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                W[i][j] = min(W[i][j], W[i][k] + W[k][j]);
            }
        }
    }
}

void Ans() {
    int t;
    cin >> t;
    while (t--) {
        int u, v;
        cin >> u >> v;
        cout << W[u][v] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> e;
    for (int i = 0, u, v, w; i < e; i++) {
        cin >> u >> v >> w;
        W[u][v] = W[v][u] = w;
    }
    for (int i = 1; i <= n; i++) W[i][i] = 0;
    Floyd();
    Ans();
}
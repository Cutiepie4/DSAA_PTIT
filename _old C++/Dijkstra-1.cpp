#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define pi pair <int,int>
#define matrix vector <vt>
const int MOD = 1e9 + 7;

int n, e, s;
vector <vector <pi>> M;

void Dijktra(int s) {
    priority_queue <pi, vector <pi>, greater <pi>> Q;
    vt D(n + 1, 1e9), prv(n + 1, -1);
    D[s] = 0;
    Q.push({ 0,s });
    while (!Q.empty()) {
        int u = Q.top().second;
        Q.pop();

        for (auto i : M[u]) {
            int Duv = i.first, v = i.second;
            if (D[u] + Duv < D[v]) {
                D[v] = D[u] + Duv;
                prv[v] = u;
                Q.push({ D[v], v });
            }
        }
    }
    for (auto i = 1; i <= n; i++) cout << D[i] << " ";
}

void solution() {
    cin >> n >> e >> s;
    M = vector <vector <pi>>(n + 1);
    for (int i = 0, u, v, k; i < e; i++) {
        cin >> u >> v >> k;
        M[u].push_back({ k,v });
        M[v].push_back({ k,u });
    }
    Dijktra(s);
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
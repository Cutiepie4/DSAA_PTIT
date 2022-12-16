#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define fi first
#define se second
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define matrix vector <vector <int>>
#define matrixl vector <vector <ll>>
const ll MOD = 1e9 + 7;

matrix M;
int n, e;
vt v;

int bfs() {
    vt mark(n + 1, 1);
    queue <int> q;
    q.push(1);
    v[1] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        mark[x] = 0;
        if (M[x].size() == 0) return 0;
        for (auto i : M[x]) {
            if (mark[i]) {
                if (v[i] == -1) v[i] = 1 - v[x];
                else if (v[i] == v[x]) return 0;
                q.push(i);
            }
        }
    }
    return 1;
}

void solution() {
    cin >> n >> e;
    v = vt(n + 1, -1);
    M = matrix(n + 1);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    if (bfs()) cout << "YES" << endl;
    else cout << "NO" << endl;
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
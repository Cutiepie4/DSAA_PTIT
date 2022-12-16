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

int bfs(int s) {
    vt mark(n + 1, 1);
    queue <int> q;
    q.push(s);
    mark[s] = 2;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        mark[x] = 0;
        for (auto i : M[x]) {
            if (mark[i] == 1) {
                q.push(i);
                mark[i] = 2;
            }
            else if (mark[i] == 2) return 1;
        }
    }
    return 0;
}

void solution() {
    cin >> n >> e;
    M = matrix(n + 1);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (bfs(i)) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
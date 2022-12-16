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

int n, e, lt;
matrix M;
vector <pair <int, int>> E;

void bfs(int s, int a1, int a2, vt& mark) {
    queue <int> q;
    q.push(s);
    mark[s] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto i : M[x]) {
            if (mark[i] && ((x != a1 && x != a2) || (i != a1 && i != a2))) {
                mark[i] = 0;
                q.push(i);
            }
        }
    }
}

void prs() {
    vt mark(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        if (mark[i]) {
            bfs(i, 0, 0, mark);
            lt++;
        }
    }
    for (auto i : E) {
        mark = vt(n + 1, 1);
        int tmp = 0;
        for (int j = 1; j <= n; j++) {
            if (mark[j]) {
                bfs(j, i.first, i.second, mark);
                tmp++;
                if (tmp > lt) {
                    cout << i.first << " " << i.second << " ";
                    break;
                }
            }
        }
    }
    cout << endl;
}

void solution() {
    E.clear();
    lt = 0;
    cin >> n >> e;
    M = matrix(n + 1);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
        if (a > b) swap(a, b);
        E.push_back({ a,b });
    }
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
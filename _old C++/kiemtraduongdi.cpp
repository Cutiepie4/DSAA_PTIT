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

void bfs(matrix& M, vt& mark, int s, vt& tmp) {
    queue <int> q;
    q.push(s);
    mark[s] = 0;
    while (!q.empty()) {
        int x = q.front();
        tmp.push_back(x);
        q.pop();
        for (auto i : M[x]) {
            if (mark[i]) {
                mark[i] = 0;
                q.push(i);
            }
        }
    }
    sort(tmp.begin(), tmp.end());
}

void init(matrix& D, matrix& M, int n) {
    vt mark(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        if (mark[i]) {
            vt tmp;
            bfs(M, mark, i, tmp);
            D.push_back(tmp);
        }
    }
}

void solution() {
    int n, e;
    cin >> n >> e;
    matrix M(n + 1), D;
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    init(D, M, n);
    int Q, s, d;
    cin >> Q;
    while (Q--) {
        cin >> s >> d;
        if (s > M.size() || d > M.size()) cout << "NO";
        else {
            int kt = 1;
            for (auto i : D) {
                if (binary_search(i.begin(), i.end(), s) && binary_search(i.begin(), i.end(), d)) {
                    cout << "YES";
                    kt = 0;
                    break;
                }
            }
            if (kt) cout << "NO";
        }
        cout << endl;
    }
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
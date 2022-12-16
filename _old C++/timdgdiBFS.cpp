/*
Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh.

Hãy tìm đường đi từ đỉnh u đến đỉnh v trên đồ thị bằng thuật toán BFS.
*/
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

int n, e, s, d;
matrix M;
vt prv;

void trace() {
    if (prv[d] == -1) {
        cout << "-1";
    }
    else {
        stack <int> st;
        st.push(d), st.push(prv[d]);
        int x = prv[d];
        while (x != s) {
            x = prv[x];
            st.push(x);
        }
        cout << s;
        st.pop();
        while (!st.empty()) {
            cout << " -> " << st.top();
            st.pop();
        }
    }
    cout << endl;
}

void bfs() {
    vt mark(n + 1, 1);
    queue <int> q;
    q.push(s);
    mark[s] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto i : M[x]) {
            if (mark[i]) {
                mark[i] = 0;
                q.push(i);
                prv[i] = x;
            }
        }
    }
    trace();
}

void solution() {
    cin >> n >> e >> s >> d;
    M = matrix(n + 1);
    prv = vt(n + 1, -1);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
    }
    bfs();
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
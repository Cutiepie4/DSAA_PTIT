#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define matrix vector <vector <int>>
#define matrixl vector <vector <ll>>
const ll MOD = 1e9 + 7;

void dfs(int u, matrix& D, vt& visited) {
    visited[u] = 0;
    cout << u << " ";
    for (int i = 0; i < D[u].size(); i++) {
        int x = D[u][i];
        if (visited[x]) dfs(x, D, visited);
    }
}

void dfs(int u, matrix D, vt& visited) {
    stack <int> st;
    st.push(u);
    cout << u << " ";
    visited[u] = 0;
    while (!st.empty()) {
        int x = st.top();
        st.pop();
        for (int i = 0; i < D[x].size(); i++) {
            if (visited[D[x][i]]) {
                cout << D[x][i] << " ";
                visited[D[x][i]] = 0;
                st.push(x);
                st.push(D[x][i]);
                break;
            }
        }
    }
}

void solution() {
    int node, edge, u;
    cin >> node >> edge >> u;
    matrix D(node + 1);
    vt visited(node + 1, 1);
    for (int i = 0, a, b; i < edge; i++) {
        cin >> a >> b;
        D[a].push_back(b);
        D[b].push_back(a);
    }
    dfs(u, D, visited);
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}
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

int dfs(int s) {
    vt mark(n + 1, 1);
    int cnt = n;
    stack <int> st;
    st.push(s);
    while (!st.empty()) {
        int x = st.top();
        st.pop();
        for (auto i : M[x]) {
            if (mark[i]) {
                mark[i] = 0;
                st.push(x), st.push(i);
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) if (mark[i]) return 0;
    return 1;
}

void solution() {
    cin >> n >> e;
    M = matrix(n + 1);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfs(i)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
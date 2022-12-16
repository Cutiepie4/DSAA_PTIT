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

void dfs(matrix& M, vt& mark, int s, int d) {
    vt prev(M.size(), 0);
    stack <int> st;
    st.push(s);
    mark[s] = 0;
    while (!st.empty()) {
        int x = st.top();
        if (x == d) break;
        st.pop();
        for (auto i : M[x]) {
            if (mark[i]) {
                mark[i] = 0;
                st.push(x), st.push(i);
                prev[i] = x;
                break;
            }
        }
    }
    if (!prev[d]) {
        cout << "-1";
    }
    else {
        stack <int> stt;
        int x = prev[d];
        stt.push(d);
        stt.push(x);
        while (x != s) {
            x = prev[x];
            stt.push(x);
        }
        while (!stt.empty()) {
            cout << stt.top() << " ";
            stt.pop();
        }
    }
}

void solution() {
    int n, e, s, d;
    cin >> n >> e >> s >> d;
    matrix M(n + 1);
    vt mark(n + 1, 1);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
    }
    dfs(M, mark, s, d);
    cout << endl;
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
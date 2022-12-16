/*
Đường đi đơn trên đồ thị có hướng hoặc vô hướng đi 
qua tất cả các đỉnh của đồ thị mỗi đỉnh đúng một lần 
được gọi là đường đi Hamilton. 
Cho đồ thị vô hướng G = , 
hãy kiểm tra xem đồ thị có đường đi Hamilton hay không?
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define pi pair <int,int>
#define matrix vector <vt>
#define matrixl vector <vtl>
const int MOD = 1e9 + 7;

int n, e;
matrix M;

int dfs(int u, vt& mark, int cnt) {
    if (cnt == n) return 1;
    for (auto i : M[u]) {
        if (mark[i]) {
            mark[i] = 0;
            if (dfs(i, mark, cnt + 1)) return 1;
            mark[i] = 1;
        }
    }
    return 0;
}

void prs() {
    for (int i = 1; i <= n; i++) {
        vt mark(1001, 1);
        mark[i] = 0;
        if (dfs(i, mark, 1)) {
            cout << "1";
            return;
        }
    }
    cout << "0";
}

void solution() {
    cin >> n >> e;
    M = matrix(1001);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    prs();
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
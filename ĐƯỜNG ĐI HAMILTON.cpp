/*
Đường đi đơn trên đồ thị có hướng hoặc vô hướng đi qua tất cả các đỉnh của đồ thị mỗi đỉnh đúng một lần được gọi là đường đi Hamilton. Cho đồ thị vô hướng G,hãy kiểm tra xem đồ thị có đường đi Hamilton hay không?
Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào hai số V, E tương ứng với số đỉnh, số cạnh của đồ thị; phần thứ hai đưa vào các cạnh của đồ thị.
T, V, E thỏa mãn ràng buộc: 1≤T ≤100; 1≤V≤10; 1≤ E ≤15.
Output:
Đưa ra 1 hoặc 0 tương ứng với test có hoặc không có đường đi Hamilton theo từng dòng.

Input
2
4 4
1 2 2 3 3 4 2 4
4 3
1 2 2 3 2 4
Output
1
0
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
/*
Cho đồ thị vô hướng gồm N đỉnh và M cạnh. Xét lần lượt các đỉnh từ 1 đến N, hãy tính xem nếu xóa đỉnh 
đó đi thì đồ thị có bao nhiêu thành phần liên thông.
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

int n, e;
matrix M;

void bfs(int s, vt& mark) {
    queue <int> q;
    q.push(s);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto i : M[x]) {
            if (mark[i]) {
                mark[i] = 0;
                q.push(i);
            }
        }
    }
}

int process(int k) {
    int cnt = 0;
    vt mark(n + 1, 1);
    mark[k] = 0, mark[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (mark[i]) {
            mark[i] = 0;
            cnt++;
            bfs(i, mark);
        }
    }
    return cnt;
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
        cout << process(i) << endl;
    }
}

int main() {
    faster();
    solution();
    return 0;
}
/*
Cho đồ thị vô hướng G có N đỉnh, M cạnh. 
Hãy liệt kê các đỉnh không cùng thành phần liên thông với đỉnh 1.
Input
Dòng đầu ghi 2 số N và M (0 < N < 300; 1 <= M <= N*(N-1)/2)).
Tiếp theo là M dòng, mỗi dòng ghi một cạnh của đồ thị. Các cạnh được liệt kê với thứ tự bất kỳ.
Output
Ghi ra các đỉnh không liên thông với đỉnh 1 theo thứ tự tăng dần, mỗi dòng ghi một đỉnh. Nếu không có đỉnh nào thì ghi ra số 0.
Ví dụ
Input
6 4
1 3
2 3
1 2
4 5
OUTPUT:
4
5
6
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
vt mark;

void bfs(int s) {
    mark[s] = 0;
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

void solution() {
    cin >> n >> e;
    M = matrix(n + 1);
    mark = vt(n + 1, 1);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    bfs(1);
    int kt = 1;
    for (int i = 2; i <= n; i++) {
        if (mark[i]) {
            cout << i << endl;
            kt = 0;
        }
    }
    if (kt) cout << "0" << endl;
}

int main() {
    faster();
    solution();
    return 0;
}
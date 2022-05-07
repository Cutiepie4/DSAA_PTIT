/*
Một trong những bài toán kinh điển của lý thuyết đồ thị là bài toán Tô màu đồ thị. Bài toán được phát biểu như sau: Cho đồ thị vô hướng G = được biểu diễn dưới dạng danh sách cạnh và số M. Nhiệm vụ của bạn là kiểm tra xem đồ thị có thể tô màu các đỉnh bằng nhiều nhất M màu sao cho hai đỉnh kề nhau đều có màu khác nhau hay không?
Đồ thị có hướng.
Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào ba số V, E, M tương ứng với số đỉnh, số cạnh và số màu; phần thứ hai đưa vào các cạnh của đồ thị.
T, V, E, M thỏa mãn ràng buộc: 1≤T ≤100; 1≤V≤10; 1≤ E ≤N(N-1), 1≤V≤N.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
4  5  3
1 2
2 3
3 4
4 1
1 3
3 3 2
1 2
2 3
1 3
Output:
YES
NO
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define matrix vector <vt>
const ll MOD = 1e9 + 7;

int n, e, k;
matrix M, color;
vt z;

int bfs(int s) {
    vt mark(n + 1, 1);
    queue <int> q;
    q.push(s);
    mark[s] = 0;
    while (!q.empty()) {
        int x = q.front(), kt = 1;
        q.pop();
        for (int i = 0; i < k; i++)
            if (color[x][i]) {
                z[x] = i;
                kt = 0;
                break;
            }
        if (kt) return 0;

        for (auto i : M[x]) {
            color[i][z[x]] = 0;
            if (mark[i]) {
                mark[i] = 0;
                q.push(i);
            }
        }
    }
    return 1;
}

void prs() {
    cout << (bfs(1) ? "YES" : "NO");
    // for (int i = 1; i <= n; i++) cout << i << " " << z[i] << endl;
}

void solution() {
    cin >> n >> e >> k;
    M = matrix(n + 1);
    color = matrix(n + 1, vt(k, 1));
    z = vt(n + 1, 0);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
        // M[b].push_back(a);
    }
    prs();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solution();
        cout << endl;
    }
}
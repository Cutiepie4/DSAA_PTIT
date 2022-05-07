/*
Cho đồ thị vô hướng G= được biểu diễn dưới dạng danh sách cạnh. Hãy viết thuật toán duyệt theo chiều sâu bắt đầu tại đỉnh uÎV (DFS(u)=?)

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E| +1 dòng: dòng đầu tiên đưa vào ba số |V|, |E| tương ứng với số đỉnh và số cạnh của đồ thị, và u là đỉnh xuất phát; |E| dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤200; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra danh sách các đỉnh được duyệt theo thuật toán DFS(u) của mỗi test theo khuôn dạng của ví dụ dưới đây.
      Ví dụ:

Input:

Output:

1

6 9 5

1 2

1 3

2 3

2 4

3 4

3 5

4 5

4 6

5 6

5 3 1 2 4 6
*/
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
    cout << u << " ";
    visited[u] = 0;
    for (auto i : D[u]) {
        if (visited[i] == 1) dfs(i, D, visited);
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
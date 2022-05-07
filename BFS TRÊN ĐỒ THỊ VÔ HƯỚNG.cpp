/*
Cho đồ thị vô hướng G= được biểu diễn dưới dạng danh sách cạnh. Hãy viết thuật toán duyệt theo chiều rộng bắt đầu tại đỉnh uÎV (BFS(u)=?)

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào ba số |V|, |E|, uÎV tương ứng với số đỉnh, số cạnh và đỉnh bắt đầu duyệt; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤200; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra danh sách các đỉnh được duyệt theo thuật toán BFS(u) của mỗi test theo khuôn dạng của ví dụ dưới đây.
     Ví dụ:

Input:
1
6 9 1
1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6
Output:
1 2 3 5 4 6
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define matrix vector <vector <int>>
#define matrixl vector <vector <ll>>
const ll MOD = 1e9 + 7;

void BFS(int u, matrix D, vt mark) {
    queue <int> q;
    q.push(u);
    mark[u] = 0;
    while (!q.empty()) {
        int x = q.front();
        cout << x << " ";
        q.pop();
        for (auto i : D[x]) {
            if (mark[i]) {
                q.push(i);
                mark[i] = 0;
            }
        }
    }
}

void solution() {
    int node, edge, u;
    cin >> node >> edge >> u;
    vt mark(node + 1, 1);
    matrix D(node + 1);
    for (int i = 0, a, b; i < edge; i++) {
        cin >> a >> b;
        D[a].push_back(b);
        D[b].push_back(a);
    }
    BFS(u, D, mark);
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}
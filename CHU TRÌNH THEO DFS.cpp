/*
Cho đồ thị vô hướng G= được biểu diễn dưới dạng danh sách cạnh. Hãy kiểm tra xem đồ thị có chu trình từ đỉnh 1 hay không, nếu có, hãy in ra chu trình đầu tiên tìm thấy theo DFS.

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số N, M  tương ứng với số đỉnh, số cạnh.
Dòng tiếp theo đưa vào các bộ đôi u, v tương ứng với một cạnh của đồ thị.
T, N, M thỏa mãn ràng buộc: 1≤T≤100; 1≤ N ≤103; 1≤ M ≤ N*(N-1)/2;
Output:

Đưa ra chu trình đầu tiên tìm thấy theo DFS từ đỉnh 1.
Nếu không có chu trình từ đỉnh 1, ghi ra NO
      Ví dụ:

Input:

Output:

1

6 9

1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6

1 2 3 1
*/
#include <bits/stdc++.h>
using namespace std;
#define vt vector <int>
#define matrix vector <vt>

int n, e;
matrix M;
vt mark, ans;

void dfs(int x, int st, vt path) {
    if (!ans.empty()) return;
    mark[x] = 0;
    for (auto i : M[x]) {
        vt tmp = path;
        tmp.push_back(i);
        if (i == st && path.size() > 2) {
            if (ans.empty()) ans = tmp;
            return;
        }
        if (mark[i]) {
            dfs(i, st, tmp);
        }
    }
}

void solution() {
    ans.clear();
    cin >> n >> e;
    M = matrix(n + 1);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) sort(M[i].begin(), M[i].end());
    mark = vt(n + 1, 1);
    dfs(1, 1, vt(1, 1));
    if (ans.empty()) cout << "NO";
    else for (auto i : ans) cout << i << " ";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}
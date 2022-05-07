/*
Một đồ thị N đỉnh là một cây, nếu như nó có đúng N-1 cạnh và giữa 2 đỉnh bất kì, chỉ tồn tại duy nhất 1 đường đi giữa chúng.

Cho một đồ thị N đỉnh và N-1 cạnh, hãy kiểm tra đồ thị đã cho có phải là một cây hay không?

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test bắt đầu bởi số nguyên N (1 ≤ N ≤ 1000).
N-1 dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết có cạnh nối giữa đỉnh u và v.
Output:

Với mỗi test, in ra “YES” nếu đồ thị đã cho là một cây, in ra “NO” trong trường hợp ngược lại.
2
4
1 2
1 3
2 4
4
1 2
1 3
2 3

YES
NO
*/
#include <bits/stdc++.h>
using namespace std;
#define matrix vector <vector <int>>

int n, e, ok;
matrix M;
vector <int> mark;

void dfs(int x, int s, int cnt) {
    mark[x] = 0;
    for (auto i : M[x]) {
        if (i == s && cnt > 2) {
            ok = 1;
            return;
        }
        if (mark[i]) {
            dfs(i, s, cnt + 1);
        }
    }
}

int bfs() {
    queue <int> Q;
    Q.push(1);
    vector <int> m(n + 1, 1);
    m[1] = 0;
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();

        for (auto i : M[x]) {
            if (m[i]) {
                m[i] = 0;
                Q.push(i);
            }
        }
    }
    for (int i = 1; i <= n; i++) if (m[i]) return 1;
    return 0;
}

int solution() {
    ok = 0;
    cin >> n;
    M = matrix(n + 1);
    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
    }

    if (bfs()) return 0; // lien thong
    for (int i = 1; i <= n; i++) {
        mark = vector <int>(n + 1, 1);
        dfs(i, i, 1);
        if (ok) return 0;
    }
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << (solution() ? "YES" : "NO") << endl;
    }
}
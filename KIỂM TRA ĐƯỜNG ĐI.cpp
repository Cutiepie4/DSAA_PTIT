/*
Cho đồ thị vô hướng có N đỉnh và M cạnh. Có Q truy vấn, mỗi truy vấn yêu cầu trả lời câu hỏi giữa 2 đỉnh x và y có tồn tại đường đi tới nhau hay không?

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm 2 số nguyên N, M (1 ≤ N, M ≤ 1000).
M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết có cạnh nối giữa đỉnh u và v.
Dòng tiếp là số lượng truy vấn Q (1 ≤ Q ≤ 1000).
Q dòng tiếp theo, mỗi dòng gồm 2 số nguyên x và y.
Output:  Với mỗi truy vấn, in ra “YES” nếu có đường đi từ x tới y, in ra “NO” nếu ngược lại.

Input:
1
5 5
1 2
2 3
3 4
1 4
5 6
2
1 5
2 4
Output:
NO
YES
*/
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

void bfs(matrix& M, vt& mark, int s, vt& tmp) {
    queue <int> q;
    q.push(s);
    mark[s] = 0;
    while (!q.empty()) {
        int x = q.front();
        tmp.push_back(x);
        q.pop();
        for (auto i : M[x]) {
            if (mark[i]) {
                mark[i] = 0;
                q.push(i);
            }
        }
    }
    sort(tmp.begin(), tmp.end());
}

void init(matrix& D, matrix& M, int n) {
    vt mark(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        if (mark[i]) {
            vt tmp;
            bfs(M, mark, i, tmp);
            D.push_back(tmp);
        }
    }
}

void solution() {
    int n, e;
    cin >> n >> e;
    matrix M(n + 1), D;
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    init(D, M, n);
    int Q, s, d;
    cin >> Q;
    while (Q--) {
        cin >> s >> d;
        if (s > M.size() || d > M.size()) cout << "NO";
        else {
            int kt = 1;
            for (auto i : D) {
                if (binary_search(i.begin(), i.end(), s) && binary_search(i.begin(), i.end(), d)) {
                    cout << "YES";
                    kt = 0;
                    break;
                }
            }
            if (kt) cout << "NO";
        }
        cout << endl;
    }
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
/*
Đồ thị hai phía là một đồ thị đặc biệt, trong đó tập các đỉnh có thể được chia thành hai tập không giao nhau thỏa mãn điều kiện không có cạnh nối hai đỉnh bất kỳ thuộc cùng một tập. Cho đồ thị N đỉnh và M cạnh, bạn hãy kiểm tra đồ thị đã cho có phải là một đồ thị hai phía hay không?
Input:

Dòng đầu tiên là số lượng bộ test T (T ≤  20).
Mỗi test bắt đầu bởi số nguyên N và M (1 ≤  N, M ≤  1000).
M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết có cạnh nối giữa đỉnh u và v.
Output: 

Với mỗi test, in ra “YES” nếu đồ thị đã cho là một đồ thị hai phía, in ra “NO” trong trường hợp ngược lại.
Ví dụ:

Input:
2
5 4
1 5
1 3
2 3
4 5
3 3
1 2
1 3
2 3
Output:
YES
NO
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

matrix M;
int n, e;
vt v;

int bfs() {
    vt mark(n + 1, 1);
    queue <int> q;
    q.push(1);
    v[1] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        mark[x] = 0;
        if (M[x].size() == 0) return 0;
        for (auto i : M[x]) {
            if (mark[i]) {
                if (v[i] == -1) v[i] = 1 - v[x];
                else if (v[i] == v[x]) return 0;
                q.push(i);
            }
        }
    }
    return 1;
}

void solution() {
    cin >> n >> e;
    v = vt(n + 1, -1);
    M = matrix(n + 1);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    if (bfs()) cout << "YES" << endl;
    else cout << "NO" << endl;
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
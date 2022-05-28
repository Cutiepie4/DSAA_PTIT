/*
Cho một cây có N node, gốc tại 1. Có Q truy vấn, mỗi truy vấn yêu cầu bạn tìm khoảng cách giữa hai node u và v.



Input:

Dòng đầu tiên là số lượng bộ test T( T≤ 20).

Mỗi test bắt đầu bằng số nguyên N (1 ≤ N ≤ 1000). N-1 dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết node u nối với node v.

Dòng tiếp theo là số lượng truy vấn Q (1 ≤ Q ≤ 1000). Q dòng tiếp theo, mỗi dòng gồm 2 số nguyên u và v.

Output:

Với mỗi test, in ra Q dòng là đáp án với mỗi truy vấn.

Test ví dụ:

Input:
1
8
1 2
1 3
2 4
2 5
3 6
3 7
6 8
5
4 5
4 6
3 4
2 4
8 5

Output
2
4
3
1
5
*/

#include <bits/stdc++.h>
using namespace std;
#define vt vector <int>
#define mt vector <vt>

mt M;

int bfs(int st, int en) {
    vt mark(10000, 1);
    mark[st] = 0;
    queue <pair <int, int>> Q;
    Q.push({ st , 0 });

    while (Q.size()) {
        int u = Q.front().first, cnt = Q.front().second;
        Q.pop();
        if (u == en) return cnt;
        for (auto i : M[u]) {
            if (mark[i]) {
                Q.push({ i, cnt + 1 });
                mark[i] = 0;
            }
        }
    }
    return -1;
}

void solution() {
    int n;
    cin >> n;
    M = mt(10000);
    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int st, en;
        cin >> st >> en;
        cout << bfs(st, en) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}
/*
Cho một cây có N node, gốc tại 1. Với mỗi node lá, bạn hãy in ra đường đi từ node gốc tới nó.



Input:

Dòng đầu tiên là số lượng bộ test T( T≤ 20).

Mỗi test bắt đầu bằng số nguyên N (1 ≤ N ≤ 1000).

N-1 dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết node u nối với node v.

Output: 

Với mỗi test, in ra K dòng, trong đó K là số lượng node lá. Mỗi dòng là đường đi từ node gốc tới node lá X. Node lá nào có nhãn nhỏ hơn, in ra trước.

Test ví dụ:

Input:
2
5
1 2
1 3
2 4
2 5
4
1 2
2 3
3 4
 
Output
1 3
1 2 4
1 2 5
1 2 3 4
*/
#include <bits/stdc++.h>
using namespace std;
#define vt vector <int>
#define mt vector <vt>

int n;
mt M, Ans;

void dfs(int x, vt path) {
    if (M[x].empty()) {
        Ans[x] = path;
        return;
    }
    for (auto i : M[x]) {
        vt tmp = path;
        tmp.push_back(i);
        dfs(i, tmp);
    }
}

void solution() {
    cin >> n;
    M = mt(n + 1);
    Ans = M;
    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        M[a].push_back(b);
    }
    dfs(1, vt(1, 1));
    for (int i = 2; i <= n; i++) {
        if (!Ans[i].empty()) {
            for (auto j : Ans[i]) cout << j << " ";
            cout << endl;
        }
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
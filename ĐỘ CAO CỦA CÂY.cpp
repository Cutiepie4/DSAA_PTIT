/*
Cho một cây có N node, gốc tại  1. Độ cao của một node u được tính bằng khoảng cách từ u tới node gốc. Độ cao của node gốc bằng 0. Nhiệm vụ của bạn là hãy tìm node xa node gốc nhất và in ra độ cao của node này.

Input:

Dòng đầu tiên là số lượng bộ test T( T≤ 20).

Mỗi test bắt đầu bằng số nguyên N (1 ≤ N ≤ 100 000).

N-1 dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết node u nối với node v.

Output: 

Với mỗi test, in ra một số nguyên là độ cao của cây.

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
2
3
*/

#include <bits/stdc++.h>
using namespace std;
#define vt vector <int>
#define mt vector <vt>

int n;
mt M;

int height_of_tree() {
    queue <pair <int, int>> Q;
    Q.push({ 1,0 });
    int Max = -1;

    while (!Q.empty()) {
        int x = Q.front().first, cnt = Q.front().second;
        Q.pop();
        Max = max(Max, cnt);

        for (auto i : M[x]) {
            Q.push({ i, cnt + 1 });
        }
    }
    return Max;
}

void solution() {
    cin >> n;
    M = mt(n + 1);
    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        M[a].push_back(b);
    }
    cout << height_of_tree();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}
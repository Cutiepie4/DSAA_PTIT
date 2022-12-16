/*
Trên cánh đồng kích thước N x N có  chú cừu. 
Người nông dân sợ các chú cừu đi lạc ên đã làm một 
số rào chắn giữa các khu vực. Các chú cừu chỉ có thể 
di chuyển lên trên, xuống dưới, sang trái,sang phải 
khu vực bên cạnh, và không thể vượt qua được hàng rào.

Hai chú cừu A và B được gọi là ‘xa ách’ nếu như 
chúng không thể di chuyển tới vị trí của nhau. 
Các bạn hãy xác định xem số cặp chú cừu xa cách 
bằng nhau nhiêu?

Input:  Dòng đầu tiên gồm 3 số nguyên dươg N, K và M 
(1 ≤  N ≤  100, K ≤  100, M ≤  N^2). 
 M dòng tiếp theo, mỗi dòng gồm 4 số nguyên u, v, x, y
  cho biết có rào chắn ở giữa hai khu vực (u, v) và (x, y)
   (2 ô này cạnh nhau). K dòng cuối, mỗi dòngchứa 2 số 
   nguyên là tọa độ của mỗi chú cừu.

Output: In ra số cặp chú cừu bị xa cách tìm được.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define matrix vector <vt>
#define matrixl vector <vtl>
const int MOD = 1e9 + 7;

const int X[] = { -1, 0, 1 , 0 };
const int Y[] = { 0, -1, 0, 1 };

int n, k, m;
vector <vector <vector <pair <int, int>>>> M;
vector <pair <int, int>> v;
matrix sheep;
matrix mark;

int bfs(int x1, int y1) {
    mark[x1][y1] = 0;
    queue <pair <int, int>> q;
    q.push({ x1,y1 });
    int cnt = 0;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (sheep[x][y]) cnt++;
        for (int i = 0; i < 4; i++) {
            int r = x + X[i], c = y + Y[i];
            if (r > 0 && c > 0 && r <= n && c <= n && mark[r][c]) {
                int kt = 1;
                for (auto j : M[x][y]) {
                    if (j.first == r && j.second == c) {
                        kt = 0;
                        break;
                    }
                }
                if (kt) {
                    q.push({ r,c });
                    mark[r][c] = 0;
                }
            }
        }
    }
    return cnt;
}

void prs() {
    int ans = 0;
    vt D;
    for (auto i : v) {
        if (mark[i.first][i.second]) {
            D.push_back(bfs(i.first, i.second));
        }
    }
    if (D.size() > 1)
        for (int i = 0; i < D.size(); i++) {
            for (int j = i + 1; j < D.size(); j++) {
                ans += D[i] * D[j];
            }
        }
    cout << ans;
}

void solution() {
    cin >> n >> k >> m;
    sheep = matrix(n + 1, vt(n + 1, 0));
    M = vector <vector <vector <pair <int, int>>>>(n + 1, vector <vector <pair <int, int>>>(n + 1));
    mark = matrix(n + 1, vt(n + 1, 1));
    for (int i = 0, a, b, c, d; i < m; i++) {
        cin >> a >> b >> c >> d;
        M[a][b].push_back({ c,d });
        M[c][d].push_back({ a,b });
    }
    for (int i = 0, a, b; i < k; i++) {
        cin >> a >> b;
        sheep[a][b] = 1;
        v.push_back({ a,b });
    }
    prs();
}

int main() {
    faster();
    solution();
    return 0;
}
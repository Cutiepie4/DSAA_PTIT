/*
Cho một đồ thị có hướng gồm N đỉnh và M cạnh. Nhiệm vụ của bạn là hãy tính khoảng cách trung bình ngắn nhất giữa hai nút bất kì nếu như chúng liên thông với nhau. Input đảm bảo rằng trong một nhóm liên thông, nếu như u đi tới được v thì v cũng đi tới được v với mọi cặp u, v.

Input:Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test bắt đầu bởi hai số nguyên N và M (1 ≤ N ≤ 100, M ≤ N*(N-1)/2). M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết có cạnh nối đơn hướng từ u tới v.

Output:  Với mỗi test, in ra đáp án tìm được với độ chính xác 2 chữ số sau dấu phảy.

Ví dụ:

Input:
2
4 5
1 2
2 4
1 3
3 1
4 3
7 5
1 2
1 4
4 2
2 7
7 1
Output:
1.83
1.75

Giải thích test 1: Ta có
d(1, 2) = 1, d(1, 3) = 1, d(1, 4) = 2; d (2, 1) = 3, d(2, 3) = 2, d(2, 4) = 1;
d(3, 1) = 1, d(3, 2) = 2, d(3, 4) = 3; d(4, 1) = 2, d(4, 2) = 3, d(4, 3) = 1.
Trung bình bằng 22/12 = 1.83
*/
/*
Cho một đồ thị có hướng gồm N đnh và M cạnh. 
Nhiệm vụ của bạn là hãy tính khoảng cách trung bình 
ngắn nhất giữa hai node bất kì nếu như chúng liên 
thông với nhau. Input đảm bảo rằng tron một nhóm 
liên thông, nếu như u đi tới được v tì v cũng đi 
tới được v với mọi cặp u, v.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define matrix vector <vector <int>>
#define matrixl vector <vector <ll>>
const ll MOD = 1e9 + 7;

int n, e, z;
matrix M;
float ans;

void bfs(int s) {
    vt mark(n + 1, 1);
    mark[s] = 0;
    queue <int> q;
    int cnt = 0;
    q.push(s);
    while (1) {
        cnt++;
        queue <int> tmp;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto i : M[x]) {
                if (mark[i]) {
                    ans += cnt;
                    mark[i] = 0;
                    tmp.push(i);
                }
            }
        }
        if (!tmp.size()) break;
        q = tmp;
        z += tmp.size();
    }
}

void solution() {
    z = 0, ans = 0;
    cin >> n >> e;
    M = matrix(n + 1);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) bfs(i);
    cout << setprecision(2) << fixed << (float)ans / z << endl;
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
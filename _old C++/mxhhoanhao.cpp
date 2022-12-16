/*
Mạng xã hội hoàn hảo khi với mọi bộ ba X, Y, Z, nếu X ết bạn với Y, Y 
kết bạn với Z thì X và Z cũng phải là bạn bè của nhau trên mạng xã hội.

Hãy xác định một mạng xã hội có phải là hoàn hảo 
hay không? Nếu có hãy in ra “YES”, “NO” trong trường hợp ngược lại.
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

int n, e;
matrix M;
vt mark;

void bfs(int s) {
    mark[s] = 0;
    queue <int> q;
    q.push(s);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto i : M[x]) {
            if (mark[i]) {
                mark[i] = 0;
                q.push(i);
            }
        }
    }
}

void solution() {
    cin >> n >> e;
    M = matrix(n + 1);
    mark = vt(n + 1, 1);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    bfs(1);
    for (int i = 1; i <= n; i++) {
        if (mark[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
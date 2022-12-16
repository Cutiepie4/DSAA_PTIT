/*
Trường học X có N sinh viên, trong đó có M cặp là bạn bè của nhau. 
Bạn của bạn cũng là bạn, tức là nếu  là bạn của B, 
B là bạn của C thì A và C cũng là bạn bè của nhau.

Các bạn hãy xác định xem số lượng sinh vin nhiều nhất 
trong một nhóm bạn là bao nhiêu?
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

int ans = 0;

void bfs(matrix& M, vt& mark, int s) {
    int cnt = 1;
    queue <int> q;
    q.push(s);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto i : M[x]) {
            if (mark[i]) {
                mark[i] = 0;
                q.push(i);
                cnt++;
            }
        }
    }
    ans = max(ans, cnt);
}

void process(matrix& M) {
    vt mark(M.size(), 1);
    for (int i = 1; i < M.size(); i++) {
        if (mark[i]) {
            mark[i] = 0;
            bfs(M, mark, i);
        }
    }
    cout << ans << endl;
}

void solution() {
    ans = 0;
    int stu, pr;
    cin >> stu >> pr;
    matrix M(stu + 1);
    for (int i = 0, a, b; i < pr; i++) {
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    process(M);
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
4
7 1
4 3
5 1
1 3
6 1
1 7
2 1

6 2
5 1
2 5
5 6
4 2
3 4

2 1000
1 2

14 1
1 2
2 3
2 4
4 5
4 6
2 7
7 8
8 9
8 10
3 11
3 12
1 13
13 14
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

struct f {
    int sz;
    vt v;
};

int n, day;
vector <f> M;
queue <int> q;

void bfs() {
    vt mark(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        M[i].sz = M[i].v.size();
        if (M[i].v.size() == 1) {
            q.push(i);
            mark[i] = 0;
        }
    }
    int cnt = n;
    while (day--) {
        queue <int> tmp;
        while (!q.empty()) {
            int x = q.front();
            cnt--;
            q.pop();
            for (auto i : M[x].v) {
                if (mark[i]) {
                    M[i].sz--;
                    if (M[i].sz == 0) tmp.push(i);
                }
            }
        }
        q = tmp;
    }
    cout << cnt << endl;
}

void solution() {
    queue <int> tmp;
    q = tmp;
    cin >> n >> day;
    M = vector <f>(n + 1);
    for (int i = 2, a, b; i <= n; i++) {
        cin >> a >> b;
        M[a].v.push_back(b);
        M[b].v.push_back(a);
    }
    bfs();
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
/*
Tìm cây khung nhỏ nhất là tìm cây khung có tổng trọng số
là nhỏ nhất.
Điều kiện: G có cây khung nhỏ nhất <=> G liên thông

*/
#include <bits/stdc++.h>
using namespace std;
#define vt vector <int>
#define mt vector <vt>

struct edge {
    int u, v, w;
};

int cmp(edge a, edge b) {
    return a.w < b.w;
}

int n, e;
vt Prv;
vector <edge> E;

int Find(int x) {
    if (Prv[x] == -1) return x;
    return Find(Prv[x]);
}

void Union(int x, int y) {
    if (x < y) Prv[y] = x;
    else Prv[x] = y;
}

int check(edge i) {
    int set_u = Find(i.u), set_v = Find(i.v);
    if (set_u == set_v) return 0;
    Union(set_u, set_v);
    return 1;
}

int Kruskal() {
    int ans = 0, cnt = 0;
    sort(E.begin(), E.end(), cmp);
    for (auto i : E) {
        if (check(i)) {
            cnt++;
            ans += i.w;
            if (cnt == n - 1) return ans;
        }
    }
    return -1;
}

void solution() {
    cin >> n >> e;
    Prv = vt(n + 1, -1);
    E = vector <edge>(0);
    for (int i = 0, u, v, w; i < e; i++) {
        cin >> u >> v >> w;
        E.push_back({ u,v,w });
    }
    cout << Kruskal();
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
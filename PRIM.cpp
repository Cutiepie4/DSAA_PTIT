/*
vector kq chứa cạnh
while lặp khi chưa đủ V đỉnh:
    tìm e = (u,v) có ts nhỏ nhất mà u thuộc kq, v ko thuộc kq
    if (tìm đc e) {
        bổ sung cạnh và đỈnh, trọng số
    }
    else return ko có cây khung
    return kq
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int>II;

int n, m;
vector <int> chuaxet;
vector <vector <II>> List;
set <II> S;
II canh[1005];
long long ans = 0;

void Prim() {
    int i, u, v;
    while (!S.empty()) {
        u = S.begin()->second;
        int d = S.begin()->first;
        chuaxet[u] = 1;
        ans += d;
        S.erase(S.begin());
        for (i = 0; i < List[u].size(); i++) {
            v = List[u][i].second;
            d = List[u][i].first;
            // cập nhật lại danh sách cạnh
            if (chuaxet[v] == 0 && canh[v].first > d) {
                S.erase(canh[v]);
                canh[v].first = d;
                S.insert(canh[v]);
            }
        }
    }
}

main() {
    int t, i, u, v, c;
    cin >> t;
    while (t--) {
        List = vector <vector <II>>(1005);
        chuaxet = vector <int>(505, 0);
        S.clear(); ans = 0;
        for (i = 1;i <= n;i++) {
            canh[i].first = 1e9;
            canh[i].second = i;
        }

        cin >> n >> m;
        for (i = 1;i <= m;i++) {
            cin >> u >> v >> c;
            List[u].push_back(II(c, v));
            List[v].push_back(II(c, u));
        }

        canh[1].first = 0;
        for (i = 1; i <= n; i++) S.insert(canh[i]);
        Prim();
        cout << ans << endl;
    }
}


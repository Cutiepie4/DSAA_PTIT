
#include <bits/stdc++.h>
using namespace std;

int path_finding(vector <vector <int>>& v, int r, int c, int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) return 0;
    queue <pair<int, int>> q;
    q.push({ x1, y1 });
    v[x1][y1] = 0;
    int ans = 0, z = 1, t = 0;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        if (v[x + 1][y] == 1) {
            if (x + 1 == x2 && y == y2) return ans + 1;
            v[x + 1][y] = 2;
            q.push({ x + 1, y }); t++;
        }
        if (v[x][y + 1] == 1) {
            if (x == x2 && y + 1 == y2) return ans + 1;
            v[x][y + 1] = 2;
            q.push({ x, y + 1 }); t++;
        }
        if (v[x][y - 1] == 1) {
            if (x == x2 && y - 1 == y2) return ans + 1;
            v[x][y - 1] = 2;
            q.push({ x, y - 1 }); t++;
        }
        if (v[x - 1][y] == 1) {
            if (x - 1 == x2 && y == y2) return ans + 1;
            v[x - 1][y] = 2;
            q.push({ x - 1, y }); t++;
        }
        q.pop();
        z--;
        if (z == 0) {
            z = t; t = 0; ans++;
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c, x1, y1, x2, y2;
        cin >> r >> c >> x1 >> y1 >> x2 >> y2;
        x1++; y1++; x2++; y2++;
        vector <vector <int>> v(r + 2, vector <int>(c + 2, 0));
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                cin >> v[i][j];
        if(v[x2][y2] == 0 || v[x1][y1] == 0) {
            cout << "-1" << endl;
            continue;
        }
        cout << path_finding(v, r, c, x1, y1, x2, y2) << endl;
        v.clear();
    }
}
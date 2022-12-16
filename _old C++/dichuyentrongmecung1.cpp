#include <bits/stdc++.h>
using namespace std;

void find_path(vector <vector <int>>& v, vector <vector <vector <string>>>& data, int row, int col, vector <vector <int>>& mark) {
    queue <pair <int, int>> q;
    q.push({ 0,0 });
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (v[x][y + 1] == 1) {
            if (mark[x][y + 1]) q.push({ x, y + 1 });
            mark[x][y + 1] = 0;
            if (data[x][y].empty()) data[x][y + 1].push_back("R");
            else for (int i = 0; i < data[x][y].size(); i++) {
                string tmp = data[x][y][i];
                tmp.push_back('R');
                data[x][y + 1].push_back(tmp);
            }
        }
        if (v[x + 1][y] == 1) {
            if (mark[x + 1][y]) q.push({ x + 1, y });
            mark[x + 1][y] = 0;
            if (data[x][y].empty()) data[x + 1][y].push_back("D");
            else for (int i = 0; i < data[x][y].size(); i++) {
                string tmp = data[x][y][i];
                tmp.push_back('D');
                data[x + 1][y].push_back(tmp);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <vector <int>> v(n + 1, vector <int>(n + 1, 0));
        vector <vector <int>> mark(n + 1, vector <int>(n + 1, 1));
        vector <vector <vector <string>>> data(n, vector <vector <string>>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        if (v[0][0] == 0) {
            cout << "-1" << endl;
            continue;
        }
        find_path(v, data, n - 1, n - 1, mark);
        if (!data[n - 1][n - 1].empty()) {
            sort(data[n - 1][n - 1].begin(), data[n - 1][n - 1].end());
            for (auto i : data[n - 1][n - 1]) cout << i << " ";
            cout << endl;
        }
        else cout << "-1" << endl;
    }
}
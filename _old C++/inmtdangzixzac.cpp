#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        vector <vector<int>> v1(n), v2(n);
        int x = 0;
        for (int i = 0; i < n; i++) {
            int j = 0, k = i;
            while (k >= 0) {
                v1[x].push_back(a[k--][j++]);
            }
            if (x % 2 == 1) reverse(v1[x].begin(), v1[x].end());
            for (auto i : v1[x]) cout << i << " ";
            x++;
        }
        x = 0;
        for (int i = n - 1; i > 0; i--) {
            int j = i, k = m - 1, y = n - i;
            while (y--) {
                v2[x].push_back(a[j++][k--]);
            }
            if (x % 2 == 0) reverse(v2[x].begin(), v2[x].end());
            x++;
        }
        for (int i = x; i >= 0; i--) {
            for (auto z : v2[i]) cout << z << " ";
        }
        cout << endl;
    }
}
// summed area table
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c, n;
        cin >> r >> c >> n;
        vector <vector <int>> v(r + 1, vector <int>(c + 1, 0));
        vector <vector <int>> sum(r + 1, vector <int>(c + 1, 0));
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> v[i][j];
            }
        }
        for (int i = 1; i <= r; i++) {
            partial_sum(v[i].begin(), v[i].end(), v[i].begin());
        }
        for (int i = 1; i <= c; i++) {
            for (int j = 1; j <= r; j++) {
                sum[j][i] = sum[j - 1][i] + v[j][i];
            }
        }
        int tmp = n * n;
        for (int i = n; i <= r; i++) {
            for (int j = n; j <= c; j++) {
                int x = sum[i][j] + sum[i - n][j - n] - sum[i][j - n] - sum[i - n][j];
                cout << x / tmp << " ";
            }
            cout << endl;
        }
    }
}
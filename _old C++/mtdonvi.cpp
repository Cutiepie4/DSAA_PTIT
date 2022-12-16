// summed area table
#include <bits/stdc++.h>
using namespace std;

void solution() {
    int r, c, k, ans = 0;
    cin >> r >> c >> k;
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
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {

        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}
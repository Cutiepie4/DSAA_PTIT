#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, tmp = 1;
        cin >> n;
        n = 4 * n;
        int a[n + 1][n + 1];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = tmp++;

        vector <int> v1, v2;
        int r = n / 2 + 1, l = n / 2, x = 2;
        while (v1.size() < n * n / 2) {
            for (int i = r; i > r - x; i--) {
                if (v1.size() >= n * n / 2) break;
                v1.push_back(a[i][l]);
            }
            r -= x;
            for (int i = l; i < l + x; i++) {
                if (v1.size() >= n * n / 2) break;
                v1.push_back(a[r][i]);
            }
            l += x;
            x += 2;
            for (int i = r; i < r + x; i++) {
                if (v1.size() >= n * n / 2) break;
                v1.push_back(a[i][l]);
            }
            r += x;
            for (int i = l; i > l - x; i--) {
                if (v1.size() >= n * n / 2) break;
                v1.push_back(a[r][i]);
            }
            l -= x;
            x += 2;
        }
        for (auto i : v1) cout << i << " ";
        cout << endl;
        r = n / 2, l = n / 2 + 1, x = 2;
        while (v2.size() < n * n / 2) {
            for (int i = r; i < r + x; i++) {
                if (v2.size() >= n * n / 2) break;
                v2.push_back(a[i][l]);
            }
            r += x;
            for (int i = l; i > l - x; i--) {
                if (v2.size() >= n * n / 2) break;
                v2.push_back(a[r][i]);
            }
            l -= x;
            x += 2;
            for (int i = r; i > r - x; i--) {
                if (v2.size() >= n * n / 2) break;
                v2.push_back(a[i][l]);
            }
            r -= x;
            for (int i = l; i < l + x; i++) {
                if (v2.size() >= n * n / 2) break;
                v2.push_back(a[r][i]);
            }
            l += x;
            x += 2;
        }
        for (auto i : v2) cout << i << " ";
        cout << endl;
    }
}
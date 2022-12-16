#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
    int n;
    cin >> n;
    vector <int> a(n + 1), f(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    f[1] = 1;
    int res = 1;
    for (int i = 2; i <= n; i++) {
        int l = 1, r = res, j = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[i] > a[f[m]]) {
                j = m;
                l = m + 1;
            }
            else r = m - 1;
        }
        if (j == res) f[++res] = i;
        if (a[i] < a[f[j + 1]]) f[j + 1] = i;
    }

    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}
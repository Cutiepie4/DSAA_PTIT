// bài này cũng dễ hiểu thôi, tính tổng giống giai thừa tại
// từng số , cắt từng phần của dãy này rồi nhét dãy kia vào

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        ll a[n + 1], b[m + 1];
        a[0] = b[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
            b[i] += b[i - 1];
        }
        ll res = max(a[n], b[m]);
        for (int i = 1; i <= n; i++) res = max(res, b[m] - b[i] + a[i]);
        for (int i = 1; i <= m; i++) res = max(res, a[n] - a[i] + b[i]);
        cout << res << endl;
    }
}
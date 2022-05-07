#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    double cnt = n * (n - 1) / 2;
    double ans = (cnt - (n - 1));
    cout << setprecision(6) << fixed << ans << endl;
    for (int i = 2; i <= n; i++) {
        cout << 1 << " " << i << endl;
    }
    
    return 0;
}
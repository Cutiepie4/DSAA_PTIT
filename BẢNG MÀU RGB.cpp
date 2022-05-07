#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll gt(ll x) {
    if (x == 1) return 1;
    return gt(x - 1) * x;
}

ll process(ll n, vector <ll> c, ll tmp) {
    for (int i = 0; i < 3; i++) {
        if (c[i] == 0) c[i] = 1;
        c[i] = gt(c[i]);
    }
    return gt(n) / c[1] / c[2] / c[0];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, ans = 0, tmp1, tmp2;
        vector <ll> c(3);
        cin >> n >> c[0] >> c[1] >> c[2];
        ll tmp = n - c[0] - c[1] - c[2];
        for (int i = 0; i <= tmp; i++) {
            vector <ll> c1 = c;
            c1[0] += i;
            tmp1 = c1[1]; tmp2 = c1[2];
            for (int j = 0; j <= tmp - i; j++) {
                c1[1] = tmp1; c1[1] += j;
                c1[2] = tmp2; c1[2] += tmp - i - j;
                ans += process(n, c1, tmp);
            }
        }
        cout << ans << endl;
    }
}
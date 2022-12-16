/*
Tính toán giá trị đa thức
P(n, x) = an-1xn-1 + an-2xn-2 +..+ a0.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll oo = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, x, k = 1;
        cin >> n >> x;
        int a[n];
        vector <ll> tmp(n, 1);
        for (int i = n - 1; i >= 0; i--) cin >> a[i];
        ll res = a[0];
        for (int i = 1; i < n; i++) {
            k = (k * x) % oo;
            res = (res + (k * a[i]) % oo) % oo;
        }
        cout << res << endl;
    }
}
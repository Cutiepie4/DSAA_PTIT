#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <ll>> 
const ll MOD = 1e9 + 7;

ll n, k;

matrix multi(matrix a, matrix b) {
    matrix res(n, vector <ll>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] = (res[i][j] % MOD + (a[i][k] % MOD * b[k][j]) % MOD) % MOD;
            }
        }
    }
    return res;
}

matrix sqr(matrix a) {
    return multi(a, a);
}

matrix power(matrix a, ll k) {
    if (k == 1) return a;
    else {
        if (k % 2 == 0) {
            return sqr(power(a, k / 2));
        }
        else return multi(a, sqr(power(a, k / 2)));
    }
}

void output(matrix a) {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + a[0][i]) % MOD;
    }
    cout << ans << endl;
}

void input(matrix& a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

void solution() {
    cin >> n >> k;
    matrix mt(n + 1, vector <ll>(n + 1, 0));
    input(mt);
    output(power(mt, k));
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}
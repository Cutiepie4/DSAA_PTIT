#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll sqr(ll x) {
    return x * x;
}

ll Pow(ll a, ll b) {
    if (b == 0) return 1 % MOD;
    else
        if (b % 2 == 0)
            return sqr(Pow(a, b / 2)) % MOD;
        else
            return a * (sqr(Pow(a, b / 2)) % MOD) % MOD;
}

void solution(ll a, ll b) {
    cout << Pow(a, b) << endl;
}

int main() {
    ll a, b;
    while (cin >> a >> b) {
        if (a == b && a == 0) return 0;
        solution(a, b);
    }
}
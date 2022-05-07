#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll poww(ll a, ll b) {
    if (b == 0) return 1;
    ll x = poww(a, b / 2);
    if (b % 2 == 0) return x * x % mod;
    return a * (x * x % mod) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    long long x = poww(2, k - 1);
    cout << x % mod * (n - k + 1) % mod;
}
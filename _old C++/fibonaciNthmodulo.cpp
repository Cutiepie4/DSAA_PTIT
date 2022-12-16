// F[i] = (F[(i+1)/2] * F[i/2]) + (F[(i-1)/2] * F[(i-2)/2])

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll oo = 1000000007;
unordered_map<ll, ll> Fb;

ll find_fib(ll n) {
    if (n < 2) return 1;
    if (Fb.find(n) != Fb.end()) return Fb[n];
    Fb[n] = (find_fib((n + 1) / 2) * find_fib(n / 2) + find_fib((n - 1) / 2) * find_fib((n - 2) / 2)) % oo;
    return Fb[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << find_fib(n-1) << endl;
    }
}
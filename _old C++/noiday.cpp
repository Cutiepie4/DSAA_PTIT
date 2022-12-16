#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll oo = 1e9 + 7;

void solution() {
    int n;
    cin >> n;
    multiset <ll> ss;
    multiset <ll> ::iterator it;
    for (ll i = 0, a; i < n; i++) {
        cin >> a;
        ss.insert(a);
    }
    ll tmp = 0, ans = 0;
    while (ss.size() != 1) {
        tmp = *ss.begin();
        ss.erase(ss.begin());
        tmp += *ss.begin();
        ss.erase(ss.begin());
        ans = (ans + tmp) % oo;
        ss.insert(tmp % oo);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}
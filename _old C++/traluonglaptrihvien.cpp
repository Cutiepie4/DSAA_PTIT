#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cmp(pair <ll, ll> a, pair<ll, ll> b) {
    if (a.first < b.first) return 1;
    else if (a.first == b.first && a.second < b.second) return 1;
    return 0;
}

int main() {
    ll n, x, y, z, ans = 0;
    cin >> n >> x >> y >> z;
    vector <pair <ll, ll>> v(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    
    sort(v.begin(), v.end(), cmp);
    for (ll i = n; i > 1; i--) {
        int cnt = 0;
        for (ll j = i - 1; j > 0; j--) {
            if (v[i].first > v[j].second) cnt++;
        }
        ans = max(ans, (i - cnt) * y + cnt * z + (n - i) * x);
    }
    cout << ans;
}
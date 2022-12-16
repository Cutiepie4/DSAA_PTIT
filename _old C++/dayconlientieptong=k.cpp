#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <ll>

void solution() {
    ll n, sum;
    cin >> n >> sum;
    vt v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++) cin >> v[i];
    if (sum > 1e15) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (v[i] == sum) {
            cout << "YES" << endl;
            return;
        }
        v[i] += v[i - 1];
    }
    for (int i = 0; i <= n; i++) {
        ll tmp = v[i] + sum;
        if (*lower_bound(v.begin() + i + 1, v.end(), tmp) == tmp) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}
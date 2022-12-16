#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <int>
#define matrixl vector <vector <ll>>
#define vtl vector <ll>
const ll MOD = 1e9 + 7;

void process(vt v, vt& dp) {
    dp[1] = v[1];
    for (int i = 2; i < v.size() - 1; i++) {
        for (int j = 1; j < i; j++) {
            if (v[j] < v[i]) {
                dp[i] = max(dp[i], dp[j] + v[i]);
            }
        }
    }
}

void solution() {
    int n, ans = 0;
    cin >> n;
    vt v(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> v[i];
    vt dp1 = v;
    process(v, dp1);
    reverse(v.begin(), v.end());
    vt dp2 = v;
    process(v, dp2);
    reverse(dp2.begin(), dp2.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i <= n + 1; i++) {
        ans = max(ans, dp1[i] + dp2[i] - v[i]);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}
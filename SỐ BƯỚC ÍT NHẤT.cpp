#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define pi pair <int,int>
#define matrix vector <vt>
#define matrixl vector <vtl>
const int MOD = 1e9 + 7;

int n;
vt v;

int prs() {
    vt dp(v.size(), 1);
    int ans = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] >= v[j]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

void solution() {
    cin >> n;
    v = vt(n);
    for (auto& i : v) cin >> i;
    cout << n - prs();
}

int main() {
    faster();
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
    return 0;
}
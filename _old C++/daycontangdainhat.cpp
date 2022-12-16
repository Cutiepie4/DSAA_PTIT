#include <bits/stdc++.h>
using namespace std;

int process(vector <int> v) {
    vector <int> dp(v.size(), 1);
    int res = 1;
    dp[0] = 1;
    for (int i = 1; i < dp.size(); i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        for (auto& i : v) cin >> i;
        cout << process(v) << endl;
    }
}
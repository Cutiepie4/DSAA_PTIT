#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string Data = "@ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vector <int> dp(27);
void init() {
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= 26; i++) {
        dp[i] = dp[i - 1] * 2 + 1;
    }
}

char find_kth_ch(int n, int k) {
    if (k == dp[n - 1] + 1) return Data[n];
    if (k > dp[n - 1]) return find_kth_ch(n - 1, k - dp[n - 1] - 1);
    return find_kth_ch(n - 1, k);
}

int main() {
    int t;
    cin >> t;
    init();
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << find_kth_ch(n, k) << endl;
    }
}
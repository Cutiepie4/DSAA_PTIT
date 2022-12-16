#include <bits/stdc++.h>
using namespace std;

int buildCheck(string S) {
    int ans = 0;
    int n = S.size();
    int CheckPalin[n][n];
    for (int i = n - 1; i >= 0; i--) {
        CheckPalin[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
            CheckPalin[i][j] = (S[i] == S[j]) && (i == j - 1 || CheckPalin[i + 1][j - 1]);
            if (CheckPalin[i][j]) ans = max(ans, j - i);
        }
    }
    return ans + 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << buildCheck(s) << endl;
    }
}
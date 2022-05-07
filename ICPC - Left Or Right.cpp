#include <bits/stdc++.h>
using namespace std;


string back(int n, string s) {
    if (n == 1) return s;
    if (n % 2 == 0) return back(n / 2, s + 'L');
    return back((n - 1) / 2, s + 'R');
}

void solution() {
    int n;
    cin >> n;
    string ans = back(n, "");
    reverse(ans.begin(), ans.end());
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}
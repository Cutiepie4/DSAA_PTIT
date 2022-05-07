/*
cứ bên phải số 1 thì đổi số
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
    string s, ans;
    cin >> s;
    ans = s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == '1') {
            if (s[i] == '0') ans[i] = '1';
            else ans[i] = '0';
        }
    }
    cout << ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}

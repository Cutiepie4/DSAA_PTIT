// công thức trên mạng
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[1010]; int r = 0;
        cin >> s;
        for (int i = 0; i < strlen(s); i++) {
            r = (2 * r + s[i] - '0') % 5;
        }
        if (r == 0) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
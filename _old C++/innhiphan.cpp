#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, kt = 0;
        cin >> n;
        string s(n, '0');
        string s1(n, '1');
        cout << s << " ";
        while (1) {
            if (kt) break;
            for (int i = s.size() - 1; i >= 0; i--) {
                if (s[i] == '0') {
                    s[i] = '1';
                    for (int j = i + 1; j < s.size(); j++) s[j] = '0';
                    cout << s << " ";
                    if (s == s1) {
                        kt = 1; break;
                    }
                    break;
                }
            }
        }
        cout << endl;
    }
}
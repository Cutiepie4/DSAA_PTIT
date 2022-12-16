#include <iostream>
#include <vector>
using namespace std;

struct data {
    char kitu;
    int dem;
}a[26];

int check(string s) {
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            if (a[j].kitu == s[i]) {
                a[j].dem++; break;
            }
        }
    }
    int kt = 0;
    for (int i = 0; i < 26; i++) {
        if (a[i].dem % 2 == 1) {
            kt++;
            if (kt > 3) break;
        }
    }
    if (kt <= 3) return 1;
    return 0;
}

main() {
    int t;
    cin >> t;
    char x = 'a';
    for (int i = 0; i < 26; i++) {
        a[i].kitu = x;
        if (x == 'z') break;
        x++;
    }
    while (t--) {
        string s;
        cin >> s;
        for (int i = 0; i < 26; i++) a[i].dem = 0;
        if (check(s) == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
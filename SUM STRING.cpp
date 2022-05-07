#include <bits/stdc++.h>
using namespace std;

string x(string s, int len) {
    while (s.size() != len) s = "0" + s;
    return s;
}
string cong(string a, string b) {
    int len = max(a.size(), b.size());
    if (a.size() < len) a = x(a, len);
    if (b.size() < len) b = x(b, len);
    string tmp; int mem = 0;
    for (int i = len - 1; i >= 0; i--) {
        a[i] -= '0'; b[i] -= '0';
        tmp.push_back(((a[i] + b[i]) % 10 + mem) % 10 + '0');
        mem = (a[i] + b[i] + mem) / 10;
        if (i == 0 && mem) tmp.push_back('1');
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

int process(string s, int i, int j, int k) {
    if (i + j + k > s.size()) return 0;
    string tmp1 = s.substr(i, j), tmp2 = s.substr(i + j, k);
    string tmp3 = cong(tmp1, tmp2), tmp;
    if (i + j + k + tmp3.size() <= s.size()) {
        tmp = s.substr(i + j + k, tmp3.size());
        if (tmp == tmp3) {
            if (i + j + k + tmp3.size() == s.size()) return 1;
            return process(s, i + j, k, tmp3.size());
        }
    }
    return 0;
}

void process(string s) {
    int check = 0;
    for (int i = 1; i <= s.size() / 2; i++) {
        if (check) break;
        for (int j = 1; max(i, j) <= s.size() - i - j; j++) {
            if (process(s, 0, i, j) == 1) {
                cout << "Yes" << endl;
                check = 1;
                break;
            }
        }
    }
    if (check == 0) cout << "No" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        process(s);
    }
}
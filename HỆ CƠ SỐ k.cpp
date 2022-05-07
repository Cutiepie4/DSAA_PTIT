#include <bits/stdc++.h>
using namespace std;

string plus_k(string a, string b, int k) {
    int len = max(a.size(), b.size());
    while (a.size() < len) a.insert(a.begin(), '0');
    while (b.size() < len) b.insert(b.begin(), '0');

    string tmp; 
    int mem = 0;
    for (int i = len - 1; i >= 0; i--) {
        a[i] -= '0'; b[i] -= '0';
        tmp.push_back(((a[i] + b[i]) % k + mem) % k + '0');
        mem = (a[i] + b[i] + mem) / k;
        if (i == 0 && mem) tmp.push_back('1');
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

void solution() {
    string a, b;
    int k;
    cin >> k >> a >> b;
    cout << plus_k(a, b, k);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}
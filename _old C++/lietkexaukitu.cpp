#include <bits/stdc++.h>
using namespace std;

set <string> Data;

void process(char a, char n, int k, string tmp1) {
    if (k == 0) {
        Data.insert(tmp1);
        return;
    }
    for (char i = a; i <= n; i++) {
        string tmp = tmp1;
        tmp.push_back(i);
        process(i, n, k - 1, tmp);
    }
}

int main() {
    char n;
    int k;
    cin >> n >> k;
    for (char i = 'A'; i <= n; i++) {
        string tmp;
        tmp.push_back(i);
        process(i, n, k - 1, tmp);
    }
    for (auto i : Data) cout << i << endl;
}
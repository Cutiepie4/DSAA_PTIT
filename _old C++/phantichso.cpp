#include <bits/stdc++.h>
using namespace std;

void process(vector <int> v, int index, string tmp1, int n, int sum) {
    for (int i = index; i < n; i++) {
        int x = sum + v[i];
        if (x <= n) {
            string tmp = tmp1;
            tmp += " ";
            tmp += to_string(v[i]);
            if (x == n) {
                tmp += ")";
                cout << tmp << " ";
            }
            else process(v, i, tmp, n, x);
        }
    }
}

void solution() {
    int n;
    cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) v[i] = n - i;

    for (int i = 0; i < n; i++) {
        string tmp = "(";
        tmp += to_string(v[i]);
        if (i == 0) {
            tmp += ")";
            cout << tmp << " ";
        }
        else process(v, i, tmp, n, v[i]);
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}
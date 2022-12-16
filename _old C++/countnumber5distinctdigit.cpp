// count element that has 5 distinct digits <= 5
#include <bits/stdc++.h>
using namespace std;

set <int> ss;

int gt(int x) {
    if (x == 1) return 1;
    return gt(x - 1) * x;
}

int convert(vector <int> v) {
    int x = 0;
    for (auto i : v) x = x * 10 + i;
    return x;
}

void next_com(vector <int>& v, int k, int n) {
    int x = gt(k);
    vector <int> tmp = v;
    while (x--) {
        ss.insert(convert(tmp));
        next_permutation(tmp.begin(), tmp.end());
    }
    int i;
    for (i = k; i > 0; i--) {
        if (v[i] < n - k + i) {
            v[i]++;
            for (int j = i + 1; j <= k; j++) {
                v[j] = v[i] + j - i;
            }
            next_com(v, k, n);
        }
    }
    return;
}


void init() {
    for (int i = 1; i < 6; i++) {
        vector <int> tmp;
        tmp.push_back(0);
        for (int j = 0; j < i; j++) tmp.push_back(j);
        next_com(tmp, i, 5);
    }
}

int main() {
    int t;
    cin >> t;
    init();
    set <int> ::iterator it;
    vector <int> data(100000, 0);
    for (it = ss.begin(); it != ss.end(); it++) data[*it]++;
    for (int i = 1; i < data.size(); i++) data[i] += data[i - 1];
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << data[r] - data[l - 1] << endl;
    }
}
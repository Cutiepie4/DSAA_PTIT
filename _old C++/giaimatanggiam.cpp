#include <bits/stdc++.h>
using namespace std;

void process(vector <int>& v) {
    int maxx = 1, index = 0;
    for (int i = index; i < v.size(); i++) {
        if (v[i] < v[i + 1] || i == v.size() - 1) {
            int x = maxx - v[i];
            for (int j = i; j >= index; j--) {
                v[j] += x;
                maxx = max(maxx, v[j]);
            }
            maxx++;
            index = i + 1;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        string s;
        cin >> s;
        vector <int> v(1, 0);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'I') {
                v.push_back(v.back());
                v.back()++;
            }
            else {
                v.push_back(v.back());
                v.back()--;
            }
        }
        process(v);
        // cout << "Test " << z << ": ";
        for (auto i : v) cout << i;
        cout << endl;
    }
}
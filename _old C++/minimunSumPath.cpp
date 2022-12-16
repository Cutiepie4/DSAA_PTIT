#include <bits/stdc++.h>
using namespace std;

int process(vector <vector <int>>& v, int r, int c) {
    for (int i = 1; i < c; i++) v[0][i] += v[0][i - 1];
    for (int i = 1; i < r; i++) v[i][0] += v[i - 1][0];
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            v[i][j] += min(v[i - 1][j], min(v[i][j - 1], v[i - 1][j - 1]));
        }
    }
    return v[r - 1][c - 1];
}

void init(vector <vector <int>>& v, int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> v[i][j];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector <vector <int>> v(r, vector <int>(c, 0));
        init(v, r, c);
        cout << process(v, r, c) << endl;
    }
}
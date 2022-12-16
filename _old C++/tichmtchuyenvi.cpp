// Truong Quoc Viet
#include <bits/stdc++.h>
using namespace std;

void init(vector <vector <int>>& v, int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
}

vector <vector <int>> xxx(vector <vector <int>> v, int n, int m) {
    vector <vector <int>> v1;
    for (int j = 0; j < m; j++) {
        vector <int> tmp;
        for (int i = 0; i < n; i++) {
            tmp.push_back(v[i][j]);
        }
        v1.push_back(tmp);
    }
    return v1;
}

vector <vector <int>> multiplication(vector <vector <int>>& v, vector <vector <int>>& v1, int n, int m) {
    vector <vector <int>> res(n, vector <int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < m; j++) {
                res[i][k] += v[i][j] * v1[j][k];
            }
        }
    }
    return res;
}

void output(vector <vector <int>> v, int n, int index) {
    cout << "Test " << index << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, m;
        cin >> n >> m;
        vector <vector <int>> v(n, vector <int>(m, 0));
        init(v, n, m);
        vector <vector <int>> v1 = xxx(v, n, m);
        vector <vector <int>> res = multiplication(v, v1, n, m);z
        output(res, n, i);
    }
}
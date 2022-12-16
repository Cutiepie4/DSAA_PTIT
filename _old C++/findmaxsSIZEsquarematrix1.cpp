/*
Cho ma trận A[N][M] chỉ bao gồm các số 0 và 1.
Hãy tìm cấp ma trận vuông con lớn nhất có các phần tử đều bằng 1
*/

#include <bits/stdc++.h>
using namespace std;

int process(vector <vector <int>> a, int r, int c) {
    int ans = 0;
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (a[i][j] == 1) {
                a[i][j] = min(a[i][j - 1], min(a[i - 1][j - 1], a[i - 1][j])) + 1;
                ans = max(ans, a[i][j]);
            }
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector <vector <int>> a(r, vector <int>(c, 0));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> a[i][j];

        cout << process(a, r, c) << endl;
    }
}
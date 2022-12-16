#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        //initiation
        int r, c;
        cin >> r >> c;
        int a[r][c];
        for (int i = 0;i < r;i++) {
            for (int j = 0;j < c;j++) {
                cin >> a[i][j];
            }
        }

        //process
        vector <int> b[100];
        int row = r, col = c, k = 0, p = 0, q = 0;
        while (k < r * c) {
            for (int i = p; i < col; i++) {
                if (k == r * c) break;
                b[q].push_back(a[p][i]); k++;
            }
            for (int i = p + 1; i < row; i++) {
                if (k == r * c) break;
                b[q].push_back(a[i][col - 1]); k++;
            }
            for (int i = col - 2; i >= p; i--) {
                if (k == r * c) break;
                b[q].push_back(a[row - 1][i]); k++;
            }
            for (int i = row - 2; i > p; i--) {
                if (k == r * c) break;
                b[q].push_back(a[i][p]); k++;
            }
            p++; q++;
            row--; col--;
        }

        //rotate
        for (int i = 0; i < q; i++) {
            int tmp = b[i][0];
            b[i].insert(b[i].begin(), b[i].back());
            b[i].pop_back();
        }

        //apply rotate
        int row1 = r, col1 = c, k1 = 0, p1 = 0, q1 = 0, z = 0;
        while (k1 < r * c) {
            for (int i = p1; i < col1; i++) {
                if (k1 == r * c) break;
                a[p1][i] = b[q1][z++]; k1++;
            }
            for (int i = p1 + 1; i < row1; i++) {
                if (k1 == r * c) break;
                a[i][col1 - 1] = b[q1][z++]; k1++;
            }
            for (int i = col1 - 2; i >= p1; i--) {
                if (k1 == r * c) break;
                a[row1 - 1][i] = b[q1][z++]; k1++;
            }
            for (int i = row1 - 2; i > p1; i--) {
                if (k1 == r * c) break;
                a[i][p1] = b[q1][z++]; k1++;
            }
            p1++; q1++; z = 0;
            row1--; col1--;
        }

        //output
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
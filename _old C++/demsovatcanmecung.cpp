#include <bits/stdc++.h>
using namespace std;

void process(vector <vector <char>>& a, int i, int j) {
    if (a[i - 1][j] == '#') {
        a[i - 1][j] = '.';
        process(a, i - 1, j);
    }
    if (a[i][j + 1] == '#') {
        a[i][j + 1] = '.';
        process(a, i, j + 1);
    }
    if (a[i][j - 1] == '#') {
        a[i][j - 1] = '.';
        process(a, i, j - 1);
    }
    if (a[i + 1][j] == '#') {
        a[i + 1][j] = '.';
        process(a, i + 1, j);
    }
}

int main() {
    int r, c;
    cin >> r >> c;
    vector <vector <char>> a(r + 2, vector <char>(c + 2, '.'));
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> a[i][j];

    int value = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (a[i][j] == '#') {
                a[i][j] = '.';
                process(a, i, j);
                value++;
            }
        }
    }
    cout << value;
}
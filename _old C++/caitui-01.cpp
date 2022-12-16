#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define matrix vector <vector <int>>
#define matrixl vector <vector <ll>>
const ll MOD = 1e9 + 7;

int n, W;
vt w, vl;
matrix M;

void prs() {
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= W; j++) {
            M[i][j] = M[i - 1][j];
            if (w[i] <= j) {
                M[i][j] = max(M[i][j], M[i - 1][j - w[i]] + vl[i]);
            }
        }
    }
    cout << M[n - 1][W] << endl;
}

void solution() {
    cin >> n >> W;
    w = vt(n);
    vl = vt(n);
    M = matrix(n, vt(W + 1, 0));
    for (auto& i : w) cin >> i;
    for (auto& i : vl) cin >> i;
    prs();
}

int main() {
    faster();
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}
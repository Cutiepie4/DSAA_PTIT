/*
Cho ba xâu ký tự X, Y, Z. Nhiệm vụ của bạn là tìm độ dài dãy con chung dài nhất có mặt trong cả ba xâu.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào độ dài xâu X, Y, X; dòng tiếp theo đưa vào ba xâu X, Y, Z.
T, X, Y, Z thỏa mãn ràng buộc: 1 ≤ T ≤ 100;  1 ≤ size(X), size(Y), size(Z) ≤ 100.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
5 8 13
geeks geeksfor geeksforgeeks
7 6 5
abcd1e2 bc12ea bd1ea

Output
5
3
*/
// Cho ba xâu ký tự X, Y, Z. Nhiệm vụ của bạn là tìm độ dài dãy con chung dài nhất có mặt trong cả ba xâu.
#include <bits/stdc++.h>
using namespace std;

int f[101][101][101];

void TestCase() {
    int n, m, k, res = 0;
    cin >> n >> m >> k;
    string x, y, z;
    cin >> x >> y >> z;

    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int l = 1; l <= k; ++l) {
                if (x[i - 1] == y[j - 1] && x[i - 1] == z[l - 1])
                    f[i][j][l] = f[i - 1][j - 1][l - 1] + 1;
                else
                    f[i][j][l] = max({ f[i - 1][j][l], f[i][j - 1][l], f[i][j][l - 1] });
                res = max(res, f[i][j][l]);
            }
        }
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        TestCase();
        cout << endl;
    }
    return 0;
}
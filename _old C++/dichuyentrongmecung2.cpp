/*
Cho một mê cung bao gồm các khối được biểu diễn như một ma trận nhị phân A[N][N]. 
Một con chuột đi từ ô đầu tiên góc trái (A[0][0]) đến ô cuối cùng góc phải (A[N-1][N-1]) theo nguyên tắc:

Down (D): Chuột được phép xuống dưới nếu ô dưới nó có giá trị 1.
Right (R): Chuột được phép sang phải dưới nếu ô bên phải nó có giá trị 1.
Left (L): Chuột được phép sang trái dưới nếu ô bên trái nó có giá trị 1.
Up (U): Chuột được phép lên trên nếu ô trên nó có giá trị 1.
Hãy đưa ra tất cả các hành trình của con chuột trên mê cung. Đưa ra -1 nếu chuột không thể đi đến đích.
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;

const int X[4] = {-1, 0, 1, 0};
const int Y[4] = {0, 1, 0, -1};
const string S = "URDL";

int n, a[10][10];
vector<string> v;

void DFS(int i, int j, string s) {
    if (i == n && j == n) {
        v.push_back(s);
        return;
    }
    for (int k = 0; k < 4; ++k) {
        int r = i + X[k];
        int c = j + Y[k];
        if (r >= 1 && r <= n && c >= 1 && c <= n && a[r][c] == 1) {
            a[r][c] = 0;
            DFS(r, c, s + S[k]);
            a[r][c] = 1;
        }
    }
}

void TestCase() {
    v.clear();
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    
    if (a[1][1] == 0 || a[n][n] == 0) {
        cout << -1;
        return;
    }

    a[1][1] = 0;
    DFS(1, 1, "");

    if (v.empty())
        cout << -1;
    else {
        sort(v.begin(), v.end());
        for (auto x : v) {
            cout << x << " ";
        }
    }
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
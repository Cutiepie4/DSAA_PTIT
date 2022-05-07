/*
Cho một bàn cờ 8 x 8, mỗi ô có một giá trị A[i][j] nhất định (0 ≤ A[i][j] ≤ 100), tương ứng với điểm số đạt được nếu như bạn đặt một quân cờ vào đó.

Nhiệm vụ của bạn là đặt 8 quân hậu lên bàn cờ, sao cho không có 2 quân nào ăn nhau, và số điểm đạt được là lớn nhất.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm 8 dòng, mỗi dòng 8 số nguyên mô tả bàn cờ.

Output:  Với mỗi test, ghi ra thứ tự bộ test và giá trị điểm lớn nhất đạt được trên một dòng.

Ví dụ:

Input

Output

1

1 2 3 4 5 6 7 8

9 10 11 12 13 14 15 16

17 18 19 20 21 22 23 24

25 26 27 28 29 30 31 32

33 34 35 36 37 38 39 40

41 42 43 44 45 46 47 48

48 50 51 52 53 54 55 56

57 58 59 60 61 62 63 64


Test 1: 260
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define pi pair <int,int>
#define matrix vector <vt>
#define matrixl vector <vtl>
const int MOD = 1e9 + 7;

int n = 8, ans = 0;

void rest(int r, int c, matrix& M) {
    int i = r, j = c;
    while (i < n && j < n) {
        M[i++][j++] = 0;
    }
    i = r + 1, j = c - 1;
    while (i < n && j >= 0) {
        M[i++][j--] = 0;
    }
    i = r + 1;
    while (i < n) {
        M[i++][c] = 0;
    }
}

void back(int cnt, matrix M, int sum) {
    if (cnt == n) {
        ans = max(ans, sum);
    }
    if (cnt > n - 1) return;
    for (int i = 0; i < n; i++) {
        if (M[cnt][i]) {
            matrix tmp = M;
            rest(cnt, i, tmp);
            back(cnt + 1, tmp, sum + M[cnt][i]);
        }
    }
}

void solution() {
    matrix M;
    ans = 0;
    M = matrix(n, vt(n, 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> M[i][j];
    back(0, M, 0);
    cout << ans;
}

int main() {
    faster();
    int T;
    cin >> T;
    int test = 1;
    while (T--) {
        cout << "Test " << test++ << ": ";
        solution();
        cout << endl;
    }
    return 0;
}
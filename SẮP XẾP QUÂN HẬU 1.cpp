/*
Cho một bàn cờ vua có kích thước n * n, ta biết ràng quân hậu có thể di chuyển theo chiều ngang, dọc, chéo. Vấn đề đặt ra rằng, có n quân hậu, bạn cần đếm số cách đặt n quân hậu này lên bàn cờ sao cho với 2 quân hậu bất kì, chúng không “ăn” nhau.

Input: Dòng đầu ghi số bộ test T (T<5). Mỗi bộ test ghi một số nguyên dương n duy nhất (không quá 10)

Output:  Ghi kết quả mỗi bộ test trên một dòng. Số cách đặt quân hậu.

Ví dụ:

Input
1
4
Output
2
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

int n, ans = 0;

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

void back(int cnt, matrix M) {
    if (cnt == n) ans++;
    if (cnt > n - 1) return;
    for (int i = 0; i < n; i++) {
        if (M[cnt][i]) {
            matrix tmp = M;
            rest(cnt, i, tmp);
            back(cnt + 1, tmp);
        }
    }
}

void solution() {
    matrix M;
    ans = 0;
    cin >> n;
    M = matrix(n, vt(n, 1));
    back(0, M);
    cout << ans;
}

int main() {
    faster();
    int T;
    cin >> T;
    while (T--) {
        solution();
        cout << endl;
    }
    return 0;
}
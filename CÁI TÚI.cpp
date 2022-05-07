/*
Một người có cái túi thể tích V (V<1000). Anh ta có N đồ vật cần mang theo (N≤1000), mỗi đồ vật có thể tích là A[i] (A[i]≤100) và giá trị là C[i] (C[i]≤100). Hãy xác định tổng giá trị lớn nhất của các đồ vật mà người đó có thể mang theo, sao cho tổng thể tích không vượt quá V.

Input

Dòng đầu ghi số bộ test T (T<10)
Mỗi bộ test gồm ba dòng. Dòng đầu ghi 2 số N và V. Dòng tiếp theo ghi N số của mảng A. Sau đó là một dòng ghi N số của mảng C.
Dữ liệu vào luôn đảm bảo không có đồ vật nào có thể tích lớn hơn V.
Output

Với mỗi bộ test, ghi trên một dòng giá trị lớn nhất có thể đạt được.
Ví dụ

Input
1
15 10
5 2 1 3 5 2 5 8 9 6 3 1 4 7 8
1 2 3 5 1 2 5 8 7 4 1 2 3 2 1

Output
15
*/

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
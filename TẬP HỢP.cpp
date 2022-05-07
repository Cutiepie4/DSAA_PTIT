/*
Xét tất cả các tập hợp các số nguyên dương có các phần tử khác nhau và không lớn hơn số n cho trước. Nhiệm vụ của bạn là hãy đếm xem có tất cả bao nhiêu tập hợp có số lượng phần tử bằng k và tổng của tất cả các phần tử trong tập hợp bằng s?

Các tập hợp là hoán vị của nhau chỉ được tính là một.

Ví dụ với n = 9, k = 3, s = 23, {6, 8, 9} là tập hợp duy nhất thỏa mãn.

Input:  Gồm nhiều bộ test (không quá 100 test).

Mỗi bộ test gồm 3 số nguyên n, k, s với 1 ≤ n ≤ 20, 1 ≤ k ≤ 10 và 1 ≤ s ≤ 155. Input kết thúc bởi 3 số 0.

Output:  Với mỗi test in ra số lượng các tập hợp thỏa mãn điều kiện đề bài.

Ví dụ:

Input
9 3 23
9 3 22
10 3 28
16 10 107
20 8 102
20 10 105
20 10 155
3 4 3
4 2 11
0 0 0

Output
1
2
0
20
1542
5448
1
0
0
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

int n, k, s;
int Data[21][11][156];

int back(int n, int k, int s) {
    if (s <= 0 || k <= 0) return 0;
    if (k == 1) {
        if (s <= n) Data[n][k][s] = 1;
        else Data[n][k][s] = 0;
        return Data[n][k][s];
    }
    if (Data[n][k][s] != -1) return Data[n][k][s];
    int sum = 0;
    for (int i = n; i >= 1; i--) {
        sum += back(i - 1, k - 1, s - i);
    }
    Data[n][k][s] = sum;
    return sum;
}

int main() {
    faster();
    memset(Data, -1, sizeof(Data));
    while (1) {
        cin >> n >> k >> s;
        if (n == 0 && k == 0 && s == 0) break;
        cout << back(n, k, s) << endl;
    }
    return 0;
}
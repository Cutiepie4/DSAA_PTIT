/*
Cho n thành phố đánh số từ 1 đến n và các tuyến đường giao thông hai chiều giữa chúng, mạng lưới giao thông này được cho bởi mảng C[1…n, 1…n] ở đây C[i][j] = C[j][i] là chi phí đi đoạn đường trực tiếp từ thành phố i đến thành phố j.

Một người du lịch xuất phát từ thành phố 1, muốn đi thăm tất cả các thành phố còn lại mỗi thành phố đúng 1 lần và cuối cùng quay lại thành phố 1. Hãy chỉ ra chi phí ít nhất mà người đó phải bỏ ra.

Dữ liệu vào: Dòng đầu tiên là số nguyên n – số thành phố (n ≤ 15); n dòng sau, mỗi dòng chứa n số nguyên thể hiện cho mảng 2 chiều C.

Kết quả: Chi phí mà người đó phải bỏ ra.

Ví dụ:

INPUT

OUTPUT

4

0 20 35 10

20 0 90 50

35 90 0 12

10 50 12 0

117
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

int n, ans = INT32_MAX;
matrix C;
vt prv, mark;

void back(int ith, int sum) {
    if (ith == n) {
        ans = min(ans, sum + C[prv[ith]][0]);
        return;
    }
    for (int j = 1; j < n; j++) {
        if (mark[j] && sum + C[prv[ith]][j] < ans) {
            mark[j] = 0;
            prv[ith + 1] = j;
            back(ith + 1, sum + C[prv[ith]][j]);
            mark[j] = 1;
        }
    }
}

void solution() {
    cin >> n;
    C = matrix(n, vt(n, 0));
    prv = vt(n, 0);
    mark = vt(n, 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> C[i][j];
    back(1, 0);
    cout << ans;
}

int main() {
    faster();
    solution();
    return 0;
}
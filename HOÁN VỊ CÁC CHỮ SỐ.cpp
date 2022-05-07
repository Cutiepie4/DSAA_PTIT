/*
Độ chênh lệch của một dãy số nguyên dương được định nghĩa là hiệu của số lớn nhất trừ đi số nhỏ nhất trong dãy.

Cho hai số nguyên dương n và k, với 1 <= n, k <= 8.

Với n xâu ký tự số có độ dài k, có thể có chữ số 0 ở đầu. Hãy tìm cách duyệt tất cả hoán vị các chữ số của từng số trong danh sách sao cho độ chênh lệch của dãy số tạo được là bé nhất có thể.

Input

Dòng đầu ghi hai số n và k.

Tiếp theo là n dòng, mỗi dòng ghi một xâu ký tự đúng k chữ số.
Ghi ra độ chênh lệch bé nhất có thể.
Ví dụ
Input
6 4
5237
2753
7523
5723
5327
2537

Output
2700

Input
3 3
010
909
012

Output
3
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

void solution() {
    int n, k, ans = INT32_MAX;
    cin >> n >> k;
    vts S(n);
    for (auto& i : S) cin >> i;
    vt v(k);
    iota(v.begin(), v.end(), 0);
    do {
        int Max = 0, Min = INT32_MAX;
        for (auto i : S) {
            int tmp = 0;
            for (int j = 0; j < k; j++) tmp = tmp * 10 + i[v[j]] - '0';
            Min = min(Min, tmp);
            Max = max(Max, tmp);
        }
        ans = min(ans, Max - Min);
    } while (next_permutation(v.begin(), v.end()));
    cout << ans;
}

int main() {
    faster();
    solution();
    return 0;
}
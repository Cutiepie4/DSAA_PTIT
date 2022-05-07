/*
Cho dãy số A[] có N phần tử. Hãy liệt kê tất cả các tổ hợp chập K của tập các phần tử khác nhau trong A[]. Các tổ hợp cần liệt kê theo thứ tự từ điển (tức là trong mỗi tổ hợp thì giá trị từ nhỏ đến lớn, và tổ hợp sau lớn hơn tổ hợp trước).

Input

Dòng đầu ghi hai số N và K.

Dòng thứ 2 ghi N số của mảng A[]. Các giá trị không quá 1000.

Dữ liệu đảm bảo số phần tử khác nhau của A[] không quá 20 và K không quá 10.

Output

Ghi ra lần lượt các tổ hợp tìm được, mỗi tổ hợp trên một dòng.

Ví dụ

Input
8 3
2 4 4 3 5 1 3 4

Output
1 2 3
1 2 4
1 2 5
1 3 4
1 3 5
1 4 5
2 3 4
2 3 5
2 4 5
3 4 5
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

int n, k;
set <int> ss;
vt v;

void next_com(vector <int>& a, int k, int n) {
    for (int i = 1; i <= k; i++) cout << v[a[i]] << " ";
    cout << endl;
    int i;
    // tìm i lớn nhất sao cho a[i] < n - k + i, tức là tìm a[i] mà chưa đạt cấu hình max đầu tiên từ dưới lên
    for (i = k; i > 0; i--) {
        if (a[i] < n - k + i) {
            a[i]++;
            for (int j = i + 1; j <= k; j++) {
                a[j] = a[i] + j - i;
            }
            next_com(a, k, n);
        }
    }
    return;
}

void solution() {
    cin >> n >> k;
    for (int i = 0, tmp; i < n; i++) {
        cin >> tmp;
        ss.insert(tmp);
    }
    v = vt(ss.begin(), ss.end());
    v.insert(v.begin(), 0);
    n = v.size() - 1;
    vt a1(k + 1);
    iota(a1.begin(), a1.end(), 0);
    next_com(a1, k, n);
}

int main() {
    faster();
    solution();
    return 0;
}
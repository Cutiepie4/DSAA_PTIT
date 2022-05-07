/*
Cho dãy số A[] có N phần tử là các số nguyên dương. Với mỗi số nguyên K, hãy tính xem có thể tách dãy số A thành ít nhất bao nhiêu nhóm sao cho mỗi số trong nhóm đều có thể tìm được ít nhất một số khác cùng nhóm có chênh lệch không vượt quá K.

Ví dụ: A[] = {2, 6, 1, 7, 3, 4, 9}; K = 1 thì kết quả là 3 ứng với 3 nhóm {2,1,3,4}; {6,7};  {9}

Input

Dòng đầu ghi hai số N và K (0 <= K <= 105; 0 <= N <= 106).

Dòng thứ 2 ghi ra N số của dãy A[], các số nguyên dương và không quá 106.

Output

Ghi ra số nhóm ít nhất có thể.

Ví dụ

Input

Output

7 1

2 6 1 7 3 4 9

3
*/
#include<bits/stdc++.h>

using namespace std;

#define fast() ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long

int main() {
    fast();
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] > k)
            ++cnt;
    }
    cout << cnt;
}
// // Cho mảng A[] gồm n số nguyên dương.
// Hãy biến mảng A[] thành một mảng đối xứng sao
// cho phép thay thế A[i] = Merge(A[i], A[i+1])
// được thực hiện ít nhất. Trong đó,
// Merge(A[i], A[i+1]) = A[i] + A[i+1].
// Ví dụ với A[] = {3, 2, 3, 3, 5} ta chỉ cần thực
// hiện 1 phép Merge(A[0], A[1]) để trở thành mảng
// A[] = {5, 3, 3, 5}.
// ta so sánh 2 số đầu và cuối, nếu số nào nhỏ hơn thì cộng số đằng trước vào thôi


#include <bits/stdc++.h>
using namespace std;

int fmino(int a[], int n) {
    int ans = 0, l = 0, r = n - 1;
    while (l < r) {
        if (a[l] == a[r]) {
            l++; r--;
        }
        else if (a[l] > a[r]) {
            r--;
            a[r] += a[r + 1];
            ans++;
        }
        else {
            l++;
            a[l] += a[l - 1];
            ans++;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << fmino(a,n) << endl;
    }
}
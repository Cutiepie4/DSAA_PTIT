#include <bits/stdc++.h>
using namespace std;


void next_com(vector <int>& v, int k, int n) {
    for (int i = 1; i <= k; i++) cout << v[i] << " ";
    cout << endl;
    int i;
    // tìm i lớn nhất sao cho a[i] < n - k + i, tức là tìm a[i] mà chưa đạt cấu hình max đầu tiên từ dưới lên
    for (i = k; i > 0; i--) {
        if (v[i] < n - k + i) {
            v[i]++;
            for (int j = i + 1; j <= k; j++) {
                v[j] = v[i] + j - i;
            }
            next_com(v, k, n);
        }
    }
    return;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector <int> v(k + 1);
    for (int i = 1; i <= k; i++) cin >> v[i];
    next_com(v, k, n);
}
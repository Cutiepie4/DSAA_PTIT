/*
Cho dãy số nguyên A[] gồm có N phần tử. Nhiệm vụ của bạn là tìm dãy số B[] có tổng phần 
tử nhỏ nhất thỏa mãn tính chất A[i] / B[i] = A[i+1] / B[i+1] với mọi chỉ số i (0 ≤ i ≤ N-2).

Phép chia trong bài toán này là phép chia guyên 
(tức là chỉ lấy phần nguyên của kết quả: dụ 5/3 = 1).   
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
    ll n, m = INT64_MAX, ans = INT64_MAX;
    cin >> n;
    vector <ll> v(n);
    for (auto& i : v) {
        cin >> i;
        m = min(m, i);
    }
    m--;
    while (m > 0) {
        ll tmp = 0, kt = 1;
        for (ll i = 0; i < n; i++) {
            int x = v[i] / (m + 1) + 1;
            if (m == v[i] / x) {
                tmp += x;
            }
            else {
                kt = 0;
                break;
            }
        }
        if (kt) ans = min(ans, tmp);
        m--;
    }
    cout << ans;
}

int main() {
    solution();
}
/*
Một dãy xâu ký tự G chỉ bao gồm các chữ cái A và B được gọi là dãy xâu Fibonacci nếu thỏa mãn tính chất:    G(1) = A; G(2) = B; G(n) = G(n-2)+G(n-1). Với phép cộng (+) là phép nối hai xâu với nhau.  Bài toán đặt ra là tìm ký tự ở vị trí thứ i (tính từ 1) của xâu Fibonacci thứ n.

Dữ liệu vào: Dòng 1 ghi số bộ test. Mỗi bộ test ghi trên một dòng 2 số nguyên N và i (1<N<93). Số i đảm bảo trong phạm vi của xâu G(N) và không quá 18 chữ số. Kết quả: Ghi ra màn hình kết quả tương ứng với từng bộ test.

Input
2
6 4
8 19

Output
A
B
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <ll> fb(100);

void init() {
    fb[1] = 1;
    fb[2] = 1;
    for (ll i = 3; i < 92; i++) fb[i] = fb[i - 1] + fb[i - 2];
}

char find_kth_ch(ll n, ll k) {
    if (n == 1 && k == 1) return 'A';
    if (n == 2 && k == 1) return 'B';
    if (n == 3 && k == 1) return 'A';
    if (n == 3 && k == 2) return 'B';

    if (k > fb[n - 2]) {
        return find_kth_ch(n - 1, k - fb[n - 2]);
    }
    return find_kth_ch(n - 2, k);
}

int main() {
    int t;
    cin >> t;
    init();
    while (t--) {
        ll n, k;
        cin >> n >> k;
        cout << find_kth_ch(n, k) << endl;
    }
}
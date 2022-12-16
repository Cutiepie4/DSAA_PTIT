// Cho hai hàm h(x) và g(x) xác định trên tập các
// số tự nhiên A[] gồm n phần tử. Trong đó, h(x)
// là tích của các số trong mảng A[], g(x) là ước
// số chung lớn nhất của các số trong mảng A[].
// Nhiệm vụ của bạn là tìm giá trị h(x)g(x). 
// Chú ý, khi lời giải cho kết quả lớn hãy đưa ra
// giá trị modulo với 109+7.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll oo = 1e9 + 7;

ll uscln(ll a, ll b) {
    if (b == 0) return a;
    return uscln(b, a % b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll a[n], res = 1;
        for (int i = 0; i < n; i++) cin >> a[i];
        ll g = a[0], h = a[0];
        for (int i = 1; i < n; i++) {
            g = uscln(g, a[i]);
            h = (h * a[i]) % oo;
        }
        for (int i = 0; i < g; i++)
            res = (res * h) % oo;
        cout << res << endl;
    }
}
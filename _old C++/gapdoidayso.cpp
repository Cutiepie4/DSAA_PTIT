/*
Một dãy số tự nhiên bắt đầu bởi con số 1 và được thực hiện N-1 phép biến đổi “gấp đôi” dãy số như sau:

Với dãy số A hiện tại, dãy số mới có dạng A, x, A trong đó x là số tự nhiên bé nhất chưa xuất hiện trong A.

Ví dụ với 2 bước biến đổi, ta có [1] à [1 2 1] à [1 2 1 3 1 2 1].

Các bạn hãy xác định số thứ K trong dãy số cuối cùng là bao nhiêu?
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <ll> v(52);
void init() {
    v[1] = 1;
    for (int i = 2; i < 52; i++) {
        v[i] = 2 * v[i - 1] + 1;
    }
}

int find_kth(ll n, ll k) {
    if (k == 1) return 1;
    if (k == v[n - 1] + 1) return n;
    if (k > v[n - 1] + 1) return find_kth(n - 1, k - v[n - 1] - 1);
    if (k < v[n - 1] + 1) return find_kth(n - 1, k);
}

int main() {
    int t;
    cin >> t;
    init();
    while (t--) {
        ll n, k;
        cin >> n >> k;
        cout << find_kth(n, k) << endl;
    }
}
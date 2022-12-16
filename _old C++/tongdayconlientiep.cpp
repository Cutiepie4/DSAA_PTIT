/*
Cho dãy số nguyên dương A[] có N phần tử. Người ta cố gắng chia dãy A[] 
thành các đoạn liên tiếp sao tổng của các đoạn đó bằng nhau.

Ví dụ: dãy A[] = {2, 5, 1, 3, 3, 7} có thể được chia 
thành 3 đoạn {2, 5} {1, 3, 3} {7} cùng có tổng các phần tử bằng 7.

Hãy tính giá trị tổng liên tiếp nhỏ nhất có thể của 
các đoạn con tổng bằng nhau trong dãy A.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll process(vector <ll> v, ll sum) {
    ll tmp = 0;
    for (ll i = 0; i < v.size(); i++) {
        tmp += v[i];
        if (tmp > sum) return 0;
        if (tmp == sum) {
            if (i == v.size() - 1) return 1;
            else tmp = 0;
        }
    }
    return 0;
}

void solution() {
    ll n, sum = 0, kt = 1;
    cin >> n;
    vector <ll> v(n);
    for (auto& i : v) {
        cin >> i;
        sum += i;
    }
    vector <ll> data;
    for (ll i = 1; i * i <= sum; i++) {
        if (sum % i == 0) {
            data.push_back(i);
            data.push_back(sum / i);
        }
    }
    sort(data.begin(), data.end());
    for (auto i : data) {
        ll x = process(v, i);
        if (x) {
            cout << i << endl;
            kt = 0;
            break;
        }
    }
    if (kt) cout << sum << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}
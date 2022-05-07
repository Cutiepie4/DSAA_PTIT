/*
Cho N sợi dây với độ dài khác nhau được lưu trong mảng A[]. Nhiệm vụ của bạn là nối N sợi dây thành một sợi sao cho tổng chi phí nối dây là nhỏ nhất. Biết chi phí nối sợi dây thứ i và sợi dây thứ j là tổng độ dài hai sợi dây A[i] và A[j].
Input
Dòng đầu ghi số bộ test T (T<10). Mỗi bộ test gồm 2 dòng. Dòng đầu tiên là số nguyên N (N ≤ 2*106).
Dòng tiếp theo gồm N số nguyên dương c[i] ( 1 ≤ A[i] ≤ 109).
Output
In ra đáp án của bộ test trên từng dòng, theo modulo 109+7.
Ví dụ:
Input:
7
2 4 1 2 10 2 3
OUTPUT:
59
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll oo = 1e9 + 7;

void solution() {
    int n;
    cin >> n;
    multiset <ll> ss;
    multiset <ll> ::iterator it;
    for (ll i = 0, a; i < n; i++) {
        cin >> a;
        ss.insert(a);
    }
    ll tmp = 0, ans = 0;
    while (ss.size() != 1) {
        tmp = *ss.begin();
        ss.erase(ss.begin());
        tmp += *ss.begin();
        ss.erase(ss.begin());
        ans = (ans + tmp) % oo;
        ss.insert(tmp % oo);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}
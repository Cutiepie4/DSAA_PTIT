/*
Cho số nguyên dương n. Hãy cho biết có bao nhiêu dãy số nguyên dương có tổng các phầ tử trong dãy bằng n. 

Dữ liệu vào: dòng đầu tiên chứa số nguyên T là số bộ dữ liệu, mỗi bộ dữ liệu ghi một số nguên dương n duy nhất không qua 1018. 

Kết quả: Mỗi bộ dữ liệu ghi ra một số nguyên duy nhất là số dư của kết quả tìm được khi chia cho 123456789.

Ví dụ:

Input

Output

1

3

4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 123456789;

ll sqr(ll x) {
    return x * x;
}

ll pow(ll a, ll b) {
    if (b == 0) return 1 % MOD;
    else
        if (b % 2 == 0)
            return sqr(pow(a, b / 2)) % MOD;
        else
            return a * (sqr(pow(a, b / 2)) % MOD) % MOD;
}

void solution(ll a, ll b) {
    cout << pow(a, b) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        solution(2, n - 1);
    }
}
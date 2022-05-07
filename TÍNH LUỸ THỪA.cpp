/*
Cho hai số nguyên không âm a và b. Hãy tính ab.

Nếu kết quả quá lớn hãy chia dư cho 109 + 7.

Input

Gồm không quá 20 bộ test, mỗi test ghi trên một dòng hai số a,b; a không quá 9 chữ số, b không quá 18 chữ số.
Input kết thúc khi a = b = 0
Output
Với mỗi test ghi ra kết quả tính được trên một dòng.
Ví dụ
Input
2 3
2 4
3 2
0 0
OUTPUT:
8
16
9
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

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
    ll a, b;
    while (cin >> a >> b) {
        if (a == b && a == 0) return 0;
        solution(a, b);
    }
}
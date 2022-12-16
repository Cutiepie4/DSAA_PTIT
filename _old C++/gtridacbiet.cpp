/*
Cho một xâu s. Với mỗi một xâu con X liên tiếp của s có độ dài bằng K, 
giá trị đặc biệt của nó được tính bằng giá trị của X 
trong hệ cơ số B modulo M.

Nhiệm vụ của bạn là tính tổng giá trị đặc biệt của 
tất cả các xâu con của s có độ dài bằng K.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s;
ll k, base, m;

void init(vector <ll>& pow) {
    pow[0] = 1;
    for (int i = 1; i < k; i++) {
        pow[i] = pow[i - 1] * base % m;
    }
}

void solution() {
    cin >> s >> k >> base >> m;
    vector <ll> pow(k);
    init(pow);
    ll sum = 0, tmp, ans = 0;
    tmp = (s[0] - '0') * pow[k - 1] % m;
    sum += tmp;
    for (int i = 1; i < k; i++) {
        sum += (s[i] - '0') * pow[k - i - 1] % m;
    }
    sum += m;
    ans += sum % m;
    for (int i = 1; i <= s.size() - k; i++) {
        sum -= tmp;
        tmp = (s[i] - '0') * pow[k - 1] % m;
        sum *= base;
        sum %= m;
        sum += m;
        sum += s[i + k - 1] - '0';
        ans += sum % m;
    }
    cout << ans;
}

int main() {
    solution();
}
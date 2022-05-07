/*
Cho một xâu s. Với mỗi một xâu con X liên tiếp của s có độ dài bằng K, giá trị đặc biệt của nó được tính bằng giá trị của X trong hệ cơ số B modulo M.

Nhiệm vụ của bạn là tính tổng giá trị đặc biệt của tất cả các xâu con của s có độ dài bằng K.

Input:

Dòng đầu tiên gồm xâu S có độ dài không quá 300 000 gồm các kí tự từ 0 – 9.

Dòng tiếp theo là số nguyên K, B và M (1 <= K <= |s|, 2 <= B <= 10, 1 <= M <= 1000).

Output: 

In ra đáp án tìm được.
Test ví dụ:

Test 1
Input:
12212
3 3 5

Output:
5

Test 2
Input:
111101
4 2 15

Output:
27
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
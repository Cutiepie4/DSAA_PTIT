/*
Cho số nguyên dương N. Mỗi bước, bạn sẽ biến đổi N thành [N/2], N mod 2, [N/2]. Sau khi thực hiện một cách triệt để, ta thu được một dãy số chỉ toàn số 0 và 1.

Nhiệm vụ của bạn là hãy đếm các số bằng 1 trong đoạn [L, R] của dãy số cuối cùng.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm 3 số nguyên N, L, R (1 ≤ N, L, R < 250, 0 ≤ R-L ≤ 100 000).

Output:

Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:

Input

Output

2

7 2 5

10 3 10

4

5



Giải thích test 1: [7] à [3, 1, 3] à [1, 1, 1, 1, 3] à [1, 1, 1, 1, 1, 1, 1].

Giải thích test 2: Dãy số sau khi biến đổi là [1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1].
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vt vector <ll>

vt cnt;
int x;

void count(ll n) {
    cnt = vt(51, 0);
    cnt[1] = 1;
    int i = 2;
    n /= 2;
    while (n) {
        cnt[i] = cnt[i - 1] * 2 + 1;
        i++;
        n /= 2;
    }
    x = i - 1;
}

int Find(ll n, ll curr, ll pos) {
    if (n == 1 || pos == cnt[n - 1] + 1) return curr % 2;
    if (pos < cnt[n - 1] + 1) return Find(n - 1, curr / 2, pos);
    return Find(n - 1, curr / 2, pos - cnt[n - 1] - 1);
}

void solution() {
    ll n, l, r, ans = 0;
    cin >> n >> l >> r;
    count(n);
    for (ll i = l; i <= r; i++) ans += Find(x, n, i);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solution();
        cout << endl;
    }
}
/*
Cho dãy số A[] gồm có N phần tử không âm và số K.

Nhiệm vụ của bạn là hãy xác định xem có tìm được 1 dãy con liên tiếp mà tổng các phần tử bằng K hay không?

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm số nguyên N và K (1≤ N ≤ 100 000, 0 ≤ K ≤ 1018).
Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 109).
Output: 

Với mỗi test, in ra trên một dòng là đáp án thu được. Nếu có hãy in ra “YES”. Nếu không tìm được đáp án, in ra “NO”.
Ví dụ:

Input:
3
6 33
1 4 20 3 10 5
7 7
1 4 0 0 3 10 5
2 0
1 4

OUTPUT
YES
YES
NO

Giải thích test 1: 20+3+10 = 33
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define matrix vector <vector <int>>
#define vt vector <ll>

void solution() {
    ll n, sum;
    cin >> n >> sum;
    vt v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++) cin >> v[i];
    if (sum > 1e15) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (v[i] == sum) {
            cout << "YES" << endl;
            return;
        }
        v[i] += v[i - 1];
    }
    for (int i = 0; i <= n; i++) {
        ll tmp = v[i] + sum;
        if (*lower_bound(v.begin() + i + 1, v.end(), tmp) == tmp) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}
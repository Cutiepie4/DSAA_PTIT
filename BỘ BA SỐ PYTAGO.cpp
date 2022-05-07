/*
Cho dãy số A[] gồm có N phần tử. Một bộ 3 số (a, b, c) được gọi là bộ ba số Pytago nếu như a^2 + b^2 = c^2.

Nhiệm vụ của bạn là kiểm tra xem có tồn tại bộ ba số Pytago trong dãy số A[] hay không?

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm số nguyên N (1≤ N ≤5000).

Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 10^9).

Output: 

Với mỗi test, in ra trên một dòng “YES” nếu tìm được, và “NO” trong trường hợp ngược lại.

Ví dụ:
Input:
2
5
3 1 4 6 5
3
1 1 1

Output
YES
NO
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define pi pair <int,int>
#define matrix vector <vt>
#define matrixl vector <vtl>
const int MOD = 1e9 + 7;

void solution() {
    ll n, Max = 0;
    cin >> n;
    vtl v(n);
    for (auto& i : v) {
        cin >> i;
        Max = max(Max, i);
    }
    Max *= Max;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        ll y = v[i] * v[i];
        for (int j = i + 1; j < n; j++) {
            ll x = y + v[j] * v[j];
            if (x > Max) break;
            else {
                ll tmp = sqrt(x);
                if (tmp * tmp == x && binary_search(v.begin() + j + 1, v.end(), tmp)) {
                    cout << "YES";
                    return;
                }
            }
        }
    }
    cout << "NO";
}

int main() {
    faster();
    int T;
    cin >> T;
    while (T--) {
        solution();
        cout << endl;
    }
    return 0;
}